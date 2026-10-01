// UpscalerFramework.cs
// Remake: NVIDIA DLSS and AMD FSR 2 / 3 / 4 through URP's upscaler framework (Unity 6.7, URP 17.7). The framework and its
// DLSS / FSR upscalers are in the render pipeline packages behind the undocumented ENABLE_UPSCALER_FRAMEWORK define (set for
// the Standalone platforms in the Player settings), on the built-in modules com.unity.modules.nvidia / com.unity.modules.amd
// (ENABLE_NVIDIA / ENABLE_AMD on Windows). With the framework compiled in, URP ignores the asset's old upscaling filter: the
// camera uses the framework's active upscaler (UniversalRenderPipeline.SetUpscaler), so every choice of the Upscaler option
// goes through here: Off = unity.auto (bilinear / point by the render scale), FSR 1 = amd.fsr1, STP = unity.stp, DLSS =
// nvidia.dlss4, FSR = the newest the device runs of amd.fsr4 / fsr3 / fsr2. DLSS and FSR 2+ pick their render resolution
// from the quality mode (the Upscaler quality option), not the render scale, and are temporal (anti-aliasing included,
// MSAA off like STP). URP resolves the active upscaler once per pipeline instance, so Bootstrap applies it again whenever
// URP creates its pipeline (RenderPipelineManager.activeRenderPipelineCreated). Which upscalers run on this device comes from the
// framework's own checks (IUpscaler.isSupportedOnDevice: the NVIDIA / AMD plugin, the GPU and the graphics API: DLSS and
// FSR 2 on Direct3D 11 / 12 or Vulkan, FSR 3 / 4 on Direct3D 12 only, FSR 4 on AMD's newest GPUs), read from the pipeline's
// framework instance (UniversalRenderPipeline.upscaling, internal: one reflection read). Without the define (Android) all of
// this compiles to nothing and Bootstrap keeps the asset's upscaling filter.

using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;

namespace GoF2Remake
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class UpscalerFramework
    {
        public const string Auto = "unity.auto", Fsr1 = "amd.fsr1", Stp = "unity.stp", Dlss = "nvidia.dlss4",
            Fsr4 = "amd.fsr4", Fsr3 = "amd.fsr3", Fsr2 = "amd.fsr2";

        /// <summary>The upscaler quality option: 0 native (DLAA / FSR native AA), 1 quality, 2 balanced, 3 performance, 4 ultra
        /// performance.</summary>
        public const int QualityNative = 0, QualityQuality = 1, QualityBalanced = 2, QualityPerformance = 3, QualityUltra = 4;

#if ENABLE_UPSCALER_FRAMEWORK
        /// <summary>The framework is compiled in (desktop builds).</summary>
        public const bool Compiled = true;

        static UniversalRenderPipeline Pipeline => RenderPipelineManager.currentPipeline as UniversalRenderPipeline;

        static System.Reflection.FieldInfo upscalingField;

        /// <summary>The pipeline's framework instance (UniversalRenderPipeline.upscaling, internal static).</summary>
        static Upscaling Instance
        {
            get
            {
                try
                {
                    upscalingField ??= typeof(UniversalRenderPipeline).GetField("upscaling",
                        System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Static);
                    return upscalingField?.GetValue(null) as Upscaling;
                }
                catch (System.Exception) { return null; }
            }
        }

        /// <summary>The upscaler is registered and runs on this device (false until URP has made its pipeline).</summary>
        public static bool Supports(string id)
        {
            var u = Instance?.GetIUpscalerById(id);
            if (u == null) return false;
            try { return u.isSupportedOnDevice; }
            catch (System.Exception) { return false; }
        }

        public static bool DlssSupported => Supports(Dlss);

        /// <summary>The newest FSR (4, 3, 2) this device runs, or null.</summary>
        public static string BestFsr => Supports(Fsr4) ? Fsr4 : Supports(Fsr3) ? Fsr3 : Supports(Fsr2) ? Fsr2 : null;

        /// <summary>"FSR 4" / "FSR 3" / "FSR 2" for the option, or null.</summary>
        public static string BestFsrLabel => BestFsr switch { Fsr4 => "FSR 4", Fsr3 => "FSR 3", Fsr2 => "FSR 2", _ => null };

        /// <summary>The upscaler the framework renders with now (its id; empty before the pipeline exists).</summary>
        public static string ActiveId => Instance?.activeUpscaler?.upscalerId ?? "";

        /// <summary>The pipeline exists (the upscalers' device checks have run).</summary>
        public static bool Ready => Pipeline != null && Instance != null;

        /// <summary>Activates the upscaler 'id' (one this device doesn't run falls back to Auto) with the DLSS / FSR quality
        /// mode 'quality'; false before URP has made its pipeline (Bootstrap applies it again then).</summary>
        public static bool Apply(string id, int quality)
        {
            var pipeline = Pipeline;
            var instance = Instance;
            if (pipeline == null || instance == null) return false;
            if (string.IsNullOrEmpty(id) || !Supports(id)) id = Auto;
            SetQuality(instance, id, Mathf.Clamp(quality, QualityNative, QualityUltra));
            if (instance.activeUpscaler?.upscalerId != id && !pipeline.SetUpscaler(id)) pipeline.SetUpscaler(Auto);
            return true;
        }

        /// <summary>The quality mode on the upscaler's options (the framework's global options; a changed mode recreates the
        /// upscaler's context).</summary>
        static void SetQuality(Upscaling instance, string id, int q)
        {
            var upscaler = instance.GetIUpscalerById(id);
            var options = upscaler != null ? instance.GetGlobalOptions(upscaler) : null;
            if (options == null) return;
#if ENABLE_NVIDIA && ENABLE_NVIDIA_MODULE
            if (options is DLSSOptions dlss)
                dlss.dlssQualityMode = q switch
                {
                    QualityNative => UnityEngine.NVIDIA.DLSSQuality.DLAA,
                    QualityQuality => UnityEngine.NVIDIA.DLSSQuality.MaximumQuality,
                    QualityBalanced => UnityEngine.NVIDIA.DLSSQuality.Balanced,
                    QualityPerformance => UnityEngine.NVIDIA.DLSSQuality.MaximumPerformance,
                    _ => UnityEngine.NVIDIA.DLSSQuality.UltraPerformance,
                };
#endif
#if ENABLE_AMD && ENABLE_AMD_MODULE
            // FSR 3 / 4: native AA, quality, balanced, performance, ultra performance (the option's order); FSR 2 has no native
            // mode: its best is quality.
            if (options is FSR4Options fsr4) fsr4.fsr4QualityMode = (UnityEngine.AMD.FSR4Quality)q;
            else if (options is FSR3Options fsr3) fsr3.fsr3QualityMode = (UnityEngine.AMD.FSR3Quality)q;
            else if (options is FSR2Options fsr2) fsr2.fsr2QualityMode = (UnityEngine.AMD.FSR2Quality)Mathf.Max(0, q - 1);
#endif
        }
#else
        public const bool Compiled = false;
        public static bool Supports(string id) => false;
        public static bool DlssSupported => false;
        public static string BestFsr => null;
        public static string BestFsrLabel => null;
        public static string ActiveId => "";
        public static bool Ready => false;
        public static bool Apply(string id, int quality) => false;
#endif
    }
}
