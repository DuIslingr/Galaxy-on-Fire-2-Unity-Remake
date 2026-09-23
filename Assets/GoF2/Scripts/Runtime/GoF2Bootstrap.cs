// GoF2Bootstrap.cs
// Process-wide startup settings, applied before the first scene loads, and the frame rate option
// (GoF2Settings.FrameRate), re-applied whenever the settings change.
// Mobile players default to 30 fps and are always synced to the display, so there "V-Sync" means the
// display's refresh rate (120 Hz on the S24) and "Uncapped" can't go beyond it either.

using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake
{
    public static class GoF2Bootstrap
    {
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        static void Init()
        {
            int editorVSync = QualitySettings.vSyncCount;
            if (Application.isMobilePlatform) Screen.sleepTimeout = SleepTimeout.NeverSleep;   // no screen dimming while playing
            ApplyFrameRate();
            GoF2Settings.Changed -= ApplyFrameRate;
            GoF2Settings.Changed += ApplyFrameRate;
#if UNITY_EDITOR
            // Leaving Play mode (Application.quitting in the Editor): restore the Editor's vSyncCount, or the
            // Play-mode value would stick to QualitySettings.asset, and unhook, because with domain reload off
            // the subscription would survive into edit mode.
            System.Action restore = null;
            restore = () =>
            {
                GoF2Settings.Changed -= ApplyFrameRate;
                QualitySettings.vSyncCount = editorVSync;
                Application.quitting -= restore;
            };
            Application.quitting += restore;
#endif
        }

        public static int DisplayRefreshRate
        {
            get
            {
                int hz = Mathf.RoundToInt((float)Screen.currentResolution.refreshRateRatio.value);
                return hz > 0 ? hz : 60;
            }
        }

        public static void ApplyFrameRate()
        {
            if (!Application.isPlaying) return;
            bool mobile = Application.isMobilePlatform;
            switch (GoF2Settings.FrameRate)
            {
                case GoF2FrameRate.Fps30: Limit(30); break;
                case GoF2FrameRate.Fps60: Limit(60); break;
                case GoF2FrameRate.Fps120: Limit(120); break;
                case GoF2FrameRate.Uncapped:
                    QualitySettings.vSyncCount = 0;
                    Application.targetFrameRate = mobile ? 1000 : -1;   // -1 on mobile would mean 30 fps
                    break;
                default:
                    QualitySettings.vSyncCount = 1;
                    Application.targetFrameRate = mobile ? Mathf.Max(30, DisplayRefreshRate) : -1;
                    break;
            }
        }

        static void Limit(int fps)
        {
            QualitySettings.vSyncCount = 0;   // targetFrameRate is ignored while vSyncCount > 0
            Application.targetFrameRate = fps;
        }
    }
}
