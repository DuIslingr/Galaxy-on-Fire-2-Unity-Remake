// GoF2MissionsWindow.cs
// The Missions window (MissionsWindow::init 0x17a604 / OnTouchEnd 0x17bbc0; Reference/research/freelance_missions.md 3.4):
// title 129 "Missions", tabs 555 "Story" / 556 "Freelance". Story: the campaign mission's objective text. Freelance: the
// client's portrait and the offer as the agent said it (#C = reward + the current standing bonus), or 174 "-BLANK-";
// 424 "Show on map" (the star map in mission mode) and, only in a station, 423 "Discard" -> 418 "Are you sure?".
// Plain class driven by GoF2StationMenu.

using GoF2Remake.Data;
using GoF2Remake.World;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class GoF2MissionsWindow
    {
        readonly GoF2StationMenu menu;
        readonly GoF2StationLevel level;
        readonly VisualElement root, portrait;
        readonly Button tabStory, tabFreelance, close, mapButton, discardButton;
        readonly Label heading, text;
        readonly ScrollView scroll;
        bool freelanceTab;

        static string T(int id) => GoF2Localization.Get(id);

        public GoF2MissionsWindow(GoF2StationMenu menu, GoF2StationLevel level, VisualElement root)
        {
            this.menu = menu;
            this.level = level;
            this.root = root;
            portrait = root.Q("missionsPortrait");
            heading = root.Q<Label>("missionsHeading");
            text = root.Q<Label>("missionsText");
            scroll = root.Q<ScrollView>("missionsScroll");
            scroll.verticalScrollerVisibility = ScrollerVisibility.Auto;
            scroll.horizontalScrollerVisibility = ScrollerVisibility.Hidden;
            tabStory = Bind("missionsTabStory", () => ShowTab(false));
            tabFreelance = Bind("missionsTabFreelance", () => ShowTab(true));
            close = Bind("missionsClose", Close);
            mapButton = Bind("missionsMap", ShowOnMap);
            discardButton = Bind("missionsDiscard", AskDiscard);
            tabStory.text = T(555).ToUpperInvariant();
            tabFreelance.text = T(556).ToUpperInvariant();
            close.text = GoF2Localization.Extra("hudBack", "BACK");
            mapButton.text = T(424).ToUpperInvariant();
            discardButton.text = T(423).ToUpperInvariant();
        }

        Button Bind(string name, System.Action action)
        {
            var b = root.Q<Button>(name);
            b.RegisterCallback<PointerDownEvent>(_ => menu.PlayPush(), TrickleDown.TrickleDown);
            b.clicked += () => { menu.PlayRelease(); action(); };
            return b;
        }

        public bool IsOpen => root.ClassListContains("missions-open");

        public void Open()
        {
            root.AddToClassList("missions-open");
            // The freelance tab first when there is no story (free play) or a freelance mission is running.
            ShowTab(GoF2Session.FreePlay || GoF2Freelance.Active);
        }

        public void Close()
        {
            if (!IsOpen) return;
            root.RemoveFromClassList("missions-open");
            menu.OnMissionsClosed();
        }

        public void NextTab() => ShowTab(!freelanceTab);

        void ShowTab(bool freelance)
        {
            freelanceTab = freelance;
            tabStory.EnableInClassList("hangar-tab--active", !freelance);
            tabFreelance.EnableInClassList("hangar-tab--active", freelance);
            var db = level.Database;
            if (!freelance)
            {
                portrait.AddToClassList("portrait-hidden");
                bool story = !GoF2Session.FreePlay && !GoF2Session.StoryMission.IsEmpty && GoF2Session.StoryMission.visible;
                heading.text = story ? T(555).ToUpperInvariant() : "";
                text.text = story ? GoF2Story.ObjectiveText(db) : T(174);
                mapButton.style.display = story && GoF2Session.StoryMission.station >= 0 ? DisplayStyle.Flex : DisplayStyle.None;
                discardButton.style.display = DisplayStyle.None;
            }
            else
            {
                var m = GoF2Freelance.Mission;
                bool active = GoF2Freelance.Active;
                portrait.EnableInClassList("portrait-hidden", !active);
                if (active) GoF2Portrait.Show(portrait, m.clientPortrait, false);
                heading.text = active ? $"{m.Name} · {m.clientName}".ToUpperInvariant() : "";
                text.text = active ? FreelanceText(db, m) : T(174);
                mapButton.style.display = active ? DisplayStyle.Flex : DisplayStyle.None;
                discardButton.style.display = active ? DisplayStyle.Flex : DisplayStyle.None;
            }
            scroll.scrollOffset = Vector2.zero;
            menu.Focus(mapButton.resolvedStyle.display != DisplayStyle.None ? mapButton : close);
        }

        /// <summary>Globals::getAgentMissionText: the offer text rebuilt from the stored ids with the current values.</summary>
        static string FreelanceText(GoF2Database db, GoF2FreelanceMission m)
        {
            var agent = new GoF2Agent { name = m.clientName, race = m.clientRace, male = m.clientMale, offer = m.type == GoF2MissionType.Purchase ? GoF2AgentOffer.Purchase : GoF2AgentOffer.Mission, mission = m };
            var chat = new GoF2LoungeChat(db, agent, GoF2Session.StationIndex, null);
            var ids = m.textIds != null && m.textIds.Count >= 6 ? m.textIds : new System.Collections.Generic.List<int> { -1, -1, -1, -1, -1, -1 };
            // Only the offer itself (no greeting or question) belongs in the window.
            return chat.Compose(agent, new System.Collections.Generic.List<int> { -1, -1, -1, ids[3], ids[4], -1 });
        }

        void ShowOnMap()
        {
            int target = freelanceTab ? GoF2Freelance.Mission.target : GoF2Session.StoryMission.station;
            if (target < 0) return;
            root.AddToClassList("station-map-open");
            var map = GoF2StarMap.Open(level.Database, GoF2StarMapMode.Mission, true, _ => { root.RemoveFromClassList("station-map-open"); menu.Focus(mapButton); }, -1, target);
            if (map == null) root.RemoveFromClassList("station-map-open");
        }

        /// <summary>423 Discard -> 418 "Are you sure?" -> the same clean-up as a discarded mission.</summary>
        void AskDiscard()
        {
            menu.ShowDialog(T(418), () => { GoF2Freelance.Discard(); ShowTab(true); menu.RefreshCredits(); });
        }

        public VisualElement[] NavItems()
        {
            var l = new System.Collections.Generic.List<VisualElement>();
            if (mapButton.resolvedStyle.display != DisplayStyle.None) l.Add(mapButton);
            if (discardButton.resolvedStyle.display != DisplayStyle.None) l.Add(discardButton);
            l.Add(close);
            return l.ToArray();
        }
    }
}
