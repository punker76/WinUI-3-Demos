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
using WinRT;

namespace WinUISamples
{
    public partial class App : Application
    {
        public App()
        {
        }

        IntPtr windowHandle;
        public IntPtr WindowHandle { get { return windowHandle; } } 


        protected override void OnLaunched(LaunchActivatedEventArgs args)
        {
            DispatcherQueueSyncContext.SetForCurrentThread();
            base.OnLaunched(args);

            var window = new MainWindow();
            WindowWrapper windowWrapper = WindowWrapper.FromAbi(window.ThisPtr);
            windowHandle = windowWrapper.WindowHandle;

            window.Title = "Folder Inspector (.NET Desktop WinUI 3)";
            window.Activate();
        }

        [ComImport]
        [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
        [Guid("EECDBF0E-BAE9-4CB6-A68E-9598E1CB57BB")]
        internal interface IWindowNative
        {
            IntPtr WindowHandle { get; }
        }

        [Guid("EECDBF0E-BAE9-4CB6-A68E-9598E1CB57BB")]
        internal class WindowWrapper : IWindowNative
        {
            [Guid("EECDBF0E-BAE9-4CB6-A68E-9598E1CB57BB")]
            public struct Vftbl
            {
                public delegate int _get_WindowHandle_0(IntPtr thisPtr, out IntPtr windowHandle);

                internal global::WinRT.Interop.IUnknownVftbl IUnknownVftbl;
                public _get_WindowHandle_0 get_WindowHandle_0;

                public static readonly Vftbl AbiToProjectionVftable;
                public static readonly IntPtr AbiToProjectionVftablePtr;

                static Vftbl()
                {
                    AbiToProjectionVftable = new Vftbl
                    {
                        IUnknownVftbl = global::WinRT.Interop.IUnknownVftbl.AbiToProjectionVftbl,
                        get_WindowHandle_0 = Do_Abi_get_WindowHandle_0
                    };
                    AbiToProjectionVftablePtr = Marshal.AllocHGlobal(Marshal.SizeOf<Vftbl>());
                    Marshal.StructureToPtr(AbiToProjectionVftable, AbiToProjectionVftablePtr, false);
                }

                private static int Do_Abi_get_WindowHandle_0(IntPtr thisPtr, out IntPtr windowHandle)
                {
                    windowHandle = default;
                    try
                    {
                        windowHandle = ComWrappersSupport.FindObject<IWindowNative>(thisPtr).WindowHandle;
                    }
                    catch (Exception ex)
                    {
                        return Marshal.GetHRForException(ex);
                    }
                    return 0;
                }
            }
            internal static ObjectReference<Vftbl> FromAbi(IntPtr thisPtr) => ObjectReference<Vftbl>.FromAbi(thisPtr);

            public static implicit operator WindowWrapper(IObjectReference obj) => (obj != null) ? new WindowWrapper(obj) : null;
            protected readonly ObjectReference<Vftbl> _obj;
            public IObjectReference ObjRef { get => _obj; }
            public IntPtr ThisPtr => _obj.ThisPtr;
            public ObjectReference<I> AsInterface<I>() => _obj.As<I>();
            public A As<A>() => _obj.AsType<A>();
            public WindowWrapper(IObjectReference obj) : this(obj.As<Vftbl>()) { }
            internal WindowWrapper(ObjectReference<Vftbl> obj)
            {
                _obj = obj;
            }

            public IntPtr WindowHandle
            {
                get
                {
                    Marshal.ThrowExceptionForHR(_obj.Vftbl.get_WindowHandle_0(ThisPtr, out IntPtr windowHandle));

                    return windowHandle;
                }
            }
        }
    }
}
