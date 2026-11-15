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
        static void ResetStatics() { loaded.Clear(); images.Clear(); }

        /// <summary>The kind a project texture path is imported as (ImportPostprocessor: *_normal* normal maps, the
        /// generated *_metallic_smoothness linear data, the rest sRGB colour).</summary>
        public static Kind KindOf(string rel) =>
            rel.IndexOf("_normal", StringComparison.OrdinalIgnoreCase) >= 0 ? Kind.Normal
            : rel.IndexOf("_metallic", StringComparison.OrdinalIgnoreCase) >= 0 ? Kind.Data : Kind.Color;

        /// <summary>A texture by its project path ("Textures/main/ships/x.png"), null when the cache has none.</summary>
        public static Texture2D Get(string rel)
        {
            if (string.IsNullOrEmpty(rel)) return null;
            if (loaded.TryGetValue(rel, out var t)) return t;
            var path = GameContent.CachePath(rel);
            if (path == null) { loaded[rel] = null; return null; }
            var kind = KindOf(rel);
            t = new Texture2D(2, 2, TextureFormat.RGBA32, true, kind != Kind.Color) { name = Path.GetFileNameWithoutExtension(rel) };
            if (!t.LoadImage(File.ReadAllBytes(path), false)) { Gone(t); loaded[rel] = null; return null; }
            if (kind == Kind.Normal)
            {
                // The game's normal maps carry specular in alpha (its own metallic map has it). URP reads a normal map's X
                // from alpha x red on desktop (UnpackNormalmapRGorAG) and from alpha on Android: (1, G, B, R) reads right
                // in both, as the importer's Normal Map type gave it.
                var px = t.GetPixels32();
                for (int i = 0; i < px.Length; i++) px[i] = new Color32(255, px[i].g, px[i].b, px[i].r);
                t.SetPixels32(px);
                t.Apply(true, false);
            }
            t.wrapMode = TextureWrapMode.Repeat;
            t.filterMode = FilterMode.Trilinear;
            t.anisoLevel = 8;
            if (t.width % 4 == 0 && t.height % 4 == 0) t.Compress(true);
            t.Apply(false, true);
            loaded[rel] = t;
            return t;
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

        static void Gone(UnityEngine.Object o)
        {
            if (Application.isPlaying) UnityEngine.Object.Destroy(o); else UnityEngine.Object.DestroyImmediate(o);
        }
    }
}
