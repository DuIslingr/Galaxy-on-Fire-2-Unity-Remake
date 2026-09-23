// GoF2LanguageTables.cs
// References every Localization/text_<lang>.json (Resources/GoF2LanguageTables, made by the scene builders) so any scene
// can load the text table on first use, also when it is started without the main menu (GoF2Localization.Get).

using UnityEngine;

namespace GoF2Remake.Data
{
    public class GoF2LanguageTables : ScriptableObject
    {
        public const string ResourceName = "GoF2LanguageTables";

        public string[] codes;
        public TextAsset[] tables;

        public static GoF2LanguageTables Load() => Resources.Load<GoF2LanguageTables>(ResourceName);
    }
}
