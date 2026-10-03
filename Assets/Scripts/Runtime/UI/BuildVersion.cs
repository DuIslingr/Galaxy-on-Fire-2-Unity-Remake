// BuildVersion.cs
// The version shown in the main menu's credit line: the date and time the player was built (yyyy.MM.dd.HHmm, local
// time), stamped into PlayerSettings.bundleVersion by the Editor's BuildVersionStamp for each build, so Application.version
// (and Android's versionName) carries it. In the Editor: "editor".
// Fingerprint: what multiplayer compares instead (two builds of the same code play together, whenever they were built):
// the hash of the code and data the Editor's BuildFingerprint wrote into Resources/GoF2Build for the build; a build
// without it (older) falls back to its version.
// Commit: which code the build was made from, "<branch>@<short commit>" with "+dirty" when the working tree had uncommitted
// changes, written by BuildVersionStamp into Resources/GoF2Build/BuildCommit (git at build time; "" when git wasn't there).
// Full = "<version>-b<commit>" (just the version without one): the main menu's credit line, /version in the chat, the
// multiplayer window and the dedicated server's log show it, so a tester can tell which code a build runs.

using UnityEngine;

namespace GoF2Remake.UI
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class BuildVersion
    {
        public const string Format = "yyyy.MM.dd.HHmm";
        public const string FingerprintResource = "GoF2Build/BuildFingerprint";
        public const string CommitResource = "GoF2Build/BuildCommit";

        static string fingerprint, commit;

        /// <summary>The build's code: "branch@abc1234" (+dirty), "" when unknown; "local" in the Editor.</summary>
        public static string Commit
        {
            get
            {
                if (Application.isEditor) return "local";
                if (commit == null)
                {
                    var asset = Resources.Load<TextAsset>(CommitResource);
                    commit = asset != null ? asset.text.Trim() : "";
                }
                return commit;
            }
        }

        /// <summary>"2026.10.03.1530-bmp-server-profiles@a1b2c3d" (the version alone when the commit is unknown).</summary>
        public static string Full => Commit.Length > 0 ? $"{Text}-b{Commit}" : Text;

        public static string Text => Application.isEditor ? "editor" : Application.version;

        /// <summary>The code's fingerprint ("editor" in the Editor): the same for every build of the same code.</summary>
        public static string Fingerprint
        {
            get
            {
                if (Application.isEditor) return "editor";
                if (fingerprint == null)
                {
                    var asset = Resources.Load<TextAsset>(FingerprintResource);
                    string text = asset != null ? asset.text.Trim() : "";
                    fingerprint = text.Length > 0 ? text : Application.version;
                }
                return fingerprint;
            }
        }
    }
}
