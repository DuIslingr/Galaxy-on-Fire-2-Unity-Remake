// WeaponBuilder.cs  (Editor only)
// Menu "GoF2/Build Weapon Fx": turns Resources/GoF2Data/weapon_fx.json (made by
// Reference/tools/weapons/build_weapon_fx.py from Reference/research/weapons.md) into one WeaponFx asset per
// weapon item in Resources/GoF2Weapons/item_XXX: projectile, muzzle flash and impact prefabs (single-mesh prefabs,
// or the assembled prefab for rockets) and the shot sound (.ogg by name). Also makes CombatAudio (asteroid
// destroyed, target lock) and cuts the HUD crosshair (normal / hit) from Textures/textures/gof2_interface.png.

using System.Collections.Generic;
using System.IO;
using System.Linq;
using GoF2Remake.Flight;
using UnityEditor;
using UnityEngine;

namespace GoF2Remake.EditorTools
{
    public static class WeaponBuilder
    {
        const string OutDir = ImportSettings.Root + "/Resources/" + WeaponFx.ResourcesFolder;
        const string HudImageDir = ImportSettings.Root + "/UI/Flight/Images";

        [System.Serializable] class Entry { public int item; public string projectile, muzzle, impact, sound; public bool beam, soundLoops; public int soundId; }
        [System.Serializable] class Wrapper { public List<Entry> list; }

        /// <summary>Shot sounds the FEV name order doesn't reach (DLC ids above 213 and a few gaps), matched by file name
        /// (weapons_special.md).</summary>
        static readonly Dictionary<int, string> ShotSounds = new Dictionary<int, string>
        {
            { 42, "Launch_Missile_EMP_GL2" }, { 43, "Launch_Missile_EMP_GLDX" }, { 45, "Rocket_Launch_AMR_Oppressor" },
            { 46, "Rocket_Launch_AMR_Extinction" }, { 60, "AMR_Claymor" }, { 61, "Neetha" }, { 62, "Ksannk" },
            { 176, "Nirai50" }, { 177, "Berger_Flak" }, { 178, "Icarus_Heavy" }, { 179, "Liberator_Launch" },
            { 180, "Berger_AGT" }, { 181, "Skuld_AT_XR" }, { 182, "Turret_HH_AT_Archimedes" }, { 183, "Laser_Disruptor" },
            { 193, "Sunfire" }, { 197, "Launch" }, { 221, "Launch" }, { 214, "Launch_02" }, { 215, "Launch_02" },
            { 216, "Launch_02" }, { 224, "Turret_Matador_TS" }, { 226, "Shockblast" }, { 228, "M6_A4_RACOON" },
            { 229, "DarkMatterLaser" }, { 230, "Canon_Massdriver" }, { 231, "Blaster_Mimung" }, { 232, "Fireworks" },
            { 211, "Berger_SG100" }, { 212, "SentryGun_SG400" }, { 213, "TSuum" },
        };

        /// <summary>Explosion::playSound by weapon and the BombGun / ObjectGun explosion types (weapons_special.md 3.4).</summary>
        static readonly Dictionary<int, (int type, string sound)> Explosions = new Dictionary<int, (int, string)>
        {
            { 41, (7, "Explosion_EMP_GL1") }, { 42, (7, "Explosion_EMP_GL2") }, { 43, (7, "Explosion_EMP_GLDX") },
            { 44, (0, "Explosion_Bomb_AMR_Tormentor") }, { 45, (0, "Explosion_Bomb_AMR_Oppressor") },
            { 46, (0, "Explosion_Bomb_AMR_Exctinctor") }, { 179, (0, "Explosion_Bomb_AMR_Exctinctor") },
            { 60, (0, "Garbage_Explosion") }, { 61, (0, "Garbage_Explosion") }, { 62, (0, "Garbage_Explosion") },
            { 176, (8, "Garbage_Explosion") }, { 177, (9, "Garbage_Explosion") }, { 178, (10, "Garbage_Explosion") },
            { 197, (0, "Plasma_Rocket_Explosion") }, { 221, (0, "Plasma_Rocket_Explosion") },
            { 226, (11, null) }, { 232, (13, "Fireworks") },
        };

