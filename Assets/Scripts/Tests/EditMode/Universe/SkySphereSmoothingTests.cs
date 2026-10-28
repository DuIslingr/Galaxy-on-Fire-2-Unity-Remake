// SkySphereSmoothingTests.cs
// Feature: CLAUDE.md "Space scene" (docs/notes/space-scene.md, the supernova flares): SkySphereSmoothing subdivides the
// flares' low-poly UV sphere onto the sphere. Expected: no cracks (every edge, by position, shared by two triangles: the
// midpoints are shared per edge, the seam's duplicates land on the same spot), every vertex on the sphere, v following the
// angle around the pole with the seam's column kept at v 2 (no triangle wrapping across the texture), the rings' own u at
// their angles; a mesh that isn't such a sphere (Fit null) gets plain halfway UVs. Also SkyLayers.FlaresFade (the flares'
// 75 % instead of the sidecars' 50).

using System.Collections.Generic;
using GoF2Remake.World;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class SkySphereSmoothingTests
    {
        const int Rings = 12, Segments = 24;
        const float Radius = 10f;
        readonly List<Object> made = new List<Object>();

        [TearDown]
        public void TearDown() { foreach (var o in made) if (o != null) Object.DestroyImmediate(o); made.Clear(); }

        /// <summary>Ring r's u: uneven steps from 0 to 2 like the flares' (0, 0.127, 0.240 ... 2).</summary>
        static float RingU(int r) => 2f * Mathf.Pow(r / (float)Rings, 1.3f);

        /// <summary>A UV sphere about +Y like the flares': (Rings + 1) x (Segments + 1) vertices (the poles and the seam
        /// duplicated), u per ring, v = the angle around / 180 (0 .. 2), the colour fading toward the poles.</summary>
        Mesh Sphere(bool scrambleV = false)
        {
            var verts = new List<Vector3>(); var uvs = new List<Vector2>(); var cols = new List<Color>();
            var rnd = new System.Random(7);
            for (int r = 0; r <= Rings; r++)
                for (int s = 0; s <= Segments; s++)
                {
                    float th = Mathf.PI * r / Rings, ph = 2f * Mathf.PI * s / Segments;
                    verts.Add(new Vector3(Mathf.Sin(th) * Mathf.Cos(ph), Mathf.Cos(th), Mathf.Sin(th) * Mathf.Sin(ph)) * Radius);
                    uvs.Add(new Vector2(RingU(r), scrambleV ? (float)rnd.NextDouble() * 2f : 2f * s / Segments));
                    cols.Add(new Color(1f, 1f, 1f, Mathf.Sin(th)));
                }
            var tris = new List<int>();
            int W = Segments + 1;
            for (int r = 0; r < Rings; r++)
                for (int s = 0; s < Segments; s++)
                {
                    int a = r * W + s, b = (r + 1) * W + s, c = (r + 1) * W + s + 1, d = r * W + s + 1;
                    if (r != Rings - 1) { tris.Add(a); tris.Add(b); tris.Add(c); }   // b, c the bottom pole: degenerate
                    if (r != 0) { tris.Add(a); tris.Add(c); tris.Add(d); }           // a, d the top pole: degenerate
                }
            var m = new Mesh { name = "test sphere" };
            m.SetVertices(verts); m.SetUVs(0, uvs); m.SetColors(cols); m.SetTriangles(tris, 0);
            made.Add(m);
            return m;
        }

        Mesh Smooth(Mesh m)
        {
            var copy = SkySphereSmoothing.Subdivide(m, SkySphereSmoothing.Levels);
            made.Add(copy);
            return copy;
        }

        static (long, long, long) Key(Vector3 p) => (Mathf.RoundToInt(p.x * 1000f), Mathf.RoundToInt(p.y * 1000f), Mathf.RoundToInt(p.z * 1000f));

        static void Angles(Vector3 p, out float polar, out float az)
        {
            var d = p.normalized;
            polar = Mathf.Acos(Mathf.Clamp(d.y, -1f, 1f)) * Mathf.Rad2Deg;
            az = Mathf.Atan2(d.z, d.x) * Mathf.Rad2Deg;
        }

        [Test]
        public void Smoothed_sphere_has_no_cracks_and_stays_on_the_sphere()
        {
            var m = Smooth(Sphere());
            var v = m.vertices; var t = m.triangles;
            Assert.AreEqual(Sphere().triangles.Length * (int)Mathf.Pow(4, SkySphereSmoothing.Levels), t.Length);
            foreach (var p in v) Assert.AreEqual(Radius, p.magnitude, 1e-3f, "a vertex off the sphere");
            var edges = new Dictionary<((long, long, long), (long, long, long)), int>();
            for (int i = 0; i < t.Length; i += 3)
                for (int k = 0; k < 3; k++)
                {
                    var a = Key(v[t[i + k]]); var b = Key(v[t[i + (k + 1) % 3]]);
                    var e = a.CompareTo(b) < 0 ? (a, b) : (b, a);
                    edges[e] = edges.TryGetValue(e, out int n) ? n + 1 : 1;
                }
            foreach (var kv in edges) Assert.AreEqual(2, kv.Value, $"edge {kv.Key} used {kv.Value} times (a crack)");
        }

        [Test]
        public void V_follows_the_angle_around_and_the_seam_keeps_v_2()
        {
            var src = Sphere();
            int original = src.vertexCount;
            var m = Smooth(src);
            var v = m.vertices; var uv = m.uv; var t = m.triangles;
            bool seamMid = false;
            for (int i = 0; i < v.Length; i++)
            {
                Angles(v[i], out float polar, out float az);
                Assert.That(uv[i].y, Is.InRange(-1e-4f, 2f + 1e-4f));
                if (polar < 2f || polar > 178f) continue;
                float expected = Mathf.Repeat(az / 180f, 2f);
                float d = Mathf.Abs(Mathf.Repeat(uv[i].y - expected + 1f, 2f) - 1f);
                Assert.Less(d, 1e-3f, $"vertex {i}: v {uv[i].y} at {az} deg");
                if (i >= original && Mathf.Abs(az) < 1e-2f && uv[i].y > 1.999f) seamMid = true;
            }
            Assert.IsTrue(seamMid, "no new vertex on the seam column at v 2");
            for (int i = 0; i < t.Length; i += 3)
            {
                float lo = Mathf.Min(uv[t[i]].y, Mathf.Min(uv[t[i + 1]].y, uv[t[i + 2]].y));
                float hi = Mathf.Max(uv[t[i]].y, Mathf.Max(uv[t[i + 1]].y, uv[t[i + 2]].y));
                Assert.Less(hi - lo, 0.5f, $"triangle {i / 3} wraps across the texture");
            }
        }

        [Test]
        public void Fit_reads_the_rings_u_and_the_original_vertices_stay()
        {
            var src = Sphere();
            var map = SkySphereSmoothing.Fit(new List<Vector3>(src.vertices), new List<Vector2>(src.uv), new List<Color>(src.colors));
            Assert.IsNotNull(map);
            Assert.AreEqual(Rings + 1, map.polar.Count);
            for (int r = 0; r <= Rings; r++)
            {
                Assert.AreEqual(180f * r / Rings, map.polar[r], 0.05f);
                Assert.AreEqual(RingU(r), map.U(map.polar[r]), 1e-4f);
            }
            var m = Smooth(src);
            var sv = src.vertices; var suv = src.uv; var mv = m.vertices; var muv = m.uv;
            for (int i = 0; i < sv.Length; i++) { Assert.AreEqual(sv[i], mv[i]); Assert.AreEqual(suv[i], muv[i]); }
        }

        [Test]
        public void Not_a_uv_sphere_gets_halfway_uvs()
        {
            // A flat quad: one "ring" with four different u.
            var quad = new Mesh { name = "test quad" };
            made.Add(quad);
            quad.vertices = new[] { new Vector3(-1f, 0f, -1f), new Vector3(1f, 0f, -1f), new Vector3(1f, 0f, 1f), new Vector3(-1f, 0f, 1f) };
            quad.uv = new[] { new Vector2(0f, 0f), new Vector2(1f, 0f), new Vector2(1f, 1f), new Vector2(0f, 1f) };
            quad.triangles = new[] { 0, 2, 1, 0, 3, 2 };
            Assert.IsNull(SkySphereSmoothing.Fit(new List<Vector3>(quad.vertices), new List<Vector2>(quad.uv), null));
            var m = Smooth(quad);
            float step = 1f / (1 << SkySphereSmoothing.Levels);
            foreach (var uv in m.uv)
            {
                Assert.AreEqual(0f, Mathf.Abs(uv.x / step - Mathf.Round(uv.x / step)), 1e-4f, $"u {uv.x} isn't a halfway value");
                Assert.AreEqual(0f, Mathf.Abs(uv.y / step - Mathf.Round(uv.y / step)), 1e-4f, $"v {uv.y} isn't a halfway value");
            }
            // A sphere whose v doesn't follow the angle around.
            var scrambled = Sphere(scrambleV: true);
            Assert.IsNull(SkySphereSmoothing.Fit(new List<Vector3>(scrambled.vertices), new List<Vector2>(scrambled.uv), null));
        }

        [Test]
        public void Flares_fade_to_75_from_100()
        {
            Assert.AreEqual(100f, SkyLayers.FlaresFade(100f), 1e-4f);
            Assert.AreEqual(SkyLayers.FlaresOpacity, SkyLayers.FlaresFade(SkyLayers.FlaresOriginalOpacity), 1e-4f);
            Assert.AreEqual(87.5f, SkyLayers.FlaresFade(75f), 1e-4f);
        }
    }
}
