using System;
using System.Reflection;
using GoF2Remake.UI;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.LowLevel;
using UnityEngine.UIElements;
using Object = UnityEngine.Object;

namespace GoF2Remake.Tests
{
    public class MouseGestureTests
    {
        const BindingFlags Private = BindingFlags.Instance | BindingFlags.NonPublic;

        static void Set(object owner, string name, object value) => owner.GetType().GetField(name, Private).SetValue(owner, value);
        static T Get<T>(object owner, string name) => (T)owner.GetType().GetField(name, Private).GetValue(owner);
        static void Call(object owner, string name, params object[] args) => owner.GetType().GetMethod(name, Private).Invoke(owner, args);

        // Set the pooled event's protected setters, so tests don't alter UI Toolkit's global device/button state.
        static T Pointer<T>(int buttons, int button = -1, VisualElement target = null) where T : PointerEventBase<T>, new()
        {
            var e = PointerEventBase<T>.GetPooled();
            var type = typeof(PointerEventBase<T>);
            foreach (var pair in new (string, object)[] {
                ("pointerId", PointerId.mousePointerId), ("pointerType", UnityEngine.UIElements.PointerType.mouse),
                ("pressedButtons", buttons), ("button", button),
                ("position", new Vector3(100f, 100f)), ("localPosition", new Vector3(100f, 100f)) })
                type.GetProperty(pair.Item1).SetValue(e, pair.Item2);
            e.target = target;
            return e;
        }

        [TestCase(0)]
        [TestCase(2)] // Right held after the primary button was released.
        public void MapDoesNotPanOnAMissedPrimaryRelease(int buttons)
        {
            var go = new GameObject("Map gesture test");
            go.SetActive(false);
            var map = go.AddComponent<StarMap>();
            try
            {
                Set(map, "touch", new VisualElement());
                Set(map, "pointer", PointerId.mousePointerId);
                Set(map, "selected", -1);
                Set(map, "vel", new Vector2(20f, 10f));
                using var e = Pointer<PointerMoveEvent>(buttons);
                Call(map, "OnPointerMove", e);
                Assert.That(Get<Vector2>(map, "pan"), Is.EqualTo(Vector2.zero));
                Assert.That(Get<int>(map, "pointer"), Is.EqualTo(-1));
                Assert.That(Get<Vector2>(map, "vel"), Is.EqualTo(Vector2.zero), "a cancelled drag must not fling");
            }
            finally { Object.DestroyImmediate(go); }
        }

        [Test]
        public void MapIgnoresSecondaryPresses()
        {
            var go = new GameObject("Map gesture test");
            go.SetActive(false);
            var map = go.AddComponent<StarMap>();
            var camera = go.AddComponent<Camera>();
            try
            {
                Set(map, "cam", camera);
                Set(map, "touch", new VisualElement());
                using var e = Pointer<PointerDownEvent>(2, 1);
                Call(map, "OnPointerDown", e);
                Assert.That(Get<int>(map, "pointer"), Is.EqualTo(-1));
            }
            finally { Object.DestroyImmediate(go); }
        }

        [Test]
        public void APrimaryDragStillMovesTheMapByThePointerDistance()
        {
            var go = new GameObject("Map gesture test");
            go.SetActive(false);
            var map = go.AddComponent<StarMap>();
            var assets = ScriptableObject.CreateInstance<StarMapAssets>();
            try
            {
                Set(map, "touch", new VisualElement());
                Set(map, "assets", assets);
                Set(map, "pointer", PointerId.mousePointerId);
                using var e = Pointer<PointerMoveEvent>(1);
                Call(map, "OnPointerMove", e);
                Assert.That(Get<Vector2>(map, "pan"), Is.EqualTo(new Vector2(32.5f, 32.5f)));
                Assert.That(Get<int>(map, "pointer"), Is.EqualTo(PointerId.mousePointerId));
            }
            finally { Object.DestroyImmediate(go); Object.DestroyImmediate(assets); }
        }

