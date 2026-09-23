// GoF2StationMenu.cs
// The docked-station screen (ModStation::OnRender2D 0xef208) over GoF2StationLevel's hangar / Space Lounge:
//   header "<station> Station" (136), left panel with "<system> System" (137), "Tech level: N" (133), the race (406+),
//   the screen buttons Hangar (167, the main station view here) and Space Lounge (398), and the launch button
//   bottom-right with the confirmation "Depart the station?" (397, ChoiceWindow, default = Yes).
// Dragging over the hangar turns the player's ship (1 rad per 120 px of a 480 px high screen, with a fling);
// a tap in the lounge skips its camera intro. Adapts to GoF2InputMode like the flight HUD:
//   Touch:      buttons, drag to turn the ship, Menu button.
//   Keyboard:   keycap hints; A/D or arrows turn the ship, 1 / 2 switch screens, L launch, Esc back.
//   Controller: Xbox hints; right stick turns the ship, LB / RB switch screens, X launch, B back, Menu to the main menu.
// Esc / B: dialog -> no, lounge -> hangar, hangar -> main menu (the original opens its system menu there).
// Not yet (the original's other buttons): the 2D shop behind "Hangar", Map, Missions, Status.

using GoF2Remake.Data;
using GoF2Remake.World;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.SceneManagement;
using UnityEngine.UIElements;
using PointerType = UnityEngine.UIElements.PointerType;

namespace GoF2Remake.UI
{
    [RequireComponent(typeof(PanelRenderer))]
    public class GoF2StationMenu : MonoBehaviour
    {
        public GoF2StationLevel level;
        public string menuScene = "MainMenu";
        [Header("Audio (FMOD events 124 / 123 / 126)")]
        public AudioSource sfxSource;
        public AudioClip buttonPush;
        public AudioClip buttonRelease;
        public AudioClip infoSound;
        [Header("Text (used when the scene is started without the main menu)")]
        public string[] languageCodes;
        public TextAsset[] languageTables;
        [Header("Turning the ship")]
        [Tooltip("Keyboard / controller turn speed, game radians per second.")]
        public float keyTurnSpeed = 1.6f;

        PanelRenderer panelRenderer;
        PanelSettings runtimePanel;
        VisualElement root, safeArea, dragZone, hints, dialog;
        Button hangarButton, loungeButton, launchButton, dialogYes, dialogNo;
        Label viewTitle;
        Vector2Int lastScreen;
        Rect lastSafeArea;
        bool touchMode;

        int dragPointer = -1;
        float dragLastX, dragLastTime, dragVelocity;   // velocity in game rad/s, sampled per frame
        float dragFrameRadians;                         // turned since the last frame (touch can send several moves per frame)
        const float MaxFling = 25f;                     // rad/s

        void OnEnable()
        {
            panelRenderer = GetComponent<PanelRenderer>();
            panelRenderer.RegisterUIReloadCallback(OnUIReload);
            if (runtimePanel == null && panelRenderer.panelSettings != null)
            {
                runtimePanel = Instantiate(panelRenderer.panelSettings);
                panelRenderer.panelSettings = runtimePanel;
            }
            GoF2InputMode.Changed += ApplyInputMode;
            if (level != null) level.ViewChanged += OnViewChanged;
        }

        void OnDisable()
        {
            panelRenderer?.UnregisterUIReloadCallback(OnUIReload);
            GoF2InputMode.Changed -= ApplyInputMode;
            if (level != null) level.ViewChanged -= OnViewChanged;
        }

