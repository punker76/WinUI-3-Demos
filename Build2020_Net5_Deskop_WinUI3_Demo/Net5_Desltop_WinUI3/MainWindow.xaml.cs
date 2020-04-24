using Microsoft.UI.Xaml;
using System;
using System.Diagnostics; //Proccess
using System.IO; //File access
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

        }


        async void OnBrowse(object sender, RoutedEventArgs e)
        {
            var folderPicker = new FolderPicker();
            //Make folderPicker work in Win32
            //Window w = this;
            //var myHandle = ((IWindowNative)w).WindowHandle;

            //IInitializeWithWindow initWindow = (IInitializeWithWindow)(object)folderPicker;
            //initWindow.Initialize(myHandle);

            //folderPicker.SuggestedStartLocation = Windows.Storage.Pickers.PickerLocationId.Desktop;
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

        //[ComImport]
        //[Guid("3E68D4BD-7135-4D10-8018-9FB6D9F33FA1")]
        //[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
        //public interface IInitializeWithWindow
        //{
        //    void Initialize(IntPtr hwnd);
        //}


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

            richEditBox.Document.SetText(Windows.UI.Text.TextSetOptions.None, list.ToString());
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
                list.AppendLine($"Unauthorized Access: {dir}");
            }
            catch (PathTooLongException ex)
            {
                list.AppendLine($"Path Too Long: {dir}");
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
    }
}