        /// <summary>Turret items -> their assembled ship-mounted prefab; sentry items -> the deployed object.</summary>
        static readonly Dictionary<int, string> Turrets = new Dictionary<int, string>
        {
            { 47, "turret_001_ship_mounted" }, { 48, "turret_002_ship_mounted" }, { 49, "turret_003_ship_mounted" },
            { 180, "v_autoturret_001_anim_ship_mounted" }, { 181, "v_autoturret_002_ship_mounted" },
            { 182, "v_autoturret_003_ship_mounted" }, { 224, "sn_turret_004_ship_mounted" },
            // The plasma collectors (sort 35): the same pivot / base / gun build, the plasma stream under the gun.
            { 198, "sn_plasma_collector_001_ship_mounted" }, { 199, "sn_plasma_collector_002_ship_mounted" },
            { 200, "sn_plasma_collector_003_ship_mounted" },
        };

        [MenuItem("GoF2/Build Weapon Fx", priority = 13)]
        public static void Build()
        {
            var json = AssetDatabase.LoadAssetAtPath<TextAsset>($"{ImportSettings.Root}/Resources/GoF2Data/weapon_fx.json");
            if (json == null) { Debug.LogError("GoF2: run Reference/tools/weapons/build_weapon_fx.py first"); return; }
            var entries = JsonUtility.FromJson<Wrapper>("{\"list\":" + json.text + "}").list;
            Directory.CreateDirectory(OutDir);
            var clips = AssetDatabase.FindAssets("t:AudioClip", new[] { ImportSettings.Root + "/Audio" })
                .Select(AssetDatabase.GUIDToAssetPath).ToList();
            int made = 0;
            // Sentry guns aren't in the projectile tables: they deploy an object that fires the look of items 2 / 20 / 14.
            foreach (int s in new[] { 211, 212, 213 })
                if (!entries.Exists(x => x.item == s)) entries.Add(new Entry { item = s });
            // Nor are the plasma collectors (no projectile): only their mounted model.
            foreach (int s in new[] { 198, 199, 200 })
                if (!entries.Exists(x => x.item == s)) entries.Add(new Entry { item = s });
            foreach (var e in entries)
            {
                string path = $"{OutDir}/item_{e.item:000}.asset";
                var fx = AssetDatabase.LoadAssetAtPath<WeaponFx>(path);
                if (fx == null) { fx = ScriptableObject.CreateInstance<WeaponFx>(); AssetDatabase.CreateAsset(fx, path); }
                fx.item = e.item;
                fx.projectile = FindPrefab(e.projectile);
                fx.muzzleFlash = FindPrefab(e.muzzle);
                fx.impact = FindPrefab(e.impact);
                fx.shot = ShotSounds.TryGetValue(e.item, out var shotName) ? FindClip(clips, shotName) : FindClip(clips, e.sound);
                fx.shotLoops = e.soundLoops;
                if (Explosions.TryGetValue(e.item, out var ex)) { fx.explosionType = ex.type; fx.explosionSound = FindClip(clips, ex.sound); }
                else { fx.explosionType = -1; fx.explosionSound = null; }
                fx.engineLoop = e.item == 179 ? FindClip(clips, "AMR_Liberator_Engine") : null;
                fx.turretMounted = Turrets.TryGetValue(e.item, out var turret) ? FindPrefab(turret) : null;
                fx.sentry = e.item >= 211 && e.item <= 213 ? FindPrefab($"sn_sentry_gun_00{e.item - 210}") : null;
                EditorUtility.SetDirty(fx);
                made++;
            }

            string audioPath = $"{OutDir}/CombatAudio.asset";
            var audio = AssetDatabase.LoadAssetAtPath<CombatAudio>(audioPath);
            if (audio == null) { audio = ScriptableObject.CreateInstance<CombatAudio>(); AssetDatabase.CreateAsset(audio, audioPath); }
            audio.asteroidDestroyed = FindClip(clips, "Destruction_Asteroid");
            audio.targetLock = FindClip(clips, "Target_Lock");
            audio.miningDrill = FindClip(clips, "Mining_Drill_Add_1");
            audio.miningLanding = FindClip(clips, "Mining_Landing");
            audio.miningDrillBroken = FindClip(clips, "Mining_Drill_Broken");
            audio.autopilotOn = FindClip(clips, "Autopilot_Activate");
            audio.autopilotOff = FindClip(clips, "Autopilot_Deactivate");
            audio.jumpToPlanet = FindClip(clips, "Jump_to_planets");
            EditorUtility.SetDirty(audio);

            BuildCrosshair();
            AssetDatabase.SaveAssets();
            Debug.Log($"GoF2: {made} weapon fx assets in {OutDir}.");
        }

