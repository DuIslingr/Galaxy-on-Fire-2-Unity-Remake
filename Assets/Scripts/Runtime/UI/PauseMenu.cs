// PauseMenu.cs
// The in-flight pause menu (MenuTouchWindow mode 1, Reference/research/mainmenu_notes.md 2.4): header 40 "Pause", then
// 41 Resume, 129 Missions, 166 Cargo hold, 31 Options, 395 Skip (the original only for a few cutscenes; here the
// prologue / rescue, IntroCutscenes.Skip) and 522 Back to Main Menu (confirm 523). The game and its sounds pause while it
// is open. Options holds the in-flight subset (volumes, sensitivity, invert); the rest stays in the main menu. Not built:
// 59 Action Freeze (photo mode) and the screenshot share buttons (60 / 61).
// Plain class driven by FlightHud: Esc / controller Menu / the touch Menu button open it; Esc / B step back.

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.World;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class PauseMenu
    {
        enum Page { Main, Missions, Cargo, Options, Quit }

        readonly VisualElement backdrop, panel, body;
        readonly Label title;
        readonly Action backToMenu;
        readonly List<VisualElement> items = new List<VisualElement>();
        readonly List<Action> actions = new List<Action>();
        Page page;
        int index, openedFrame;
        ScrollView scroll;
        SpaceLevel level;
        bool audioWasPaused;
        float previousTimeScale = 1f;

        public bool IsOpen { get; private set; }

        static string T(int id) => Localization.Get(id).ToUpperInvariant();

        public PauseMenu(VisualElement root, Action backToMenu)
        {
            this.backToMenu = backToMenu;
            backdrop = new VisualElement();
            backdrop.AddToClassList("pause-backdrop");
            panel = new VisualElement();
            panel.AddToClassList("pause-panel");
            title = new Label { pickingMode = PickingMode.Ignore };
            title.AddToClassList("autopilot-menu-title");
            title.AddToClassList("gof-semibold");
            title.AddToClassList("pause-title");
            body = new VisualElement();
            body.AddToClassList("pause-body");
            panel.Add(title);
            panel.Add(body);
            backdrop.Add(panel);
            root.Add(backdrop);
        }

        // ---- open / close -----------------------------------------------------------------------------------

        public void Open(SpaceLevel spaceLevel)
        {
            if (IsOpen) return;
            level = spaceLevel;
            IsOpen = true;
            openedFrame = Time.frameCount;
            previousTimeScale = Time.timeScale;
            Time.timeScale = 0f;
            if (level != null && level.Navigation != null) level.Navigation.PauseMenuOpen = true;
            if (level != null && level.Weapons != null) level.Weapons.SetPrimaryHeld(false);
            audioWasPaused = AudioListener.pause;
            AudioListener.pause = true;
            backdrop.AddToClassList("pause-backdrop--shown");
            Show(Page.Main);
        }

        public void Close()
        {
            if (!IsOpen) return;
            IsOpen = false;
            backdrop.RemoveFromClassList("pause-backdrop--shown");
            AudioListener.pause = audioWasPaused;
            if (level != null && level.Navigation != null) level.Navigation.PauseMenuOpen = false;   // restores its own time scale
            else Time.timeScale = previousTimeScale;
            // Options changed in flight reach the ship at once.
            if (level != null && level.Player != null)
            {
                level.Player.sensitivity = Settings.Sensitivity;
                level.Player.invertPitch = Settings.InvertPitch;
            }
        }

        // ---- pages --------------------------------------------------------------------------------------------

        void Show(Page p)
        {
            page = p;
            body.Clear();
            items.Clear();
            actions.Clear();
            scroll = null;
            index = 0;
            switch (p)
            {
                case Page.Main:
                    title.text = T(40);
                    Item(T(41), Close);
                    Item(T(129), () => Show(Page.Missions));
                    Item(T(166), () => Show(Page.Cargo));
                    Item(T(31), () => Show(Page.Options));
                    var intro = level != null && level.Campaign != null ? level.Campaign.Intro : null;
                    if (intro != null && intro.CanSkip) Item(T(395), () => { Close(); intro.Skip(); });
                    Item(T(522), () => Show(Page.Quit));
                    break;
                case Page.Quit:
                    title.text = T(522);
                    Text(Localization.Get(523));
                    Item(T(134), () => { Close(); backToMenu?.Invoke(); });
                    Item(T(135), () => Show(Page.Main));
                    index = 1;
                    break;
                case Page.Missions:
                    title.text = T(129);
                    BuildMissions();
                    Item("‹  " + T(170), () => Show(Page.Main));
                    break;
                case Page.Cargo:
                    title.text = T(166);
                    BuildCargo();
                    Item("‹  " + T(170), () => Show(Page.Main));
                    break;
                case Page.Options:
                    title.text = T(31);
                    BuildOptions();
                    Item("‹  " + T(170), () => Show(Page.Main));
                    break;
            }
            Highlight();
        }

        void Item(string text, Action action)
        {
            var b = new Button { text = text, focusable = false };
            b.AddToClassList("autopilot-menu-item");
            b.AddToClassList("gof-semibold");
            b.clicked += action;
            body.Add(b);
            items.Add(b);
            actions.Add(action);
        }

        Label Text(string text, string cls = "pause-text")
        {
            var l = new Label(text) { pickingMode = PickingMode.Ignore };
            l.AddToClassList(cls);
            (scroll != null ? (VisualElement)scroll : body).Add(l);
            return l;
        }

        ScrollView Scroll()
        {
            scroll = new ScrollView(ScrollViewMode.Vertical) { horizontalScrollerVisibility = ScrollerVisibility.Hidden };
            scroll.AddToClassList("pause-scroll");
            // A ScrollView doesn't grow with its content: size it to the content, up to 560 px, then it scrolls.
            var sv = scroll;
            sv.contentContainer.RegisterCallback<GeometryChangedEvent>(e => sv.style.height = Mathf.Min(560f, e.newRect.height));
            body.Add(scroll);
            return scroll;
        }

        /// <summary>MissionsWindow's two panels as text: the story objective and the freelance offer.</summary>
        void BuildMissions()
        {
            var db = level != null ? level.Database : null;
            Scroll();
            Text(T(555), "pause-heading");
            bool story = !Session.FreePlay && !Session.StoryMission.IsEmpty && Session.StoryMission.visible && db != null;
            Text(story ? Story.ObjectiveText(db) : Localization.Get(174));
            Text(T(556), "pause-heading");
            var m = Freelance.Mission;
            if (Freelance.Active && db != null)
            {
                string station = db.Stations.Find(s => s.index == m.clientStation)?.name ?? "";
                Text($"{m.clientName} · {station} · {m.Name}", "pause-subheading");
                Text(MissionsWindow.FreelanceText(db, m));
            }
            else Text(Localization.Get(174));
        }

        /// <summary>The cargo hold: every cargo stack with its tonnage, and the load against the capacity.</summary>
        void BuildCargo()
        {
            var db = level != null ? level.Database : null;
            int load = Shop.CargoLoad(), max = db != null ? Shop.MaxLoad(db) : 0;
            Text($"{load} / {max} t", load > max ? "pause-heading--red" : "pause-heading");
            Scroll();
            if (Session.Cargo.Count == 0) { Text(Localization.Get(174)); return; }
            foreach (var s in Session.Cargo)
            {
                var row = new VisualElement { pickingMode = PickingMode.Ignore };
                row.AddToClassList("pause-cargo-row");
                var icon = new VisualElement { pickingMode = PickingMode.Ignore };
                icon.AddToClassList("pause-cargo-icon");
                var tex = ItemInfo.ItemIcon(s.item);
                if (tex != null) icon.style.backgroundImage = new StyleBackground(tex);
                row.Add(icon);
                var name = new Label(Localization.Get(1274 + s.item)) { pickingMode = PickingMode.Ignore };
                name.AddToClassList("pause-cargo-name");
                row.Add(name);
                var amount = new Label($"{s.amount} t") { pickingMode = PickingMode.Ignore };
                amount.AddToClassList("pause-cargo-amount");
                row.Add(amount);
                scroll.Add(row);
            }
        }

        readonly List<VisualElement> optionRows = new List<VisualElement>();

        /// <summary>The in-flight options: music / FX / voice volume, sensitivity, invert (the main menu's Options pages).</summary>
        void BuildOptions()
        {
            optionRows.Clear();
            Slider Volume(int text, float value, Action<float> set)
            {
                var s = new Slider(Localization.Get(text), 0f, 1f) { value = value };
                s.RegisterValueChangedCallback(e => set(e.newValue));
                return s;
            }
            var sens = new Slider($"{Localization.Get(499)}: {Settings.Sensitivity:0.0}", 0.2f, 2.2f) { value = Settings.Sensitivity };
            sens.RegisterValueChangedCallback(e => { Settings.Sensitivity = e.newValue; sens.label = $"{Localization.Get(499)}: {Settings.Sensitivity:0.0}"; });
            var invert = new Toggle(Localization.Get(500)) { value = Settings.InvertPitch };
            invert.RegisterValueChangedCallback(e => Settings.InvertPitch = e.newValue);
            foreach (var e in new VisualElement[]
                     {
                         Volume(34, Settings.MusicVolume, v => Settings.MusicVolume = v),
                         Volume(35, Settings.SfxVolume, v => Settings.SfxVolume = v),
                         Volume(36, Settings.VoiceVolume, v => Settings.VoiceVolume = v),
                         sens, invert,
                     })
            {
                e.AddToClassList("pause-option");
                e.focusable = false;
                body.Add(e);
                items.Add(e);
                actions.Add(null);
                optionRows.Add(e);
            }
        }

        void Highlight()
        {
            bool keys = InputMode.Current != InputKind.Touch;
            for (int i = 0; i < items.Count; i++) items[i].EnableInClassList("autopilot-menu-item--selected", keys && i == index);
        }

        // ---- input (unscaled: the game is paused) -------------------------------------------------------------

        public void Tick()
        {
            if (!IsOpen || Time.frameCount - openedFrame < 1) return;   // the key that opened it
            var kb = Keyboard.current;
            var pad = Gamepad.current;
            bool back = (kb != null && (kb.escapeKey.wasPressedThisFrame || kb.backspaceKey.wasPressedThisFrame))
                        || (pad != null && (pad.buttonEast.wasPressedThisFrame || pad.startButton.wasPressedThisFrame));
            if (back)
            {
                if (page == Page.Main) Close(); else Show(Page.Main);
                return;
            }
            int move = 0;
            if (kb != null && (kb.wKey.wasPressedThisFrame || kb.upArrowKey.wasPressedThisFrame)) move = -1;
            if (kb != null && (kb.sKey.wasPressedThisFrame || kb.downArrowKey.wasPressedThisFrame)) move = 1;
            if (pad != null && (pad.dpad.up.wasPressedThisFrame || pad.leftStick.up.wasPressedThisFrame)) move = -1;
            if (pad != null && (pad.dpad.down.wasPressedThisFrame || pad.leftStick.down.wasPressedThisFrame)) move = 1;
            if (move != 0 && items.Count > 0)
            {
                index = (index + move + items.Count) % items.Count;
                Highlight();
                if (scroll != null) scroll.scrollOffset += new Vector2(0f, move * 120f);
            }
            int side = 0;
            if (kb != null && (kb.aKey.wasPressedThisFrame || kb.leftArrowKey.wasPressedThisFrame)) side = -1;
            if (kb != null && (kb.dKey.wasPressedThisFrame || kb.rightArrowKey.wasPressedThisFrame)) side = 1;
            if (pad != null && (pad.dpad.left.wasPressedThisFrame || pad.leftStick.left.wasPressedThisFrame)) side = -1;
            if (pad != null && (pad.dpad.right.wasPressedThisFrame || pad.leftStick.right.wasPressedThisFrame)) side = 1;
            var current = index < items.Count ? items[index] : null;
            if (side != 0 && current is Slider slider)
                slider.value = Mathf.Clamp(slider.value + side * (slider.highValue - slider.lowValue) / 20f, slider.lowValue, slider.highValue);
            bool confirm = (kb != null && (kb.enterKey.wasPressedThisFrame || kb.numpadEnterKey.wasPressedThisFrame || kb.spaceKey.wasPressedThisFrame))
                           || (pad != null && pad.buttonSouth.wasPressedThisFrame);
            if (!confirm || current == null) return;
            if (current is Toggle toggle) toggle.value = !toggle.value;
            else actions[index]?.Invoke();
        }
    }
}
