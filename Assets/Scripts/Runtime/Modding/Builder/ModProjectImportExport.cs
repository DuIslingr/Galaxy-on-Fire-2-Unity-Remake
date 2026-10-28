// ModProjectImportExport.cs
// ModProject: import and export (part of the partial ModProject; its fields are in ModProject.cs).

using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using GoF2Remake.Data;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using UnityEngine;

namespace GoF2Remake.Modding
{
    public partial class ModProject
    {
        // ---- import -------------------------------------------------------------------------------------------
        /// <summary>The project of the mod 'id', or null (the projects page asks before replacing it).</summary>
        public static ModProject WithId(string id) =>
            List().FirstOrDefault(p => string.Equals(p.Id, id, StringComparison.OrdinalIgnoreCase));
        /// <summary>A mod made elsewhere as a project: every file of 'src' (an installed mod, a downloaded .zip; a zip's top
        /// folder left out, ModSource) copied as it is under 'root' (ModProject.Root, read on the main thread), in a folder
        /// named after the mod's id 'id', or into 'replaceFolder' (the project of that id, removed only once the copy is
        /// complete). The mod keeps its id, so the project's Export replaces the installed copy. No Unity calls: runs on a
        /// worker thread (a mod of models and textures is hundreds of MB). Returns the project's folder for Load, or null
        /// with the error.</summary>
        public static string CopyMod(ModSource src, string root, string id, string replaceFolder, out string error)
        {
            error = null;
            string tmp = Path.Combine(root, "." + id + ".import");
            try
            {
                if (Directory.Exists(tmp)) Directory.Delete(tmp, true);
                Directory.CreateDirectory(tmp);
                string inside = Path.GetFullPath(tmp) + Path.DirectorySeparatorChar;
                foreach (string rel in src.Files)
                {
                    if (string.Equals(rel, BuilderFile, StringComparison.OrdinalIgnoreCase)) continue;   // the builder's own
                    string dst = Path.GetFullPath(Path.Combine(tmp, rel));
                    if (!dst.StartsWith(inside, StringComparison.OrdinalIgnoreCase)) continue;   // an archive's "../" path
                    Directory.CreateDirectory(Path.GetDirectoryName(dst));
                    File.WriteAllBytes(dst, src.ReadBytes(rel));
                }
                // Its id stays its own (KeepsId); the rest of builder.json the builder fills in as it is used.
                File.WriteAllText(Path.Combine(tmp, BuilderFile), new JObject { ["keepId"] = true }.ToString(Formatting.Indented));
                string target = replaceFolder ?? Path.Combine(root, id);
                for (int i = 2; replaceFolder == null && Directory.Exists(target); i++) target = Path.Combine(root, $"{id}_{i}");
                if (replaceFolder != null && Directory.Exists(replaceFolder)) Directory.Delete(replaceFolder, true);
                Directory.Move(tmp, target);
                Directory.SetLastWriteTimeUtc(target, DateTime.UtcNow);   // the newest project: the list's top
                Debug.Log($"Mod Builder: imported the mod \"{id}\" from {src.Location} into {target}");
                return target;
            }
            catch (Exception e)
            {
                error = e.Message;
                Debug.LogWarning($"Mod Builder: importing {id} from {src.Location} failed: {e.Message}");
                try { if (Directory.Exists(tmp)) Directory.Delete(tmp, true); } catch { }
                return null;
            }
        }
        /// <summary>Deletes the project's folder.</summary>
        public bool Delete(out string error)
        {
            error = null;
            try { Directory.Delete(Folder, true); Debug.Log($"Mod Builder: deleted the project {Folder}"); return true; }
            catch (Exception e) { error = e.Message; return false; }
        }
        // ---- export ---------------------------------------------------------------------------------------------
        /// <summary>An installed mod (not this project) has the project's id, or an id it had before (ChangeId): the export
        /// replaces it.</summary>
        public ModInfo InstalledMod =>
            ModManager.Installed.FirstOrDefault(m => string.Equals(m.Id, Id, StringComparison.OrdinalIgnoreCase))
            ?? ModManager.Installed.FirstOrDefault(m => m.Id != null && PreviousIds.Contains(m.Id, StringComparer.OrdinalIgnoreCase));
        /// <summary>The files Export puts into the mod (full path, path in the mod): not builder.json, the skin templates or a
        /// .tmp file.</summary>
        public IEnumerable<(string path, string rel)> ExportedFiles()
        {
            foreach (var f in Directory.GetFiles(Folder, "*", SearchOption.AllDirectories))
            {
                string rel = f.Substring(Folder.Length).TrimStart('/', '\\').Replace('\\', '/');
                if (rel == BuilderFile || rel.EndsWith(".tmp") || rel.StartsWith(TemplatesFolder + "/")) continue;
                yield return (f, rel);
            }
        }
        /// <summary>The mod's size: its exported files together, before the zip compresses them (bytes; 0 when unreadable).</summary>
        public long ModSize()
        {
            try { return ExportedFiles().Sum(f => new FileInfo(f.path).Length); }
            catch (Exception) { return 0; }
        }
        /// <summary>Zips the mod's files (not builder.json) into the Mods folder as "<name>.zip" (the project's name as it is
        /// now), replacing an installed mod with its id in its own folder (it keeps its on / off and load order), or one under
        /// an id it had before (ChangeId; the new id is turned on when that was). Returns the zip's path, or null with the
        /// error.</summary>
        public string Export(out string error)
        {
            error = null;
            Save();
            try
            {
                var old = InstalledMod;
                string folder = old != null ? ModManager.FolderOf(old) : ModManager.MainFolder;
                // The mod installed under an earlier id: the new one takes its place, on if it was on.
                bool renamed = old != null && !string.Equals(old.Id, Id, StringComparison.OrdinalIgnoreCase);
                bool wasOn = renamed && ModManager.IsEnabled(old.Id);
                if (old != null && !ModImport.Delete(old, out error, keepEnabled: !renamed)) return null;
                Directory.CreateDirectory(folder);
                string target = Path.Combine(folder, ZipName(folder)), tmp = target + ".tmp";
                using (var zip = new ZipArchive(File.Create(tmp), ZipArchiveMode.Create))
                    foreach (var (f, rel) in ExportedFiles())
                    {
                        var e = zip.CreateEntry(rel, System.IO.Compression.CompressionLevel.Optimal);
                        using var dst = e.Open();
                        using var src = File.OpenRead(f);
                        src.CopyTo(dst);
                    }
                if (File.Exists(target)) File.Delete(target);
                File.Move(tmp, target);
                Debug.Log($"Mod Builder: exported \"{Id}\" to {target}");
                ModManager.Scan();
                if (wasOn) ModManager.SetEnabled(Id, true);
                return target;
            }
            catch (Exception e) { error = e.Message; Debug.LogWarning($"Mod Builder: export of {Id} failed: {e.Message}"); return null; }
        }
        /// <summary>The zip's file name from the project's name (characters a file name can't hold become '_'); another
        /// file of that name in the folder (a different mod: the old one was removed first) gets the id appended.</summary>
        string ZipName(string folder)
        {
            var bad = Path.GetInvalidFileNameChars();
            string name = new string((Name ?? "").Select(c => Array.IndexOf(bad, c) >= 0 ? '_' : c).ToArray()).Trim().TrimEnd('.');
            if (name.Length > 60) name = name.Substring(0, 60).TrimEnd();
            if (name.Length == 0) name = Id;
            string file = name + ".zip";
            if (File.Exists(Path.Combine(folder, file)) || Directory.Exists(Path.Combine(folder, name))) file = $"{name} ({Id}).zip";
            return file;
        }
    }
}
