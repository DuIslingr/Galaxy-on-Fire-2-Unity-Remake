// SaveGame.cs
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
    public class SaveData
    {
        public const int CurrentVersion = 9;

        public int version = CurrentVersion;
        public string savedAtUtc;
        public float playSeconds;
        public int campaign;
        public float difficulty;
        public int campaignMission;
        public int station, previousStation, ship, credits;
        public List<ItemStack> equipment, cargo;
        public List<StationStock> recentStations;
        public List<int> seenItems, visitedStations, attackedStations;
        public List<KnownPrice> lowestPrices, highestPrices;
        public bool[] systemVisible;
        public int jumpgatesUsed, kills, pirateKills;
        public int[] standing;
        // version 2: the story
        public bool freePlay;
        public StoryMission storyMission;
        public float storyStepStart;
        public bool storyRadioPending;
        public int freelanceCompleted, storyCounter, voidInvasionSystem = -1, voidInvasionStation = -1, invasionDepartures;
        public List<int> unsaleable;
        // version 3: the bar (agents live in recentStations)
        public FreelanceMission freelanceMission;
        public int passengers;
        public bool[] usedMissionTypes;
        public bool informerKilled, informerFailed;
        public List<string> wingmen;
        public int wingmanRace;
        public float wingmanContractMs;
        public int[] wingmanPortrait;
        public int wingmenHired;
        public List<int> unlockedBlueprints, shipMods;
        public List<BlueprintState> blueprints;
        public List<PendingProduct> pendingProducts;
        public int goodsProduced;
        public int[] medals;
        public int asteroidsDestroyed, oreMined, coresMined, cratesSalvaged, junkDestroyed, battleshipsDestroyed, highestCredits, lastArrivalHullPercent = 100;
        public List<int> oreTypesMined, coreTypesMined;
        public int boozeBought, alienRemainsCollected;   // v8
        public List<int> boozeTypes;
        public int agentsTalkedTo, offersDeclined, offersRepeated, acceptedBlindRisk, acceptedBlindMap, containersDelivered, passengersDelivered;
        // version 4: the Kaamo Club
        public int kaamoState;
        public List<ItemStack> kaamoItems;
        public List<StoredShip> kaamoShips;
        // version 5: combat
        public int selectedSecondary = -1, bombsDetonated;
        public bool[] pirateBaseDestroyed;
        public int graveRiserKills;
        public long cloakMs;
        public List<int> hints;
        // version 6: the Valkyrie story (the parked own ship, step 59's target stations)
        public bool hasParkedShip;
        public ParkedShip parkedShip;
        public List<int> storyTargets;
        // version 7: the Supernova story (the Most Wanted boards)
        public List<WantedState> wanted;
        public int[] collectedBounties;
        public int wantedHints;
        public int hiddenBlueprintsFound;
        // version 9: the elite medals' flags and streaks (Status+0x120 .. +0x148)
        public List<int> eliteFlags;
        public int oreStreak, blindKills;
        public bool lomaTollPaid, lomaTollRefused;

        [Serializable]
        public class KnownPrice { public int item, price, system; }
    }

    public static class SaveGame
    {
        public const int SlotCount = 12;
        public const int AutoSaveSlot = 0;

        static string Dir => Path.Combine(Application.persistentDataPath, "Saves");
        static string PathOf(int slot) => Path.Combine(Dir, $"slot_{slot:00}.json");

        public static bool Exists(int slot) => File.Exists(PathOf(slot));

        /// <summary>The slot's contents without loading it (null = empty or unreadable).</summary>
        public static SaveData Preview(int slot)
        {
            try { return Exists(slot) ? JsonUtility.FromJson<SaveData>(File.ReadAllText(PathOf(slot))) : null; }
            catch (Exception e) { Debug.LogWarning($"SaveGame: slot {slot} unreadable: {e.Message}"); return null; }
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
            // Multiplayer: a session is a separate free-play game; it never overwrites the single-player saves (also not
            // after its connection went, while its game is still loaded).
            if (GoF2Remake.Multiplayer.NetGame.SessionGame) return false;
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
            catch (Exception e) { Debug.LogError($"SaveGame: saving slot {slot} failed: {e.Message}"); return false; }
        }

        /// <summary>ModStation::autosave: slot 0, not for a game without playing time.</summary>
        public static void AutoSave()
        {
            if (Session.PlaySeconds <= 0f) return;
            Save(AutoSaveSlot);
        }

        public static bool Load(int slot)
        {
            if (GoF2Remake.Multiplayer.NetGame.Active) return false;   // multiplayer: no single-player save into the session
            var s = Preview(slot);
            if (s == null) return false;
            Apply(s);
            return true;
        }

        static SaveData Capture()
        {
            static List<SaveData.KnownPrice> Prices(Dictionary<int, (int price, int system)> d)
            {
                var l = new List<SaveData.KnownPrice>();
                foreach (var kv in d) l.Add(new SaveData.KnownPrice { item = kv.Key, price = kv.Value.price, system = kv.Value.system });
                return l;
            }
            return new SaveData
            {
                savedAtUtc = DateTime.UtcNow.ToString("o"),
                playSeconds = Session.PlaySeconds,
                campaign = (int)Session.Campaign,
                difficulty = Session.Difficulty,
                campaignMission = Session.CampaignMission,
                station = Session.StationIndex,
                previousStation = Session.PreviousStationIndex,
                ship = Session.ShipIndex,
                credits = Session.Credits,
                equipment = Session.Equipment.ConvertAll(e => e.Clone()),
                cargo = Session.Cargo.ConvertAll(e => e.Clone()),
                recentStations = Session.RecentStations,
                seenItems = new List<int>(Session.SeenItems),
                visitedStations = new List<int>(Session.VisitedStations),
                attackedStations = new List<int>(Session.AttackedStations),
                lowestPrices = Prices(Session.LowestKnownPrice),
                highestPrices = Prices(Session.HighestKnownPrice),
                systemVisible = Session.SystemVisible,
                jumpgatesUsed = Session.JumpgatesUsed,
                kills = Session.Kills,
                pirateKills = Session.PirateKills,
                standing = (int[])Session.Standing.Clone(),
                freePlay = Session.FreePlay,
                storyMission = Session.StoryMission,
                storyStepStart = Session.StoryStepStart,
                storyRadioPending = Session.StoryRadioPending,
                freelanceCompleted = Session.FreelanceCompleted,
                storyCounter = Session.StoryCounter,
                voidInvasionSystem = Session.VoidInvasionSystem,
                voidInvasionStation = Session.VoidInvasionStation,
                invasionDepartures = Session.InvasionDepartures,
                unsaleable = new List<int>(Session.Unsaleable),
                freelanceMission = Session.FreelanceMission,
                passengers = Session.Passengers,
                usedMissionTypes = Session.UsedMissionTypes,
                informerKilled = Session.InformerKilled,
                wingmen = Session.Wingmen, wingmanRace = Session.WingmanRace, wingmanContractMs = Session.WingmanContractMs,
                wingmanPortrait = Session.WingmanPortrait, wingmenHired = Session.WingmenHired,
                unlockedBlueprints = new List<int>(Session.UnlockedBlueprints), shipMods = Session.ShipMods,
                blueprints = Session.Blueprints, pendingProducts = Session.PendingProducts, goodsProduced = Session.GoodsProduced,
                medals = Session.Medals, asteroidsDestroyed = Session.AsteroidsDestroyed, oreMined = Session.OreMined, coresMined = Session.CoresMined,
                cratesSalvaged = Session.CratesSalvaged, junkDestroyed = Session.JunkDestroyed, battleshipsDestroyed = Session.BattleshipsDestroyed,
                highestCredits = Session.HighestCredits, lastArrivalHullPercent = Session.LastArrivalHullPercent,
                oreTypesMined = new List<int>(Session.OreTypesMined), coreTypesMined = new List<int>(Session.CoreTypesMined),
                boozeBought = Session.BoozeBought, alienRemainsCollected = Session.AlienRemainsCollected, boozeTypes = new List<int>(Session.BoozeTypes),
                informerFailed = Session.InformerFailed,
                agentsTalkedTo = Session.AgentsTalkedTo, offersDeclined = Session.OffersDeclined, offersRepeated = Session.OffersRepeated,
                acceptedBlindRisk = Session.AcceptedBlindRisk, acceptedBlindMap = Session.AcceptedBlindMap,
                containersDelivered = Session.ContainersDelivered, passengersDelivered = Session.PassengersDelivered,
                kaamoState = Session.KaamoState, kaamoItems = Session.KaamoItems, kaamoShips = Session.KaamoShips,
                selectedSecondary = Session.SelectedSecondary, bombsDetonated = Session.BombsDetonated,
                pirateBaseDestroyed = Session.PirateBaseDestroyed, hints = new List<int>(Session.Hints),
                graveRiserKills = Session.GraveRiserKills, cloakMs = Session.CloakMs,
                hasParkedShip = Session.ParkedShip != null, parkedShip = Session.ParkedShip, storyTargets = new List<int>(Session.StoryTargets),
                wanted = new List<WantedState>(Session.Wanted), collectedBounties = (int[])Session.CollectedBounties.Clone(),
                wantedHints = Session.WantedHints, hiddenBlueprintsFound = Session.HiddenBlueprintsFound,
                eliteFlags = new List<int>(Session.EliteFlags), oreStreak = Session.OreStreak, blindKills = Session.BlindKills,
                lomaTollPaid = Session.LomaTollPaid, lomaTollRefused = Session.LomaTollRefused,
            };
        }

        static void Apply(SaveData s)
        {
            static Dictionary<int, (int, int)> Prices(List<SaveData.KnownPrice> l)
            {
                var d = new Dictionary<int, (int, int)>();
                if (l != null) foreach (var p in l) d[p.item] = (p.price, p.system);
                return d;
            }
            Session.ResetNewGame();
            Session.PlaySeconds = s.playSeconds;
            Session.Campaign = (Campaign)s.campaign;
            Session.Difficulty = s.difficulty;
            Session.CampaignMission = s.campaignMission;
            Session.StationIndex = s.station;
            Session.PreviousStationIndex = s.previousStation;
            Session.ShipIndex = s.ship;
            Session.Credits = s.credits;
            Session.Equipment = s.equipment ?? new List<ItemStack>();
            Session.Cargo = s.cargo ?? new List<ItemStack>();
            Session.RecentStations = s.recentStations ?? new List<StationStock>();
            Session.SeenItems = new HashSet<int>(s.seenItems ?? new List<int>());
            Session.VisitedStations = new HashSet<int>(s.visitedStations ?? new List<int> { s.station });
            Session.AttackedStations = new HashSet<int>(s.attackedStations ?? new List<int>());
            Session.LowestKnownPrice = Prices(s.lowestPrices);
            Session.HighestKnownPrice = Prices(s.highestPrices);
            Session.SystemVisible = s.systemVisible != null && s.systemVisible.Length > 0 ? s.systemVisible : null;
            Session.JumpgatesUsed = s.jumpgatesUsed;
            Session.Kills = s.kills;
            Session.PirateKills = s.pirateKills;
            if (s.standing != null && s.standing.Length == 2) Session.Standing = s.standing;
            if (s.version < 2)
            {
                // Saved before the story existed: free play at index 20.
                Session.FreePlay = true;
                Session.CampaignMission = Session.FreePlayMission;
                return;
            }
            Session.FreePlay = s.freePlay;
            Session.StoryMission = s.storyMission ?? new StoryMission();
            Session.StoryStepStart = s.storyStepStart;
            Session.StoryRadioPending = s.storyRadioPending;
            Session.FreelanceCompleted = s.freelanceCompleted;
            Session.StoryCounter = s.storyCounter;
            Session.VoidInvasionSystem = s.voidInvasionSystem;
            Session.VoidInvasionStation = s.voidInvasionStation;
            Session.InvasionDepartures = s.invasionDepartures;
            Session.Unsaleable = new HashSet<int>(s.unsaleable ?? new List<int>());
            if (s.version >= 3)
            {
                Session.FreelanceMission = s.freelanceMission ?? new FreelanceMission();
                Session.Passengers = s.passengers;
                if (s.usedMissionTypes != null && s.usedMissionTypes.Length == 15) Session.UsedMissionTypes = s.usedMissionTypes;
                Session.InformerKilled = s.informerKilled;
                Session.Wingmen = s.wingmen ?? new List<string>();
                Session.WingmanRace = s.wingmanRace;
                Session.WingmanContractMs = s.wingmanContractMs;
                if (s.wingmanPortrait != null && s.wingmanPortrait.Length == 5) Session.WingmanPortrait = s.wingmanPortrait;
                Session.WingmenHired = s.wingmenHired;
                Session.UnlockedBlueprints = new HashSet<int>(s.unlockedBlueprints ?? new List<int>());
                Session.ShipMods = s.shipMods ?? new List<int>();
                Session.Blueprints = s.blueprints ?? new List<BlueprintState>();
                Session.PendingProducts = s.pendingProducts ?? new List<PendingProduct>();
                Session.GoodsProduced = s.goodsProduced;
                if (s.medals != null && s.medals.Length == 45) Session.Medals = s.medals;
                Session.AsteroidsDestroyed = s.asteroidsDestroyed; Session.OreMined = s.oreMined; Session.CoresMined = s.coresMined;
                Session.CratesSalvaged = s.cratesSalvaged; Session.JunkDestroyed = s.junkDestroyed; Session.BattleshipsDestroyed = s.battleshipsDestroyed;
                Session.HighestCredits = s.highestCredits; Session.LastArrivalHullPercent = s.lastArrivalHullPercent;
                Session.OreTypesMined = new HashSet<int>(s.oreTypesMined ?? new List<int>());
                Session.BoozeBought = s.boozeBought; Session.AlienRemainsCollected = s.alienRemainsCollected;
                Session.BoozeTypes = new HashSet<int>(s.boozeTypes ?? new List<int>());
                Session.CoreTypesMined = new HashSet<int>(s.coreTypesMined ?? new List<int>());
                Session.InformerFailed = s.informerFailed;
                Session.AgentsTalkedTo = s.agentsTalkedTo; Session.OffersDeclined = s.offersDeclined; Session.OffersRepeated = s.offersRepeated;
                Session.AcceptedBlindRisk = s.acceptedBlindRisk; Session.AcceptedBlindMap = s.acceptedBlindMap;
                Session.ContainersDelivered = s.containersDelivered; Session.PassengersDelivered = s.passengersDelivered;
            }
            if (s.version >= 4)
            {
                Session.KaamoState = s.kaamoState;
                Session.KaamoItems = s.kaamoItems ?? new List<ItemStack>();
                Session.KaamoShips = s.kaamoShips ?? new List<StoredShip>();
            }
            if (s.version >= 5)
            {
                Session.SelectedSecondary = s.selectedSecondary;
                Session.BombsDetonated = s.bombsDetonated;
                if (s.pirateBaseDestroyed != null && s.pirateBaseDestroyed.Length == 4) Session.PirateBaseDestroyed = s.pirateBaseDestroyed;
                Session.Hints = new HashSet<int>(s.hints ?? new List<int>());
                Session.GraveRiserKills = s.graveRiserKills;
                Session.CloakMs = s.cloakMs;
            }
            if (s.version >= 6)
            {
                Session.ParkedShip = s.hasParkedShip ? s.parkedShip : null;   // JsonUtility writes an empty object for null
                Session.StoryTargets = s.storyTargets ?? new List<int>();
            }
            if (s.version >= 7)
            {
                Session.Wanted = s.wanted ?? new List<WantedState>();
                Session.CollectedBounties = s.collectedBounties != null && s.collectedBounties.Length == 4 ? s.collectedBounties : new int[4];
                Session.WantedHints = s.wantedHints;
                Session.HiddenBlueprintsFound = s.hiddenBlueprintsFound;
            }
            else { Session.Wanted = new List<WantedState>(); Session.CollectedBounties = new int[4]; Session.WantedHints = 0; Session.HiddenBlueprintsFound = 0; }
            Session.EliteFlags = new HashSet<int>(s.eliteFlags ?? new List<int>());
            Session.OreStreak = s.oreStreak;
            Session.BlindKills = s.blindKills;
            Session.LomaTollPaid = s.lomaTollPaid;
            Session.LomaTollRefused = s.lomaTollRefused;
            Story.RepairCheckpoint();
        }
    }
}
