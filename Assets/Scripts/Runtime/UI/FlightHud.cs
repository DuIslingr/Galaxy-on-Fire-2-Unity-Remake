// FlightHud.cs
// In-flight HUD (UI Toolkit) that adapts to the input in use (InputMode):
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
// autopilot approach, "Stop mining" in the minigame (Mining, the original's fire button), else "Dock" near the
// station (SpaceLevel.CanDock). MiningView draws the lock ring, the ore plate, HUD messages and the minigame.
// The autopilot button (touch), Tab or the controller's View button opens the autopilot menu (game paused): pick an entry
// by tap / click, W/S + Enter or D-pad + A; Esc / B / the same button closes it.
// The star map (StarMap) covers everything while open; jump scenes and docking to the gate hide the HUD
// (SystemJump.Cinematic); the Khador Drive's charge shows as a bar; after a gate / Khador jump the arrival camera shows
// the orbit information (Hud::drawOrbitInformation: race logo, station, "<System> System", security level).
// Combat (CombatView): ship / crate markers, the ship lock plate, the player's shield / hull / armor bars and hit arcs;
// radio and salvage messages; after the player's death the "Game Over" screen (319) with "Tap to load last savegame."
// (196) 7 s later, which reloads the last docked state (Session.LoadAutosave), or the main menu without one (199).

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
    public class FlightHud : MonoBehaviour
    {
        public string menuScene = "MainMenu";
        [Tooltip("Stick travel in panel units (the base is twice this wide in the USS).")]
        public float stickRadius = 110f;

        PanelRenderer panelRenderer;
        PanelSettings runtimePanel;
        VisualElement turretButton;
        Label turretCaption;
        bool lastTurretView, lastTurretAuto;
        VisualElement root, safeArea, hints, throttleTrack, throttleFill, throttleHandle, throttleBarFill, boostBarFill, boostButton, boostCharge, levelButton;
        VisualElement fireButton, missileButton, crosshair, dockPrompt, dockGlyph;
        Label dockLabel;
        SpaceLevel level;
        Mining mining;
        MiningView miningView;
        ObjectDocking docking;
        HackingView hackingView;
        Label transferCounter;
        Mining.Phase lastPhase;
        Navigation nav;
        NavigationView navView;
        SystemJump jump;
        CombatView combatView;
        PlayerHealth health;
        CombatRadar radar;
        Traffic traffic;
        StorySpace story;
        DialogueView storyDialogue;
        LensFlareView lensFlare;
        PauseMenu pauseMenu;
        Button introSkip;
        InputKind introSkipKind;
        GoF2Remake.World.FreelanceOrbit freelance;
        AudioSource voiceSource;
        VisualElement radioBox, radioPortrait, screenFade;
        Label radioSpeaker, radioText;
        int radioShown = -1;
        Traffic.Chatter shownChatter;
        VisualElement gameOver;
        Label gameOverText;
        float gameOverMs = -1f;
        VisualElement jumpCharge, jumpChargeFill, orbitInfo;
        Label jumpChargeLabel;
        bool lastCloakCharging;
        bool orbitInfoFilled;
        bool lastAutopilot;
        VisualElement autopilotMenu, autopilotMenuItems;
        readonly System.Collections.Generic.List<(Button button, Navigation.Target target)> menuButtons = new System.Collections.Generic.List<(Button, Navigation.Target)>();
        int menuIndex, lastMenuMove, menuOpenedFrame;
        Label speedValue, missileAmmo, secondaryLabel;
        WeaponSystem weapons;
        float hitFlashMs;
        const float CrosshairDistanceMeters = 22000f * 0.05f;   // 0x46abe000
        TouchStick stick;
        ShipController ship;
        ChaseCamera chase;
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
            InputMode.Changed += ApplyInputMode;
        }

        void OnDisable()
        {
            pauseMenu?.Close();   // the scene is going: sounds and time back to normal
            if (mining != null) mining.Message -= OnMiningMessage;
            if (docking != null) docking.Message -= OnMiningMessage;
            if (nav != null) nav.Message -= OnMiningMessage;
            if (jump != null) jump.Message -= OnMiningMessage;
            if (traffic != null) traffic.Message -= OnMiningMessage;
            if (radar != null) radar.Message -= OnCombatMessage;
            if (health != null) health.GameOverStarted -= OnGameOver;
            panelRenderer?.UnregisterUIReloadCallback(OnUIReload);
            InputMode.Changed -= ApplyInputMode;
        }

        void OnUIReload(PanelRenderer renderer, VisualElement rootElement, int version)
        {
            root = rootElement;
            root.style.flexGrow = 1;   // no default theme to stretch the document root
            root.pickingMode = PickingMode.Ignore;
            safeArea = root.Q("safeArea");
            hints = root.Q("hints");
            InputGlyph.TrackHintsOption(hints);
            throttleTrack = root.Q("throttleTrack");
            throttleFill = root.Q("throttleFill");
            throttleHandle = root.Q("throttleHandle");
            throttleBarFill = root.Q("throttleBarFill");
            boostBarFill = root.Q("boostBarFill");
            boostButton = root.Q("boostButton");
            boostCharge = root.Q("boostCharge");
            levelButton = root.Q("levelButton");
            turretButton = root.Q("turretButton");
            turretCaption = root.Q<Label>("turretCaption");
            speedValue = root.Q<Label>("speedValue");
            fireButton = root.Q("fireButton");
            missileButton = root.Q("missileButton");
            missileAmmo = root.Q<Label>("missileAmmo");
            secondaryLabel = root.Q<Label>("secondaryLabel");
            // Remake: a tap on the secondary's name switches to the next mounted one (the original's HUD quick menu).
            secondaryLabel?.RegisterCallback<PointerDownEvent>(e => { weapons?.CycleSecondary(); e.StopPropagation(); });
            crosshair = root.Q("crosshair");
            dockPrompt = root.Q("dockPrompt");
            dockGlyph = root.Q("dockGlyph");
            dockLabel = root.Q<Label>("dockLabel");
            jumpCharge = root.Q("jumpCharge");
            jumpChargeFill = root.Q("jumpChargeFill");
            orbitInfo = root.Q("orbitInfo");
            jumpChargeLabel = root.Q<Label>("jumpChargeLabel");
            jumpChargeLabel.text = Localization.Get(1359).ToUpperInvariant();   // Khador Drive
            orbitInfoFilled = false;

            stick = new TouchStick(root.Q("stickZone"), root.Q("stickBase"), root.Q("stickKnob"), root.Q("stickGhost"), stickRadius);
            HookThrottle();
            HookPress(boostButton, () => ship?.Boost());
            HookPress(levelButton, () => ship?.AlignToHorizon());
            HookPress(turretButton, () => level?.Turret?.Toggle());
            HookPress(fireButton, () => weapons?.SetPrimaryHeld(true), () => weapons?.SetPrimaryHeld(false));
            HookPress(missileButton, null, () => weapons?.FireSecondary());
            HookPress(dockPrompt, null, Interact);
            miningView = new MiningView(root);
            hackingView = new HackingView(root);
            transferCounter = new Label { pickingMode = PickingMode.Ignore };
            transferCounter.AddToClassList("transfer-counter");
            transferCounter.AddToClassList("gof-semibold");
            transferCounter.AddToClassList("transfer-counter--hidden");
            root.Add(transferCounter);
            navView = new NavigationView(root);
            combatView = new CombatView(root);
            lensFlare = new LensFlareView(root);
            root.Q("storyDialogue").pickingMode = PickingMode.Ignore;
            if (voiceSource == null)
            {
                voiceSource = gameObject.AddComponent<AudioSource>();
                voiceSource.playOnAwake = false;
                voiceSource.spatialBlend = 0f;
                voiceSource.ignoreListenerPause = true;
            }
            storyDialogue = new DialogueView(root, voiceSource);
            pauseMenu?.Close();   // a UI reload rebuilds it: don't leave the game paused
            pauseMenu = new PauseMenu(root, BackToMenu);
            // Remake-only: skip the prologue / rescue (the original's unreachable skip branches, IntroCutscenes.Skip).
            introSkip = new Button { focusable = false };
            introSkip.AddToClassList("intro-skip");
            introSkip.clicked += SkipIntro;
            root.Add(introSkip);
            introSkipKind = (InputKind)(-1);
            radioBox = root.Q("radio");
            screenFade = root.Q("screenFade");
            radioPortrait = root.Q("radioPortrait");
            radioSpeaker = root.Q<Label>("radioSpeaker");
            radioText = root.Q<Label>("radioText");
            radioShown = -1;
            gameOver = root.Q("gameOver");
            gameOverText = root.Q<Label>("gameOverText");
            root.Q<Label>("gameOverTitle").text = Localization.Get(319).ToUpperInvariant();   // Game Over
            gameOver.RegisterCallback<PointerDownEvent>(_ => LoadLastSave());
            navView.AutopilotButton += OnAutopilotButton;
            autopilotMenu = root.Q("autopilotMenu");
            autopilotMenuItems = root.Q("autopilotMenuItems");
            root.Q<Label>("autopilotMenuTitle").text = Localization.Get(571).ToUpperInvariant();   // Autopilot
            var menuIcon = Resources.Load<Texture2D>("GoF2Hud/autopilot_title");
            if (menuIcon != null) root.Q("autopilotMenuIcon").style.backgroundImage = new StyleBackground(menuIcon);
            root.Q<Button>("menuButton").clicked += OpenPause;

            root.Q<Label>("stickCaption").text = Localization.Extra("hudSteer", "STEER");
            root.Q<Label>("boostCaption").text = Localization.Extra("hudBoost", "BOOST");
            root.Q<Label>("levelCaption").text = Localization.Extra("hudLevel", "LEVEL");
            root.Q<Label>("fireCaption").text = Localization.Extra("hudFire", "FIRE");
            root.Q<Label>("missileCaption").text = Localization.Extra("hudMissile", "MISSILE");
            root.Q<Label>("speedUnit").text = "M/S";
            root.Q<Button>("menuButton").text = Localization.Extra("hudMenu", "MENU");
            root.Q<Label>("dockLabel").text = Localization.Extra("hudDock", "DOCK");

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
            var kind = InputMode.Current;
            root.EnableInClassList("input-touch", kind == InputKind.Touch);
            root.EnableInClassList("input-keyboard", kind == InputKind.KeyboardMouse);
            root.EnableInClassList("input-gamepad", kind == InputKind.Gamepad);
            if (kind != InputKind.Touch) { stick?.Release(); weapons?.SetPrimaryHeld(false); }
            if (chase != null) chase.handlingDependent = kind != InputKind.Touch;
            BuildHints(kind);
            dockGlyph.Clear();
            if (kind == InputKind.KeyboardMouse) dockGlyph.Add(InputGlyph.Key("ENTER", true));
            else if (kind == InputKind.Gamepad) dockGlyph.Add(InputGlyph.Pad(PadButton.X));
        }

        void BuildHints(InputKind kind)
        {
            hints.Clear();
            string T(string key, string english) => Localization.Extra(key, english);
            if (nav != null && nav.MenuOpen)
            {
                if (kind == InputKind.KeyboardMouse)
                {
                    Hint(T("hudSelect", "SELECT"), InputGlyph.Key("W"), InputGlyph.Key("S"));
                    Hint(T("hudConfirm", "CONFIRM"), InputGlyph.Key("ENTER", true));
                    Hint(T("hudBack", "BACK"), InputGlyph.Key("ESC"));
                }
                else if (kind == InputKind.Gamepad)
                {
                    Hint(T("hudSelect", "SELECT"), InputGlyph.Pad(PadButton.DPad));
                    Hint(T("hudConfirm", "CONFIRM"), InputGlyph.Pad(PadButton.A));
                    Hint(T("hudBack", "BACK"), InputGlyph.Pad(PadButton.B));
                }
                return;
            }
            var turretNow = level != null ? level.Turret : null;
            if (turretNow != null && turretNow.InTurretView)
            {
                // PlayerEgo::setTurretMode: the stick aims the turret, fire fires it, the ship flies straight.
                string aimLabel = T("hudAimTurret", "AIM TURRET"), fire = T("hudFire", "FIRE"), exit = T("hudTurretExit", "CHASE VIEW");
                if (kind == InputKind.KeyboardMouse)
                {
                    Hint(aimLabel, InputGlyph.Key("W"), InputGlyph.Key("A"), InputGlyph.Key("S"), InputGlyph.Key("D"));
                    Hint(T("hudThrottle", "THROTTLE"), InputGlyph.Key("Q"), InputGlyph.Key("E"));
                    Hint(fire, InputGlyph.Key("CTRL"));
                    Hint(exit, InputGlyph.Key("V"));
                }
                else if (kind == InputKind.Gamepad)
                {
                    Hint(aimLabel, InputGlyph.Pad(PadButton.LeftStick));
                    Hint(fire, InputGlyph.Pad(PadButton.RightTrigger));
                    Hint(exit, InputGlyph.Pad(PadButton.DPad));
                }
                return;
            }
            if (lastAutopilot)
            {
                // Autopilot: throttle, boost and guns still work; fast-forward is held.
                string ff = T("hudFastForward", "FAST FORWARD"), off = T("hudAutopilotOff", "AUTOPILOT OFF");
                if (kind == InputKind.KeyboardMouse)
                {
                    Hint(T("hudThrottle", "THROTTLE"), InputGlyph.Key("Q"), InputGlyph.Key("E"));
                    Hint(ff + " (" + T("hudHold", "HOLD") + ")", InputGlyph.Key("R"));
                    Hint(off, InputGlyph.Key("ENTER", true));
                    Hint(T("hudFire", "FIRE"), InputGlyph.Key("CTRL"));
                    Hint(T("hudMenu", "MENU"), InputGlyph.Key("ESC"));
                }
                else if (kind == InputKind.Gamepad)
                {
                    Hint(T("hudThrottle", "THROTTLE"), InputGlyph.Pad(PadButton.LeftBumper), InputGlyph.Pad(PadButton.RightBumper));
                    Hint(ff + " (" + T("hudHold", "HOLD") + ")", InputGlyph.Pad(PadButton.Y));
                    Hint(off, InputGlyph.Pad(PadButton.X));
                    Hint(T("hudFire", "FIRE"), InputGlyph.Pad(PadButton.RightTrigger));
                    Hint(T("hudMenu", "MENU"), InputGlyph.Pad(PadButton.Menu));
                }
                return;
            }
            if (lastPhase != Mining.Phase.Idle)
            {
                // Autopilot to an asteroid / mining: only the drill and the action prompt matter.
                bool drilling = lastPhase == Mining.Phase.Mining;
                string action = drilling ? T("hudMiningStop", "STOP MINING") : T("hudMiningAbort", "ABORT");
                if (kind == InputKind.KeyboardMouse)
                {
                    if (drilling) Hint(T("hudDrill", "DRILL"), InputGlyph.Key("W"), InputGlyph.Key("A"), InputGlyph.Key("S"), InputGlyph.Key("D"));
                    if (lastPhase == Mining.Phase.Approaching) Hint(T("hudFastForward", "FAST FORWARD") + " (" + T("hudHold", "HOLD") + ")", InputGlyph.Key("R"));
                    Hint(action, InputGlyph.Key("ENTER", true));
                }
                else if (kind == InputKind.Gamepad)
                {
                    if (drilling) Hint(T("hudDrill", "DRILL"), InputGlyph.Pad(PadButton.LeftStick));
                    if (lastPhase == Mining.Phase.Approaching) Hint(T("hudFastForward", "FAST FORWARD") + " (" + T("hudHold", "HOLD") + ")", InputGlyph.Pad(PadButton.Y));
                    Hint(action, InputGlyph.Pad(PadButton.X));
                }
                return;
            }
            if (kind == InputKind.KeyboardMouse)
            {
                Hint(T("hudSteer", "STEER"), InputGlyph.Key("W"), InputGlyph.Key("A"), InputGlyph.Key("S"), InputGlyph.Key("D"));
                Hint(T("hudThrottle", "THROTTLE"), InputGlyph.Key("Q"), InputGlyph.Key("E"));
                Hint(T("hudFire", "FIRE"), InputGlyph.Key("CTRL"));
                Hint(T("hudMissile", "MISSILE"), InputGlyph.Key("F"));
                if (weapons != null && weapons.CanCycleSecondary) Hint(T("hudSwitchSecondary", "SWITCH"), InputGlyph.Key("G"));
                if (level != null && level.Turret != null)
                    Hint(level.Turret.IsAuto ? Localization.Get(37).ToUpperInvariant() : T("hudTurretView", "TURRET VIEW"), InputGlyph.Key(level.Turret.IsAuto ? "T" : "V"));
                Hint(T("hudBoost", "BOOST"), InputGlyph.Key("SPACE", true));
                Hint(T("hudLevel", "LEVEL"), InputGlyph.Key("R"));
                Hint(Localization.Get(571).ToUpperInvariant(), InputGlyph.Key("TAB"));
                Hint(T("hudMenu", "MENU"), InputGlyph.Key("ESC"));
            }
            else if (kind == InputKind.Gamepad)
            {
                Hint(T("hudSteer", "STEER"), InputGlyph.Pad(PadButton.LeftStick));
                Hint(T("hudThrottle", "THROTTLE"), InputGlyph.Pad(PadButton.LeftBumper), InputGlyph.Pad(PadButton.RightBumper));
                Hint(T("hudFire", "FIRE"), InputGlyph.Pad(PadButton.RightTrigger));
                Hint(T("hudMissile", "MISSILE"), InputGlyph.Pad(PadButton.LeftTrigger));
                if (weapons != null && weapons.CanCycleSecondary) Hint(T("hudSwitchSecondary", "SWITCH"), InputGlyph.Pad(PadButton.DPad));
                if (level != null && level.Turret != null)
                    Hint(level.Turret.IsAuto ? Localization.Get(37).ToUpperInvariant() : T("hudTurretView", "TURRET VIEW"), InputGlyph.Pad(PadButton.DPad));
                Hint(T("hudBoost", "BOOST"), InputGlyph.Pad(PadButton.A));
                Hint(T("hudLevel", "LEVEL"), InputGlyph.Pad(PadButton.Y));
                Hint(Localization.Get(571).ToUpperInvariant(), InputGlyph.Pad(PadButton.View));
                Hint(T("hudMenu", "MENU"), InputGlyph.Pad(PadButton.Menu));
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
            lensFlare?.Update(level != null ? level.Backdrop : null, StarMap.IsOpen || !Settings.LensFlare);   // StarSystem::render2D, under the HUD

            bool mapOpen = StarMap.IsOpen;
            root.EnableInClassList("hud-map", mapOpen);
            if (mapOpen) return;   // the map has its own input

            if (storyDialogue != null && storyDialogue.IsOpen)
            {
                ship?.SetSteer(Vector2.zero);
                storyDialogue.Tick(Time.unscaledDeltaTime * 1000f);
                return;
            }

            UpdateFreelanceTimer();
            if (nav != null && nav.MenuOpen)
            {
                UpdateAutopilotMenu();
                return;
            }

            if (pauseMenu.IsOpen) { pauseMenu.Tick(); return; }
            if ((Keyboard.current != null && Keyboard.current.escapeKey.wasPressedThisFrame)
                || (Gamepad.current != null && Gamepad.current.startButton.wasPressedThisFrame))
            {
                // MenuTouchWindow(1): the pause menu; after the player's death straight back to the main menu.
                if (health != null && health.Dead) BackToMenu(); else OpenPause();
                return;
            }
            if (UpdateIntroSkip()) return;
            if (nav != null && ((Keyboard.current != null && Keyboard.current.tabKey.wasPressedThisFrame)
                                || (Gamepad.current != null && Gamepad.current.selectButton.wasPressedThisFrame)))
                OnAutopilotButton();

            if (ship == null)
            {
                level = FindAnyObjectByType<SpaceLevel>();
                ship = level != null ? level.Player : null;
                if (ship == null) return;
                weapons = level.Weapons;
                mining = level.Mining;
                if (mining != null) mining.Message += OnMiningMessage;
                docking = level.Docking;
                if (docking != null) docking.Message += OnMiningMessage;
                if (level.GasClouds != null) level.GasClouds.Message += OnMiningMessage;
                nav = level.Navigation;
                if (nav != null) nav.Message += OnMiningMessage;
                jump = level.SystemJump;
                if (jump != null) jump.Message += OnMiningMessage;
                health = level.Health;
                radar = level.Radar;
                traffic = level.Traffic;
                if (traffic != null) traffic.Message += OnMiningMessage;
                // Layout::showMissionRewardMessage(reward, bounty): "Bounty collected" (3206) and the credits, sound 36.
                if (traffic != null) traffic.BountyCollected += reward =>
                {
                    miningView?.ShowMessage($"{Localization.Get(3206)}  +{ItemInfo.Credits(reward)}", 2);
                    var ca = CombatAssets.Load();
                    if (ca != null && ca.missionAccomplished != null) Sfx.PlayAt(ca.missionAccomplished, Camera.main != null ? Camera.main.transform.position : Vector3.zero);
                };
                if (radar != null) radar.Message += OnCombatMessage;
                if (health != null) health.GameOverStarted += OnGameOver;
                story = level.StorySpace;
                if (story != null)
                {
                    story.DialogueRequested += (pages, closed) => { stick?.Release(); weapons?.SetPrimaryHeld(false); storyDialogue.Show(pages, closed); };
                    story.MessageRequested += (text, speaker, closed) => { stick?.Release(); weapons?.SetPrimaryHeld(false); storyDialogue.ShowMessage(text, speaker, closed); };
                }
                freelance = level.FreelanceOrbit;
                if (freelance != null)
                {
                    freelance.MessageRequested += (text, name, portrait, closed) => { stick?.Release(); weapons?.SetPrimaryHeld(false); storyDialogue.ShowAgentMessage(text, name, portrait, closed); };
                    freelance.RewardMessage += OnMiningMessage;
                }
                if (weapons != null) weapons.Hit += () => hitFlashMs = 200f;
                if (level.Turret != null) level.Turret.Message += OnMiningMessage;   // HUD event 0x20 / 0x21 (auto fire on / off)
                if (health != null) health.Message += OnMiningMessage;             // injector / gamma messages
                if (level.Cloak != null) level.Cloak.Message += OnMiningMessage;   // cells paid, "Cloak ready", 583
                chase = Camera.main != null ? Camera.main.GetComponent<ChaseCamera>() : null;
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

            // The launch / arrival camera: no HUD but the orbit information until it ends or is skipped (MGame+0x5f).
            root.EnableInClassList("hud-launch", !level.LaunchCameraOver);
            if (level.Cutscene)
            {
                // A LevelScript cutscene (MGame+0x5f): no HUD, no controls; the radio and fades still show.
                root.EnableInClassList("hud-cinematic", true);
                dockPrompt.EnableInClassList("dock-prompt--hidden", true);
                ship.SetSteer(Vector2.zero);
                weapons?.SetPrimaryHeld(false);
                combatView.Update(radar, traffic, health, Camera.main, true, false);
                UpdateRadio();
                UpdateFade();
                return;
            }

            // The action prompt: navigation (autopilot / jump) first, then mining (lock / approach / minigame), else docking.
            string prompt = docking != null ? docking.PromptText : null;
            if (prompt == null && nav != null) prompt = nav.PromptText;
            if (prompt == null && mining != null) prompt = mining.PromptText;
            if (prompt == null && level.CanDock) prompt = Localization.Extra("hudDock", "DOCK");
            dockPrompt.EnableInClassList("dock-prompt--hidden", prompt == null);
            if (prompt != null) dockLabel.text = prompt;
            if (prompt != null && ((Keyboard.current != null && (Keyboard.current.enterKey.wasPressedThisFrame || Keyboard.current.numpadEnterKey.wasPressedThisFrame))
                                   || (Gamepad.current != null && Gamepad.current.buttonWest.wasPressedThisFrame)))
            {
                Interact();
                if (level == null || !level.isActiveAndEnabled) return;
            }

            var phase = mining != null ? mining.State : Mining.Phase.Idle;
            bool autopilot = nav != null && nav.Autopilot;
            if (phase != lastPhase || autopilot != lastAutopilot) { lastPhase = phase; lastAutopilot = autopilot; BuildHints(InputMode.Current); }
            // The turret: the touch button (turret view / auto-fire) and the hints of the turret view.
            var turret = level != null ? level.Turret : null;
            if (turretButton != null)
            {
                turretButton.EnableInClassList("touch-button--hidden", turret == null);
                if (turret != null)
                {
                    turretCaption.text = turret.IsAuto ? Localization.Get(37).ToUpperInvariant() : Localization.Extra("hudTurret", "TURRET");
                    turretButton.EnableInClassList("touch-button--pressed", turret.InTurretView || (turret.IsAuto && turret.AutoEnabled));
                }
            }
            bool tv = turret != null && turret.InTurretView, ta = turret != null && turret.AutoEnabled;
            if (tv != lastTurretView || ta != lastTurretAuto) { lastTurretView = tv; lastTurretAuto = ta; BuildHints(InputMode.Current); }
            root.EnableInClassList("hud-cinematic", (nav != null && nav.Jumping) || (jump != null && jump.Cinematic));   // jumps: no HUD
            // The Khador Drive's charge bar, shared with the cloak's "Cloak charging" (317, Hud::draw 0x1933f6).
            var cloak = level != null && level.Cloak != null ? level.Cloak.Rules : null;
            bool cloakCharging = cloak != null && cloak.State == Cloak.Phase.Charging && (jump == null || !jump.Charging);
            jumpCharge.EnableInClassList("jump-charge--shown", (jump != null && jump.Charging) || cloakCharging);
            if (cloakCharging != lastCloakCharging)
            {
                lastCloakCharging = cloakCharging;
                jumpChargeLabel.text = (cloakCharging ? Localization.Get(317) : Localization.Get(1359)).ToUpperInvariant();
            }
            if (jump != null && jump.Charging) jumpChargeFill.style.width = Length.Percent(jump.ChargeRate * 100f);
            else if (cloakCharging) jumpChargeFill.style.width = Length.Percent(Mathf.Min(1f, cloak.ChargeRate * 1.05f) * 100f);
            // The time extender: the fast-forward slot's clock (touch) while it isn't fast-forward.
            if (navView.ConsumeExtenderTap()) level?.Extender?.Toggle();
            UpdateOrbitInfo();
            // Fast-forward: the touch button, or hold R / controller Y (MGame key 0x100, hold-to-use).
            bool ffHeld = navView.FastForwardPressed
                          || (Keyboard.current != null && Keyboard.current.rKey.isPressed)
                          || (Gamepad.current != null && Gamepad.current.buttonNorth.isPressed);
            nav?.SetFastForwardHeld(ffHeld);
            root.EnableInClassList("hud-docking", phase != Mining.Phase.Idle);
            root.EnableInClassList("hud-mining", phase == Mining.Phase.Mining);
            var touchStick = InputMode.Current == InputKind.Touch && stick != null ? stick.Value : Vector2.zero;
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
            if (secondaryLabel != null)
            {
                bool any = weapons != null && weapons.SelectedSecondary >= 0;
                secondaryLabel.EnableInClassList("secondary-label--shown", any);
                secondaryLabel.EnableInClassList("secondary-label--empty", ammo == 0);
                string text = any ? $"{weapons.SecondaryName} ({ammo})" : "";
                if (secondaryLabel.text != text) secondaryLabel.text = text;
            }
            fireButton.EnableInClassList("touch-button--hidden", weapons == null || !weapons.HasPrimary);
            UpdateCrosshair();
            miningView.UpdateLock(mining, crosshair.style.left, crosshair.style.top, !crosshair.ClassListContains("crosshair--hidden") && phase == Mining.Phase.Idle);
            miningView.UpdateGame(mining, Time.deltaTime * 1000f);
            hackingView?.Update(docking);
            if (transferCounter != null)
            {
                bool on = docking != null && docking.TransferLabel != null;
                transferCounter.EnableInClassList("transfer-counter--hidden", !on);
                if (on) transferCounter.text = $"{docking.TransferLabel.ToUpperInvariant()}  {docking.TransferDone} / {docking.TransferTotal}";
            }
            var lockRing = root.Q("lockRing");
            lockRing.style.left = crosshair.style.left;
            lockRing.style.top = crosshair.style.top;
            navView.Update(nav, Camera.main, InputMode.Current == InputKind.Touch, phase,
                           level.Layout.alienOrbit ? Standing.Void : level.Layout.raceId, level.SystemJumpgateStation, level.StationInfo != null ? level.StationInfo.techLevel : 0);
            bool cinematic = (nav != null && nav.Jumping) || (jump != null && jump.Cinematic);
            bool plateFree = (nav == null || nav.Locked == null) && (mining == null || (mining.State == Mining.Phase.Idle && mining.Locked == null));
            // Radar::draw isn't called while the launch / arrival camera runs: no ship markers (their layer sets its display
            // inline, which the .hud-launch rule can't override).
            combatView.Update(radar, traffic, health, Camera.main, cinematic, plateFree, !level.LaunchCameraOver);
            UpdateRadio();
            UpdateFade();
        }

        /// <summary>Layout::drawFade: the campaign level's full-screen fade.</summary>
        /// <summary>The Skip button during the prologue / rescue (tap, Backspace, controller B); hidden while a dialogue is
        /// open. True when the skip was used this frame.</summary>
        bool UpdateIntroSkip()
        {
            var intro = level != null && level.Campaign != null ? level.Campaign.Intro : null;
            bool shown = intro != null && intro.CanSkip && !storyDialogue.IsOpen && (health == null || !health.Dead);
            introSkip.EnableInClassList("intro-skip--shown", shown);
            if (!shown) return false;
            var kind = InputMode.Current;
            if (kind != introSkipKind)
            {
                introSkipKind = kind;
                introSkip.Clear();
                if (kind == InputKind.KeyboardMouse) introSkip.Add(InputGlyph.Key("BACKSPACE", true));
                else if (kind == InputKind.Gamepad) introSkip.Add(InputGlyph.Pad(PadButton.B));
                var l = new Label(Localization.Get(395).ToUpperInvariant()) { pickingMode = PickingMode.Ignore };
                l.AddToClassList("intro-skip-label");
                l.AddToClassList("gof-semibold");
                introSkip.Add(l);
            }
            if ((Keyboard.current != null && Keyboard.current.backspaceKey.wasPressedThisFrame)
                || (Gamepad.current != null && Gamepad.current.buttonEast.wasPressedThisFrame))
            {
                SkipIntro();
                return true;
            }
            return false;
        }

        void SkipIntro()
        {
            var intro = level != null && level.Campaign != null ? level.Campaign.Intro : null;
            if (intro == null || !intro.CanSkip || storyDialogue.IsOpen) return;
            storyDialogue.ButtonSound?.Invoke(false);
            intro.Skip();
        }

        void UpdateFade()
        {
            var c = level != null ? level.Campaign : null;
            float a = c != null ? c.FadeAlpha : 0f;
            screenFade.style.opacity = a;
            if (c != null && a > 0f) screenFade.style.backgroundColor = c.FadeColor;
        }

        /// <summary>Radio::draw: the campaign level's current radio line (portrait, name, text; its voice once).</summary>
        void UpdateRadio()
        {
            var radio = level != null && level.Campaign != null ? level.Campaign.Radio : null;
            var line = radio?.Visible;
            int index = radio != null ? radio.VisibleIndex : -1;
            // Generic chatter (Level::createRadioMessage) in the same box while the level's own radio is quiet.
            var chatter = line == null && level != null && level.Traffic != null ? level.Traffic.ChatterVisible : null;
            if (chatter != null)
            {
                radioBox.EnableInClassList("radio--shown", true);
                if (chatter == shownChatter) return;
                shownChatter = chatter;
                radioShown = -1;
                radioSpeaker.text = chatter.speaker.ToUpperInvariant();
                AlienText.Set(radioText, chatter.text, chatter.portrait == null && StoryTable.UsesAlienFont(chatter.speakerId));
                if (chatter.portrait != null) Portrait.Show(radioPortrait, chatter.portrait, false);
                else Portrait.ShowSpeaker(radioPortrait, chatter.speakerId, false);
                var voiceClip = StoryAssets.Load()?.Voice(chatter.voice);
                if (voiceClip != null && voiceSource != null) { voiceSource.clip = voiceClip; voiceSource.volume = Settings.VoiceVolume; voiceSource.Play(); }
                return;
            }
            shownChatter = null;
            radioBox.EnableInClassList("radio--shown", line != null);
            if (line == null || index == radioShown) { if (line == null) radioShown = -1; return; }
            radioShown = index;
            radioSpeaker.text = StoryTable.SpeakerName(line.speaker).ToUpperInvariant();
            AlienText.Set(radioText, Localization.Get(line.text), StoryTable.UsesAlienFont(line.speaker));
            Portrait.ShowSpeaker(radioPortrait, line.speaker, false);
            var clip = StoryAssets.Load()?.Voice(line.voice);
            if (clip != null && voiceSource != null) { voiceSource.clip = clip; voiceSource.volume = Settings.VoiceVolume; voiceSource.Play(); }
        }

        /// <summary>The autopilot button (HUD key 0x40, MGame::OnTouchEnd): turns the autopilot off, cancels an asteroid
        /// approach, or opens / closes the autopilot menu.</summary>
        void OnAutopilotButton()
        {
            if (nav == null) return;
            if (nav.MenuOpen) CloseAutopilotMenu();
            else if (nav.Autopilot) nav.Interact();
            else if (mining != null && mining.State == Mining.Phase.Approaching) mining.Interact();
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
            menuActions.Clear();
            root.Q<Label>("autopilotMenuTitle").text = Localization.Get(571).ToUpperInvariant();
            foreach (var t in nav.MenuEntries())
            {
                var target = t;
                var b = new Button { text = t.name.ToUpperInvariant() };
                b.AddToClassList("autopilot-menu-item");
                b.AddToClassList("gof-semibold");
                b.focusable = false;
                b.clicked += () => ChooseMenuTarget(target);
                if (t.disabled) b.AddToClassList("autopilot-menu-item--disabled");
                autopilotMenuItems.Add(b);
                menuButtons.Add((b, target));
            }
            menuIndex = 0;
            lastMenuMove = 0;
            menuOpenedFrame = Time.frameCount;
            autopilotMenu.AddToClassList("autopilot-menu--shown");
            HighlightMenu();
            BuildHints(InputMode.Current);
        }

        void CloseAutopilotMenu()
        {
            nav?.CloseMenu();
            HideAutopilotMenu();
        }

        void HideAutopilotMenu()
        {
            autopilotMenu.RemoveFromClassList("autopilot-menu--shown");
            BuildHints(InputMode.Current);
        }

        void HighlightMenu()
        {
            bool keys = InputMode.Current != InputKind.Touch;
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
                if (menuIndex < menuActions.Count && menuActions[menuIndex] != null) menuActions[menuIndex]();
                else ChooseMenuTarget(menuButtons[menuIndex].target);
            }
        }

        readonly System.Collections.Generic.List<System.Action> menuActions = new System.Collections.Generic.List<System.Action>();

        void ChooseMenuTarget(Navigation.Target target)
        {
            if (target != null && target.disabled) return;   // TouchButton+0xa7: half-transparent, no taps
            if (target != null && target.kind == Navigation.Kind.Wingmen) { OpenWingmanMenu(); return; }
            nav.ChooseMenuEntry(target);
            HideAutopilotMenu();
        }

        /// <summary>Hud::initHudMenu(2): 307 Fire at will, 308 Attack my target, 309 Secure next waypoint, 310 / 311 Use laser /
        /// Use EMP blaster; a command goes to every living wingman, closes the menu and resumes the game.</summary>
        void OpenWingmanMenu()
        {
            var traffic = level != null ? level.Traffic : null;
            if (traffic == null) return;
            autopilotMenuItems.Clear();
            menuButtons.Clear();
            menuActions.Clear();
            root.Q<Label>("autopilotMenuTitle").text = Localization.Get(306).ToUpperInvariant();
            foreach (var (command, text) in new[] { (1, 307), (3, 308), (2, 309), (0, Session.WingmanShowEmp ? 311 : 310) })
            {
                int cmd = command;
                System.Action act = () =>
                {
                    traffic.CommandWingmen(cmd, level.Radar != null ? level.Radar.Locked : null, nav.PlayerRoute);
                    CloseAutopilotMenu();
                    root.Q<Label>("autopilotMenuTitle").text = Localization.Get(571).ToUpperInvariant();
                };
                var b = new Button { text = Localization.Get(text).ToUpperInvariant() };
                b.AddToClassList("autopilot-menu-item");
                b.AddToClassList("gof-semibold");
                b.focusable = false;
                b.clicked += act;
                autopilotMenuItems.Add(b);
                menuButtons.Add((b, null));
                menuActions.Add(act);
            }
            menuIndex = 0;
            HighlightMenu();
        }

        void OnMiningMessage(string text) => miningView?.ShowMessage(text);

        /// <summary>Junk removal's time limit (and a campaign level's, LevelScript+0: index 29's survival) as a HUD message:
        /// every 10 s, then every second from 10 s.</summary>
        void UpdateFreelanceTimer()
        {
            float left = -1f;
            if (freelance != null && !freelance.DialogueOpen) left = freelance.TimeLeftMs;
            else if (freelance == null && level != null && level.Campaign != null && !level.Dialogue && !level.Cutscene) left = level.Campaign.TimeLeftMs;
            if (left < 0f || left <= 0f && lastTimerSecond == 0) return;
            int sec = Mathf.CeilToInt(left / 1000f);
            if (sec == lastTimerSecond) return;
            lastTimerSecond = sec;
            if (sec % 10 == 0 || sec <= 10) OnMiningMessage($"{sec / 60}:{sec % 60:00}");
        }
        int lastTimerSecond = -1;
        void OnCombatMessage(string text, int colour) => miningView?.ShowMessage(text, colour);

        // ---- game over (MGame game-over state) ------------------------------------------------------------

        void OnGameOver()
        {
            gameOverMs = 0f;
            gameOver.AddToClassList("game-over--shown");
            gameOverText.text = Localization.Get(Session.HasAutosave ? 196 : 199);
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
            if (Session.LoadAutosave() && Application.CanStreamedLevelBeLoaded("Station")) SceneManager.LoadScene("Station");
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
            bool owned = GalaxyMap.HasOwner(system) && race >= 0 && race <= 3;
            var logo = orbitInfo.Q("orbitLogo");
            var tex = owned ? Resources.Load<Texture2D>($"GoF2Hud/logo_{race}") : null;
            logo.style.display = tex != null ? DisplayStyle.Flex : DisplayStyle.None;
            if (tex != null) { logo.style.backgroundImage = new StyleBackground(tex); logo.style.width = tex.width; logo.style.height = tex.height; }
            orbitInfo.Q<Label>("orbitStation").text = st == null ? "" : st.index == 101 ? st.name : $"{st.name} {Localization.Get(136)}";
            orbitInfo.Q<Label>("orbitSystem").text = st == null ? "" : $"{st.systemName} {Localization.Get(137)}";
            int sec = Mathf.Clamp(GalaxyMap.SecurityOf(level.Database.Systems.Find(s => s.index == system)), 0, 3);
            var secLabel = orbitInfo.Q<Label>("orbitSecurity");
            secLabel.text = Localization.Get(402 + sec);
            secLabel.style.color = (Color)GalaxyMap.SecurityColours[sec];
        }

        /// <summary>The action prompt: mining (mine / abort / stop) when it has something to do, else dock.</summary>
        void Interact()
        {
            if (docking != null && docking.PromptText != null) docking.Interact();
            else if (nav != null && nav.PromptText != null) nav.Interact();
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
                Debug.Log($"FlightHud: screen {w}x{h}, safe area {raw} -> {sa}, panel {root.layout.size}, input {InputMode.Current}");
            }).ExecuteLater(1);
        }

        void Dock()
        {
            if (level != null && level.CanDock) level.Dock();
        }

        void OpenPause()
        {
            if (level == null || pauseMenu.IsOpen || (health != null && health.Dead) || StarMap.IsOpen || storyDialogue.IsOpen) return;
            if (nav != null && nav.MenuOpen) CloseAutopilotMenu();
            stick?.Release();
            ship?.SetSteer(Vector2.zero);
            weapons?.SetPrimaryHeld(false);
            pauseMenu.Open(level);
        }

        void BackToMenu()
        {
            if (Application.CanStreamedLevelBeLoaded(menuScene)) SceneManager.LoadScene(menuScene);
        }
    }
}
