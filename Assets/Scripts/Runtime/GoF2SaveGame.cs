// GoF2SaveGame.cs
// Save games (the original's RecordHandler / GameRecord): one JSON file per slot in Application.persistentDataPath/Saves.
// Slot 0 is the auto-save (texts 486 / 489), written when docking like ModStation::autosave 0xe9eb4 (which skips a game
// with no playing time); slots 1..11 are manual saves (MenuTouchWindow::saveGame 0x14bcf8). The file format is the
// remake's own (the original writes Status field by field in RecordHandler::recordStoreWrite 0xdf760); the preview
// holds what RecordHandler::recordStoreWritePreview 0xe13e0 stores: playing time, credits, station, system, campaign
// mission, rank, difficulty and ship. Saves are only made while docked, so loading one opens the Station scene.

using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

namespace GoF2Remake.Data
{
    [Serializable]
    public class GoF2SaveData
    {
        public const int CurrentVersion = 3;

        public int version = CurrentVersion;
        public string savedAtUtc;
        public float playSeconds;
        public int campaign;
        public float difficulty;
        public int campaignMission;
        public int station, previousStation, ship, credits;
        public List<GoF2Stack> equipment, cargo;
        public List<GoF2StationStock> recentStations;
        public List<int> seenItems, visitedStations, attackedStations;
        public List<KnownPrice> lowestPrices, highestPrices;
        public bool[] systemVisible;
        public int jumpgatesUsed, kills, pirateKills;
        public int[] standing;
        // version 2: the story
        public bool freePlay;
        public GoF2StoryMission storyMission;
        public float storyStepStart;
        public bool storyRadioPending;
        public int freelanceCompleted, storyCounter, voidInvasionSystem = -1, voidInvasionStation = -1;
        public List<int> unsaleable;
        // version 3: the bar (agents live in recentStations)
        public GoF2FreelanceMission freelanceMission;
        public int passengers;
        public bool[] usedMissionTypes;
        public bool informerKilled, informerFailed;
        public List<string> wingmen;
        public int wingmanRace;
        public float wingmanContractMs;
        public List<int> unlockedBlueprints, shipMods;
        public List<GoF2BlueprintState> blueprints;
        public List<GoF2PendingProduct> pendingProducts;
        public int goodsProduced;
        public int agentsTalkedTo, offersDeclined, offersRepeated, acceptedBlindRisk, acceptedBlindMap, containersDelivered, passengersDelivered;

        [Serializable]
        public class KnownPrice { public int item, price, system; }
    }

    public static class GoF2SaveGame
    {
        public const int SlotCount = 12;
        public const int AutoSaveSlot = 0;

        static string Dir => Path.Combine(Application.persistentDataPath, "Saves");
        static string PathOf(int slot) => Path.Combine(Dir, $"slot_{slot:00}.json");

        public static bool Exists(int slot) => File.Exists(PathOf(slot));

        /// <summary>The slot's contents without loading it (null = empty or unreadable).</summary>
        public static GoF2SaveData Preview(int slot)
        {
            try { return Exists(slot) ? JsonUtility.FromJson<GoF2SaveData>(File.ReadAllText(PathOf(slot))) : null; }
            catch (Exception e) { Debug.LogWarning($"GoF2SaveGame: slot {slot} unreadable: {e.Message}"); return null; }
        }

        /// <summary>The most recently written slot (the main menu's Resume), -1 = none.</summary>
        public static int MostRecentSlot()
        {
            int best = -1; DateTime newest = DateTime.MinValue;
            for (int i = 0; i < SlotCount; i++)
            {
                if (!Exists(i)) continue;
                var t = File.GetLastWriteTimeUtc(PathOf(i));
                if (t > newest) { newest = t; best = i; }
            }
            return best;
        }

        public static bool Save(int slot)
        {
            var s = Capture();
            try
            {
                Directory.CreateDirectory(Dir);
                string tmp = PathOf(slot) + ".tmp";
                File.WriteAllText(tmp, JsonUtility.ToJson(s, true));
                if (File.Exists(PathOf(slot))) File.Delete(PathOf(slot));
                File.Move(tmp, PathOf(slot));
                return true;
            }
            catch (Exception e) { Debug.LogError($"GoF2SaveGame: saving slot {slot} failed: {e.Message}"); return false; }
        }

