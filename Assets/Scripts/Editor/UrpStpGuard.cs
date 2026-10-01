// UrpStpGuard.cs  (Editor only)
// Keeps every URP pipeline asset saved with STP as its upscaling filter. URP's STPResourceStripper drops STP's compute
// shaders from a player build unless a pipeline asset uses STP, and the in-game upscaler option (Bootstrap) changes the
// asset while playing; Bootstrap restores it when Play mode ends, but a script recompile during Play mode loses that
// restore, and a build then saved the asset without STP (the APK froze when STP was picked on Android).
// Enforced on Editor load, whenever Play mode ends, and before every player build.
// With the upscaler framework compiled in (ENABLE_UPSCALER_FRAMEWORK, the Standalone platforms: UpscalerFramework) URP reads
// STP's use from the asset's upscaler priority list instead (isStpUsed), so the guard also keeps that list holding every
// upscaler the game offers (STP, DLSS, FSR 4 / 3 / 2, FSR 1, Auto); the game picks one at runtime (SetUpscaler), and the
// scaling mode stays None so the Editor's own views render plain. The old filter stays STP for the Android builds (no
// framework there). The list only exists while the framework is compiled: switching to Android and saving the asset drops
// it, and the guard puts it back on the next load / build with the framework.

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
                if (asset == null) continue;
#pragma warning disable 618   // the old filter: obsolete with the framework, still what the Android builds use
                if (asset.upscalingFilter != UpscalingFilterSelection.STP)
                {
                    Debug.Log($"UrpStpGuard: {asset.name} had upscaling filter {asset.upscalingFilter}; set back to STP (keeps STP in builds).");
                    asset.upscalingFilter = UpscalingFilterSelection.STP;
                    EditorUtility.SetDirty(asset);
                    changed = true;
                }
#pragma warning restore 618
#if ENABLE_UPSCALER_FRAMEWORK
                changed |= EnforcePriority(asset);
#endif
            }
            if (changed && save) AssetDatabase.SaveAssets();
        }

#if ENABLE_UPSCALER_FRAMEWORK
        /// <summary>The upscalers every asset lists (the ones registered in this Editor), highest priority first.</summary>
        static readonly string[] Priority = { "unity.stp", "nvidia.dlss4", "amd.fsr4", "amd.fsr3", "amd.fsr2", "amd.fsr1", "unity.auto" };

        /// <summary>The asset's m_UpscalerPriority (internal) set to Priority through its serialized form; true if it changed.</summary>
        static bool EnforcePriority(UniversalRenderPipelineAsset asset)
        {
            var wanted = new System.Collections.Generic.List<(string id, string name)>();
            foreach (var id in Priority)
                if (UnityEngine.Rendering.UpscalerRegistry.s_RegisteredUpscalers.TryGetValue(id, out var reg)) wanted.Add((id, reg.DisplayName));
            var so = new SerializedObject(asset);
            var list = so.FindProperty("m_UpscalerPriority");
            if (list == null || !list.isArray) return false;
            bool same = list.arraySize == wanted.Count;
            for (int i = 0; same && i < wanted.Count; i++)
                same = list.GetArrayElementAtIndex(i).FindPropertyRelative("upscalerId").stringValue == wanted[i].id;
            if (same) return false;
            list.arraySize = wanted.Count;
            for (int i = 0; i < wanted.Count; i++)
            {
                var e = list.GetArrayElementAtIndex(i);
                e.FindPropertyRelative("upscalerId").stringValue = wanted[i].id;
                e.FindPropertyRelative("upscalerName").stringValue = wanted[i].name;
            }
            so.ApplyModifiedPropertiesWithoutUndo();
            EditorUtility.SetDirty(asset);
            Debug.Log($"UrpStpGuard: {asset.name}'s upscaler list set to {string.Join(", ", wanted.ConvertAll(w => w.id))} (keeps them in builds).");
            return true;
        }
#endif
    }
}