        /// <summary>Rockets/bombs are assembled objects (with their flame child); everything else a single-mesh prefab.</summary>
        static GameObject FindPrefab(string name)
        {
            if (string.IsNullOrEmpty(name)) return null;
            GameObject single = null, assembled = null;
            foreach (var guid in AssetDatabase.FindAssets($"{name} t:Prefab"))
            {
                string p = AssetDatabase.GUIDToAssetPath(guid);
                if (Path.GetFileNameWithoutExtension(p) != name) continue;
                var go = AssetDatabase.LoadAssetAtPath<GameObject>(p);
                if (p.Contains("/Resources/Assembled/")) assembled = go; else single = go;
            }
            var result = assembled != null ? assembled : single;
            if (result == null) Debug.LogWarning($"GoF2: weapon fx prefab '{name}' not found");
            return result;
        }

        /// <summary>Exact file name first, then the first file that starts with it (e.g. Laser_Nirai_Charged_Impulse_v01).</summary>
        static AudioClip FindClip(List<string> clips, string name)
        {
            if (string.IsNullOrEmpty(name)) return null;
            string lower = name.ToLowerInvariant();
            string path = clips.FirstOrDefault(p => Path.GetFileNameWithoutExtension(p).ToLowerInvariant() == lower)
                          ?? clips.FirstOrDefault(p => Path.GetFileNameWithoutExtension(p).ToLowerInvariant().StartsWith(lower));
            return path != null ? AssetDatabase.LoadAssetAtPath<AudioClip>(path) : null;
        }

        /// <summary>Crosshair 0x4c0 (339, 814, 40x40) and the orange "hit" one 0x4ce (339, 856) (weapons.md section 9).</summary>
        static void BuildCrosshair()
        {
            string src = $"{ImportSettings.Root}/Textures/textures/gof2_interface.png";
            if (!File.Exists(src)) return;
            var tex = new Texture2D(2, 2, TextureFormat.RGBA32, false);
            tex.LoadImage(File.ReadAllBytes(src));
            Directory.CreateDirectory(HudImageDir);
            Cut(tex, 339, 814, 40, 40, $"{HudImageDir}/crosshair.png");
            Cut(tex, 339, 856, 40, 40, $"{HudImageDir}/crosshair_hit.png");
            Object.DestroyImmediate(tex);
        }

        static void Cut(Texture2D tex, int x, int y, int w, int h, string path)
        {
            var px = tex.GetPixels(x, tex.height - y - h, w, h);   // rects are top-left based
            var o = new Texture2D(w, h, TextureFormat.RGBA32, false);
            o.SetPixels(px);
            o.Apply();
            File.WriteAllBytes(path, o.EncodeToPNG());
            Object.DestroyImmediate(o);
            AssetDatabase.ImportAsset(path, ImportAssetOptions.ForceSynchronousImport);
            var ti = (TextureImporter)AssetImporter.GetAtPath(path);
            ti.textureType = TextureImporterType.Sprite;
            ti.mipmapEnabled = false;
            ti.alphaIsTransparency = true;
            ti.SaveAndReimport();
        }
    }
}
