// BuildVersion.cs
// The version shown in the main menu's credit line: the date and time the player was built (yyyy.MM.dd.HHmm, local
// time), stamped into PlayerSettings.bundleVersion by the Editor's BuildVersionStamp for each build, so Application.version
// (and Android's versionName) carries it. In the Editor: "editor".
// Fingerprint: what multiplayer compares instead (two builds of the same code play together, whenever they were built):
// the hash of the code and data the Editor's BuildFingerprint wrote into Resources/GoF2Build for the build; a build
// without it (older) falls back to its version.

using UnityEngine;

namespace GoF2Remake.UI
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class BuildVersion
    {
        public const string Format = "yyyy.MM.dd.HHmm";
        public const string FingerprintResource = "GoF2Build/BuildFingerprint";

        static string fingerprint;

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
