// Settings.cs
// Player options (original: Globals::init option defaults / the options menu: music, sound and voice volume,
// brightness, quality, steering sensitivity, invert, Reference/research/mainmenu_notes.md 2.6), stored in PlayerPrefs.
// Plain C# so menus and game code can share it; Bootstrap applies the process-wide ones. The rest are remake options.

using System;
using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Data
{
    /// <summary>Frame rate option (remake only; the original ran at the device's fixed rate).</summary>
    public enum FrameRate { Fps30, Fps60, Fps120, Uncapped, VSync }

    /// <summary>Window mode option (desktop only).</summary>
    public enum DisplayMode { Borderless, Fullscreen, Windowed }

    public static class Settings
    {
        const string Prefix = "gof2.";

        /// <summary>The original's vertical field of view (MGame::reset, 1.22 rad).</summary>
        public const float OriginalFov = 1.22f * Mathf.Rad2Deg;
        public const float DefaultDeadzone = 0.125f;   // the Input System's default stick dead zone

        public static event Action Changed;

        // ---- sound -------------------------------------------------------------------------------------------

        public static float MasterVolume { get => Get("masterVolume", 1f); set => Set("masterVolume", Mathf.Clamp01(value)); }
        public static float MusicVolume { get => Get("musicVolume", 0.8f); set => Set("musicVolume", Mathf.Clamp01(value)); }
        public static float SfxVolume { get => Get("sfxVolume", 1f); set => Set("sfxVolume", Mathf.Clamp01(value)); }
        public static float VoiceVolume { get => Get("voiceVolume", 1f); set => Set("voiceVolume", Mathf.Clamp01(value)); }

        // ---- graphics ----------------------------------------------------------------------------------------

        public static DisplayMode DisplayMode
        {
            get => (DisplayMode)Mathf.Clamp(Mathf.RoundToInt(Get("displayMode", 0f)), 0, (int)DisplayMode.Windowed);
            set => Set("displayMode", (float)value);
        }

        /// <summary>Screen resolution (desktop); 0 x 0 = the display's own.</summary>
        public static Vector2Int Resolution
        {
            get => new Vector2Int(Mathf.RoundToInt(Get("resolutionWidth", 0f)), Mathf.RoundToInt(Get("resolutionHeight", 0f)));
            set { SetQuiet("resolutionWidth", value.x); Set("resolutionHeight", value.y, force: true); }
        }

        /// <summary>Frame rate limit, applied by Bootstrap. V-Sync (display refresh rate) by default.</summary>
        public static FrameRate FrameRate
        {
            get => (FrameRate)Mathf.Clamp(Mathf.RoundToInt(Get("frameRate", (float)FrameRate.VSync)), 0, (int)FrameRate.VSync);
            set => Set("frameRate", (float)value);
        }

        /// <summary>URP render scale; 0 = the platform's render pipeline asset (1 on PC, 0.8 on mobile).</summary>
        public static float RenderScale { get => Get("renderScale", 0f); set => Set("renderScale", value <= 0f ? 0f : Mathf.Clamp(value, 0.5f, 2f)); }

        /// <summary>Upscaler (the URP asset's upscaling filter): 0 off (URP's automatic bilinear / point), 1 AMD FSR 1
        /// (sharpening, also at 100 %), 2 Unity STP (temporal: anti-aliasing and upscaling, replaces MSAA).</summary>
        public static int Upscaler { get => Mathf.RoundToInt(Get("upscaler", 0f)); set => Set("upscaler", Mathf.Clamp(value, 0, 2)); }
        public const int UpscalerOff = 0, UpscalerFsr = 1, UpscalerStp = 2;

        /// <summary>MSAA samples (1 = off, 2, 4, 8); 0 = the platform's render pipeline asset.</summary>
        public static int Msaa { get => Mathf.RoundToInt(Get("msaa", 0f)); set => Set("msaa", value); }

        /// <summary>Original "Quality" option (504; texts 507-512): 0 Low (smoke off, fog off, detail low), 1 Medium (smoke
        /// off, fog off, detail medium), 2 High (everything on). Default High (Globals::init options+0x28 = 1.0).</summary>
        public static int Quality { get => Mathf.RoundToInt(Get("quality", 2f)); set => Set("quality", Mathf.Clamp(value, 0, 2)); }
        public static bool QualityEffects => Quality >= 2;

        /// <summary>Original "Brightness" option: 0 Dark, 1 Medium, 2 Bright (texts 513-515).</summary>
        public static int Brightness { get => Mathf.RoundToInt(Get("brightness", 1f)); set => Set("brightness", Mathf.Clamp(value, 0, 2)); }

        /// <summary>Exposure offset for the brightness option (applied through post-processing).</summary>
        public static float BrightnessExposure => (Brightness - 1) * 0.35f;

        /// <summary>Post-processing bloom on/off.</summary>
        public static bool Bloom { get => GetBool("bloom", true); set => SetBool("bloom", value); }

        /// <summary>The sun's lens flare in flight (LensFlareView).</summary>
        public static bool LensFlare { get => GetBool("lensFlare", true); set => SetBool("lensFlare", value); }

        /// <summary>The chase camera's vertical field of view in degrees (at 16:9; the original's is OriginalFov).</summary>
        public static float FieldOfView { get => Get("fov", OriginalFov); set => Set("fov", Mathf.Clamp(value, 55f, 95f)); }

        /// <summary>Camera shake and rumble strength, 0..1 (hits, collisions, explosions, cutscenes).</summary>
        public static float CameraShake { get => Get("cameraShake", 1f); set => Set("cameraShake", Mathf.Clamp01(value)); }

        // ---- controls ----------------------------------------------------------------------------------------

        /// <summary>Steering sensitivity (FlightModel.Sensitivity, 0..2.2).</summary>
        public static float Sensitivity { get => Get("sensitivity", 1f); set => Set("sensitivity", Mathf.Clamp(value, 0f, 2.2f)); }
        public static bool InvertPitch { get => GetBool("invertPitch", false); set => SetBool("invertPitch", value); }
        /// <summary>Globals::mouseCursorActivated (the PC version): the mouse moves the crosshair and steers (desktop only).</summary>
        public static bool MouseSteering { get => GetBool("mouseSteering", true); set => SetBool("mouseSteering", value); }
        /// <summary>options[0x11] = 0: the accelerometer steers (MGame::handleAccelerometer).</summary>
        public static bool TiltSteering { get => GetBool("tiltSteering", false); set => SetBool("tiltSteering", value); }
        /// <summary>options+0x18: the tilt sensitivity, 0..1 (default 1, the maximum).</summary>
        public static float TiltSensitivity { get => Get("tiltSensitivity", 1f); set => Set("tiltSensitivity", Mathf.Clamp01(value)); }
        /// <summary>options+0x1c / +0x20: the calibrated position (Globals::init 0.6 / 0.6).</summary>
        public static float TiltCalX { get => Get("tiltCalX", 0.6f); set => Set("tiltCalX", value); }
        public static float TiltCalZ { get => Get("tiltCalZ", 0.6f); set => Set("tiltCalZ", value); }
        public static bool TiltCalibrated { get => GetBool("tiltCalibrated", false); set => SetBool("tiltCalibrated", value); }

        /// <summary>Controller stick dead zone (InputSettings.defaultDeadzoneMin).</summary>
        public static float StickDeadzone { get => Get("stickDeadzone", DefaultDeadzone); set => Set("stickDeadzone", Mathf.Clamp(value, 0.05f, 0.4f)); }

        // ---- gameplay ----------------------------------------------------------------------------------------

        /// <summary>The launch / arrival camera (LevelScript's start sequence); off = straight to the chase camera.</summary>
        public static bool LaunchCamera { get => GetBool("launchCamera", true); set => SetBool("launchCamera", value); }

        /// <summary>Remake: the ship flies into the hangar after docking and out of it when launching (HangarFlight).</summary>
        public static bool HangarFlights { get => GetBool("hangarFlights", true); set => SetBool("hangarFlights", value); }

        /// <summary>DialogueWindow::update: with voice, turn the page once the line has ended.</summary>
        public static bool AutoAdvanceDialogue { get => GetBool("autoAdvanceDialogue", true); set => SetBool("autoAdvanceDialogue", value); }

        /// <summary>The keyboard / controller hint rows of the HUDs (the touch controls always show).</summary>
        public static bool InputHints { get => GetBool("inputHints", true); set => SetBool("inputHints", value); }

        /// <summary>Language code of Localization/text_{code}.json.</summary>
        public static string Language
        {
            get => PlayerPrefs.GetString(Prefix + "language", "en");
            set { PlayerPrefs.SetString(Prefix + "language", value); PlayerPrefs.Save(); Changed?.Invoke(); }
        }

        /// <summary>"Default settings" (497): every option back to its default, the language kept.</summary>
        public static void ResetToDefaults()
        {
            foreach (var key in new[]
                     {
                         "masterVolume", "musicVolume", "sfxVolume", "voiceVolume", "displayMode", "resolutionWidth", "resolutionHeight",
                         "frameRate", "renderScale", "upscaler", "msaa", "quality", "brightness", "bloom", "lensFlare", "fov", "cameraShake",
                         "sensitivity", "invertPitch", "stickDeadzone", "launchCamera", "autoAdvanceDialogue", "inputHints",
                     })
                PlayerPrefs.DeleteKey(Prefix + key);
            PlayerPrefs.Save();
            cache.Clear();
            Changed?.Invoke();
        }

        // PlayerPrefs reads go through a cache: game code reads some options every frame.
        static readonly Dictionary<string, float> cache = new Dictionary<string, float>();

        static float Get(string key, float fallback)
        {
            if (cache.TryGetValue(key, out var v)) return v;
            v = PlayerPrefs.GetFloat(Prefix + key, fallback);
            cache[key] = v;
            return v;
        }

        static bool GetBool(string key, bool fallback) => Get(key, fallback ? 1f : 0f) > 0.5f;
        static void SetBool(string key, bool value) => Set(key, value ? 1f : 0f);

        static void SetQuiet(string key, float value)
        {
            PlayerPrefs.SetFloat(Prefix + key, value);
            cache[key] = value;
        }

        static void Set(string key, float value, bool force = false)
        {
            if (!force && Mathf.Approximately(PlayerPrefs.GetFloat(Prefix + key, float.NaN), value)) return;
            SetQuiet(key, value);
            PlayerPrefs.Save();
            Changed?.Invoke();
        }
    }
}