        void OnUIReload(PanelRenderer renderer, VisualElement rootElement, int version)
        {
            if (!GoF2Localization.IsLoaded && languageTables != null && languageTables.Length > 0)
            {
                int i = languageCodes != null ? System.Array.IndexOf(languageCodes, GoF2Settings.Language) : -1;
                if (i < 0) i = 0;
                GoF2Localization.Load(languageCodes != null && i < languageCodes.Length ? languageCodes[i] : "en", languageTables[i]);
            }
            root = rootElement;
            root.style.flexGrow = 1;
            root.pickingMode = PickingMode.Ignore;
            safeArea = root.Q("safeArea");
            dragZone = root.Q("dragZone");
            hints = root.Q("hints");
            dialog = root.Q("dialog");
            viewTitle = root.Q<Label>("viewTitle");
            hangarButton = Bind("hangarButton", () => level?.SetView(GoF2StationView.Hangar));
            loungeButton = Bind("loungeButton", () => level?.SetView(GoF2StationView.Lounge));
            launchButton = Bind("launchButton", AskLaunch);
            dialogYes = Bind("dialogYes", () => { CloseDialog(); level?.Launch(); });
            dialogNo = Bind("dialogNo", CloseDialog);
            Bind("menuButton", BackToMenu);

            var st = level != null ? level.Station : null;
            string T(int id) => GoF2Localization.Get(id);
            root.Q<Label>("stationTitle").text = st == null ? "" :
                (st.index == 101 ? st.name : $"{st.name} {T(136)}").ToUpperInvariant();   // no suffix for station 101
            root.Q<Label>("systemName").text = st == null ? "" : $"{st.systemName} {T(137)}";
            root.Q<Label>("techLevel").text = st == null ? "" : $"{T(133)}: {st.techLevel}";
            int race = level != null ? level.Layout.raceId : -1;
            var raceLabel = root.Q<Label>("raceName");
            raceLabel.text = race >= 0 && race < 4 ? T(406 + race) : "";
            raceLabel.style.display = raceLabel.text.Length > 0 ? DisplayStyle.Flex : DisplayStyle.None;
            hangarButton.text = T(167).ToUpperInvariant();
            loungeButton.text = T(398).ToUpperInvariant();
            launchButton.text = GoF2Localization.Extra("stationLaunch", "LAUNCH");
            root.Q<Label>("dialogText").text = T(397);
            dialogYes.text = T(134).ToUpperInvariant();
            dialogNo.text = T(135).ToUpperInvariant();
            root.Q<Button>("menuButton").text = GoF2Localization.Extra("hudMenu", "MENU");

            HookDrag();
            root.RegisterCallback<PointerDownEvent>(OnPointerDown, TrickleDown.TrickleDown);
            root.RegisterCallback<PointerMoveEvent>(e => { if (e.pointerType == PointerType.mouse) SetTouchMode(false); }, TrickleDown.TrickleDown);
            root.RegisterCallback<NavigationMoveEvent>(OnNavigate, TrickleDown.TrickleDown);

            OnViewChanged();
            ApplyInputMode();
            UpdateLayout();
        }

        Button Bind(string name, System.Action action)
        {
            var b = root.Q<Button>(name);
            b.RegisterCallback<PointerDownEvent>(_ => Play(buttonPush), TrickleDown.TrickleDown);
            b.clicked += () => { Play(buttonRelease); action(); };
            return b;
        }

        // ---- screens -----------------------------------------------------------------------------------

        void OnViewChanged()
        {
            if (root == null || level == null) return;
            bool hangar = level.View == GoF2StationView.Hangar;
            hangarButton.EnableInClassList("station-button--current", hangar);
            loungeButton.EnableInClassList("station-button--current", !hangar);
            viewTitle.text = GoF2Localization.Get(hangar ? 167 : 398).ToUpperInvariant();
            dragVelocity = 0f;
            BuildHints(GoF2InputMode.Current);
        }

        void AskLaunch()
        {
            dialog.AddToClassList("station-dialog-backdrop--shown");
            Play(infoSound);
            Select(dialogYes);
        }

        void CloseDialog()
        {
            dialog.RemoveFromClassList("station-dialog-backdrop--shown");
            Select(launchButton);
        }

        bool DialogOpen => dialog != null && dialog.ClassListContains("station-dialog-backdrop--shown");

        void Back()
        {
            if (DialogOpen) { Play(buttonRelease); CloseDialog(); }
            else if (level != null && level.View == GoF2StationView.Lounge) { Play(buttonRelease); level.SetView(GoF2StationView.Hangar); }
            else BackToMenu();
        }

