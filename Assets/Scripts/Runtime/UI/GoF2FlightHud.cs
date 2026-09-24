// GoF2FlightHud.cs
// In-flight HUD (UI Toolkit) that adapts to the input in use (GoF2InputMode):
//   Touch:      floating stick on the left half (steer), throttle slider on the right edge (the original's touch
//               throttle is a vertical drag too, MGame::OnTouchMove), Fire (hold), Missile (fires on release, like
//               MGame::OnTouchEnd), Boost and Level buttons, a Menu button.
//   Keyboard:   keycap hints (WASD, Q/E, Ctrl, F, Space, R, Esc).
//   Controller: Xbox button hints (LS, LB/RB, RT, LT, A, Y, Menu).
// Always: speed, throttle and boost readout, and the crosshair: the screen projection of ship + forward * 22000
// units (where the bullets are after 22000 units), orange for 200 ms after a hit (weapons.md section 9). The chase camera uses the original's fixed touch-mode damping for
// touch and the handling-dependent damping otherwise (TargetFollowCamera::resetShipHandling / setShipHandling).
// Esc, the Android back button or the controller's Menu button returns to the main menu (no pause menu yet).
// One action prompt (tap it, Enter, or the controller's X): "Mine" with a locked asteroid, "Abort" during the
// autopilot approach, "Stop mining" in the minigame (GoF2Mining, the original's fire button), else "Dock" near the
// station (GoF2SpaceLevel.CanDock). GoF2MiningView draws the lock ring, the ore plate, HUD messages and the minigame.
// The autopilot button (touch), Tab or the controller's View button opens the autopilot menu (game paused): pick an entry
// by tap / click, W/S + Enter or D-pad + A; Esc / B / the same button closes it.
// The star map (GoF2StarMap) covers everything while open; jump scenes and docking to the gate hide the HUD
// (GoF2SystemJump.Cinematic); the Khador Drive's charge shows as a bar; after a gate / Khador jump the arrival camera shows
// the orbit information (Hud::drawOrbitInformation: race logo, station, "<System> System", security level).
// Combat (GoF2CombatView): ship / crate markers, the ship lock plate, the player's shield / hull / armor bars and hit arcs;
// radio and salvage messages; after the player's death the "Game Over" screen (319) with "Tap to load last savegame."
// (196) 7 s later, which reloads the last docked state (GoF2Session.LoadAutosave), or the main menu without one (199).