        [Test]
        public void LosingWindowFocusCancelsMapDragAndPinch()
        {
            var go = new GameObject("Map gesture test");
            go.SetActive(false);
            var map = go.AddComponent<StarMap>();
            try
            {
                Set(map, "touch", new VisualElement());
                Set(map, "pointer", PointerId.mousePointerId);
                Set(map, "yawVel", 200f);
                Set(map, "vel", Vector2.one);
                Get<System.Collections.Generic.Dictionary<int, Vector2>>(map, "pinch")[PointerId.mousePointerId] = Vector2.one;
                Call(map, "OnApplicationFocus", false);
                Assert.That(Get<int>(map, "pointer"), Is.EqualTo(-1));
                Assert.That(Get<Vector2>(map, "vel"), Is.EqualTo(Vector2.zero));
                Assert.That(Get<float>(map, "yawVel"), Is.Zero);
                Assert.That(Get<System.Collections.Generic.Dictionary<int, Vector2>>(map, "pinch"), Is.Empty);
            }
            finally { Object.DestroyImmediate(go); }
        }

        [TestCase("slider")]
        [TestCase("slider-int")]
        [TestCase("text")]
        [TestCase("integer")]
        [TestCase("float")]
        [TestCase("scroller")]
        public void ListDragDoesNotStealAControlGesture(string kind)
        {
            var scroll = new ScrollView();
            VisualElement control = kind switch {
                "slider" => new Slider(), "slider-int" => new SliderInt(), "text" => new TextField(),
                "integer" => new IntegerField(), "float" => new FloatField(), _ => new Scroller() };
            var inner = new VisualElement();
            control.Add(inner);
            scroll.Add(control);
            var drag = new DragScroll(scroll);
            using var e = Pointer<PointerDownEvent>(1, 0, inner);
            Call(drag, "OnDown", e);
            Assert.That(Get<int>(drag, "pointerId"), Is.EqualTo(-1));
        }

        [Test]
        public void ListRowsStillAllowDragScrolling()
        {
            var scroll = new ScrollView();
            var row = new Button();
            scroll.Add(row);
            var drag = new DragScroll(scroll);
            using var e = Pointer<PointerDownEvent>(1, 0, row);
            Call(drag, "OnDown", e);
            Assert.That(Get<int>(drag, "pointerId"), Is.EqualTo(PointerId.mousePointerId));
        }

        [Test]
        public void ANewControlPressClearsAnOldPendingListDrag()
        {
            var scroll = new ScrollView();
            var slider = new Slider();
            scroll.Add(slider);
            var drag = new DragScroll(scroll);
            Set(drag, "pointerId", PointerId.mousePointerId);
            using var e = Pointer<PointerDownEvent>(1, 0, slider);
            Call(drag, "OnDown", e);
            Assert.That(Get<int>(drag, "pointerId"), Is.EqualTo(-1));
        }

        [TestCase(0)]
        [TestCase(2)]
        public void ListDragEndsWhenPrimaryIsNoLongerHeld(int buttons)
        {
            var scroll = new ScrollView();
            var drag = new DragScroll(scroll);
            Set(drag, "pointerId", PointerId.mousePointerId);
            using var e = Pointer<PointerMoveEvent>(buttons);
            Call(drag, "OnMove", e);
            Assert.That(Get<int>(drag, "pointerId"), Is.EqualTo(-1));
        }

        [Test]
        public void ScrollbarIgnoresSecondaryPresses()
        {
            var scroll = new ScrollView();
            var bar = Activator.CreateInstance(typeof(ScrollBars), Private, null, new object[] { scroll }, null);
            using var e = Pointer<PointerDownEvent>(2, 1);
            Call(bar, "OnDown", e);
            Assert.That(Get<int>(bar, "pointer"), Is.EqualTo(-1));
        }

        [TestCase(0)]
        [TestCase(2)]
        public void ScrollbarStopsOnAMissedPrimaryRelease(int buttons)
        {
            var scroll = new ScrollView();
            var bar = Activator.CreateInstance(typeof(ScrollBars), Private, null, new object[] { scroll }, null);
            Set(bar, "pointer", PointerId.mousePointerId);
            using var e = Pointer<PointerMoveEvent>(buttons);
            Call(bar, "OnMove", e);
            Assert.That(Get<int>(bar, "pointer"), Is.EqualTo(-1));
        }

        public class FocusWindow : EditorWindow { }