        void BackToMenu()
        {
            if (Application.CanStreamedLevelBeLoaded(menuScene)) SceneManager.LoadScene(menuScene);
        }

        // ---- turning the ship (ModStation::OnTouchMove / OnTouchEnd) ----------------------------------------

        /// <summary>Panel units per game radian: the original's 120 px on a 480 px high screen, a quarter of the height.</summary>
        float UnitsPerRadian => Mathf.Max(1f, root.layout.height) * (GoF2StationTables.TurntablePixelsPerRadian / 480f);

        void HookDrag()
        {
            dragZone.RegisterCallback<PointerDownEvent>(e =>
            {
                if (level == null || dragPointer >= 0) return;
                if (level.View == GoF2StationView.Lounge) { level.SkipIntro(); return; }   // OnTouchEnd case 0: jump to B
                dragPointer = e.pointerId;
                dragZone.CapturePointer(e.pointerId);
                dragLastX = e.position.x;
                dragLastTime = Time.unscaledTime;
                dragVelocity = dragFrameRadians = 0f;
                level.RotateShip(0f);   // stops a fling
            });
            dragZone.RegisterCallback<PointerMoveEvent>(e =>
            {
                if (e.pointerId != dragPointer) return;
                float rad = (e.position.x - dragLastX) / UnitsPerRadian;
                level.RotateShip(rad);
                dragFrameRadians += rad;
                dragLastX = e.position.x;
                dragLastTime = Time.unscaledTime;
            });
            dragZone.RegisterCallback<PointerUpEvent>(e => EndDrag(e.pointerId, true));
            dragZone.RegisterCallback<PointerCancelEvent>(e => EndDrag(e.pointerId, false));
        }

        void EndDrag(int pointerId, bool fling)
        {
            if (pointerId != dragPointer) return;
            if (dragZone.HasPointerCapture(dragPointer)) dragZone.ReleasePointer(dragPointer);
            dragPointer = -1;
            // OnTouchEnd: fling only if the finger was still moving (the original: last dx > 3 px).
            bool moving = Time.unscaledTime - dragLastTime < 0.08f;
            float minSpeed = 3f / GoF2StationTables.TurntablePixelsPerRadian / 0.02f;
            if (fling && moving && Mathf.Abs(dragVelocity) > minSpeed) level.FlingShip(Mathf.Clamp(dragVelocity, -MaxFling, MaxFling));
        }

        // ---- input mode, focus and navigation -------------------------------------------------------------

        void ApplyInputMode()
        {
            if (root == null) return;
            var kind = GoF2InputMode.Current;
            root.EnableInClassList("input-touch", kind == GoF2InputKind.Touch);
            root.EnableInClassList("input-keyboard", kind == GoF2InputKind.KeyboardMouse);
            root.EnableInClassList("input-gamepad", kind == GoF2InputKind.Gamepad);
            SetTouchMode(kind == GoF2InputKind.Touch);
            if (kind == GoF2InputKind.Gamepad && root.focusController?.focusedElement == null)
                Select(DialogOpen ? dialogYes : level != null && level.View == GoF2StationView.Lounge ? loungeButton : hangarButton);
            BuildHints(kind);
        }

        // Touch has no hover and shouldn't leave a focus highlight on what the finger pressed (see GoF2MainMenu).
        void SetTouchMode(bool on)
        {
            touchMode = on;
            root.EnableInClassList("can-hover", !on);
            if (on && root.focusController?.focusedElement is VisualElement focused) focused.Blur();
        }

        void OnPointerDown(PointerDownEvent e)
        {
            if (e.pointerType == PointerType.mouse) { SetTouchMode(false); return; }
            SetTouchMode(true);
            root.focusController?.IgnoreEvent(e);
        }

        void Select(VisualElement e)
        {
            if (!touchMode) e?.Focus();
        }

