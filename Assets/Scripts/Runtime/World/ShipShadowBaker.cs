// ShipShadowBaker.cs
// Remake: a hangar ship's floor shadow map (ShipShadowSet's format, HangarShipShadow), made from its hull triangles seen
// from above: rasterised into a 128 x 128 map over a square 2.2 x the hull, R = the hull's underside (the lowest hull
// point over each texel above the hull's bottom, / heightRange; spread outward to the texels around it), G = the
// silhouette (lightly blurred), A = a wide soft halo of it (box blur, 3 passes). The Editor's "GoF2 > Build > Hangar
// Shadows" (HangarShadowsBuilder) bakes the game's ships with it; at run time it bakes the ships the set has no entry for
// whose meshes are readable (the mods' ships: glTFast keeps its meshes readable), once per assembly and set of mods, the
// rasterising on a worker thread (Request / Bake). The game's own meshes are imported non-readable, so the debug capital
// hulls keep the soft oval.

using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;

namespace GoF2Remake.World
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class ShipShadowBaker
    {
        public const int N = 128;
        const int HaloRadius = 13, HaloPasses = 3;
        const float Margin = 2.2f;

        /// <summary>A baked map: the pixels (linear RGBA) and where they lie in the ship's space (Unity metres, scale 1).</summary>
        public sealed class Result
        {
            public Color32[] pixels;
            public Vector2 center;
            public float size, bottom, heightRange;
        }

        // ---- run time: ships without a baked entry ----------------------------------------------------------------

        static readonly Dictionary<string, Task<Result>> pending = new Dictionary<string, Task<Result>>();
        static readonly Dictionary<string, ShipShadowSet.Entry> baked = new Dictionary<string, ShipShadowSet.Entry>();
        static int revision = -1;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { pending.Clear(); baked.Clear(); revision = -1; }

        /// <summary>The mods changed: a ship type's model may be another one now.</summary>
        static void Check()
        {
            if (revision == Modding.ModManager.Revision) return;
            foreach (var e in baked.Values) if (e?.texture != null) Object.Destroy(e.texture);
            baked.Clear();
            pending.Clear();
            revision = Modding.ModManager.Revision;
        }

        /// <summary>A mod's ship (ModShipBuilder's template: origin "mod <id>"): baked here, never from the set.</summary>
        public static bool IsModShip(GameObject ship)
        {
            var asm = ship != null ? ship.GetComponent<Visuals.AssembledObject>() : null;
            return asm != null && asm.origin != null && asm.origin.StartsWith("mod ");
        }

        /// <summary>The run-time map of 'assembly' (null: none yet). The first call for a ship type with readable meshes
        /// starts its bake ('ship' an instance of it); false = it can't be baked here (non-readable meshes or no hull),
        /// so the caller keeps the oval.</summary>
        public static bool Request(string assembly, GameObject ship, out ShipShadowSet.Entry entry)
        {
            Check();
            entry = null;
            if (string.IsNullOrEmpty(assembly)) return false;
            if (baked.TryGetValue(assembly, out entry)) return entry != null;
            if (pending.TryGetValue(assembly, out var task))
            {
                if (!task.IsCompleted) return true;
                pending.Remove(assembly);
                entry = task.Status == TaskStatus.RanToCompletion ? ToEntry(assembly, task.Result) : null;
                if (task.IsFaulted) Debug.LogWarning($"Hangar shadow of {assembly}: {task.Exception?.GetBaseException().Message}");
                baked[assembly] = entry;
                return entry != null;
            }
            var tris = new List<Vector3>();
            if (!Collect(ship, tris, out float bottom, false)) { baked[assembly] = null; return false; }
            pending[assembly] = Task.Run(() => Rasterise(tris, bottom));
            return true;
        }

        static ShipShadowSet.Entry ToEntry(string assembly, Result r)
        {
            if (r == null) return null;
            return new ShipShadowSet.Entry
            {
                assembly = assembly, texture = ToTexture(r, assembly + " shadow"),
                center = r.center, size = r.size, bottom = r.bottom, heightRange = r.heightRange,
            };
        }

        /// <summary>The map as the shader reads it: linear, uncompressed, clamped, no mips.</summary>
        public static Texture2D ToTexture(Result r, string name)
        {
            var tex = new Texture2D(N, N, TextureFormat.RGBA32, false, true) { name = name, wrapMode = TextureWrapMode.Clamp };
            tex.SetPixels32(r.pixels);
            tex.Apply(false, !Application.isEditor || Application.isPlaying);
            return tex;
        }

        // ---- the bake ---------------------------------------------------------------------------------------------

        /// <summary>The hull's triangles in the ship's own space (scale 1) and its lowest point: every active, enabled mesh
        /// but the additive layers, the LOD meshes and the mod ships' engine / throttle glows. 'anyMesh': read non-readable
        /// meshes too (the Editor can); else false when one of them isn't readable (a build can't).</summary>
        public static bool Collect(GameObject ship, List<Vector3> tris, out float bottom, bool anyMesh)
        {
            bottom = float.PositiveInfinity;
            if (ship == null) return false;
            var root = ship.transform.worldToLocalMatrix;
            var vertices = new List<Vector3>();
            var triangles = new List<int>();
            foreach (var mf in ship.GetComponentsInChildren<MeshFilter>())
            {
                var mesh = mf.sharedMesh;
                if (mesh == null || !mf.gameObject.activeInHierarchy) continue;
                string n = mf.name;
                if (n.Contains("_add") || n.Contains("_lod") || n.StartsWith("engine_glow") || n.StartsWith("throttle_glow")) continue;
                var mr = mf.GetComponent<MeshRenderer>();
                if (mr == null || !mr.enabled) continue;
                if (!mesh.isReadable && !anyMesh) return false;
                var m = root * mf.transform.localToWorldMatrix;
                mesh.GetVertices(vertices);
                int start = tris.Count;
                for (int s = 0; s < mesh.subMeshCount; s++)
                {
                    var topology = mesh.GetTopology(s);
                    if (topology != MeshTopology.Triangles) continue;
                    mesh.GetTriangles(triangles, s);
                    foreach (int i in triangles) tris.Add(m.MultiplyPoint3x4(vertices[i]));
                }
                for (int i = start; i < tris.Count; i++) bottom = Mathf.Min(bottom, tris[i].y);
            }
            return tris.Count > 0;
        }

        /// <summary>The map of the triangles (thread-safe: no Unity objects).</summary>
        public static Result Rasterise(List<Vector3> tris, float bottom)
        {
            if (tris == null || tris.Count < 3) return null;
            var min = new Vector2(float.PositiveInfinity, float.PositiveInfinity);
            var max = new Vector2(float.NegativeInfinity, float.NegativeInfinity);
            foreach (var p in tris)
            {
                min = Vector2.Min(min, new Vector2(p.x, p.z));
                max = Vector2.Max(max, new Vector2(p.x, p.z));
            }
            var c = (min + max) * 0.5f;
            float size = Mathf.Max(max.x - min.x, max.y - min.y) * Margin;
            if (size <= 0f) return null;
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
            var px = new Color32[N * N];
            for (int i = 0; i < px.Length; i++)
                px[i] = new Color32(Byte((under[i] - bottom) / range), Byte(core[i]), 0, Byte(halo[i]));
            return new Result { pixels = px, center = c, size = size, bottom = bottom, heightRange = range };
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
    }
}
