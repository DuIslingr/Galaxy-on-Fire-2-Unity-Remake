// SupernovaAssets.cs
// What the Supernova add-on's systems load that has no name to look up at runtime (Resources/GoF2Story/SupernovaAssets,
// made by "GoF2 > Build Supernova Assets"): the DLC2 sounds and music. The FMOD event ids above 213 (0x8be-0x8ea, 2238-2282)
// aren't in fmod_event_ids.txt; the clips are name-matched to the DLC2 banks (noted per field).

using UnityEngine;

namespace GoF2Remake.Data
{
    public class SupernovaAssets : ScriptableObject
    {
        [Header("Docking and hacking")]
        public AudioClip docking;          // 0x8de (2270) DLC2_SFX/Docking_Landing_01
        public AudioClip hackingTurn;      // 0x8e2 (2274) Hacking_Dialling_1
        public AudioClip hackingSolved;    // 0x8e1 (2273) Hacking_Solved_1
        public AudioClip transferLoop;     // Transport_Loop (the loading / unloading, name-matched)

        [Header("Plasma")]
        public AudioClip plasmaCollected;  // 2256 Container_01
        public AudioClip ionizingBlast;    // 2253 Plasma_Rocket_Explosion

        [Header("Story sounds")]
        public AudioClip carrierJump;      // 0x8ca (2250) CS102_CarrierJump_2
        public AudioClip valkyrieBeam;     // 0x8c7 (2247) GOF2_Valkyrie_RayBeam_1
        public AudioClip selfDestruct;     // Selfdestruct_Warning
        public AudioClip explosion;        // 0x8c3 / 0x8c4 (2243 / 2244) DLC2_SFX/Explosion
        public AudioClip launch;           // Launch (the freighter / carrier leaving, 0x8c9)

        [Header("Music")]
        public AudioClip wantedMusic;      // 151 SN_WantedBoardCriminals (20120527_GOF2_Addon_WantedBoardCriminal)
        public AudioClip stealthMusic1;    // 149 (20120527_GOF2_Addon_StealthFighter1)
        public AudioClip stealthMusic2;    // 150 (StealthFighter2)
        public AudioClip gammaRayMusic;    // the supernova system (20120527_GOF2_Addon_GammarRaySystems)
        public AudioClip supernovaIntro;   // 0x8be (2238) GOF2_SN_CS_1_02 (index 89's cutscene)
        public AudioClip katashunMusic;    // 0x8bf (2239) GOF2SN_CS_126_Trunt1_02 (Katashun during 126 / 133)
        public AudioClip mission102;       // 0x8c0 (2240) GOF2_Mission_102_CutScene
        public AudioClip mission102Loop;   // 0x8c1 (2241) GOF2_Mission_102_CutScene_Loop

        [Header("Sky")]
        public Material supernovaIntroSky;  // Level::createSpace at index 89: skybox_005 instead of the supernova sky

        static SupernovaAssets instance;
        public static SupernovaAssets Load() => instance != null ? instance : instance = Resources.Load<SupernovaAssets>("GoF2Story/SupernovaAssets");
    }
}
