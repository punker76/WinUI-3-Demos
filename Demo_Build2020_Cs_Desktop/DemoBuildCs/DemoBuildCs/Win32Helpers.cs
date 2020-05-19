using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Windows.Foundation;

namespace DemoBuildCs
{
    public class Win32Helpers
    {
        const int GWL_EXSTYLE = -20;
        const int WS_EX_DLGMODALFRAME = 0x0001;
        const int SWP_NOSIZE = 0x0001;
        const int SWP_NOMOVE = 0x0002;
        const int SWP_NOZORDER = 0x0004;
        const int SWP_FRAMECHANGED = 0x0020;
        const uint WM_SETICON = 0x0080;
        const int SWP_SHOWWINDOW = 0x0040;
        const int GWL_STYLE = -16;
        const long WS_VISIBLE = 0x10000000L;
        const long WS_EX_TOOLWINDOW = 0x00000080L;
        const long WS_EX_APPWINDOW = 0x00040000L;
        const int SW_HIDE = 0;
        const int SW_SHOW = 5;
        const int CLOSE_PARAM = 0x0010;
        const int SHOWNORMAL_PARAM = 1;
        const int SHOWMINIMIZED_PARAM = 2;
        const int SHOWMAXIMIZED_PARAM = 3;
        static readonly IntPtr HWND_BOTTOM = new IntPtr(1);
        const int SWP_NOACTIVATE = 0x0010;

        public static void MoveWindow(IntPtr hwnd)
        {
            SetWindowPos(hwnd, 0, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_SHOWWINDOW);
        }

        public static void RemoveIcon(IntPtr hwnd)
        {

            // Change the extended window style to not show a window icon
            int extendedStyle = GetWindowLong(hwnd, GWL_EXSTYLE);
            SetWindowLong(hwnd, GWL_EXSTYLE, extendedStyle | WS_EX_DLGMODALFRAME);

            // Update the window's non-client area to reflect the changes
            SetWindowPos(hwnd, 0, 0, 0, 0, 0, SWP_NOMOVE |
                  SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
        }


        public static void HideWindowInTaskBar(IntPtr hwnd)
        {
            long style = GetWindowLong(hwnd, GWL_STYLE);
            style &= ~(WS_VISIBLE);    // this works - window become invisible 

            style |= WS_EX_TOOLWINDOW;   // flags don't work - windows remains in taskbar
            style &= ~(WS_EX_APPWINDOW);

            ShowWindow(hwnd, SW_HIDE); // hide the window
            SetWindowLong(hwnd, GWL_STYLE, style); // set the style
            ShowWindow(hwnd, SW_SHOW); // show the window for the new style to come into effect
            ShowWindow(hwnd, SW_HIDE); // hide the window so we can't see it

        }

        public static void Maximize(IntPtr hwnd)
        {
            ShowWindow(hwnd, SHOWMAXIMIZED_PARAM);
        }

        public static void Minimize(IntPtr hwnd)
        {
            ShowWindow(hwnd, SHOWMINIMIZED_PARAM);
        }

        public static void Normalize(IntPtr hwnd)
        {
            ShowWindow(hwnd, SHOWNORMAL_PARAM);
        }

        [DllImport("user32.dll", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        static extern bool GetWindowRect(IntPtr hWnd, ref RECT lpRect);
        [StructLayout(LayoutKind.Sequential)]
        private struct RECT
        {
            public int Left;
            public int Top;
            public int Right;
            public int Bottom;
        }
        public static Rect GetWindowRect(IntPtr hwnd)
        {

            RECT rct = new RECT();
            GetWindowRect(hwnd, ref rct);
            return new Rect() { X = rct.Left, Y = rct.Top, Height = rct.Bottom - rct.Top, Width = rct.Right - rct.Left };
        }
        public static void SetWindowToBottom(IntPtr hwnd)
        {
            SetWindowPos(hwnd, 1, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
        }
       
        [DllImport("user32.dll", EntryPoint = "SetWindowPos")]
        public static extern bool SetWindowPos(IntPtr hWnd, int hWndInsertAfter, int x, int Y, int cx, int cy, int wFlags);


        [DllImport("user32.dll")]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool IsWindow(IntPtr hWnd);


        [DllImport("user32.dll")]
        static extern int GetWindowLong(IntPtr hwnd, int index);

        [DllImport("user32.dll")]
        static extern int SetWindowLong(IntPtr hwnd, int index, long newStyle);

     

        [DllImport("user32.dll")]
        static extern IntPtr SendMessage(IntPtr hwnd, uint msg,
            IntPtr wParam, IntPtr lParam);

        [DllImport("user32.dll")]
        static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);
    }
}

