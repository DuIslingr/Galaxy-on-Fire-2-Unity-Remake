// Exercise the real Input System -> EventSystem -> UI Toolkit path. Calling a menu's private handlers with fabricated
// pressedButtons values cannot catch a bridge that loses the held button between a press and subsequent movement.
using System.Collections;
using System.Collections.Generic;
using GoF2Remake.UI;
using GoF2Remake.World;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.LowLevel;
using UnityEngine.TestTools;
using UnityEngine.UIElements;

namespace GoF2Remake.Tests
{
    public class MouseDragInputTests : PlayModeTest
    {
        Mouse mouse;
        InputSettings.BackgroundBehavior background;
        InputSettings.EditorInputBehaviorInPlayMode editorInput;

        [SetUp]
        public void UseTestMouse()
        {
            background = InputSystem.settings.backgroundBehavior;
            editorInput = InputSystem.settings.editorInputBehaviorInPlayMode;
            InputSystem.settings.backgroundBehavior = InputSettings.BackgroundBehavior.IgnoreFocus;
            InputSystem.settings.editorInputBehaviorInPlayMode = InputSettings.EditorInputBehaviorInPlayMode.AllDeviceInputAlwaysGoesToGameView;
            mouse = InputSystem.AddDevice<Mouse>();
        }

        [TearDown]
        public void RestoreInput()
        {
            InputSystem.RemoveDevice(mouse);
            InputSystem.settings.backgroundBehavior = background;
            InputSystem.settings.editorInputBehaviorInPlayMode = editorInput;
        }

        static Vector2 ScreenPoint(VisualElement target)
        {
            var origin = RuntimePanelUtils.ScreenToPanel(target.panel, Vector2.zero);
            var end = RuntimePanelUtils.ScreenToPanel(target.panel, new Vector2(Screen.width, Screen.height));
            var p = target.worldBound.center;
            return new Vector2((p.x - origin.x) / (end.x - origin.x) * Screen.width,
                Screen.height - (p.y - origin.y) / (end.y - origin.y) * Screen.height);
        }

        void MouseAt(Vector2 point, bool held)
        {
            var state = new MouseState { position = point };
            if (held) state = state.WithButton(UnityEngine.InputSystem.LowLevel.MouseButton.Left);
            InputSystem.QueueStateEvent(mouse, state);
        }

        static List<string> Trace(VisualElement target)
        {
            var trace = new List<string>();
            target.RegisterCallback<PointerDownEvent>(e => trace.Add($"down id={e.pointerId} button={e.button} held={e.pressedButtons}"));
            target.RegisterCallback<PointerMoveEvent>(e => trace.Add($"move id={e.pointerId} button={e.button} held={e.pressedButtons}"));
            target.RegisterCallback<PointerUpEvent>(e => trace.Add($"up id={e.pointerId} button={e.button} held={e.pressedButtons}"));
            target.RegisterCallback<PointerCaptureOutEvent>(e => trace.Add($"capture-out id={e.pointerId}"));
            return trace;
        }

        // Fault injection: preserve the real held device state but reproduce a UI bridge omitting its button mask.
        static void OmitMoveButtonMask(VisualElement target)
        {
            target.RegisterCallback<PointerMoveEvent>(e => typeof(PointerEventBase<PointerMoveEvent>)
                .GetProperty("pressedButtons").SetValue(e, 0), TrickleDown.TrickleDown);
        }

        IEnumerator StationReady()
        {
            FreePlayAt(78);
            yield return Load("Station");
            var menu = Find<StationMenu>();
            yield return WaitFor(() => !Get<bool>(menu, "UiBlocked") && !Get<bool>(menu, "ArrivalPending"), 15f, "station controls");
        }

        [UnityTest]
        public IEnumerator HoldingMouseTurnsShipAndReleaseCanFling([Values(false, true)] bool omitMoveButtonMask)
        {
            yield return StationReady();
            var menu = Find<StationMenu>();
            var level = Find<StationLevel>();
            var zone = Get<VisualElement>(menu, "dragZone");
            var trace = Trace(zone);
            if (omitMoveButtonMask) OmitMoveButtonMask(zone);
            var p = ScreenPoint(zone);
            MouseAt(p, false);
            yield return null;
            MouseAt(p, true);
            yield return null;
            float before = Get<float>(level, "shipYaw");
            for (int i = 1; i <= 4; i++)
            {
                MouseAt(p + Vector2.right * (i * 40f), true);
                yield return null;
                Assert.That(Get<int>(menu, "dragPointer"), Is.EqualTo(PointerId.mousePointerId), string.Join("\n", trace));
            }
            Assert.That(Mathf.Abs(Get<float>(level, "shipYaw") - before), Is.GreaterThan(0.1f), string.Join("\n", trace));
            MouseAt(p + Vector2.right * 200f, false);
            yield return null;
            yield return null;
            Assert.That(Get<int>(menu, "dragPointer"), Is.EqualTo(-1), string.Join("\n", trace));
            Assert.That(Mathf.Abs(Get<float>(level, "flingVelocity")), Is.GreaterThan(0f), "a deliberate release still flings\n" + string.Join("\n", trace));
        }

        [UnityTest]
        public IEnumerator HoldingMousePansMapAcrossSeveralFrames([Values(false, true)] bool omitMoveButtonMask)
        {
            yield return StationReady();
            var map = StarMap.Open(Db, StarMapMode.Mission, false, _ => { });
            for (int i = 0; i < 5; i++) yield return null;
            var zone = Get<VisualElement>(map, "touch");
            var trace = Trace(zone);
            if (omitMoveButtonMask) OmitMoveButtonMask(zone);
            var p = ScreenPoint(zone);
            MouseAt(p, false);
            yield return null;
            MouseAt(p, true);
            yield return null;
            Vector2 before = Get<Vector2>(map, "pan");
            for (int i = 1; i <= 4; i++)
            {
                MouseAt(p + Vector2.right * (i * 40f), true);
                yield return null;
                Assert.That(Get<int>(map, "pointer"), Is.EqualTo(PointerId.mousePointerId), string.Join("\n", trace));
            }
            Assert.That(Vector2.Distance(Get<Vector2>(map, "pan"), before), Is.GreaterThan(1f), string.Join("\n", trace));
            MouseAt(p + Vector2.right * 160f, false);
            yield return null;
            yield return null;
            Assert.That(Get<int>(map, "pointer"), Is.EqualTo(-1), string.Join("\n", trace));
        }
    }
}
