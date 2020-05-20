using System;
using System.Diagnostics; //Proccess
using System.IO; //File access
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;

using Windows.Storage.Pickers;
using WinRT;

using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Documents;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;


namespace DemoBuildCs
{
    public sealed partial class MainWindow : Window
    {
        public MainWindow()
        {
            this.InitializeComponent();
            splitView.PaneOpened += OnPaneOpened;
        }

        private void OnPaneOpened(SplitView sender, object args)
        {
            string currentTheme = sender.RequestedTheme == ElementTheme.Default ? App.Current.RequestedTheme.ToString() : sender.RequestedTheme.ToString();
            themePanel.Children.Cast<RadioButton>().FirstOrDefault(c => c?.Tag?.ToString() == currentTheme).IsChecked = true;
        }

        async void OnBrowse(object sender, RoutedEventArgs e)
        {
            var folderPicker = new FolderPicker();

            //Make folder Picker work in Win32
            IntPtr windowHandle = (App.Current as App).WindowHandle;
            InitializeWithWindowWrapper initializeWithWindowWrapper = InitializeWithWindowWrapper.FromAbi(folderPicker.ThisPtr);
            initializeWithWindowWrapper.Initialize(windowHandle);
            folderPicker.FileTypeFilter.Add("*");

            var folder = await folderPicker.PickSingleFolderAsync();
            textBox.Text = folder != null ? folder.Path : string.Empty;
        }