        /// <summary>Up/down walks the screen buttons and launch (left/right: yes/no in the dialog); left/right otherwise
        /// stay free for turning the ship.</summary>
        void OnNavigate(NavigationMoveEvent e)
        {
            SetTouchMode(false);
            bool vertical = e.direction == NavigationMoveEvent.Direction.Up || e.direction == NavigationMoveEvent.Direction.Down;
            bool horizontal = e.direction == NavigationMoveEvent.Direction.Left || e.direction == NavigationMoveEvent.Direction.Right;
            var items = DialogOpen ? new VisualElement[] { dialogYes, dialogNo } : new VisualElement[] { hangarButton, loungeButton, launchButton };
            if (DialogOpen ? horizontal : vertical)
            {
                var focused = root.focusController?.focusedElement as VisualElement;
                int i = System.Array.IndexOf(items, focused);
                int step = e.direction == NavigationMoveEvent.Direction.Up || e.direction == NavigationMoveEvent.Direction.Left ? -1 : 1;
                items[i < 0 ? 0 : Mathf.Clamp(i + step, 0, items.Length - 1)].Focus();
            }
            e.StopPropagation();
            root.focusController?.IgnoreEvent(e);
        }

        void BuildHints(GoF2InputKind kind)
        {
            if (hints == null) return;
            hints.Clear();
            string T(string key, string english) => GoF2Localization.Extra(key, english);
            bool hangar = level == null || level.View == GoF2StationView.Hangar;
            string rotate = T("stationRotate", "TURN SHIP"), launch = T("stationLaunch", "LAUNCH");
            string back = hangar ? T("hudMenu", "MENU") : T("hudBack", "BACK");
            if (kind == GoF2InputKind.KeyboardMouse)
            {
                if (hangar) Hint(rotate, GoF2InputGlyph.Key("A"), GoF2InputGlyph.Key("D"));
                Hint(GoF2Localization.Get(167).ToUpperInvariant(), GoF2InputGlyph.Key("1"));
                Hint(GoF2Localization.Get(398).ToUpperInvariant(), GoF2InputGlyph.Key("2"));
                Hint(launch, GoF2InputGlyph.Key("L"));
                Hint(back, GoF2InputGlyph.Key("ESC"));
            }
            else if (kind == GoF2InputKind.Gamepad)
            {
                if (hangar) Hint(rotate, GoF2InputGlyph.Pad(GoF2PadButton.RightStick));
                Hint($"{GoF2Localization.Get(167)} / {GoF2Localization.Get(398)}".ToUpperInvariant(),
                     GoF2InputGlyph.Pad(GoF2PadButton.LeftBumper), GoF2InputGlyph.Pad(GoF2PadButton.RightBumper));
                Hint(launch, GoF2InputGlyph.Pad(GoF2PadButton.X));
                Hint(T("hudBack", "BACK"), GoF2InputGlyph.Pad(GoF2PadButton.B));
                Hint(T("hudMenu", "MENU"), GoF2InputGlyph.Pad(GoF2PadButton.Menu));
            }
        }

        void Hint(string label, params VisualElement[] glyphs)
        {
            var h = new VisualElement { pickingMode = PickingMode.Ignore };
            h.AddToClassList("hint");
            foreach (var g in glyphs) h.Add(g);
            var l = new Label(label) { pickingMode = PickingMode.Ignore };
            l.AddToClassList("hint-label");
            l.AddToClassList("gof-semibold");
            h.Add(l);
            hints.Add(h);
        }

        // ---- per frame -----------------------------------------------------------------------------------

