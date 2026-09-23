// GoF2StationMenu.cs
// The docked-station screen (ModStation::OnRender2D 0xef208) over GoF2StationLevel's hangar / Space Lounge:
//   header "<station> Station" (136), left panel with "<system> System" (137), "Tech level: N" (133), the race (406+),
//   the screen buttons Hangar (167: opens the shop window, GoF2HangarWindow, over the 3D hangar) and Space Lounge (398),
//   and the launch button bottom-right with the confirmation "Depart the station?" (397, ChoiceWindow, default = Yes);
//   launching with more cargo than the hold takes is refused (204, ModStation::leaveStation 0xec1ec).
// Dragging over the hangar turns the player's ship (1 rad per 120 px of a 480 px high screen, with a fling);
// a tap in the lounge skips its camera intro. Adapts to GoF2InputMode like the flight HUD:
//   Touch:      buttons, drag to turn the ship, Menu button.
//   Keyboard:   keycap hints; A/D or arrows turn the ship, 1 hangar, 2 lounge, L launch, Esc back.
//   Controller: Xbox hints; right stick turns the ship, LB hangar / RB lounge, X launch, B back, Menu to the main menu.
//   In the hangar window: up / down select, left / right sell / buy, Enter / A confirm, Q / E or LB / RB switch tabs.
// Esc / B: dialog -> no, hangar window / lounge -> main view, main view -> main menu (the original opens its system menu).
// Not yet (the original's other buttons): Map, Missions, Status.

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
        [Header("Hangar sounds (FMOD events 0x65 / 0x64 / 0x62 / 0x60)")]
        public AudioClip shopBuy;
        public AudioClip shopSell;
        public AudioClip shopMount;
        public AudioClip shopDemount;
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
        Label viewTitle, toast;
        GoF2HangarWindow hangarWindow;
        System.Action dialogAction;
        float toastMs;
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
            toast = root.Q<Label>("toast");
            hangarButton = Bind("hangarButton", OpenHangar);
            loungeButton = Bind("loungeButton", OpenLounge);
            launchButton = Bind("launchButton", AskLaunch);
            dialogYes = Bind("dialogYes", () => { var a = dialogAction; CloseDialog(); a?.Invoke(); });
            dialogNo = Bind("dialogNo", CloseDialog);
            hangarWindow = new GoF2HangarWindow(this, level, root);
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
            dialogNo.text = T(135).ToUpperInvariant();
            root.Q<Button>("menuButton").text = GoF2Localization.Extra("hudMenu", "MENU");

            HookDrag();
            root.RegisterCallback<PointerDownEvent>(OnPointerDown, TrickleDown.TrickleDown);
            root.RegisterCallback<PointerMoveEvent>(e => { if (e.pointerType == PointerType.mouse) SetTouchMode(false); }, TrickleDown.TrickleDown);
            root.RegisterCallback<NavigationMoveEvent>(OnNavigate, TrickleDown.TrickleDown);
            // The hangar window keeps its own selection; Enter / A are read in Update, so no button may also take them.
            root.RegisterCallback<NavigationSubmitEvent>(e =>
            {
                if (!HangarOpen || DialogOpen) return;
                e.StopPropagation();
                root.focusController?.IgnoreEvent(e);
            }, TrickleDown.TrickleDown);

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
            bool lounge = level.View == GoF2StationView.Lounge;
            hangarButton.EnableInClassList("station-button--current", HangarOpen);
            loungeButton.EnableInClassList("station-button--current", lounge);
            viewTitle.text = HangarOpen ? GoF2Localization.Get(167).ToUpperInvariant() : lounge ? GoF2Localization.Get(398).ToUpperInvariant() : "";
            viewTitle.style.display = viewTitle.text.Length > 0 ? DisplayStyle.Flex : DisplayStyle.None;
            dragVelocity = 0f;
            BuildHints(GoF2InputMode.Current);
        }

        bool HangarOpen => hangarWindow != null && hangarWindow.IsOpen;

        /// <summary>Station button 0 (ModStation::OnKeyPress): the Hangar window over the main view.</summary>
        void OpenHangar()
        {
            if (HangarOpen || level == null) return;
            if (level.View != GoF2StationView.Hangar) level.SetView(GoF2StationView.Hangar);
            hangarWindow.Open();
            root.AddToClassList("hangar-open");
            if (root.focusController?.focusedElement is VisualElement f) f.Blur();
            OnViewChanged();
        }

        public void CloseHangar()
        {
            if (!HangarOpen) return;
            hangarWindow.Close();
            root.RemoveFromClassList("hangar-open");
            OnViewChanged();
            Select(hangarButton);
        }

        void OpenLounge()
        {
            CloseHangar();
            level?.SetView(GoF2StationView.Lounge);
        }

        /// <summary>ModStation::leaveStation: refused while the cargo hold is overloaded (204), else "Depart the station?".</summary>
        void AskLaunch()
        {
            if (new GoF2Hangar(level.Database, level.Stock).Overloaded) { ShowDialog(GoF2Localization.Get(204), null, true); return; }
            ShowDialog(GoF2Localization.Get(397), level.Launch);
        }

        /// <summary>ChoiceWindow: yes / no, or a message with one button ('info').</summary>
        public void ShowDialog(string text, System.Action onYes, bool info = false)
        {
            dialogAction = onYes;
            root.Q<Label>("dialogText").text = text;
            dialogYes.text = info ? GoF2Localization.Extra("ok", "OK") : GoF2Localization.Get(134).ToUpperInvariant();
            dialogNo.style.display = info ? DisplayStyle.None : DisplayStyle.Flex;
            dialog.AddToClassList("station-dialog-backdrop--shown");
            Play(infoSound);
            if (root.focusController?.focusedElement is VisualElement f) f.Blur();
            Select(dialogYes);
        }

        void CloseDialog()
        {
            dialog.RemoveFromClassList("station-dialog-backdrop--shown");
            dialogAction = null;
            if (!HangarOpen) Select(launchButton);
            else if (root.focusController?.focusedElement is VisualElement f) f.Blur();
        }

        bool DialogOpen => dialog != null && dialog.ClassListContains("station-dialog-backdrop--shown");

        /// <summary>A short message at the top ("#N mounted.", "You need an additional #C." ...), 3 s.</summary>
        public void ShowToast(string text)
        {
            toast.text = text;
            toast.AddToClassList("station-toast--shown");
            toastMs = 3000f;
        }

        public void PlayPush() => Play(buttonPush);
        public void PlayRelease() => Play(buttonRelease);
        public void PlayClip(AudioClip clip) => Play(clip);

        void Back()
        {
            if (DialogOpen) { Play(buttonRelease); CloseDialog(); }
            else if (HangarOpen) { Play(buttonRelease); CloseHangar(); }
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
            if (kind == GoF2InputKind.Gamepad && !HangarOpen && root.focusController?.focusedElement == null)
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
            if (HangarOpen && !DialogOpen)
            {
                // Read in Update (HoldDirections): navigation events only arrive while a UI element has focus.
                e.StopPropagation();
                root.focusController?.IgnoreEvent(e);
                return;
            }
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
            if (HangarOpen)
            {
                string select = T("hudSelect", "SELECT"), trade = $"{T("shopSell", "SELL")} / {T("shopBuy", "BUY")}";
                string tabs = $"{GoF2Localization.Get(183)} / {GoF2Localization.Get(185)}".ToUpperInvariant(), confirm = T("hudConfirm", "CONFIRM");
                if (kind == GoF2InputKind.KeyboardMouse)
                {
                    Hint(select, GoF2InputGlyph.Key("W"), GoF2InputGlyph.Key("S"));
                    Hint(trade, GoF2InputGlyph.Key("A"), GoF2InputGlyph.Key("D"));
                    Hint(confirm, GoF2InputGlyph.Key("ENTER", true));
                    Hint(tabs, GoF2InputGlyph.Key("Q"), GoF2InputGlyph.Key("E"));
                    Hint(T("hudBack", "BACK"), GoF2InputGlyph.Key("ESC"));
                }
                else if (kind == GoF2InputKind.Gamepad)
                {
                    Hint($"{select} / {trade}", GoF2InputGlyph.Pad(GoF2PadButton.DPad));
                    Hint(confirm, GoF2InputGlyph.Pad(GoF2PadButton.A));
                    Hint(tabs, GoF2InputGlyph.Pad(GoF2PadButton.LeftBumper), GoF2InputGlyph.Pad(GoF2PadButton.RightBumper));
                    Hint(T("hudBack", "BACK"), GoF2InputGlyph.Pad(GoF2PadButton.B));
                }
                return;
            }
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
            if (toastMs > 0f && (toastMs -= Time.unscaledDeltaTime * 1000f) <= 0f) toast.RemoveFromClassList("station-toast--shown");
            if (DialogOpen) return;

            if (HangarOpen)
            {
                float dtMs = Time.unscaledDeltaTime * 1000f;
                int v = 0, h = 0;
                if (kb != null)
                {
                    if (kb.wKey.isPressed || kb.upArrowKey.isPressed) v -= 1;
                    if (kb.sKey.isPressed || kb.downArrowKey.isPressed) v += 1;
                    if (kb.aKey.isPressed || kb.leftArrowKey.isPressed) h -= 1;
                    if (kb.dKey.isPressed || kb.rightArrowKey.isPressed) h += 1;
                }
                if (pad != null)
                {
                    var stick = pad.leftStick.ReadValue() + pad.dpad.ReadValue();
                    if (stick.y > 0.5f) v -= 1; else if (stick.y < -0.5f) v += 1;
                    if (stick.x < -0.5f) h -= 1; else if (stick.x > 0.5f) h += 1;
                }
                hangarWindow.HoldDirections(System.Math.Sign(v), System.Math.Sign(h), dtMs);
                hangarWindow.Update(dtMs);
                if ((kb != null && (kb.enterKey.wasPressedThisFrame || kb.numpadEnterKey.wasPressedThisFrame)) || (pad != null && pad.buttonSouth.wasPressedThisFrame))
                    hangarWindow.Action();
                else if ((kb != null && (kb.qKey.wasPressedThisFrame || kb.eKey.wasPressedThisFrame))
                         || (pad != null && (pad.leftShoulder.wasPressedThisFrame || pad.rightShoulder.wasPressedThisFrame)))
                {
                    Play(buttonPush);
                    hangarWindow.NextTab();
                }
                else if (kb != null && kb.digit2Key.wasPressedThisFrame) OpenLounge();
                return;
            }

            if ((kb != null && kb.digit1Key.wasPressedThisFrame) || (pad != null && pad.leftShoulder.wasPressedThisFrame))
                OpenHangar();
            if ((kb != null && kb.digit2Key.wasPressedThisFrame) || (pad != null && pad.rightShoulder.wasPressedThisFrame))
                OpenLounge();
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
