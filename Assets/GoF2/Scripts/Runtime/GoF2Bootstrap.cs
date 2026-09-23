// GoF2Bootstrap.cs
// Process-wide startup settings, applied before the first scene loads.
// Mobile players default to 30 fps; run at the display's refresh rate instead (the S24 does 120 Hz),
// capped at 120. Desktop keeps Unity's default (uncapped / vsync).

using UnityEngine;

namespace GoF2Remake
{
    public static class GoF2Bootstrap
    {
        public const int MaxFrameRate = 120;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        static void Init()
        {
            if (!Application.isMobilePlatform) return;
            int hz = Mathf.RoundToInt((float)Screen.currentResolution.refreshRateRatio.value);
            Application.targetFrameRate = Mathf.Clamp(hz > 0 ? hz : 60, 30, MaxFrameRate);
            Screen.sleepTimeout = SleepTimeout.NeverSleep;   // no screen dimming while playing
        }
    }
}
