// GoF2StarMapAssets.cs
// What the star map and the system jumps need that can't be loaded by name (Resources/GoF2StarMap/StarMapAssets, made by
// GoF2 > Build Star Map Assets): the overlay UXML and panel settings, the galaxy-view sun materials (mesh 18070 + system
// texture index -> its material), the Khador jump fx (mesh 15026) and the sounds (starmap_travel.md 11.1):
//   103 Select_System, 104 / 105 Map_Select_Planet_Push / _Release, 106 / 107 Map_Zoom_In / _Out, 124 / 123 / 126 buttons and
//   message box, 31 Jumpgate (Jumpgate_1b..3b, one at random), 33 Jumpgate_Charge, 32 KhadorDrive (no .ogg by that name:
//   Jumpgate_4c stands in, unverified). 102 Map_Whoosh has no known file and is left out.

using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class GoF2StarMapAssets : ScriptableObject
    {
        public const string ResourcePath = "GoF2StarMap/StarMapAssets";

        public VisualTreeAsset layout;
        public PanelSettings panelSettings;
        [Tooltip("Indexed by the system's textureIndex.")]
        public Material[] sunMaterials;
        public GameObject khadorJump;

        public AudioClip selectSystem, planetPush, planetRelease, zoomIn, zoomOut;
        public AudioClip buttonPush, buttonRelease, infoSound;
        public AudioClip[] jumpgate;
        public AudioClip jumpgateCharge, khadorDrive;

        static GoF2StarMapAssets cached;
        public static GoF2StarMapAssets Load() => cached != null ? cached : cached = Resources.Load<GoF2StarMapAssets>(ResourcePath);
    }
}
