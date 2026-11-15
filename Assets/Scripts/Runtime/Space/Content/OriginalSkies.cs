// OriginalSkies.cs
// Feature: docs/notes/player-assets.md "The content layer": the skies and reflection cubemaps of a build without the
// originals, made from the player's converted copy when Resources has none:
//   Sky("stars_000" / "nebula_005")  what SkyboxBaker.BakeSpaceSkies baked into Resources/GoF2Sky: the original's sky meshes
//                                    with their textures (GoF2/Unlit stars, GoF2/Additive nebula, seen from inside) rendered
//                                    into a cube (Camera.RenderToCubemap), once per run
//   Reflection("cubemap_skybox_003") the original's own cubemap strip (AEI type 0x81, 6 faces stacked, the converter's
//                                    Textures/<pack>/cubemaps/<name>.png) as a Cubemap: Resources/GoF2Reflections holds 4x
//                                    upscales of the same (an optional upgrade, see the packs)

using System.Collections.Generic;
using System.IO;
using GoF2Remake.Data;
using UnityEngine;
using UnityEngine.Rendering;

namespace GoF2Remake.Visuals
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class OriginalSkies
    {
        static readonly Dictionary<string, Texture> made = new Dictionary<string, Texture>();

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() => made.Clear();

        /// <summary>The face size of a rendered sky (SkyboxBaker's 2048; phones 1024, its strips are 8192 there).</summary>
        public static int FaceSize => Application.isMobilePlatform ? 1024 : 2048;

        /// <summary>A space sky layer by its GoF2Sky name: Resources' cubemap, else rendered from the converted copy.</summary>
        public static Texture Sky(string name)
        {
            var c = Resources.Load<Cubemap>("GoF2Sky/" + name);
            if (c != null) return c;
            if (made.TryGetValue("sky:" + name, out var t) && t != null) return t;
            t = Render(name);
            made["sky:" + name] = t;
            return t;
        }

        /// <summary>The meshes and textures of a sky layer (SkyboxBaker: stars_i the stars mesh, nebula_t its system's).</summary>
        static (string model, string shader, string texture)? LayerOf(string name)
        {
            if (name.StartsWith("stars_") && int.TryParse(name.Substring(6), out int i))
                return ("Models/main/skyboxes/skybox_stars.fbx", "GoF2/Unlit", $"Textures/main/skyboxes/skybox_stars_{i:000}.png");
            if (!name.StartsWith("nebula_") || !int.TryParse(name.Substring(7), out int t)) return null;
            if (t <= 10) return ($"Models/main/skyboxes/skybox_{t:000}.fbx", "GoF2/Additive", $"Textures/main/skyboxes/skybox_{t:000}.png");
            if (t <= 14) return ($"Models/valkyrie/skyboxes/v_skybox_{(t == 14 ? 13 : t):000}.fbx", "GoF2/Additive", $"Textures/valkyrie/skyboxes/v_skybox_{t:000}.png");
            return ($"Models/supernova/skyboxes/sn_skybox_{t:000}.fbx", "GoF2/Additive", $"Textures/supernova/skyboxes/sn_skybox_{t:000}.png");
        }

        /// <summary>The layer rendered into a cube render texture (sRGB, mipmapped), as SkyboxBaker.BakeCube's camera saw it:
        /// at the mesh's centre, 90 degrees, black behind; on a layer of its own far from anything.</summary>
        static Texture Render(string name)
        {
            var layer = LayerOf(name);
            // (no GPU: a server or a -nographics batch run renders nothing)
            if (layer == null || !GameContent.Installed || SystemInfo.graphicsDeviceType == GraphicsDeviceType.Null) return null;
            var (model, shaderName, texture) = layer.Value;
            var go = OriginalModels.Build(model);
            var shader = Shader.Find(shaderName);
            var tex = OriginalTextures.Get(texture);
            if (go == null || shader == null || tex == null) { if (go != null) OriginalAssemblies.Gone(go); return null; }
            const int Layer = 31;
            var origin = new Vector3(0f, -1e6f, 0f);
            go.transform.position = origin;
            var mat = new Material(shader);
            mat.SetTexture("_MainTex", tex);
            mat.SetFloat("_Cull", 0f);   // seen from inside
            foreach (var r in go.GetComponentsInChildren<MeshRenderer>(true))
            {
                r.sharedMaterial = mat;
                r.shadowCastingMode = ShadowCastingMode.Off;
                r.gameObject.layer = Layer;
            }
            var anim = go.GetComponent<PartAnimation>();
            if (anim != null) anim.enabled = false;
            var camGo = new GameObject("Sky render camera");
            var cam = camGo.AddComponent<Camera>();
            cam.transform.position = origin;
            cam.clearFlags = CameraClearFlags.SolidColor;
            cam.backgroundColor = Color.black;
            cam.cullingMask = 1 << Layer;
            cam.nearClipPlane = 0.1f;
            cam.farClipPlane = 1000f;
            cam.enabled = false;
            var rt = new RenderTexture(new RenderTextureDescriptor(FaceSize, FaceSize, RenderTextureFormat.ARGB32, 24)
            {
                dimension = TextureDimension.Cube, sRGB = true, useMipMap = true, autoGenerateMips = true,
            }) { name = name, wrapMode = TextureWrapMode.Clamp, filterMode = FilterMode.Trilinear };
            rt.Create();
            cam.RenderToCubemap(rt);
            OriginalAssemblies.Gone(camGo);
            OriginalAssemblies.Gone(go);
            OriginalAssemblies.Gone(mat);
            return rt;
        }

        /// <summary>A reflection cubemap by its GoF2Reflections name: Resources' (the 4x upscales), else the original's own
        /// strip from the converted copy. Null when neither has it.</summary>
        public static Cubemap Reflection(string name)
        {
            var c = Resources.Load<Cubemap>("GoF2Reflections/" + name);
            if (c != null) return c;
            if (made.TryGetValue("refl:" + name, out var t)) return t as Cubemap;
            string path = null;
            foreach (var pack in new[] { "main", "valkyrie", "supernova" })
                if ((path = GameContent.CachePath($"Textures/{pack}/cubemaps/{name}.png")) != null) break;
            if (path != null) c = FromStrip(File.ReadAllBytes(path), name);
            made["refl:" + name] = c;
            return c;
        }

        /// <summary>A vertical strip of six faces (+X, -X, +Y, -Y, +Z, -Z from the top, as Unity's cubemap import reads a 1:6
        /// image) as a Cubemap.</summary>
        public static Cubemap FromStrip(byte[] png, string name)
        {
            var strip = new Texture2D(2, 2, TextureFormat.RGBA32, false);
            if (!strip.LoadImage(png, false) || strip.height != strip.width * 6) { OriginalAssemblies.Gone(strip); return null; }
            int s = strip.width;
            var cube = new Cubemap(s, TextureFormat.RGBA32, true) { name = name, wrapMode = TextureWrapMode.Clamp, filterMode = FilterMode.Trilinear };
            var faces = new[] { CubemapFace.PositiveX, CubemapFace.NegativeX, CubemapFace.PositiveY, CubemapFace.NegativeY, CubemapFace.PositiveZ, CubemapFace.NegativeZ };
            for (int i = 0; i < 6; i++)
            {
                // a Texture2D's rows run bottom up, a cubemap face's top down: face i is the strip's i-th square from the top
                var px = strip.GetPixels(0, (5 - i) * s, s, s);
                var flipped = new Color[px.Length];
                for (int y = 0; y < s; y++) System.Array.Copy(px, y * s, flipped, (s - 1 - y) * s, s);
                cube.SetPixels(flipped, faces[i]);
            }
            cube.Apply(true, true);
            OriginalAssemblies.Gone(strip);
            return cube;
        }
    }
}
