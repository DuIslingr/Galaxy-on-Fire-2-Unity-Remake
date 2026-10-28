// StickScrollTests.cs
// Feature: CLAUDE.md "Right stick scrolls the texts" (docs/notes/input.md; StickScroll, #169). Expected behaviour (the
// remake defines it): in the station menu the controller's right stick, up and down, scrolls a long text on screen that
// doesn't hold the focus; a stick pushed more sideways (the hangar's ship turning) scrolls nothing, and a list holding the
// focus is left to the focus. Through the real Input System with a test gamepad.

using System.Collections;
using GoF2Remake.UI;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.LowLevel;
using UnityEngine.TestTools;
using UnityEngine.UIElements;

namespace GoF2Remake.Tests
{
    public class StickScrollTests : PlayModeTest
    {
        Gamepad pad;
        InputSettings.BackgroundBehavior background;
        InputSettings.EditorInputBehaviorInPlayMode editorInput;

        [SetUp]
        public void UseTestPad()
        {
            background = InputSystem.settings.backgroundBehavior;
            editorInput = InputSystem.settings.editorInputBehaviorInPlayMode;
            InputSystem.settings.backgroundBehavior = InputSettings.BackgroundBehavior.IgnoreFocus;
            InputSystem.settings.editorInputBehaviorInPlayMode = InputSettings.EditorInputBehaviorInPlayMode.AllDeviceInputAlwaysGoesToGameView;
            pad = InputSystem.AddDevice<Gamepad>();
            pad.MakeCurrent();
        }

        [TearDown]
        public void RestoreInput()
        {
            InputSystem.RemoveDevice(pad);
            InputSystem.settings.backgroundBehavior = background;
            InputSystem.settings.editorInputBehaviorInPlayMode = editorInput;
        }

        static ScrollView LongText(VisualElement root, string name)
        {
            var sv = new ScrollView(ScrollViewMode.Vertical) { name = name };
            sv.style.position = Position.Absolute;
            sv.style.left = 10;
            sv.style.top = 10;
            sv.style.width = 300;
            sv.style.height = 200;
            for (int i = 0; i < 60; i++) sv.Add(new Button { text = name + " " + i, focusable = true });
            root.Add(sv);
            return sv;
        }

        IEnumerator Push(Vector2 stick, int frames)
        {
            InputSystem.QueueStateEvent(pad, new GamepadState { rightStick = stick });
            for (int i = 0; i < frames; i++) yield return null;
            InputSystem.QueueStateEvent(pad, new GamepadState());
            yield return null;
        }

        [UnityTest]
        public IEnumerator TheRightStickScrollsTheTextWithoutTheFocus()
        {
            FreePlayAt(78);
            yield return Load("Station");
            var menu = Find<StationMenu>();
            yield return WaitFor(() => !Get<bool>(menu, "UiBlocked") && !Get<bool>(menu, "ArrivalPending"), 15f, "station controls");
            var root = Get<VisualElement>(menu, "dragZone").panel.visualTree.Q(className: "gof-stick-scroll-watched");
            Assert.IsNotNull(root, "the station menu's document is watched");
            var list = LongText(root, "list");
            var text = LongText(root, "text");
            text.style.left = 400;
            yield return null;
            yield return null;
            list[0].Focus();
            Assert.AreSame(text, StickScroll.Pick(root, list[0]), "the long text without the focus");

            yield return Push(new Vector2(0f, -1f), 10);
            Assert.Greater(text.scrollOffset.y, 20f, "stick down: further down the text");
            Assert.AreEqual(0f, list.scrollOffset.y, 0.5f, "the list with the focus is left alone");
            float down = text.scrollOffset.y;
            yield return Push(new Vector2(0f, 1f), 3);
            Assert.Less(text.scrollOffset.y, down, "stick up: back toward the top");

            float before = text.scrollOffset.y;
            yield return Push(new Vector2(0.9f, -0.5f), 10);
            Assert.AreEqual(before, text.scrollOffset.y, 0.01f, "more sideways than down: the ship's turning, no scroll");
            root.Remove(list);
            root.Remove(text);
        }
    }
}
