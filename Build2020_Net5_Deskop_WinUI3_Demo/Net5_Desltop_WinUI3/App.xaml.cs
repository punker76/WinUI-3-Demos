using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;
using Microsoft.UI.Threading;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Shapes;

namespace WinUISamples
{
    public partial class App : Application
    {
        public App()
        {
        }

        protected override void OnLaunched(LaunchActivatedEventArgs args)
        {
            DispatcherQueueSyncContext.SetForCurrentThread();
            base.OnLaunched(args);

            var window = new MainWindow();
            var n = (Window)window as IWindowNative;

            //IntPtr myHandle = ((IWindowNative)window).WindowHandle;

            window.Title = "Disk Usage(.NET Desktop WinUI 3)";
            window.Activate();
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
