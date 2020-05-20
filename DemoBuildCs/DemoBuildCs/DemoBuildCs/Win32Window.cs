using System;
using System.Runtime.InteropServices;

namespace DemoBuildCs
{
    public class Win32Window
    {
        const int SWP_NOSIZE = 0x0001;
        const int SWP_NOMOVE = 0x0002;
        const int SHOWNORMAL_PARAM = 1;
        const int SHOWMINIMIZED_PARAM = 2;
        const int SHOWMAXIMIZED_PARAM = 3;
        const int SWP_NOACTIVATE = 0x0010;

        [DllImport("user32.dll", EntryPoint = "SetWindowPos")]
        public static extern bool SetWindowPos(IntPtr hWnd, int hWndInsertAfter, int x, int Y, int cx, int cy, int wFlags);

        public static void SetWindowToBottom(IntPtr hwnd)
        {
            SetWindowPos(hwnd, 1, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
        }

        [DllImport("user32.dll")]
        static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);
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
    }
}

