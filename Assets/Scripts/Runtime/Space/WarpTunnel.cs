// WarpTunnel.cs
// Remake: the tube around the camera between the systems (World.InterstellarField, the shader GoF2/WarpTunnel): an open
// cylinder along the ship's nose, its textures a mod's warp.json (Modding.ModWarp), else made here, so the space works with
// no mod's art. Its strength is the cruise drive's ramp.

using GoF2Remake.Modding;
using UnityEngine;

namespace GoF2Remake.Visuals
{
    public class WarpTunnel : MonoBehaviour
    {
        const float RadiusMeters = 60f, LengthMeters = 900f, BehindMeters = 150f;
        const int Rings = 12, Segments = 32;
        /// <summary>How fast the layers run: at rest, and added at full cruise (turns of the texture per second).</summary>
        const float IdleScroll = 0.2f, CruiseScroll = 1.6f;

        Material material;
        MeshRenderer view;
        float scroll;
        Texture2D ownNoise, ownDetail, ownStreaks;

        public static WarpTunnel Spawn(Transform parent)
        {
            var shader = Resources.Load<Shader>("GoF2Warp/WarpTunnel");
            if (shader == null) { Debug.LogWarning("WarpTunnel: no GoF2Warp/WarpTunnel shader"); return null; }
            var go = new GameObject("WarpTunnel");
            go.transform.SetParent(parent, false);
            var t = go.AddComponent<WarpTunnel>();
            t.Build(shader);
            return t;
        }

        void Build(Shader shader)
        {
            gameObject.AddComponent<MeshFilter>().sharedMesh = Tube();
            view = gameObject.AddComponent<MeshRenderer>();
            view.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
            view.receiveShadows = false;
            material = new Material(shader) { name = "WarpTunnel (runtime)" };
            var warp = ModWarp.Current;
            material.SetTexture("_Noise", Layer(warp, warp?.tunnel, ref ownNoise, 16, 16, 1));
            material.SetTexture("_Detail", Layer(warp, warp?.detail, ref ownDetail, 32, 8, 2));
            material.SetTexture("_Streaks", Layer(warp, warp?.streaks, ref ownStreaks, 64, 4, 3));
            if (warp != null && warp.tint.HasValue) material.SetColor("_Tint", warp.tint.Value);
            view.sharedMaterial = material;
            view.enabled = false;
        }

        Texture2D Layer(ModWarp.Def warp, string path, ref Texture2D own, int cellsAcross, int cellsAlong, int seed)
        {
            var t = warp != null && !string.IsNullOrEmpty(path) ? ModWarp.Texture(warp, path) : null;
            if (t == null) t = own = MakeNoise(cellsAcross, cellsAlong, seed);
            t.wrapMode = TextureWrapMode.Repeat;
            return t;
        }

        /// <summary>Value noise that tiles both ways, for a space with no mod's textures.</summary>
        static Texture2D MakeNoise(int cellsAcross, int cellsAlong, int seed)
        {
            const int Size = 128;
            var random = new System.Random(seed);
            var cells = new float[cellsAcross, cellsAlong];
            for (int x = 0; x < cellsAcross; x++) for (int y = 0; y < cellsAlong; y++) cells[x, y] = (float)random.NextDouble();
            var pixels = new Color32[Size * Size];
            for (int y = 0; y < Size; y++)
                for (int x = 0; x < Size; x++)
                {
                    float u = x * cellsAcross / (float)Size, v = y * cellsAlong / (float)Size;
                    int cx = (int)u, cy = (int)v;
                    float fx = Mathf.SmoothStep(0f, 1f, u - cx), fy = Mathf.SmoothStep(0f, 1f, v - cy);
                    float a = Mathf.Lerp(cells[cx, cy], cells[(cx + 1) % cellsAcross, cy], fx);
                    float b = Mathf.Lerp(cells[cx, (cy + 1) % cellsAlong], cells[(cx + 1) % cellsAcross, (cy + 1) % cellsAlong], fx);
                    byte c = (byte)(Mathf.Lerp(a, b, fy) * 255f);
                    pixels[y * Size + x] = new Color32(c, c, c, 255);
                }
            var t = new Texture2D(Size, Size, TextureFormat.RGBA32, true, true) { name = "WarpNoise", wrapMode = TextureWrapMode.Repeat };
            t.SetPixels32(pixels);
            t.Apply(true, true);
            return t;
        }

        static Mesh Tube()
        {
            var vertices = new Vector3[(Rings + 1) * (Segments + 1)];
            var uv = new Vector2[vertices.Length];
            var triangles = new int[Rings * Segments * 6];
            int n = 0;
            for (int r = 0; r <= Rings; r++)
                for (int s = 0; s <= Segments; s++, n++)
                {
                    float along = r / (float)Rings, turn = s / (float)Segments, a = turn * Mathf.PI * 2f;
                    vertices[n] = new Vector3(Mathf.Cos(a) * RadiusMeters, Mathf.Sin(a) * RadiusMeters, along * LengthMeters - BehindMeters);
                    uv[n] = new Vector2(turn, along);
                }
            n = 0;
            for (int r = 0; r < Rings; r++)
                for (int s = 0; s < Segments; s++)
                {
                    int a = r * (Segments + 1) + s, b = a + Segments + 1;
                    triangles[n++] = a; triangles[n++] = b; triangles[n++] = a + 1;
                    triangles[n++] = a + 1; triangles[n++] = b; triangles[n++] = b + 1;
                }
            return new Mesh { name = "WarpTunnel", vertices = vertices, uv = uv, triangles = triangles,
                              bounds = new Bounds(new Vector3(0f, 0f, LengthMeters / 2f - BehindMeters), new Vector3(RadiusMeters * 2f, RadiusMeters * 2f, LengthMeters)) };
        }

        /// <summary>Every frame: 'level' 0..1, around the camera at 'eye', along the ship's nose.</summary>
        public void Show(float level, Vector3 eye, Quaternion nose, float dtMs)
        {
            bool on = level > 0.001f;
            if (view.enabled != on) view.enabled = on;
            if (!on) return;
            transform.SetPositionAndRotation(eye, nose);
            scroll = Mathf.Repeat(scroll + (IdleScroll + CruiseScroll * level) * dtMs / 1000f, 1000f);
            material.SetFloat("_Level", level);
            material.SetFloat("_Scroll", scroll);
        }

        void OnDestroy()
        {
            if (material != null) Destroy(material);
            if (ownNoise != null) Destroy(ownNoise);
            if (ownDetail != null) Destroy(ownDetail);
            if (ownStreaks != null) Destroy(ownStreaks);
        }
    }
}
