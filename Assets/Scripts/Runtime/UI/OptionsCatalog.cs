// OptionsCatalog.cs
// Every player option as data (label, kind, range, get / set on Settings), in the order the menus show them. The main
// menu's Options panel (one tab per page) and the in-flight pause menu build their rows from it (OptionControl).
// Original options (Reference/research/mainmenu_notes.md 2.3 / 2.6): Music 34, FX 35, Voice 36, Brightness 503
// (513-515), Quality 504 (507-509, descriptions 510-512), Sensitivity 499, Invert controls 500, Default settings 497.
// The rest are remake options (Localization.Extra texts). Not here: touch / accelerometer steering and its
// calibration (490-494; tilt isn't built), the text language (the Language tab's buttons, with the voice language row under them).

using System;
using System.Collections.Generic;
using System.Linq;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.UI
{
    public enum OptionPage { Sound, Graphics, Controls, Gameplay, Language }
    public enum OptionKind { Slider, Toggle, Choice, Button, Binding }

    public sealed class OptionDef
    {
        public string id;
        public OptionPage page;
        public OptionKind kind;
        public Func<string> label;
        public Func<string> description;   // optional line under the row
        public Func<UnityEngine.UIElements.VisualElement> extra;   // optional element under the row (not focusable)

        // Slider
        public float min, max;
        public Func<float> get;
        public Action<float> set;
        public Func<float, string> format;

        // Toggle
        public Func<bool> getBool;
        public Action<bool> setBool;

        // Choice
        public Func<string[]> choices;
        public Func<int> getIndex;
        public Action<int> setIndex;
        public bool segmented;

        // Button
        public Action action;

        // Binding (a key bindings row, BindingRow)
        public Flight.ControlRow control;
    }

    public static class OptionsCatalog
    {
        static string X(string key, string english) => Localization.Extra(key, english);
        static string Percent(float v) => $"{Mathf.RoundToInt(v * 100f)} %";

        public static string PageTitle(OptionPage page) => page switch
        {
            OptionPage.Sound => X("tabSound", "Sound"),
            OptionPage.Graphics => Localization.Get(502),
            OptionPage.Controls => Localization.Get(498),
            OptionPage.Language => Localization.Get(0),
            _ => X("tabGameplay", "Gameplay"),
        };

        static readonly string[] VoiceCodes = { "auto", "en", "de" };
        static readonly float[] RenderScales = { 0.5f, 0.67f, 0.75f, 0.8f, 0.9f, 1f, 1.25f, 1.5f, 2f };
        static readonly int[] MsaaSamples = { 1, 2, 4, 8 };

        /// <summary>The options of this platform, page by page.</summary>
        public static List<OptionDef> All()
        {
            var list = new List<OptionDef>
            {
                // ---- sound
                Slider("master", OptionPage.Sound, () => X("masterVolume", "Master"), 0f, 1f, () => Settings.MasterVolume, v => Settings.MasterVolume = v, Percent),
                Slider("music", OptionPage.Sound, () => Localization.Get(34), 0f, 1f, () => Settings.MusicVolume, v => Settings.MusicVolume = v, Percent),
                Slider("sfx", OptionPage.Sound, () => Localization.Get(35), 0f, 1f, () => Settings.SfxVolume, v => Settings.SfxVolume = v, Percent),
                Slider("voice", OptionPage.Sound, () => Localization.Get(36), 0f, 1f, () => Settings.VoiceVolume, v => Settings.VoiceVolume = v, Percent),
                // Remake: the voices apart from the text language (only English and German were recorded); on the Language tab.
                Choice("voiceLanguage", OptionPage.Language, () => X("voiceLanguage", "Voice language"), true,
                    () => new[] { X("voiceAuto", "As text"), "English", "Deutsch" },
                    () => Array.IndexOf(VoiceCodes, Settings.VoiceLanguage) is var i && i >= 0 ? i : 0,
                    i => Settings.VoiceLanguage = VoiceCodes[i]),
            };

            // ---- graphics
            if (Bootstrap.HasDisplayOptions)
            {
                list.Add(Choice("displayMode", OptionPage.Graphics, () => X("displayMode", "Display mode"), true,
                    () => new[] { X("borderless", "Borderless"), X("fullscreen", "Fullscreen"), X("windowed", "Windowed") },
                    () => (int)Settings.DisplayMode, i => Settings.DisplayMode = (DisplayMode)i));
                var sizes = Bootstrap.Resolutions();
                list.Add(Choice("resolution", OptionPage.Graphics, () => X("resolution", "Resolution"), false,
                    () => sizes.Select(r => $"{r.x} × {r.y}").Prepend(X("resolutionNative", "Display's own")).ToArray(),
                    () => { int i = sizes.IndexOf(Settings.Resolution); return i < 0 ? 0 : i + 1; },
                    i => Settings.Resolution = i <= 0 ? Vector2Int.zero : sizes[i - 1]));
            }
            list.Add(Choice("frameRate", OptionPage.Graphics, () => X("frameRate", "Frame rate"), true,
                () => new[] { "30", "60", "120", X("fpsUncapped", "UNCAPPED"), X("fpsVSync", "V-SYNC") },
                () => (int)Settings.FrameRate, i => Settings.FrameRate = (FrameRate)i));
            list.Add(Choice("quality", OptionPage.Graphics, () => Localization.Get(504), true,
                () => new[] { Localization.Get(507), Localization.Get(508), Localization.Get(509) },
                () => Settings.Quality, i => Settings.Quality = i,
                () => QualityDescription(Settings.Quality)));
            list.Add(Choice("renderScale", OptionPage.Graphics, () => X("renderScale", "Render scale"), false,
                () => RenderScales.Select(Percent).ToArray(),
                () => Nearest(RenderScales, Settings.RenderScale > 0f ? Settings.RenderScale : Bootstrap.DefaultRenderScale),
                i => Settings.RenderScale = RenderScales[i]));
            // Only the upscalers this device runs (Android: FSR 1 needs GLES 3.1 / Vulkan, STP Vulkan).
            var upscalers = new List<int> { Settings.UpscalerOff };
            if (Bootstrap.FsrSupported) upscalers.Add(Settings.UpscalerFsr);
            if (Bootstrap.StpSupported) upscalers.Add(Settings.UpscalerStp);
            if (upscalers.Count > 1)
                list.Add(Choice("upscaler", OptionPage.Graphics, () => X("upscaler", "Upscaler"), true,
                    () => upscalers.Select(u => u == Settings.UpscalerFsr ? "FSR 1" : u == Settings.UpscalerStp ? "STP" : X("off", "Off")).ToArray(),
                    () => Math.Max(0, upscalers.IndexOf(Bootstrap.ActiveUpscaler)),
                    i => Settings.Upscaler = upscalers[i],
                    () => Bootstrap.ActiveUpscaler switch
                    {
                        Settings.UpscalerFsr => X("upscalerFsr", "AMD FidelityFX Super Resolution 1: sharp upscaling from the render scale"),
                        Settings.UpscalerStp => X("upscalerStp", "Unity Spatial-Temporal Post-processing: temporal anti-aliasing and upscaling, replaces MSAA"),
                        _ => X("upscalerOff", "Plain scaling from the render scale"),
                    }));
            // MSAA with STP on: STP's temporal anti-aliasing takes its place (shown as off); picking MSAA turns STP off.
            list.Add(Choice("msaa", OptionPage.Graphics, () => X("antiAliasing", "Anti-aliasing"), true,
                () => new[] { X("off", "Off"), "MSAA 2×", "MSAA 4×", "MSAA 8×" },
                () => Bootstrap.ActiveUpscaler == Settings.UpscalerStp ? 0
                    : Math.Max(0, Array.IndexOf(MsaaSamples, Settings.Msaa > 0 ? Settings.Msaa : Bootstrap.DefaultMsaa)),
                i =>
                {
                    if (i > 0 && Bootstrap.ActiveUpscaler == Settings.UpscalerStp) Settings.Upscaler = Settings.UpscalerOff;
                    Settings.Msaa = MsaaSamples[i];
                }));
            list.Add(Choice("brightness", OptionPage.Graphics, () => Localization.Get(503), true,
                () => new[] { Localization.Get(513), Localization.Get(514), Localization.Get(515) },
                () => Settings.Brightness, i => Settings.Brightness = i));
            // Remake: the remake's bloom (the HDR glow of lights and effects) or the original's (every bright pixel, ClassicBloomPass).
            list.Add(Choice("bloom", OptionPage.Graphics, () => X("bloom", "Bloom"), true,
                () => new[] { X("off", "Off"), X("bloomRemake", "Remake"), X("bloomOriginal", "Original") },
                () => Mathf.Clamp(Settings.BloomStyle, 0, 2), i => Settings.BloomStyle = i));
            list.Add(Toggle("lensFlare", OptionPage.Graphics, () => X("lensFlare", "Lens flare"), () => Settings.LensFlare, v => Settings.LensFlare = v));
            list.Add(Slider("fov", OptionPage.Graphics, () => X("fov", "Field of view"), 55f, 95f,
                () => Settings.FieldOfView, v => Settings.FieldOfView = Mathf.Round(v), v => $"{Mathf.RoundToInt(v)}°"));
            list.Add(Slider("cameraShake", OptionPage.Graphics, () => X("cameraShake", "Camera shake"), 0f, 1f,
                () => Settings.CameraShake, v => Settings.CameraShake = v, Percent));

            // ---- controls
            // MenuTouchWindow state 8: 490 Touch / 491 Accelerometer pictures (options[0x11]), 492 Steering Calibration
            // (493, then OK stores the device's position), the sensitivity slider per mode (+0x14 / +0x18).
            if (Flight.TiltSteering.Available)
            {
                list.Add(Choice("steering", OptionPage.Controls, () => X("steering", "Steering"), true,
                    () => new[] { Localization.Get(490), Localization.Get(491) },
                    () => Settings.TiltSteering ? 1 : 0, i =>
                    {
                        bool tilt = i == 1;
                        if (tilt && !Settings.TiltCalibrated) Flight.TiltSteering.Calibrate();   // remake: calibrate on first use
                        Settings.TiltSteering = tilt;
                    }));
                list.Add(new OptionDef
                {
                    id = "calibrate", page = OptionPage.Controls, kind = OptionKind.Button, label = () => Localization.Get(492),
                    description = () => Localization.Get(493), action = Flight.TiltSteering.Calibrate,
                });
                list.Add(Slider("tiltSensitivity", OptionPage.Controls, () => Localization.Get(499) + " (" + Localization.Get(491) + ")", 0f, 1f,
                    () => Settings.TiltSensitivity, v => Settings.TiltSensitivity = v, v => Mathf.RoundToInt(v * 100f).ToString()));
            }
            list.Add(Slider("sensitivity", OptionPage.Controls, () => Localization.Get(499), 0.2f, 2.2f,
                () => Settings.Sensitivity, v => Settings.Sensitivity = v, v => v.ToString("0.0")));
            // options[0x10] "Invert controls" (500), split per axis; the mining drill has its own pair.
            list.Add(Toggle("invert", OptionPage.Controls, () => X("invertY", "Invert up / down"), () => Settings.InvertPitch, v => Settings.InvertPitch = v));
            list.Add(Toggle("invertYaw", OptionPage.Controls, () => X("invertX", "Invert left / right"), () => Settings.InvertYaw, v => Settings.InvertYaw = v));
            list.Add(Toggle("invertDrillY", OptionPage.Controls, () => X("invertDrillY", "Mining drill: invert up / down"), () => Settings.InvertDrillY, v => Settings.InvertDrillY = v));
            list.Add(Toggle("invertDrillX", OptionPage.Controls, () => X("invertDrillX", "Mining drill: invert left / right"), () => Settings.InvertDrillX, v => Settings.InvertDrillX = v));
            if (!Application.isMobilePlatform)
                list.Add(Toggle("mouseSteering", OptionPage.Controls, () => X("mouseSteering", "Mouse steering"), () => Settings.MouseSteering, v => Settings.MouseSteering = v));
            list.Add(Slider("deadzone", OptionPage.Controls, () => X("deadzone", "Stick dead zone"), 0.05f, 0.4f,
                () => Settings.StickDeadzone, v => Settings.StickDeadzone = v, Percent));
            // Remake: every flight control rebindable (GameControls): two keyboard / mouse keys and a controller button each.
            list.Add(new OptionDef
            {
                id = "resetBindings", page = OptionPage.Controls, kind = OptionKind.Button,
                label = () => X("resetBindings", "Reset key bindings"),
                description = () => X("bindingsHelp", "Keys, second keys and controller buttons: pick one to change it. Esc cancels, Backspace clears. The menu keys stay fixed."),
                action = Flight.GameControls.ResetToDefaults,
                extra = BindingRow.Header,
            });
            foreach (var row in Flight.GameControls.Rows)
                list.Add(new OptionDef { id = "bind_" + row.id, page = OptionPage.Controls, kind = OptionKind.Binding, label = row.label, control = row });

            // ---- gameplay
            list.Add(Toggle("launchCamera", OptionPage.Gameplay, () => X("launchCamera", "Launch and arrival camera"),
                () => Settings.LaunchCamera, v => Settings.LaunchCamera = v));
            list.Add(Toggle("hangarFlights", OptionPage.Gameplay, () => X("hangarFlights", "Hangar arrival and take-off"),
                () => Settings.HangarFlights, v => Settings.HangarFlights = v));
            list.Add(Toggle("autoAdvance", OptionPage.Gameplay, () => X("autoAdvance", "Turn voiced dialogue pages automatically"),
                () => Settings.AutoAdvanceDialogue, v => Settings.AutoAdvanceDialogue = v));
            list.Add(Toggle("animatedDialogue", OptionPage.Gameplay, () => X("animatedDialogue", "Animated dialogue"),
                () => Settings.AnimatedDialogue, v => Settings.AnimatedDialogue = v));
            list.Add(Toggle("inputHints", OptionPage.Gameplay, () => X("inputHintsFlight", "Button hints in flight"),
                () => Settings.InputHints, v => Settings.InputHints = v));
            // Remake: the testing tools (Cheats.Unlocked), also opened by F10, LB + RB or three fingers on the main menu.
            var debug = Toggle("debugTools", OptionPage.Gameplay, () => X("debugTools", "Debug tools"), () => Cheats.Unlocked, v => Cheats.Unlocked = v);
            debug.description = () => X("debugToolsHelp", "A Debug button in the main menu (the mission select) and a Debug page in the pause and station menus (cheats, items, spawns).");
            list.Add(debug);
            return list;
        }

        /// <summary>510-512 "Low quality:\n- Smoke off\n- Fog off\n- Detail low" as one line: "Smoke off · Fog off · Detail low".</summary>
        static string QualityDescription(int quality)
        {
            var lines = Localization.Get(510 + quality).Replace("\r", "").Split('\n').Skip(1)
                .Select(l => l.TrimStart('-', ' ').Trim()).Where(l => l.Length > 0);
            return string.Join("  ·  ", lines);
        }

        static int Nearest(float[] values, float v)
        {
            int best = 0;
            for (int i = 1; i < values.Length; i++) if (Mathf.Abs(values[i] - v) < Mathf.Abs(values[best] - v)) best = i;
            return best;
        }

        static OptionDef Slider(string id, OptionPage page, Func<string> label, float min, float max, Func<float> get, Action<float> set,
                                Func<float, string> format) =>
            new OptionDef { id = id, page = page, kind = OptionKind.Slider, label = label, min = min, max = max, get = get, set = set, format = format };

        static OptionDef Toggle(string id, OptionPage page, Func<string> label, Func<bool> get, Action<bool> set) =>
            new OptionDef { id = id, page = page, kind = OptionKind.Toggle, label = label, getBool = get, setBool = set };

        static OptionDef Choice(string id, OptionPage page, Func<string> label, bool segmented, Func<string[]> choices, Func<int> get,
                                Action<int> set, Func<string> description = null) =>
            new OptionDef
            {
                id = id, page = page, kind = OptionKind.Choice, label = label, segmented = segmented, choices = choices, getIndex = get,
                setIndex = set, description = description,
            };
    }
}
