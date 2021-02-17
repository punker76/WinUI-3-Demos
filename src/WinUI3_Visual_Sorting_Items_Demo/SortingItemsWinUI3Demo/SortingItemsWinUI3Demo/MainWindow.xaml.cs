using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

using Windows.System; //For Virtual Keys
using Windows.UI.Core;

using Microsoft.System;
using Microsoft.UI;
using Microsoft.UI.Input;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Shapes;
using WinRT;

using VisualSorting.SortingAlgorithm;


namespace VisualSorting
{
    public sealed partial class MainWindow : Window
    {
        public List<ISortStrategy> _algorithmCollection;
        const int Size = 100;
        const int PaddingElement = 2;
        const int ElementSize = 4;
        int _speed = 50;

        IList<int> _collection;
        IList<int> _exceptCollection;
        ISortStrategy _sorter;
        CancellationTokenSource _cancellationTokenSource;

        public MainWindow()
        {
            InitializeCollections();

            Title = "Visual Sorting Demo for WinUI 3 Preview 4"; // You still need the Title for the TaskBar title, and the Icon
            LoadIcon("Images/windowIcon.ico");

            InitializeComponent();

            // Custom Title Bar
            ExtendsContentIntoTitleBar = true;
            SetTitleBar(myTitleBar);
         
            //Bug: In Preview 4 Alt + F4 doesn't close the Window. This is a workaround.
            Content.KeyDown += (sender, e) => {
                //This is no longer valid:
                //Window.Current.CoreWindow.GetKeyState(VirtualKey).HasFlag(CoreVirtualKeyStates);
                bool altDown = KeyboardInput.GetKeyStateForCurrentThread(VirtualKey.Menu).HasFlag(CoreVirtualKeyStates.Down);
                if (e.Key == VirtualKey.F4 && altDown)
                {
                    this.Close();
                }
            };
        }

        private void InitializeCollections()
        {
            _algorithmCollection = new List<ISortStrategy>
                                    {
                                          new BubbleSort(),
                                          new QuickSort(),
                                          new SelectionSort(),
                                          new MergeSort(),
                                          new InsertionSort()
                                      };

            _collection = new List<int>();
            _exceptCollection = new List<int>();
            for (int i = 0; i < Size; i++)
            {
                _exceptCollection.Add(i);
            }
        }

        private void OnStartClick(object sender, RoutedEventArgs e)
        {
            if (AlgorithmComboBox.SelectedItem == null) return;

            InitializeCollectionWithRandonNumbers(_collection, Size);

            _sorter = (ISortStrategy)AlgorithmComboBox.SelectedItem;
            _sorter.ReportProgress += UpdateProgress;

            StartSorting();
        }

        private void InitializeCollectionWithRandonNumbers(IList<int> collection, int size)
        {
            collection.Clear();
            Random random = new();
            for (int i = 0; i < size; i++)
            {
                int newNumber = random.Next(size);
                if (collection.Contains(newNumber))
                {
                    IList<int> tmp = _exceptCollection.Except(collection).ToList();
                    newNumber = tmp[random.Next(tmp.Count - 1)];
                }
                collection.Add(newNumber);
            }
        }

        void UpdateProgress(IList<int> list)
        {
            VisualizeCollection(list);
            Thread.Sleep(_speed);
        }

        //TODO: This can be improved using Win2D.
        private void VisualizeCollection(IList<int> list)
        {
            if (list != null && list.Count > 0)
            {
                canvas.DispatcherQueue.TryEnqueue(() =>
                {
                    canvas.Children.Clear();

                    for (int i = 0; i < list.Count; i++)
                    {
                        int element = list[i];
                        Rectangle rectangle = new();
                        rectangle.Width = rectangle.Height = ElementSize;
                        rectangle.Fill = new SolidColorBrush(Colors.Gray);
                        canvas.Children.Add(rectangle);

                        Canvas.SetLeft(rectangle, list.IndexOf(element) * ElementSize + PaddingElement);
                        Canvas.SetTop(rectangle, element * ElementSize + PaddingElement);
                    }
                });
            }
        }

        private async void StartSorting()
        {
            myInfoBar.IsOpen = true;
            myInfoBar.Message = "Action in progress.";
            myInfoBar.Severity = InfoBarSeverity.Warning;
            myProgressRing.IsActive = true;
            DateTime dtStart = DateTime.Now;

            _cancellationTokenSource = new();
            try
            {
                await Task.Run(() =>
                {
                    _sorter.SortCancellationToken = _cancellationTokenSource.Token;
                    _sorter.Sort(_collection);

                    this.DispatcherQueue.TryEnqueue(() =>
                    {
                        TimeSpan time = DateTime.Now.Subtract(dtStart);
                        myInfoBar.Message = $"Action completed. ({time.TotalSeconds.ToString("F")} seconds)";
                        myInfoBar.Severity = InfoBarSeverity.Success;
                        myProgressRing.IsActive = false;
                    });

                });
            }
            catch (OperationCanceledException)
            {
                myInfoBar.Message = "Action cancelled.";
                myInfoBar.Severity = InfoBarSeverity.Error;
                myProgressRing.IsActive = false;
            }
        }
      
        private void OnStopClick(object sender, RoutedEventArgs e)
        {
            if (_cancellationTokenSource != null)
            {
                _cancellationTokenSource.Cancel();
                canvas.Children.Clear();
                _collection.Clear();
            }
        }

        private void OnNewWindow(object sender, RoutedEventArgs e)
        {
            if ((bool)IsSameThread.IsChecked)
            {
                MainWindow mainWindow = new MainWindow();
                mainWindow.Activate();
            }
            else
            {
                var thread = new Thread(() =>
                {
                    var syncContext = new DispatcherQueueSynchronizationContext(Microsoft.System.DispatcherQueue.GetForCurrentThread());
                    SynchronizationContext.SetSynchronizationContext(syncContext);
                    Application.Start((p) =>
                    {
                        MainWindow mainWindow = new MainWindow();
                        mainWindow.Activate();
                    });
                });
                thread.SetApartmentState(ApartmentState.STA);
                thread.Start();

            }
        }

        private void LoadIcon(string iconName)
        {
            //Get the Window's HWND
            var hwnd = this.As<IWindowNative>().WindowHandle;

            IntPtr hIcon = PInvoke.User32.LoadImage(IntPtr.Zero, iconName,
                PInvoke.User32.ImageType.IMAGE_ICON, 16, 16, PInvoke.User32.LoadImageFlags.LR_LOADFROMFILE);

            PInvoke.User32.SendMessage(hwnd, PInvoke.User32.WindowMessage.WM_SETICON, (IntPtr)0, hIcon);
        }

        [ComImport]
        [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
        [Guid("EECDBF0E-BAE9-4CB6-A68E-9598E1CB57BB")]
        internal interface IWindowNative
        {
            IntPtr WindowHandle { get; }
        }
    }
}
