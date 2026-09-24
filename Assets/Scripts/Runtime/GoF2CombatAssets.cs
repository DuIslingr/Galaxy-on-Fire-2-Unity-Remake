// GoF2CombatAssets.cs
// What ship combat needs that can't be loaded by name (Resources/GoF2Combat/CombatAssets, made by GoF2 > Build Combat
// Assets; Reference/research/ship_combat.md 5, 8 and npc_traffic_ai.md 8):
//   crates      container_003_terran / 004_vossk / 002_nivelian / 001_midorian / 005_void (KIPlayer::createCrate)
//   wrecks      cargo_003_terran / 004_vossk / 002_nivelian / 001_midorian _explosion_anim, battleship_terran_explosion_anim
//   explosion   Explosion type 0: explosion_anim_lookat_alpha (+ _add child), 3..9 explosion_debris streaks
//   tractor     beam meshes of items 68, 69, 70, 194 (projectile_068..070, v_projectile_194)
//   smoke       materials 20101 sprite_smoke (alpha) / 27250 sprite_fire (additive) of the burning-ship sprites (GoF2ShipSmoke)
//   sounds      25 / 23 / 24 incoming fire shield / armor / hull, 20 ship destroyed, 18 / 19 explosion big / mid,
//               0 tractor beam loop, 4 tractor door, 37 game over, NPC shots per race (52, 55, 54, 53, 61), engine loops
//               46 Spaceship_Engine_Enemy / 47 Spaceship_Engine_Freighter: their FEV sound definitions Engine_Enemy_01 (one
//               of Engine_09, Engine_newnew_05 / 02 / 06_mixdown / 03, equal weights) and Engine_Freighter (Engine_Freighter_03 / 02)
//   music       134 / 139 / 138 / 137 space no-combat per race, 140 / 141 / 142 Space_Battle_Low / Medium / Full

using UnityEngine;

namespace GoF2Remake.Flight
{
    public class GoF2CombatAssets : ScriptableObject
    {
        public const string ResourcePath = "GoF2Combat/CombatAssets";

        [Tooltip("Terran, Vossk, Nivelian, Midorian, Void.")]
        public GameObject[] crates;
        [Tooltip("Freighter wrecks by race (Terran, Vossk, Nivelian, Midorian), then the battleship.")]
        public GameObject[] wrecks;
        public GameObject explosion, debris;
        [Tooltip("Items 68, 69, 70, 194.")]
        public GameObject[] tractorBeams;
        public Material smokeMaterial, fireMaterial;

        public AudioClip[] hitShield, hitArmor, hitHull, shipDestroyed, explosionBig, explosionMid, shots;
        public AudioClip targetLock, tractorLoop, tractorClose, gameOver;
        [Tooltip("Sound 36 Mission_accomplished.")]
        public AudioClip missionAccomplished;
        [Tooltip("Sound 46: one picked per ship.")]
        public AudioClip[] enemyEngines;
        [Tooltip("Sound 47: one picked per ship.")]
        public AudioClip[] freighterEngines;
        [Tooltip("No-combat music by race: Terran, Vossk, Nivelian, Midorian.")]
        public AudioClip[] spaceMusic;
        [Tooltip("Space_Battle_Low, Medium, Full.")]
        public AudioClip[] battleMusic;

        static GoF2CombatAssets cached;
        public static GoF2CombatAssets Load() => cached != null ? cached : cached = Resources.Load<GoF2CombatAssets>(ResourcePath);

        public GameObject Crate(int race) => crates == null || crates.Length < 5 ? null
            : race == 0 ? crates[0] : race == 1 ? crates[1] : race == 3 ? crates[3] : race == 9 ? crates[4] : crates[2];

        public GameObject Tractor(int item) => tractorBeams == null || tractorBeams.Length < 4 ? null
            : item == 68 ? tractorBeams[0] : item == 69 ? tractorBeams[1] : item == 70 ? tractorBeams[2] : tractorBeams[3];

        public static AudioClip Pick(AudioClip[] clips) => clips == null || clips.Length == 0 ? null : clips[Random.Range(0, clips.Length)];
    }
}
