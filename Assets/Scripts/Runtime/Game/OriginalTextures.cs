// OriginalTextures.cs
// Feature: docs/notes/player-assets.md "The content layer": a texture of the player's converted copy (GameContent's
// Textures/<rel>.png) as the Editor's importer set the original up: the game's normal maps (specular in alpha) rewritten
// so URP reads them on desktop and Android, sRGB colour, linear data, mipmaps, compressed where the size allows.

using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

namespace GoF2Remake.Data
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class OriginalTextures
    {
        public enum Kind { Color, Normal, Data }

        static readonly Dictionary<string, Texture2D> loaded = new Dictionary<string, Texture2D>(StringComparer.OrdinalIgnoreCase);

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics()
        {
            loaded.Clear();
            images.Clear();
            GameContent.Refreshed -= ResetStatics;
            GameContent.Refreshed += ResetStatics;   // (a new copy converted)
        }

        /// <summary>The kind a project texture path is imported as (ImportPostprocessor: *_normal* normal maps, the
        /// generated *_metallic_smoothness linear data, the rest sRGB colour).</summary>
        public static Kind KindOf(string rel) =>
            rel.IndexOf("_normal", StringComparison.OrdinalIgnoreCase) >= 0 ? Kind.Normal
            : rel.IndexOf("_metallic", StringComparison.OrdinalIgnoreCase) >= 0 ? Kind.Data : Kind.Color;

        /// <summary>A texture by its project path ("Textures/main/ships/x.png"), null when the cache has none. GPU-ready from
        /// the disk cache (GameContent.GpuCache, ModTextureCache's format) after its first use: the first time decoded,
        /// converted and compressed with its mipmaps on the worker threads (ModTextureEncoder: DXT on desktop, ETC2 on
        /// phones), then stored.</summary>
        public static Texture2D Get(string rel)
        {
            if (string.IsNullOrEmpty(rel)) return null;
            if (loaded.TryGetValue(rel, out var t)) return t;
            var path = GameContent.CachePath(rel);
            if (path == null) { loaded[rel] = null; return null; }
            var kind = KindOf(rel);
            bool linear = kind != Kind.Color;
            string name = Path.GetFileNameWithoutExtension(rel);
            bool dxt = SystemInfo.SupportsTextureFormat(TextureFormat.DXT1) && SystemInfo.SupportsTextureFormat(TextureFormat.DXT5);
            bool etc = !dxt && SystemInfo.SupportsTextureFormat(TextureFormat.ETC2_RGB) && SystemInfo.SupportsTextureFormat(TextureFormat.ETC2_RGBA8);
            string fmt = dxt ? "dxt" : etc ? "etc2" : null;
            string cacheFile = fmt != null ? CacheFile(rel, path, fmt + (kind == Kind.Normal ? "-nrm" : "") + (linear ? "-lin" : "")) : null;
            var cached = cacheFile != null ? Modding.ModTextureCache.Read(cacheFile) : null;
            if (cached != null) t = Modding.ModTextureCache.Make(cached, name);
            if (t == null) t = Decode(path, name, kind, linear, fmt, cacheFile);
            if (t == null) { loaded[rel] = null; return null; }
            t.wrapMode = TextureWrapMode.Repeat;
            t.filterMode = FilterMode.Trilinear;
            t.anisoLevel = 8;
            loaded[rel] = t;
            return t;
        }

        /// <summary>The GPU cache file of a converted texture: its path, the PNG's size and date, the format.</summary>
        static string CacheFile(string rel, string png, string fmt)
        {
            var fi = new FileInfo(png);
            string id = $"{rel.ToLowerInvariant()}|{fi.Length}|{fi.LastWriteTimeUtc.Ticks}|{fmt}";
            using var sha = System.Security.Cryptography.SHA256.Create();
            var hash = sha.ComputeHash(System.Text.Encoding.UTF8.GetBytes(id));
            var sb = new System.Text.StringBuilder(32);
            for (int i = 0; i < 16; i++) sb.Append(hash[i].ToString("x2"));
            return Path.Combine(GameContent.GpuCache, "textures", sb + ".tex");
        }

        /// <summary>The PNG decoded (the normal maps rewritten for URP), compressed with its mipmaps and stored.</summary>
        static Texture2D Decode(string path, string name, Kind kind, bool linear, string fmt, string cacheFile)
        {
            var src = new Texture2D(2, 2, TextureFormat.RGBA32, false, linear) { name = name };
            if (!src.LoadImage(File.ReadAllBytes(path), false)) { Gone(src); return null; }
            if (kind == Kind.Normal)
            {
                // The game's normal maps carry specular in alpha (its own metallic map has it). URP reads a normal map's X
                // from alpha x red on desktop (UnpackNormalmapRGorAG) and from alpha on Android: (1, G, B, R) reads right
                // in both, as the importer's Normal Map type gave it.
                var px = src.GetPixels32();
                for (int i = 0; i < px.Length; i++) px[i] = new Color32(255, px[i].g, px[i].b, px[i].r);
                src.SetPixels32(px);
                src.Apply(false, false);
            }
            if (fmt == null || src.width % 4 != 0 || src.height % 4 != 0)
            {
                // a GPU that reads neither DXT nor ETC2, or a size the blocks don't fit: uncompressed with mipmaps
                var t = new Texture2D(src.width, src.height, TextureFormat.RGBA32, true, linear) { name = name };
                t.SetPixels32(src.GetPixels32());
                t.Apply(true, true);
                Gone(src);
                return t;
            }
            var work = Modding.ModTextureEncoder.Start(src, linear, Modding.ModTextureEncoder.Remap.None, 1f, 1f,
                fmt == "etc2" ? Modding.ModTextureEncoder.Target.Etc2 : Modding.ModTextureEncoder.Target.Dxt);
            Gone(src);
            if (work == null) return null;
            var tex = work.Upload(name);
            if (cacheFile != null)
                Modding.ModTextureCache.Write(cacheFile, tex.width, tex.height, tex.format, tex.mipmapCount, linear, work.Data.AsReadOnlySpan());
            work.Dispose();
            return tex;
        }

        static readonly Dictionary<string, Texture2D> images = new Dictionary<string, Texture2D>(StringComparer.OrdinalIgnoreCase);

        /// <summary>An interface image by its Resources path ("GoF2Hud/lock_00", "GoF2Icons/item_012"): the build's own when
        /// it has one, else the converted copy's (DerivedImages cut it from the atlases), set up as the importer sets up the
        /// interface images: no mipmaps, clamped (the HUD's scrolling strips repeat), uncompressed. Null when neither has it.</summary>
        public static Texture2D Image(string resourcesPath)
        {
            var t = Resources.Load<Texture2D>(resourcesPath);
            if (t != null) return t;
            if (images.TryGetValue(resourcesPath, out t)) return t;
            var path = GameContent.CachePath("Resources/" + resourcesPath + ".png");
            if (path != null)
            {
                t = new Texture2D(2, 2, TextureFormat.RGBA32, false) { name = Path.GetFileName(resourcesPath) };
                if (t.LoadImage(File.ReadAllBytes(path), true))
                {
                    bool repeat = resourcesPath.StartsWith("GoF2Hud/strip_");
                    t.wrapMode = repeat ? TextureWrapMode.Repeat : TextureWrapMode.Clamp;
                    t.filterMode = FilterMode.Bilinear;
                }
                else { Gone(t); t = null; }
            }
            images[resourcesPath] = t;
            return t;
        }

        /// <summary>A texture of the converted copy by its project path ("Textures/textures/3_1_0_ipad_large.png") set up as the
        /// importer sets up a sprite: no mipmaps, clamped, bilinear, uncompressed. Null when the copy hasn't it.</summary>
        public static Texture2D UiImage(string projectPath)
        {
            if (string.IsNullOrEmpty(projectPath)) return null;
            if (images.TryGetValue(projectPath, out var t)) return t;
            var path = GameContent.CachePath(projectPath);
            if (path != null)
            {
                t = new Texture2D(2, 2, TextureFormat.RGBA32, false) { name = Path.GetFileNameWithoutExtension(projectPath) };
                if (t.LoadImage(File.ReadAllBytes(path), true)) { t.wrapMode = TextureWrapMode.Clamp; t.filterMode = FilterMode.Bilinear; }
                else { Gone(t); t = null; }
            }
            if (t != null || GameContent.Installed) images[projectPath] = t;
            return t;
        }

        static void Gone(UnityEngine.Object o)
        {
            if (Application.isPlaying) UnityEngine.Object.Destroy(o); else UnityEngine.Object.DestroyImmediate(o);
        }
    }
}
