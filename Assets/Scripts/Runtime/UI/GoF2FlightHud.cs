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
// Near the station a "Dock" prompt appears (GoF2SpaceLevel.CanDock): tap it, Enter, or the controller's X.

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
        GoF2SpaceLevel level;
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

            stick = new GoF2TouchStick(root.Q("stickZone"), root.Q("stickBase"), root.Q("stickKnob"), root.Q("stickGhost"), stickRadius);
            HookThrottle();
            HookPress(boostButton, () => ship?.Boost());
            HookPress(levelButton, () => ship?.AlignToHorizon());
            HookPress(fireButton, () => weapons?.SetPrimaryHeld(true), () => weapons?.SetPrimaryHeld(false));
            HookPress(missileButton, null, () => weapons?.FireSecondary());
            HookPress(dockPrompt, null, Dock);
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
            if (kind == GoF2InputKind.KeyboardMouse)
            {
                Hint(T("hudSteer", "STEER"), GoF2InputGlyph.Key("W"), GoF2InputGlyph.Key("A"), GoF2InputGlyph.Key("S"), GoF2InputGlyph.Key("D"));
                Hint(T("hudThrottle", "THROTTLE"), GoF2InputGlyph.Key("Q"), GoF2InputGlyph.Key("E"));
                Hint(T("hudFire", "FIRE"), GoF2InputGlyph.Key("CTRL"));
                Hint(T("hudMissile", "MISSILE"), GoF2InputGlyph.Key("F"));
                Hint(T("hudBoost", "BOOST"), GoF2InputGlyph.Key("SPACE", true));
                Hint(T("hudLevel", "LEVEL"), GoF2InputGlyph.Key("R"));
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

            if ((Keyboard.current != null && Keyboard.current.escapeKey.wasPressedThisFrame)
                || (Gamepad.current != null && Gamepad.current.startButton.wasPressedThisFrame))
            {
                BackToMenu();
                return;
            }

            if (ship == null)
            {
                level = FindAnyObjectByType<GoF2SpaceLevel>();
                ship = level != null ? level.Player : null;
                if (ship == null) return;
                weapons = level.Weapons;
                if (weapons != null) weapons.Hit += () => hitFlashMs = 200f;
                chase = Camera.main != null ? Camera.main.GetComponent<GoF2ChaseCamera>() : null;
                ApplyInputMode();
            }

            bool canDock = level.CanDock;
            dockPrompt.EnableInClassList("dock-prompt--hidden", !canDock);
            if (canDock && ((Keyboard.current != null && (Keyboard.current.enterKey.wasPressedThisFrame || Keyboard.current.numpadEnterKey.wasPressedThisFrame))
                            || (Gamepad.current != null && Gamepad.current.buttonWest.wasPressedThisFrame)))
            {
                Dock();
                return;
            }

            ship.SetSteer(GoF2InputMode.Current == GoF2InputKind.Touch && stick != null ? stick.Value : Vector2.zero);

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
