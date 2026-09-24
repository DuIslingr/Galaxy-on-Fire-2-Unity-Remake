// StorySpace.cs
// The story in a flight level (MGame, Reference/research/campaign_flow.md 3.2 / 3.3, campaign_levels_a.md 1.3):
//   MGame::dialogueEvent 0x1b0498   after the launch / arrival camera, the briefing of the level mission (when it has
//                                   briefing pages and is visible); it restarts the mission clock
//   MGame::successCheck 0x1b0620    from 5000 ms of level time: the campaign mission complete (Story.IsComplete in
//                                   space) or the campaign level's win objective -> the success conversation; closing it
//                                   credits the reward and advances the story (index &gt; 45 without pages: advance at
//                                   once); the level keeps running with the new index. New index 15 -> station 98
//                                   (arrested), 22 -> back into Kappa's station
//   MGame::gameOverCheck 0x1b0d04   the campaign level's fail objective -> "Mission failed!" (392, + 527 at 38 / 40 / 41)
//                                   and "Game Over" (319), then the last save
//   MGame::OnUpdate 0x1ac778        add-on entry calls: in free flight (no level mission, not mining, no autopilot) at
//                                   index 45 the Valkyrie call (conversation 46), at 84 the Supernova call (85), each
//                                   followed by two nextCampaignMission (the remake owns both add-ons)
// The conversation is shown by the flight HUD (DialogueRequested); the game is paused meanwhile (Navigation.Paused).

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.World
{
    public class StorySpace : MonoBehaviour
    {
        /// <summary>Show these pages; call the action (skipped) when the window closes.</summary>
        public event Action<List<DialoguePage>, Action<bool>> DialogueRequested;
        public bool DialogueOpen { get; private set; }

        SpaceLevel level;
        CampaignLevel campaign;
        float levelMs;
        bool briefingChecked, failed;

        public void Setup(SpaceLevel spaceLevel, CampaignLevel campaignLevel)
        {
            level = spaceLevel;
            campaign = campaignLevel;
        }

        void Update()
        {
            if (Session.FreePlay || level == null || DialogueRequested == null || DialogueOpen) return;
            levelMs += Time.deltaTime * 1000f;
            if (level.Health != null && level.Health.Dead) return;
            if (!level.StartSequenceOver) return;
            if (!briefingChecked)
            {
                briefingChecked = true;
                var step = Story.Step;
                if (campaign != null && step != null && step.briefing.Count > 0 && Story.Mission.visible && !Story.Mission.won)
                {
                    Open(step.briefing, _ => campaign.ResetClock());
                    return;
                }
            }
            if (campaign != null && !failed && campaign.Failed && Story.Index == campaign.BuiltIndex) { Fail(); return; }
            if (levelMs >= 5000f) CheckSuccess();
            if (levelMs >= 5000f && !DialogueOpen) CheckAddonEntry();
        }

        void CheckSuccess()
        {
            var ctx = new StoryContext { docked = false, levelMs = levelMs, station = Session.StationIndex };
            bool levelWon = campaign != null && Story.Index == campaign.BuiltIndex && campaign.Won;
            if (Story.Mission.won || !(Story.IsComplete(level.Database, ctx) || levelWon)) return;
            Story.Mission.won = true;
            int reward = Story.Mission.reward;
            var step = Story.Step;
            if (step != null && step.success.Count > 0) Open(step.success, _ => AfterSuccess(reward));
            else AfterSuccess(reward);
        }

        /// <summary>MGame::OnTouchEnd after a campaign success conversation in space.</summary>
        void AfterSuccess(int reward)
        {
            Session.Credits += reward;
            int n = Story.Advance(level.Database);
            if (n == 15) { Session.StationIndex = 98; level.Dock(); }       // arrested: taken to Alioth
            else if (n == 22) level.Dock();                                       // back into Kappa's station
        }

        void Fail()
        {
            failed = true;
            int index = Story.Index;
            string text = Localization.Get(392);
            if (index == 38 || index == 40 || index == 41) text += "\n" + Localization.Get(527);
            text += "\n\n" + Localization.Get(319);
            OpenText(text, 16, () => level.LoadLastSave());
        }

        void CheckAddonEntry()
        {
            int index = Story.Index;
            if (index != Story.GameWonIndex && index != Story.Dlc1WonIndex) return;
            if (Story.IsLevelMission(Session.StationIndex)) return;
            if (level.Mining != null && level.Mining.State != Flight.Mining.Phase.Idle) return;
            if (level.Navigation != null && level.Navigation.Autopilot) return;
            var call = StoryTable.Step(index + 1);   // conversation 46 / 85
            if (call == null || call.success.Count == 0) return;
            Open(call.success, _ => { Story.Advance(level.Database); Story.Advance(level.Database); });
        }

        void Open(List<DialoguePage> pages, Action<bool> after)
        {
            DialogueOpen = true;
            if (level.Navigation != null) level.Navigation.Paused = true;
            DialogueRequested?.Invoke(pages, skipped =>
            {
                DialogueOpen = false;
                if (level.Navigation != null) level.Navigation.Paused = false;
                after?.Invoke(skipped);
            });
        }

        /// <summary>A one-page note (failure) as a page list with a literal text.</summary>
        public event Action<string, int, Action> MessageRequested;

        void OpenText(string text, int speaker, Action after)
        {
            DialogueOpen = true;
            if (level.Navigation != null) level.Navigation.Paused = true;
            MessageRequested?.Invoke(text, speaker, () =>
            {
                DialogueOpen = false;
                if (level.Navigation != null) level.Navigation.Paused = false;
                after?.Invoke();
            });
        }
    }
}