using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.World;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.SceneManagement;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    [RequireComponent(typeof(PanelRenderer))]
    public class GoF2FlightHud : MonoBehaviour
    {
        public string menuScene = "MainMenu";
        [Tooltip("Stick travel in panel units (the base is twice this wide in the USS).")]
        public float stickRadius = 110f;

        PanelRenderer panelRenderer;
        PanelSettings runtimePanel;
        VisualElement root, safeArea, hints, throttleTrack, throttleFill, throttleHandle, throttleBarFill, boostBarFill, boostButton, boostCharge, levelButton;
        VisualElement fireButton, missileButton, crosshair, dockPrompt, dockGlyph;
        Label dockLabel;
        GoF2SpaceLevel level;
        GoF2Mining mining;
        GoF2MiningView miningView;
        GoF2Mining.Phase lastPhase;
        GoF2Navigation nav;
        GoF2NavigationView navView;
        GoF2SystemJump jump;
        GoF2CombatView combatView;
        GoF2PlayerHealth health;
        GoF2CombatRadar radar;
        GoF2Traffic traffic;
        GoF2StorySpace story;
        GoF2DialogueView storyDialogue;
        AudioSource voiceSource;
        VisualElement radioBox, radioPortrait;
        Label radioSpeaker, radioText;
        int radioShown = -1;
        VisualElement gameOver;
        Label gameOverText;
        float gameOverMs = -1f;
        VisualElement jumpCharge, jumpChargeFill, orbitInfo;
        bool orbitInfoFilled;
        bool lastAutopilot;
        VisualElement autopilotMenu, autopilotMenuItems;
        readonly System.Collections.Generic.List<(Button button, GoF2Navigation.Target target)> menuButtons = new System.Collections.Generic.List<(Button, GoF2Navigation.Target)>();
        int menuIndex, lastMenuMove, menuOpenedFrame;
        Label speedValue, missileAmmo;
        GoF2WeaponSystem weapons;
        float hitFlashMs;
        const float CrosshairDistanceMeters = 22000f * 0.05f;   // 0x46abe000
        GoF2TouchStick stick;
        GoF2ShipController ship;
        GoF2ChaseCamera chase;
        Vector2Int lastScreen;
        Rect lastSafeArea;
        int throttlePointer = -1;

        void OnEnable()
        {
            panelRenderer = GetComponent<PanelRenderer>();
            panelRenderer.RegisterUIReloadCallback(OnUIReload);   // before the panel settings swap, which reloads
            if (runtimePanel == null && panelRenderer.panelSettings != null)
            {
                runtimePanel = Instantiate(panelRenderer.panelSettings);   // per-scene scaling (phone reference)
                panelRenderer.panelSettings = runtimePanel;
            }
            GoF2InputMode.Changed += ApplyInputMode;
        }

        void OnDisable()
        {
            if (mining != null) mining.Message -= OnMiningMessage;
            if (nav != null) nav.Message -= OnMiningMessage;
            if (jump != null) jump.Message -= OnMiningMessage;
            if (traffic != null) traffic.Message -= OnMiningMessage;
            if (radar != null) radar.Message -= OnCombatMessage;
            if (health != null) health.GameOverStarted -= OnGameOver;
            panelRenderer?.UnregisterUIReloadCallback(OnUIReload);
            GoF2InputMode.Changed -= ApplyInputMode;
        }

        void OnUIReload(PanelRenderer renderer, VisualElement rootElement, int version)
        {
            root = rootElement;
            root.style.flexGrow = 1;   // no default theme to stretch the document root
            root.pickingMode = PickingMode.Ignore;
            safeArea = root.Q("safeArea");
            hints = root.Q("hints");
            throttleTrack = root.Q("throttleTrack");
            throttleFill = root.Q("throttleFill");
            throttleHandle = root.Q("throttleHandle");
            throttleBarFill = root.Q("throttleBarFill");
            boostBarFill = root.Q("boostBarFill");
            boostButton = root.Q("boostButton");
            boostCharge = root.Q("boostCharge");
            levelButton = root.Q("levelButton");
            speedValue = root.Q<Label>("speedValue");
            fireButton = root.Q("fireButton");
            missileButton = root.Q("missileButton");
            missileAmmo = root.Q<Label>("missileAmmo");
            crosshair = root.Q("crosshair");
            dockPrompt = root.Q("dockPrompt");
            dockGlyph = root.Q("dockGlyph");
            dockLabel = root.Q<Label>("dockLabel");
            jumpCharge = root.Q("jumpCharge");
            jumpChargeFill = root.Q("jumpChargeFill");
            orbitInfo = root.Q("orbitInfo");
            root.Q<Label>("jumpChargeLabel").text = GoF2Localization.Get(1359).ToUpperInvariant();   // Khador Drive
            orbitInfoFilled = false;

            stick = new GoF2TouchStick(root.Q("stickZone"), root.Q("stickBase"), root.Q("stickKnob"), root.Q("stickGhost"), stickRadius);
            HookThrottle();
            HookPress(boostButton, () => ship?.Boost());
            HookPress(levelButton, () => ship?.AlignToHorizon());
            HookPress(fireButton, () => weapons?.SetPrimaryHeld(true), () => weapons?.SetPrimaryHeld(false));
            HookPress(missileButton, null, () => weapons?.FireSecondary());
            HookPress(dockPrompt, null, Interact);
            miningView = new GoF2MiningView(root);
            navView = new GoF2NavigationView(root);
            combatView = new GoF2CombatView(root);
            root.Q("storyDialogue").pickingMode = PickingMode.Ignore;
            if (voiceSource == null)
            {
                voiceSource = gameObject.AddComponent<AudioSource>();
                voiceSource.playOnAwake = false;
                voiceSource.spatialBlend = 0f;
                voiceSource.ignoreListenerPause = true;
            }
            storyDialogue = new GoF2DialogueView(root, voiceSource);
            radioBox = root.Q("radio");
            radioPortrait = root.Q("radioPortrait");
            radioSpeaker = root.Q<Label>("radioSpeaker");
            radioText = root.Q<Label>("radioText");
            radioShown = -1;
            gameOver = root.Q("gameOver");
            gameOverText = root.Q<Label>("gameOverText");
            root.Q<Label>("gameOverTitle").text = GoF2Localization.Get(319).ToUpperInvariant();   // Game Over
            gameOver.RegisterCallback<PointerDownEvent>(_ => LoadLastSave());
            navView.AutopilotButton += OnAutopilotButton;
            autopilotMenu = root.Q("autopilotMenu");
            autopilotMenuItems = root.Q("autopilotMenuItems");
            root.Q<Label>("autopilotMenuTitle").text = GoF2Localization.Get(571).ToUpperInvariant();   // Autopilot
            var menuIcon = Resources.Load<Texture2D>("GoF2Hud/autopilot_title");
            if (menuIcon != null) root.Q("autopilotMenuIcon").style.backgroundImage = new StyleBackground(menuIcon);
            root.Q<Button>("menuButton").clicked += BackToMenu;

            root.Q<Label>("stickCaption").text = GoF2Localization.Extra("hudSteer", "STEER");
            root.Q<Label>("boostCaption").text = GoF2Localization.Extra("hudBoost", "BOOST");
            root.Q<Label>("levelCaption").text = GoF2Localization.Extra("hudLevel", "LEVEL");
            root.Q<Label>("fireCaption").text = GoF2Localization.Extra("hudFire", "FIRE");
            root.Q<Label>("missileCaption").text = GoF2Localization.Extra("hudMissile", "MISSILE");
            root.Q<Label>("speedUnit").text = "M/S";
            root.Q<Button>("menuButton").text = GoF2Localization.Extra("hudMenu", "MENU");
            root.Q<Label>("dockLabel").text = GoF2Localization.Extra("hudDock", "DOCK");

            ApplyInputMode();
            UpdateLayout();
        }

        // ---- touch controls ------------------------------------------------------------------------------

        void HookThrottle()
        {
            throttleTrack.RegisterCallback<PointerDownEvent>(e =>
            {
                if (throttlePointer >= 0) return;
                throttlePointer = e.pointerId;
                throttleTrack.CapturePointer(e.pointerId);
                SetThrottleFrom(e.localPosition.y);
                e.StopPropagation();
            });
            throttleTrack.RegisterCallback<PointerMoveEvent>(e =>
            {
                if (e.pointerId != throttlePointer) return;
                SetThrottleFrom(e.localPosition.y);
                e.StopPropagation();
            });
            EventCallback<IPointerEvent> end = e =>
            {
                if (e.pointerId != throttlePointer) return;
                if (throttleTrack.HasPointerCapture(throttlePointer)) throttleTrack.ReleasePointer(throttlePointer);
                throttlePointer = -1;
            };
            throttleTrack.RegisterCallback<PointerUpEvent>(e => end(e));
            throttleTrack.RegisterCallback<PointerCancelEvent>(e => end(e));
        }

        void SetThrottleFrom(float localY)
        {
            float h = throttleTrack.contentRect.height;
            if (h > 0f) ship?.SetThrottle(1f - Mathf.Clamp01(localY / h));
        }

        /// <summary>'down' runs on press, 'up' on release; shows a pressed state while the finger stays down.</summary>
        static void HookPress(VisualElement button, System.Action down, System.Action up = null)
        {
            int pointer = -1;
            button.RegisterCallback<PointerDownEvent>(e =>
            {
                if (pointer >= 0) return;
                pointer = e.pointerId;
                button.CapturePointer(pointer);
                button.AddToClassList("touch-button--pressed");
                down?.Invoke();
                e.StopPropagation();
            });
            void Up(int id)
            {
                if (id != pointer) return;
                if (button.HasPointerCapture(pointer)) button.ReleasePointer(pointer);
                pointer = -1;
                button.RemoveFromClassList("touch-button--pressed");
                up?.Invoke();
            }
            button.RegisterCallback<PointerUpEvent>(e => Up(e.pointerId));
            button.RegisterCallback<PointerCancelEvent>(e => Up(e.pointerId));
        }

        // ---- input mode ------------------------------------------------------------------------------------

        void ApplyInputMode()
        {
            if (root == null) return;
            var kind = GoF2InputMode.Current;
            root.EnableInClassList("input-touch", kind == GoF2InputKind.Touch);
            root.EnableInClassList("input-keyboard", kind == GoF2InputKind.KeyboardMouse);
            root.EnableInClassList("input-gamepad", kind == GoF2InputKind.Gamepad);
            if (kind != GoF2InputKind.Touch) { stick?.Release(); weapons?.SetPrimaryHeld(false); }
            if (chase != null) chase.handlingDependent = kind != GoF2InputKind.Touch;
            BuildHints(kind);
            dockGlyph.Clear();
            if (kind == GoF2InputKind.KeyboardMouse) dockGlyph.Add(GoF2InputGlyph.Key("ENTER", true));
            else if (kind == GoF2InputKind.Gamepad) dockGlyph.Add(GoF2InputGlyph.Pad(GoF2PadButton.X));
        }

        void BuildHints(GoF2InputKind kind)
        {
            hints.Clear();
            string T(string key, string english) => GoF2Localization.Extra(key, english);
            if (nav != null && nav.MenuOpen)
            {
                if (kind == GoF2InputKind.KeyboardMouse)
                {
                    Hint(T("hudSelect", "SELECT"), GoF2InputGlyph.Key("W"), GoF2InputGlyph.Key("S"));
                    Hint(T("hudConfirm", "CONFIRM"), GoF2InputGlyph.Key("ENTER", true));
                    Hint(T("hudBack", "BACK"), GoF2InputGlyph.Key("ESC"));
                }
                else if (kind == GoF2InputKind.Gamepad)
                {
                    Hint(T("hudSelect", "SELECT"), GoF2InputGlyph.Pad(GoF2PadButton.DPad));
                    Hint(T("hudConfirm", "CONFIRM"), GoF2InputGlyph.Pad(GoF2PadButton.A));
                    Hint(T("hudBack", "BACK"), GoF2InputGlyph.Pad(GoF2PadButton.B));
                }
                return;
            }
            if (lastAutopilot)
            {
                // Autopilot: throttle, boost and guns still work; fast-forward is held.
                string ff = T("hudFastForward", "FAST FORWARD"), off = T("hudAutopilotOff", "AUTOPILOT OFF");
                if (kind == GoF2InputKind.KeyboardMouse)
                {
                    Hint(T("hudThrottle", "THROTTLE"), GoF2InputGlyph.Key("Q"), GoF2InputGlyph.Key("E"));
                    Hint(ff + " (" + T("hudHold", "HOLD") + ")", GoF2InputGlyph.Key("R"));
                    Hint(off, GoF2InputGlyph.Key("ENTER", true));
                    Hint(T("hudFire", "FIRE"), GoF2InputGlyph.Key("CTRL"));
                    Hint(T("hudMenu", "MENU"), GoF2InputGlyph.Key("ESC"));
                }
                else if (kind == GoF2InputKind.Gamepad)
                {
                    Hint(T("hudThrottle", "THROTTLE"), GoF2InputGlyph.Pad(GoF2PadButton.LeftBumper), GoF2InputGlyph.Pad(GoF2PadButton.RightBumper));
                    Hint(ff + " (" + T("hudHold", "HOLD") + ")", GoF2InputGlyph.Pad(GoF2PadButton.Y));
                    Hint(off, GoF2InputGlyph.Pad(GoF2PadButton.X));
                    Hint(T("hudFire", "FIRE"), GoF2InputGlyph.Pad(GoF2PadButton.RightTrigger));
                    Hint(T("hudMenu", "MENU"), GoF2InputGlyph.Pad(GoF2PadButton.Menu));
                }
                return;
            }
            if (lastPhase != GoF2Mining.Phase.Idle)
            {
                // Autopilot to an asteroid / mining: only the drill and the action prompt matter.
                bool drilling = lastPhase == GoF2Mining.Phase.Mining;
                string action = drilling ? T("hudMiningStop", "STOP MINING") : T("hudMiningAbort", "ABORT");
                if (kind == GoF2InputKind.KeyboardMouse)
                {
                    if (drilling) Hint(T("hudDrill", "DRILL"), GoF2InputGlyph.Key("W"), GoF2InputGlyph.Key("A"), GoF2InputGlyph.Key("S"), GoF2InputGlyph.Key("D"));
                    if (lastPhase == GoF2Mining.Phase.Approaching) Hint(T("hudFastForward", "FAST FORWARD") + " (" + T("hudHold", "HOLD") + ")", GoF2InputGlyph.Key("R"));
                    Hint(action, GoF2InputGlyph.Key("ENTER", true));
                }
                else if (kind == GoF2InputKind.Gamepad)
                {
                    if (drilling) Hint(T("hudDrill", "DRILL"), GoF2InputGlyph.Pad(GoF2PadButton.LeftStick));
                    if (lastPhase == GoF2Mining.Phase.Approaching) Hint(T("hudFastForward", "FAST FORWARD") + " (" + T("hudHold", "HOLD") + ")", GoF2InputGlyph.Pad(GoF2PadButton.Y));
                    Hint(action, GoF2InputGlyph.Pad(GoF2PadButton.X));
                }
                return;
            }
            if (kind == GoF2InputKind.KeyboardMouse)
            {
                Hint(T("hudSteer", "STEER"), GoF2InputGlyph.Key("W"), GoF2InputGlyph.Key("A"), GoF2InputGlyph.Key("S"), GoF2InputGlyph.Key("D"));
                Hint(T("hudThrottle", "THROTTLE"), GoF2InputGlyph.Key("Q"), GoF2InputGlyph.Key("E"));
                Hint(T("hudFire", "FIRE"), GoF2InputGlyph.Key("CTRL"));
                Hint(T("hudMissile", "MISSILE"), GoF2InputGlyph.Key("F"));
                Hint(T("hudBoost", "BOOST"), GoF2InputGlyph.Key("SPACE", true));
                Hint(T("hudLevel", "LEVEL"), GoF2InputGlyph.Key("R"));
                Hint(GoF2Localization.Get(571).ToUpperInvariant(), GoF2InputGlyph.Key("TAB"));
                Hint(T("hudMenu", "MENU"), GoF2InputGlyph.Key("ESC"));
            }
            else if (kind == GoF2InputKind.Gamepad)
            {
                Hint(T("hudSteer", "STEER"), GoF2InputGlyph.Pad(GoF2PadButton.LeftStick));
                Hint(T("hudThrottle", "THROTTLE"), GoF2InputGlyph.Pad(GoF2PadButton.LeftBumper), GoF2InputGlyph.Pad(GoF2PadButton.RightBumper));
                Hint(T("hudFire", "FIRE"), GoF2InputGlyph.Pad(GoF2PadButton.RightTrigger));
                Hint(T("hudMissile", "MISSILE"), GoF2InputGlyph.Pad(GoF2PadButton.LeftTrigger));
                Hint(T("hudBoost", "BOOST"), GoF2InputGlyph.Pad(GoF2PadButton.A));
                Hint(T("hudLevel", "LEVEL"), GoF2InputGlyph.Pad(GoF2PadButton.Y));
                Hint(GoF2Localization.Get(571).ToUpperInvariant(), GoF2InputGlyph.Pad(GoF2PadButton.View));
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
            if (root == null) return;
            if (lastScreen != ScreenSize() || lastSafeArea != Screen.safeArea) UpdateLayout();

            bool mapOpen = GoF2StarMap.IsOpen;
            root.EnableInClassList("hud-map", mapOpen);
            if (mapOpen) return;   // the map has its own input

            if (storyDialogue != null && storyDialogue.IsOpen)
            {
                ship?.SetSteer(Vector2.zero);
                storyDialogue.Tick(Time.unscaledDeltaTime * 1000f);
                return;
            }

            if (nav != null && nav.MenuOpen)
            {
                UpdateAutopilotMenu();
                return;
            }

            if ((Keyboard.current != null && Keyboard.current.escapeKey.wasPressedThisFrame)
                || (Gamepad.current != null && Gamepad.current.startButton.wasPressedThisFrame))
            {
                BackToMenu();
                return;
            }
            if (nav != null && ((Keyboard.current != null && Keyboard.current.tabKey.wasPressedThisFrame)
                                || (Gamepad.current != null && Gamepad.current.selectButton.wasPressedThisFrame)))
                OnAutopilotButton();

            if (ship == null)
            {
                level = FindAnyObjectByType<GoF2SpaceLevel>();
                ship = level != null ? level.Player : null;
                if (ship == null) return;
                weapons = level.Weapons;
                mining = level.Mining;
                if (mining != null) mining.Message += OnMiningMessage;
                nav = level.Navigation;
                if (nav != null) nav.Message += OnMiningMessage;
                jump = level.SystemJump;
                if (jump != null) jump.Message += OnMiningMessage;
                health = level.Health;
                radar = level.Radar;
                traffic = level.Traffic;
                if (traffic != null) traffic.Message += OnMiningMessage;
                if (radar != null) radar.Message += OnCombatMessage;
                if (health != null) health.GameOverStarted += OnGameOver;
                story = level.Story;
                if (story != null)
                {
                    story.DialogueRequested += (pages, closed) => { stick?.Release(); weapons?.SetPrimaryHeld(false); storyDialogue.Show(pages, closed); };
                    story.MessageRequested += (text, speaker, closed) => { stick?.Release(); weapons?.SetPrimaryHeld(false); storyDialogue.ShowMessage(text, speaker, closed); };
                }
                if (weapons != null) weapons.Hit += () => hitFlashMs = 200f;
                chase = Camera.main != null ? Camera.main.GetComponent<GoF2ChaseCamera>() : null;
                ApplyInputMode();
            }

            if (health != null && health.Dead)
            {
                // Dead: no HUD, no controls (PlayerEgo::explode); then the game-over screen.
                root.EnableInClassList("hud-cinematic", true);
                dockPrompt.EnableInClassList("dock-prompt--hidden", true);
                ship.SetSteer(Vector2.zero);
                UpdateGameOver();
                return;
            }

            // The action prompt: navigation (autopilot / jump) first, then mining (lock / approach / minigame), else docking.
            string prompt = nav != null ? nav.PromptText : null;
            if (prompt == null && mining != null) prompt = mining.PromptText;
            if (prompt == null && level.CanDock) prompt = GoF2Localization.Extra("hudDock", "DOCK");
            dockPrompt.EnableInClassList("dock-prompt--hidden", prompt == null);
            if (prompt != null) dockLabel.text = prompt;
            if (prompt != null && ((Keyboard.current != null && (Keyboard.current.enterKey.wasPressedThisFrame || Keyboard.current.numpadEnterKey.wasPressedThisFrame))
                                   || (Gamepad.current != null && Gamepad.current.buttonWest.wasPressedThisFrame)))
            {
                Interact();
                if (level == null || !level.isActiveAndEnabled) return;
            }

            var phase = mining != null ? mining.State : GoF2Mining.Phase.Idle;
            bool autopilot = nav != null && nav.Autopilot;
            if (phase != lastPhase || autopilot != lastAutopilot) { lastPhase = phase; lastAutopilot = autopilot; BuildHints(GoF2InputMode.Current); }
            root.EnableInClassList("hud-cinematic", (nav != null && nav.Jumping) || (jump != null && jump.Cinematic));   // jumps: no HUD
            jumpCharge.EnableInClassList("jump-charge--shown", jump != null && jump.Charging);
            if (jump != null && jump.Charging) jumpChargeFill.style.width = Length.Percent(jump.ChargeRate * 100f);
            UpdateOrbitInfo();
            // Fast-forward: the touch button, or hold R / controller Y (MGame key 0x100, hold-to-use).
            bool ffHeld = navView.FastForwardPressed
                          || (Keyboard.current != null && Keyboard.current.rKey.isPressed)
                          || (Gamepad.current != null && Gamepad.current.buttonNorth.isPressed);
            nav?.SetFastForwardHeld(ffHeld);
            root.EnableInClassList("hud-docking", phase != GoF2Mining.Phase.Idle);
            root.EnableInClassList("hud-mining", phase == GoF2Mining.Phase.Mining);
            var touchStick = GoF2InputMode.Current == GoF2InputKind.Touch && stick != null ? stick.Value : Vector2.zero;
            ship.SetSteer(touchStick);
            mining?.SetTouchInput(touchStick);

            var model = ship.Model;
            float throttle = model.Throttle;
            speedValue.text = Mathf.RoundToInt(ship.SpeedMetersPerSecond).ToString();
            throttleBarFill.style.width = Length.Percent(throttle * 100f);
            throttleFill.style.height = Length.Percent(throttle * 100f);
            throttleHandle.style.bottom = Length.Percent(throttle * 100f);

            // Recharge 0..1; empty while boosting, and when there is no booster at all (never ready, nothing recharging).
            float boost = model.IsBoosting ? 0f : Mathf.Clamp01(model.BoostRechargePercent);
            if (!model.BoostReady && !model.IsBoosting && boost >= 1f) boost = 0f;
            boostBarFill.style.width = Length.Percent(boost * 100f);
            boostCharge.style.height = Length.Percent(boost * 100f);
            boostButton.EnableInClassList("touch-button--disabled", !model.BoostReady && !model.IsBoosting);

            // Weapons: missile button with its ammo (hidden without a secondary), crosshair and hit flash.
            int ammo = weapons != null ? weapons.SecondaryAmmo : -1;
            missileButton.EnableInClassList("touch-button--hidden", ammo < 0);
            missileButton.EnableInClassList("touch-button--disabled", ammo == 0);
            missileAmmo.text = ammo >= 0 ? ammo.ToString() : "";
            fireButton.EnableInClassList("touch-button--hidden", weapons == null || !weapons.HasPrimary);
            UpdateCrosshair();
            miningView.UpdateLock(mining, crosshair.style.left, crosshair.style.top, !crosshair.ClassListContains("crosshair--hidden") && phase == GoF2Mining.Phase.Idle);
            miningView.UpdateGame(mining, Time.deltaTime * 1000f);
            var lockRing = root.Q("lockRing");
            lockRing.style.left = crosshair.style.left;
            lockRing.style.top = crosshair.style.top;
            navView.Update(nav, Camera.main, GoF2InputMode.Current == GoF2InputKind.Touch, phase,
                           level.Layout.raceId, level.SystemJumpgateStation, level.StationInfo != null ? level.StationInfo.techLevel : 0);
            bool cinematic = (nav != null && nav.Jumping) || (jump != null && jump.Cinematic);
            bool plateFree = (nav == null || nav.Locked == null) && (mining == null || (mining.State == GoF2Mining.Phase.Idle && mining.Locked == null));
            combatView.Update(radar, traffic, health, Camera.main, cinematic, plateFree);
            UpdateRadio();
        }

        /// <summary>Radio::draw: the campaign level's current radio line (portrait, name, text; its voice once).</summary>
        void UpdateRadio()
        {
            var radio = level != null && level.Campaign != null ? level.Campaign.Radio : null;
            var line = radio?.Visible;
            int index = radio != null ? radio.VisibleIndex : -1;
            radioBox.EnableInClassList("radio--shown", line != null);
            if (line == null || index == radioShown) { if (line == null) radioShown = -1; return; }
            radioShown = index;
            radioSpeaker.text = GoF2StoryTable.SpeakerName(line.speaker).ToUpperInvariant();
            radioText.text = GoF2Localization.Get(line.text);
            GoF2Portrait.Show(radioPortrait, GoF2StoryTable.Portrait(line.speaker), false);
            var clip = GoF2StoryAssets.Load()?.Voice(line.voice);
            if (clip != null && voiceSource != null) { voiceSource.clip = clip; voiceSource.volume = GoF2Settings.VoiceVolume; voiceSource.Play(); }
        }

        /// <summary>The autopilot button (HUD key 0x40, MGame::OnTouchEnd): turns the autopilot off, cancels an asteroid
        /// approach, or opens / closes the autopilot menu.</summary>
        void OnAutopilotButton()
        {
            if (nav == null) return;
            if (nav.MenuOpen) CloseAutopilotMenu();
            else if (nav.Autopilot) nav.Interact();
            else if (mining != null && mining.State == GoF2Mining.Phase.Approaching) mining.Interact();
            else if (nav.CanOpenMenu) OpenAutopilotMenu();
        }

        // ---- autopilot menu (Hud::initHudMenu(3)) --------------------------------------------------------------

        void OpenAutopilotMenu()
        {
            nav.OpenMenu();
            if (!nav.MenuOpen) return;
            stick?.Release();
            weapons?.SetPrimaryHeld(false);
            autopilotMenuItems.Clear();
            menuButtons.Clear();
            foreach (var t in nav.MenuEntries())
            {
                var target = t;
                var b = new Button { text = t.name.ToUpperInvariant() };
                b.AddToClassList("autopilot-menu-item");
                b.AddToClassList("gof-semibold");
                b.focusable = false;
                b.clicked += () => { nav.ChooseMenuEntry(target); HideAutopilotMenu(); };
                autopilotMenuItems.Add(b);
                menuButtons.Add((b, target));
            }
            menuIndex = 0;
            lastMenuMove = 0;
            menuOpenedFrame = Time.frameCount;
            autopilotMenu.AddToClassList("autopilot-menu--shown");
            HighlightMenu();
            BuildHints(GoF2InputMode.Current);
        }

        void CloseAutopilotMenu()
        {
            nav?.CloseMenu();
            HideAutopilotMenu();
        }

        void HideAutopilotMenu()
        {
            autopilotMenu.RemoveFromClassList("autopilot-menu--shown");
            BuildHints(GoF2InputMode.Current);
        }

        void HighlightMenu()
        {
            bool keys = GoF2InputMode.Current != GoF2InputKind.Touch;
            for (int i = 0; i < menuButtons.Count; i++) menuButtons[i].button.EnableInClassList("autopilot-menu-item--selected", keys && i == menuIndex);
        }

        /// <summary>While the menu is open (game paused): keys / D-pad pick, Esc / B / Tab / View close.</summary>
        void UpdateAutopilotMenu()
        {
            var kb = Keyboard.current;
            var pad = Gamepad.current;
            // The press that opened the menu can still read as "pressed this frame" on the next frame (editor input
            // updates): ignore the toggle keys for two frames.
            if (Time.frameCount - menuOpenedFrame < 2) return;
            if ((kb != null && (kb.escapeKey.wasPressedThisFrame || kb.tabKey.wasPressedThisFrame))
                || (pad != null && (pad.buttonEast.wasPressedThisFrame || pad.selectButton.wasPressedThisFrame || pad.startButton.wasPressedThisFrame)))
            {
                CloseAutopilotMenu();
                return;
            }
            int move = 0;
            if (kb != null && (kb.wKey.wasPressedThisFrame || kb.upArrowKey.wasPressedThisFrame)) move = -1;
            if (kb != null && (kb.sKey.wasPressedThisFrame || kb.downArrowKey.wasPressedThisFrame)) move = 1;
            if (pad != null)
            {
                var v = pad.dpad.ReadValue() + pad.leftStick.ReadValue();
                int dir = v.y > 0.5f ? -1 : v.y < -0.5f ? 1 : 0;
                if (dir != 0 && dir != lastMenuMove) move = dir;
                lastMenuMove = dir;
            }
            if (move != 0 && menuButtons.Count > 0)
            {
                menuIndex = (menuIndex + move + menuButtons.Count) % menuButtons.Count;
                HighlightMenu();
            }
            bool confirm = (kb != null && (kb.enterKey.wasPressedThisFrame || kb.numpadEnterKey.wasPressedThisFrame))
                           || (pad != null && (pad.buttonSouth.wasPressedThisFrame || pad.buttonWest.wasPressedThisFrame));
            if (confirm && menuIndex < menuButtons.Count)
            {
                nav.ChooseMenuEntry(menuButtons[menuIndex].target);
                HideAutopilotMenu();
            }
        }

        void OnMiningMessage(string text) => miningView?.ShowMessage(text);
        void OnCombatMessage(string text, int colour) => miningView?.ShowMessage(text, colour);

        // ---- game over (MGame game-over state) ------------------------------------------------------------

        void OnGameOver()
        {
            gameOverMs = 0f;
            gameOver.AddToClassList("game-over--shown");
            gameOverText.text = GoF2Localization.Get(GoF2Session.HasAutosave ? 196 : 199);
        }

        /// <summary>Overlay fades in after 3000 ms over 4000 ms, then the blinking "Tap to load last savegame.".</summary>
        void UpdateGameOver()
        {
            if (gameOverMs < 0f) return;
            gameOverMs += Time.unscaledDeltaTime * 1000f;
            gameOver.EnableInClassList("game-over--dim", gameOverMs > 3000f);
            bool ready = gameOverMs > 7000f;
            gameOverText.EnableInClassList("game-over-text--shown", ready && (int)(gameOverMs / 500f) % 2 == 0);
            if (ready && ((Keyboard.current != null && Keyboard.current.anyKey.wasPressedThisFrame)
                          || (Gamepad.current != null && (Gamepad.current.buttonSouth.wasPressedThisFrame || Gamepad.current.startButton.wasPressedThisFrame))))
                LoadLastSave();
        }

        /// <summary>GameRecord::load(last save) -> the station; no save -> the main menu.</summary>
        void LoadLastSave()
        {
            if (gameOverMs < 7000f) return;
            gameOverMs = -1f;
            if (GoF2Session.LoadAutosave() && Application.CanStreamedLevelBeLoaded("Station")) SceneManager.LoadScene("Station");
            else BackToMenu();
        }

        /// <summary>Hud::drawOrbitInformation during the arrival camera after a gate / Khador jump.</summary>
        void UpdateOrbitInfo()
        {
            bool show = level != null && level.OrbitInfoVisible;
            orbitInfo.EnableInClassList("orbit-info--shown", show);
            root.EnableInClassList("hud-orbit-info", show);   // it takes the speed panel's corner
            if (!show || orbitInfoFilled) return;
            orbitInfoFilled = true;
            var st = level.StationInfo;
            int system = level.Layout.systemIndex, race = level.Layout.raceId;
            bool owned = GoF2GalaxyMap.HasOwner(system) && race >= 0 && race <= 3;
            var logo = orbitInfo.Q("orbitLogo");
            var tex = owned ? Resources.Load<Texture2D>($"GoF2Hud/logo_{race}") : null;
            logo.style.display = tex != null ? DisplayStyle.Flex : DisplayStyle.None;
            if (tex != null) { logo.style.backgroundImage = new StyleBackground(tex); logo.style.width = tex.width; logo.style.height = tex.height; }
            orbitInfo.Q<Label>("orbitStation").text = st == null ? "" : st.index == 101 ? st.name : $"{st.name} {GoF2Localization.Get(136)}";
            orbitInfo.Q<Label>("orbitSystem").text = st == null ? "" : $"{st.systemName} {GoF2Localization.Get(137)}";
            int sec = Mathf.Clamp(level.Database.Systems.Find(s => s.index == system)?.securityLevel ?? 0, 0, 3);
            var secLabel = orbitInfo.Q<Label>("orbitSecurity");
            secLabel.text = GoF2Localization.Get(402 + sec);
            secLabel.style.color = (Color)GoF2GalaxyMap.SecurityColours[sec];
        }

        /// <summary>The action prompt: mining (mine / abort / stop) when it has something to do, else dock.</summary>
        void Interact()
        {
            if (nav != null && nav.PromptText != null) nav.Interact();
            else if (mining != null && mining.PromptText != null) mining.Interact();
            else Dock();
        }

        /// <summary>The panel's pixel size: the screen, or the target texture when rendering offscreen (tests).</summary>
        Vector2Int ScreenSize()
        {
            var rt = runtimePanel != null ? runtimePanel.targetTexture : null;
            return rt != null ? new Vector2Int(rt.width, rt.height) : new Vector2Int(Screen.width, Screen.height);
        }

        void UpdateCrosshair()
        {
            var cam = Camera.main;
            if (cam == null || crosshair.panel == null) return;
            var aim = ship.transform.position + ship.transform.forward * CrosshairDistanceMeters;
            bool visible = Vector3.Dot(aim - cam.transform.position, cam.transform.forward) > 0f;
            crosshair.EnableInClassList("crosshair--hidden", !visible);
            if (!visible) return;
            var p = RuntimePanelUtils.CameraTransformWorldToPanel(crosshair.panel, aim, cam);
            var parent = crosshair.parent.worldBound;
            crosshair.style.left = p.x - parent.x;
            crosshair.style.top = p.y - parent.y;
            if (hitFlashMs > 0f) hitFlashMs -= Time.deltaTime * 1000f;
            crosshair.EnableInClassList("crosshair--hit", hitFlashMs > 0f);
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

        /// <summary>
        /// Device safe-area insets (pixels -> panel units). Needs the panel's laid-out size, which is NaN on the first
        /// frame: until then it retries every frame (a NaN inset collapses the HUD into the top-left corner).
        /// </summary>
        void ApplySafeArea(float w, float h, bool offscreen)
        {
            root.schedule.Execute(() =>
            {
                if (safeArea == null) return;
                if (!(root.layout.width > 0f)) { ApplySafeArea(w, h, offscreen); return; }   // also catches NaN
                float k = root.layout.width / w;
                // Screen.safeArea can reach past Screen.width/height on some phones (display cutouts / insets):
                // clamp it to the screen, or negative insets push right- and bottom-anchored controls off-screen.
                var raw = offscreen ? new Rect(0f, 0f, w, h) : Screen.safeArea;
                var sa = Rect.MinMaxRect(Mathf.Clamp(raw.xMin, 0f, w), Mathf.Clamp(raw.yMin, 0f, h),
                                         Mathf.Clamp(raw.xMax, 0f, w), Mathf.Clamp(raw.yMax, 0f, h));
                if (sa.width < w * 0.5f || sa.height < h * 0.5f) sa = new Rect(0f, 0f, w, h);   // nonsense: ignore
                safeArea.style.left = sa.xMin * k;
                safeArea.style.right = (w - sa.xMax) * k;
                safeArea.style.top = (h - sa.yMax) * k;
                safeArea.style.bottom = sa.yMin * k;
                Debug.Log($"GoF2FlightHud: screen {w}x{h}, safe area {raw} -> {sa}, panel {root.layout.size}, input {GoF2InputMode.Current}");
            }).ExecuteLater(1);
        }

        void Dock()
        {
            if (level != null && level.CanDock) level.Dock();
        }

        void BackToMenu()
        {
            if (Application.CanStreamedLevelBeLoaded(menuScene)) SceneManager.LoadScene(menuScene);
        }
    }
}
