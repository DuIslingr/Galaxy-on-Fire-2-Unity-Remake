// GoF2Story.cs
// The campaign's rules as plain C# (Reference/research/campaign_flow.md): the current step's mission, when it is complete,
// advancing to the next step with its side effects, and the restrictions a story mission puts on the player.
//   Status::missionCompleted 0x0b924c      IsComplete: the completion rule per objective type (§2.2)
//   Status::nextCampaignMission 0x0b6c98   Advance: index + 1 (52 -> 54, 128 -> 130), the new step's mission and its side
//                                          effects (§1.3, §4); index 93 / 111 / 143 flag a story radio call
//   Status::departStation 0x0b63e0         LevelMissionFor: the mission a launch builds its orbit around (§3.2)
//   MGame::dockEvent / Radar / UseKhadorDrive   BlocksDockingAndJumps: "Not possible on a mission." (525, §7)
//   ModStation::OnInitialize 0x0e8080      OnDocked: step-specific station tweaks (Betty at index 1, free EMP bombs...)
// State lives in GoF2Session (CampaignMission = the index, StoryMission = slot 0) and is saved by GoF2SaveGame.
// Only the main campaign's side effects (0-45) are implemented so far; the add-ons' come with their levels.

using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Data
{
    /// <summary>Mission+0x8 values the campaign uses (campaign_flow.md 2.2).</summary>
    public static class GoF2StoryType
    {
        public const int Empty = -1, DockedAny = 0x00, Defense = 0x01, Level = 0x04, Wanted = 0x06, Purchase = 0x08,
            Intercept = 0x0a, Dock = 0x0b, Challenge = 0x0c, FreelanceCount = 0x96, CargoLoad = 0x9a, ReachOrbit = 0x9c,
            WeaponAndArmor = 0x9e, DelayedCall = 0xa0, VoidInvasion = 0xa1, TargetList = 0xa3, CallAfterLaunch = 0xa4,
            InOrbit = 0xa5, DeliverOrMount = 0xa6, Counter = 0xa8, ScriptFlag = 0xaa, Lounge = 0xab, LoungeWithGoods = 0xac,
            AmountReached = 0xae, Passengers = 0xb8, EquipCategory = 0xbd;
    }

    /// <summary>A campaign mission (the original's Mission object in Status slot 0).</summary>
    [System.Serializable]
    public class GoF2StoryMission
    {
        public int type = GoF2StoryType.Empty;
        public int reward;
        public int station = -1;
        public int value;
        public int goodsItem = -1, goodsAmount;
        public bool visible = true;
        public bool won;

        public bool IsEmpty => type == GoF2StoryType.Empty;

        public static GoF2StoryMission From(GoF2StoryStep s) => s == null ? new GoF2StoryMission() : new GoF2StoryMission
        {
            type = s.type, reward = s.reward, station = s.station, value = s.value,
            goodsItem = s.goodsItem, goodsAmount = s.goodsAmount, visible = s.visible,
        };
    }

    /// <summary>What IsComplete needs to know about the moment (Status::missionCompleted's arguments and reads).</summary>
    public struct GoF2StoryContext
    {
        public bool docked;           // in a station (else in space)
        public bool inLounge;         // docked, in the Space Lounge with its intro finished
        public float levelMs;         // in space: time since the level started
        public int station;           // the current station / orbit
    }

    public static class GoF2Story
    {
        public const int GameWonIndex = 45, Dlc1WonIndex = 84, LastIndex = 162;

        public static int Index => GoF2Session.CampaignMission;
        public static GoF2StoryMission Mission => GoF2Session.StoryMission;
        public static GoF2StoryStep Step => GoF2StoryTable.Step(Index);

        /// <summary>Status::gameWon: index &gt; 44.</summary>
        public static bool GameWon => Index >= GameWonIndex;
        /// <summary>Status::dlc1Won: index &gt; 83.</summary>
        public static bool Dlc1Won => Index >= Dlc1WonIndex;

        /// <summary>Status::resetGame: index 0, the prologue mission (Mission(4, 0, 78)).</summary>
        public static void StartNewGame(int index = 0)
        {
            GoF2Session.CampaignMission = index;
            GoF2Session.StoryMission = GoF2StoryMission.From(GoF2StoryTable.Step(index));
            GoF2Session.StoryStepStart = GoF2Session.PlaySeconds;
        }

        /// <summary>MenuTouchWindow::startGOF2 / startValkyrie / startSupernova 0x1540f0 / 0x153ba4 / 0x153e14 after
        /// Status::resetGame. Returns the scene to load. The prologue (index 0, a scripted flight level) isn't built yet, so
        /// the main game starts like skipping it (MGame::OnTouchEnd: index 1, 3 kills) and docks at Var Hastra.</summary>
        public static string StartCampaign(GoF2Database db, GoF2Campaign campaign)
        {
            StartNewGame(0);
            switch (campaign)
            {
                case GoF2Campaign.Valkyrie:
                    for (int i = 0; i < GameWonIndex; i++) Advance(db);
                    GoF2Session.ShipIndex = 5;   // Inflict
                    GoF2Session.Equipment = new List<GoF2Stack> { new GoF2Stack(2, 1), new GoF2Stack(5, 1), new GoF2Stack(36, 10), new GoF2Stack(81, 1),
                                                                  new GoF2Stack(51, 1), new GoF2Stack(86, 1), new GoF2Stack(85, 1) };
                    GoF2Session.StationIndex = 91;   // Dima
                    RevealSystem(db, 6);
                    RevealSystem(db, 25);
                    GoF2Session.Kills = 197;
                    break;
                case GoF2Campaign.Supernova:
                    for (int i = 0; i < Dlc1WonIndex; i++) Advance(db);
                    GoF2Session.ShipIndex = 30;   // Berger CrossXT
                    GoF2Session.Equipment = new List<GoF2Stack> { new GoF2Stack(176, 1), new GoF2Stack(20, 1), new GoF2Stack(36, 20), new GoF2Stack(44, 20),
                                                                  new GoF2Stack(81, 1), new GoF2Stack(51, 1), new GoF2Stack(68, 1), new GoF2Stack(86, 1),
                                                                  new GoF2Stack(85, 1), new GoF2Stack(56, 1) };
                    GoF2Session.Cargo = new List<GoF2Stack> { new GoF2Stack(GoF2GalaxyMap.EnergyCellItem, 8) };
                    GoF2Session.StationIndex = 70;   // Dis
                    GoF2Session.Kills = 386;
                    break;
                default:
                    Advance(db);   // skipping the prologue: nextCampaignMission, setKills(3)
                    GoF2Session.Kills = 3;
                    GoF2Session.StationIndex = 78;
                    break;
            }
            return "Station";
        }

        /// <summary>GameRecord::load 0x180dc4: a save taken inside an in-space chain restarts at the chain's first step
        /// (25 -> 24, 29 -> 28, 41 -> 39; 35 with another target -> Ga'kkrr).</summary>
        public static void RepairCheckpoint()
        {
            GoF2StoryMission M(int type, int station) => new GoF2StoryMission { type = type, station = station };
            switch (Index)
            {
                case 25:
                    GoF2Session.CampaignMission = 24; GoF2Session.StoryMission = M(0x04, 48);
                    GoF2Session.VoidInvasionSystem = 9; GoF2Session.VoidInvasionStation = 48;
                    break;
                case 29:
                    GoF2Session.CampaignMission = 28; GoF2Session.StoryMission = M(0x04, 91);
                    GoF2Session.VoidInvasionSystem = 18; GoF2Session.VoidInvasionStation = 91;
                    break;
                case 41: GoF2Session.CampaignMission = 39; GoF2Session.StoryMission = M(0x0b, 30); break;
                case 35: if (Mission.station != 29) GoF2Session.StoryMission = M(0x0b, 29); break;
            }
        }

        // ---- completion (Status::missionCompleted 0x0b924c) ------------------------------------------------------

        public static int CargoLoad()
        {
            int t = 0;
            foreach (var s in GoF2Session.Cargo) t += s.amount;
            return t;
        }

        public static int CargoOf(int item)
        {
            int t = 0;
            foreach (var s in GoF2Session.Cargo) if (s.item == item) t += s.amount;
            return t;
        }

        static bool Mounted(GoF2Database db, System.Func<ItemData, bool> pred)
        {
            foreach (var e in GoF2Session.Equipment) { var it = db.Item(e.item); if (it != null && pred(it)) return true; }
            return false;
        }

        /// <summary>Is the current campaign mission done? (null-safe; a mission already won is not reported again.)</summary>
        public static bool IsComplete(GoF2Database db, GoF2StoryContext c)
        {
            var m = Mission;
            if (m == null || m.IsEmpty || m.won) return false;
            bool atTarget = c.station == m.station;
            switch (m.type)
            {
                case GoF2StoryType.DockedAny:
                case GoF2StoryType.Dock: return c.docked && atTarget;
                case GoF2StoryType.Purchase: return c.docked && atTarget && CargoOf(m.goodsItem) >= m.goodsAmount;
                case GoF2StoryType.FreelanceCount: return GoF2Session.FreelanceCompleted >= m.value;
                case GoF2StoryType.CargoLoad: return CargoLoad() >= m.value;
                case GoF2StoryType.ReachOrbit: return !c.docked && atTarget && c.levelMs >= 10000f;
                case GoF2StoryType.WeaponAndArmor:
                    return Mounted(db, it => it.TypeId == 0) && Mounted(db, it => it.categoryId == 10);
                case GoF2StoryType.DelayedCall: return c.docked || (c.levelMs >= 10000f && (m.station < 0 || !atTarget));
                case GoF2StoryType.CallAfterLaunch: return !c.docked && c.levelMs > 10000f;
                case GoF2StoryType.InOrbit: return !c.docked && m.station >= 0 && atTarget;
                case GoF2StoryType.DeliverOrMount:
                    return c.docked && atTarget && (CargoOf(m.goodsItem) >= m.goodsAmount || GoF2Session.Equipment.Exists(e => e.item == m.goodsItem));
                case GoF2StoryType.Counter: return GoF2Session.StoryCounter >= m.value;
                case GoF2StoryType.ScriptFlag: return m.value == 1;
                case GoF2StoryType.Lounge: return c.docked && atTarget && c.inLounge;
                case GoF2StoryType.LoungeWithGoods: return c.docked && atTarget && c.inLounge && CargoOf(m.goodsItem) >= m.goodsAmount;
                case GoF2StoryType.AmountReached: return m.value >= m.goodsAmount;
                case GoF2StoryType.Passengers: return m.value == 0;
                case GoF2StoryType.EquipCategory: return c.docked && Mounted(db, it => it.categoryId == m.value);
                default: return false;   // level-driven types (0x04, 0x01, 0x06, 0x0a, 0x0c, 0xa1, 0xa3 ...)
            }
        }

        // ---- the level mission and restrictions (Status::departStation, MGame::dockEvent) -------------------------

        static readonly HashSet<int> NotLevelTypes = new HashSet<int> { 0x96, 0x97, 0x99, 0x9b, 0xa1, 0xa2, 0xa3, 0xa4, 0xa6, 0xa7, 0xa9, 0xad, 0x08, 0x0e };

        /// <summary>Status::departStation: does the campaign mission build the orbit of 'station'? (Status+400)</summary>
        public static bool IsLevelMission(int station)
        {
            var m = Mission;
            if (m == null || m.IsEmpty) return false;
            if (m.type == GoF2StoryType.DelayedCall) return m.station != station;
            return m.station == station && !NotLevelTypes.Contains(m.type);
        }

        /// <summary>"On a mission" (campaign_flow.md 7): the level mission is not a docking / lounge type, so docking,
        /// planet jumps and the Khador Drive are refused with 525. Indices 49-54 also refuse docking except at Kanado.</summary>
        public static bool BlocksDocking(int station)
        {
            if (Index >= 49 && Index <= 54 && station != 74) return true;
            return BlocksJumps(station);
        }

        public static bool BlocksJumps(int station)
        {
            if (!IsLevelMission(station)) return false;
            int t = Mission.type;
            return t != 0x00 && t != 0x0b && t != 0x0d && t != 0xab && t != 0xac && t != 0xbd;
        }

        /// <summary>ModStation::OnInitialize menu buttons: Hangar from 5, Map / Missions from 9 (not at 15), Lounge from 12
        /// (not at 15, never at stations 100 / 101).</summary>
        public static bool HangarUnlocked => GoF2Session.FreePlay || Index >= 5;
        public static bool MapUnlocked => GoF2Session.FreePlay || (Index >= 9 && Index != 15);
        public static bool LoungeUnlocked(int station) => station != 100 && station != 101 && (GoF2Session.FreePlay || (Index >= 12 && Index != 15));
        /// <summary>The autopilot is off at index 0-1 and 48; planet locks from index 2.</summary>
        public static bool AutopilotAllowed => GoF2Session.FreePlay || (Index > 1 && Index != 48);

        // ---- advancing (Status::nextCampaignMission 0x0b6c98) ----------------------------------------------------

        /// <summary>Index + 1 with the new step's mission and side effects. Returns the new index.</summary>
        public static int Advance(GoF2Database db)
        {
            int next = Index + 1;
            if (next == 53 || next == 129) next++;   // cases 52 / 128 run twice
            GoF2Session.CampaignMission = next;
            GoF2Session.StoryStepStart = GoF2Session.PlaySeconds;
            if (next == 93 || next == 111 || next == 143) GoF2Session.StoryRadioPending = true;
            var step = GoF2StoryTable.Step(next);
            // Steps without a creating case (45's +40 000 aside, 46, 107, >= 162) keep the old mission object.
            if (step != null && step.type != -1 || next == GameWonIndex || next >= LastIndex) GoF2Session.StoryMission = GoF2StoryMission.From(step);
            ApplyStepEffects(db, next);
            return next;
        }

        /// <summary>The side effects of the nextCampaignMission case that creates step 'n' (campaign_flow.md 4).</summary>
        static void ApplyStepEffects(GoF2Database db, int n)
        {
            switch (n)
            {
                case 4: GoF2Session.Cargo.Clear(); break;                                   // Ship::setCargo(null)
                case 6: GoF2Session.Cargo.Clear(); break;                                   // Ship::removeAllCargo
                case 8: GoF2Session.Unsaleable.Clear(); break;                              // everything saleable again
                case 10:                                                                    // drill -> IMT Extract 1.3
                    for (int i = 0; i < GoF2Session.Equipment.Count; i++)
                        if (db.Item(GoF2Session.Equipment[i].item)?.categoryId == 19) GoF2Session.Equipment[i] = new GoF2Stack(86, 1);
                    GoF2Session.Unsaleable.Remove(90);
                    break;
                case 13: GoF2Session.StoryMission.value = GoF2Session.FreelanceCompleted + 1; break;
                case 23: RevealSystem(db, 6); break;                                        // Wolf-Reiser
                case 24: GoF2Session.VoidInvasionSystem = 9; GoF2Session.VoidInvasionStation = 48; break;
                case 25: GoF2Session.Unsaleable.Add(131); break;                            // Alien Remains
                case 26: GoF2Session.VoidInvasionSystem = GoF2Session.VoidInvasionStation = -1; break;
                case 28: GoF2Session.VoidInvasionSystem = 18; GoF2Session.VoidInvasionStation = 91; break;
                case 34: GoF2Shop.RemoveFromCargo(164, 50); break;                          // the Void Crystals (+ Khador blueprint: no blueprints yet)
                case 42: GoF2Session.VoidInvasionSystem = GoF2Session.VoidInvasionStation = -10; break;
                case 45:
                    GoF2Session.Credits += 40000;
                    GoF2Session.VoidInvasionSystem = GoF2Session.VoidInvasionStation = -10;
                    break;
            }
        }

        static void RevealSystem(GoF2Database db, int system)
        {
            GoF2GalaxyMap.Visibility(db);
            if (GoF2Session.SystemVisible != null && system >= 0 && system < GoF2Session.SystemVisible.Length) GoF2Session.SystemVisible[system] = true;
        }

        /// <summary>ModStation::OnInitialize's per-step station tweaks (campaign_flow.md 3.1 6), when docking.</summary>
        public static void OnDocked(GoF2Database db, int station, GoF2StationStock stock)
        {
            // Index 1: the prologue's Phantom becomes Betty with Gunant's Drill and a Telta Quickscan, both unsaleable.
            if (Index == 1 && GoF2Session.ShipIndex != 0)
            {
                GoF2Session.ShipIndex = 0;
                GoF2Session.Equipment = new List<GoF2Stack> { new GoF2Stack(90, 1), new GoF2Stack(81, 1) };
                GoF2Session.Unsaleable.Add(90);
                GoF2Session.Unsaleable.Add(81);
                GoF2Session.PlayerHull = GoF2Session.PlayerArmor = -1;
                GoF2Session.PlayerShield = -1f;
            }
            // Index 20 at Kappa: EMP GL I (41) free and 10 more in stock.
            if (Index == 20 && station == 55 && stock != null)
            {
                var row = stock.items.Find(s => s.item == 41);
                if (row != null) row.amount += 10; else GoF2Shop.InsertStock(stock, new GoF2Stack(41, 10));
            }
            // Index 27 at the target: the Alien Remains are handed over.
            if (Index == 27 && station == Mission.station) { GoF2Session.Unsaleable.Remove(131); GoF2Shop.RemoveFromCargo(131, CargoOf(131)); }
        }

        /// <summary>The price the shop charges ('price' = the normal one): index 20 at Kappa gives the EMP bombs away.</summary>
        public static int AdjustPrice(int station, int item, int price) => Index == 20 && station == 55 && item == 41 ? 0 : price;

        /// <summary>The Missions window's objective text for the current step ('#' = the target station).</summary>
        public static string ObjectiveText(GoF2Database db)
        {
            var step = Step;
            if (step == null || step.objectiveText < 0) return "";
            var target = db.Stations.Find(s => s.index == Mission.station);
            return GoF2Localization.Get(step.objectiveText).Replace("#", target?.name ?? "");
        }
    }
}