        void Update()
        {
            if (root == null || level == null) return;
            if (lastScreen != ScreenSize() || lastSafeArea != Screen.safeArea) UpdateLayout();

            var kb = Keyboard.current;
            var pad = Gamepad.current;
            if ((kb != null && kb.escapeKey.wasPressedThisFrame) || (pad != null && pad.buttonEast.wasPressedThisFrame)) { Back(); return; }
            if (pad != null && pad.startButton.wasPressedThisFrame) { BackToMenu(); return; }
            if (DialogOpen) return;

            if ((kb != null && kb.digit1Key.wasPressedThisFrame) || (pad != null && pad.leftShoulder.wasPressedThisFrame))
                level.SetView(GoF2StationView.Hangar);
            if ((kb != null && kb.digit2Key.wasPressedThisFrame) || (pad != null && pad.rightShoulder.wasPressedThisFrame))
                level.SetView(GoF2StationView.Lounge);
            if ((kb != null && kb.lKey.wasPressedThisFrame) || (pad != null && pad.buttonWest.wasPressedThisFrame))
            {
                Play(buttonRelease);
                AskLaunch();
                return;
            }

            if (dragPointer >= 0)
            {
                // Release velocity: the turn per frame, smoothed (the original uses the last frame's dx).
                dragVelocity = Mathf.Lerp(dragVelocity, dragFrameRadians / Mathf.Max(Time.unscaledDeltaTime, 1e-3f), 0.6f);
                dragFrameRadians = 0f;
            }
            else if (level.View == GoF2StationView.Hangar)
            {
                float turn = 0f;
                if (kb != null)
                {
                    if (kb.aKey.isPressed || kb.leftArrowKey.isPressed) turn -= 1f;
                    if (kb.dKey.isPressed || kb.rightArrowKey.isPressed) turn += 1f;
                }
                if (pad != null && Mathf.Abs(pad.rightStick.x.ReadValue()) > 0.15f) turn += pad.rightStick.x.ReadValue();
                if (turn != 0f) level.RotateShip(Mathf.Clamp(turn, -1f, 1f) * keyTurnSpeed * Time.deltaTime);
            }
            else if (level.IntroPlaying && ((kb != null && kb.anyKey.wasPressedThisFrame) || (pad != null && pad.buttonSouth.wasPressedThisFrame)))
                level.SkipIntro();
        }

        void Play(AudioClip clip)
        {
            if (sfxSource != null && clip != null) sfxSource.PlayOneShot(clip, GoF2Settings.SfxVolume);
        }

        // ---- layout (same scaling and safe-area handling as the flight HUD) ---------------------------------

        Vector2Int ScreenSize()
        {
            var rt = runtimePanel != null ? runtimePanel.targetTexture : null;
            return rt != null ? new Vector2Int(rt.width, rt.height) : new Vector2Int(Screen.width, Screen.height);
        }

        void UpdateLayout()
        {
            lastScreen = ScreenSize();
            lastSafeArea = Screen.safeArea;
            bool offscreen = runtimePanel != null && runtimePanel.targetTexture != null;
            float w = Mathf.Max(1, lastScreen.x), h = Mathf.Max(1, lastScreen.y);
            float inches = Screen.dpi > 0f ? Mathf.Sqrt(w * w + h * h) / Screen.dpi : 20f;
            bool phone = Application.isMobilePlatform && inches < 7.5f;
            if (runtimePanel != null)
            {
                runtimePanel.referenceResolution = phone ? new Vector2Int(1600, 900) : new Vector2Int(1920, 1080);
                runtimePanel.screenMatchMode = PanelScreenMatchMode.MatchWidthOrHeight;
                runtimePanel.match = 1f;
            }
            root.EnableInClassList("layout-phone", phone);
            ApplySafeArea(w, h, offscreen);
        }

        /// <summary>Device safe-area insets; retries until the panel has a real (non-NaN) size, see GoF2FlightHud.</summary>
        void ApplySafeArea(float w, float h, bool offscreen)
        {
            root.schedule.Execute(() =>
            {
                if (safeArea == null) return;
                if (!(root.layout.width > 0f)) { ApplySafeArea(w, h, offscreen); return; }
                float k = root.layout.width / w;
                var raw = offscreen ? new Rect(0f, 0f, w, h) : Screen.safeArea;
                var sa = Rect.MinMaxRect(Mathf.Clamp(raw.xMin, 0f, w), Mathf.Clamp(raw.yMin, 0f, h),
                                         Mathf.Clamp(raw.xMax, 0f, w), Mathf.Clamp(raw.yMax, 0f, h));
                if (sa.width < w * 0.5f || sa.height < h * 0.5f) sa = new Rect(0f, 0f, w, h);
                safeArea.style.left = sa.xMin * k;
                safeArea.style.right = (w - sa.xMax) * k;
                safeArea.style.top = (h - sa.yMax) * k;
                safeArea.style.bottom = sa.yMin * k;
            }).ExecuteLater(1);
        }
    }
}
