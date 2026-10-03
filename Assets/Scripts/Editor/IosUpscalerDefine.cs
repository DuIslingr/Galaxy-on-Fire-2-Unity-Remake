// IosUpscalerDefine.cs  (Editor only)
// Keeps ENABLE_UPSCALER_FRAMEWORK in the iOS scripting define symbols, like the Standalone ones (Player settings), so iOS
// builds get URP's upscaler framework and with it Apple MetalFX Spatial / Temporal (UpscalerFramework; the core package
// compiles the MetalFX upscalers for UNITY_IOS with the framework define and com.unity.modules.metalfx). With the framework
// compiled in URP ignores the old upscaling filter on iOS too: Bootstrap's framework path picks Off / FSR 1 / STP / MetalFX
// (Auto, FSR 1 and STP are registered on every platform). Android keeps the old filter (no define there).
// Set from code rather than in ProjectSettings.asset so it also lands while an Editor has the project open: on every
// Editor load, and checked before an iOS build (a missing define is added and the build stopped, since the player's
// scripts were already compiled without it). MetalFX needs iOS 16 (the project's minimum, Player settings).

using System.Linq;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;

namespace GoF2Remake.EditorTools
{
    [InitializeOnLoad]
    public class IosUpscalerDefine : IPreprocessBuildWithReport
    {
        const string Define = "ENABLE_UPSCALER_FRAMEWORK";

        static IosUpscalerDefine() => EditorApplication.delayCall += () => Ensure();

        // After BuildTargetGuard (int.MinValue), before UrpStpGuard (-1000).
        public int callbackOrder => -2000;

        public void OnPreprocessBuild(BuildReport report)
        {
            if (report.summary.platform != BuildTarget.iOS || !Ensure()) return;
            throw new BuildFailedException(
                $"{Define} was missing from the iOS scripting define symbols and has been added. Let the scripts recompile, " +
                "then build again (the upscaler framework and MetalFX are compiled in only with it).");
        }

        /// <summary>Adds the define to the iOS symbols; true if it was missing.</summary>
        static bool Ensure()
        {
            var target = NamedBuildTarget.iOS;
            var symbols = PlayerSettings.GetScriptingDefineSymbols(target);
            var list = symbols.Split(';').Select(s => s.Trim()).Where(s => s.Length > 0).ToList();
            if (list.Contains(Define)) return false;
            list.Add(Define);
            PlayerSettings.SetScriptingDefineSymbols(target, string.Join(";", list));
            UnityEngine.Debug.Log($"IosUpscalerDefine: added {Define} to the iOS scripting define symbols (MetalFX upscaling on iOS).");
            return true;
        }
    }
}
