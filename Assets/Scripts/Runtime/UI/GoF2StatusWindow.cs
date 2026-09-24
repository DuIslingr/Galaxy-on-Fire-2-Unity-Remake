// GoF2StatusWindow.cs
// The Status window (StatusWindow 0x18345c / reInit 0x183784 / draw 0x183a64 / getMedalHintText 0x185da4; Reference/
// research/lounge_ui.md 6), station button 169 "Status". HD layout, both columns side by side:
//   left   1597 Keith T. Maxwell (credits, 321 Level N, playing time hh:mm), the ship (icon, name, 569 Fire power, 570
//          Defense), 576 Reputation (Terran / Vossk and Nivelian / Midorian bars, the marker toward the liked race, the
//          emblem tinted while that race is hostile), 577 Statistics (568 missions, 176 kills, 552 asteroids, 559 cargo
//          salvaged, 557 stations, 3235 battleships | 564 jumpgates, 558 goods produced, 560 ore, 561 cores, 567 wingmen)
//   right  168 Medals: 45 plates in three columns, coloured by grade (GoF2Achievements); an earned medal shows its hint
//          (1552 + i, # = the threshold of its grade)
// Fire power: the original's Ship::getFirePower formula was not recovered; the remake shows the mounted primaries' damage
// per second. Medal images aren't cut from the interface atlas yet: text plates stand in. Plain class driven by
// GoF2StationMenu.

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.World;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class GoF2StatusWindow
    {
        readonly GoF2StationMenu menu;
        readonly GoF2StationLevel level;
        readonly VisualElement root, left, grid;
        readonly Label hint;
        readonly Button close;
        readonly List<Button> medalButtons = new List<Button>();
        int selectedMedal = -1;

        static string T(int id) => GoF2Localization.Get(id);

        public GoF2StatusWindow(GoF2StationMenu menu, GoF2StationLevel level, VisualElement root)
        {
            this.menu = menu;
            this.level = level;
            this.root = root;
            left = root.Q("statusLeft");
            grid = root.Q("medalGrid");
            hint = root.Q<Label>("medalHint");
            close = root.Q<Button>("statusClose");
            close.text = GoF2Localization.Extra("hudBack", "BACK");
            close.RegisterCallback<PointerDownEvent>(_ => menu.PlayPush(), TrickleDown.TrickleDown);
            close.clicked += () => { menu.PlayRelease(); Close(); };
            root.Q<Label>("statusTitle").text = T(169).ToUpperInvariant();
            root.Q<Label>("medalsTitle").text = T(168).ToUpperInvariant();
            var scroll = root.Q<ScrollView>("medalScroll");
            scroll.verticalScrollerVisibility = ScrollerVisibility.Auto;
            scroll.horizontalScrollerVisibility = ScrollerVisibility.Hidden;
        }

        public bool IsOpen => root.ClassListContains("status-open");

        public void Open()
        {
            root.AddToClassList("status-open");
            Build();
        }

        public void Close()
        {
            if (!IsOpen) return;
            root.RemoveFromClassList("status-open");
            menu.OnStatusClosed();
        }

        void Build()
        {
            var db = level.Database;
            left.Clear();
            // Pilot and ship.
            Plate(left, T(1597));
            var row = Row(left);
            var pilot = Box(row, false);
            pilot.AddToClassList("status-pilot");
            var portrait = new VisualElement { pickingMode = PickingMode.Ignore };
            portrait.AddToClassList("portrait");
            pilot.Add(portrait);
            GoF2Portrait.ShowSpeaker(portrait, 0, false);
            var lines = new VisualElement { pickingMode = PickingMode.Ignore };
            lines.AddToClassList("status-pilot-lines");
            pilot.Add(lines);
            Line(lines, GoF2ItemInfo.Credits(GoF2Session.Credits), true);
            Line(lines, $"{T(321)} {GoF2Session.Rank}", false);
            int minutes = (int)(GoF2Session.PlaySeconds / 60f);
            Line(lines, $"{minutes / 60:00}:{minutes % 60:00}", false);

            var shipBox = Box(row, true);
            var icon = new VisualElement { pickingMode = PickingMode.Ignore };
            icon.AddToClassList("status-ship-icon");
            icon.style.backgroundImage = new StyleBackground(GoF2ItemInfo.ShipIcon(GoF2Session.ShipIndex));
            shipBox.Add(icon);
            Line(shipBox, GoF2ItemInfo.ShipName(GoF2Session.ShipIndex), true);
            StatLine(shipBox, T(569), FirePower(db).ToString("0.0"));
            StatLine(shipBox, T(570), CombinedHp(db).ToString());

            // Reputation.
            Plate(left, T(576));
            var rep = Row(left);
            Reputation(Box(rep, false), 0, 1, GoF2Session.Standing[0]);
            Reputation(Box(rep, true), 2, 3, GoF2Session.Standing[1]);

            // Statistics.
            Plate(left, T(577));
            var stats = Row(left);
            var a = Box(stats, false);
            StatLine(a, T(568), GoF2Session.FreelanceCompleted.ToString());
            StatLine(a, T(176), GoF2Session.Kills.ToString());
            StatLine(a, T(552), GoF2Session.AsteroidsDestroyed.ToString());
            StatLine(a, T(559), GoF2Session.CratesSalvaged.ToString());
            StatLine(a, T(557), GoF2Session.VisitedStations.Count.ToString());
            StatLine(a, T(3235), GoF2Session.BattleshipsDestroyed.ToString());
            var b = Box(stats, true);
            StatLine(b, T(564), GoF2Session.JumpgatesUsed.ToString());
            StatLine(b, T(558), GoF2Session.GoodsProduced.ToString());
            StatLine(b, T(560), GoF2Session.OreMined.ToString());
            StatLine(b, T(561), GoF2Session.CoresMined.ToString());
            StatLine(b, T(567), GoF2Session.WingmenHired.ToString());

            // Medals.
            grid.Clear();
            medalButtons.Clear();
            for (int i = 0; i < GoF2Achievements.Count; i++)
            {
                int medal = i;
                int grade = GoF2Achievements.Grade(i);
                var m = new Button();
                m.AddToClassList("medal");
                if (grade > 0) m.AddToClassList("medal--earned");
                m.AddToClassList(grade == 1 ? "medal--gold" : grade == 2 ? "medal--silver" : grade == 3 ? "medal--bronze" : "medal--none");
                var g = new Label(grade == 1 ? "GOLD" : grade == 2 ? "SILVER" : grade == 3 ? "BRONZE" : "—") { pickingMode = PickingMode.Ignore };
                g.AddToClassList("medal-grade");
                g.AddToClassList("gof-semibold");
                m.Add(g);
                var n = new Label(T(1507 + i)) { pickingMode = PickingMode.Ignore };
                n.AddToClassList("medal-name");
                n.AddToClassList("gof-semibold");
                m.Add(n);
                // Only earned medals react (TouchButton enabled by level).
                m.clicked += () => { if (GoF2Achievements.Grade(medal) > 0) { menu.PlayRelease(); ShowHint(medal); } };
                m.RegisterCallback<FocusInEvent>(_ => { if (GoF2Achievements.Grade(medal) > 0) ShowHint(medal); });
                grid.Add(m);
                medalButtons.Add(m);
            }
            hint.text = T(647);
            menu.Focus(close);
        }

        void ShowHint(int medal)
        {
            selectedMedal = medal;
            for (int i = 0; i < medalButtons.Count; i++) medalButtons[i].EnableInClassList("medal--selected", i == medal);
            hint.text = $"{T(1507 + medal)}\n{GoF2Achievements.Hint(medal)}";
        }

        /// <summary>The mounted primaries' damage per second (Ship::getFirePower's formula is lost; an assumption).</summary>
        static float FirePower(GoF2Database db)
        {
            float dps = 0f;
            foreach (var e in GoF2Session.Equipment)
            {
                var it = db.Item(e.item);
                if (it == null || it.TypeId != 0) continue;
                float reload = Mathf.Max(1, it.Stat("loadingTimeMs", 500));
                dps += it.Stat("damage") * 1000f / reload;
            }
            return dps;
        }

        /// <summary>Ship::getCombinedHP: hull (+ mod) + shield + armor.</summary>
        static int CombinedHp(GoF2Database db)
        {
            int hull = (db.Ship(GoF2Session.ShipIndex)?.armor ?? 0) + (GoF2Session.HasMod(0) ? 40 : 0);
            var shield = GoF2Shop.FirstMounted(db, 9);
            var armor = GoF2Shop.FirstMounted(db, 10);
            return hull + (shield != null ? shield.Attr(18) : 0) + (armor != null ? armor.Attr(20) : 0);
        }

        // ---- building blocks -----------------------------------------------------------------------------

        static void Plate(VisualElement parent, string text)
        {
            var l = new Label(text.ToUpperInvariant()) { pickingMode = PickingMode.Ignore };
            l.AddToClassList("status-plate");
            l.AddToClassList("gof-semibold");
            parent.Add(l);
        }

        static VisualElement Row(VisualElement parent)
        {
            var r = new VisualElement { pickingMode = PickingMode.Ignore };
            r.AddToClassList("status-row");
            parent.Add(r);
            return r;
        }

        static VisualElement Box(VisualElement parent, bool last)
        {
            var b = new VisualElement { pickingMode = PickingMode.Ignore };
            b.AddToClassList("status-box");
            if (last) b.AddToClassList("status-box--last");
            parent.Add(b);
            return b;
        }

        static void Line(VisualElement parent, string text, bool big)
        {
            var l = new Label(text) { pickingMode = PickingMode.Ignore };
            l.AddToClassList(big ? "status-big" : "status-line");
            if (big) l.AddToClassList("gof-semibold");
            parent.Add(l);
        }

        static void StatLine(VisualElement parent, string label, string value)
        {
            var row = new VisualElement { pickingMode = PickingMode.Ignore };
            row.AddToClassList("stat-line");
            var a = new Label(label) { pickingMode = PickingMode.Ignore };
            a.AddToClassList("stat-line-label");
            var b = new Label(value) { pickingMode = PickingMode.Ignore };
            b.AddToClassList("stat-line-value");
            b.AddToClassList("gof-semibold");
            row.Add(a);
            row.Add(b);
            parent.Add(row);
        }

        /// <summary>A reputation bar: rate = standing / 100 toward the first race (+) or the second (-).</summary>
        static void Reputation(VisualElement box, int raceA, int raceB, int standing)
        {
            var row = new VisualElement { pickingMode = PickingMode.Ignore };
            row.AddToClassList("rep-row");
            row.Add(Emblem(raceA));
            var track = new VisualElement { pickingMode = PickingMode.Ignore };
            track.AddToClassList("rep-track");
            float rate = Mathf.Clamp(standing / 100f, -1f, 1f);
            var fill = new VisualElement { pickingMode = PickingMode.Ignore };
            fill.AddToClassList("rep-fill");
            // Drawn from the centre toward the favoured side (the left race when positive).
            fill.style.left = Length.Percent(rate > 0f ? 50f - rate * 50f : 50f);
            fill.style.width = Length.Percent(Mathf.Abs(rate) * 50f);
            track.Add(fill);
            var marker = new VisualElement { pickingMode = PickingMode.Ignore };
            marker.AddToClassList("rep-marker");
            marker.style.left = Length.Percent(50f - rate * 50f);
            track.Add(marker);
            row.Add(track);
            row.Add(Emblem(raceB));
            box.Add(row);
            var names = new VisualElement { pickingMode = PickingMode.Ignore };
            names.AddToClassList("rep-names");
            var na = new Label(T(406 + raceA)) { pickingMode = PickingMode.Ignore };
            na.AddToClassList("rep-name");
            var nb = new Label(T(406 + raceB)) { pickingMode = PickingMode.Ignore };
            nb.AddToClassList("rep-name");
            names.Add(na);
            names.Add(nb);
            box.Add(names);
        }

        static VisualElement Emblem(int race)
        {
            var e = new VisualElement { pickingMode = PickingMode.Ignore };
            e.AddToClassList("rep-emblem");
            var tex = Resources.Load<Texture2D>($"GoF2Hud/race_{race}");
            if (tex != null) e.style.backgroundImage = new StyleBackground(tex);
            e.EnableInClassList("rep-emblem--hostile", GoF2Standing.IsEnemy(race));
            return e;
        }

        public VisualElement[] NavItems()
        {
            var l = new List<VisualElement>(medalButtons) { close };
            return l.ToArray();
        }
    }
}
