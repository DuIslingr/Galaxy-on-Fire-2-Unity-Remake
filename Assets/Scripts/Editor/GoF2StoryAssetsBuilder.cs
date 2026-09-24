// GoF2StoryAssetsBuilder.cs  (Editor only)
// Menu "GoF2/Build Story Assets": Resources/GoF2Story/StoryAssets (GoF2StoryAssets): the story voice lines (English and
// German, base game and both add-ons) and the portrait parts. Needs the HUD images (portrait background / frame).

using System.IO;
using System.Text.RegularExpressions;
using GoF2Remake.Data;
using UnityEditor;
using UnityEngine;

namespace GoF2Remake.EditorTools
{
    public static class GoF2StoryAssetsBuilder
    {
        const string Root = GoF2ImportSettings.Root;
        public const string AssetPath = Root + "/Resources/GoF2Story/StoryAssets.asset";
        static readonly string[] VoiceBanks = { "VOICE", "DLC_VOICE", "DLC2_VOICE" };
        static readonly Regex PartName = new Regex(@"^(\d+)_(\d)_(\d+)_ipad_large$");

        [MenuItem("GoF2/Build Story Assets", priority = 18)]
        public static void Build()
        {
            Directory.CreateDirectory(Path.GetDirectoryName(AssetPath));
            var a = AssetDatabase.LoadAssetAtPath<GoF2StoryAssets>(AssetPath);
            if (a == null) { a = ScriptableObject.CreateInstance<GoF2StoryAssets>(); AssetDatabase.CreateAsset(a, AssetPath); }

            a.voiceNamesEng.Clear(); a.voiceClipsEng.Clear(); a.voiceNamesDeu.Clear(); a.voiceClipsDeu.Clear();
            foreach (var bank in VoiceBanks)
            {
                AddVoices($"{Root}/Audio/{bank}_eng", "", a.voiceNamesEng, a.voiceClipsEng);
                AddVoices($"{Root}/Audio/{bank}_deu", "de_", a.voiceNamesDeu, a.voiceClipsDeu);
            }

            a.partNames.Clear(); a.partTextures.Clear(); a.partHeights.Clear();
            var regions = ManifestRegionHeights();
            foreach (var guid in AssetDatabase.FindAssets("t:Texture2D", new[] { $"{Root}/Textures/textures" }))
            {
                string path = AssetDatabase.GUIDToAssetPath(guid);
                var m = PartName.Match(Path.GetFileNameWithoutExtension(path));
                if (!m.Success) continue;
                a.partNames.Add($"{m.Groups[1].Value}_{m.Groups[2].Value}_{m.Groups[3].Value}");
                var tex = AssetDatabase.LoadAssetAtPath<Texture2D>(path);
                a.partTextures.Add(tex);
                a.partHeights.Add(regions.TryGetValue(Path.GetFileName(path), out int h) ? h : tex != null ? tex.height : 0);
            }
            a.portraitBackground = AssetDatabase.LoadAssetAtPath<Texture2D>($"{Root}/Resources/GoF2Hud/portrait_bg.png");
            a.portraitFrame = AssetDatabase.LoadAssetAtPath<Texture2D>($"{Root}/Resources/GoF2Hud/portrait_frame.png");
            if (a.portraitBackground == null || a.portraitFrame == null) Debug.LogWarning("GoF2: portrait background / frame missing, run Build HUD Images");

            a.introAtmo = Clip("MUSIC/IntroAtmo_02.ogg");
            a.battleFull = Clip("MUSIC/Space_Battle_Full.ogg");
            a.timeShift = Clip("MUSIC/TimeShift_Start.ogg");
            a.cutsceneExplosion = Clip("SFX_SPACE/Cutscenes_Explosion_01.ogg");
            a.rumble = Clip("SFX_SPACE/Rumble_CutScene_01.ogg");
            a.timeJump = Clip("CUTSCENES/SpaceTimeJump_01.ogg");
            a.timeJumpEnd = a.timeJump;
            a.engineBroken = Clip("SFX_SPACE/Engine_09_Broken.ogg");
            a.engineBrokenLoop = Clip("SFX_SPACE/Spaceship_Engine_05_Broken_02.ogg");
            a.introSky = AssetDatabase.LoadAssetAtPath<Material>($"{Root}/Skyboxes/skybox_003.mat");
            a.introSkyAfterJump = AssetDatabase.LoadAssetAtPath<Material>($"{Root}/Skyboxes/skybox_009.mat");
            a.hyperDrive = AssetDatabase.LoadAssetAtPath<GameObject>($"{Root}/Prefabs/main/fx/hyper_drive.prefab");

            EditorUtility.SetDirty(a);
            AssetDatabase.SaveAssets();
            Debug.Log($"GoF2: story assets at {AssetPath} ({a.voiceClipsEng.Count} English / {a.voiceClipsDeu.Count} German voice lines, " +
                      $"{a.partTextures.Count} portrait parts).");
        }

        /// <summary>Textures/_texture_manifest.json: png name -> height of its first region (the .aei image inside the canvas).</summary>
        static System.Collections.Generic.Dictionary<string, int> ManifestRegionHeights()
        {
            var map = new System.Collections.Generic.Dictionary<string, int>();
            string path = $"{Root}/Textures/_texture_manifest.json";
            if (!File.Exists(path)) { Debug.LogWarning("GoF2: texture manifest missing"); return map; }
            // "regions": [[x, y, w, h]] is a nested array (JsonUtility can't read it): a small regex per entry instead.
            var entry = new Regex(@"""regions"":\s*\[\s*\[\s*-?\d+,\s*-?\d+,\s*(\d+),\s*(\d+)\s*\][^{}]*?""png"":\s*""([^""]+)""");
            foreach (Match m in entry.Matches(File.ReadAllText(path)))
                map[Path.GetFileName(m.Groups[3].Value)] = int.Parse(m.Groups[2].Value);
            return map;
        }

        static AudioClip Clip(string rel)
        {
            var c = AssetDatabase.LoadAssetAtPath<AudioClip>($"{Root}/Audio/{rel}");
            if (c == null) Debug.LogWarning($"GoF2: missing clip {rel}");
            return c;
        }

        static void AddVoices(string folder, string prefix, System.Collections.Generic.List<string> names, System.Collections.Generic.List<AudioClip> clips)
        {
            if (!AssetDatabase.IsValidFolder(folder)) { Debug.LogWarning($"GoF2: missing voice folder {folder}"); return; }
            foreach (var guid in AssetDatabase.FindAssets("t:AudioClip", new[] { folder }))
            {
                string path = AssetDatabase.GUIDToAssetPath(guid);
                string name = Path.GetFileNameWithoutExtension(path);
                if (prefix.Length > 0 && name.StartsWith(prefix)) name = name.Substring(prefix.Length);
                names.Add(name);
                clips.Add(AssetDatabase.LoadAssetAtPath<AudioClip>(path));
            }
        }
    }
}
