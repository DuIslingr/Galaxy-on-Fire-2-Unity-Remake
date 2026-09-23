// GoF2MainMenu.cs
// Main menu controller (UI Toolkit). Follows the original flow (MTitle -> ModMainMenu -> MenuTouchWindow(0)):
//   1. Splash: FISHLABS then (instead of ABYSS ENGINE) "Made with Unity". In players this is Unity's own
//      splash screen (Player Settings); in the editor the menu shows the FISHLABS logo itself.
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
using PointerType = UnityEngine.UIElements.PointerType;

namespace GoF2Remake.UI
{
    [RequireComponent(typeof(PanelRenderer))]
    [DefaultExecutionOrder(-1000)]   // register for the UI load before PanelRenderer loads the UXML
    public class GoF2MainMenu : MonoBehaviour
    {
        [Header("Flow")]
        public bool showSplash = true;
        [Tooltip("Scene loaded by Start new game (until the campaign exists).")]
        public string gameScene = "Space";
        public string versionText = "Galaxy on Fire 2 Remake  ·  pre-alpha";

        [Header("Editor splash (players use Unity's splash screen with the same logos)")]
        [Tooltip("MTitle image 7001 (FISHLABS). Each logo: 1 s fade in, 2 s hold, 1 s fade out.")]
        public Texture2D[] editorSplashLogos;

        [Header("Audio")]
        public AudioSource musicSource;
        public AudioSource sfxSource;
        public AudioClip menuMusic;      // event 145 Space_NoCombat_Void
        public AudioClip buttonPush;     // event 124
        public AudioClip buttonRelease;  // event 123
        public AudioClip infoSound;      // event 126
        // Voice volume preview (remake: the original only previewed FX). Same lines in both voice banks;
        // German voices play when the language is German, like the original's voice bank switch.
        public AudioSource voiceSource;
        public AudioClip[] voicePreviewEnglish;
        public AudioClip[] voicePreviewGerman;

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
        VisualElement openPanel, fpsRow;
        Action dialogYes;
        MenuState screen = MenuState.Splash;
        bool skipRequested;
        GoF2Campaign pendingCampaign;
        IVisualElementScheduledItem pulse;
        Bloom bloom;
        ColorAdjustments colorAdjustments;
        IDisposable anyKey;
        PanelSettings runtimePanel;
        PanelRenderer panelRenderer;
        bool started;
        int voicePreviewIndex;
        bool touchMode;   // last input was a finger: no hover styles, no focus highlight (see SetTouchMode)
        VisualElement safeArea;
        Vector2Int lastScreen;
        Rect lastSafeArea;

        // ---- setup ----------------------------------------------------------------------------

        void OnEnable()
        {
            // Per-instance panel settings: scaling is adapted to the screen shape (see UpdateLayout).
            panelRenderer = GetComponent<PanelRenderer>();
            if (!started) touchMode = Application.isMobilePlatform;
            GoF2Settings.Changed += ApplySettings;
            // PanelRenderer hands out the UI root when it (re)loads the UXML, including live reloads.
            // Register first: assigning the panel settings below reloads the UI.
            panelRenderer.RegisterUIReloadCallback(OnUIReload);
            if (runtimePanel == null && panelRenderer.panelSettings != null)
            {
                runtimePanel = Instantiate(panelRenderer.panelSettings);
                panelRenderer.panelSettings = runtimePanel;
            }
        }

