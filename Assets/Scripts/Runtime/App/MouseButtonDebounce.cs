// MouseButtonDebounce.cs
// Modified: a Windows build with a high polling rate mouse (2000 Hz) saw every press and release of a mouse button
// come in as a burst within one input update: 0 1 0 (a press, a release, a press again) or 1 0 1 0 (Player.log with
// -logpointer, InputDeviceLog: 153 of 253 presses / releases changed the button three times). The menus took each as
// a press or a release (InputSystemProvider dispatches every change of UI/Click), so one click was two, drags ended
// and began again, and a press left a button holding the pointer: the next click anywhere went to it. At 125 Hz it
// happened far less, in the Editor and on Linux / Android not at all (their mouse input is coalesced; the Windows
// player reads the raw reports). A mouse button's state change is taken once, and a change back within DebounceSeconds
// is written back to the state taken (a switch debounce: a real double click's changes are 60 ms or more apart).

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

        static bool installed;
        static readonly System.Collections.Generic.Dictionary<int, State> states = new System.Collections.Generic.Dictionary<int, State>();

        class State
        {
            public readonly bool[] pressed = new bool[5];
            public readonly double[] changedAt = new double[5];
        }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        static void Init()
        {
            if (installed) return;
            installed = true;
            InputSystem.onEvent += OnEvent;
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
                states[device.deviceId] = s = new State();
                for (int i = 0; i < 5; i++) s.pressed[i] = Button(mouse, i)?.isPressed ?? false;
            }
            double t = ptr.time;
            for (int i = 0; i < 5; i++)
            {
                var button = Button(mouse, i);
                if (button == null || !button.ReadValueFromEvent(ptr, out float v)) continue;
                bool p = v >= button.pressPointOrDefault;
                if (p == s.pressed[i]) continue;
                if (t - s.changedAt[i] < DebounceSeconds)
                    button.WriteValueIntoEvent(s.pressed[i] ? 1f : 0f, ptr);   // a bounce: keep the state just taken
                else
                {
                    s.pressed[i] = p;
                    s.changedAt[i] = t;
                }
            }
        }
    }
}
