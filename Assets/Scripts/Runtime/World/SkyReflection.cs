// SkyReflection.cs
// The environment reflection of the current skybox (remake). The scenes have no baked lighting data, so in a player URP's
// Lit materials reflect the hidden probe Unity captured from its built-in Default Skybox (a bright blue-grey sky), whatever
// RenderSettings.skybox is: DynamicGI.UpdateEnvironment refreshes the ambient probe but not that reflection (Unity issue
// UUM-27634, "by design"). The Editor regenerates it live, so it only showed in builds: the mods' metallic hulls (the
// original's models are unlit, the Enterprise-E's hull is hardly metallic) came out pale blue-white on Android.
// One realtime ReflectionProbe that sees only the skybox and covers every level is rendered again whenever a level sets
// its sky (Update instead of DynamicGI.UpdateEnvironment); it lives for the whole run, so a scene that sets no sky keeps
// the last one's.

using UnityEngine;
using UnityEngine.Rendering;

namespace GoF2Remake.World
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class SkyReflection
    {
        const float Size = 100000f;   // metres: the menu's far plane is 10 km, the alien orbit's arrival ~8.5 km out
        const int Resolution = 128;   // the scenes' Default Reflection Resolution

        static ReflectionProbe probe;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() => probe = null;

        /// <summary>The ambient light and the reflection from RenderSettings.skybox (call after changing it).</summary>
        public static void Update()
        {
            DynamicGI.UpdateEnvironment();
            if (SystemInfo.graphicsDeviceType == GraphicsDeviceType.Null || RenderSettings.skybox == null) return;   // the dedicated server
            if (probe == null)
            {
                var go = new GameObject("Sky reflection");
                Object.DontDestroyOnLoad(go);
                probe = go.AddComponent<ReflectionProbe>();
                probe.mode = ReflectionProbeMode.Realtime;
                probe.refreshMode = ReflectionProbeRefreshMode.ViaScripting;
                probe.timeSlicingMode = ReflectionProbeTimeSlicingMode.NoTimeSlicing;
                probe.clearFlags = ReflectionProbeClearFlags.Skybox;
                probe.cullingMask = 0;   // the sky alone
                probe.size = Vector3.one * Size;
                probe.resolution = Resolution;
                probe.hdr = true;
                probe.boxProjection = false;
                probe.importance = 0;    // a probe a scene places itself wins
                probe.nearClipPlane = 0.3f;
                probe.farClipPlane = 1000f;
            }
            probe.RenderProbe();
        }
    }
}