        void OnUIReload(PanelRenderer renderer, VisualElement rootElement, int version)
        {
            root = rootElement;
            root.style.flexGrow = 1;   // the default theme would stretch the document root; ours is custom
            root.EnableInClassList("can-hover", !touchMode);
            safeArea = root.Q("safeArea");
            LoadLanguage(GoF2Settings.Language);

            logo = root.Q("logo");
            logo.usageHints = UsageHints.DynamicTransform;
            logo.RegisterCallback<GeometryChangedEvent>(_ => PlaceTitleLogo());
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
            {
                panels[n] = root.Q(n);
                panels[n].usageHints = UsageHints.DynamicTransform;
            }
            foreach (var n in new[] { "aboutScroll", "slotList" })
            {
                var sv = root.Q<ScrollView>(n);
                sv.mode = ScrollViewMode.Vertical;
                sv.verticalScrollerVisibility = ScrollerVisibility.Hidden;     // drag / wheel / focus scrolling instead
                sv.horizontalScrollerVisibility = ScrollerVisibility.Hidden;
                new GoF2DragScroll(sv);
            }
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
            root.RegisterCallback<PointerDownEvent>(OnPointerDown, TrickleDown.TrickleDown);
            root.RegisterCallback<PointerMoveEvent>(e => { if (e.pointerType == PointerType.mouse) SetTouchMode(false); }, TrickleDown.TrickleDown);
            root.RegisterCallback<FocusInEvent>(e => { if (e.target is VisualElement v) EnsureVisible(v); });

            if (postVolume != null && postVolume.profile != null)
            {
                postVolume.profile.TryGet(out bloom);
                postVolume.profile.TryGet(out colorAdjustments);
            }
            ApplySettings();

            RefreshTexts();
            lastScreen = Vector2Int.zero;
            UpdateLayout();
            if (!started)
            {
                started = true;
                foreach (var b in mainButtons.Query<Button>().ToList()) b.AddToClassList("menu-button--hidden");
                StartCoroutine(Run());
            }
            else RestoreState();
        }

        /// <summary>After a live UI reload the tree is new: put it back in the current flow state.</summary>
        void RestoreState()
        {
            if (screen == MenuState.Splash) return;
            splash.AddToClassList("splash--gone");
            splash.AddToClassList("splash--removed");
            logo.RemoveFromClassList("logo--instant");
            if (screen == MenuState.Title) { logo.AddToClassList("logo--title-visible"); return; }
            logo.AddToClassList("logo--menu");
            pressAnyKey.AddToClassList("press-any-key--hidden");
            root.AddToClassList("menu-root--menu");
            FocusFirst(mainButtons);
        }

        [Tooltip("Force the phone layout (for testing in the editor).")]
        public bool simulatePhone;

        /// <summary>The loaded UI root (PanelRenderer has no rootVisualElement; set by the reload callback).</summary>
        public VisualElement Root => root;

        /// <summary>Size the panel renders at: the screen, or its target texture when rendering off-screen.</summary>
        Vector2Int ScreenSize()
        {
            var rt = runtimePanel != null ? runtimePanel.targetTexture : null;
            return rt != null ? new Vector2Int(rt.width, rt.height) : new Vector2Int(Screen.width, Screen.height);
        }

        void Update()
        {
            if (root == null) return;
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

            ApplySafeArea(w, h, offscreen);
        }

        /// <summary>Safe area insets (pixels -> panel units) once the panel is laid out (its size is NaN before).</summary>
        void ApplySafeArea(float w, float h, bool offscreen)
        {
            root.schedule.Execute(() =>
            {
                if (safeArea == null) return;
                if (!(root.layout.width > 0f)) { ApplySafeArea(w, h, offscreen); return; }   // also catches NaN
                float k = root.layout.width / w;
                var sa = offscreen ? new Rect(0f, 0f, w, h) : Screen.safeArea;
                safeArea.style.paddingLeft = sa.xMin * k;
                safeArea.style.paddingRight = (w - sa.xMax) * k;
                safeArea.style.paddingTop = (h - sa.yMax) * k;
                safeArea.style.paddingBottom = sa.yMin * k;
            }).ExecuteLater(1);
        }

        void OnDisable()
        {
            panelRenderer?.UnregisterUIReloadCallback(OnUIReload);
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
            // Mouse only: a finger sliding over the UI must not drag the selection along with it.
            e.RegisterCallback<PointerEnterEvent>(ev => { if (ev.pointerType == PointerType.mouse && e.enabledInHierarchy && e.focusable) e.Focus(); });
            e.RegisterCallback<FocusInEvent>(_ => { if (screen == MenuState.Menu) Play(buttonPush, 0.45f); });
        }

        // Touch has no hover, and a highlight that follows the finger (or stays on whatever was last pressed)
        // looks broken. In touch mode the selection highlight is off: hover styles need the root's can-hover
        // class, presses don't move focus and menus don't pre-select their first item. A mouse or
        // keyboard/controller navigation switches back.
        void SetTouchMode(bool on)
        {
            if (root == null || on == touchMode && root.ClassListContains("can-hover") != on) return;
            touchMode = on;
            root.EnableInClassList("can-hover", !on);
            if (on && root.focusController?.focusedElement is VisualElement focused) focused.Blur();
        }

