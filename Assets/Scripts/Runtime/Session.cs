// Session.cs
// Choices made in the main menu that the game scenes read (MenuTouchWindow: startGOF2 / startValkyrie /
// startSupernova, difficulty stored at options+0x2c: Normal 0.5, Extreme 1.5), and the player's state (the
// original's Status). A new game starts like Status::resetGame 0xba78c: 0 credits, ship 10 "Phantom" at station 78
// "Var Hastra" (system 15 Mido) with the starting equipment, empty cargo. Saving and loading: SaveGame.

using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Data
{
    public enum Campaign { GalaxyOnFire2, Valkyrie, Supernova }

    public static class Session
    {
        public const float DifficultyNormal = 0.5f;
        public const float DifficultyExtreme = 1.5f;

        public static Campaign Campaign = Campaign.GalaxyOnFire2;
        public static float Difficulty = DifficultyNormal;
        public static bool IsExtreme => Difficulty > 1f;

        /// <summary>
        /// Status+0x1e8, the campaign index (Story): one value per story step, 0..162. Shop stock, ship dealers, NPC
        /// strength and several locks depend on it.
        /// </summary>
        public static int CampaignMission;

        /// <summary>Status slot 0: the current step's mission (Story).</summary>
        public static StoryMission StoryMission = new StoryMission();
        /// <summary>Status+0x100: playing time (s) when the current step started.</summary>
        public static float StoryStepStart;
        /// <summary>Status+0x178: a story radio call is due in space (indices 93 / 111 / 143).</summary>
        public static bool StoryRadioPending;
        /// <summary>Status+0x1c4: freelance missions completed.</summary>
        public static int FreelanceCompleted;
        /// <summary>Status missions[1]: the freelance mission (Freelance), type -1 = none.</summary>
        public static FreelanceMission FreelanceMission = new FreelanceMission();
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
        /// left (ms); Wingmen.</summary>
        public static List<string> Wingmen = new List<string>();
        public static int WingmanRace;
        public static float WingmanContractMs;
        /// <summary>Status+0x28: the hiring agent's portrait (the goodbye dialogue); +0xd4 wingmen hired (statistic, medal 27);
        /// +0xf8 the menu shows "Use EMP blaster" (reset on every station visit, not saved).</summary>
        public static int[] WingmanPortrait = new int[5];
        public static int WingmenHired;
        public static bool WingmanShowEmp = true;
        /// <summary>Blueprints the player owns (BluePrint::unlock), by product item index.</summary>
        public static HashSet<int> UnlockedBlueprints = new HashSet<int>();
        /// <summary>Status+0x18: each touched blueprint's progress (Blueprints); +0x1c products waiting at a station;
        /// +0x1d4 goods produced (completed runs).</summary>
        public static List<BlueprintState> Blueprints = new List<BlueprintState>();
        public static List<PendingProduct> PendingProducts = new List<PendingProduct>();
        public static int GoodsProduced;

        /// <summary>Achievements: the 45 medal grades (0 none, 1 gold, 2 silver, 3 bronze; Achievements).</summary>
        public static int[] Medals = new int[45];
        /// <summary>Statistics for the Status window and the medals: Status+0xd8 asteroids destroyed, +0xa0 / +0xa4 ore /
        /// cores mined (t) and the types (+0x94 / +0x98), crates salvaged (t), +0xb0 junk destroyed, +0x118 battleships
        /// destroyed, the highest credits, the hull % on the last arrival at a station (Survivor).</summary>
        public static int AsteroidsDestroyed, OreMined, CoresMined, CratesSalvaged, JunkDestroyed, BattleshipsDestroyed, HighestCredits;
        public static int LastArrivalHullPercent = 100;
        public static HashSet<int> OreTypesMined = new HashSet<int>(), CoreTypesMined = new HashSet<int>();
        /// <summary>Status+0xa8 (medal 8 Personal Need): the booze tonnes gained per hangar visit (ModStation::OnKeyPress /
        /// OnTouchEnd); Status+0xac (medal 9 Barkeeper): the booze types traded (items 132-153); Status+0xcc (medal 21
        /// Alien Hunter): tonnes captured from Void crates (KIPlayer::captureCrate).</summary>
        public static int BoozeBought, AlienRemainsCollected;
        public static HashSet<int> BoozeTypes = new HashSet<int>();
        public static bool IsBooze(int item) => item >= 132 && item <= 153;
        /// <summary>Ship+0x78 (Ship::addMod, each at most once; Reference/research/blueprints_mods.md 2): the current ship's
        /// mods: 0 +40 hull, 1 +30 t cargo, 2 +1 equipment slot, 3 handling +0.2. They belong to the hull (cleared when
        /// the ship is traded).</summary>
        public static List<int> ShipMods = new List<int>();
        public static void AddShipMod(int mod) { if (mod >= 0 && !ShipMods.Contains(mod)) ShipMods.Add(mod); }
        public static bool HasMod(int mod) => ShipMods.Contains(mod);

        /// <summary>Status+0x114 (Reference/research/kaamo_club.md 2): the Kaamo Club, 0 not owned, 1 Mkkt Bkkt's call
        /// heard, 2 purchasable, 3 owned.</summary>
        public static int KaamoState;
        /// <summary>Status+0xf4: the selected secondary weapon item (-1 = none), kept while it stays mounted.</summary>
        public static int SelectedSecondary = -1;
        /// <summary>Status+200: nukes detonated (medal 20).</summary>
        public static int BombsDetonated;
        /// <summary>Status+0x4c: the four pirate bases destroyed (PirateBases.Stations order).</summary>
        public static bool[] PirateBaseDestroyed = new bool[4];
        /// <summary>Status+0xf9: an outpost was destroyed; the next docking pays the reward (not saved, like the original).</summary>
        public static bool PirateBaseRewardPending;
        /// <summary>The radio hints already given (0x23 / 0x24: the Nivelian pirate hints).</summary>
        public static HashSet<int> Hints = new HashSet<int>();
        /// <summary>Status+0x13c best: kills during one emergency-system bubble (medal 43 "Grave Riser").</summary>
        public static int GraveRiserKills;
        /// <summary>Status+0xc0: ms spent cloaked (medal 19 "Ninja", minutes).</summary>
        public static long CloakMs;
        /// <summary>Status+0x68: the gamma pool (0..100) carried between the supernova orbits, -1 = full.</summary>
        public static float PlayerGamma = -1f;
        /// <summary>Status+0x14c, the storage station: its goods (station 108's stock while owned) and parked hulls.</summary>
        public static List<ItemStack> KaamoItems = new List<ItemStack>();
        public static List<StoredShip> KaamoShips = new List<StoredShip>();
        /// <summary>Status+0x174: the counter of story types 0xa8 / 0xb8.</summary>
        public static int StoryCounter;
        /// <summary>Status+0x8c: the own ship parked while a story loaner is flown (null = none).</summary>
        public static ParkedShip ParkedShip;
        /// <summary>Status+0x90: the target stations of a type-0xa3 step (step 59's convoys); -1 = that one is done.</summary>
        public static List<int> StoryTargets = new List<int>();
        /// <summary>Status+0x00: the Most Wanted criminals' state (WantedBoard), by wanted.json index.</summary>
        public static List<WantedState> Wanted = new List<WantedState>();
        /// <summary>Status+0x04: bounties collected per board (0 Terran, 1 Vossk, 2 Nivelian, 3 Midorian).</summary>
        public static int[] CollectedBounties = new int[4];
        /// <summary>hints[0x2a] (601, the Terran board), hints 613 (the other boards) and 0x33-0x36 (3232, ships 45-48 at
        /// Quineros) shown, as bits 0 / 1 / 2-5.</summary>
        public static int WantedHints;
        /// <summary>Status+0x58 bool[5]: the Supernova wrecks' hidden blueprints found (bit k, TrafficPlan.HiddenBlueprints).</summary>
        public static int HiddenBlueprintsFound;
        /// <summary>Status+0x7c / +0x80: the Void-invasion system and station (-1 none, -10 never again).</summary>
        public static int VoidInvasionSystem = -1, VoidInvasionStation = -1;
        /// <summary>Status+0x88: departures to other stations since the invasion station was rolled (index 32-44, re-rolled at 10).</summary>
        public static int InvasionDepartures;
        /// <summary>The alien orbit (Status+0x78, the Void's home orbit): StationIndex while the player is there.</summary>
        public const int VoidOrbit = -1;
        public static bool InVoidOrbit => StationIndex == VoidOrbit;
        /// <summary>Status+0x84: the station a wormhole ride out of the Void returns to (not saved: only set in flight).</summary>
        public static int VoidReturnStation = 10;
        /// <summary>Level::comingFromAlienWorld: the next level starts with a wormhole closing behind the player.</summary>
        public static bool ComingFromVoid;
        /// <summary>Level::lastMissionFreighterHitpoints: Errkt's freighter's hull carried from index 40 into 41 (-1 none).</summary>
        public static int LastFreighterHull = -1;
        /// <summary>Globals::lastCampaignMissionFailed / FailCount: the campaign index that failed and how often in a row (globals:
        /// they survive loading a save, unlike the rest of Session).</summary>
        public static int LastFailedMission = -1, FailCount;
        /// <summary>The ending (ModStation::OnTouchEnd at index 43) is to be shown by the main menu's backdrop.</summary>
        public static bool EndingPending;
        /// <summary>Items the story made unsaleable (Item::setUnsaleable: Gunant's Drill, the Alien Remains ...).</summary>
        public static HashSet<int> Unsaleable = new HashSet<int>();

        /// <summary>
        /// Remake-only free play: no story steps. Plays as if past the tutorial (index 20: hangar, map, lounge and the Mido
        /// ship dealer unlocked), with the remake's help for leaving gateless Mido (GalaxyMap.HasJumpDrive, Var Hastra's
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
        public static List<ItemStack> Equipment = StartEquipment();

        /// <summary>Cargo hold (Ship+0x70) in acquisition order; every unit weighs 1 t.</summary>
        public static List<ItemStack> Cargo = new List<ItemStack>();

        /// <summary>Status+0x1ac.</summary>
        public static int Credits;

        /// <summary>Status+0x19c: the last 3 visited stations with their stock (newest last).</summary>
        public static List<StationStock> RecentStations = new List<StationStock>();

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
        /// initiallyVisible by GalaxyMap.Visibility).</summary>
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

        /// <summary>Standing: [0] Terran (+) / Vossk (-), [1] Nivelian (+) / Midorian (-), -100..100 (Standing);
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
        static List<ItemStack> StartEquipment() => new List<ItemStack>
        {
            new ItemStack(2, 1), new ItemStack(2, 1), new ItemStack(36, 6),
            new ItemStack(54, 1), new ItemStack(59, 1), new ItemStack(82, 1), new ItemStack(73, 1),
        };

        // ---- playing time (Status::getPlayingTime, shown in the save previews) ------------------------------------

        static float playBase, playSince;
        public static float PlaySeconds
        {
            get => playBase + (Time.realtimeSinceStartup - playSince);
            set { playBase = value; playSince = Time.realtimeSinceStartup; }
        }

        // ---- auto-save (slot 0, see SaveGame) ---------------------------------------------------------------

        public static bool HasAutosave => SaveGame.Exists(SaveGame.AutoSaveSlot);

        /// <summary>ModStation::autosave 0xe9eb4: save slot 0 when docking.</summary>
        public static void Autosave() => SaveGame.AutoSave();

        /// <summary>GameRecord::load(last save): back to the docked state of the auto-save.</summary>
        public static bool LoadAutosave() => SaveGame.Load(SaveGame.AutoSaveSlot);

        public static void ResetNewGame()
        {
            PlaySeconds = 0f;
            StationIndex = 78;
            PreviousStationIndex = -1;
            ShipIndex = 10;
            Equipment = StartEquipment();
            Cargo = new List<ItemStack>();
            Credits = 0;
            CampaignMission = 0;
            StoryMission = new StoryMission();
            StoryStepStart = 0f;
            StoryRadioPending = false;
            FreelanceCompleted = 0;
            FreelanceMission = new FreelanceMission();
            Passengers = 0;
            UsedMissionTypes = new bool[15];
            InformerKilled = InformerFailed = false;
            Wingmen = new List<string>();
            WingmanRace = 0;
            WingmanContractMs = 0f;
            WingmanPortrait = new int[5];
            WingmenHired = 0;
            WingmanShowEmp = true;
            UnlockedBlueprints = new HashSet<int>();
            Blueprints = new List<BlueprintState>();
            PendingProducts = new List<PendingProduct>();
            GoodsProduced = 0;
            Medals = new int[45];
            AsteroidsDestroyed = OreMined = CoresMined = CratesSalvaged = JunkDestroyed = BattleshipsDestroyed = HighestCredits = 0;
            LastArrivalHullPercent = 100;
            OreTypesMined = new HashSet<int>();
            BoozeBought = AlienRemainsCollected = 0;
            BoozeTypes = new HashSet<int>();
            CoreTypesMined = new HashSet<int>();
            ShipMods = new List<int>();
            KaamoState = 0;
            SelectedSecondary = -1;
            BombsDetonated = 0;
            PirateBaseDestroyed = new bool[4];
            PirateBaseRewardPending = false;
            Hints = new HashSet<int>();
            GraveRiserKills = 0;
            CloakMs = 0;
            PlayerGamma = -1f;
            KaamoItems = new List<ItemStack>();
            KaamoShips = new List<StoredShip>();
            AgentsTalkedTo = OffersDeclined = OffersRepeated = AcceptedBlindRisk = AcceptedBlindMap = ContainersDelivered = PassengersDelivered = 0;
            StoryCounter = 0;
            ParkedShip = null;
            StoryTargets = new List<int>();
            Wanted = new List<WantedState>();
            CollectedBounties = new int[4];
            WantedHints = 0;
            HiddenBlueprintsFound = 0;
            VoidInvasionSystem = VoidInvasionStation = -1;
            InvasionDepartures = 0;
            VoidReturnStation = 10;
            ComingFromVoid = false;
            LastFreighterHull = -1;
            EndingPending = false;
            Unsaleable = new HashSet<int>();
            FreePlay = false;
            RecentStations = new List<StationStock>();
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
