using Microsoft.UI.Xaml.Documents;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Diagnostics; //Proccess
using System.IO; //File access
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using Windows.Storage.Pickers;

namespace WinUISamples
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

            IInitializeWithWindow initWindow = (IInitializeWithWindow)(object)folderPicker;
            initWindow.Initialize(windowHandle);

            folderPicker.FileTypeFilter.Add("*");

            var folder = await folderPicker.PickSingleFolderAsync();
            if (folder != null)
            {
                textBox.Text = folder.Name;
            }
            else
            {
                textBox.Text = string.Empty;
            }
        }

        [ComImport]
        [Guid("3E68D4BD-7135-4D10-8018-9FB6D9F33FA1")]
        [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
        public interface IInitializeWithWindow
        {
            void Initialize(IntPtr hwnd);
        }

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

            //richTextBlock.Document.SetText(Windows.UI.Text.TextSetOptions.None, list.ToString());
            Paragraph paragraph = new Paragraph();
            Run run = new Run();
            run.Text = list.ToString();
            paragraph.Inlines.Add(run);
            richTextBlock.Blocks.Add(paragraph);
            statusTextBlock.Text = $"Status: completed in {sw.Elapsed.TotalMilliseconds} ms";
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
            TeachingTips(true);
        }




        void TeachingTips(bool status)
        {
            statusTextBlockTeachingTip.IsOpen = status;
            richTextBlockTeachingTip.IsOpen = status;
            textBoxTeachingTip.IsOpen = status;
            runBtnTeachingTip.IsOpen = status;
        }

        private void OnTeachingTipsClosed(TeachingTip sender, TeachingTipClosedEventArgs args)
        {
            TeachingTips(false);
        }

        private TEnum GetEnum<TEnum>(string text) where TEnum : struct
        {
            if (!typeof(TEnum).GetTypeInfo().IsEnum)
            {
                throw new InvalidOperationException("Generic parameter 'TEnum' must be an enum.");
            }
            return (TEnum)Enum.Parse(typeof(TEnum), text);
        }

        //TESTS
        void OnWindowHelper(object sender, RoutedEventArgs e)
        {
            IntPtr hwnd = (App.Current as App).WindowHandle;

            bool isWindow = Win32Helpers.IsWindow(hwnd);
            Win32Helpers.MoveWindow(hwnd);
        }
        
        
    }
}
