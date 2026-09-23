// GoF2WeaponBuilder.cs  (Editor only)
// Menu "GoF2/Build Weapon Fx": turns Resources/GoF2Data/weapon_fx.json (made by
// Reference/tools/weapons/build_weapon_fx.py from Reference/research/weapons.md) into one GoF2WeaponFx asset per
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
    public static class GoF2WeaponBuilder
    {
        const string OutDir = GoF2ImportSettings.Root + "/Resources/" + GoF2WeaponFx.ResourcesFolder;
        const string HudImageDir = GoF2ImportSettings.Root + "/UI/Flight/Images";

        [System.Serializable] class Entry { public int item; public string projectile, muzzle, impact, sound; public bool beam, soundLoops; public int soundId; }
        [System.Serializable] class Wrapper { public List<Entry> list; }

        [MenuItem("GoF2/Build Weapon Fx", priority = 13)]
        public static void Build()
        {
            var json = AssetDatabase.LoadAssetAtPath<TextAsset>($"{GoF2ImportSettings.Root}/Resources/GoF2Data/weapon_fx.json");
            if (json == null) { Debug.LogError("GoF2: run Reference/tools/weapons/build_weapon_fx.py first"); return; }
            var entries = JsonUtility.FromJson<Wrapper>("{\"list\":" + json.text + "}").list;
            Directory.CreateDirectory(OutDir);
            var clips = AssetDatabase.FindAssets("t:AudioClip", new[] { GoF2ImportSettings.Root + "/Audio" })
                .Select(AssetDatabase.GUIDToAssetPath).ToList();
            int made = 0;
            foreach (var e in entries)
            {
                string path = $"{OutDir}/item_{e.item:000}.asset";
                var fx = AssetDatabase.LoadAssetAtPath<GoF2WeaponFx>(path);
                if (fx == null) { fx = ScriptableObject.CreateInstance<GoF2WeaponFx>(); AssetDatabase.CreateAsset(fx, path); }
                fx.item = e.item;
                fx.projectile = FindPrefab(e.projectile);
                fx.muzzleFlash = FindPrefab(e.muzzle);
                fx.impact = FindPrefab(e.impact);
                fx.shot = FindClip(clips, e.sound);
                fx.shotLoops = e.soundLoops;
                EditorUtility.SetDirty(fx);
                made++;
            }

            string audioPath = $"{OutDir}/CombatAudio.asset";
            var audio = AssetDatabase.LoadAssetAtPath<GoF2CombatAudio>(audioPath);
            if (audio == null) { audio = ScriptableObject.CreateInstance<GoF2CombatAudio>(); AssetDatabase.CreateAsset(audio, audioPath); }
            audio.asteroidDestroyed = FindClip(clips, "Destruction_Asteroid");
            audio.targetLock = FindClip(clips, "Target_Lock");
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
            string src = $"{GoF2ImportSettings.Root}/Textures/textures/gof2_interface.png";
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