        void OnPointerDown(PointerDownEvent e)
        {
            if (e.pointerType == PointerType.mouse) { SetTouchMode(false); return; }
            SetTouchMode(true);
            root.focusController?.IgnoreEvent(e);   // don't focus what the finger presses
        }

        void Select(VisualElement e)
        {
            if (!touchMode) e?.Focus();
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
            bool splashLogos = showSplash && Application.isEditor && editorSplashLogos != null;
            if (splashLogos)
            {
                foreach (var tex in editorSplashLogos)
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
            yield return new WaitForSeconds(splashLogos ? 1.5f : 0.3f);
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

        /// <summary>
        /// The logo lives at its menu spot (top-left); on the title screen it is moved to the centre and enlarged
        /// with translate + scale only, so the move to the menu is a cheap GPU transform animation.
        /// </summary>
        void PlaceTitleLogo()
        {
            if (screen == MenuState.Menu || screen == MenuState.Leaving || logo.parent == null) return;
            var p = logo.parent.layout;
            var el = logo.layout;
            if (el.width <= 0f || el.height <= 0f || p.width <= 0f) return;
            const float aspect = 670f / 207f;                           // logo_gof2.png
            float imgW = Mathf.Min(el.width, el.height * aspect);     // scale-to-fit, left aligned
            var imgCenter = new Vector2(el.x + imgW * 0.5f, el.y + el.height * 0.5f);
            float targetW = Mathf.Min(p.width * 0.56f, p.height * 0.34f * aspect);
            float k = targetW / imgW;
            var target = new Vector2(p.width * 0.5f, p.height * 0.41f);
            logo.style.transformOrigin = new TransformOrigin(Length.Pixels(imgW * 0.5f), Length.Percent(50f));
            logo.style.translate = new Translate(target.x - imgCenter.x, target.y - imgCenter.y);
            logo.style.scale = new Scale(new Vector2(k, k));
            // First placement happens without animation; transitions are enabled afterwards.
            if (logo.ClassListContains("logo--instant"))
                logo.schedule.Execute(() => logo.RemoveFromClassList("logo--instant")).ExecuteLater(50);
        }

        void EnterMenu()
        {
            screen = MenuState.Menu;
            anyKey?.Dispose();
            pulse?.Pause();
            pressAnyKey.AddToClassList("press-any-key--hidden");
            // Back to the logo's own (menu) placement: a transform-only transition, no relayout per frame.
            // Swap classes first and start the move once the styles are resolved again: a transition that starts
            // before that still uses the title fade's 3.9 s duration instead of the 0.9 s of .logo.
            logo.RemoveFromClassList("logo--title-visible");
            logo.AddToClassList("logo--menu");
            IVisualElementScheduledItem move = null;
            move = logo.schedule.Execute(() =>
            {
                foreach (var d in logo.resolvedStyle.transitionDuration)
                    if ((d.unit == TimeUnit.Millisecond ? d.value / 1000f : d.value) > 2f) return;
                logo.style.translate = StyleKeyword.Null;
                logo.style.scale = StyleKeyword.Null;
                move.Pause();
            }).Every(0);
            root.AddToClassList("menu-root--menu");
            mainButtons.AddToClassList("main-buttons--revealing");
            root.schedule.Execute(() =>
            {
                foreach (var b in mainButtons.Query<Button>().ToList()) b.RemoveFromClassList("menu-button--hidden");
                FocusFirst(mainButtons);
            }).ExecuteLater(200);
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
            Select(target);
        }

        void PickCampaign(GoF2Campaign c)
        {
            pendingCampaign = c;
            OpenPanel("difficultyPanel");
        }

        void StartGame(float difficulty)
        {
            GoF2Session.ResetNewGame();   // Status::resetGame: Phantom at Var Hastra (Mido)
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
            Select(root.Q<Button>("dialogNo"));
        }

        void CloseDialog()
        {
            dialog.RemoveFromClassList("dialog-backdrop--shown");
            dialogYes = null;
            if (openPanel != null) FocusFirst(openPanel); else Select(exitButton);
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
                row.AddToClassList("slot-row--empty");   // no save system yet

                var index = new Label(i.ToString("00"));
                index.AddToClassList("slot-index");
                index.AddToClassList("gof-semibold");
                var info = new VisualElement();
                info.AddToClassList("slot-info");
                var name = new Label(i == 0 ? GoF2Localization.Get(486) : $"{GoF2Localization.Extra("slot", "Slot")} {i}");
                name.AddToClassList("slot-name");
                info.Add(name);
                if (i == 0)
                {
                    var sub = new Label(GoF2Localization.Extra("autosaveHint", "Saved automatically when you dock"));
                    sub.AddToClassList("slot-sub");
                    info.Add(sub);
                }
                var state = new Label(GoF2Localization.Get(174));   // -BLANK-
                state.AddToClassList("slot-state");

                foreach (var e in new VisualElement[] { index, info, state }) e.pickingMode = PickingMode.Ignore;
                row.Add(index);
                row.Add(info);
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
            voice.RegisterCallback<PointerCaptureOutEvent>(_ => PlayVoicePreview());
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

            // Frame rate: one focusable row (left/right steps through it), segments clickable by touch/mouse.
            fpsRow = root.Q("fpsRow");
            var fpsChoices = root.Q("fpsChoices");
            for (int i = 0; i <= (int)GoF2FrameRate.VSync; i++)
            {
                var mode = (GoF2FrameRate)i;
                var b = new Button { name = "fps_" + mode, focusable = false };
                b.AddToClassList("fps-choice");
                b.AddToClassList("gof-semibold");
                b.clicked += () => SetFrameRate(mode);
                fpsChoices.Add(b);
            }
            HookFocusSound(fpsRow);

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

        void SetFrameRate(GoF2FrameRate mode)
        {
            if (mode == GoF2Settings.FrameRate) return;
            Play(buttonRelease);
            GoF2Settings.FrameRate = mode;
            RefreshTexts();
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
            if (voiceSource != null) voiceSource.volume = GoF2Settings.VoiceVolume;
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
            root.Q<Label>("fpsLabel").text = GoF2Localization.Extra("frameRate", "Frame rate");
            foreach (var b in root.Q("fpsChoices").Query<Button>().ToList())
            {
                var mode = (GoF2FrameRate)Enum.Parse(typeof(GoF2FrameRate), b.name.Substring(4));
                b.text = mode switch
                {
                    GoF2FrameRate.Fps30 => "30",
                    GoF2FrameRate.Fps60 => "60",
                    GoF2FrameRate.Fps120 => "120",
                    GoF2FrameRate.Uncapped => GoF2Localization.Extra("fpsUncapped", "UNCAPPED"),
                    _ => GoF2Localization.Extra("fpsVSync", "V-SYNC"),
                };
                b.EnableInClassList("fps-choice--active", mode == GoF2Settings.FrameRate);
            }
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
            SetTouchMode(false);
            var focused = root.focusController?.focusedElement as VisualElement;
            bool vertical = e.direction == NavigationMoveEvent.Direction.Up || e.direction == NavigationMoveEvent.Direction.Down;
            bool horizontal = e.direction == NavigationMoveEvent.Direction.Left || e.direction == NavigationMoveEvent.Direction.Right;
            if (!vertical && !horizontal) return;

            if (horizontal && focused != null && focused == fpsRow)
            {
                int dir = e.direction == NavigationMoveEvent.Direction.Left ? -1 : 1;
                SetFrameRate((GoF2FrameRate)Mathf.Clamp((int)GoF2Settings.FrameRate + dir, 0, (int)GoF2FrameRate.VSync));
                e.StopPropagation();
                root.focusController?.IgnoreEvent(e);
                return;
            }

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
            if (items.Count > 0) Select(items[0]);
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

        void PlayVoicePreview()
        {
            var clips = GoF2Localization.Language == "de" && voicePreviewGerman != null && voicePreviewGerman.Length > 0
                ? voicePreviewGerman : voicePreviewEnglish;
            if (voiceSource == null || clips == null || clips.Length == 0) return;
            voiceSource.Stop();   // one line at a time, a new release restarts it
            voiceSource.clip = clips[voicePreviewIndex++ % clips.Length];
            voiceSource.volume = GoF2Settings.VoiceVolume;
            voiceSource.Play();
        }

        void Play(AudioClip clip, float volume = 1f)
        {
            if (clip != null && sfxSource != null) sfxSource.PlayOneShot(clip, volume);
        }
    }
}
