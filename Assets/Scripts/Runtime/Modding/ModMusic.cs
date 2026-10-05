// ModMusic.cs
// Remake mods: music. A mod that is on ships tracks in its music folder (music/<name>.ogg | .wav | .mp3):
//   - a track named like one of the game's (the file names in Assets/Audio/MUSIC, DLC_MUSIC, DLC2_MUSIC: Space_Terraner,
//     Station_Vossk, Space_Battle_Low, Space_NoCombat_Void (the main menu), IntroAtmo_02, OutroSong_02b...) replaces it
//     wherever the game plays it (Replace, at every place that starts music);
//   - any other name is a new track: the event graphs' Play Music / "/music <name>" play it, and a mod's systems.json /
//     stations.json name it as a system's space or station music ("spaceMusic", "stationMusic") or a station's ("music").
// A later mod in the load order wins. Every track loads in the background when the mods change (Preload; the main menu
// waits for it before a game starts, MainMenu.Leave); Changed fires as tracks arrive (the menu swaps its theme then).

using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class ModMusic
    {
        static readonly Dictionary<string, AudioClip> tracks = new Dictionary<string, AudioClip>(StringComparer.OrdinalIgnoreCase);
        static readonly HashSet<string> names = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        static int revision = -1, loading;

        /// <summary>A track finished loading.</summary>
        public static event Action Changed;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { tracks.Clear(); names.Clear(); revision = -1; loading = 0; Changed = null; }

        /// <summary>The tracks to load and those still loading (the main menu's loading screen).</summary>
        public static int Count => names.Count;
        public static int Loading => loading;

        /// <summary>Every track of the mods that are on is loaded (or failed).</summary>
        public static bool Ready { get { Preload(); return loading == 0; } }

        /// <summary>Loads the mods' tracks again when the mods changed (no-op otherwise).</summary>
        public static void Preload()
        {
            if (revision == ModManager.Revision) return;
            revision = ModManager.Revision;
            tracks.Clear();
            names.Clear();
            // The last mod in the load order with a name wins.
            var files = new Dictionary<string, (ModInfo mod, string file)>(StringComparer.OrdinalIgnoreCase);
            foreach (var mod in ModManager.Active)
                foreach (string f in mod.Source.FilesIn("music", ModAudio.Extensions))
                    files[Path.GetFileNameWithoutExtension(f)] = (mod, f);
            int started = revision;
            foreach (var kv in files)
            {
                string name = kv.Key;
                names.Add(name);
                loading++;
                ModAudio.Load(kv.Value.mod, kv.Value.file, clip =>
                {
                    if (started != revision) return;   // the mods changed meanwhile (that load counts afresh)
                    loading--;
                    if (clip == null) return;
                    tracks[name] = clip;
                    Debug.Log($"Mods: {kv.Value.mod.Id}: music \"{name}\"");
                    Changed?.Invoke();
                });
            }
        }

        /// <summary>A mod's track by name (null: none, or still loading).</summary>
        public static AudioClip Track(string name)
        {
            if (string.IsNullOrEmpty(name)) return null;
            Preload();
            return tracks.TryGetValue(name, out var c) ? c : null;
        }

        /// <summary>A mod ships a track of that name (loaded or not).</summary>
        public static bool Has(string name) { Preload(); return !string.IsNullOrEmpty(name) && names.Contains(name); }

        /// <summary>The mods' track names (the graphs' and /music's list).</summary>
        public static IEnumerable<string> Names { get { Preload(); return names; } }

        /// <summary>The game's track, or a mod's replacement of the same name.</summary>
        public static AudioClip Replace(AudioClip clip) => clip == null ? null : Track(clip.name) ?? clip;
    }
}
