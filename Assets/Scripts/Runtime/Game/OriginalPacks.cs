// OriginalPacks.cs
// Feature: docs/notes/player-assets.md "Packs": what the player's copy doesn't provide, distributed separately (never on
// GitHub): the common pack, an edition's gap pack, the HD pack (the HD textures, the Real-ESRGAN skies and their sky
// patches, the 3D planets). A pack is a zip of files at their converted copy's paths ("Textures/main/x.png",
// "Resources/GoF2Planets3D/009/albedo.png") and a gof2pack.json manifest (name, title, version, order: common 0, gap 1,
// HD 2), made by Reference/tools/player_assets/make_packs.py. Picked on the setup screen (or put in GamePaths.Data/Packs),
// a pack is kept in Packs and its files written over the converted copy (later packs win), recorded in the copy's
// _packs.tsv; every kept pack is written again after a conversion (OriginalSetup), and one not yet applied at the next
// start (StartupSplash).

using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using UnityEngine;

namespace GoF2Remake.Data
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class OriginalPacks
    {
        public const string ManifestName = "gof2pack.json";
        public const string Extension = ".gof2pack";

        [Serializable]
        public sealed class Info
        {
            public string name, title, edition;
            public int version, order, files;
            public long bytes;
            [NonSerialized] public string file;
        }

        /// <summary>Where kept packs live (main thread: GamePaths).</summary>
        public static string Folder => Path.Combine(GamePaths.Data, "Packs");

        /// <summary>A pack's manifest, or null when 'path' isn't a pack (any thread).</summary>
        public static Info Read(string path)
        {
            try
            {
                using var z = ZipFile.OpenRead(path);
                var e = z.GetEntry(ManifestName);
                if (e == null) return null;
                using var r = new StreamReader(e.Open());
                var info = JsonUtility.FromJson<Info>(r.ReadToEnd());
                if (info == null || string.IsNullOrEmpty(info.name)) return null;
                info.file = path;
                return info;
            }
            catch (Exception e) when (e is IOException || e is InvalidDataException || e is UnauthorizedAccessException || e is ArgumentException) { return null; }
        }

        /// <summary>The kept packs, in the order they are written (common, gap, HD; then by name).</summary>
        public static List<Info> Kept(string folder)
        {
            var list = new List<Info>();
            if (Directory.Exists(folder))
                foreach (var f in Directory.GetFiles(folder))
                {
                    var i = Read(f);
                    if (i != null) list.Add(i);
                }
            return list.OrderBy(i => i.order).ThenBy(i => i.name, StringComparer.Ordinal).ToList();
        }

        /// <summary>Kept packs not yet written into the converted copy (or at another version).</summary>
        public static List<Info> Pending(string folder, string root)
        {
            var applied = Applied(root);
            return Kept(folder).Where(p => !applied.TryGetValue(p.name, out int v) || v != p.version).ToList();
        }

        public static Dictionary<string, int> Applied(string root)
        {
            var d = new Dictionary<string, int>(StringComparer.Ordinal);
            string f = Path.Combine(root, "_packs.tsv");
            if (File.Exists(f))
                foreach (var line in File.ReadAllLines(f))
                {
                    var p = line.Split('\t');
                    if (p.Length >= 2 && int.TryParse(p[1], out int v)) d[p[0]] = v;
                }
            return d;
        }

        /// <summary>Keeps a picked pack in 'folder' under its own name (replacing an older one of that name); its new path.</summary>
        public static string Keep(Info info, string folder, bool move)
        {
            Directory.CreateDirectory(folder);
            foreach (var old in Kept(folder).Where(p => p.name == info.name && p.file != info.file)) File.Delete(old.file);
            string to = Path.Combine(folder, info.name + Extension);
            if (Path.GetFullPath(to) == Path.GetFullPath(info.file)) return to;
            if (File.Exists(to)) File.Delete(to);
            if (move) File.Move(info.file, to); else File.Copy(info.file, to);
            info.file = to;
            return to;
        }

        /// <summary>Writes the pack's files over the converted copy at 'root' and records it (a worker thread may call it).</summary>
        public static void Apply(Info pack, string root, Action<int, int, string> progress)
        {
            string full = Path.GetFullPath(root).TrimEnd(Path.DirectorySeparatorChar) + Path.DirectorySeparatorChar;
            using (var z = ZipFile.OpenRead(pack.file))
            {
                int done = 0, total = z.Entries.Count;
                foreach (var e in z.Entries)
                {
                    done++;
                    if (e.FullName == ManifestName || e.FullName.EndsWith("/")) continue;
                    string target = Path.GetFullPath(Path.Combine(root, e.FullName));
                    if (!target.StartsWith(full, StringComparison.Ordinal)) throw new InvalidDataException($"{pack.name}: {e.FullName} points outside the copy");
                    if (e.FullName.StartsWith("_", StringComparison.Ordinal)) continue;   // (the copy's own bookkeeping: never a pack's)
                    Directory.CreateDirectory(Path.GetDirectoryName(target));
                    e.ExtractToFile(target, true);
                    progress?.Invoke(done, total, e.FullName);
                }
            }
            var applied = Applied(root);
            applied[pack.name] = pack.version;
            File.WriteAllLines(Path.Combine(root, "_packs.tsv"), applied.Select(kv => kv.Key + "\t" + kv.Value));
        }
    }
}
