// PauseMenu.cs
// The in-flight pause menu (MenuTouchWindow mode 1, Reference/research/mainmenu_notes.md 2.4): header 40 "Pause", then
// 41 Resume, 129 Missions (from campaign 16, not in the alien orbit), 166 Cargo hold (from 2), 31 Options, 59 Action Freeze
// (PhotoMode), 395 Skip (LevelScript::canSkipCutsceneNow: the prologue / rescue, 154, 157, 158) and 522 Back to Main Menu
// (confirm 523). The game and its sounds pause while it is open. Options holds the main menu's options (OptionsCatalog)
// but the language. Also the ChoiceWindow (Ask: Loma's toll 448, the flight hints). The share buttons (60 / 61) are dead
// code in the original (the remake's 60 saves the picture).
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
        enum Page { Main, Missions, Cargo, Options, Quit, Photo, Choice }

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
        /// <summary>ChoiceWindow::set: sound 126 when the confirmation shows.</summary>
        public Action InfoSound;
        /// <summary>59 Action Freeze (MenuTouchWindow button 0x13 -> state 0xd); set by FlightHud.</summary>
        public PhotoMode Photo;

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

        string choiceText, choiceYes, choiceNo;
        Action choiceOnYes, choiceOnNo;

        /// <summary>A ChoiceWindow in flight (MGame+0x90, e.g. Loma's toll 448): the game and its sounds pause (MGame+0x5d,
        /// pauseSounds) until it is answered; Back picks the second answer. 'no' null = a message with one button.</summary>
        public void Ask(SpaceLevel spaceLevel, string text, string yes, string no, Action onYes, Action onNo)
        {
            choiceText = text;
            choiceYes = yes;
            choiceNo = no;
            choiceOnYes = onYes;
            choiceOnNo = onNo;
            if (!IsOpen) Open(spaceLevel);
            Show(Page.Choice);
        }

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
            if (Photo != null && Photo.Active) Photo.Exit();
            IsOpen = false;
            backdrop.RemoveFromClassList("pause-backdrop--shown");
            AudioListener.pause = audioWasPaused;
            if (level != null && level.Navigation != null) level.Navigation.PauseMenuOpen = false;   // restores its own time scale
            else Time.timeScale = previousTimeScale;
            // Options changed here reach the ship at once (SpaceLevel.ApplyOptions).
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
                    // MenuTouchWindow mode 1: Missions from campaign 16 (not in the alien orbit), the cargo hold from 2.
                    int cm = Session.FreePlay ? 20 : Session.CampaignMission;
                    if (cm >= 16 && (level == null || !level.Layout.alienOrbit)) Item(T(129), () => Show(Page.Missions));
                    if (cm >= 2) Item(T(166), () => Show(Page.Cargo));
                    Item(T(31), () => Show(Page.Options));
                    var campaign = level != null ? level.Campaign : null;
                    if (campaign != null && campaign.CanSkipCutscene) Item(T(395), () => { Close(); campaign.SkipCutscene(); });
                    // MGame::setCinematicMode: not while a cutscene holds the camera.
                    if (Photo != null && level != null && !level.Cutscene) Item(T(59), () => Show(Page.Photo));
                    Item(T(522), () => Show(Page.Quit));
                    break;
                case Page.Photo:
                    backdrop.RemoveFromClassList("pause-backdrop--shown");
                    Photo.Enter(level);
                    if (!Photo.Active) { backdrop.AddToClassList("pause-backdrop--shown"); Show(Page.Main); }
                    return;
                case Page.Choice:
                    title.text = "";
                    Text(choiceText);
                    InfoSound?.Invoke();
                    Item((choiceYes ?? Localization.Extra("ok", "OK")).ToUpperInvariant(), () => { Close(); var a = choiceOnYes; choiceOnYes = choiceOnNo = null; a?.Invoke(); });
                    if (choiceNo != null) Item(choiceNo.ToUpperInvariant(), () => { Close(); var a = choiceOnNo; choiceOnYes = choiceOnNo = null; a?.Invoke(); });
                    break;
                case Page.Quit:
                    title.text = T(522);
                    Text(Localization.Get(523));
                    InfoSound?.Invoke();
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

        readonly Dictionary<VisualElement, OptionControl> optionRows = new Dictionary<VisualElement, OptionControl>();

        /// <summary>The main menu's options (OptionsCatalog) page by page under their headings, then Default settings (497).
        /// Rows don't take focus: the keys / D-pad drive them through Tick.</summary>
        void BuildOptions()
        {
            optionRows.Clear();
            Scroll();
            OptionPage? page = null;
            foreach (var def in OptionsCatalog.All())
            {
                if (page != def.page) { page = def.page; Text(OptionsCatalog.PageTitle(def.page).ToUpperInvariant(), "pause-heading"); }
                var c = new OptionControl(def);
                c.Field.focusable = false;
                c.Changed += () => { foreach (var o in optionRows.Values) if (o != c) o.Refresh(); };   // STP turns MSAA off
                c.Root.AddToClassList("pause-option");
                scroll.Add(c.Root);
                items.Add(c.Root);
                actions.Add(null);
                optionRows[c.Root] = c;
            }
            Item(T(497), () => { Settings.ResetToDefaults(); foreach (var c in optionRows.Values) c.Refresh(); });
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
            if (page == Page.Photo)
            {
                // Back leaves state 0xd for the pause page; the game stays paused.
                if (Photo == null || !Photo.Tick()) { backdrop.AddToClassList("pause-backdrop--shown"); Show(Page.Main); openedFrame = Time.frameCount; }
                return;
            }
            var kb = Keyboard.current;
            var pad = Gamepad.current;
            bool back = (kb != null && (kb.escapeKey.wasPressedThisFrame || kb.backspaceKey.wasPressedThisFrame))
                        || (pad != null && (pad.buttonEast.wasPressedThisFrame || pad.startButton.wasPressedThisFrame));
            if (back)
            {
                if (page == Page.Choice) actions[actions.Count - 1]?.Invoke();   // the second answer (or the only one)
                else if (page == Page.Main) Close(); else Show(Page.Main);
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
                if (scroll != null && scroll.contentContainer.Contains(items[index])) scroll.ScrollTo(items[index]);
                else if (scroll != null) scroll.scrollOffset += new Vector2(0f, move * 120f);
            }
            int side = 0;
            if (kb != null && (kb.aKey.wasPressedThisFrame || kb.leftArrowKey.wasPressedThisFrame)) side = -1;
            if (kb != null && (kb.dKey.wasPressedThisFrame || kb.rightArrowKey.wasPressedThisFrame)) side = 1;
            if (pad != null && (pad.dpad.left.wasPressedThisFrame || pad.leftStick.left.wasPressedThisFrame)) side = -1;
            if (pad != null && (pad.dpad.right.wasPressedThisFrame || pad.leftStick.right.wasPressedThisFrame)) side = 1;
            var current = index < items.Count ? items[index] : null;
            optionRows.TryGetValue(current ?? backdrop, out var option);
            if (side != 0 && option != null) option.Step(side);
            bool confirm = (kb != null && (kb.enterKey.wasPressedThisFrame || kb.numpadEnterKey.wasPressedThisFrame || kb.spaceKey.wasPressedThisFrame))
                           || (pad != null && pad.buttonSouth.wasPressedThisFrame);
            if (!confirm || current == null) return;
            if (option != null) option.Activate();
            else actions[index]?.Invoke();
        }
    }
}