        /// <summary>ModStation::autosave: slot 0, not for a game without playing time.</summary>
        public static void AutoSave()
        {
            if (GoF2Session.PlaySeconds <= 0f) return;
            Save(AutoSaveSlot);
        }

        public static bool Load(int slot)
        {
            var s = Preview(slot);
            if (s == null) return false;
            Apply(s);
            return true;
        }

        static GoF2SaveData Capture()
        {
            static List<GoF2SaveData.KnownPrice> Prices(Dictionary<int, (int price, int system)> d)
            {
                var l = new List<GoF2SaveData.KnownPrice>();
                foreach (var kv in d) l.Add(new GoF2SaveData.KnownPrice { item = kv.Key, price = kv.Value.price, system = kv.Value.system });
                return l;
            }
            return new GoF2SaveData
            {
                savedAtUtc = DateTime.UtcNow.ToString("o"),
                playSeconds = GoF2Session.PlaySeconds,
                campaign = (int)GoF2Session.Campaign,
                difficulty = GoF2Session.Difficulty,
                campaignMission = GoF2Session.CampaignMission,
                station = GoF2Session.StationIndex,
                previousStation = GoF2Session.PreviousStationIndex,
                ship = GoF2Session.ShipIndex,
                credits = GoF2Session.Credits,
                equipment = GoF2Session.Equipment.ConvertAll(e => e.Clone()),
                cargo = GoF2Session.Cargo.ConvertAll(e => e.Clone()),
                recentStations = GoF2Session.RecentStations,
                seenItems = new List<int>(GoF2Session.SeenItems),
                visitedStations = new List<int>(GoF2Session.VisitedStations),
                attackedStations = new List<int>(GoF2Session.AttackedStations),
                lowestPrices = Prices(GoF2Session.LowestKnownPrice),
                highestPrices = Prices(GoF2Session.HighestKnownPrice),
                systemVisible = GoF2Session.SystemVisible,
                jumpgatesUsed = GoF2Session.JumpgatesUsed,
                kills = GoF2Session.Kills,
                pirateKills = GoF2Session.PirateKills,
                standing = (int[])GoF2Session.Standing.Clone(),
                freePlay = GoF2Session.FreePlay,
                storyMission = GoF2Session.StoryMission,
                storyStepStart = GoF2Session.StoryStepStart,
                storyRadioPending = GoF2Session.StoryRadioPending,
                freelanceCompleted = GoF2Session.FreelanceCompleted,
                storyCounter = GoF2Session.StoryCounter,
                voidInvasionSystem = GoF2Session.VoidInvasionSystem,
                voidInvasionStation = GoF2Session.VoidInvasionStation,
                unsaleable = new List<int>(GoF2Session.Unsaleable),
                freelanceMission = GoF2Session.FreelanceMission,
                passengers = GoF2Session.Passengers,
                usedMissionTypes = GoF2Session.UsedMissionTypes,
                informerKilled = GoF2Session.InformerKilled,
                wingmen = GoF2Session.Wingmen, wingmanRace = GoF2Session.WingmanRace, wingmanContractMs = GoF2Session.WingmanContractMs,
                unlockedBlueprints = new List<int>(GoF2Session.UnlockedBlueprints), shipMods = GoF2Session.ShipMods,
                blueprints = GoF2Session.Blueprints, pendingProducts = GoF2Session.PendingProducts, goodsProduced = GoF2Session.GoodsProduced,
                informerFailed = GoF2Session.InformerFailed,
                agentsTalkedTo = GoF2Session.AgentsTalkedTo, offersDeclined = GoF2Session.OffersDeclined, offersRepeated = GoF2Session.OffersRepeated,
                acceptedBlindRisk = GoF2Session.AcceptedBlindRisk, acceptedBlindMap = GoF2Session.AcceptedBlindMap,
                containersDelivered = GoF2Session.ContainersDelivered, passengersDelivered = GoF2Session.PassengersDelivered,
            };
        }

