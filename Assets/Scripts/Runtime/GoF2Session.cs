// GoF2Session.cs
// Choices made in the main menu that the game scenes read (MenuTouchWindow: startGOF2 / startValkyrie /
// startSupernova, difficulty stored at options+0x2c: Normal 0.5, Extreme 1.5), and the player's state (the
// original's Status). A new game starts like Status::resetGame 0xba78c: 0 credits, ship 10 "Phantom" at station 78
// "Var Hastra" (system 15 Mido) with the starting equipment, empty cargo. Saving and loading: GoF2SaveGame.

using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Data
{
    public enum GoF2Campaign { GalaxyOnFire2, Valkyrie, Supernova }

    public static class GoF2Session
    {
        public const float DifficultyNormal = 0.5f;
        public const float DifficultyExtreme = 1.5f;

        public static GoF2Campaign Campaign = GoF2Campaign.GalaxyOnFire2;
        public static float Difficulty = DifficultyNormal;
        public static bool IsExtreme => Difficulty > 1f;

        /// <summary>
        /// Status+0x1e8, the campaign index (GoF2Story): one value per story step, 0..162. Shop stock, ship dealers, NPC
        /// strength and several locks depend on it.
        /// </summary>
        public static int CampaignMission;

        /// <summary>Status slot 0: the current step's mission (GoF2Story).</summary>
        public static GoF2StoryMission StoryMission = new GoF2StoryMission();
        /// <summary>Status+0x100: playing time (s) when the current step started.</summary>
        public static float StoryStepStart;
        /// <summary>Status+0x178: a story radio call is due in space (indices 93 / 111 / 143).</summary>
        public static bool StoryRadioPending;
        /// <summary>Status+0x1c4: freelance missions completed.</summary>
        public static int FreelanceCompleted;
        /// <summary>Status missions[1]: the freelance mission (GoF2Freelance), type -1 = none.</summary>
        public static GoF2FreelanceMission FreelanceMission = new GoF2FreelanceMission();
        /// <summary>Status+0x34: passengers aboard (Passenger missions).</summary>
        public static int Passengers;
        /// <summary>Status+0x50: freelance types already offered (every type once before repeats).</summary>
        public static bool[] UsedMissionTypes = new bool[15];
        /// <summary>Status+0xf0 / +0xf1: the Informer mission's spy is dead / another ship died in its orbit.</summary>
        public static bool InformerKilled, InformerFailed;
        /// <summary>Bar statistics: Status+0xd0 agents talked to, +0xe0 declines, +0xe4 repeats, +0xe8 / +0xec accepted
        /// without asking the risk / for the map, +0x9c containers and +0xb8 passengers delivered.</summary>
        public static int AgentsTalkedTo, OffersDeclined, OffersRepeated, AcceptedBlindRisk, AcceptedBlindMap, ContainersDelivered, PassengersDelivered;
        /// <summary>Status+0xd4 / +0x2c / +0x30: hired wingmen (the agent and its friends), their race and the contract time
        /// left (ms); GoF2Wingmen.</summary>
        public static List<string> Wingmen = new List<string>();
        public static int WingmanRace;
        public static float WingmanContractMs;
        /// <summary>Blueprints the player owns (BluePrint::unlock), by product item index.</summary>
        public static HashSet<int> UnlockedBlueprints = new HashSet<int>();
        /// <summary>Status+0x18: each touched blueprint's progress (GoF2Blueprints); +0x1c products waiting at a station;
        /// +0x1d4 goods produced (completed runs).</summary>
        public static List<GoF2BlueprintState> Blueprints = new List<GoF2BlueprintState>();
        public static List<GoF2PendingProduct> PendingProducts = new List<GoF2PendingProduct>();
        public static int GoodsProduced;
        /// <summary>Ship::addMod: the mods bought for the current ship.</summary>
        public static List<int> ShipMods = new List<int>();
        public static void AddShipMod(int mod) { if (mod >= 0 && !ShipMods.Contains(mod)) ShipMods.Add(mod); }
        /// <summary>Status+0x174: the counter of story types 0xa8 / 0xb8.</summary>
        public static int StoryCounter;
        /// <summary>Status+0x7c / +0x80: the Void-invasion system and station (-1 none, -10 never again).</summary>
        public static int VoidInvasionSystem = -1, VoidInvasionStation = -1;
        /// <summary>Items the story made unsaleable (Item::setUnsaleable: Gunant's Drill, the Alien Remains ...).</summary>
        public static HashSet<int> Unsaleable = new HashSet<int>();

        /// <summary>
        /// Remake-only free play: no story steps. Plays as if past the tutorial (index 20: hangar, map, lounge and the Mido
        /// ship dealer unlocked), with the remake's help for leaving gateless Mido (GoF2GalaxyMap.HasJumpDrive, Var Hastra's
        /// drill and energy cells). Saves from before the story load as free play.
        /// </summary>
        public static bool FreePlay;
        public const int FreePlayMission = 20;

        /// <summary>Current station (Status::getStation): one flight level = one station orbit.</summary>
        public static int StationIndex = 78;

        /// <summary>Status' station stack [1]: where the player came from (the planet-jump arrival point), -1 = none.</summary>
        public static int PreviousStationIndex = -1;

        /// <summary>Player ship index (ships.json), Status+0x18c.</summary>
        public static int ShipIndex = 10;

        /// <summary>Mounted items (Ship+0x6c), one entry per occupied slot; secondaries carry their ammo as the amount.</summary>
        public static List<GoF2Stack> Equipment = StartEquipment();

        /// <summary>Cargo hold (Ship+0x70) in acquisition order; every unit weighs 1 t.</summary>
        public static List<GoF2Stack> Cargo = new List<GoF2Stack>();

        /// <summary>Status+0x1ac.</summary>
        public static int Credits;

        /// <summary>Status+0x19c: the last 3 visited stations with their stock (newest last).</summary>
        public static List<GoF2StationStock> RecentStations = new List<GoF2StationStock>();

        /// <summary>Status+0x70: play time (s, realtime) at the last departure; -1 = never departed.</summary>
        public static float LastDepartureTime = -1f;

        /// <summary>Status+0x54: items the player has inspected, bought or sold (the shop marks the others as new).</summary>
        public static HashSet<int> SeenItems = new HashSet<int>();

        /// <summary>Status+0x3c..0x48: lowest / highest price seen per item and where (system index), -1 = unknown.</summary>
        public static Dictionary<int, (int price, int system)> LowestKnownPrice = new Dictionary<int, (int, int)>();
        public static Dictionary<int, (int price, int system)> HighestKnownPrice = new Dictionary<int, (int, int)>();

        /// <summary>Level::initStreamOutPosition: false = undocking from the station, true = arriving by travel.</summary>
        public static bool ArrivedByTravel;

        /// <summary>Set by the station's launch button: the flight level starts with the launch camera
        /// (LevelScript: a fixed camera 9000 units ahead watches the ship fly past for 7 s).</summary>
        public static bool LaunchedFromStation;

        /// <summary>Arrived through a jumpgate or the Khador Drive: the arrival camera shows the orbit information
        /// (Hud::drawOrbitInformation, not after a planet jump).</summary>
        public static bool ArrivedBySystemJump;

        /// <summary>Status+0x38: which systems the star map shows (null = not set up yet, filled from systems.json
        /// initiallyVisible by GoF2GalaxyMap.Visibility).</summary>
        public static bool[] SystemVisible;

        /// <summary>Galaxy::getVisited: stations the player has docked at (the star map's "Already visited" tick).</summary>
        public static HashSet<int> VisitedStations = new HashSet<int> { 78 };

        /// <summary>Level::programmedStation: the destination picked on the star map, -1 = none. The autopilot routes to it
        /// after the launch / arrival camera (LevelScript::setAutoPilotToProgrammedStation).</summary>
        public static int ProgrammedStation = -1;

        /// <summary>Level doInstantJump / energyCellsForNextJump: the Khador Drive charges for the programmed station
        /// (another system) 5 s into the level, using that many energy cells.</summary>
        public static bool InstantJump;
        public static int EnergyCellsForNextJump;

        /// <summary>Status+0x1dc (Status::jumpgateUsed).</summary>
        public static int JumpgatesUsed;

        /// <summary>Standing: [0] Terran (+) / Vossk (-), [1] Nivelian (+) / Midorian (-), -100..100 (GoF2Standing);
        /// a new game starts at 30 / 0.</summary>
        public static int[] Standing = { 30, 0 };

        /// <summary>Stations whose race the player attacked (Station::setAttackedFriends): on the next visit at least 7
        /// hostile local fighters wait there.</summary>
        public static HashSet<int> AttackedStations = new HashSet<int>();

        /// <summary>Status+0x1c0 kills (also XP), +0x1d8 pirate kills.</summary>
        public static int Kills, PirateKills;

        /// <summary>Status+0x64 / +0x5c / +0x60: the player's hull, shield and armor between levels (-1 = full).</summary>
        public static int PlayerHull = -1, PlayerArmor = -1;
        public static float PlayerShield = -1f;

        /// <summary>DAT_00252b0c: XP needed per rank 0..20 (Status::checkForLevelUp).</summary>
        static readonly int[] RankXp = { 0, 7, 21, 42, 70, 105, 147, 196, 252, 315, 385, 462, 546, 637, 735, 840, 952, 1071, 1197, 1330, 1650 };

        /// <summary>Status::getLevel: the player's rank 0..20 from XP. The remake counts kills only (the original adds
        /// credits / 50, missions and other statistics that don't exist yet).</summary>
        public static int Rank
        {
            get
            {
                int xp = Kills, r = 0;
                for (int i = 0; i < RankXp.Length; i++) if (xp >= RankXp[i]) r = i;
                return r;
            }
        }

        /// <summary>Status::resetGame: 2x Nirai Charged Pulse, 6 Edo missiles, Fluxed Matter Shield, T'yol,
        /// Telta Ecoscan, Synchrotron Boost.</summary>
        static List<GoF2Stack> StartEquipment() => new List<GoF2Stack>
        {
            new GoF2Stack(2, 1), new GoF2Stack(2, 1), new GoF2Stack(36, 6),
            new GoF2Stack(54, 1), new GoF2Stack(59, 1), new GoF2Stack(82, 1), new GoF2Stack(73, 1),
        };

        // ---- playing time (Status::getPlayingTime, shown in the save previews) ------------------------------------

        static float playBase, playSince;
        public static float PlaySeconds
        {
            get => playBase + (Time.realtimeSinceStartup - playSince);
            set { playBase = value; playSince = Time.realtimeSinceStartup; }
        }

        // ---- auto-save (slot 0, see GoF2SaveGame) ---------------------------------------------------------------

        public static bool HasAutosave => GoF2SaveGame.Exists(GoF2SaveGame.AutoSaveSlot);

        /// <summary>ModStation::autosave 0xe9eb4: save slot 0 when docking.</summary>
        public static void Autosave() => GoF2SaveGame.AutoSave();

        /// <summary>GameRecord::load(last save): back to the docked state of the auto-save.</summary>
        public static bool LoadAutosave() => GoF2SaveGame.Load(GoF2SaveGame.AutoSaveSlot);

        public static void ResetNewGame()
        {
            PlaySeconds = 0f;
            StationIndex = 78;
            PreviousStationIndex = -1;
            ShipIndex = 10;
            Equipment = StartEquipment();
            Cargo = new List<GoF2Stack>();
            Credits = 0;
            CampaignMission = 0;
            StoryMission = new GoF2StoryMission();
            StoryStepStart = 0f;
            StoryRadioPending = false;
            FreelanceCompleted = 0;
            FreelanceMission = new GoF2FreelanceMission();
            Passengers = 0;
            UsedMissionTypes = new bool[15];
            InformerKilled = InformerFailed = false;
            Wingmen = new List<string>();
            WingmanRace = 0;
            WingmanContractMs = 0f;
            UnlockedBlueprints = new HashSet<int>();
            Blueprints = new List<GoF2BlueprintState>();
            PendingProducts = new List<GoF2PendingProduct>();
            GoodsProduced = 0;
            ShipMods = new List<int>();
            AgentsTalkedTo = OffersDeclined = OffersRepeated = AcceptedBlindRisk = AcceptedBlindMap = ContainersDelivered = PassengersDelivered = 0;
            StoryCounter = 0;
            VoidInvasionSystem = VoidInvasionStation = -1;
            Unsaleable = new HashSet<int>();
            FreePlay = false;
            RecentStations = new List<GoF2StationStock>();
            LastDepartureTime = -1f;
            SeenItems = new HashSet<int>();
            LowestKnownPrice = new Dictionary<int, (int, int)>();
            HighestKnownPrice = new Dictionary<int, (int, int)>();
            ArrivedByTravel = false;
            LaunchedFromStation = false;
            ArrivedBySystemJump = false;
            SystemVisible = null;
            VisitedStations = new HashSet<int> { 78 };
            ProgrammedStation = -1;
            InstantJump = false;
            EnergyCellsForNextJump = 0;
            JumpgatesUsed = 0;
            Standing = new[] { 30, 0 };
            AttackedStations = new HashSet<int>();
            Kills = PirateKills = 0;
            PlayerHull = PlayerArmor = -1;
            PlayerShield = -1f;
        }
    }
}
