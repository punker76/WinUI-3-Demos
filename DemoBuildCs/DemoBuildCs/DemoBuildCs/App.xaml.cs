
using System;
using System.Runtime.InteropServices;

using Windows.ApplicationModel;
using WinRT;

using Microsoft.UI.Threading;
using Microsoft.UI.Xaml;


namespace DemoBuildCs
{
    public partial class App : Application
    {
        public App()
        {
            this.InitializeComponent();
            this.Suspending += OnSuspending;
        }

        protected override void OnLaunched(Microsoft.UI.Xaml.LaunchActivatedEventArgs args)
        {
            DispatcherQueueSyncContext.SetForCurrentThread();
            base.OnLaunched(args);

            m_window = new MainWindow();
            WindowWrapper windowWrapper = WindowWrapper.FromAbi(m_window.ThisPtr);
            m_windowHandle = windowWrapper.WindowHandle;
            m_window.Title = "Folder Inspector (.NET Desktop WinUI 3)";
            m_window.Activate();
        }

        private void OnSuspending(object sender, SuspendingEventArgs e)
        {
            // Save application state and stop any background activity
        }

        private Window m_window;
        IntPtr m_windowHandle;
        public IntPtr WindowHandle { get { return m_windowHandle; } }

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
