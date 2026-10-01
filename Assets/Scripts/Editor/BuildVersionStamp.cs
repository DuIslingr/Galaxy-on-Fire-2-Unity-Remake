// BuildVersionStamp.cs
// Every player build gets its date and time as its version (BuildVersion.Format, e.g. 2026.09.29.2315): set into
// PlayerSettings.bundleVersion before the build (Application.version, Android's versionName) and put back once the build
// has finished or failed (EditorApplication.delayCall runs after BuildPipeline.BuildPlayer returns), so the project
// settings keep their own value. A release's builds share one version through GOF2_BUILD_VERSION (OverrideVariable).

using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;

namespace GoF2Remake.EditorTools
{
    public class BuildVersionStamp : IPreprocessBuildWithReport
    {
        // After BuildTargetGuard (int.MinValue), before the rest.
        public int callbackOrder => int.MinValue + 1;

        /// <summary>Set (System.Environment.SetEnvironmentVariable in the Editor) to give several builds the same version.</summary>
        public const string OverrideVariable = "GOF2_BUILD_VERSION";

        public void OnPreprocessBuild(BuildReport report)
        {
            string saved = PlayerSettings.bundleVersion;
            // A release's builds share one version: the Editor process's GOF2_BUILD_VERSION environment variable (it outlives
            // the domain reloads of switching platforms) wins over the build's own date and time.
            string stamp = System.Environment.GetEnvironmentVariable(OverrideVariable);
            if (string.IsNullOrWhiteSpace(stamp))
                stamp = System.DateTime.Now.ToString(GoF2Remake.UI.BuildVersion.Format, System.Globalization.CultureInfo.InvariantCulture);
            PlayerSettings.bundleVersion = stamp;
            UnityEngine.Debug.Log($"GoF2: build version {stamp}");
            // The build saves the project settings with the stamp in them: put the value back and save them again.
            EditorApplication.delayCall += () =>
            {
                PlayerSettings.bundleVersion = saved;
                AssetDatabase.SaveAssets();
            };
        }
    }
}
