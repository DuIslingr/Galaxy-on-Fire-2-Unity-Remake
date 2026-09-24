// GoF2CombatAssetsBuilder.cs  (Editor only)
// Menu "GoF2/Build Combat Assets": Resources/GoF2Combat/CombatAssets (GoF2CombatAssets), the prefabs and sounds of ship
// combat (crates, wrecks, explosion, tractor beams, hit / death / music clips). Run by Create Space Scene.

using System.IO;
using System.Linq;
using GoF2Remake.Flight;
using UnityEditor;
using UnityEngine;

namespace GoF2Remake.EditorTools
{
    public static class GoF2CombatAssetsBuilder
    {
        const string Root = GoF2ImportSettings.Root;
        public const string AssetPath = Root + "/Resources/" + GoF2CombatAssets.ResourcePath + ".asset";

        [MenuItem("GoF2/Build Combat Assets", priority = 17)]
        public static void Build()
        {
            Directory.CreateDirectory(Path.GetDirectoryName(AssetPath));
            var a = AssetDatabase.LoadAssetAtPath<GoF2CombatAssets>(AssetPath);
            if (a == null) { a = ScriptableObject.CreateInstance<GoF2CombatAssets>(); AssetDatabase.CreateAsset(a, AssetPath); }

            a.crates = new[] { "container_003_terran", "container_004_vossk", "container_002_nivelian", "container_001_midorian", "container_005_void" }
                .Select(n => Prefab($"Prefabs/main/misc/{n}.prefab")).ToArray();
            a.wrecks = new[] { "cargo_003_terran", "cargo_004_vossk", "cargo_002_nivelian", "cargo_001_midorian", "battleship_terran" }
                .Select(n => Prefab($"Prefabs/main/ships/{n}_explosion_anim.prefab")).ToArray();
            a.explosion = Prefab("Resources/Assembled/main/fx/explosion_anim_lookat_alpha.prefab");
            a.debris = Prefab("Prefabs/main/fx/explosion_debris_anim_add.prefab");
            a.junk = new[] { "space_junk_001", "space_junk_002", "space_junk_003" }.Select(n => Prefab($"Prefabs/main/misc/{n}.prefab")).ToArray();
            a.tractorBeams = new[] { Find("projectile_068_anim_add"), Find("projectile_069_anim_add"), Find("projectile_070_anim_add"), Find("v_projectile_194_anim_add") };

            a.smokeMaterial = AssetDatabase.LoadAssetAtPath<Material>($"{Root}/Materials/mat_20101_sprite_smoke.mat");
            a.fireMaterial = AssetDatabase.LoadAssetAtPath<Material>($"{Root}/Materials/mat_27250_sprite_fire.mat");
            if (a.smokeMaterial == null || a.fireMaterial == null) Debug.LogWarning("GoF2: missing sprite_smoke / sprite_fire materials");
            a.hitShield = Clips("SFX_SPACE", "Incoming_Fire_Shield");
            a.hitArmor = Clips("SFX_SPACE", "Incoming_Fire_Armor");
            a.hitHull = Clips("SFX_SPACE", "Incoming_Fire_Hull");
            a.shipDestroyed = Clips("SFX_SPACE", "Destruction_Ship_Small");
            a.explosionBig = Clips("SFX_SPACE", "Destruction_Ship_Big");
            a.explosionMid = Clips("SFX_SPACE", "Destruction_Ship_Med");
            a.shots = new[] { Clip("SFX_SPACE/Laser_Nirai_Impulse_EX1_V01.ogg"), Clip("SFX_SPACE/Laser_Shkoom_v02.ogg"),
                              Clip("SFX_SPACE/Laser_Nirai_Charged_Impulse_v01.ogg"), Clip("SFX_SPACE/Laser_Nirai_Impulse_EX2_V01.ogg"),
                              Clip("SFX_SPACE/Laser_Enemy_V04b.ogg") };
            a.targetLock = Clip("SFX_SPACE/Target_Lock_v08.ogg");
            a.tractorLoop = Clip("SFX_SPACE/Tractor_Beam_v1.ogg");
            a.tractorClose = Clip("SFX_SPACE/Tractor_Beam_Close_Door_01c.ogg");
            a.gameOver = Clip("SFX_SPACE/game_over_v02.ogg");
            a.missionAccomplished = Clip("SFX_SPACE/Mission_Accomplished_v05.ogg");
            a.enemyEngines = new[] { "Engine_09", "Engine_newnew_05", "Engine_newnew_02", "Engine_newnew_06_mixdown", "Engine_newnew_03" }
                .Select(n => Clip($"SFX_SPACE/{n}.ogg")).ToArray();
            a.freighterEngines = new[] { Clip("SFX_SPACE/Engine_Freighter_03.ogg"), Clip("SFX_SPACE/Engine_Freighter_02.ogg") };
            a.spaceMusic = new[] { Clip("MUSIC/Space_Terraner.ogg"), Clip("MUSIC/Space_Vossk.ogg"), Clip("MUSIC/Space_Nivelianer.ogg"), Clip("MUSIC/Space_Midorianer.ogg") };
            a.battleMusic = new[] { Clip("MUSIC/Space_Battle_Low.ogg"), Clip("MUSIC/Space_Battle_Medium.ogg"), Clip("MUSIC/Space_Battle_Full.ogg") };

            EditorUtility.SetDirty(a);
            AssetDatabase.SaveAssets();
            Debug.Log($"GoF2: combat assets at {AssetPath} ({a.crates.Count(c => c != null)} crates, {a.wrecks.Count(w => w != null)} wrecks, " +
                      $"{a.tractorBeams.Count(t => t != null)} tractor beams, explosion {(a.explosion != null)}).");
        }

        static GameObject Prefab(string rel)
        {
            var p = AssetDatabase.LoadAssetAtPath<GameObject>($"{Root}/{rel}");
            if (p == null) Debug.LogWarning($"GoF2: missing prefab {rel}");
            return p;
        }

        static GameObject Find(string name)
        {
            foreach (var guid in AssetDatabase.FindAssets($"{name} t:Prefab", new[] { $"{Root}/Prefabs" }))
            {
                string path = AssetDatabase.GUIDToAssetPath(guid);
                if (Path.GetFileNameWithoutExtension(path) == name) return AssetDatabase.LoadAssetAtPath<GameObject>(path);
            }
            Debug.LogWarning($"GoF2: missing prefab {name}");
            return null;
        }

        static AudioClip Clip(string rel)
        {
            var c = AssetDatabase.LoadAssetAtPath<AudioClip>($"{Root}/Audio/{rel}");
            if (c == null) Debug.LogWarning($"GoF2: missing audio {rel}");
            return c;
        }

        static AudioClip[] Clips(string folder, string prefix) =>
            Directory.GetFiles($"{Root}/Audio/{folder}", prefix + "*.ogg").OrderBy(p => p)
                .Select(p => AssetDatabase.LoadAssetAtPath<AudioClip>(p.Replace('\\', '/'))).Where(c => c != null).ToArray();
    }
}
