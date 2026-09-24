// Settings.cs
// Player options (original: Status / options menu: music volume, sound volume, steering sensitivity,
// invert, ...), stored in PlayerPrefs. Plain C# so menus and game code can share it.

using System;
using UnityEngine;

namespace GoF2Remake.Data
{
    /// <summary>Frame rate option (remake only; the original ran at the device's fixed rate).</summary>
    public enum FrameRate { Fps30, Fps60, Fps120, Uncapped, VSync }

    public static class Settings
    {
        const string Prefix = "gof2.";

        public static event Action Changed;

        public static float MusicVolume { get => Get("musicVolume", 0.8f); set => Set("musicVolume", Mathf.Clamp01(value)); }
        public static float SfxVolume { get => Get("sfxVolume", 1f); set => Set("sfxVolume", Mathf.Clamp01(value)); }
        public static float VoiceVolume { get => Get("voiceVolume", 1f); set => Set("voiceVolume", Mathf.Clamp01(value)); }

        /// <summary>Steering sensitivity (FlightModel.Sensitivity, 0..2.2).</summary>
        public static float Sensitivity { get => Get("sensitivity", 1f); set => Set("sensitivity", Mathf.Clamp(value, 0f, 2.2f)); }
        public static bool InvertPitch { get => Get("invertPitch", 0f) > 0.5f; set => Set("invertPitch", value ? 1f : 0f); }

        /// <summary>Post-processing bloom on/off (graphics option).</summary>
        public static bool Bloom { get => Get("bloom", 1f) > 0.5f; set => Set("bloom", value ? 1f : 0f); }

        /// <summary>Original "Brightness" option: 0 Dark, 1 Medium, 2 Bright (texts 513-515).</summary>
        public static int Brightness { get => Mathf.RoundToInt(Get("brightness", 1f)); set => Set("brightness", Mathf.Clamp(value, 0, 2)); }

        /// <summary>Exposure offset for the brightness option (applied through post-processing).</summary>
        public static float BrightnessExposure => (Brightness - 1) * 0.35f;

        /// <summary>Frame rate limit, applied by Bootstrap. V-Sync (display refresh rate) by default.</summary>
        public static FrameRate FrameRate
        {
            get => (FrameRate)Mathf.Clamp(Mathf.RoundToInt(Get("frameRate", (float)FrameRate.VSync)), 0, (int)FrameRate.VSync);
            set => Set("frameRate", (float)value);
        }

        /// <summary>Language code of Localization/text_{code}.json.</summary>
        public static string Language
        {
            get => PlayerPrefs.GetString(Prefix + "language", "en");
            set { PlayerPrefs.SetString(Prefix + "language", value); PlayerPrefs.Save(); Changed?.Invoke(); }
        }

        static float Get(string key, float fallback) => PlayerPrefs.GetFloat(Prefix + key, fallback);

        static void Set(string key, float value)
        {
            if (Mathf.Approximately(PlayerPrefs.GetFloat(Prefix + key, float.NaN), value)) return;
            PlayerPrefs.SetFloat(Prefix + key, value);
            PlayerPrefs.Save();
            Changed?.Invoke();
        }
    }
}
