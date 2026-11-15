// NebulaClouds.cs
// Remake (2026-11-14, the user: EVERSPACE 2's sky methods in the base game, without ES2's files): Options > Graphics "Nebula
// clouds" (Settings.NebulaClouds, off by default: the original has none). Clouds of gas round the orbit, in its own sky's
// colours, that the player flies through and past with real parallax, as EVERSPACE 2's local nebulae (BP_Skybox_Nebula_Local,
// read from its compiled script): of 101 random points in a sphere of the cloud's radius, those under HalfHeight x radius x
// r^2 off its plane (r random 0..1: a flattened disc, densest in its middle) each become a flat sprite at a random turn, 1-3 x
// its piece size, with its own random values (the mask's scale and offset) and one of the mask's three channels; drawn by
// GoF2/NebulaCloud (M_Nebula_Local_Parent's look). ES2's levels have 1-5 of them (most two), 20 km across with their middles a
// few km out, density 1, their own colours; here 0-3 by how much of the orbit's sky its nebula covers, sized to GoF2's orbits
// (the level's far plane is 15 km), their colours the main colours of the orbit's nebula sky (nebula_clouds.json), all seeded
// by the station, so an orbit's clouds are the same on every visit.
using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.World
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public sealed class NebulaClouds : MonoBehaviour
    {
        public const int Candidates = 101;          // ES2: 0..100 (51 on consoles)
        public const float HalfHeight = 0.3f;       // ES2's default
        public const float MinRadius = 6000f, MaxRadius = 14000f;   // m
        public const float PieceShare = 0.25f;     // a piece's half-size per (1-3 x) the radius: ES2's 5 km planes at 1-3 x radius / 10 km

        [System.Serializable] public sealed class Rgbw { public float r, g, b, weight; }
        [System.Serializable] public sealed class Sky { public float coverage, brightness; public Rgbw[] colors; }
        [System.Serializable] sealed class Table { public Sky[] nebulae; }

        static Table table;
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)] static void ResetStatics() => table = null;

        /// <summary>The cloud look of GoF2's nebula sky 'index' (0-18); null without one.</summary>
        public static Sky Of(int index)
        {
            if (table == null)
            {
                var asset = Resources.Load<TextAsset>("GoF2SkyLayers/nebula_clouds");
                table = asset != null ? JsonUtility.FromJson<Table>(asset.text) : new Table { nebulae = new Sky[0] };
            }
            return index >= 0 && index < table.nebulae.Length ? table.nebulae[index] : null;
        }

        /// <summary>How many clouds an orbit under a sky with this coverage has: none under the barest skies, three in the
        /// ones that fill the sky.</summary>
        public static int CountFor(float coverage) => coverage >= 0.5f ? 3 : coverage >= 0.06f ? 2 : coverage >= 0.025f ? 1 : 0;

        public struct Piece { public Vector3 position; public Quaternion turn; public float size; public Vector4 random; public int channel; }

        /// <summary>One cloud's pieces, ES2's placement (its radius, in its own frame: the disc's plane is its xy).</summary>
        public static List<Piece> Pieces(System.Random rng, float radius)
        {
            var list = new List<Piece>();
            for (int i = 0; i < Candidates; i++)
            {
                Vector3 p;
                do p = new Vector3(Next(rng) * 2f - 1f, Next(rng) * 2f - 1f, Next(rng) * 2f - 1f);
                while (p.sqrMagnitude > 1f);
                p *= radius;
                float r = Next(rng);
                if (Mathf.Abs(p.z) >= HalfHeight * radius * r * r) continue;
                var turn = Quaternion.Euler(Next(rng) * 360f, Next(rng) * 360f, Next(rng) * 360f);
                float size = Mathf.Lerp(1f, 3f, Next(rng)) * radius * PieceShare;
                var random = new Vector4(Next(rng), Next(rng), Next(rng), Next(rng));
                list.Add(new Piece { position = p, turn = turn, size = size, random = random, channel = rng.Next(3) });
            }
            return list;
        }

        static float Next(System.Random rng) => (float)rng.NextDouble();

        /// <summary>Whether an orbit has near clouds: the option, or the sky styles that are EVERSPACE 2's (ES2 style and
        /// Combined: its locations have their local nebulae round them).</summary>
        public static bool NearClouds => Settings.NebulaClouds || Settings.SkyStyle == Settings.SkyEs2 || Settings.SkyStyle == Settings.SkyCombined;

        /// <summary>Whether its sky's bright regions are distant clouds: ES2 style (with its layers drawn, Live mod skies), as
        /// ES2 draws a sector's nebulae from a location (BP_EnvironmentGenerator.ProcessSpaceObjects: each a local nebula at its
        /// direction and scaled distance; the sky sphere has only the stars and a faint sky-wide nebula).</summary>
        public static bool RegionClouds => Settings.SkyStyle == Settings.SkyEs2 && Settings.LiveSkies;

        /// <summary>Distant clouds' distance (m): far past the far plane (15 km), so they barely move as the ship does; drawn at
        /// the far plane in their own direction, so their size on the sky is kept.</summary>
        public const float RegionDistance = 45000f;

        /// <summary>The orbit's clouds (null: none: off, the space between the systems, or a sky too bare for any).</summary>
        public static NebulaClouds Spawn(OrbitLayout layout, Transform parent = null)
        {
            if (layout == null || layout.interstellar) return null;
            var sky = Of(layout.systemTexture);
            if (sky == null || sky.colors == null || sky.colors.Length == 0) return null;
            int near = NearClouds ? CountFor(sky.coverage) : 0;
            var regions = RegionClouds ? GoF2SkyLayers.Of(layout.systemTexture) : null;
            if (near == 0 && (regions?.regions == null || regions.regions.Length == 0)) return null;
            var shader = Resources.Load<Shader>("GoF2SkyLayers/NebulaCloud");
            var masks = Modding.ModTextures.SkyLayer("cloud_masks") ?? Resources.Load<Texture2D>("GoF2SkyLayers/cloud_masks");   // (a mod's textures/cloud_masks: the ES2 mod's, ES2's own)
            if (shader == null || masks == null) return null;

            var go = new GameObject("NebulaClouds");
            go.transform.SetParent(parent, false);
            var clouds = go.AddComponent<NebulaClouds>();
            var rng = new System.Random(layout.stationIndex * 7919 + layout.systemTexture * 104729 + 17);
            var mesh = new Builder();
            for (int c = 0; c < near; c++)
            {
                float radius = Mathf.Lerp(MinRadius, MaxRadius, Next(rng));
                // its middle a few km out (ES2's median 3.6 km for 20 km clouds), its plane at a random turn
                var dir = new Vector3(Next(rng) * 2f - 1f, (Next(rng) * 2f - 1f) * 0.5f, Next(rng) * 2f - 1f).normalized;
                var centre = dir * radius * Mathf.Lerp(0.15f, 0.6f, Next(rng));
                var plane = Quaternion.Euler(Mathf.Lerp(-30f, 30f, Next(rng)), Next(rng) * 360f, Mathf.Lerp(-30f, 30f, Next(rng)));
                var tint = Pick(sky.colors, Next(rng));
                float strength = Mathf.Lerp(0.6f, 1.2f, Next(rng)) * Mathf.Clamp(sky.brightness * 3f, 0.4f, 1.5f);
                mesh.Cloud(rng, centre, plane, radius, new Color(tint.r * strength, tint.g * strength, tint.b * strength));
            }
            if (regions?.regions != null)
            {
                // the sky's bright regions as distant local nebulae: in their direction (the sky's turn: the baked cube's frame
                // to the world), as wide on the sky as the region, its plane facing the orbit, its own colour
                var turn = OrbitBuilder.SkyRotation(layout);
                foreach (var r in regions.regions)
                {
                    if (r.dir == null || r.dir.Length < 3) continue;
                    var dir = (turn * new Vector3(r.dir[0], r.dir[1], r.dir[2])).normalized;
                    float radius = RegionDistance * Mathf.Tan(Mathf.Clamp(r.radius, 4f, 40f) * Mathf.Deg2Rad);
                    float strength = Mathf.Clamp(r.brightness * 4f, 0.3f, 2f);
                    var col = r.color != null && r.color.Length >= 3 ? new Color(r.color[0] * strength, r.color[1] * strength, r.color[2] * strength) : Color.white * strength;
                    mesh.Cloud(rng, dir * RegionDistance, Quaternion.LookRotation(dir), radius, col);
                }
            }
            var built = mesh.Mesh();
            var look = new Material(shader) { name = "NebulaClouds" };
            look.SetTexture("_Masks", masks);
            var sun = OrbitLayout.DirToUnity(layout.lightDirection).normalized;
            look.SetVector("_SunDir", new Vector4(sun.x, sun.y, sun.z, 0f));
            look.SetColor("_SunColor", layout.sunColor.maxColorComponent > 0f ? layout.sunColor : Color.white);
            // the "system colour" ES2's local nebulae turn to at their thin edges: the sky's main colour
            var main = GoF2SkyLayers.Of(layout.systemTexture)?.main;
            look.SetColor("_SysColor", main != null && main.Length >= 3 ? new Color(main[0], main[1], main[2]) * Mathf.Clamp(sky.brightness * 3f, 0.3f, 1.5f) : Color.gray);
            go.AddComponent<MeshFilter>().sharedMesh = built;
            var renderer = go.AddComponent<MeshRenderer>();
            renderer.sharedMaterial = look;
            renderer.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
            renderer.receiveShadows = false;
            clouds.mesh = built; clouds.look = look;
            return clouds;
        }

        /// <summary>The clouds' sprites as one mesh.</summary>
        sealed class Builder
        {
            readonly List<Vector3> vertices = new(), normals = new();
            readonly List<Vector2> uvs = new();
            readonly List<Vector4> randoms = new();
            readonly List<Color> colors = new();
            readonly List<int> tris = new();

            public void Cloud(System.Random rng, Vector3 centre, Quaternion plane, float radius, Color tint)
            {
                foreach (var piece in Pieces(rng, radius))
                {
                    var at = centre + plane * piece.position;
                    var turn = plane * piece.turn;
                    var right = turn * Vector3.right * piece.size; var up = turn * Vector3.up * piece.size; var n = turn * Vector3.forward;
                    int b = vertices.Count;
                    vertices.Add(at - right - up); vertices.Add(at + right - up); vertices.Add(at + right + up); vertices.Add(at - right + up);
                    uvs.Add(new Vector2(0, 0)); uvs.Add(new Vector2(1, 0)); uvs.Add(new Vector2(1, 1)); uvs.Add(new Vector2(0, 1));
                    var col = new Color(tint.r, tint.g, tint.b, piece.channel * 0.5f);
                    for (int k = 0; k < 4; k++) { normals.Add(n); randoms.Add(piece.random); colors.Add(col); }
                    tris.Add(b); tris.Add(b + 2); tris.Add(b + 1); tris.Add(b); tris.Add(b + 3); tris.Add(b + 2);
                }
            }

            public Mesh Mesh()
            {
                var mesh = new Mesh { name = "NebulaClouds", indexFormat = UnityEngine.Rendering.IndexFormat.UInt32 };
                mesh.SetVertices(vertices); mesh.SetNormals(normals); mesh.SetUVs(0, uvs); mesh.SetUVs(1, randoms); mesh.SetColors(colors);
                mesh.SetTriangles(tris, 0);
                mesh.bounds = new Bounds(Vector3.zero, Vector3.one * 1e6f);   // (always drawn: the far pieces are pulled inside the far plane)
                return mesh;
            }
        }

        /// <summary>A cloud's colour: one of its sky's main colours, the less common ones as likely as the first (a cloud in
        /// exactly the sky's own colour vanishes against it; ES2's local nebulae have their own).</summary>
        static Rgbw Pick(Rgbw[] colors, float u)
        {
            float total = 0f;
            foreach (var c in colors) total += Mathf.Sqrt(Mathf.Max(c.weight, 0f));
            u *= total;
            foreach (var c in colors) { float w = Mathf.Sqrt(Mathf.Max(c.weight, 0f)); if (u < w) return c; u -= w; }
            return colors[colors.Length - 1];
        }

        Mesh mesh;
        Material look;

        void OnDestroy()
        {
            if (mesh != null) Destroy(mesh);
            if (look != null) Destroy(look);
        }
    }
}