        #region IInitializeWithWindow
        [ComImport]
        [Guid("3E68D4BD-7135-4D10-8018-9FB6D9F33FA1")]
        [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
        public interface IInitializeWithWindow
        {
            void Initialize(IntPtr hwnd);
        }

        // This is the actual wrapper for CSWinRT  
        [Guid("3E68D4BD-7135-4D10-8018-9FB6D9F33FA1")]
        internal class InitializeWithWindowWrapper : IInitializeWithWindow
        {
            [Guid("3E68D4BD-7135-4D10-8018-9FB6D9F33FA1")]
            public struct Vftbl
            {
                public delegate int _Initialize_0(IntPtr thisPtr, IntPtr hwnd);

                internal global::WinRT.Interop.IUnknownVftbl IUnknownVftbl;
                public _Initialize_0 Initialize_0;

                public static readonly Vftbl AbiToProjectionVftable;
                public static readonly IntPtr AbiToProjectionVftablePtr;

                static Vftbl()
                {
                    AbiToProjectionVftable = new Vftbl
                    {
                        IUnknownVftbl = global::WinRT.Interop.IUnknownVftbl.AbiToProjectionVftbl,
                        Initialize_0 = Do_Abi_Initialize_0
                    };
                    AbiToProjectionVftablePtr = Marshal.AllocHGlobal(Marshal.SizeOf<Vftbl>());
                    Marshal.StructureToPtr(AbiToProjectionVftable, AbiToProjectionVftablePtr, false);
                }

                private static int Do_Abi_Initialize_0(IntPtr thisPtr, IntPtr windowHandle)
                {
                    try
                    {
                        ComWrappersSupport.FindObject<IInitializeWithWindow>(thisPtr).Initialize(windowHandle);
                    }
                    catch (Exception ex)
                    {
                        return Marshal.GetHRForException(ex);
                    }
                    return 0;
                }
            }
            internal static ObjectReference<Vftbl> FromAbi(IntPtr thisPtr) => ObjectReference<Vftbl>.FromAbi(thisPtr);

            public static implicit operator InitializeWithWindowWrapper(IObjectReference obj) => (obj != null) ? new InitializeWithWindowWrapper(obj) : null;
            protected readonly ObjectReference<Vftbl> _obj;
            public IObjectReference ObjRef { get => _obj; }
            public IntPtr ThisPtr => _obj.ThisPtr;
            public ObjectReference<I> AsInterface<I>() => _obj.As<I>();
            public A As<A>() => _obj.AsType<A>();
            public InitializeWithWindowWrapper(IObjectReference obj) : this(obj.As<Vftbl>()) { }
            internal InitializeWithWindowWrapper(ObjectReference<Vftbl> obj)
            {
                _obj = obj;
            }

            public void Initialize(IntPtr windowHandle)
            {
                Marshal.ThrowExceptionForHR(_obj.Vftbl.Initialize_0(ThisPtr, windowHandle));
            }
        }
        #endregion

        void OnRun(object sender, RoutedEventArgs e)
        {
            if (!Directory.Exists(textBox.Text) && !File.Exists(textBox.Text))
            {
                return;
            }

            statusTextBlock.Text = "Status: running";

            int depth = (int)numberBox.Value;

            list.Clear();
            var sw = Stopwatch.StartNew();
            ListDirectories(textBox.Text, depth);
            sw.Stop();


            richTextBlock.Blocks.Clear();
            Paragraph paragraph = new Paragraph();
            Run run = new Run();
            run.Text = list.ToString();
            paragraph.Inlines.Add(run);
            richTextBlock.Blocks.Add(paragraph);
            statusTextBlock.Text = $"Status: completed in {sw.Elapsed.TotalMilliseconds} ms";
        }

        void OnKeyDownTextBox(object sender, KeyRoutedEventArgs e)
        {
            if (e.Key == Windows.System.VirtualKey.Enter)
            {
                OnRun(null, null);
            }
        }

        StringBuilder list = new StringBuilder();
        private void ListDirectories(string dir, int depth)
        {
            if (depth < 0)
                return;
            try
            {
                foreach (string d in Directory.GetDirectories(dir))
                {
                    list.AppendLine($"{d}");
                    ListDirectories(d, depth - 1);
                }
            }
            catch (UnauthorizedAccessException ex)
            {
                list.AppendLine($"Unauthorized Access: {dir} - {ex.Message}");
            }
            catch (PathTooLongException ex)
            {
                list.AppendLine($"Path Too Long: {dir} - {ex.Message}");
            }
            catch (System.Exception ex)
            {
                list.AppendLine($"Exception: {ex.Message}");
            }
        }

        async void OnAbout(object sender, RoutedEventArgs e)
        {
            splitView.IsPaneOpen = false;

            var description = new StringBuilder();
            var process = Process.GetCurrentProcess();
            foreach (ProcessModule module in process.Modules)
            {
                description.AppendLine(module.FileName);
            }
            cdTextBlock.Text = description.ToString();
            contentDialog.XamlRoot = gridRoot.XamlRoot;
            await contentDialog.ShowAsync();
        }

        void OnSettings(object sender, RoutedEventArgs e)
        {
            splitView.IsPaneOpen = !splitView.IsPaneOpen;
        }

        void OnThemeRadioButtonChecked(object sender, RoutedEventArgs e)
        {
            var selectedTheme = ((RadioButton)sender)?.Tag?.ToString();
            if (selectedTheme != null)
            {
                ((sender as RadioButton).XamlRoot.Content as SplitView).RequestedTheme = GetEnum<ElementTheme>(selectedTheme);
            }
        }
        void OnHelp(object sender, RoutedEventArgs e)
        {
            teachingTip.IsOpen = true;
        }

        private TEnum GetEnum<TEnum>(string text) where TEnum : struct
        {
            if (!typeof(TEnum).GetTypeInfo().IsEnum)
            {
                throw new InvalidOperationException("Generic parameter 'TEnum' must be an enum.");
            }
            return (TEnum)Enum.Parse(typeof(TEnum), text);
        }

        void OnSendToBottom(object sender, RoutedEventArgs e)
        {

            IntPtr hwnd = (App.Current as App).WindowHandle;
            Win32Window.SetWindowToBottom(hwnd);
        }
        void OnWindowMinimize(object sender, RoutedEventArgs e)
        {
            IntPtr hwnd = (App.Current as App).WindowHandle;
            Win32Window.Minimize(hwnd);
        }

        void OnWindowMaximize(object sender, RoutedEventArgs e)
        {
            IntPtr hwnd = (App.Current as App).WindowHandle;
            Win32Window.Maximize(hwnd);
        }
        void OnWindowNormalize(object sender, RoutedEventArgs e)
        {
            IntPtr hwnd = (App.Current as App).WindowHandle;
            Win32Window.Normalize(hwnd);
        }

    }
}
