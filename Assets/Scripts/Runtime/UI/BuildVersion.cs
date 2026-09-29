// BuildVersion.cs
// The version shown in the main menu's credit line: the date and time the player was built (yyyy.MM.dd.HHmm, local
// time), stamped into PlayerSettings.bundleVersion by the Editor's BuildVersionStamp for each build, so Application.version
// (and Android's versionName) carries it. In the Editor: "editor".

using UnityEngine;

namespace GoF2Remake.UI
{
    public static class BuildVersion
    {
        public const string Format = "yyyy.MM.dd.HHmm";

        public static string Text => Application.isEditor ? "editor" : Application.version;
    }
}
