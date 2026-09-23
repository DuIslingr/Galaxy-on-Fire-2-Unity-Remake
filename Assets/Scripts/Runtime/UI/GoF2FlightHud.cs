// GoF2FlightHud.cs
// In-flight HUD (UI Toolkit) that adapts to the input in use (GoF2InputMode):
//   Touch:      floating stick on the left half (steer), throttle slider on the right edge (the original's touch
//               throttle is a vertical drag too, MGame::OnTouchMove), Boost and Level buttons, a Menu button.
//   Keyboard:   keycap hints (WASD, Q/E, Space, R, Esc).
//   Controller: Xbox button hints (LS, LT/RT, A, Y, Menu).
// Always: speed, throttle and boost readout. The chase camera uses the original's fixed touch-mode damping for
// touch and the handling-dependent damping otherwise (TargetFollowCamera::resetShipHandling / setShipHandling).
// Esc, the Android back button or the controller's Menu button returns to the main menu (no pause menu yet).

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
        Label speedValue;
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

            stick = new GoF2TouchStick(root.Q("stickZone"), root.Q("stickBase"), root.Q("stickKnob"), root.Q("stickGhost"), stickRadius);
            HookThrottle();
            HookPress(boostButton, () => ship?.Boost());
            HookPress(levelButton, () => ship?.AlignToHorizon());
            root.Q<Button>("menuButton").clicked += BackToMenu;

            root.Q<Label>("stickCaption").text = GoF2Localization.Extra("hudSteer", "STEER");
            root.Q<Label>("boostCaption").text = GoF2Localization.Extra("hudBoost", "BOOST");
            root.Q<Label>("levelCaption").text = GoF2Localization.Extra("hudLevel", "LEVEL");
            root.Q<Label>("speedUnit").text = "M/S";
            root.Q<Button>("menuButton").text = GoF2Localization.Extra("hudMenu", "MENU");

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

        /// <summary>Fires on press (not release) and shows a pressed state while the finger stays down.</summary>
        static void HookPress(VisualElement button, System.Action action)
        {
            int pointer = -1;
            button.RegisterCallback<PointerDownEvent>(e =>
            {
                if (pointer >= 0) return;
                pointer = e.pointerId;
                button.CapturePointer(pointer);
                button.AddToClassList("touch-button--pressed");
                action();
                e.StopPropagation();
            });
            void Up(int id)
            {
                if (id != pointer) return;
                if (button.HasPointerCapture(pointer)) button.ReleasePointer(pointer);
                pointer = -1;
                button.RemoveFromClassList("touch-button--pressed");
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
            if (kind != GoF2InputKind.Touch) stick?.Release();
            if (chase != null) chase.handlingDependent = kind != GoF2InputKind.Touch;
            BuildHints(kind);
        }

        void BuildHints(GoF2InputKind kind)
        {
            hints.Clear();
            string T(string key, string english) => GoF2Localization.Extra(key, english);
            if (kind == GoF2InputKind.KeyboardMouse)
            {
                Hint(T("hudSteer", "STEER"), GoF2InputGlyph.Key("W"), GoF2InputGlyph.Key("A"), GoF2InputGlyph.Key("S"), GoF2InputGlyph.Key("D"));
                Hint(T("hudThrottle", "THROTTLE"), GoF2InputGlyph.Key("Q"), GoF2InputGlyph.Key("E"));
                Hint(T("hudBoost", "BOOST"), GoF2InputGlyph.Key("SPACE", true));
                Hint(T("hudLevel", "LEVEL"), GoF2InputGlyph.Key("R"));
                Hint(T("hudMenu", "MENU"), GoF2InputGlyph.Key("ESC"));
            }
            else if (kind == GoF2InputKind.Gamepad)
            {
                Hint(T("hudSteer", "STEER"), GoF2InputGlyph.Pad(GoF2PadButton.LeftStick));
                Hint(T("hudThrottle", "THROTTLE"), GoF2InputGlyph.Pad(GoF2PadButton.LeftTrigger), GoF2InputGlyph.Pad(GoF2PadButton.RightTrigger));
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
                var level = FindAnyObjectByType<GoF2SpaceLevel>();
                ship = level != null ? level.Player : null;
                if (ship == null) return;
                chase = Camera.main != null ? Camera.main.GetComponent<GoF2ChaseCamera>() : null;
                ApplyInputMode();
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
        }

        /// <summary>The panel's pixel size: the screen, or the target texture when rendering offscreen (tests).</summary>
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
            // Device safe-area insets (pixels -> panel units) once the panel has its new size.
            root.schedule.Execute(() =>
            {
                if (safeArea == null || root.layout.width <= 0f) return;
                float k = root.layout.width / w;
                var sa = offscreen ? new Rect(0f, 0f, w, h) : Screen.safeArea;
                safeArea.style.left = sa.xMin * k;
                safeArea.style.right = (w - sa.xMax) * k;
                safeArea.style.top = (h - sa.yMax) * k;
                safeArea.style.bottom = sa.yMin * k;
            });
        }

        void BackToMenu()
        {
            if (Application.CanStreamedLevelBeLoaded(menuScene)) SceneManager.LoadScene(menuScene);
        }
    }
}
