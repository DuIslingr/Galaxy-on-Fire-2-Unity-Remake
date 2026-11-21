// ModShipIcons.cs
// Remake (the user's request, 2026-11-21): a shop icon for every mod ship without one of its own. ships.json "icon" is
// optional, and the ships that had none showed the Phantom's (about 300 across the GoF3, ES2, Chorus and NMS mods: their
// NPC, capital and traffic hulls, which the hangar, the shops' blueprints and the Debug Ships tab list too). Each is drawn
// from its built template by ShipIconMaker (the Mod Builder's icons: GoF2's own camera, light and ship frame), so every
// mod's ships look like the game's whatever renderer their importer had.
// The ships are drawn on the main menu's loading screen (IconsReady, polled by ModLoading.Busy) once their models are built,
// and kept on disk for later plays (persistentDataPath/ModCache/ShipIcons/<mod id>/<key>.png): the key is the hull's
// triangles, its materials' shaders and main textures, the mod's version and IconVersion, so a changed model or skin is
// drawn again. The pass keeps only the files its ships used in their mods' folders, and ModManager.Scan deletes the folders
// of the mods no longer installed (PruneCache). A mod's own icon always wins; a server (batch mode) draws none.

using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;
using UnityEngine;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class ModShipIcons
    {
        /// <summary>Bumped when ShipIconMaker draws differently: the icons drawn before are drawn again.</summary>
        const int IconVersion = 1;
        /// <summary>Main-thread time per frame for the pass (at least one ship): a draw is a few renders and reads back.</summary>
        const double FrameMs = 12.0;

        static readonly List<(int ship, string name, GameObject template)> queue = new List<(int, string, GameObject)>();
        static readonly List<Texture2D> made = new List<Texture2D>();
        static readonly HashSet<string> usedFiles = new HashSet<string>(System.StringComparer.OrdinalIgnoreCase);
        static readonly HashSet<string> modDirs = new HashSet<string>(System.StringComparer.OrdinalIgnoreCase);
        static int revision = -1, next;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics()
        {
            queue.Clear(); made.Clear(); usedFiles.Clear(); modDirs.Clear();
            revision = -1; next = 0; Done = Drawn = 0; Current = null;
        }

        /// <summary>The ships the pass has done (ModLoading's progress and line), how many it drew (not from the cache).</summary>
        public static int Done { get; private set; }
        public static int Drawn { get; private set; }
        public static int Count => queue.Count;
        /// <summary>The ship being drawn now (null: none).</summary>
        public static string Current { get; private set; }

        /// <summary>This game draws icons: not a server.</summary>
        public static bool Wanted => !Application.isBatchMode;

        /// <summary>How far the pass is, 0..1 (0 until the models are built).</summary>
        public static float Progress => revision != ModManager.Revision ? 0f : queue.Count == 0 ? 1f : Done / (float)queue.Count;

        /// <summary>Every built mod ship without an icon of its own has one now. Polled each frame while the loading screen
        /// shows (ModLoading.Busy): starts once the models are built, then reads or draws icons for FrameMs of each call.</summary>
        public static bool IconsReady
        {
            get
            {
                if (!ModShips.Ready) return false;
                if (revision != ModManager.Revision) Start();
                if (Done >= queue.Count) return true;
                Tick();
                return Done >= queue.Count;
            }
        }

        static void Start()
        {
            foreach (var t in made) if (t != null) Object.Destroy(t);   // ModShips dropped them with its models
            made.Clear(); queue.Clear(); usedFiles.Clear(); modDirs.Clear();
            revision = ModManager.Revision;
            next = 0; Done = Drawn = 0; Current = null;
            if (!Wanted) return;
            foreach (var (ship, name, template) in ModShips.Built)
                if (template != null && ModShips.Icon(ship) == null) queue.Add((ship, name, template));
        }

        static void Tick()
        {
            long start = System.Diagnostics.Stopwatch.GetTimestamp();
            while (next < queue.Count)
            {
                var (ship, name, template) = queue[next++];
                Current = name;
                try
                {
                    if (template != null && ModShips.Icon(ship) == null)
                    {
                        var icon = Icon(template);
                        if (icon != null) ModShips.SetIcon(ship, icon);
                    }
                }
                catch (System.Exception e) { Debug.LogWarning($"Mods: the icon of ship {ship} \"{name}\": {e.Message}"); }
                Done++;
                if ((System.Diagnostics.Stopwatch.GetTimestamp() - start) * 1000.0 / System.Diagnostics.Stopwatch.Frequency >= FrameMs) break;
            }
            if (Done < queue.Count) return;
            Current = null;
            if (queue.Count > 0)
            {
                Debug.Log($"Mods: {queue.Count} ship icon(s) ready, {Drawn} drawn");
                PruneUnused();
            }
        }

        /// <summary>A template's icon: from the cache, else drawn (ShipIconMaker) and saved there.</summary>
        static Texture2D Icon(GameObject template)
        {
            var mod = ModOf(template);
            string file = null;
            if (mod != null)
            {
                string dir = Path.GetFullPath(Path.Combine(CacheRoot, mod.Id));
                modDirs.Add(dir);
                file = Path.Combine(dir, Key(template, mod) + ".png");
                try
                {
                    if (File.Exists(file))
                    {
                        var cached = new Texture2D(2, 2, TextureFormat.RGBA32, false) { wrapMode = TextureWrapMode.Clamp, name = "mod ship icon" };
                        if (cached.LoadImage(File.ReadAllBytes(file), true))
                        {
                            usedFiles.Add(file);
                            made.Add(cached);
                            return cached;
                        }
                        Object.Destroy(cached);
                    }
                }
                catch (System.Exception e) { Debug.LogWarning($"Mods: ship icon cache ({mod.Id}): {e.Message}"); }
            }
            var icon = ShipIconMaker.Make(template);
            if (icon == null) return null;
            Drawn++;
            made.Add(icon);
            if (file != null)
                try
                {
                    Directory.CreateDirectory(Path.GetDirectoryName(file));
                    string tmp = file + ".tmp";
                    File.WriteAllBytes(tmp, icon.EncodeToPNG());
                    if (File.Exists(file)) File.Delete(file);
                    File.Move(tmp, file);
                    usedFiles.Add(file);
                }
                catch (System.Exception e) { Debug.LogWarning($"Mods: ship icon cache ({mod.Id}): {e.Message}"); }
            return icon;
        }

        /// <summary>What the icon is drawn from: the hull's triangles, each drawn mesh's materials (shader, main texture and
        /// its size), the mod's version and IconVersion (SHA-256, first 16 hex).</summary>
        static string Key(GameObject template, ModInfo mod)
        {
            var tris = new List<Vector3>();
            World.ShipShadowBaker.Collect(template, tris, out _, true);
            var text = new System.Text.StringBuilder($"{IconVersion}|{mod.Id}|{mod.Version}|{tris.Count}");
            foreach (var r in template.GetComponentsInChildren<Renderer>(true))
            {
                if (!(r is MeshRenderer || r is SkinnedMeshRenderer)) continue;
                text.Append('|').Append(r.name).Append(r.enabled ? '+' : '-');
                foreach (var m in r.sharedMaterials)
                {
                    if (m == null) continue;
                    var tex = m.HasProperty("_BaseMap") ? m.GetTexture("_BaseMap") : m.mainTexture;
                    text.Append(';').Append(m.shader != null ? m.shader.name : "").Append(':')
                        .Append(tex != null ? $"{tex.name}@{tex.width}x{tex.height}" : "-");
                }
            }
            var header = System.Text.Encoding.UTF8.GetBytes(text.ToString());
            var bytes = new byte[header.Length + tris.Count * 12];
            System.Buffer.BlockCopy(header, 0, bytes, 0, header.Length);
            int o = header.Length;
            foreach (var p in tris)
            {
                System.BitConverter.TryWriteBytes(new System.Span<byte>(bytes, o, 4), p.x);
                System.BitConverter.TryWriteBytes(new System.Span<byte>(bytes, o + 4, 4), p.y);
                System.BitConverter.TryWriteBytes(new System.Span<byte>(bytes, o + 8, 4), p.z);
                o += 12;
            }
            using var sha = SHA256.Create();
            var h = sha.ComputeHash(bytes);
            var sb = new System.Text.StringBuilder(16);
            for (int i = 0; i < 8; i++) sb.Append(h[i].ToString("x2"));
            return sb.ToString();
        }

        /// <summary>The installed mod a template comes from (its origin "mod &lt;id&gt;"), else null.</summary>
        static ModInfo ModOf(GameObject template)
        {
            if (!World.ShipShadowBaker.IsModShip(template)) return null;
            var mod = ModManager.Find(template.GetComponent<Visuals.AssembledObject>().origin.Substring(4).Trim());
            return mod != null && mod.Manifest != null && !string.IsNullOrEmpty(mod.Id) ? mod : null;
        }

        /// <summary>persistentDataPath/ModCache/ShipIcons (main thread only: persistentDataPath).</summary>
        static string CacheRoot => Path.Combine(GamePaths.Data, "ModCache", "ShipIcons");

        /// <summary>The pass is done: in each of its mods' folders only the icons its ships used stay.</summary>
        static void PruneUnused()
        {
            int removed = 0;
            foreach (var dir in modDirs)
                try
                {
                    if (!Directory.Exists(dir)) continue;
                    foreach (var f in Directory.GetFiles(dir))
                        if (!usedFiles.Contains(Path.GetFullPath(f))) { File.Delete(f); removed++; }
                }
                catch (System.Exception e) { Debug.LogWarning($"Mods: ship icon cache: {e.Message}"); }
            if (removed > 0) Debug.Log($"Mods: removed {removed} unused cached ship icon(s)");
        }

        /// <summary>Deletes the cached icons of the mods no longer installed (ModManager.Scan: 'installedIds' every mod id
        /// found, on or off).</summary>
        public static void PruneCache(IEnumerable<string> installedIds)
        {
            try
            {
                string root = CacheRoot;
                if (!Directory.Exists(root)) return;
                var keep = new HashSet<string>(installedIds, System.StringComparer.OrdinalIgnoreCase);
                foreach (var dir in Directory.GetDirectories(root))
                    if (!keep.Contains(Path.GetFileName(dir))) Directory.Delete(dir, true);
            }
            catch (System.Exception e) { Debug.LogWarning($"Mods: ship icon cache: {e.Message}"); }
        }
    }
}