        static void Apply(GoF2SaveData s)
        {
            static Dictionary<int, (int, int)> Prices(List<GoF2SaveData.KnownPrice> l)
            {
                var d = new Dictionary<int, (int, int)>();
                if (l != null) foreach (var p in l) d[p.item] = (p.price, p.system);
                return d;
            }
            GoF2Session.ResetNewGame();
            GoF2Session.PlaySeconds = s.playSeconds;
            GoF2Session.Campaign = (GoF2Campaign)s.campaign;
            GoF2Session.Difficulty = s.difficulty;
            GoF2Session.CampaignMission = s.campaignMission;
            GoF2Session.StationIndex = s.station;
            GoF2Session.PreviousStationIndex = s.previousStation;
            GoF2Session.ShipIndex = s.ship;
            GoF2Session.Credits = s.credits;
            GoF2Session.Equipment = s.equipment ?? new List<GoF2Stack>();
            GoF2Session.Cargo = s.cargo ?? new List<GoF2Stack>();
            GoF2Session.RecentStations = s.recentStations ?? new List<GoF2StationStock>();
            GoF2Session.SeenItems = new HashSet<int>(s.seenItems ?? new List<int>());
            GoF2Session.VisitedStations = new HashSet<int>(s.visitedStations ?? new List<int> { s.station });
            GoF2Session.AttackedStations = new HashSet<int>(s.attackedStations ?? new List<int>());
            GoF2Session.LowestKnownPrice = Prices(s.lowestPrices);
            GoF2Session.HighestKnownPrice = Prices(s.highestPrices);
            GoF2Session.SystemVisible = s.systemVisible != null && s.systemVisible.Length > 0 ? s.systemVisible : null;
            GoF2Session.JumpgatesUsed = s.jumpgatesUsed;
            GoF2Session.Kills = s.kills;
            GoF2Session.PirateKills = s.pirateKills;
            if (s.standing != null && s.standing.Length == 2) GoF2Session.Standing = s.standing;
            if (s.version < 2)
            {
                // Saved before the story existed: free play at index 20.
                GoF2Session.FreePlay = true;
                GoF2Session.CampaignMission = GoF2Session.FreePlayMission;
                return;
            }
            GoF2Session.FreePlay = s.freePlay;
            GoF2Session.StoryMission = s.storyMission ?? new GoF2StoryMission();
            GoF2Session.StoryStepStart = s.storyStepStart;
            GoF2Session.StoryRadioPending = s.storyRadioPending;
            GoF2Session.FreelanceCompleted = s.freelanceCompleted;
            GoF2Session.StoryCounter = s.storyCounter;
            GoF2Session.VoidInvasionSystem = s.voidInvasionSystem;
            GoF2Session.VoidInvasionStation = s.voidInvasionStation;
            GoF2Session.Unsaleable = new HashSet<int>(s.unsaleable ?? new List<int>());
            if (s.version >= 3)
            {
                GoF2Session.FreelanceMission = s.freelanceMission ?? new GoF2FreelanceMission();
                GoF2Session.Passengers = s.passengers;
                if (s.usedMissionTypes != null && s.usedMissionTypes.Length == 15) GoF2Session.UsedMissionTypes = s.usedMissionTypes;
                GoF2Session.InformerKilled = s.informerKilled;
                GoF2Session.Wingmen = s.wingmen ?? new List<string>();
                GoF2Session.WingmanRace = s.wingmanRace;
                GoF2Session.WingmanContractMs = s.wingmanContractMs;
                GoF2Session.UnlockedBlueprints = new HashSet<int>(s.unlockedBlueprints ?? new List<int>());
                GoF2Session.ShipMods = s.shipMods ?? new List<int>();
                GoF2Session.Blueprints = s.blueprints ?? new List<GoF2BlueprintState>();
                GoF2Session.PendingProducts = s.pendingProducts ?? new List<GoF2PendingProduct>();
                GoF2Session.GoodsProduced = s.goodsProduced;
                GoF2Session.InformerFailed = s.informerFailed;
                GoF2Session.AgentsTalkedTo = s.agentsTalkedTo; GoF2Session.OffersDeclined = s.offersDeclined; GoF2Session.OffersRepeated = s.offersRepeated;
                GoF2Session.AcceptedBlindRisk = s.acceptedBlindRisk; GoF2Session.AcceptedBlindMap = s.acceptedBlindMap;
                GoF2Session.ContainersDelivered = s.containersDelivered; GoF2Session.PassengersDelivered = s.passengersDelivered;
            }
            GoF2Story.RepairCheckpoint();
        }
    }
}
