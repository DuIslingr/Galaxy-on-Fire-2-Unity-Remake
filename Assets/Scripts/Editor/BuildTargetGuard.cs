// BuildTargetGuard.cs
// Stops a build whose platform isn't the Editor's active build target. URP chooses the shader variants to keep from the
// quality levels of the *active* target (ShaderBuildPreprocessor.HandleEnabledShaderStripping ->
// EditorUserBuildSettings.activeBuildTarget.TryGetRenderPipelineAssets), not the platform being built: an Android build
// made while Windows was active only saw the PC quality level (Mobile is excluded on Standalone), stripped URP's
// post-processing shaders (UberPost) and the phone's lit variants, and rendered lit geometry black. Switch the build
// profile first (File > Build Profiles > Switch Profile), then build.

using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;

namespace GoF2Remake.EditorTools
{
    public class BuildTargetGuard : IPreprocessBuildWithReport
    {
        // Before URP's own preprocessing (its shader stripping data is gathered from the active target).
        public int callbackOrder => int.MinValue;

        public void OnPreprocessBuild(BuildReport report)
        {
            var building = report.summary.platform;
            var active = EditorUserBuildSettings.activeBuildTarget;
            if (building == active) return;
            throw new BuildFailedException(
                $"Building {building} while {active} is the active build target: URP would keep the wrong shader variants " +
                $"(the {active} quality levels) and the build would render wrongly. Switch the active build profile to " +
                $"{building} first (File > Build Profiles > Switch Profile), then build.");
        }
    }
}
