// MouseButtonDebounce.cs
// Modified: a Windows build with a high polling rate mouse (2000 Hz) saw every press and release of a mouse button
// come in as a burst within one input update: 0 1 0 (a press, a release, a press again) or 1 0 1 0 (Player.log with
// -logpointer, InputDeviceLog: 153 of 253 presses / releases changed the button three times). The menus took each as
// a press or a release (InputSystemProvider dispatches every change of UI/Click), so one click was two, drags ended
// and began again, and a press left a button holding the pointer: the next click anywhere went to it. At 125 Hz it
// happened far less, in the Editor and on Linux / Android not at all (their mouse input is coalesced; the Windows
// player reads the raw reports). A mouse button's state change is taken once, and a change back within DebounceSeconds
// is written back to the state taken (a switch debounce: a real double click's changes are 60 ms or more apart).
// The button's last reported state is kept: when it still differs from the state taken once DebounceSeconds have
// passed (a touchpad tap, a quick click: the release came within the window and no mouse event followed), it is queued
// as an event of its own (Settle), else the button stayed down until the mouse moved.

using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.LowLevel;

namespace GoF2Remake
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class MouseButtonDebounce
    {
        const double DebounceSeconds = 0.03;
        const int Buttons = 5;

        static bool installed;
        static readonly System.Collections.Generic.Dictionary<int, State> states = new System.Collections.Generic.Dictionary<int, State>();

        class State
        {
            public Mouse mouse;
            public readonly bool[] pressed = new bool[Buttons];   // the state taken
            public readonly bool[] reported = new bool[Buttons];  // the device's last report
            public readonly double[] changedAt = new double[Buttons];
            public bool unsettled;
        }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        static void Init()
        {
            states.Clear();   // Play mode without a domain reload: last session's devices
            if (installed) return;
            installed = true;
            InputSystem.onEvent += OnEvent;
            InputSystem.onAfterUpdate += Settle;
        }

        static ButtonControl Button(Mouse m, int i)
        {
            switch (i)
            {
                case 0: return m.leftButton;
                case 1: return m.rightButton;
                case 2: return m.middleButton;
                case 3: return m.backButton;
                default: return m.forwardButton;
            }
        }

        static void OnEvent(InputEventPtr ptr, InputDevice device)
        {
            if (!(device is Mouse mouse) || !(ptr.IsA<StateEvent>() || ptr.IsA<DeltaStateEvent>())) return;
            if (!states.TryGetValue(device.deviceId, out var s))
            {
                states[device.deviceId] = s = new State { mouse = mouse };
                for (int i = 0; i < Buttons; i++) s.reported[i] = s.pressed[i] = Button(mouse, i)?.isPressed ?? false;
            }
            double t = ptr.time;
            for (int i = 0; i < Buttons; i++)
            {
                var button = Button(mouse, i);
                if (button == null || !button.ReadValueFromEvent(ptr, out float v)) continue;
                bool p = v >= button.pressPointOrDefault;
                s.reported[i] = p;
                if (p == s.pressed[i]) continue;
                if (t - s.changedAt[i] < DebounceSeconds)
                {
                    button.WriteValueIntoEvent(s.pressed[i] ? 1f : 0f, ptr);   // a bounce: keep the state just taken
                    s.unsettled = true;
                }
                else
                {
                    s.pressed[i] = p;
                    s.changedAt[i] = t;
                }
            }
        }

        /// <summary>After each input update: a button whose last report still differs from the state taken, once the
        /// debounce time has passed, gets that report as a queued state event (taken by OnEvent in the next update).</summary>
        static void Settle()
        {
            if (states.Count == 0) return;
            double now = InputState.currentTime;
            foreach (var s in states.Values)
            {
                if (!s.unsettled || s.mouse == null || !s.mouse.added) continue;
                bool due = false, waiting = false;
                for (int i = 0; i < Buttons; i++)
                {
                    if (s.reported[i] == s.pressed[i]) continue;
                    if (now - s.changedAt[i] >= DebounceSeconds) due = true;
                    else waiting = true;
                }
                s.unsettled = waiting || due;
                if (!due) continue;
                using (StateEvent.From(s.mouse, out var ev))
                {
                    ev.time = now;
                    // The device's current state, with the buttons as last reported; no movement or scroll (Mouse adds
                    // each event's delta and scroll to the frame's).
                    s.mouse.delta.WriteValueIntoEvent(Vector2.zero, ev);
                    s.mouse.scroll.WriteValueIntoEvent(Vector2.zero, ev);
                    for (int i = 0; i < Buttons; i++)
                    {
                        var button = Button(s.mouse, i);
                        if (button != null && s.reported[i] != s.pressed[i] && now - s.changedAt[i] >= DebounceSeconds)
                            button.WriteValueIntoEvent(s.reported[i] ? 1f : 0f, ev);
                    }
                    InputSystem.QueueEvent(ev);
                }
            }
        }
    }
}
