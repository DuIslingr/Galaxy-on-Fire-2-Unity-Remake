// Bootstrap.cs
// Process-wide startup settings, applied before the first scene loads, and the options that act on the whole process
// (Settings), re-applied whenever the settings change: frame rate, master volume, window mode and resolution, render
// scale, upscaler and MSAA (the URP asset), the Quality option's detail (LOD bias) and fog, the stick dead zone, and
// bloom / brightness on every scene's global post-processing volume.
// The URP assets themselves are saved with STP selected: URP strips STP's compute shaders from a player build unless a
// pipeline asset uses it (STPResourceStripper). Players never see that value: the upscaler option replaces it before the
// first scene, "off" being URP's automatic filter.
// Mobile players default to 30 fps and are always synced to the display, so there "V-Sync" means the
// display's refresh rate (120 Hz on the S24) and "Uncapped" can't go beyond it either.

using System.Collections.Generic;
using System.Linq;
using GoF2Remake.Data;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;
using UnityEngine.SceneManagement;

namespace GoF2Remake
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class Bootstrap
    {
        // The project's own values, the "default" of the render scale / MSAA options and the base of the LOD bias.
        static float defaultRenderScale = 1f, defaultLodBias = 1f, defaultDeadzone = Settings.DefaultDeadzone;
        static int defaultMsaa = 1;
        static UpscalingFilterSelection defaultUpscaling = UpscalingFilterSelection.Auto;
        static UniversalRenderPipelineAsset urp;

        /// <summary>The platform's render scale and MSAA samples (what the options' 0 = default stands for).</summary>
        public static float DefaultRenderScale => defaultRenderScale;
        public static int DefaultMsaa => defaultMsaa;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        static void Init()
        {
            int editorVSync = QualitySettings.vSyncCount;
            if (Application.isMobilePlatform) Screen.sleepTimeout = SleepTimeout.NeverSleep;   // no screen dimming while playing
            urp = GraphicsSettings.currentRenderPipeline as UniversalRenderPipelineAsset;
            if (urp != null) { defaultRenderScale = urp.renderScale; defaultMsaa = urp.msaaSampleCount; defaultUpscaling = urp.upscalingFilter; }
            defaultLodBias = QualitySettings.lodBias;
            defaultDeadzone = InputSystem.settings.defaultDeadzoneMin;

            ApplyAll();
            ApplyDisplay();
            Visuals.ClassicBloomPass.Install();   // the "Original" bloom option
            HitchLogger.Install();                // development builds: frame hitches to hitches.log
            UI.ScreenshotKey.Install();           // F12: a screenshot to the pictures library
            UI.DiscordPresence.Install();         // desktop: Discord Rich Presence
            Flight.Haptics.Install();             // controller rumble and phone vibration
            Settings.Changed -= ApplyAll;
            Settings.Changed += ApplyAll;
            SceneManager.sceneLoaded -= OnSceneLoaded;
            SceneManager.sceneLoaded += OnSceneLoaded;
#if UNITY_EDITOR
            // Leaving Play mode (Application.quitting in the Editor): restore the Editor's values, or the Play-mode ones would
            // stick to QualitySettings.asset and the URP asset, and unhook, because with domain reload off the subscriptions
            // would survive into edit mode.
            System.Action restore = null;
            restore = () =>
            {
                Settings.Changed -= ApplyAll;
                SceneManager.sceneLoaded -= OnSceneLoaded;
                QualitySettings.vSyncCount = editorVSync;
                QualitySettings.lodBias = defaultLodBias;
                if (urp != null) { urp.renderScale = defaultRenderScale; urp.msaaSampleCount = defaultMsaa; urp.upscalingFilter = defaultUpscaling; }
                InputSystem.settings.defaultDeadzoneMin = defaultDeadzone;
                AudioListener.volume = 1f;
                Application.quitting -= restore;
            };
            Application.quitting += restore;
#endif
        }

        static void OnSceneLoaded(Scene scene, LoadSceneMode mode) => ApplyPostProcessing();

        static void ApplyAll()
        {
            if (!Application.isPlaying) return;
            ApplyFrameRate();
            AudioListener.volume = Settings.MasterVolume;
            if (urp != null)
            {
                int upscaler = ActiveUpscaler;
                urp.renderScale = Settings.RenderScale > 0f ? Settings.RenderScale : defaultRenderScale;
                urp.upscalingFilter = upscaler == Settings.UpscalerFsr ? UpscalingFilterSelection.FSR
                    : upscaler == Settings.UpscalerStp ? UpscalingFilterSelection.STP : UpscalingFilterSelection.Auto;
                // STP runs on URP's temporal anti-aliasing, which needs MSAA off (UniversalCameraData.IsTemporalAAEnabled).
                urp.msaaSampleCount = upscaler == Settings.UpscalerStp ? 1 : Settings.Msaa > 0 ? Settings.Msaa : defaultMsaa;
            }
            QualitySettings.lodBias = defaultLodBias * (Settings.Quality >= 2 ? 1f : Settings.Quality == 1 ? 0.6f : 0.35f);
            if (!Mathf.Approximately(InputSystem.settings.defaultDeadzoneMin, Settings.StickDeadzone))
                InputSystem.settings.defaultDeadzoneMin = Settings.StickDeadzone;
            ApplyFog();
            ApplyPostProcessing();
            ApplyDisplay();
        }

        // ---- upscaler ----------------------------------------------------------------------------------------

        /// <summary>FSR 1 needs shader model 4.5 (FSRUtils); STP compute shaders and no OpenGL ES (STP.IsSupported), so on
        /// Android it runs on Vulkan only, and its compute shaders in the build (StpResourcesPresent).</summary>
        public static bool FsrSupported => FSRUtils.IsSupported();
        public static bool StpSupported => STP.IsSupported() && StpResourcesPresent;

        static bool? stpResources;

        /// <summary>STP.RuntimeResources (its compute shaders) survived the build: URP's STPResourceStripper drops them when no
        /// pipeline asset had STP selected at build time, and STP then fails every frame (the game froze on Android). The
        /// type is internal, so GraphicsSettings.TryGetRenderPipelineSettings is called through reflection.</summary>
        static bool StpResourcesPresent
        {
            get
            {
                if (stpResources.HasValue) return stpResources.Value;
                bool present = false;
                try
                {
                    var type = typeof(STP).GetNestedType("RuntimeResources", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Public);
                    var method = typeof(GraphicsSettings).GetMethods(System.Reflection.BindingFlags.Public | System.Reflection.BindingFlags.Static)
                        .FirstOrDefault(m => m.Name == "TryGetRenderPipelineSettings" && m.IsGenericMethodDefinition && m.GetParameters().Length == 1);
                    if (type != null && method != null)
                    {
                        var args = new object[] { null };
                        present = (bool)method.MakeGenericMethod(type).Invoke(null, args) && args[0] != null;
                    }
                }
                catch (System.Exception e) { Debug.LogWarning($"Bootstrap: STP resources check failed ({e.Message})"); }
                if (!present) Debug.LogWarning("Bootstrap: STP's resources are not in this build; the STP upscaler is unavailable.");
                stpResources = present;
                return present;
            }
        }

        /// <summary>The upscaler option as far as this device supports it (else off).</summary>
        public static int ActiveUpscaler => Settings.Upscaler switch
        {
            Settings.UpscalerFsr when FsrSupported => Settings.UpscalerFsr,
            Settings.UpscalerStp when StpSupported => Settings.UpscalerStp,
            _ => Settings.UpscalerOff,
        };

        // ---- frame rate --------------------------------------------------------------------------------------

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
            switch (Settings.FrameRate)
            {
                case FrameRate.Fps30: Limit(30); break;
                case FrameRate.Fps60: Limit(60); break;
                case FrameRate.Fps120: Limit(120); break;
                case FrameRate.Uncapped:
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

        // ---- window ------------------------------------------------------------------------------------------

        /// <summary>Window mode and resolution apply to desktop players only (the Editor's Game view keeps its own).</summary>
        public static bool HasDisplayOptions => !Application.isMobilePlatform && !Application.isEditor;

        /// <summary>The display's resolutions, distinct sizes, smallest first.</summary>
        public static List<Vector2Int> Resolutions()
        {
            var list = Screen.resolutions.Select(r => new Vector2Int(r.width, r.height)).Distinct()
                .Where(r => r.y >= 480).OrderBy(r => r.x * r.y).ToList();
            var native = NativeResolution;
            if (!list.Contains(native)) list.Add(native);
            return list;
        }

        static Vector2Int NativeResolution
        {
            get { var d = Screen.mainWindowDisplayInfo; return d.width > 0 ? new Vector2Int(d.width, d.height) : new Vector2Int(Screen.currentResolution.width, Screen.currentResolution.height); }
        }

        /// <summary>Launched with Unity's own window options (-screen-fullscreen / -screen-width / -screen-height /
        /// -window-mode / -popupwindow, e.g. the multiplayer test client in a small window): those win over the window mode
        /// and resolution options for this run.</summary>
        static readonly bool displayFromCommandLine = System.Array.Exists(System.Environment.GetCommandLineArgs(),
            a => a == "-screen-fullscreen" || a == "-screen-width" || a == "-screen-height" || a == "-window-mode" || a == "-popupwindow");

        static void ApplyDisplay()
        {
            if (!HasDisplayOptions || displayFromCommandLine) return;
            var mode = Settings.DisplayMode switch
            {
                DisplayMode.Fullscreen => FullScreenMode.ExclusiveFullScreen,
                DisplayMode.Windowed => FullScreenMode.Windowed,
                _ => FullScreenMode.FullScreenWindow,
            };
            var size = Settings.Resolution;
            if (size.x <= 0 || size.y <= 0)
            {
                size = NativeResolution;
                if (mode == FullScreenMode.Windowed) size = new Vector2Int(size.x * 4 / 5, size.y * 4 / 5);   // a window that fits
            }
            if (Screen.fullScreenMode == mode && Screen.width == size.x && Screen.height == size.y) return;
            Screen.SetResolution(size.x, size.y, mode);
        }

        // ---- fog (the Quality option) ------------------------------------------------------------------------

        static bool sceneFog;

        /// <summary>The level's fog (the system's, a Vossk hangar's): on only with Quality High ("Fog on", 512).</summary>
        public static void SetSceneFog(bool on)
        {
            sceneFog = on;
            ApplyFog();
        }

        static void ApplyFog() => RenderSettings.fog = sceneFog && Settings.QualityEffects;

        // ---- post-processing ---------------------------------------------------------------------------------

        /// <summary>Bloom and the brightness exposure on every global volume (its runtime copy of the profile).</summary>
        public static void ApplyPostProcessing()
        {
            if (!Application.isPlaying) return;
            foreach (var v in Object.FindObjectsByType<Volume>(FindObjectsInactive.Exclude))
            {
                if (!v.isGlobal || v.sharedProfile == null) continue;
                var p = v.profile;
                if (p.TryGet(out Bloom bloom)) bloom.active = Settings.Bloom;
                if (!p.TryGet(out ColorAdjustments color)) color = p.Add<ColorAdjustments>();
                color.postExposure.overrideState = true;
                color.postExposure.value = Settings.BrightnessExposure;
            }
        }
    }
}
