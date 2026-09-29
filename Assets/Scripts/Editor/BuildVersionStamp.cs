// BuildVersionStamp.cs
// Every player build gets its date and time as its version (BuildVersion.Format, e.g. 2026.09.29.2315): set into
// PlayerSettings.bundleVersion before the build (Application.version, Android's versionName) and put back once the build
// has finished or failed (EditorApplication.delayCall runs after BuildPipeline.BuildPlayer returns), so the project
// settings keep their own value.

using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;

namespace GoF2Remake.EditorTools
{
    public class BuildVersionStamp : IPreprocessBuildWithReport
    {
        // After BuildTargetGuard (int.MinValue), before the rest.
        public int callbackOrder => int.MinValue + 1;

        public void OnPreprocessBuild(BuildReport report)
        {
            string saved = PlayerSettings.bundleVersion;
            string stamp = System.DateTime.Now.ToString(GoF2Remake.UI.BuildVersion.Format, System.Globalization.CultureInfo.InvariantCulture);
            PlayerSettings.bundleVersion = stamp;
            UnityEngine.Debug.Log($"GoF2: build version {stamp}");
            EditorApplication.delayCall += () => PlayerSettings.bundleVersion = saved;
        }
    }
}
