// ControllerGyro.cs
// Remake: gyro steering with a PC controller (DualSense, DualShock 4, Switch Pro Controller, Joy-Cons) through Jibb Smart's
// JoyShockLibrary 3.0 (MIT, Assets/Plugins/JoyShockLibrary: the Windows x64 DLL; Unity's Input System doesn't expose these
// controllers' motion sensors). Like gyro-to-mouse: the controller's turn rate moves a steering offset (player space, the
// library's recommended default for controllers: turning or rolling the controller both steer sideways), the offset /
// its limit steers like a stick, Level out re-centres it. The library calibrates the gyro by itself whenever the controller
// is held still. With Steam Input on for the game, Steam owns the controller and only a virtual pad without a gyro reaches
// the game. Windows only (the DLL); elsewhere Supported is false. Plain C#: ShipController polls it.

using System.Runtime.InteropServices;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class ControllerGyro
    {
        /// <summary>Degrees of controller rotation for a full steering offset at sensitivity 1.</summary>
        const float FullDeflectionDegrees = 20f;
        const float RescanSeconds = 3f;

        static readonly int[] handles = new int[8];
        static int device = -1;
        static float nextScan;
        static bool failed, quitHooked;

        /// <summary>The steering offset, -1..1 per axis (x right, y up).</summary>
        public static Vector2 Offset { get; private set; }

        public static bool Supported =>
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
            !failed;
#else
            false;
#endif

        /// <summary>A motion controller is connected (looked for every few seconds while the option is on).</summary>
        public static bool Connected => device >= 0;

        public static void Recenter() => Offset = Vector2.zero;

        /// <summary>Once a frame while flying: the steering from the controller's turn since the last call (zero when the
        /// option is off or no controller is there).</summary>
        public static Vector2 Steer(float dt)
        {
            if (!Settings.GyroSteering || !Supported) { Offset = Vector2.zero; return Vector2.zero; }
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
            try
            {
                if (device >= 0 && !JslStillConnected(device)) device = -1;
                if (device < 0)
                {
                    if (Time.unscaledTime < nextScan) return Offset = Vector2.zero;
                    nextScan = Time.unscaledTime + RescanSeconds;
                    if (!quitHooked) { quitHooked = true; Application.quitting += () => { try { JslDisconnectAndDisposeAll(); } catch { } }; }
                    int n = JslConnectDevices();
                    if (n <= 0) return Offset = Vector2.zero;
                    JslGetConnectedDeviceHandles(handles, handles.Length);
                    device = handles[0];
                    JslSetGyroSpace(device, 2);               // player space
                    JslSetAutomaticCalibration(device, true);   // recalibrates while held still
                    Debug.Log($"ControllerGyro: controller {device} connected (type {JslGetControllerType(device)})");
                }
                JslGetAndFlushAccumulatedGyro(device, out float gx, out float gy, out float gz);
                // Player space: X = pitch (+ = nose up), Y = yaw (+ = left), degrees per second.
                float k = Mathf.Max(0.05f, Settings.GyroSensitivity) / FullDeflectionDegrees;
                var o = Offset + new Vector2(-gy, gx) * (dt * k);
                Offset = new Vector2(Mathf.Clamp(o.x, -1f, 1f), Mathf.Clamp(o.y, -1f, 1f));
                return Offset;
            }
            catch (System.Exception e)
            {
                // The DLL missing or not loadable (a 32-bit or non-Windows player): off for this session.
                failed = true;
                device = -1;
                Debug.LogWarning("ControllerGyro: JoyShockLibrary unavailable: " + e.Message);
                return Offset = Vector2.zero;
            }
#else
            return Vector2.zero;
#endif
        }

#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
        const string Dll = "JoyShockLibrary";
        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)] static extern int JslConnectDevices();
        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)] static extern int JslGetConnectedDeviceHandles(int[] deviceHandleArray, int size);
        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)] static extern void JslDisconnectAndDisposeAll();
        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)] [return: MarshalAs(UnmanagedType.I1)] static extern bool JslStillConnected(int deviceId);
        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)] static extern void JslGetAndFlushAccumulatedGyro(int deviceId, out float gyroX, out float gyroY, out float gyroZ);
        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)] static extern void JslSetGyroSpace(int deviceId, int gyroSpace);
        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)] static extern void JslSetAutomaticCalibration(int deviceId, [MarshalAs(UnmanagedType.I1)] bool enabled);
        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)] static extern int JslGetControllerType(int deviceId);
#endif
    }
}