        [Test]
        public void HoverCannotTakeFocusFromACapturedGestureEvenWithoutAFocusedControl()
        {
            var window = ScriptableObject.CreateInstance<FocusWindow>();
            try
            {
                window.Show();
                var owner = new VisualElement();
                var button = new Button();
                window.rootVisualElement.Add(owner);
                window.rootVisualElement.Add(button);
                owner.CapturePointer(PointerId.mousePointerId);
                Assert.That(UiHover.CanChangeFocus(button, 0), Is.False);
                owner.ReleasePointer(PointerId.mousePointerId);
                Assert.That(UiHover.CanChangeFocus(button, 0), Is.True);
                Assert.That(UiHover.CanChangeFocus(button, 1), Is.False);
            }
            finally { window.Close(); }
        }

        [Test]
        public void HoverDoesNotBeginATextEdit()
        {
            Assert.That(UiHover.CanChangeFocus(new TextField(), 0), Is.False);
            Assert.That(UiHover.CanChangeFocus(new IntegerField(), 0), Is.False);
            Assert.That(UiHover.CanChangeFocus(new FloatField(), 0), Is.False);
        }

        [TestCase("text")]
        [TestCase("integer")]
        [TestCase("float")]
        public void StationKeepsAnEditFocusedWhenMouseLeaves(string kind)
        {
            var go = new GameObject("Station gesture test");
            go.SetActive(false);
            var station = go.AddComponent<StationMenu>();
            var window = ScriptableObject.CreateInstance<FocusWindow>();
            var previous = DataUiTestKit.SetInputMode(InputKind.KeyboardMouse);
            try
            {
                window.Show();
                VisualElement field = kind switch { "integer" => new IntegerField(), "float" => new FloatField(), _ => new TextField() };
                var button = new Button();
                window.rootVisualElement.Add(field);
                window.rootVisualElement.Add(button);
                Set(station, "root", window.rootVisualElement);
                Set(station, "pointerPos", new Vector2(-100f, -100f));
                field.Focus();
                var focused = window.rootVisualElement.focusController.focusedElement;
                Assert.That(focused, Is.Not.Null);
                Assert.That(UiHover.CanChangeFocus(button, 0), Is.False, "hover must not steal the edit");
                Call(station, "UnmarkLeftButton");
                Assert.That(window.rootVisualElement.focusController.focusedElement, Is.SameAs(focused));
            }
            finally { DataUiTestKit.SetInputMode(previous); window.Close(); Object.DestroyImmediate(go); }
        }

        [Test]
        public void StationUsesTheClickPositionEvenWithoutAPrecedingMove()
        {
            var go = new GameObject("Station gesture test");
            go.SetActive(false);
            var station = go.AddComponent<StationMenu>();
            try
            {
                using var e = Pointer<PointerDownEvent>(1, 0);
                Call(station, "OnPointerDown", e);
                Assert.That(Get<Vector2>(station, "pointerPos"), Is.EqualTo(new Vector2(100f, 100f)));
            }
            finally { Object.DestroyImmediate(go); }
        }

        [TestCase(false)]
        [TestCase(true)]
        public void WheelAndMiddleButtonCountAsMouseUse(bool wheel)
        {
            var mouse = InputSystem.AddDevice<Mouse>();
            try
            {
                using var buffer = StateEvent.From(mouse, out var e);
                if (wheel) mouse.scroll.WriteValueIntoEvent(new Vector2(0f, 120f), e);
                else mouse.middleButton.WriteValueIntoEvent(1f, e);
                var used = typeof(InputMode).GetMethod("MouseUsed", BindingFlags.Static | BindingFlags.NonPublic);
                Assert.That((bool)used.Invoke(null, new object[] { e, mouse }), Is.True);
            }
            finally { InputSystem.RemoveDevice(mouse); }
        }

        [Test]
        public void ARealHeldMouseButtonSurvivesAMoveWithNoReportedButtons()
        {
            var mouse = InputSystem.AddDevice<Mouse>();
            try
            {
                InputState.Change(mouse, new MouseState().WithButton(UnityEngine.InputSystem.LowLevel.MouseButton.Left));
                using var move = Pointer<PointerMoveEvent>(0);
                Assert.That(UiPointerButtons.PrimaryHeld(move), Is.True);
                Assert.That(UiPointerButtons.AnyHeld(move), Is.True);
            }
            finally { InputSystem.RemoveDevice(mouse); }
        }

