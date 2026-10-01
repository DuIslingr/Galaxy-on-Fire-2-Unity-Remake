// WinConsole.cs
// The dedicated server's console on Windows (DedicatedServer): a Windows player is a GUI program, started without a console
// and with no standard handles unless they were redirected. Open makes a console window of its own; Input / Output are
// streams on the standard handles (the new console's, or the redirected ones); OnClose runs on Ctrl+C, Ctrl+Break and the
// window's close button (Windows gives the handler a few seconds before it ends the process on a close).

#if UNITY_STANDALONE_WIN
using System;
using System.IO;
using System.Runtime.InteropServices;
using Microsoft.Win32.SafeHandles;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    static class WinConsole
    {
        const int StdInput = -10, StdOutput = -11;
        const uint Utf8 = 65001, FileTypeUnknown = 0;

        delegate bool CtrlHandler(uint ctrlType);
        static CtrlHandler handler;   // kept alive: the native side holds only a pointer

        /// <summary>The standard output goes somewhere (redirected to a file or pipe, or a console already there).</summary>
        public static bool HasOutput()
        {
            IntPtr h = GetStdHandle(StdOutput);
            return h != IntPtr.Zero && h != new IntPtr(-1) && GetFileType(h) != FileTypeUnknown;
        }

        public static void Open(string title)
        {
            if (GetConsoleWindow() == IntPtr.Zero && !AllocConsole()) throw new IOException("AllocConsole failed");
            SetConsoleOutputCP(Utf8);
            SetConsoleCP(Utf8);
            SetConsoleTitle(title);
        }

        public static Stream Input() => Open(StdInput, FileAccess.Read);
        public static Stream Output() => Open(StdOutput, FileAccess.Write);

        static Stream Open(int std, FileAccess access)
        {
            IntPtr h = GetStdHandle(std);
            if (h == IntPtr.Zero || h == new IntPtr(-1)) return null;
            return new FileStream(new SafeFileHandle(h, false), access);
        }

        public static void OnClose(Action action)
        {
            handler = _ => { action(); return true; };
            SetConsoleCtrlHandler(handler, true);
        }

        [DllImport("kernel32.dll", SetLastError = true)] static extern bool AllocConsole();
        [DllImport("kernel32.dll")] static extern IntPtr GetConsoleWindow();
        [DllImport("kernel32.dll", SetLastError = true)] static extern IntPtr GetStdHandle(int std);
        [DllImport("kernel32.dll")] static extern uint GetFileType(IntPtr handle);
        [DllImport("kernel32.dll")] static extern bool SetConsoleOutputCP(uint codePage);
        [DllImport("kernel32.dll")] static extern bool SetConsoleCP(uint codePage);
        [DllImport("kernel32.dll", CharSet = CharSet.Unicode)] static extern bool SetConsoleTitle(string title);
        [DllImport("kernel32.dll")] static extern bool SetConsoleCtrlHandler(CtrlHandler handler, bool add);
    }
}
#endif
