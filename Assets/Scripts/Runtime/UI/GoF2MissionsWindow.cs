// GoF2MissionsWindow.cs
// The Missions window (MissionsWindow::init 0x17a604 / draw 0x17b240 / OnTouchEnd 0x17bbc0; Reference/research/
// lounge_ui.md 5, freelance_missions.md 3.4): title 129 "Missions", two panels side by side:
//   555 "Story"      the campaign objective text (story.json objectiveText, # = the target station), 424 "Show on map"
//   556 "Freelance"  the client's portrait, name, station and mission type (354 + type), the offer as the agent said it
//                    (#C = reward + the current standing bonus), 424 "Show on map" and, only in a station, 423 "Discard"
//                    (red) -> 418 "Are you sure?"; no mission: 174 "-BLANK-"
// Show on map opens the star map in mission mode (StarMap(true, mission)). Locked before campaign 9 like the Map.
// Plain class driven by GoF2StationMenu.

using System.Collections.Generic;
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
        readonly Button close, storyMap, freelanceMap, discard;
        readonly Label storyText, freelanceText, freelanceClient, freelanceWhere;
        readonly ScrollView storyScroll, freelanceScroll;

        static string T(int id) => GoF2Localization.Get(id);

        public GoF2MissionsWindow(GoF2StationMenu menu, GoF2StationLevel level, VisualElement root)
        {
            this.menu = menu;
            this.level = level;
            this.root = root;
            portrait = root.Q("missionsPortrait");
            storyText = root.Q<Label>("storyText");
            freelanceText = root.Q<Label>("freelanceText");
            freelanceClient = root.Q<Label>("freelanceClient");
            freelanceWhere = root.Q<Label>("freelanceWhere");
            storyScroll = Scroll("storyScroll");
            freelanceScroll = Scroll("freelanceScroll");
            close = Bind("missionsClose", Close);
            storyMap = Bind("storyMap", () => ShowOnMap(GoF2Session.StoryMission.station, storyMap));
            freelanceMap = Bind("freelanceMap", () => ShowOnMap(GoF2Freelance.Mission.target, freelanceMap));
            discard = Bind("freelanceDiscard", AskDiscard);
            root.Q<Label>("missionsTitle").text = T(129).ToUpperInvariant();
            root.Q<Label>("storyHeading").text = T(555).ToUpperInvariant();
            root.Q<Label>("freelanceHeading").text = T(556).ToUpperInvariant();
            close.text = GoF2Localization.Extra("hudBack", "BACK");
            storyMap.text = freelanceMap.text = T(424).ToUpperInvariant();
            discard.text = T(423).ToUpperInvariant();
        }

        ScrollView Scroll(string name)
        {
            var s = root.Q<ScrollView>(name);
            s.verticalScrollerVisibility = ScrollerVisibility.Auto;
            s.horizontalScrollerVisibility = ScrollerVisibility.Hidden;
            return s;
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
            Fill();
        }

        public void Close()
        {
            if (!IsOpen) return;
            root.RemoveFromClassList("missions-open");
            menu.OnMissionsClosed();
        }

        void Fill()
        {
            var db = level.Database;
            // Story: the objective text; no button once there is nothing to show.
            bool story = !GoF2Session.FreePlay && !GoF2Session.StoryMission.IsEmpty && GoF2Session.StoryMission.visible;
            storyText.text = story ? GoF2Story.ObjectiveText(db) : T(174);
            Show(storyMap, story && GoF2Session.StoryMission.station >= 0);

            var m = GoF2Freelance.Mission;
            bool active = GoF2Freelance.Active;
            portrait.EnableInClassList("portrait-hidden", !active);
            if (active) GoF2Portrait.Show(portrait, m.clientPortrait, false);
            freelanceClient.text = active ? m.clientName.ToUpperInvariant() : "";
            string station = active ? db.Stations.Find(s => s.index == m.clientStation)?.name ?? "" : "";
            freelanceWhere.text = active ? $"{station}\n{m.Name}" : "";
            freelanceText.text = active ? FreelanceText(db, m) : T(174);
            Show(freelanceMap, active);
            Show(discard, active);
            storyScroll.scrollOffset = freelanceScroll.scrollOffset = Vector2.zero;
            menu.Focus(active ? freelanceMap : story ? storyMap : close);
        }

        static void Show(VisualElement e, bool on) => e.style.display = on ? DisplayStyle.Flex : DisplayStyle.None;

        /// <summary>Globals::getAgentMissionText: the offer text rebuilt from the stored ids with the current values.</summary>
        static string FreelanceText(GoF2Database db, GoF2FreelanceMission m)
        {
            var agent = new GoF2Agent
            {
                name = m.clientName, race = m.clientRace, male = m.clientMale, mission = m,
                offer = m.type == GoF2MissionType.Purchase ? GoF2AgentOffer.Purchase : GoF2AgentOffer.Mission,
            };
            var chat = new GoF2LoungeChat(db, agent, GoF2Session.StationIndex, null);
            var ids = m.textIds != null && m.textIds.Count >= 6 ? m.textIds : new List<int> { -1, -1, -1, -1, -1, -1 };
            // Only the offer itself (no greeting or question) belongs in the window.
            return chat.Compose(agent, new List<int> { -1, -1, -1, ids[3], ids[4], -1 });
        }

        void ShowOnMap(int target, Button from)
        {
            if (target < 0) return;
            root.AddToClassList("station-map-open");
            var map = GoF2StarMap.Open(level.Database, GoF2StarMapMode.Mission, false, _ => { root.RemoveFromClassList("station-map-open"); menu.Focus(from); }, -1, target);
            if (map == null) root.RemoveFromClassList("station-map-open");
        }

        /// <summary>423 Discard -> 418 "Are you sure?" -> the same clean-up as a discarded mission.</summary>
        void AskDiscard()
        {
            menu.ShowDialog(T(418), () => { GoF2Freelance.Discard(); Fill(); menu.RefreshCredits(); });
        }

        public VisualElement[] NavItems()
        {
            var l = new List<VisualElement>();
            foreach (var b in new[] { storyMap, freelanceMap, discard })
                if (b.style.display != DisplayStyle.None) l.Add(b);
            l.Add(close);
            return l.ToArray();
        }
    }
}
