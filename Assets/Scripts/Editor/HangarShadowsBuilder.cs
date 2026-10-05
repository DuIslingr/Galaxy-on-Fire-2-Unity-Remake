// HangarShadowsBuilder.cs
// GoF2 > Build > Hangar Shadows: Resources/GoF2Station/ShipShadows (World.ShipShadowSet), the hangar ships' floor shadows
// (World.HangarShipShadow). Every ship assembly (category "ships": the hangars' fighters and the add-ons' ships) is
// spawned as the hangar spawns it (NPC variant, exhaust off; StationLevel.SpawnShip), its hull triangles
// (not the additive / LOD meshes) rasterised from above into a 128 x 128 map over a square 2.2 x the hull: R = the hull's
// underside (the lowest hull point over each texel above the hull's bottom, / heightRange; spread outward to the texels
// around it), G = the silhouette (lightly blurred), A = a wide soft halo of it (box blur, 3 passes), the part a camera
// looking down past the hull sees. Saved linear and uncompressed (R is data), with the square's centre and side, the
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
        const int N = 128, HaloRadius = 13, HaloPasses = 3;
        const float Margin = 2.2f;

        [MenuItem("GoF2/Build/Hangar Shadows", priority = 207)]
        public static void Build()
        {
            var db = Database.Load();
            Directory.CreateDirectory(Dir);
            var names = new SortedSet<string>();
            foreach (var a in db.Assemblies) if (a.category == "ships") names.Add(a.name);   // every ship, the add-ons' too
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
                // The hull's triangles in the ship's space, and its lowest point.
                var tris = new List<Vector3>();
                float bottom = float.PositiveInfinity;
                var min = new Vector2(float.PositiveInfinity, float.PositiveInfinity);
                var max = new Vector2(float.NegativeInfinity, float.NegativeInfinity);
                foreach (var mf in go.GetComponentsInChildren<MeshFilter>())
                {
                    if (mf.sharedMesh == null || !mf.gameObject.activeInHierarchy || mf.name.Contains("_add") || mf.name.Contains("_lod")) continue;
                    var mr = mf.GetComponent<MeshRenderer>();
                    if (mr == null || !mr.enabled) continue;
                    var m = mf.transform.localToWorldMatrix;
                    var v = mf.sharedMesh.vertices;
                    var t = mf.sharedMesh.triangles;
                    var w = new Vector3[v.Length];
                    for (int i = 0; i < v.Length; i++) { w[i] = m.MultiplyPoint3x4(v[i]); bottom = Mathf.Min(bottom, w[i].y); }
                    for (int i = 0; i + 2 < t.Length; i += 3)
                        for (int k = 0; k < 3; k++)
                        {
                            var p = w[t[i + k]];
                            tris.Add(p);
                            min = Vector2.Min(min, new Vector2(p.x, p.z));
                            max = Vector2.Max(max, new Vector2(p.x, p.z));
                        }
                }
                if (tris.Count == 0) return null;
                var c = (min + max) * 0.5f;
                float size = Mathf.Max(max.x - min.x, max.y - min.y) * Margin;
                float cell = size / N;
                var origin = c - new Vector2(size, size) * 0.5f;
                // The lowest hull point over each texel (infinity: no hull).
                var under = new float[N * N];
                for (int i = 0; i < under.Length; i++) under[i] = float.PositiveInfinity;
                Vector3 Grid(Vector3 p) => new Vector3((p.x - origin.x) / cell, p.y, (p.z - origin.y) / cell);
                for (int i = 0; i + 2 < tris.Count; i += 3) Fill(under, Grid(tris[i]), Grid(tris[i + 1]), Grid(tris[i + 2]));
                var core = new float[N * N];
                float top = bottom;
                for (int i = 0; i < under.Length; i++) if (!float.IsInfinity(under[i])) { core[i] = 1f; top = Mathf.Max(top, under[i]); }
                var halo = (float[])core.Clone();
                for (int pass = 0; pass < HaloPasses; pass++) { Blur(halo, true, HaloRadius); Blur(halo, false, HaloRadius); }
                Blur(core, true, 1);
                Blur(core, false, 1);
                Spread(under);
                float range = Mathf.Max(1f, top - bottom);
                var tex = new Texture2D(N, N, TextureFormat.RGBA32, false, true);
                var px = new Color32[N * N];
                for (int i = 0; i < px.Length; i++)
                    px[i] = new Color32(Byte((under[i] - bottom) / range), Byte(core[i]), 0, Byte(halo[i]));
                tex.SetPixels32(px);
                tex.Apply();
                entry = new ShipShadowSet.Entry { assembly = assembly, center = c, size = size, bottom = bottom, heightRange = range };
                return tex;
            }
            finally
            {
                Object.DestroyImmediate(go);
            }
        }

        static byte Byte(float v) => (byte)Mathf.RoundToInt(Mathf.Clamp01(v) * 255f);

        /// <summary>Fills a triangle (x / z in grid units, y in metres) into the map: the cells whose centres it covers keep
        /// the lowest height of it there.</summary>
        static void Fill(float[] under, Vector3 a3, Vector3 b3, Vector3 c3)
        {
            Vector2 a = new Vector2(a3.x, a3.z), b = new Vector2(b3.x, b3.z), c = new Vector2(c3.x, c3.z);
            float area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
            if (Mathf.Abs(area) < 1e-6f) return;
            int x0 = Mathf.Max(0, Mathf.FloorToInt(Mathf.Min(a.x, Mathf.Min(b.x, c.x)))), x1 = Mathf.Min(N - 1, Mathf.CeilToInt(Mathf.Max(a.x, Mathf.Max(b.x, c.x))));
            int y0 = Mathf.Max(0, Mathf.FloorToInt(Mathf.Min(a.y, Mathf.Min(b.y, c.y)))), y1 = Mathf.Min(N - 1, Mathf.CeilToInt(Mathf.Max(a.y, Mathf.Max(b.y, c.y))));
            float s = Mathf.Sign(area);
            for (int y = y0; y <= y1; y++)
            for (int x = x0; x <= x1; x++)
            {
                var p = new Vector2(x + 0.5f, y + 0.5f);
                float w0 = ((b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x)) * s;
                float w1 = ((c.x - b.x) * (p.y - b.y) - (c.y - b.y) * (p.x - b.x)) * s;
                float w2 = ((a.x - c.x) * (p.y - c.y) - (a.y - c.y) * (p.x - c.x)) * s;
                if (w0 < 0f || w1 < 0f || w2 < 0f) continue;
                // w1 weighs a (the edge opposite it), w2 b, w0 c.
                float h = (w1 * a3.y + w2 * b3.y + w0 * c3.y) / Mathf.Abs(area);
                if (h < under[y * N + x]) under[y * N + x] = h;
            }
        }

        /// <summary>Gives every texel without hull the height of the nearest one with it (a breadth-first spread).</summary>
        static void Spread(float[] under)
        {
            var queue = new Queue<int>();
            for (int i = 0; i < under.Length; i++) if (!float.IsInfinity(under[i])) queue.Enqueue(i);
            while (queue.Count > 0)
            {
                int i = queue.Dequeue(), x = i % N, y = i / N;
                void Try(int xx, int yy)
                {
                    if (xx < 0 || yy < 0 || xx >= N || yy >= N) return;
                    int j = yy * N + xx;
                    if (!float.IsInfinity(under[j])) return;
                    under[j] = under[i];
                    queue.Enqueue(j);
                }
                Try(x - 1, y); Try(x + 1, y); Try(x, y - 1); Try(x, y + 1);
            }
        }

        static void Blur(float[] mask, bool horizontal, int radius)
        {
            var copy = (float[])mask.Clone();
            for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++)
            {
                float sum = 0f;
                for (int k = -radius; k <= radius; k++)
                {
                    int xx = horizontal ? x + k : x, yy = horizontal ? y : y + k;
                    if (xx >= 0 && xx < N && yy >= 0 && yy < N) sum += copy[yy * N + xx];
                }
                mask[y * N + x] = sum / (2 * radius + 1);
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
