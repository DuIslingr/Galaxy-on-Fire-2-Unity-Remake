// SkySphereSmoothing.cs
// Modified (the user's requests): the supernova flares' sky sphere (sn_skybox_015_flares_1 / 2) is a low-poly UV sphere,
// 12 rings x 24 segments about its local Y: the texture's u runs from pole to pole in uneven steps per ring (0, 0.127,
// 0.240 ... 2) and v around it (one texture per 180 degrees), the vertex colours fade it out toward the poles. Its flat
// triangles showed as facets, and as the fire scrolls along u (PartAnimation's v5_0) its speed changed from one ring to the
// next, so the texture bent at every row of triangles. A smoother copy: every triangle split into four, Levels times, each
// new vertex pushed out onto the sphere, its u and colour from a smooth curve (Catmull-Rom) through the rings' own values at
// its angle from the pole, its v from its angle around the pole (both read from the mesh itself), so the scroll's speed
// changes smoothly from ring to ring instead of jumping at every row (the rings' uneven u steps stay).
// A mesh that isn't such a sphere gets plain halfway values. Midpoints are shared per edge (no cracks); the original mesh is
// left alone; one copy per mesh for the run. Needs a readable mesh (AssetImport makes these two Read/Write).

using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Rendering;

namespace GoF2Remake.World
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class SkySphereSmoothing
    {
        public const int Levels = 3;
        static readonly Dictionary<Mesh, Mesh> made = new Dictionary<Mesh, Mesh>();

        /// <summary>The u / colour per ring (by the angle from the pole, degrees) and how v follows the angle around it.</summary>
        internal sealed class Mapping
        {
            public readonly List<float> polar = new List<float>(), u = new List<float>();
            public readonly List<Color> colour = new List<Color>();
            public float vOffset, vSign;   // v = vSign * (azimuth - vOffset) / 180

            public float U(float p) => Spline(polar, u, p);
            public Color C(float p) => new Color(Spline(polar, colour, p, 0), Spline(polar, colour, p, 1), Spline(polar, colour, p, 2), Spline(polar, colour, p, 3));
            public float V(float az) => vSign * (az - vOffset) / 180f;
        }

        public static Mesh Smooth(Mesh mesh)
        {
            if (mesh == null) return null;
            if (made.TryGetValue(mesh, out var done) && done != null) return done;
            if (!mesh.isReadable) { Debug.LogWarning($"SkySphereSmoothing: {mesh.name} isn't readable (reimport it)"); return mesh; }
            var copy = Subdivide(mesh, Levels);
            copy.UploadMeshData(true);
            made[mesh] = copy;
            return copy;
        }

        /// <summary>The smoother copy, still readable (Smooth uploads it; the tests read it). 'mesh' must be readable.</summary>
        internal static Mesh Subdivide(Mesh mesh, int levels)
        {
            var verts = new List<Vector3>(mesh.vertices);
            var uvs = new List<Vector2>(mesh.uv);
            var cols = new List<Color>(mesh.colors);
            bool hasUv = uvs.Count == verts.Count, hasCol = cols.Count == verts.Count;
            var map = hasUv ? Fit(verts, uvs, hasCol ? cols : null) : null;
            var subs = new List<int[]>();
            for (int s = 0; s < mesh.subMeshCount; s++) subs.Add(mesh.GetTriangles(s));
            for (int level = 0; level < levels; level++)
            {
                var mid = new Dictionary<long, int>();
                int Mid(int a, int b)
                {
                    long key = a < b ? ((long)a << 32) | (uint)b : ((long)b << 32) | (uint)a;
                    if (mid.TryGetValue(key, out int m)) return m;
                    var pa = verts[a]; var pb = verts[b];
                    var p = (pa + pb) * 0.5f;
                    float r = (pa.magnitude + pb.magnitude) * 0.5f;
                    if (p.sqrMagnitude > 1e-12f) p = p.normalized * r;
                    m = verts.Count;
                    verts.Add(p);
                    var halfUv = hasUv ? (uvs[a] + uvs[b]) * 0.5f : Vector2.zero;
                    var halfCol = hasCol ? (cols[a] + cols[b]) * 0.5f : Color.white;
                    if (map != null)
                    {
                        Angles(p, out float polar, out float az);
                        float v = map.V(az);
                        v += 2f * Mathf.Round((halfUv.y - v) / 2f);   // the same turn as its edge's ends (the seam at v 0 / 2)
                        // Near the poles the angle around is meaningless: the halfway v there.
                        if (polar < 2f || polar > 178f) v = halfUv.y;
                        halfUv = new Vector2(map.U(polar), v);
                        if (hasCol) halfCol = map.C(polar);
                    }
                    if (hasUv) uvs.Add(halfUv);
                    if (hasCol) cols.Add(halfCol);
                    mid[key] = m;
                    return m;
                }
                for (int s = 0; s < subs.Count; s++)
                {
                    var t = subs[s];
                    var n = new int[t.Length * 4];
                    for (int i = 0, o = 0; i + 2 < t.Length; i += 3)
                    {
                        int a = t[i], b = t[i + 1], c = t[i + 2];
                        int ab = Mid(a, b), bc = Mid(b, c), ca = Mid(c, a);
                        n[o++] = a; n[o++] = ab; n[o++] = ca;
                        n[o++] = ab; n[o++] = b; n[o++] = bc;
                        n[o++] = ca; n[o++] = bc; n[o++] = c;
                        n[o++] = ab; n[o++] = bc; n[o++] = ca;
                    }
                    subs[s] = n;
                }
            }
            var copy = new Mesh { name = mesh.name + " (smooth)", indexFormat = verts.Count > 65000 ? IndexFormat.UInt32 : IndexFormat.UInt16 };
            copy.SetVertices(verts);
            if (hasUv) copy.SetUVs(0, uvs);
            if (hasCol) copy.SetColors(cols);
            copy.subMeshCount = subs.Count;
            for (int s = 0; s < subs.Count; s++) copy.SetTriangles(subs[s], s, false);
            copy.RecalculateBounds();
            copy.RecalculateNormals();
            return copy;
        }

        /// <summary>The angle from the local +Y pole and around it (degrees).</summary>
        static void Angles(Vector3 p, out float polar, out float az)
        {
            var d = p.normalized;
            polar = Mathf.Acos(Mathf.Clamp(d.y, -1f, 1f)) * Mathf.Rad2Deg;
            az = Mathf.Atan2(d.z, d.x) * Mathf.Rad2Deg;
        }

        /// <summary>The rings' u and colour by their angle from the pole, and v's line around it, read from the original
        /// vertices; null when the mesh isn't a UV sphere about Y (a ring's u differs, or v doesn't follow the angle).</summary>
        internal static Mapping Fit(List<Vector3> verts, List<Vector2> uvs, List<Color> cols)
        {
            var rings = new SortedDictionary<int, (float polar, float u, Color c, int n)>();
            float bestSpread = float.MaxValue;
            var map = new Mapping();
            foreach (float sign in new[] { 1f, -1f })
            {
                // v = sign (az - offset) / 180  ->  offset = az - sign 180 v (mod 360), the same for every vertex.
                float sx = 0f, sy = 0f;
                var offs = new List<float>();
                for (int i = 0; i < verts.Count; i++)
                {
                    Angles(verts[i], out float pol, out float az);
                    if (pol < 5f || pol > 175f) continue;
                    float o = az - sign * 180f * uvs[i].y;
                    offs.Add(o);
                    sx += Mathf.Cos(o * Mathf.Deg2Rad); sy += Mathf.Sin(o * Mathf.Deg2Rad);
                }
                if (offs.Count == 0) return null;
                float mean = Mathf.Atan2(sy, sx) * Mathf.Rad2Deg, spread = 0f;
                foreach (var o in offs) spread = Mathf.Max(spread, Mathf.Abs(Mathf.DeltaAngle(o, mean)));
                if (spread < bestSpread) { bestSpread = spread; map.vOffset = mean; map.vSign = sign; }
            }
            if (bestSpread > 3f) return null;
            for (int i = 0; i < verts.Count; i++)
            {
                Angles(verts[i], out float pol, out _);
                int key = Mathf.RoundToInt(pol * 2f);   // half-degree bins
                var c = cols != null ? cols[i] : Color.white;
                if (rings.TryGetValue(key, out var r))
                {
                    if (Mathf.Abs(r.u - uvs[i].x) > 0.01f) return null;   // a ring with two u: not this kind of sphere
                    rings[key] = (r.polar + pol, r.u, r.c + c, r.n + 1);
                }
                else rings[key] = (pol, uvs[i].x, c, 1);
            }
            foreach (var r in rings.Values)
            {
                map.polar.Add(r.polar / r.n);
                map.u.Add(r.u);
                map.colour.Add(r.c / r.n);
            }
            return map.polar.Count >= 3 ? map : null;
        }

        static float Spline(List<float> x, List<float> y, float p) => Spline(x, i => y[i], p);
        static float Spline(List<float> x, List<Color> y, float p, int ch) => Spline(x, i => y[i][ch], p);

        /// <summary>Catmull-Rom through (x, y), x ascending; flat beyond the ends.</summary>
        static float Spline(List<float> x, System.Func<int, float> y, float p)
        {
            int n = x.Count;
            if (p <= x[0]) return y(0);
            if (p >= x[n - 1]) return y(n - 1);
            int i = 0;
            while (i < n - 2 && p > x[i + 1]) i++;
            float x0 = x[i], x1 = x[i + 1];
            float t = (p - x0) / Mathf.Max(x1 - x0, 1e-4f);
            float y1 = y(i), y2 = y(i + 1);
            // Tangents by the neighbours' slopes (finite differences over the uneven spacing).
            float m1 = i > 0 ? (y2 - y(i - 1)) / (x1 - x[i - 1]) * (x1 - x0) : (y2 - y1);
            float m2 = i + 2 < n ? (y(i + 2) - y1) / (x[i + 2] - x0) * (x1 - x0) : (y2 - y1);
            float t2 = t * t, t3 = t2 * t;
            return (2f * t3 - 3f * t2 + 1f) * y1 + (t3 - 2f * t2 + t) * m1 + (-2f * t3 + 3f * t2) * y2 + (t3 - t2) * m2;
        }
    }
}
