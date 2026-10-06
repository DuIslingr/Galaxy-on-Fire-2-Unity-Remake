// HangarShadowsBuilder.cs
// GoF2 > Build > Hangar Shadows: Resources/GoF2Station/ShipShadows (World.ShipShadowSet), the hangar ships' floor shadows
// (World.HangarShipShadow). Every ship assembly (category "ships": the hangars' fighters and the add-ons' ships) is
// spawned as the hangar spawns it (NPC variant, exhaust off; StationLevel.SpawnShip) and its hull baked by
// World.ShipShadowBaker (the same code bakes the mods' ships at run time): a 128 x 128 map over a square 2.2 x the hull,
// R = the hull's underside, G = the silhouette, A = a wide soft halo, the part a camera looking down past the hull
// sees. Saved linear and uncompressed (R is data), with the square's centre and side, the
// hull's lowest point and the height range. Also the shadow material (GoF2/HangarShadow, the decal-like projection,
// black) and a soft oval for ships without an entry. In a preview scene: the open scene is untouched. Run again after
// changing a ship model.

using System.Collections.Generic;
using System.IO;
using GoF2Remake.Data;
using GoF2Remake.World;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace GoF2Remake.EditorTools
{
    public static class HangarShadowsBuilder
    {
        const string Dir = "Assets/Resources/GoF2Station/ShipShadows";
        const string SetPath = "Assets/Resources/GoF2Station/ShipShadows.asset";
        const string MaterialPath = "Assets/Resources/GoF2Station/HangarShipShadow.mat";

        [MenuItem("GoF2/Build/Hangar Shadows", priority = 207)]
        public static void Build()
        {
            var db = Database.Load();
            Directory.CreateDirectory(Dir);
            var names = new SortedSet<string>();
            // Every ship, the add-ons' too; not the mods' (their "ship_NNN_mod" numbers differ between games: baked at run time).
            foreach (var a in db.Assemblies) if (a.category == "ships" && a.pack != Modding.ModShips.Pack) names.Add(a.name);
            var set = AssetDatabase.LoadAssetAtPath<ShipShadowSet>(SetPath);
            if (set == null) { set = ScriptableObject.CreateInstance<ShipShadowSet>(); AssetDatabase.CreateAsset(set, SetPath); }
            set.entries.Clear();
            var scene = EditorSceneManager.NewPreviewScene();
            var made = new List<(ShipShadowSet.Entry entry, string path)>();
            try
            {
                foreach (var name in names)
                {
                    var r = Bake(db, name, scene, out var entry);
                    if (r == null) continue;
                    string path = $"{Dir}/{name}.png";
                    File.WriteAllBytes(path, r.EncodeToPNG());
                    Object.DestroyImmediate(r);
                    made.Add((entry, path));
                }
            }
            finally
            {
                EditorSceneManager.ClosePreviewScene(scene);
            }
            string ovalPath = $"{Dir}/_oval.png";
            File.WriteAllBytes(ovalPath, Oval().EncodeToPNG());
            AssetDatabase.Refresh();
            foreach (var p in new List<string>(made.ConvertAll(m => m.path)) { ovalPath })
            {
                var ti = (TextureImporter)AssetImporter.GetAtPath(p);
                if (ti == null) continue;
                ti.textureType = TextureImporterType.Default;
                ti.alphaIsTransparency = false;
                ti.alphaSource = TextureImporterAlphaSource.FromInput;
                ti.sRGBTexture = false;
                ti.textureCompression = TextureImporterCompression.Uncompressed;
                ti.wrapMode = TextureWrapMode.Clamp;
                ti.mipmapEnabled = false;
                ti.SaveAndReimport();
            }
            foreach (var (entry, path) in made)
            {
                entry.texture = AssetDatabase.LoadAssetAtPath<Texture2D>(path);
                set.entries.Add(entry);
            }
            set.oval = AssetDatabase.LoadAssetAtPath<Texture2D>(ovalPath);
            var shader = Shader.Find("GoF2/HangarShadow");
            var mat = AssetDatabase.LoadAssetAtPath<Material>(MaterialPath);
            if (mat == null && shader != null) { mat = new Material(shader); AssetDatabase.CreateAsset(mat, MaterialPath); }
            if (mat != null)
            {
                if (shader != null) mat.shader = shader;
                mat.SetTexture("_MainTex", set.oval);
                mat.SetColor("_Color", new Color(0f, 0f, 0f, 0.85f));
                EditorUtility.SetDirty(mat);
            }
            set.material = mat;
            EditorUtility.SetDirty(set);
            AssetDatabase.SaveAssets();
            Debug.Log($"GoF2: {set.entries.Count} hangar ship shadows in {Dir}");
        }

        /// <summary>One ship's mask (white, the shadow in alpha) and its square; null when it has no hull meshes.</summary>
        static Texture2D Bake(Database db, string assembly, Scene scene, out ShipShadowSet.Entry entry)
        {
            entry = null;
            var prefab = Visuals.AssembledObject.LoadPrefab(db.AssemblyByName(assembly));
            if (prefab == null) return null;
            var go = Object.Instantiate(prefab, Vector3.zero, Quaternion.identity);
            SceneManager.MoveGameObjectToScene(go, scene);
            try
            {
                var asm = go.GetComponent<Visuals.AssembledObject>();
                if (asm != null)
                {
                    asm.SetPlayerVariant(false);
                    if (asm.npcVariantParts != null) foreach (var p in asm.npcVariantParts) if (p != null) p.SetActive(false);
                }
                // The hull's triangles in the ship's space and its lowest point, rasterised from above (ShipShadowBaker).
                var tris = new List<Vector3>();
                if (!ShipShadowBaker.Collect(go, tris, out float bottom, true)) return null;
                var r = ShipShadowBaker.Rasterise(tris, bottom);
                if (r == null) return null;
                entry = new ShipShadowSet.Entry { assembly = assembly, center = r.center, size = r.size, bottom = r.bottom, heightRange = r.heightRange };
                return ShipShadowBaker.ToTexture(r, assembly);
            }
            finally
            {
                Object.DestroyImmediate(go);
            }
        }

        /// <summary>A soft oval (a disc fading out from 40 % of its radius; R 0 = the hull's bottom everywhere) for ships
        /// without a baked shadow.</summary>
        static Texture2D Oval()
        {
            var tex = new Texture2D(64, 64, TextureFormat.RGBA32, false, true);
            for (int y = 0; y < 64; y++)
            for (int x = 0; x < 64; x++)
            {
                float d = new Vector2((x + 0.5f) / 32f - 1f, (y + 0.5f) / 32f - 1f).magnitude;
                tex.SetPixel(x, y, new Color(0f, d < 0.55f ? 1f : 0f, 0f, Mathf.Clamp01((1f - d) / 0.6f)));
            }
            tex.Apply();
            return tex;
        }
    }
}
