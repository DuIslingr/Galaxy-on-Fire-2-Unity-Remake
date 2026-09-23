// GoF2InputMode.cs
// Which kind of input the player is using right now: touch, keyboard/mouse or a controller. Switches on the
// first real input of another kind (a touch, a key press, a mouse move or click, a button or a stick pushed past a
// dead zone), on phones and PCs alike, so UI can show touch controls, keyboard hints or controller (Xbox) hints.
// Starts as Touch on mobile, Gamepad if one is connected on other platforms, else KeyboardMouse.

using System;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.LowLevel;

namespace GoF2Remake.UI
{
    public enum GoF2InputKind { Touch, KeyboardMouse, Gamepad }

    public static class GoF2InputMode
    {
        const float StickThreshold = 0.35f;   // sticks drift; only count a deliberate push
        const float MouseThreshold = 4f;      // pixels per event

        public static GoF2InputKind Current { get; private set; }

        /// <summary>Raised on the main thread when Current changes.</summary>
        public static event Action Changed;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        static void Init()
        {
            Current = Application.isMobilePlatform ? GoF2InputKind.Touch
                    : Gamepad.current != null ? GoF2InputKind.Gamepad : GoF2InputKind.KeyboardMouse;
            InputSystem.onEvent -= OnEvent;   // domain reload may be off: never subscribe twice
            InputSystem.onEvent += OnEvent;
        }

        static void OnEvent(InputEventPtr e, InputDevice device)
        {
            if (!e.IsA<StateEvent>() && !e.IsA<DeltaStateEvent>()) return;
            GoF2InputKind kind;
            switch (device)
            {
                case Touchscreen _:
                    kind = GoF2InputKind.Touch;
                    break;
                case Gamepad _:
                    if (!HasControlAbove(e, device, StickThreshold)) return;
                    kind = GoF2InputKind.Gamepad;
                    break;
                case Keyboard _:
                    if (!HasControlAbove(e, device, 0.5f)) return;
                    kind = GoF2InputKind.KeyboardMouse;
                    break;
                case Mouse mouse:
                    // Touches on some platforms also arrive as a simulated mouse: ignore those.
                    if (Current == GoF2InputKind.Touch && Touchscreen.current != null && Touchscreen.current.primaryTouch.isInProgress) return;
                    if (!MouseUsed(e, mouse)) return;
                    kind = GoF2InputKind.KeyboardMouse;
                    break;
                default:
                    return;
            }
            if (kind == Current) return;
            Current = kind;
            Changed?.Invoke();
        }

        /// <summary>True if the event sets any control of the device to at least this magnitude (a pressed button = 1).</summary>
        static bool HasControlAbove(InputEventPtr e, InputDevice device, float threshold)
        {
            foreach (var control in e.EnumerateChangedControls(device, threshold)) return true;
            return false;
        }

        static bool MouseUsed(InputEventPtr e, Mouse mouse)
        {
            if (mouse.delta.ReadValueFromEvent(e, out Vector2 d) && d.sqrMagnitude >= MouseThreshold * MouseThreshold) return true;
            if (mouse.leftButton.ReadValueFromEvent(e, out float l) && l > 0.5f) return true;
            return mouse.rightButton.ReadValueFromEvent(e, out float r) && r > 0.5f;
        }
    }
}
