// GameContent.cs
// Feature: docs/notes/player-assets.md "The content layer": where the game's own content comes from. The player's own copy
// of Galaxy on Fire 2, converted into a cache (OriginalConverter, the separate packs layered over it), in the project's own
// layout below GamePaths.Data/Original; while a build still carries the originals (the Editor, builds before the switch),
// Resources is the fallback. Every reader of an original goes through here, so the two sources stay one path.

using System;
using System.IO;
using UnityEngine;

namespace GoF2Remake.Data
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class GameContent
    {
        /// <summary>The converted cache's folder (GamePaths.Data/Original), or the folder set for tests.</summary>
        public static string Root
        {
            get => root ?? Path.Combine(GamePaths.Data, "Original");
            set { root = value; installed = null; }
        }
        static string root;
        static bool? installed;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { root = null; installed = null; }

        /// <summary>Whether a converted copy of this converter's format is there (its manifest, which the converter writes
        /// last, starting with OriginalConverter.ManifestHeader).</summary>
        public static bool Installed => installed ??= FirstLine(Path.Combine(Root, "_manifest.tsv")) == OriginalConverter.ManifestHeader;

        /// <summary>A converted copy is there but made by an older game (another format): convert it again.</summary>
        public static bool Stale
        {
            get
            {
                string first = FirstLine(Path.Combine(Root, "_manifest.tsv"));
                return first != null && first != OriginalConverter.ManifestHeader;
            }
        }

        /// <summary>The folder the GPU-ready caches made from the converted copy go to (dropped with it).</summary>
        public static string GpuCache => Path.Combine(Root, "_gpu", "v" + OriginalConverter.FormatVersion);

        static string FirstLine(string path)
        {
            try
            {
                if (!File.Exists(path)) return null;
                using var r = new StreamReader(path);
                return r.ReadLine();
            }
            catch (IOException) { return null; }
        }

        /// <summary>Forget what was found (after a conversion or a pack installed).</summary>
        public static void Refresh() => installed = null;

        /// <summary>A file of the cache by its path there ("Resources/GoF2Data/items.json"), null when it has none.</summary>
        public static string CachePath(string rel)
        {
            if (!Installed) return null;
            string p = Path.Combine(Root, rel);
            return File.Exists(p) ? p : null;
        }

        /// <summary>A text table by its Resources path ("GoF2Data/items", no extension): the cache's .json, else the
        /// TextAsset in Resources. Null when neither has it.</summary>
        public static string Text(string resourcePath)
        {
            var p = CachePath("Resources/" + resourcePath + ".json");
            if (p != null) return File.ReadAllText(p);
            var ta = Resources.Load<TextAsset>(resourcePath);
            if (ta == null) return null;
            string text = ta.text;
            Resources.UnloadAsset(ta);
            return text;
        }

        /// <summary>A binary table by its Resources path (a .bytes TextAsset there; the same name + .bytes in the cache).</summary>
        public static byte[] Bytes(string resourcePath)
        {
            var p = CachePath("Resources/" + resourcePath + ".bytes");
            if (p != null) return File.ReadAllBytes(p);
            var ta = Resources.Load<TextAsset>(resourcePath);
            if (ta == null) return null;
            var b = ta.bytes;
            Resources.UnloadAsset(ta);
            return b;
        }

        /// <summary>The text table of a language (text_<code>.json: the original's strings, the packs' overlay applied), null
        /// when the cache has none for it (the caller then uses the build's own table, LanguageTables).</summary>
        public static string LanguageText(string code)
        {
            var p = CachePath("Localization/text_" + code + ".json");
            return p != null ? File.ReadAllText(p) : null;
        }
    }
}
