// ModAudio.cs
// Remake mods: loading a mod's audio file (.ogg, .wav, .mp3) into an AudioClip, for ModVoices and ModMusic. Unity can't
// decode compressed audio from bytes, so the file is read with UnityWebRequestMultimedia from disk: a folder mod's own
// file, a zip mod's copied into the cache first. In the background; the
// callback gets the clip, or null when it couldn't be read (logged). (The zip copy is ModInfo.LocalFile, shared with the
// textures' background decoding.)

using System;
using System.IO;
using UnityEngine;
using UnityEngine.Networking;

namespace GoF2Remake.Modding
{
    public static class ModAudio
    {
        public static readonly string[] Extensions = { ".ogg", ".wav", ".mp3" };

        /// <summary>The AudioType of a file name (Unknown: not one of the Extensions).</summary>
        public static AudioType TypeOf(string file)
        {
            string ext = Path.GetExtension(file ?? "").ToLowerInvariant();
            return ext == ".ogg" ? AudioType.OGGVORBIS : ext == ".wav" ? AudioType.WAV : ext == ".mp3" ? AudioType.MPEG : AudioType.UNKNOWN;
        }

        /// <summary>The file's own spelling in the mod (any case; null: no such file).</summary>
        public static string Find(ModSource source, string path)
        {
            foreach (var f in source.Files) if (string.Equals(f, path, StringComparison.OrdinalIgnoreCase)) return f;
            return null;
        }

        /// <summary>Loads 'file' of 'mod' and calls 'done' with the clip or null. 'compressed': kept compressed in memory
        /// (music and voices are long); sound effects are decoded once (no decoding per play).</summary>
        public static async void Load(ModInfo mod, string file, Action<AudioClip> done, bool compressed = true)
        {
            AudioClip clip = null;
            try
            {
                var type = TypeOf(file);
                if (type == AudioType.UNKNOWN) throw new Exception("not an .ogg, .wav or .mp3 file");
                // A zip mod's file is copied out on a worker thread (ModInfo.LocalFile).
                string path = await System.Threading.Tasks.Task.Run(() => mod.LocalFile(file));
                if (path == null) throw new Exception("can't be read");
                using var req = UnityWebRequestMultimedia.GetAudioClip(new Uri(path).AbsoluteUri, type);
                if (req.downloadHandler is DownloadHandlerAudioClip handler) handler.compressed = compressed;
                var op = req.SendWebRequest();
                while (!op.isDone) await Awaitable.NextFrameAsync();
                if (req.result != UnityWebRequest.Result.Success) throw new Exception(req.error);
                clip = DownloadHandlerAudioClip.GetContent(req);
                if (clip != null) clip.name = Path.GetFileNameWithoutExtension(file);
            }
            catch (Exception e) { Debug.LogWarning($"Mods: {mod.Id}: {file}: {e.Message}"); clip = null; }
            done?.Invoke(clip);
        }
    }
}