        [Test]
        public void AnIdleMouseCannotKeepAMissingReleaseAlive()
        {
            var mouse = InputSystem.AddDevice<Mouse>();
            try
            {
                using var move = Pointer<PointerMoveEvent>(0);
                Assert.That(UiPointerButtons.PrimaryHeld(move), Is.False);
                Assert.That(UiPointerButtons.AnyHeld(move), Is.False);
            }
            finally { InputSystem.RemoveDevice(mouse); }
        }

        [TestCase(UnityEngine.InputSystem.LowLevel.MouseButton.Right)]
        [TestCase(UnityEngine.InputSystem.LowLevel.MouseButton.Middle)]
        public void SecondaryMouseButtonsKeepPanningButCannotKeepAPrimaryDrag(UnityEngine.InputSystem.LowLevel.MouseButton button)
        {
            var mouse = InputSystem.AddDevice<Mouse>();
            try
            {
                InputState.Change(mouse, new MouseState().WithButton(button));
                using var move = Pointer<PointerMoveEvent>(0);
                Assert.That(UiPointerButtons.AnyHeld(move), Is.True);
                Assert.That(UiPointerButtons.PrimaryHeld(move), Is.False);
            }
            finally { InputSystem.RemoveDevice(mouse); }
        }

        [Test]
        public void ReleaseFrameMovementKeepsItsEventButtonUntilTheUpEvent()
        {
            var mouse = InputSystem.AddDevice<Mouse>();
            try
            {
                InputState.Change(mouse, new MouseState());
                using var move = Pointer<PointerMoveEvent>(1);
                Assert.That(UiPointerButtons.PrimaryHeld(move), Is.True, "movement can precede the queued button-up; don't discard a fling");
            }
            finally { InputSystem.RemoveDevice(mouse); }
        }

        [TestCase("touch")]
        [TestCase("pen")]
        public void ARealMouseCannotKeepADifferentPointerHeld(string type)
        {
            var mouse = InputSystem.AddDevice<Mouse>();
            try
            {
                InputState.Change(mouse, new MouseState().WithButton(UnityEngine.InputSystem.LowLevel.MouseButton.Left));
                using var move = Pointer<PointerMoveEvent>(0);
                typeof(PointerEventBase<PointerMoveEvent>).GetProperty("pointerType").SetValue(move, type);
                Assert.That(UiPointerButtons.PrimaryHeld(move), Is.False);
                Assert.That(UiPointerButtons.AnyHeld(move), Is.False);
            }
            finally { InputSystem.RemoveDevice(mouse); }
        }

        [Test]
        public void HeldMouseMovementDoesNotCancelTheMapOrListWhenItsEventMaskIsEmpty()
        {
            var mouse = InputSystem.AddDevice<Mouse>();
            var go = new GameObject("Map held-button test");
            go.SetActive(false);
            var map = go.AddComponent<StarMap>();
            var assets = ScriptableObject.CreateInstance<StarMapAssets>();
            try
            {
                InputState.Change(mouse, new MouseState().WithButton(UnityEngine.InputSystem.LowLevel.MouseButton.Left));
                Set(map, "touch", new VisualElement());
                Set(map, "assets", assets);
                Set(map, "pointer", PointerId.mousePointerId);
                using var move = Pointer<PointerMoveEvent>(0);
                Call(map, "OnPointerMove", move);
                Assert.That(Get<int>(map, "pointer"), Is.EqualTo(PointerId.mousePointerId));
                Assert.That(Get<Vector2>(map, "pan"), Is.EqualTo(new Vector2(32.5f, 32.5f)));
                var drag = new DragScroll(new ScrollView());
                Set(drag, "pointerId", PointerId.mousePointerId);
                Set(drag, "startPos", new Vector2(100f, 100f)); // stay below the capture threshold
                Call(drag, "OnMove", move);
                Assert.That(Get<int>(drag, "pointerId"), Is.EqualTo(PointerId.mousePointerId));
            }
            finally { Object.DestroyImmediate(go); Object.DestroyImmediate(assets); InputSystem.RemoveDevice(mouse); }
        }
    }
}
