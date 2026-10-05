// ModVoices.cs
// Remake mods: voice-over for the event graphs' dialogue and radio lines. A page's text may hold "[voice <clip>]" (taken
// out of the text, Take): the clip is one of the original voice lines by its event name (StoryAssets.Voice, e.g.
// MSG_MISSION_24_NO_EQUIPMENT_INSTALLED) or an audio file a mod that is on ships: voices/<language>/<clip>.ogg | .wav |
// .mp3 (the voice language, de / en, Settings.GermanVoices), else voices/<clip>.<ext>; a later mod in the load order wins.
// The files load in the background (Preload, when the page arrives; ModAudio); StoryAssets.Voice then finds them (Get), so
// the dialogue window and the radio box play them like the story's voices (EventScreen holds a dialogue up to 3 s for its
// clips). Every game resolves the clip from its own mods (a session's are the same for all).

using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class ModVoices
    {
        static readonly Dictionary<string, AudioClip> clips = new Dictionary<string, AudioClip>(StringComparer.OrdinalIgnoreCase);
        static readonly HashSet<string> loading = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        static readonly HashSet<string> missing = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        static int revision = -1;

        static readonly Regex Token = new Regex(@"\[voice\s+([A-Za-z0-9_\-./]+)\s*\]", RegexOptions.IgnoreCase);

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { clips.Clear(); loading.Clear(); missing.Clear(); revision = -1; }

        /// <summary>The "[voice &lt;clip&gt;]" of a page's text (null: none); the text without it.</summary>
        public static string Take(ref string text)
        {
            if (string.IsNullOrEmpty(text) || text.IndexOf("[voice", StringComparison.OrdinalIgnoreCase) < 0) return null;
            var m = Token.Match(text);
            if (!m.Success) return null;
            text = (text.Substring(0, m.Index) + text.Substring(m.Index + m.Length)).Replace("  ", " ").Trim();
            return m.Groups[1].Value;
        }

        static string Language => Settings.GermanVoices ? "de" : "en";
        static string Key(string name) => Language + "/" + name;

        static void CheckMods()
        {
            if (revision == ModManager.Revision) return;
            revision = ModManager.Revision;
            clips.Clear();
            missing.Clear();
        }

        /// <summary>A mod's clip once loaded (null: none, or still loading).</summary>
        public static AudioClip Get(string name)
        {
            if (string.IsNullOrEmpty(name)) return null;
            CheckMods();
            return clips.TryGetValue(Key(name), out var c) ? c : null;
        }

        /// <summary>The clip is still loading.</summary>
        public static bool Pending(string name) => !string.IsNullOrEmpty(name) && loading.Contains(Key(name));

        /// <summary>Starts loading a mod's clip (nothing for an original voice line, one loaded or one no mod has).</summary>
        public static void Preload(string name)
        {
            if (string.IsNullOrEmpty(name) || name.Contains("..")) return;
            CheckMods();
            string key = Key(name);
            if (clips.ContainsKey(key) || loading.Contains(key) || missing.Contains(key)) return;
            var assets = StoryAssets.Load();
            if (assets != null && assets.Voice(name) != null) return;   // an original line
            var mods = ModManager.Active;
            for (int m = mods.Count - 1; m >= 0; m--)
                foreach (string folder in new[] { "voices/" + Language + "/", "voices/" })
                    foreach (string ext in ModAudio.Extensions)
                    {
                        string file = ModAudio.Find(mods[m].Source, folder + name + ext);
                        if (file == null) continue;
                        int started = revision;
                        loading.Add(key);
                        ModAudio.Load(mods[m], file, clip =>
                        {
                            loading.Remove(key);
                            if (started != revision) return;   // the mods changed meanwhile
                            if (clip != null) clips[key] = clip; else missing.Add(key);
                        });
                        return;
                    }
            missing.Add(key);
            Debug.LogWarning($"Mods: no voice clip \"{name}\" (voices/{Language}/{name}.ogg or voices/{name}.ogg in a mod that is on)");
        }
    }
}
