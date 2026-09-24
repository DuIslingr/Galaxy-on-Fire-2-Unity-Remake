// StoryAssets.cs
// What the story presentation can't load by name (Resources/GoF2Story/StoryAssets, built by "GoF2 > Build Story Assets"):
//   voice lines   Audio/VOICE_*, DLC_VOICE_*, DLC2_VOICE_* (FMOD voice banks, dialogue_cutscenes.md 5.1), English and
//                 German (the German files carry a "de_" prefix; only part of the lines were recorded in German)
//   portraits     the face parts Textures/textures/<body>_<part>_<variant>_ipad_large.png (ImageFactory::loadImage 0x141870)
//                 plus the portrait background 0x485 and frame 0x511 (Resources/GoF2Hud)
//   cutscenes     the prologue's sounds (FMOD ids 141-143, 156-161, fmod_event_ids.txt with dialogue_cutscenes.md 5.2's
//                 correction) and its skies (skybox_003 = Level::createSpace's intro sky 0x458b / 0x2754, skybox_009 =
//                 switchSkyboxForIntro 0x4591 / 0x275a)
// The voice clips don't preload their audio data, so referencing all of them here is cheap.

using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Data
{
    public class StoryAssets : ScriptableObject
    {
        public List<string> voiceNamesEng = new List<string>();
        public List<AudioClip> voiceClipsEng = new List<AudioClip>();
        public List<string> voiceNamesDeu = new List<string>();
        public List<AudioClip> voiceClipsDeu = new List<AudioClip>();
        [Tooltip("\"body_part_variant\" names of the portrait parts.")]
        public List<string> partNames = new List<string>();
        public List<Texture2D> partTextures = new List<Texture2D>();
        [Tooltip("Height of each part's image inside its power-of-two canvas (the .aei region, Textures/_texture_manifest.json).")]
        public List<int> partHeights = new List<int>();
        public Texture2D portraitBackground, portraitFrame;
        [Header("Cutscenes")]
        public AudioClip introAtmo;           // 143 IntroAtmo
        public AudioClip battleFull;          // 142 Space_Combat_Full
        public AudioClip timeShift;           // 141 (TimeShift_Start)
        public AudioClip cutsceneExplosion;   // 157 Cutscenes_Explosion
        public AudioClip rumble;              // 158 Rumble_CutScene_01
        public AudioClip timeJumpEnd;         // 159 TimeSpaceJumpEnd (no file of its own: SpaceTimeJump stands in)
        public AudioClip timeJump;            // 160 SpaceTimeJump
        public AudioClip engineBroken;        // 161 Engine_09_Broken
        public AudioClip engineBrokenLoop;    // 156 Spaceship_Engine_05_Broken
        public Material introSky, introSkyAfterJump;
        public GameObject hyperDrive;         // mesh 15027 hyper_drive

        Dictionary<string, AudioClip> eng, deu;
        Dictionary<string, (Texture2D tex, int height)> parts;

        static StoryAssets instance;
        public static StoryAssets Load() => instance != null ? instance : instance = Resources.Load<StoryAssets>("GoF2Story/StoryAssets");

        /// <summary>A voice line by its event name; German when the language is German and the line was recorded, else
        /// English (FMOD's language banks).</summary>
        public AudioClip Voice(string name)
        {
            if (string.IsNullOrEmpty(name)) return null;
            eng ??= Map(voiceNamesEng, voiceClipsEng);
            deu ??= Map(voiceNamesDeu, voiceClipsDeu);
            if (Settings.Language == "de" && deu.TryGetValue(name, out var d)) return d;
            return eng.TryGetValue(name, out var e) ? e : null;
        }

        /// <summary>A portrait part: its texture (the image sits in the top-left corner of the canvas) and image height.</summary>
        public (Texture2D tex, int height) Part(int body, int part, int variant) => Part($"{body}_{part}_{variant}");

        public (Texture2D tex, int height) Part(string key)
        {
            if (parts == null)
            {
                parts = new Dictionary<string, (Texture2D, int)>();
                for (int i = 0; i < partNames.Count && i < partTextures.Count; i++)
                    parts[partNames[i]] = (partTextures[i], i < partHeights.Count ? partHeights[i] : partTextures[i] != null ? partTextures[i].height : 0);
            }
            return parts.TryGetValue(key, out var t) ? t : (null, 0);
        }

        static Dictionary<string, T> Map<T>(List<string> names, List<T> values)
        {
            var d = new Dictionary<string, T>();
            for (int i = 0; i < names.Count && i < values.Count; i++) d[names[i]] = values[i];
            return d;
        }
    }
}
