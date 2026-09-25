// UrpStpGuard.cs  (Editor only)
// Keeps every URP pipeline asset saved with STP as its upscaling filter. URP's STPResourceStripper drops STP's compute
// shaders from a player build unless a pipeline asset uses STP, and the in-game upscaler option (Bootstrap) changes the
// asset while playing; Bootstrap restores it when Play mode ends, but a script recompile during Play mode loses that
// restore, and a build then saved the asset without STP (the APK froze when STP was picked on Android).
// Enforced on Editor load, whenever Play mode ends, and before every player build.

using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;
using UnityEngine.Rendering.Universal;

namespace GoF2Remake.EditorTools
{
    [InitializeOnLoad]
    public class UrpStpGuard : IPreprocessBuildWithReport
    {
        static UrpStpGuard()
        {
            EditorApplication.playModeStateChanged -= OnPlayMode;
            EditorApplication.playModeStateChanged += OnPlayMode;
            if (!EditorApplication.isPlayingOrWillChangePlaymode) EditorApplication.delayCall += () => Enforce(false);
        }

        public int callbackOrder => -1000;

        public void OnPreprocessBuild(BuildReport report) => Enforce(true);

        static void OnPlayMode(PlayModeStateChange change)
        {
            if (change == PlayModeStateChange.EnteredEditMode) Enforce(false);
        }

        /// <summary>STP on every UniversalRenderPipelineAsset of the project; 'save' writes them to disk (before a build).</summary>
        public static void Enforce(bool save)
        {
            bool changed = false;
            foreach (var guid in AssetDatabase.FindAssets("t:UniversalRenderPipelineAsset", new[] { "Assets" }))   // not the package's own
            {
                var asset = AssetDatabase.LoadAssetAtPath<UniversalRenderPipelineAsset>(AssetDatabase.GUIDToAssetPath(guid));
                if (asset == null || asset.upscalingFilter == UpscalingFilterSelection.STP) continue;
                Debug.Log($"UrpStpGuard: {asset.name} had upscaling filter {asset.upscalingFilter}; set back to STP (keeps STP in builds).");
                asset.upscalingFilter = UpscalingFilterSelection.STP;
                EditorUtility.SetDirty(asset);
                changed = true;
            }
            if (changed && save) AssetDatabase.SaveAssets();
        }
    }
}
