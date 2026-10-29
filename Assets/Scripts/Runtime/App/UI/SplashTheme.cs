// SplashTheme.cs
// Remake: Resources/GoF2Music/MenuTheme, what SplashMusic plays from Unity's splash screen: a reference to the menu theme
// (Audio/MUSIC/Space_NoCombat_Void, event 145) rather than a copy of it in Resources, so the clip ships once.

using UnityEngine;

namespace GoF2Remake.UI
{
    public class SplashTheme : ScriptableObject
    {
        [Tooltip("The main menu's theme (MainMenu.menuMusic), event 145 Space_NoCombat_Void.")]
        public AudioClip clip;
    }
}
