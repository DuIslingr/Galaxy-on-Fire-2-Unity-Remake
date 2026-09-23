// GoF2MainMenu.cs
// Main menu controller (UI Toolkit). Follows the original flow (MTitle -> ModMainMenu -> MenuTouchWindow(0)):
//   1. Splash: FISHLABS then ABYSS ENGINE logo, 1 s fade in / 2 s hold / 1 s fade out each, skippable.
//   2. Title: the GoF2 logo fades in over the live 3D scene (3.9 s), "press any key" pulses under it.
//   3. Menu: Resume (only with a save), Start new game -> Select Campaign -> difficulty (Normal / Extreme),
//      Load game (save slots, slot 0 = Auto-save), Options (Sound & Graphics, Controls, Language), About, Exit.
// Text comes from the original table (GoF2Localization, text IDs in comments). Sounds: Button_Push on focus
// changes, Button_Release on confirm, Message_Info_Screen for dialogs (FMOD events 124 / 123 / 126).
// Modern additions: keyboard/gamepad navigation, animated transitions, bloom/brightness options.

using System;
using System.Collections;
using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Utilities;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;
using UnityEngine.SceneManagement;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    [RequireComponent(typeof(UIDocument))]
    public class GoF2MainMenu : MonoBehaviour
    {
        [Header("Flow")]
        public bool showSplash = true;
        [Tooltip("Scene loaded by Start new game (until the campaign exists).")]
        public string gameScene = "FlightTest";
        public string versionText = "Galaxy on Fire 2 Remake  ·  pre-alpha";

        [Header("Splash logos (MTitle images 7001, 7000)")]
        public Texture2D fishlabsLogo;
        public Texture2D abyssLogo;

        [Header("Audio")]
        public AudioSource musicSource;
        public AudioSource sfxSource;
        public AudioClip menuMusic;      // event 145 Space_NoCombat_Void
        public AudioClip buttonPush;     // event 124
        public AudioClip buttonRelease;  // event 123
        public AudioClip infoSound;      // event 126

        [Header("Localization (text_<code>.json)")]
        public string[] languageCodes = { "en" };
        public string[] languageNames = { "English" };
        public TextAsset[] languageTables;

        [Header("Post-processing")]
        public Volume postVolume;

        enum MenuState { Splash, Title, Menu, Leaving }

        VisualElement root, logo, splash, splashLogo, fade, dialog, mainColumn, mainButtons;
        Label pressAnyKey, versionLabel, hintLabel;
        Button resumeButton, newGameButton, loadButton, optionsButton, aboutButton, exitButton;
        readonly Dictionary<string, VisualElement> panels = new Dictionary<string, VisualElement>();
        VisualElement openPanel;
        Action dialogYes;
        MenuState screen = MenuState.Splash;
        bool skipRequested;
        GoF2Campaign pendingCampaign;
        IVisualElementScheduledItem pulse;
        Bloom bloom;
        ColorAdjustments colorAdjustments;
        IDisposable anyKey;
        PanelSettings runtimePanel;
        VisualElement safeArea;
        Vector2Int lastScreen;
        Rect lastSafeArea;

        // ---- setup ----------------------------------------------------------------------------

        void OnEnable()
        {
            // Per-instance panel settings: scaling is adapted to the screen shape (see UpdateLayout).
            var doc = GetComponent<UIDocument>();
            if (runtimePanel == null && doc.panelSettings != null)
            {
                runtimePanel = Instantiate(doc.panelSettings);
                doc.panelSettings = runtimePanel;
            }
            root = doc.rootVisualElement;
            root.style.flexGrow = 1;   // the default theme would stretch the document root; ours is custom
            safeArea = root.Q("safeArea");
            LoadLanguage(GoF2Settings.Language);

            logo = root.Q("logo");
            splash = root.Q("splash");
            splashLogo = root.Q("splashLogo");
            fade = root.Q("fade");
            dialog = root.Q("dialog");
            mainColumn = root.Q("mainColumn");
            mainButtons = root.Q("mainButtons");
            pressAnyKey = root.Q<Label>("pressAnyKey");
            versionLabel = root.Q<Label>("versionLabel");
            hintLabel = root.Q<Label>("hintLabel");

            resumeButton = Bind("resumeButton", () => { });           // needs the save system
            newGameButton = Bind("newGameButton", () => OpenPanel("campaignPanel"));
            loadButton = Bind("loadButton", () => { BuildSlots(); OpenPanel("loadPanel"); });
            optionsButton = Bind("optionsButton", () => { OpenPanel("optionsPanel"); SelectTab("soundPage"); });
            aboutButton = Bind("aboutButton", () => OpenPanel("aboutPanel"));
            exitButton = Bind("exitButton", () => ShowDialog(GoF2Localization.Get(390), GoF2Localization.Get(53), Quit));
            resumeButton.AddToClassList("menu-button--gone");        // original: only shown when a save exists

            foreach (var n in new[] { "campaignPanel", "difficultyPanel", "loadPanel", "optionsPanel", "aboutPanel" })
                panels[n] = root.Q(n);
            foreach (var n in new[] { "campaignBack", "difficultyBack", "loadBack", "optionsBack", "aboutBack" })
            {
                var b = root.Q<Button>(n);
                b.clicked += Back;   // Back() plays the release sound itself (also used by Esc)
                HookFocusSound(b);
            }

            Bind("cardGof2", () => PickCampaign(GoF2Campaign.GalaxyOnFire2));
            Bind("cardValkyrie", () => PickCampaign(GoF2Campaign.Valkyrie));
            Bind("cardSupernova", () => PickCampaign(GoF2Campaign.Supernova));
            Bind("normalButton", () => StartGame(GoF2Session.DifficultyNormal));
            Bind("extremeButton", () => ShowDialog(GoF2Localization.Get(25), GoF2Localization.Get(26),
                () => StartGame(GoF2Session.DifficultyExtreme)));
            Bind("dialogYes", () => { var a = dialogYes; CloseDialog(); a?.Invoke(); });
            Bind("dialogNo", CloseDialog);

            Bind("tabSound", () => SelectTab("soundPage"));
            Bind("tabControls", () => SelectTab("controlsPage"));
            Bind("tabLanguage", () => SelectTab("languagePage"));
            SetupOptions();

            root.RegisterCallback<NavigationCancelEvent>(_ => Back(), TrickleDown.TrickleDown);
            root.RegisterCallback<NavigationMoveEvent>(OnNavigate, TrickleDown.TrickleDown);
            root.RegisterCallback<FocusInEvent>(e => { if (e.target is VisualElement v) EnsureVisible(v); });

            if (postVolume != null && postVolume.profile != null)
            {
                postVolume.profile.TryGet(out bloom);
                postVolume.profile.TryGet(out colorAdjustments);
            }
            ApplySettings();
            GoF2Settings.Changed += ApplySettings;

            RefreshTexts();
            foreach (var b in mainButtons.Query<Button>().ToList()) b.AddToClassList("menu-button--hidden");
            lastScreen = Vector2Int.zero;
            UpdateLayout();
            StartCoroutine(Run());
        }

        [Tooltip("Force the phone layout (for testing in the editor).")]
        public bool simulatePhone;

        /// <summary>Size the panel renders at: the screen, or its target texture when rendering off-screen.</summary>
        Vector2Int ScreenSize()
        {
            var rt = runtimePanel != null ? runtimePanel.targetTexture : null;
            return rt != null ? new Vector2Int(rt.width, rt.height) : new Vector2Int(Screen.width, Screen.height);
        }

        void Update()
        {
            if (lastScreen != ScreenSize() || lastSafeArea != Screen.safeArea) UpdateLayout();
        }

        // ---- aspect ratios ---------------------------------------------------------------------

        /// <summary>
        /// Landscape only. The UI scales to the screen height (1080 units) so text keeps its size whatever the
        /// aspect ratio; widths then vary from 4:3 to 32:9 and the USS layout classes adapt. Phones get a smaller
        /// reference resolution (bigger UI) and the device safe area (notch, corners).
        /// </summary>
        void UpdateLayout()
        {
            lastScreen = ScreenSize();
            lastSafeArea = Screen.safeArea;
            bool offscreen = runtimePanel != null && runtimePanel.targetTexture != null;
            float w = Mathf.Max(1, lastScreen.x), h = Mathf.Max(1, lastScreen.y), aspect = w / h;
            float inches = Screen.dpi > 0f ? Mathf.Sqrt(w * w + h * h) / Screen.dpi : 20f;
            bool phone = simulatePhone || Application.isMobilePlatform && inches < 7.5f;

            if (runtimePanel != null)
            {
                runtimePanel.referenceResolution = phone ? new Vector2Int(1600, 900) : new Vector2Int(1920, 1080);
                runtimePanel.screenMatchMode = PanelScreenMatchMode.MatchWidthOrHeight;
                runtimePanel.match = 1f;
            }
            root.EnableInClassList("layout-narrow", aspect < 1.55f);
            root.EnableInClassList("layout-ultrawide", aspect > 2.3f);
            root.EnableInClassList("layout-phone", phone);

            // Safe area insets (pixels -> panel units), applied once the panel has its new size.
            root.schedule.Execute(() =>
            {
                if (safeArea == null || root.layout.width <= 0f) return;
                float k = root.layout.width / w;
                var sa = offscreen ? new Rect(0f, 0f, w, h) : Screen.safeArea;
                safeArea.style.paddingLeft = sa.xMin * k;
                safeArea.style.paddingRight = (w - sa.xMax) * k;
                safeArea.style.paddingTop = (h - sa.yMax) * k;
                safeArea.style.paddingBottom = sa.yMin * k;
            });
        }

        void OnDisable()
        {
            GoF2Settings.Changed -= ApplySettings;
            anyKey?.Dispose();
        }

        Button Bind(string name, Action onClick)
        {
            var b = root.Q<Button>(name);
            if (b == null) { Debug.LogWarning($"GoF2MainMenu: button '{name}' missing"); return null; }
            b.clicked += () => { Play(buttonRelease); onClick(); };
            HookFocusSound(b);
            return b;
        }

        void HookFocusSound(VisualElement e)
        {
            e.RegisterCallback<PointerEnterEvent>(_ => { if (e.enabledInHierarchy && e.focusable) e.Focus(); });
            e.RegisterCallback<FocusInEvent>(_ => { if (screen == MenuState.Menu) Play(buttonPush, 0.45f); });
        }

        // ---- flow ------------------------------------------------------------------------------

        IEnumerator Run()
        {
            if (musicSource != null && menuMusic != null)
            {
                musicSource.clip = menuMusic;
                musicSource.loop = true;
                musicSource.volume = 0f;
                musicSource.Play();      // MTitle starts the menu theme with the first logo
            }
            StartCoroutine(FadeMusic(GoF2Settings.MusicVolume, 3f));

            WatchAnyKey();
            if (showSplash)
            {
                foreach (var tex in new[] { fishlabsLogo, abyssLogo })
                {
                    if (tex == null) continue;
                    skipRequested = false;
                    splashLogo.style.backgroundImage = new StyleBackground(tex);
                    splashLogo.AddToClassList("splash-logo--visible");
                    yield return Wait(3f);                        // 1 s fade in + 2 s hold
                    splashLogo.RemoveFromClassList("splash-logo--visible");
                    yield return Wait(1f);                        // 1 s fade out
                }
            }
            splash.AddToClassList("splash--gone");
            screen = MenuState.Title;
            yield return new WaitForSeconds(0.2f);
            logo.AddToClassList("logo--title-visible");
            yield return new WaitForSeconds(showSplash ? 1.5f : 0.3f);
            splash.AddToClassList("splash--removed");
            pulse = pressAnyKey.schedule.Execute(() => pressAnyKey.ToggleInClassList("press-any-key--on")).Every(1050);
            skipRequested = false;
            while (!skipRequested) yield return null;
            EnterMenu();
        }

        IEnumerator Wait(float seconds)
        {
            for (float t = 0f; t < seconds && !skipRequested; t += Time.unscaledDeltaTime) yield return null;
        }

        void WatchAnyKey()
        {
            anyKey?.Dispose();
            anyKey = InputSystem.onAnyButtonPress.Call(_ => { if (screen == MenuState.Splash || screen == MenuState.Title) skipRequested = true; });
        }

        void EnterMenu()
        {
            screen = MenuState.Menu;
            anyKey?.Dispose();
            pulse?.Pause();
            pressAnyKey.AddToClassList("press-any-key--hidden");
            logo.RemoveFromClassList("logo--title");
            logo.RemoveFromClassList("logo--title-visible");
            logo.AddToClassList("logo--menu");
            root.AddToClassList("menu-root--menu");
            mainButtons.AddToClassList("main-buttons--revealing");
            root.schedule.Execute(() =>
            {
                foreach (var b in mainButtons.Query<Button>().ToList()) b.RemoveFromClassList("menu-button--hidden");
                FocusFirst(mainButtons);
            }).ExecuteLater(350);
            root.schedule.Execute(() => mainButtons.RemoveFromClassList("main-buttons--revealing")).ExecuteLater(1200);
        }

        // ---- panels ----------------------------------------------------------------------------

        void OpenPanel(string name)
        {
            if (openPanel != null) HidePanel(openPanel);
            var p = panels[name];
            openPanel = p;
            p.AddToClassList("panel--shown");
            p.schedule.Execute(() => p.AddToClassList("panel--visible")).ExecuteLater(16);
            mainColumn.AddToClassList("main-column--dimmed");
            SetFocusable(mainButtons, false);
            p.schedule.Execute(() => FocusFirst(p)).ExecuteLater(30);
        }

        void HidePanel(VisualElement p)
        {
            p.RemoveFromClassList("panel--visible");
            p.RemoveFromClassList("panel--shown");
        }

        void Back()
        {
            if (screen != MenuState.Menu) return;
            if (dialog.ClassListContains("dialog-backdrop--shown")) { CloseDialog(); return; }
            if (openPanel == null) return;
            Play(buttonRelease);
            if (openPanel == panels["difficultyPanel"]) { OpenPanel("campaignPanel"); return; }
            var closing = openPanel;
            HidePanel(closing);
            openPanel = null;
            mainColumn.RemoveFromClassList("main-column--dimmed");
            SetFocusable(mainButtons, true);
            var target = closing == panels["campaignPanel"] ? newGameButton
                : closing == panels["loadPanel"] ? loadButton
                : closing == panels["optionsPanel"] ? optionsButton : aboutButton;
            target?.Focus();
        }

        void PickCampaign(GoF2Campaign c)
        {
            pendingCampaign = c;
            OpenPanel("difficultyPanel");
        }

        void StartGame(float difficulty)
        {
            GoF2Session.Campaign = pendingCampaign;
            GoF2Session.Difficulty = difficulty;
            StartCoroutine(Leave());
        }

        IEnumerator Leave()
        {
            screen = MenuState.Leaving;
            fade.AddToClassList("fade--on");
            StartCoroutine(FadeMusic(0f, 1.2f));
            yield return new WaitForSeconds(1.3f);
            if (Application.CanStreamedLevelBeLoaded(gameScene)) SceneManager.LoadScene(gameScene);
            else
            {
                Debug.LogWarning($"GoF2MainMenu: scene '{gameScene}' is not in the build settings.");
                fade.RemoveFromClassList("fade--on");
                screen = MenuState.Menu;
                StartCoroutine(FadeMusic(GoF2Settings.MusicVolume, 1f));
            }
        }

        void Quit()
        {
#if UNITY_EDITOR
            UnityEditor.EditorApplication.isPlaying = false;
#else
            Application.Quit();
#endif
        }

        // ---- dialog ----------------------------------------------------------------------------

        void ShowDialog(string title, string text, Action onYes)
        {
            dialogYes = onYes;
            root.Q<Label>("dialogTitle").text = title.ToUpperInvariant();
            root.Q<Label>("dialogText").text = text;
            dialog.AddToClassList("dialog-backdrop--shown");
            Play(infoSound);
            root.Q<Button>("dialogNo").Focus();
        }

        void CloseDialog()
        {
            dialog.RemoveFromClassList("dialog-backdrop--shown");
            dialogYes = null;
            if (openPanel != null) FocusFirst(openPanel); else exitButton?.Focus();
        }

        // ---- save slots (RecordHandler: 12 slots, slot 0 = Auto-save; no save system yet) --------

        void BuildSlots()
        {
            var list = root.Q<ScrollView>("slotList");
            list.Clear();
            for (int i = 0; i < 12; i++)
            {
                var row = new Button { focusable = true };
                row.AddToClassList("slot-row");
                var name = new Label(i == 0 ? GoF2Localization.Get(486) : $"{GoF2Localization.Extra("slot", "Slot")} {i}");
                name.AddToClassList("slot-name");
                var state = new Label(GoF2Localization.Get(174));   // -BLANK-
                state.AddToClassList("slot-state");
                row.Add(name);
                row.Add(state);
                row.clicked += () => Play(buttonPush);
                HookFocusSound(row);
                list.Add(row);
            }
        }

        // ---- options ---------------------------------------------------------------------------

        void SetupOptions()
        {
            var music = root.Q<Slider>("musicSlider");
            music.value = GoF2Settings.MusicVolume;
            music.RegisterValueChangedCallback(e => GoF2Settings.MusicVolume = e.newValue);
            var fx = root.Q<Slider>("fxSlider");
            fx.value = GoF2Settings.SfxVolume;
            fx.RegisterValueChangedCallback(e => GoF2Settings.SfxVolume = e.newValue);
            fx.RegisterCallback<PointerCaptureOutEvent>(_ => Play(infoSound));   // original: FX preview on release
            var voice = root.Q<Slider>("voiceSlider");
            voice.value = GoF2Settings.VoiceVolume;
            voice.RegisterValueChangedCallback(e => GoF2Settings.VoiceVolume = e.newValue);
            var brightness = root.Q<SliderInt>("brightnessSlider");
            brightness.value = GoF2Settings.Brightness;
            brightness.RegisterValueChangedCallback(e => { GoF2Settings.Brightness = e.newValue; RefreshTexts(); });
            var bloomToggle = root.Q<Toggle>("bloomToggle");
            bloomToggle.value = GoF2Settings.Bloom;
            bloomToggle.RegisterValueChangedCallback(e => GoF2Settings.Bloom = e.newValue);
            var sens = root.Q<Slider>("sensitivitySlider");
            sens.value = GoF2Settings.Sensitivity;
            sens.RegisterValueChangedCallback(e => { GoF2Settings.Sensitivity = e.newValue; RefreshTexts(); });
            var invert = root.Q<Toggle>("invertToggle");
            invert.value = GoF2Settings.InvertPitch;
            invert.RegisterValueChangedCallback(e => GoF2Settings.InvertPitch = e.newValue);
            foreach (var e in new VisualElement[] { music, fx, voice, brightness, bloomToggle, sens, invert }) HookFocusSound(e);

            var langList = root.Q("languageList");
            for (int i = 0; i < languageCodes.Length && i < languageNames.Length; i++)
            {
                string code = languageCodes[i];
                var b = new Button { text = languageNames[i], name = "lang_" + code };
                b.AddToClassList("menu-button");
                b.AddToClassList("language-button");
                b.clicked += () => { Play(buttonRelease); GoF2Settings.Language = code; LoadLanguage(code); RefreshTexts(); };
                HookFocusSound(b);
                langList.Add(b);
            }
        }

        void SelectTab(string page)
        {
            foreach (var (tab, p) in new[] { ("tabSound", "soundPage"), ("tabControls", "controlsPage"), ("tabLanguage", "languagePage") })
            {
                root.Q(tab).EnableInClassList("tab-button--active", p == page);
                root.Q(p).EnableInClassList("tab-page--active", p == page);
            }
        }

        void ApplySettings()
        {
            if (musicSource != null && screen != MenuState.Leaving && !fadingMusic) musicSource.volume = GoF2Settings.MusicVolume;
            if (sfxSource != null) sfxSource.volume = GoF2Settings.SfxVolume;
            if (bloom != null) bloom.active = GoF2Settings.Bloom;
            if (colorAdjustments != null)
            {
                colorAdjustments.postExposure.overrideState = true;
                colorAdjustments.postExposure.value = GoF2Settings.BrightnessExposure;
            }
        }

        // ---- text ------------------------------------------------------------------------------

        void LoadLanguage(string code)
        {
            int i = Array.IndexOf(languageCodes, code);
            if (i < 0 || languageTables == null || i >= languageTables.Length || languageTables[i] == null) i = 0;
            if (languageTables != null && languageTables.Length > 0) GoF2Localization.Load(languageCodes[i], languageTables[i]);
        }

        void RefreshTexts()
        {
            string T(int id) => GoF2Localization.Get(id).ToUpperInvariant();
            void Set(string name, string text) { var e = root.Q<TextElement>(name); if (e != null) e.text = text; }

            Set("resumeButton", T(41));
            Set("newGameButton", T(28));
            Set("loadButton", T(29));
            Set("optionsButton", T(31));
            Set("aboutButton", T(43));
            Set("exitButton", T(33));
            foreach (var n in new[] { "campaignBack", "difficultyBack", "loadBack", "optionsBack", "aboutBack" }) Set(n, "‹  " + T(170));

            Set("campaignTitle", T(103));
            Set("difficultyTitle", T(517));
            Set("normalLabel", T(519));
            Set("normalDesc", GoF2Localization.Extra("normalDesc", "The classic Galaxy on Fire 2 experience."));
            Set("extremeLabel", T(25));
            Set("extremeDesc", GoF2Localization.Extra("extremeDesc", "For veterans who finished the game: tougher enemies and a harsher economy."));
            Set("loadTitle", T(29));
            Set("optionsTitle", T(31));
            Set("tabSound", T(489));
            Set("tabControls", T(498));
            Set("tabLanguage", T(0));
            Set("volumeHeader", T(501));
            Set("graphicsHeader", T(502));
            Set("aboutTitle", T(43));
            Set("dialogYes", T(134));
            Set("dialogNo", T(135));

            root.Q<Slider>("musicSlider").label = GoF2Localization.Get(34);
            root.Q<Slider>("fxSlider").label = GoF2Localization.Get(35);
            root.Q<Slider>("voiceSlider").label = GoF2Localization.Get(36);
            root.Q<SliderInt>("brightnessSlider").label = $"{GoF2Localization.Get(503)}: {GoF2Localization.Get(513 + GoF2Settings.Brightness)}";
            root.Q<Toggle>("bloomToggle").label = GoF2Localization.Extra("bloom", "Bloom");
            root.Q<Slider>("sensitivitySlider").label = $"{GoF2Localization.Get(499)}: {GoF2Settings.Sensitivity:0.0}";
            root.Q<Toggle>("invertToggle").label = GoF2Localization.Get(500);
            foreach (var b in root.Q("languageList").Query<Button>().ToList())
                b.EnableInClassList("language-button--active", b.name == "lang_" + GoF2Localization.Language);

            pressAnyKey.text = GoF2Localization.Extra("pressAnyKey", "PRESS ANY KEY");
            versionLabel.text = versionText;
            hintLabel.text = GoF2Localization.Extra("hint", "↑ ↓  NAVIGATE     ENTER  SELECT     ESC  " + T(170));
            root.Q<Label>("aboutText").text = $"{versionText}\n\n{GoF2Localization.Get(45).TrimEnd()}\n\n{GoF2Localization.Get(48)}";
        }

        // ---- navigation ------------------------------------------------------------------------

        void OnNavigate(NavigationMoveEvent e)
        {
            if (screen != MenuState.Menu) return;
            var focused = root.focusController?.focusedElement as VisualElement;
            bool vertical = e.direction == NavigationMoveEvent.Direction.Up || e.direction == NavigationMoveEvent.Direction.Down;
            bool horizontal = e.direction == NavigationMoveEvent.Direction.Left || e.direction == NavigationMoveEvent.Direction.Right;
            if (!vertical && !horizontal) return;

            // Sliders and toggles keep left/right for themselves.
            if (horizontal && focused is BaseField<float> || horizontal && focused is BaseField<int>) return;

            var scope = dialog.ClassListContains("dialog-backdrop--shown") ? dialog : openPanel ?? mainButtons;
            var items = Focusables(scope);
            if (items.Count == 0) return;
            int i = focused != null ? items.IndexOf(focused) : -1;
            int step = e.direction == NavigationMoveEvent.Direction.Up || e.direction == NavigationMoveEvent.Direction.Left ? -1 : 1;
            int next = i < 0 ? 0 : Mathf.Clamp(i + step, 0, items.Count - 1);
            items[next].Focus();
            e.StopPropagation();
            root.focusController?.IgnoreEvent(e);
        }

        static List<VisualElement> Focusables(VisualElement scope)
        {
            var list = new List<VisualElement>();
            scope.Query<VisualElement>().Where(v => v.focusable && v.canGrabFocus && v.enabledInHierarchy && v.resolvedStyle.display != DisplayStyle.None
                                                     && !(v.parent is BaseField<float>) && !(v.parent is BaseField<int>) && !(v.parent is Toggle)
                                                     && IsShown(v, scope))
                .ForEach(list.Add);
            return list;
        }

        static bool IsShown(VisualElement v, VisualElement scope)
        {
            for (var p = v; p != null && p != scope.parent; p = p.parent)
                if (p.resolvedStyle.display == DisplayStyle.None) return false;
            return true;
        }

        void FocusFirst(VisualElement scope)
        {
            var items = Focusables(scope);
            if (items.Count > 0) items[0].Focus();
        }

        static void SetFocusable(VisualElement scope, bool on)
        {
            foreach (var b in scope.Query<Button>().ToList()) b.focusable = on;
        }

        static void EnsureVisible(VisualElement v)
        {
            for (var p = v.parent; p != null; p = p.parent)
                if (p is ScrollView sv) { sv.ScrollTo(v); return; }
        }

        // ---- audio -----------------------------------------------------------------------------

        bool fadingMusic;

        IEnumerator FadeMusic(float target, float seconds)
        {
            if (musicSource == null) yield break;
            fadingMusic = true;
            float start = musicSource.volume;
            for (float t = 0f; t < seconds; t += Time.unscaledDeltaTime)
            {
                musicSource.volume = Mathf.Lerp(start, target, t / seconds);
                yield return null;
            }
            musicSource.volume = target;
            fadingMusic = false;
        }

        void Play(AudioClip clip, float volume = 1f)
        {
            if (clip != null && sfxSource != null) sfxSource.PlayOneShot(clip, volume);
        }
    }
}
