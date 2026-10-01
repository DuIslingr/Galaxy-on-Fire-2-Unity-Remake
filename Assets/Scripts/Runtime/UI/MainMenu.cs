// MainMenu.cs
// Main menu controller (UI Toolkit). Follows the original flow (MTitle -> ModMainMenu -> MenuTouchWindow(0)):
//   1. Splash: FISHLABS then (instead of ABYSS ENGINE) "Made with Unity". In players this is Unity's own
//      splash screen (Player Settings); in the editor the menu shows the FISHLABS logo itself.
//   2. Title: the GoF2 logo fades in over the live 3D scene (3.9 s), "press any key" pulses under it.
//   3. Menu: Resume (only with a save), Start new game -> Select Campaign -> difficulty (Easy / Normal / Hard / Extreme: the PC version's four),
//      Load game (save slots, slot 0 = Auto-save), Options (Sound & Graphics, Controls, Language), About, Exit.
// Text comes from the original table (Localization, text IDs in comments). Sounds: Button_Push on focus
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
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public class MainMenu : MonoBehaviour
    {
        [Header("Flow")]
        public bool showSplash = true;
        [Tooltip("Fallback scene for Leave() without a scene name.")]
        public string gameScene = "Space";
        /// <summary>The credit line under the menu and on the About page (the heart is the text icons' sprite, the version
        /// the build's date and time, BuildVersion).</summary>
        static string VersionText =>
            "Galaxy on Fire 2 Unity Remake created with <sprite=\"gof2_text_icons\" name=\"heart\"> by JoppieToppie  ·  " + BuildVersion.Text;

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
        // German voices play with the German voice language (by default the German text, like the original's voice bank switch).
        public AudioSource voiceSource;
        public AudioClip[] voicePreviewEnglish;
        public AudioClip[] voicePreviewGerman;

        [Header("Localization (text_<code>.json)")]
        public string[] languageCodes = { "en" };
        public string[] languageNames = { "English" };
        public TextAsset[] languageTables;

        [Header("Post-processing")]
        [Tooltip("The menu's volume (bloom and brightness are applied to every global volume by Bootstrap).")]
        public Volume postVolume;

        enum MenuState { Splash, Title, Menu, Leaving }

        /// <summary>A panel to open as soon as the menu loads ("campaignPanel": the station menu's Start new game).</summary>
        public static string OpenPanelOnStart;

        VisualElement root, logo, splash, splashLogo, fade, dialog, mainColumn, mainButtons;
        Label pressAnyKey, versionLabel, hintLabel;
        Button resumeButton, newGameButton, multiplayerButton, loadButton, optionsButton, aboutButton, debugButton, exitButton;
        readonly Dictionary<string, VisualElement> panels = new Dictionary<string, VisualElement>();
        VisualElement openPanel;
        readonly List<OptionControl> optionControls = new List<OptionControl>();
        Action dialogYes;
        MenuState screen = MenuState.Splash;
        bool skipRequested;
        Campaign pendingCampaign;
        IVisualElementScheduledItem pulse;
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
            Settings.Changed += ApplySettings;
            InputMode.Changed -= UpdatePressAnyKey;
            InputMode.Changed += UpdatePressAnyKey;
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
            LoadLanguage(Settings.Language);

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

            resumeButton = Bind("resumeButton", () => LoadSlot(SaveGame.MostRecentSlot()));
            newGameButton = Bind("newGameButton", () => OpenPanel("campaignPanel"));
            multiplayerButton = Bind("multiplayerButton", OpenMultiplayer);
            loadButton = Bind("loadButton", () => { BuildSlots(); OpenPanel("loadPanel"); });
            optionsButton = Bind("optionsButton", () => { OpenPanel("optionsPanel"); SelectTab(OptionPages[0].page); });
            aboutButton = Bind("aboutButton", () => OpenPanel("aboutPanel"));
            debugButton = Bind("debugButton", OpenDebug);
            UpdateDebugButton();
            exitButton = Bind("exitButton", () => ShowDialog(Localization.Get(390), Localization.Get(53), Quit));
            resumeButton.EnableInClassList("menu-button--gone", SaveGame.MostRecentSlot() < 0);   // only with a save

            foreach (var n in new[] { "campaignPanel", "difficultyPanel", "economyPanel", "loadPanel", "optionsPanel", "aboutPanel", "multiplayerPanel" })
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
                new DragScroll(sv);
            }
            // The option pages scroll by wheel, touch and focus only (a drag would fight the sliders).
            foreach (var (_, pg) in OptionPages)
            {
                if (!(root.Q(pg) is ScrollView sv)) continue;
                sv.mode = ScrollViewMode.Vertical;
                sv.verticalScrollerVisibility = ScrollerVisibility.Hidden;
                sv.horizontalScrollerVisibility = ScrollerVisibility.Hidden;
            }
            foreach (var n in new[] { "campaignBack", "difficultyBack", "economyBack", "loadBack", "optionsBack", "aboutBack", "multiplayerBack" })
            {
                var b = root.Q<Button>(n);
                b.clicked += Back;   // Back() plays the release sound itself (also used by Esc)
                HookFocusSound(b);
            }

            Bind("cardGof2", () => PickCampaign(Campaign.GalaxyOnFire2));
            Bind("cardValkyrie", () => PickCampaign(Campaign.Valkyrie));
            Bind("cardSupernova", () => PickCampaign(Campaign.Supernova));
            BuildDebugPanel();
            UpdateDebugButton();
            SetupMultiplayerPanel();
            Bind("easyButton", () => PickDifficulty(Session.DifficultyEasy));
            Bind("normalButton", () => PickDifficulty(Session.DifficultyNormal));
            Bind("hardButton", () => PickDifficulty(Session.DifficultyHard));
            Bind("extremeButton", () => ShowDialog(Localization.Get(25), Localization.Get(26),
                () => PickDifficulty(Session.DifficultyExtreme)));
            Bind("economyDefaultButton", () => StartGame(Economy.Default));
            Bind("economyAndroidButton", () => StartGame(Economy.Android));
            Bind("dialogYes", () => { var a = dialogYes; CloseDialog(); a?.Invoke(); });
            Bind("dialogNo", CloseDialog);

            foreach (var (tab, pg) in OptionPages) Bind(tab, () => SelectTab(pg));
            Bind("optionsDefaults", () => { Settings.ResetToDefaults(); RefreshTexts(); });   // 497
            SetupOptions();

            root.RegisterCallback<NavigationCancelEvent>(_ => Back(), TrickleDown.TrickleDown);
            root.RegisterCallback<NavigationMoveEvent>(OnNavigate, TrickleDown.TrickleDown);
            root.RegisterCallback<NavigationSubmitEvent>(e =>
            {
                if (screen == MenuState.Menu && root.focusController?.focusedElement is ChoiceRow row) { row.Cycle(); e.StopPropagation(); }
            }, TrickleDown.TrickleDown);
            root.RegisterCallback<PointerDownEvent>(OnPointerDown, TrickleDown.TrickleDown);
            root.RegisterCallback<PointerMoveEvent>(e => { DragScroll.NotePointer(); if (e.pointerType == PointerType.mouse) SetTouchMode(false); }, TrickleDown.TrickleDown);
            root.RegisterCallback<WheelEvent>(_ => DragScroll.NotePointer(), TrickleDown.TrickleDown);
            // Keys / controller: the focused row scrolls into view (not for the pointer's own focus: DragScroll.PointerActive).
            root.RegisterCallback<FocusInEvent>(e => { if (e.target is VisualElement v && !DragScroll.PointerActive) EnsureVisible(v); });

            ApplySettings();

            RefreshTexts();
            lastScreen = Vector2Int.zero;
            UpdateLayout();
            if (!started)
            {
                started = true;
                // The main story's ending plays over this scene's backdrop (ModStation's CutScene(2)), then the station.
                if (Session.EndingPending) { EndingCredits.Begin(gameObject, root, musicSource); return; }
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
            if (root == null || GoF2Remake.Flight.GameControls.BlocksMenus) return;
            // Remake: the debug panel (F10, LB + RB or three fingers held for a second, or five taps on the version text).
            if (screen == MenuState.Menu && Keyboard.current != null && Keyboard.current.f10Key.wasPressedThisFrame) OpenDebug();
            var pad = Gamepad.current;
            if (screen == MenuState.Menu && ((pad != null && pad.leftShoulder.isPressed && pad.rightShoulder.isPressed) || FingersDown() >= 3))
            {
                debugHoldTime += Time.unscaledDeltaTime;
                if (debugHoldTime >= 1f && debugHoldTime - Time.unscaledDeltaTime < 1f) OpenDebug();
            }
            else debugHoldTime = 0f;
            if (lastScreen != ScreenSize() || lastSafeArea != Screen.safeArea) UpdateLayout();
        }

        static int FingersDown()
        {
            var ts = Touchscreen.current;
            if (ts == null) return 0;
            int n = 0;
            foreach (var t in ts.touches) if (t.press.isPressed) n++;
            return n;
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
            Settings.Changed -= ApplySettings;
            InputMode.Changed -= UpdatePressAnyKey;
            anyKey?.Dispose();
        }

        /// <summary>The title prompt follows the input scheme: any key on the keyboard, any button on a controller, a tap
        /// on touch.</summary>
        void UpdatePressAnyKey()
        {
            if (pressAnyKey == null) return;
            pressAnyKey.text = InputMode.Current switch
            {
                InputKind.Gamepad => Localization.Extra("pressAnyButton", "PRESS ANY BUTTON"),
                InputKind.Touch => Localization.Extra("tapToStart", "TAP TO START"),
                _ => Localization.Extra("pressAnyKey", "PRESS ANY KEY"),
            };
        }

        Button Bind(string name, Action onClick)
        {
            var b = root.Q<Button>(name);
            if (b == null) { Debug.LogWarning($"MainMenu: button '{name}' missing"); return null; }
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
            DragScroll.NotePointer();
            if (e.pointerType == PointerType.mouse) { SetTouchMode(false); return; }
            SetTouchMode(true);
            // Don't focus what the finger presses, except a text field (the address, the debug search): it needs the focus
            // for the on-screen keyboard.
            for (var v = e.target as VisualElement; v != null; v = v.parent)
                if (v is TextField) return;
            root.focusController?.IgnoreEvent(e);
        }

        void Select(VisualElement e)
        {
            if (!touchMode) e?.Focus();
        }

        // ---- flow ------------------------------------------------------------------------------

        IEnumerator Run()
        {
            // Whatever the last scene left: never a muted listener here (a pause menu open when a multiplayer session
            // ended loads the menu without closing it), and a finished session's game is gone.
            AudioListener.pause = false;
            GoF2Remake.Multiplayer.NetGame.OnMainMenu();
            if (musicSource != null && menuMusic != null)
            {
                musicSource.clip = menuMusic;
                musicSource.loop = true;
                musicSource.volume = 0f;
                musicSource.Play();      // MTitle starts the menu theme with the first logo
            }
            StartCoroutine(FadeMusic(Settings.MusicVolume, 3f));

            // The station menu's Start new game (MenuTouchWindow mode 2, 28): straight to the menu with that panel open.
            if (OpenPanelOnStart != null && panels.ContainsKey(OpenPanelOnStart))
            {
                string name = OpenPanelOnStart;
                OpenPanelOnStart = null;
                splash.AddToClassList("splash--gone");
                splash.AddToClassList("splash--removed");
                EnterMenu();
                // Out of a multiplayer session (the host left, the connection dropped): the reason, taken now (a -mpjoin
                // client's next try starts a new session at once, which clears the status).
                string reason = null;
                bool popup = name == "multiplayerPanel" && GoF2Remake.Multiplayer.NetGame.TakePopup(out reason);
                root.schedule.Execute(() =>
                {
                    OpenPanel(name);
                    if (popup) ShowNotice(Localization.Extra("multiplayer", "Multiplayer"), reason);
                }).ExecuteLater(400);
                if (GoF2Remake.Multiplayer.NetGame.AutoJoinAddress != null) StartCoroutine(AutoJoin(GoF2Remake.Multiplayer.NetGame.AutoJoinAddress));
                yield break;
            }
            OpenPanelOnStart = null;
            // Multiplayer testing (-mpjoin <address>, e.g. a second Windows player next to the Editor's host): straight to the
            // menu, then join.
            if (GoF2Remake.Multiplayer.NetGame.AutoJoinAddress != null || GoF2Remake.Multiplayer.NetGame.TestHost)
            {
                splash.AddToClassList("splash--gone");
                splash.AddToClassList("splash--removed");
                EnterMenu();
                root.schedule.Execute(() => OpenPanel("multiplayerPanel")).ExecuteLater(400);   // its status shows the tries
                if (GoF2Remake.Multiplayer.NetGame.AutoJoinAddress != null) StartCoroutine(AutoJoin(GoF2Remake.Multiplayer.NetGame.AutoJoinAddress));
                else StartCoroutine(TestHostSoon());   // -mphost (development builds)
                yield break;
            }
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
            if (name == "multiplayerPanel") RefreshAddresses();   // the adapters may have changed
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
            if (openPanel == panels["economyPanel"]) { OpenPanel("difficultyPanel"); return; }
            if (openPanel == panels["difficultyPanel"]) { OpenPanel(pendingStartIndex >= 0 && panels.ContainsKey("debugPanel") ? "debugPanel" : "campaignPanel"); return; }
            var closing = openPanel;
            HidePanel(closing);
            openPanel = null;
            mainColumn.RemoveFromClassList("main-column--dimmed");
            SetFocusable(mainButtons, true);
            var target = closing == panels["campaignPanel"] || panels.TryGetValue("debugPanel", out var ap) && closing == ap ? newGameButton
                : closing == panels["loadPanel"] ? loadButton
                : closing == panels["optionsPanel"] ? optionsButton
                : closing == panels["multiplayerPanel"] ? multiplayerButton : aboutButton;
            Select(target);
        }

        void PickCampaign(Campaign c)
        {
            pendingCampaign = c;
            pendingStartIndex = -1;
            OpenPanel("difficultyPanel");
        }

        float pendingDifficulty = Session.DifficultyNormal;

        void PickDifficulty(float difficulty)
        {
            pendingDifficulty = difficulty;
            OpenPanel("economyPanel");
        }

        void StartGame(Economy economy)
        {
            Session.ResetNewGame();   // Status::resetGame: Phantom at Var Hastra (Mido)
            Session.Campaign = pendingCampaign;
            Session.Difficulty = pendingDifficulty;
            Session.Economy = economy;   // before the Database: it loads that economy's tables
            var db = Database.Load();
            // Remake: the mission select starts a new game at the chosen story step (Story.StartAtMission).
            if (pendingStartIndex >= 0) { StartCoroutine(Leave(Story.StartAtMission(db, pendingStartIndex))); return; }
            // MenuTouchWindow::startGOF2 / startValkyrie / startSupernova: the story's first step (Story).
            StartCoroutine(Leave(Story.StartCampaign(db, pendingCampaign)));
        }

        // ---- multiplayer (remake-only MVP, NetGame: host or join by address, one shared orbit) ----

        TextField mpAddress, mpName, mpPort;
        Label mpStatus;
        VisualElement mpAddressList;

        void SetupMultiplayerPanel()
        {
            mpAddress = root.Q<TextField>("mpAddress");
            mpStatus = root.Q<Label>("mpStatus");
            if (mpAddress != null) mpAddress.value = PlayerPrefs.GetString("mp_address", "127.0.0.1");
            mpName = root.Q<TextField>("mpName");
            if (mpName != null)
            {
                mpName.maxLength = GoF2Remake.Multiplayer.NetGame.MaxNameLength;
                mpName.value = GoF2Remake.Multiplayer.NetGame.PlayerName;
                mpName.RegisterValueChangedCallback(e => GoF2Remake.Multiplayer.NetGame.PlayerName = e.newValue);
            }
            mpAddressList = root.Q("mpAddressList");
            mpPort = root.Q<TextField>("mpPort");
            if (mpPort != null)
            {
                mpPort.maxLength = 5;
                mpPort.keyboardType = TouchScreenKeyboardType.NumberPad;   // the on-screen keyboard's number pad
                mpPort.value = GoF2Remake.Multiplayer.NetGame.HostPort.ToString();
                mpPort.RegisterValueChangedCallback(e =>
                {
                    if (ushort.TryParse(e.newValue, out ushort p) && p >= 1024) GoF2Remake.Multiplayer.NetGame.HostPort = p;
                    RefreshAddresses();
                });
            }
            Bind("mpHost", () => StartCoroutine(LeaveForMultiplayer(null)));
            Bind("mpJoin", () =>
            {
                string address = mpAddress != null ? mpAddress.value.Trim() : "";
                if (address.Length == 0) return;
                PlayerPrefs.SetString("mp_address", address);
                StartCoroutine(LeaveForMultiplayer(address));
            });
        }

        /// <summary>-mphost: hosts once the menu is up (the panel has listed the addresses).</summary>
        IEnumerator TestHostSoon()
        {
            yield return new WaitForSeconds(2f);
            while (screen != MenuState.Menu) yield return null;
            yield return LeaveForMultiplayer(null);
        }

        /// <summary>-mpjoin: joins that address, again every 2 s until a host answers (and after a session ends).</summary>
        IEnumerator AutoJoin(string address)
        {
            while (true)
            {
                while (screen != MenuState.Menu) yield return null;
                yield return LeaveForMultiplayer(address);   // returns only when the connection failed
                yield return new WaitForSeconds(2f);
            }
        }

        void OpenMultiplayer()
        {
            if (mpStatus != null) mpStatus.text = GoF2Remake.Multiplayer.NetGame.Status;   // why the last session ended
            OpenPanel("multiplayerPanel");
        }

        /// <summary>The host card's addresses: one row per adapter (NetGame.LocalAddresses) with the port when it isn't the
        /// default; a tap copies it (what a friend types into Join).</summary>
        void RefreshAddresses()
        {
            if (mpAddressList == null) return;
            mpAddressList.Clear();
            ushort port = GoF2Remake.Multiplayer.NetGame.HostPort;
            var addresses = GoF2Remake.Multiplayer.NetGame.LocalAddresses();
            if (Debug.isDebugBuild) Debug.Log("Multiplayer addresses: " + string.Join(", ", addresses));
            if (addresses.Count == 0)
            {
                // No network: hosting still works on this device, but nobody else could join yet.
                var none = new Label(Localization.Extra("mpNoNetwork", "No network: connect to Wi-Fi (or turn on a hotspot) so others can join."));
                none.AddToClassList("mp-card-text");
                mpAddressList.Add(none);
            }
            foreach (var (name, address) in addresses)
            {
                string join = port == GoF2Remake.Multiplayer.NetGame.DefaultPort ? address : $"{address}:{port}";
                var row = new Button { focusable = true };
                row.AddToClassList("mp-address-row");
                var n = new Label(name) { pickingMode = PickingMode.Ignore };
                n.AddToClassList("mp-address-name");
                var v = new Label(join) { pickingMode = PickingMode.Ignore };
                v.AddToClassList("mp-address-value");
                v.AddToClassList("gof-semibold");
                var c = new Label(Localization.Extra("mpCopy", "copy")) { pickingMode = PickingMode.Ignore };
                c.AddToClassList("mp-address-copy");
                row.Add(n); row.Add(v); row.Add(c);
                row.clicked += () =>
                {
                    GUIUtility.systemCopyBuffer = join;
                    foreach (var other in mpAddressList.Children()) other.RemoveFromClassList("mp-address-row--copied");
                    foreach (var other in mpAddressList.Query<Label>(className: "mp-address-copy").ToList()) other.text = Localization.Extra("mpCopy", "copy");
                    row.AddToClassList("mp-address-row--copied");
                    c.text = Localization.Extra("mpCopied", "copied");
                };
                mpAddressList.Add(row);
            }
        }

        /// <summary>Fades out, then hosts (address null: NetGame loads Space for everyone) or joins (the host's scene loads
        /// once connected). A failed start or connection fades the menu back in with the reason.</summary>
        IEnumerator LeaveForMultiplayer(string address)
        {
            if (screen != MenuState.Menu) yield break;
            screen = MenuState.Leaving;
            bool started;
            if (address == null)
            {
                // Only fade out when it can start: a port in use says so at once (with a free one in the port field).
                if (!GoF2Remake.Multiplayer.NetGame.CanHost())
                {
                    if (mpStatus != null) mpStatus.text = GoF2Remake.Multiplayer.NetGame.Status;
                    if (GoF2Remake.Multiplayer.NetGame.SuggestedPort > 0 && mpPort != null) mpPort.value = GoF2Remake.Multiplayer.NetGame.SuggestedPort.ToString();
                    screen = MenuState.Menu;
                    yield break;
                }
                if (mpStatus != null) mpStatus.text = "";
                fade.AddToClassList("fade--on");
                StartCoroutine(FadeMusic(0f, 1.2f));
                yield return new WaitForSeconds(1.3f);
                started = GoF2Remake.Multiplayer.NetGame.StartHost();
            }
            else
            {
                // Joining: the menu stays while it connects (a missing host would be a long black screen); the fade once connected.
                if (mpStatus != null) mpStatus.text = string.Format(Localization.Extra("mpConnecting", "Connecting to {0}..."), address);
                started = GoF2Remake.Multiplayer.NetGame.StartClient(address);
                while (started && GoF2Remake.Multiplayer.NetGame.Active && !GoF2Remake.Multiplayer.NetGame.Connected) yield return null;
                if (started && GoF2Remake.Multiplayer.NetGame.Active)
                {
                    fade.AddToClassList("fade--on");
                    StartCoroutine(FadeMusic(0f, 1.2f));
                }
            }
            while (started && GoF2Remake.Multiplayer.NetGame.Active) yield return null;   // the scene change ends this
            if (mpStatus != null) mpStatus.text = GoF2Remake.Multiplayer.NetGame.Status;
            // The port was in use: the free one it found goes into the port field (hosting again uses it).
            if (address == null && GoF2Remake.Multiplayer.NetGame.SuggestedPort > 0 && mpPort != null)
                mpPort.value = GoF2Remake.Multiplayer.NetGame.SuggestedPort.ToString();
            fade.RemoveFromClassList("fade--on");
            screen = MenuState.Menu;
            StartCoroutine(FadeMusic(Settings.MusicVolume, 1f));
        }

        // ---- debug panel (remake-only testing tools: F10 or five taps on the version text) -------

        int pendingStartIndex = -1;
        ScrollView missionList;
        TextField missionFilter;
        /// <summary>The list's rows with their search text, and each campaign heading with its rows.</summary>
        readonly List<(VisualElement row, string text)> missionRows = new List<(VisualElement, string)>();
        readonly List<(VisualElement heading, List<VisualElement> rows)> missionSections = new List<(VisualElement, List<VisualElement>)>();
        int versionTaps;
        float versionTapTime, debugHoldTime;
        readonly List<OptionControl> debugControls = new List<OptionControl>();

        /// <summary>A hidden panel next to the others: the mission list (a new game from any story step, no intro) on the
        /// left, the cheat toggles on the right.</summary>
        void BuildDebugPanel()
        {
            // A UI reload (PanelRenderer) rebuilds the tree: drop the old panel's elements.
            debugControls.Clear();
            missionRows.Clear();
            missionSections.Clear();
            var host = root.Q("panelHost");
            if (host == null) return;
            var panel = new VisualElement { name = "debugPanel" };
            panel.AddToClassList("panel");
            panel.AddToClassList("panel--wide");
            panel.AddToClassList("debug-panel");
            panel.usageHints = UsageHints.DynamicTransform;
            var title = new Label { name = "debugTitle" };
            title.AddToClassList("panel-title");
            title.AddToClassList("gof-semibold");
            panel.Add(title);
            var accent = new VisualElement();
            accent.AddToClassList("panel-accent");
            panel.Add(accent);
            var columns = new VisualElement();
            columns.AddToClassList("debug-columns");
            var left = new VisualElement();
            left.AddToClassList("debug-column");
            left.AddToClassList("debug-column--missions");
            var right = new VisualElement();
            right.AddToClassList("debug-column");
            right.AddToClassList("debug-column--cheats");
            columns.Add(left);
            columns.Add(right);
            panel.Add(columns);
            var back = new Button { name = "debugBack" };
            back.AddToClassList("menu-button");
            back.AddToClassList("back-button");
            back.AddToClassList("gof-semibold");
            back.clicked += Back;
            HookFocusSound(back);
            panel.Add(back);
            host.Add(panel);
            panels["debugPanel"] = panel;
            BuildMissionList(left);

            // The cheat toggles (Cheats; the actions are on the pause menu's / station's Debug page, in a running game).
            var heading = new Label { name = "debugCheatsTitle", pickingMode = PickingMode.Ignore };
            heading.AddToClassList("debug-heading");
            heading.AddToClassList("gof-semibold");
            right.Add(heading);
            foreach (var def in CheatsCatalog.Toggles())
            {
                var c = new OptionControl(def);
                c.Field.AddToClassList("option-row");
                c.Root.AddToClassList("debug-option");
                HookFocusSound(c.Field);
                c.Changed += () => Play(buttonRelease);
                right.Add(c.Root);
                debugControls.Add(c);
            }
            var note = new Label { name = "debugNote", pickingMode = PickingMode.Ignore };
            note.AddToClassList("debug-note");
            right.Add(note);

            // Touch: five taps on the version text, each within 1 s of the last (its tap zone reaches well past the
            // small text, .footer-version).
            if (versionLabel != null)
            {
                versionLabel.pickingMode = PickingMode.Position;
                versionLabel.AddToClassList("footer-version");
                versionLabel.RegisterCallback<PointerDownEvent>(_ =>
                {
                    if (Time.unscaledTime - versionTapTime > 1f) versionTaps = 0;
                    versionTapTime = Time.unscaledTime;
                    if (++versionTaps >= 5) { versionTaps = 0; OpenDebug(); }
                });
            }
        }

        /// <summary>The main menu's Debug button: only with the debug tools on (Options > Gameplay, or opened once).</summary>
        void UpdateDebugButton() => debugButton?.EnableInClassList("menu-button--gone", !Cheats.Unlocked || !panels.ContainsKey("debugPanel"));

        void OpenDebug()
        {
            if (!panels.ContainsKey("debugPanel") || openPanel == panels["debugPanel"]) return;
            if (dialog.ClassListContains("dialog-backdrop--shown")) return;
            Play(buttonRelease);
            Cheats.Unlocked = true;   // from now on the pause menu and the station's system menu have a Debug page
            UpdateDebugButton();
            foreach (var c in debugControls) c.Refresh();
            OpenPanel("debugPanel");
        }

        /// <summary>A search field and every story step, grouped by campaign: "index  title  station" over an optional
        /// subtitle (StepSummaries). A row starts that step (the difficulty panel first).</summary>
        void BuildMissionList(VisualElement parent)
        {
            var heading = new Label { name = "debugMissionsTitle", pickingMode = PickingMode.Ignore };
            heading.AddToClassList("debug-heading");
            heading.AddToClassList("gof-semibold");
            parent.Add(heading);
            missionFilter = new TextField { name = "debugFilter" };
            missionFilter.AddToClassList("debug-filter");
            missionFilter.textEdition.hidePlaceholderOnFocus = true;
            missionFilter.RegisterValueChangedCallback(e => FilterMissions(e.newValue));
            parent.Add(missionFilter);
            missionList = new ScrollView(ScrollViewMode.Vertical)
            {
                horizontalScrollerVisibility = ScrollerVisibility.Hidden,
                verticalScrollerVisibility = ScrollerVisibility.Hidden,
            };
            missionList.AddToClassList("debug-mission-list");
            new DragScroll(missionList);
            parent.Add(missionList);

            var db = Database.Load();
            Campaign? section = null;
            List<VisualElement> sectionRows = null;
            for (int i = 0; i <= Story.LastIndex; i++)
            {
                if (i == 53 || i == 129) continue;   // nextCampaignMission skips them (52 -> 54, 128 -> 130)
                var campaign = CampaignOf(i);
                if (section != campaign)
                {
                    section = campaign;
                    var h = new Label(campaign switch
                    {
                        Campaign.Valkyrie => "VALKYRIE  ·  45-83",
                        Campaign.Supernova => "SUPERNOVA  ·  84-162",
                        _ => "GALAXY ON FIRE 2  ·  0-44",
                    }) { pickingMode = PickingMode.Ignore };
                    h.AddToClassList("debug-mission-section");
                    h.AddToClassList("gof-semibold");
                    missionList.Add(h);
                    sectionRows = new List<VisualElement>();
                    missionSections.Add((h, sectionRows));
                }
                var step = StoryTable.Step(i);
                var info = StepSummaries.Get(i);
                string station = step == null ? "" : step.station >= 0 ? db.Stations.Find(s => s.index == step.station)?.name ?? ""
                               : step.station == Session.VoidOrbit ? "Void" : "";
                // A one-line title over an optional subtitle (the objective texts repeat, e.g. the whole tutorial is
                // "I'm on my way to Var Hastra.", so they only stand in when a step has no title).
                string summary = info?.summary ?? "";
                string name = !string.IsNullOrEmpty(info?.title) ? info.title : Story.StepLabel(db, i);
                if (string.IsNullOrEmpty(name)) name = station;

                var row = new Button();
                row.AddToClassList("debug-mission");
                var top = new VisualElement { pickingMode = PickingMode.Ignore };
                top.AddToClassList("debug-mission-top");
                var num = new Label(i.ToString()) { pickingMode = PickingMode.Ignore };
                num.AddToClassList("debug-mission-index");
                num.AddToClassList("gof-semibold");
                top.Add(num);
                var label = new Label(name) { pickingMode = PickingMode.Ignore };
                label.AddToClassList("debug-mission-title");
                label.AddToClassList("gof-semibold");
                top.Add(label);
                if (!string.IsNullOrEmpty(station) && station != name)
                {
                    var where = new Label(station) { pickingMode = PickingMode.Ignore };
                    where.AddToClassList("debug-mission-station");
                    top.Add(where);
                }
                row.Add(top);
                if (!string.IsNullOrEmpty(summary))
                {
                    var sum = new Label(summary) { pickingMode = PickingMode.Ignore };
                    sum.AddToClassList("debug-mission-summary");
                    row.Add(sum);
                }
                int index = i;
                row.clicked += () => { Play(buttonRelease); StartAtStep(index); };
                HookFocusSound(row);
                missionList.Add(row);
                missionRows.Add((row, $"{i} {name} {station} {summary}".ToLowerInvariant()));
                sectionRows.Add(row);
            }
        }

        static Campaign CampaignOf(int index) =>
            index >= Story.Dlc1WonIndex ? Campaign.Supernova : index >= Story.GameWonIndex ? Campaign.Valkyrie : Campaign.GalaxyOnFire2;

        void StartAtStep(int index)
        {
            pendingStartIndex = index;
            pendingCampaign = CampaignOf(index);
            OpenPanel("difficultyPanel");
        }

        /// <summary>Rows whose index, title, station or summary contain every word typed (a number matches the index
        /// exactly); a campaign heading hides with all its rows.</summary>
        void FilterMissions(string query)
        {
            var words = (query ?? "").ToLowerInvariant().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            foreach (var (row, text) in missionRows)
            {
                bool match = true;
                foreach (var w in words)
                {
                    if (int.TryParse(w, out _)) { if (!text.StartsWith(w + " ")) { match = false; break; } }
                    else if (!text.Contains(w)) { match = false; break; }
                }
                row.style.display = match ? DisplayStyle.Flex : DisplayStyle.None;
            }
            foreach (var (heading, rows) in missionSections)
                heading.style.display = rows.Exists(r => r.style.display != DisplayStyle.None) ? DisplayStyle.Flex : DisplayStyle.None;
            missionList.scrollOffset = Vector2.zero;
        }

        /// <summary>GameRecord::load: the saved (docked) state, then the station.</summary>
        void LoadSlot(int slot)
        {
            if (slot < 0 || !SaveGame.Load(slot)) return;
            StartCoroutine(Leave("Station"));
        }

        IEnumerator Leave(string scene = null)
        {
            scene ??= gameScene;
            screen = MenuState.Leaving;
            fade.AddToClassList("fade--on");
            StartCoroutine(FadeMusic(0f, 1.2f));
            yield return new WaitForSeconds(1.3f);
            if (Application.CanStreamedLevelBeLoaded(scene)) SceneManager.LoadScene(scene);
            else
            {
                Debug.LogWarning($"MainMenu: scene '{scene}' is not in the build settings.");
                fade.RemoveFromClassList("fade--on");
                screen = MenuState.Menu;
                StartCoroutine(FadeMusic(Settings.MusicVolume, 1f));
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

        /// <summary>The dialog as a notice: one button (the Yes button as OK), no question.</summary>
        void ShowNotice(string title, string text)
        {
            Debug.Log($"MainMenu: notice '{text}'");
            ShowDialog(title, text, null);
            var no = root.Q<Button>("dialogNo");
            var yes = root.Q<Button>("dialogYes");
            no.style.display = DisplayStyle.None;
            yes.text = "OK";
            Select(yes);
        }

        void CloseDialog()
        {
            var no = root.Q<Button>("dialogNo");
            if (no.style.display == DisplayStyle.None)
            {
                no.style.display = StyleKeyword.Null;
                root.Q<Button>("dialogYes").text = Localization.Get(134).ToUpperInvariant();
            }
            dialog.RemoveFromClassList("dialog-backdrop--shown");
            dialogYes = null;
            if (openPanel != null) FocusFirst(openPanel); else Select(exitButton);
        }

        // ---- save slots (RecordHandler: 12 slots, slot 0 = Auto-save; SaveGame) ------------

        void BuildSlots()
        {
            var list = root.Q<ScrollView>("slotList");
            list.Clear();
            var db = Database.Load();
            for (int i = 0; i < SaveGame.SlotCount; i++)
            {
                int slot = i;
                var save = SaveGame.Preview(i);
                var row = SaveSlotRow.Build(db, i, save, Localization.Extra("autosaveHint", "Saved automatically when you dock"));
                row.clicked += () => { Play(buttonPush); if (save != null) LoadSlot(slot); };
                HookFocusSound(row);
                list.Add(row);
            }
        }

        // ---- options ---------------------------------------------------------------------------

        static readonly (string tab, string page)[] OptionPages =
        {
            ("tabSound", "soundPage"), ("tabGraphics", "graphicsPage"), ("tabControls", "controlsPage"), ("tabGameplay", "gameplayPage"),
            ("tabLanguage", "languagePage"),
        };

        static string PageName(OptionPage p) => p switch
        {
            OptionPage.Sound => "soundPage",
            OptionPage.Graphics => "graphicsPage",
            OptionPage.Controls => "controlsPage",
            OptionPage.Language => "languagePage",   // under the language buttons
            _ => "gameplayPage",
        };

        /// <summary>One row per OptionsCatalog entry on its tab, then the language buttons.</summary>
        void SetupOptions()
        {
            optionControls.Clear();
            foreach (var def in OptionsCatalog.All())
            {
                var c = new OptionControl(def);
                c.Field.AddToClassList("option-row");
                HookFocusSound(c.Field);
                if (def.kind == OptionKind.Choice || def.kind == OptionKind.Toggle) c.Changed += () => Play(buttonRelease);
                // Options depend on each other (STP turns MSAA off): every row follows a change.
                c.Changed += () => { foreach (var o in optionControls) if (o != c) o.Refresh(); UpdateDebugButton(); };
                // Original: the FX volume plays a sample on release; remake: the voice volume a voice line.
                if (def.id == "sfx") c.Field.RegisterCallback<PointerCaptureOutEvent>(_ => Play(infoSound));
                if (def.id == "voice") c.Field.RegisterCallback<PointerCaptureOutEvent>(_ => PlayVoicePreview());
                if (def.page == OptionPage.Language) c.Root.AddToClassList("language-voice-row");
                root.Q(PageName(def.page)).Add(c.Root);
                optionControls.Add(c);
            }

            var langList = root.Q("languageList");
            for (int i = 0; i < languageCodes.Length && i < languageNames.Length; i++)
            {
                string code = languageCodes[i];
                var b = new Button { text = languageNames[i], name = "lang_" + code };
                b.AddToClassList("menu-button");
                b.AddToClassList("language-button");
                b.clicked += () => { Play(buttonRelease); Settings.Language = code; LoadLanguage(code); RefreshTexts(); };
                HookFocusSound(b);
                langList.Add(b);
            }
        }

        void SelectTab(string page)
        {
            foreach (var (tab, p) in OptionPages)
            {
                root.Q(tab).EnableInClassList("tab-button--active", p == page);
                root.Q(p).EnableInClassList("tab-page--active", p == page);
            }
        }

        void ApplySettings()
        {
            if (musicSource != null && screen != MenuState.Leaving && !fadingMusic) musicSource.volume = Settings.MusicVolume;
            if (sfxSource != null) sfxSource.volume = Settings.SfxVolume;
            if (voiceSource != null) voiceSource.volume = Settings.VoiceVolume;
        }

        // ---- text ------------------------------------------------------------------------------

        void LoadLanguage(string code)
        {
            int i = Array.IndexOf(languageCodes, code);
            if (i < 0 || languageTables == null || i >= languageTables.Length || languageTables[i] == null) i = 0;
            if (languageTables != null && languageTables.Length > 0) Localization.Load(languageCodes[i], languageTables[i]);
        }

        void RefreshTexts()
        {
            string T(int id) => Localization.Get(id).ToUpperInvariant();
            void Set(string name, string text) { var e = root.Q<TextElement>(name); if (e != null) e.text = text; }

            Set("resumeButton", T(41));
            Set("newGameButton", T(28));
            Set("loadButton", T(29));
            Set("optionsButton", T(31));
            Set("aboutButton", T(43));
            Set("exitButton", T(33));
            Set("debugButton", Localization.Extra("debugButton", "Debug").ToUpperInvariant());
            foreach (var n in new[] { "campaignBack", "difficultyBack", "economyBack", "loadBack", "optionsBack", "aboutBack", "multiplayerBack" }) Set(n, "‹  " + T(170));
            string mp = Localization.Extra("multiplayer", "Multiplayer").ToUpperInvariant();
            Set("multiplayerButton", mp);
            Set("multiplayerTitle", mp);
            Set("mpBadge", Localization.Extra("mpExperimental", "Experimental").ToUpperInvariant());
            Set("mpIntro", Localization.Extra("mpIntro", "One shared universe: meet other pilots in orbits and hangars, form squads and fly bar missions together for a shared reward."));
            Set("mpNameLabel", Localization.Extra("mpNameLabel", "Pilot name").ToUpperInvariant());
            if (mpName != null) mpName.textEdition.placeholder = Localization.Extra("mpNamePlaceholder", "Your pilot name");
            Set("mpHostTitle", Localization.Extra("mpHostTitle", "Host a game").ToUpperInvariant());
            Set("mpHostText", Localization.Extra("mpHostText", "Start a session on this device. Players join with one of your addresses (tap to copy):"));
            Set("mpPortLabel", Localization.Extra("mpPortLabel", "Port").ToUpperInvariant());
            Set("mpHost", Localization.Extra("mpHost", "Host").ToUpperInvariant());
            Set("mpJoinTitle", Localization.Extra("mpJoinTitle", "Join a game").ToUpperInvariant());
            Set("mpJoinText", Localization.Extra("mpJoinText", "Enter the address shown on the host's screen (with :port if it isn't 7777):"));
            if (mpAddress != null) mpAddress.textEdition.placeholder = "192.168.1.20  /  192.168.1.20:7778";
            Set("mpJoin", Localization.Extra("mpJoin", "Join").ToUpperInvariant());

            Set("campaignTitle", T(103));
            Set("debugTitle", Localization.Extra("debugTitle", "Debug").ToUpperInvariant());
            Set("debugBack", "‹  " + T(170));
            Set("debugCheatsTitle", Localization.Extra("debugCheats", "Cheats").ToUpperInvariant());
            Set("debugNote", Localization.Extra("debugNote", "Credits, repair, ammo, energy cells, the map and standing: the Debug page of the pause menu (in flight) and of the station's menu."));
            foreach (var c in debugControls) c.Refresh();
            Set("debugMissionsTitle", Localization.Extra("missionSelect", "Start at mission").ToUpperInvariant());
            if (missionFilter != null) missionFilter.textEdition.placeholder = Localization.Extra("missionSearch", "Search: a step number, a station, a word...");
            Set("difficultyTitle", T(517));
            Set("easyLabel", T(518));
            Set("easyDesc", Localization.Extra("easyDesc", "Weaker enemies in smaller groups, a shorter cloak cooldown and a smaller toll."));
            Set("normalLabel", T(519));
            Set("normalDesc", Localization.Extra("normalDesc", "The classic Galaxy on Fire 2 experience."));
            Set("hardLabel", T(520));
            Set("hardDesc", Localization.Extra("hardDesc", "Tougher, harder-hitting enemies in bigger groups; the economy stays as on Normal."));
            Set("economyTitle", Localization.Extra("economyTitle", "Select the economy").ToUpperInvariant());
            Set("economyDefaultLabel", Session.EconomyName(Economy.Default).ToUpperInvariant());
            Set("economyDefaultDesc", Localization.Extra("economyDefaultDesc",
                "The original prices of the PC, Mac and iPhone versions: cheap commodities, tractor beams and signatures, smaller blueprint recipes, dearer ships."));
            Set("economyAndroidLabel", Session.EconomyName(Economy.Android).ToUpperInvariant());
            Set("economyAndroidDesc", Localization.Extra("economyAndroidDesc",
                "The Android version's prices: commodities, tractor beams, shields and armor far dearer, blueprints need many more ingredients, ships cheaper."));
            Set("extremeLabel", T(25));
            Set("extremeDesc", Localization.Extra("extremeDesc", "For veterans who finished the game: tougher enemies and a harsher economy."));
            Set("loadTitle", T(29));
            Set("optionsTitle", T(31));
            Set("tabSound", OptionsCatalog.PageTitle(OptionPage.Sound).ToUpperInvariant());
            Set("tabGraphics", OptionsCatalog.PageTitle(OptionPage.Graphics).ToUpperInvariant());
            Set("tabControls", OptionsCatalog.PageTitle(OptionPage.Controls).ToUpperInvariant());
            Set("tabGameplay", OptionsCatalog.PageTitle(OptionPage.Gameplay).ToUpperInvariant());
            Set("tabLanguage", T(0));
            Set("optionsDefaults", T(497));
            Set("aboutTitle", T(43));
            Set("dialogYes", T(134));
            Set("dialogNo", T(135));

            foreach (var c in optionControls) c.Refresh();
            foreach (var b in root.Q("languageList").Query<Button>().ToList())
                b.EnableInClassList("language-button--active", b.name == "lang_" + Localization.Language);

            UpdatePressAnyKey();
            versionLabel.text = VersionText;
            hintLabel.text = Localization.Extra("hint", "↑ ↓  NAVIGATE     ENTER  SELECT     ESC  " + T(170));
            var aboutText = root.Q<Label>("aboutText");
            aboutText.text = $"{VersionText}\n\n{AboutText.Get()}\n\n{Localization.Get(48)}";
            AboutText.Hook(aboutText);
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

            if (horizontal && focused is ChoiceRow choiceRow)
            {
                choiceRow.Step(e.direction == NavigationMoveEvent.Direction.Left ? -1 : 1);
                e.StopPropagation();
                root.focusController?.IgnoreEvent(e);
                return;
            }
            if (horizontal && focused is BindingRow bindingRow)
            {
                bindingRow.Step(e.direction == NavigationMoveEvent.Direction.Left ? -1 : 1);
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
            // The difficulty list starts on Normal (the original's first entry), Easy above it; the economy on the last one picked.
            var normal = scope.name == "difficultyPanel" ? scope.Q<Button>("normalButton")
                : scope.name == "economyPanel" ? scope.Q<Button>(Session.Economy == Economy.Android ? "economyAndroidButton" : "economyDefaultButton") : null;
            if (normal != null && items.Contains(normal)) Select(normal);
            else if (items.Count > 0) Select(items[0]);
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
            var clips = Settings.GermanVoices && voicePreviewGerman != null && voicePreviewGerman.Length > 0
                ? voicePreviewGerman : voicePreviewEnglish;
            if (voiceSource == null || clips == null || clips.Length == 0) return;
            voiceSource.Stop();   // one line at a time, a new release restarts it
            voiceSource.clip = clips[voicePreviewIndex++ % clips.Length];
            voiceSource.volume = Settings.VoiceVolume;
            voiceSource.Play();
        }

        void Play(AudioClip clip, float volume = 1f)
        {
            if (clip != null && sfxSource != null) sfxSource.PlayOneShot(clip, volume);
        }
    }
}
