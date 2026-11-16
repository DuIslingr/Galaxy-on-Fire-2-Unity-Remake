// PlayerAssetsBuild.cs
// Feature: docs/notes/player-assets.md "Builds without the originals": a player build made from a checkout without the
// original's assets (the test bed, a sparse checkout: exactly what such a build ships) for checking the content layer in a
// real player. Batch mode, development build (so $GOF2_ORIGINAL_CACHE can point it at a converted copy):
//   Unity -batchmode -buildTarget Linux64 -projectPath <checkout> -executeMethod
//     GoF2Remake.EditorTools.PlayerAssetsBuild.LinuxDevelopment   ($GOF2_BUILD_OUT: the folder, else Build/PlayerAssets/Linux)

using System;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEditor.Build.Reporting;
using UnityEngine;

namespace GoF2Remake.EditorTools
{
    public static class PlayerAssetsBuild
    {
        public static void LinuxDevelopment()
        {
            string dir = Environment.GetEnvironmentVariable("GOF2_BUILD_OUT");
            if (string.IsNullOrEmpty(dir)) dir = Path.GetFullPath("Build/PlayerAssets/Linux");
            Directory.CreateDirectory(dir);
            var options = new BuildPlayerOptions
            {
                scenes = EditorBuildSettings.scenes.Where(s => s.enabled).Select(s => s.path).ToArray(),
                locationPathName = Path.Combine(dir, "GoF2Remake.x86_64"),
                target = BuildTarget.StandaloneLinux64,
                options = BuildOptions.Development,
            };
            // The stylesheets again: imported while their images were left out (stripped_checkout's placeholders came after),
            // they kept no reference, and UiImageSlots had no texture to fill.
            foreach (var guid in AssetDatabase.FindAssets("t:StyleSheet", new[] { "Assets" }).Concat(AssetDatabase.FindAssets("t:ThemeStyleSheet", new[] { "Assets" })))
                AssetDatabase.ImportAsset(AssetDatabase.GUIDToAssetPath(guid), ImportAssetOptions.ForceUpdate);
            // (BuildVersionStamp puts the version back after the build in a delayCall, which an exit right after never runs)
            string version = PlayerSettings.bundleVersion;
            var report = BuildPipeline.BuildPlayer(options);
            PlayerSettings.bundleVersion = version;
            AssetDatabase.SaveAssets();
            var s = report.summary;
            Debug.Log($"GoF2: player-assets build {s.result}: {s.totalSize / 1048576} MB, {s.totalTime.TotalMinutes:0.0} min, {s.totalErrors} errors -> {dir}");
            if (Application.isBatchMode) EditorApplication.Exit(s.result == BuildResult.Succeeded ? 0 : 1);
        }
    }
}
