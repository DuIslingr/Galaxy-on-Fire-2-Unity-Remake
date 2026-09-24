// Story.cs
// The campaign's rules as plain C# (Reference/research/campaign_flow.md): the current step's mission, when it is complete,
// advancing to the next step with its side effects, and the restrictions a story mission puts on the player.
//   Status::missionCompleted 0x0b924c      IsComplete: the completion rule per objective type (§2.2)
//   Status::nextCampaignMission 0x0b6c98   Advance: index + 1 (52 -> 54, 128 -> 130), the new step's mission and its side
//                                          effects (§1.3, §4); index 93 / 111 / 143 flag a story radio call
//   Status::departStation 0x0b63e0         LevelMissionFor: the mission a launch builds its orbit around (§3.2)
//   MGame::dockEvent / Radar / UseKhadorDrive   BlocksDockingAndJumps: "Not possible on a mission." (525, §7)
//   ModStation::OnInitialize 0x0e8080      OnDocked: step-specific station tweaks (Betty at index 1, free EMP bombs...)
// State lives in Session (CampaignMission = the index, StoryMission = slot 0) and is saved by SaveGame.
// Only the main campaign's side effects (0-45) are implemented so far; the add-ons' come with their levels.

using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Data
{
    /// <summary>Mission+0x8 values the campaign uses (campaign_flow.md 2.2).</summary>
    public static class StoryType
    {
        public const int Empty = -1, DockedAny = 0x00, Defense = 0x01, Level = 0x04, Wanted = 0x06, Purchase = 0x08,
            Intercept = 0x0a, Dock = 0x0b, Challenge = 0x0c, FreelanceCount = 0x96, CargoLoad = 0x9a, ReachOrbit = 0x9c,
            WeaponAndArmor = 0x9e, DelayedCall = 0xa0, VoidInvasion = 0xa1, TargetList = 0xa3, CallAfterLaunch = 0xa4,
            InOrbit = 0xa5, DeliverOrMount = 0xa6, Counter = 0xa8, ScriptFlag = 0xaa, Lounge = 0xab, LoungeWithGoods = 0xac,
            AmountReached = 0xae, Passengers = 0xb8, EquipCategory = 0xbd;
    }

    /// <summary>A campaign mission (the original's Mission object in Status slot 0).</summary>
    [System.Serializable]
    public class StoryMission
    {
        public int type = StoryType.Empty;
        public int reward;
        public int station = -1;
        public int value;
        public int goodsItem = -1, goodsAmount;
        public bool visible = true;
        public bool won;

        public bool IsEmpty => type == StoryType.Empty;

        public static StoryMission From(StoryStep s) => s == null ? new StoryMission() : new StoryMission
        {
            type = s.type, reward = s.reward, station = s.station, value = s.value,
            goodsItem = s.goodsItem, goodsAmount = s.goodsAmount, visible = s.visible,
        };
    }

    /// <summary>What IsComplete needs to know about the moment (Status::missionCompleted's arguments and reads).</summary>
    public struct StoryContext
    {
        public bool docked;           // in a station (else in space)
        public bool inLounge;         // docked, in the Space Lounge with its intro finished
        public float levelMs;         // in space: time since the level started
        public int station;           // the current station / orbit
    }

    public static class Story
    {
        public const int GameWonIndex = 45, Dlc1WonIndex = 84, LastIndex = 162;

        public static int Index => Session.CampaignMission;
        public static StoryMission Mission => Session.StoryMission;
        public static StoryStep Step => StoryTable.Step(Index);

        /// <summary>Where the current mission is: its target station, or for type 0xa1 (index 40) the station the Void attack
        /// (Status+0x80, shown on the map by the early-warning wormhole). -1 = none / the alien orbit.</summary>
        public static int TargetStation => Mission == null ? -1
                                          : Mission.type == StoryType.VoidInvasion && Index < GameWonIndex ? Session.VoidInvasionStation : Mission.station;

        /// <summary>Status::gameWon: index &gt; 44.</summary>
        public static bool GameWon => Index >= GameWonIndex;
        /// <summary>Status::dlc1Won: index &gt; 83.</summary>
        public static bool Dlc1Won => Index >= Dlc1WonIndex;

        /// <summary>Status::resetGame: index 0, the prologue mission (Mission(4, 0, 78)).</summary>
        public static void StartNewGame(int index = 0)
        {
            Session.CampaignMission = index;
            Session.StoryMission = StoryMission.From(StoryTable.Step(index));
            Session.StoryStepStart = Session.PlaySeconds;
        }

        /// <summary>MenuTouchWindow::startGOF2 / startValkyrie / startSupernova 0x1540f0 / 0x153ba4 / 0x153e14 after
        /// Status::resetGame. Returns the scene to load: the main game starts in flight with the prologue (index 0, the
        /// Phantom in the Dareius belt), the add-ons docked.</summary>
        public static string StartCampaign(Database db, Campaign campaign)
        {
            StartNewGame(0);
            switch (campaign)
            {
                case Campaign.Valkyrie:
                    for (int i = 0; i < GameWonIndex; i++) Advance(db);
                    Session.ShipIndex = 5;   // Inflict
                    Session.Equipment = new List<ItemStack> { new ItemStack(2, 1), new ItemStack(5, 1), new ItemStack(36, 10), new ItemStack(81, 1),
                                                                  new ItemStack(51, 1), new ItemStack(86, 1), new ItemStack(85, 1) };
                    Session.StationIndex = 91;   // Dima
                    RevealSystem(db, 6);
                    RevealSystem(db, 25);
                    Session.Kills = 197;
                    break;
                case Campaign.Supernova:
                    for (int i = 0; i < Dlc1WonIndex; i++) Advance(db);
                    Session.ShipIndex = 30;   // Berger CrossXT
                    Session.Equipment = new List<ItemStack> { new ItemStack(176, 1), new ItemStack(20, 1), new ItemStack(36, 20), new ItemStack(44, 20),
                                                                  new ItemStack(81, 1), new ItemStack(51, 1), new ItemStack(68, 1), new ItemStack(86, 1),
                                                                  new ItemStack(85, 1), new ItemStack(56, 1) };
                    Session.Cargo = new List<ItemStack> { new ItemStack(GalaxyMap.EnergyCellItem, 8) };
                    Session.StationIndex = 70;   // Dis
                    Session.Kills = 386;
                    break;
                default:
                    Session.StationIndex = 78;
                    Session.LaunchedFromStation = Session.ArrivedByTravel = false;
                    return "Space";   // module 2: the prologue
            }
            return "Station";
        }

        /// <summary>GameRecord::load 0x180dc4: a save taken inside an in-space chain restarts at the chain's first step
        /// (25 -> 24, 29 -> 28, 41 -> 39; 35 with another target -> Ga'kkrr).</summary>
        public static void RepairCheckpoint()
        {
            StoryMission M(int type, int station) => new StoryMission { type = type, station = station };
            switch (Index)
            {
                case 25:
                    Session.CampaignMission = 24; Session.StoryMission = M(0x04, 48);
                    Session.VoidInvasionSystem = 9; Session.VoidInvasionStation = 48;
                    break;
                case 29:
                    Session.CampaignMission = 28; Session.StoryMission = M(0x04, 91);
                    Session.VoidInvasionSystem = 18; Session.VoidInvasionStation = 91;
                    break;
                case 41: Session.CampaignMission = 39; Session.StoryMission = M(0x0b, 30); break;
                case 35: if (Mission.station != 29) Session.StoryMission = M(0x0b, 29); break;
            }
        }

        // ---- completion (Status::missionCompleted 0x0b924c) ------------------------------------------------------

        public static int CargoLoad()
        {
            int t = 0;
            foreach (var s in Session.Cargo) t += s.amount;
            return t;
        }

        public static int CargoOf(int item)
        {
            int t = 0;
            foreach (var s in Session.Cargo) if (s.item == item) t += s.amount;
            return t;
        }

        static bool Mounted(Database db, System.Func<ItemData, bool> pred)
        {
            foreach (var e in Session.Equipment) { var it = db.Item(e.item); if (it != null && pred(it)) return true; }
            return false;
        }

        /// <summary>Is the current campaign mission done? (null-safe; a mission already won is not reported again.)</summary>
        public static bool IsComplete(Database db, StoryContext c)
        {
            var m = Mission;
            if (m == null || m.IsEmpty || m.won) return false;
            bool atTarget = c.station == m.station;
            switch (m.type)
            {
                case StoryType.DockedAny:
                case StoryType.Dock: return c.docked && atTarget;
                case StoryType.Purchase: return c.docked && atTarget && CargoOf(m.goodsItem) >= m.goodsAmount;
                case StoryType.FreelanceCount: return Session.FreelanceCompleted >= m.value;
                case StoryType.CargoLoad: return CargoLoad() >= m.value;
                case StoryType.ReachOrbit: return !c.docked && atTarget && c.levelMs >= 10000f;
                case StoryType.WeaponAndArmor:
                    return Mounted(db, it => it.TypeId == 0) && Mounted(db, it => it.categoryId == 10);
                // 0xa0: docked anywhere, or 10 s in space at another orbit than the target (-1 = the alien orbit: index 42
                // completes once out of the Void).
                case StoryType.DelayedCall: return c.docked || (c.levelMs >= 10000f && !atTarget);
                case StoryType.CallAfterLaunch: return !c.docked && c.levelMs > 10000f;
                case StoryType.InOrbit: return !c.docked && m.station >= 0 && atTarget;
                case StoryType.DeliverOrMount:
                    return c.docked && atTarget && (CargoOf(m.goodsItem) >= m.goodsAmount || Session.Equipment.Exists(e => e.item == m.goodsItem));
                case StoryType.Counter: return Session.StoryCounter >= m.value;
                case StoryType.ScriptFlag: return m.value == 1;
                case StoryType.Lounge: return c.docked && atTarget && c.inLounge;
                case StoryType.LoungeWithGoods: return c.docked && atTarget && c.inLounge && CargoOf(m.goodsItem) >= m.goodsAmount;
                case StoryType.AmountReached: return m.value >= m.goodsAmount;
                case StoryType.Passengers: return m.value == 0;
                case StoryType.EquipCategory: return c.docked && Mounted(db, it => it.categoryId == m.value);
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
            if (m.type == StoryType.DelayedCall) return m.station != station;
            // Rule 2: index < 45, type 0xa1 in the orbit the Void attack (Status+0x80), not the alien orbit.
            if (m.type == StoryType.VoidInvasion)
                return Index < GameWonIndex && station == Session.VoidInvasionStation && station != Session.VoidOrbit;
            return m.station == station && !NotLevelTypes.Contains(m.type);
        }

        /// <summary>Status::departStation's Void-invasion bookkeeping: from index 32 to 44 every 10th departure to a station
        /// that is neither the campaign target nor the attacked one re-rolls the attacked station (a random visible system,
        /// not 10 or 15, then a random station of it); from index 45 on nothing is attacked any more (-10).</summary>
        public static void OnDepart(Database db, int station)
        {
            if (Session.FreePlay || station == Session.VoidOrbit) return;
            if (Index >= GameWonIndex) { Session.VoidInvasionSystem = Session.VoidInvasionStation = -10; return; }
            if (Index < 32 || Index > 44 || station == Mission.station || station == Session.VoidInvasionStation) return;
            if (++Session.InvasionDepartures < 10) return;
            Session.InvasionDepartures = 0;
            GalaxyMap.Visibility(db);
            var systems = new List<int>();
            for (int i = 0; i < db.Systems.Count; i++)
            {
                int s = db.Systems[i].index;
                if (s == 10 || s == 15) continue;
                if (Session.SystemVisible != null && s < Session.SystemVisible.Length && !Session.SystemVisible[s]) continue;
                if (db.Systems[i].stations == null || db.Systems[i].stations.Count == 0) continue;
                systems.Add(i);
            }
            if (systems.Count == 0) return;
            var sys = db.Systems[systems[Random.Range(0, systems.Count)]];
            Session.VoidInvasionSystem = sys.index;
            Session.VoidInvasionStation = sys.stations[Random.Range(0, sys.stations.Count)];
        }

        /// <summary>"On a mission" (campaign_flow.md 7): the level mission is not a docking / lounge type, so docking,
        /// planet jumps and the Khador Drive are refused with 525. Indices 49-54 also refuse docking except at Kanado.</summary>
        public static bool BlocksDocking(int station)
        {
            if (station == Session.VoidOrbit) return true;   // Level::collideStation: no docking at the Void station
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
        public static bool HangarUnlocked => Session.FreePlay || Index >= 5;
        public static bool MapUnlocked => Session.FreePlay || (Index >= 9 && Index != 15);
        public static bool LoungeUnlocked(int station) => station != 100 && station != 101 && (Session.FreePlay || (Index >= 12 && Index != 15));
        /// <summary>Planet jumps are refused (HUD event 0x15, 525) before index 10 and at 48 (campaign_levels_a.md 1.7).</summary>
        public static bool PlanetJumpsAllowed => Session.FreePlay || (Index >= 10 && Index != 48);
        /// <summary>The autopilot is off at index 0-1 and 48; planet locks from index 2.</summary>
        public static bool AutopilotAllowed => Session.FreePlay || (Index > 1 && Index != 48);

        // ---- advancing (Status::nextCampaignMission 0x0b6c98) ----------------------------------------------------

        /// <summary>Index + 1 with the new step's mission and side effects. Returns the new index.</summary>
        public static int Advance(Database db)
        {
            int next = Index + 1;
            if (next == 53 || next == 129) next++;   // cases 52 / 128 run twice
            Session.CampaignMission = next;
            Session.StoryStepStart = Session.PlaySeconds;
            if (next == 93 || next == 111 || next == 143) Session.StoryRadioPending = true;
            var step = StoryTable.Step(next);
            // Steps without a creating case (45's +40 000 aside, 46, 107, >= 162) keep the old mission object.
            if (step != null && step.type != -1 || next == GameWonIndex || next >= LastIndex) Session.StoryMission = StoryMission.From(step);
            ApplyStepEffects(db, next);
            return next;
        }

        /// <summary>The side effects of the nextCampaignMission case that creates step 'n' (campaign_flow.md 4).</summary>
        static void ApplyStepEffects(Database db, int n)
        {
            switch (n)
            {
                case 4: Session.Cargo.Clear(); break;                                   // Ship::setCargo(null)
                case 6: Session.Cargo.Clear(); break;                                   // Ship::removeAllCargo
                case 8: Session.Unsaleable.Clear(); break;                              // everything saleable again
                case 10:                                                                    // drill -> IMT Extract 1.3
                    for (int i = 0; i < Session.Equipment.Count; i++)
                        if (db.Item(Session.Equipment[i].item)?.categoryId == 19) Session.Equipment[i] = new ItemStack(86, 1);
                    Session.Unsaleable.Remove(90);
                    break;
                case 13: Session.StoryMission.value = Session.FreelanceCompleted + 1; break;
                case 23: RevealSystem(db, 6); break;                                        // Wolf-Reiser
                case 24: Session.VoidInvasionSystem = 9; Session.VoidInvasionStation = 48; break;
                case 25: Session.Unsaleable.Add(131); break;                            // Alien Remains
                case 26: Session.VoidInvasionSystem = Session.VoidInvasionStation = -1; break;
                case 28: Session.VoidInvasionSystem = 18; Session.VoidInvasionStation = 91; break;
                case 34: Shop.RemoveFromCargo(164, 50); Blueprints.UnlockFromStory(db, n); break;   // the Void Crystals -> the Khador blueprint
                case 58: case 72: case 104: case 141: Blueprints.UnlockFromStory(db, n); break;     // Liberator, Disruptor, Gamma II, Chromo Plasma
                case 42: Session.VoidInvasionSystem = Session.VoidInvasionStation = -10; break;
                case 45:
                    Session.Credits += 40000;
                    Session.VoidInvasionSystem = Session.VoidInvasionStation = -10;
                    break;
            }
        }

        static void RevealSystem(Database db, int system)
        {
            GalaxyMap.Visibility(db);
            if (Session.SystemVisible != null && system >= 0 && system < Session.SystemVisible.Length) Session.SystemVisible[system] = true;
        }

        /// <summary>ModStation::OnInitialize's per-step station tweaks (campaign_flow.md 3.1 6), when docking.</summary>
        public static void OnDocked(Database db, int station, StationStock stock)
        {
            // Index 1: the prologue's Phantom becomes Betty with Gunant's Drill and a Telta Quickscan, both unsaleable.
            if (Index == 1 && Session.ShipIndex != 0)
            {
                Session.ShipIndex = 0;
                Session.Equipment = new List<ItemStack> { new ItemStack(90, 1), new ItemStack(81, 1) };
                Session.Unsaleable.Add(90);
                Session.Unsaleable.Add(81);
                Session.PlayerHull = Session.PlayerArmor = -1;
                Session.PlayerShield = -1f;
            }
            // Index 20 at Kappa: EMP GL I (41) free and 10 more in stock.
            if (Index == 20 && station == 55 && stock != null)
            {
                var row = stock.items.Find(s => s.item == 41);
                if (row != null) row.amount += 10; else Shop.InsertStock(stock, new ItemStack(41, 10));
            }
            // Index 27 at the target: the Alien Remains are handed over.
            if (Index == 27 && station == Mission.station) { Session.Unsaleable.Remove(131); Shop.RemoveFromCargo(131, CargoOf(131)); }
        }

        /// <summary>The price the shop charges ('price' = the normal one): the tutorial gear at Var Hastra before step 7 and the EMP
        /// bombs at Kappa in step 20 are free.</summary>
        public static int AdjustPrice(int station, int item, int price)
        {
            // Generator::getItemBuyList (shop.md 4.3): Var Hastra before step 7 stocks the tutorial gear 0 / 22 / 55 at price 0
            // (steps 5-6: "go and get yourself a weapon and some armor plating"); selling there pays the same 0.
            if (station == 78 && Session.CampaignMission < 7) return 0;
            return Index == 20 && station == 55 && item == 41 ? 0 : price;
        }

        /// <summary>The Missions window's objective text for the current step ('#' = the target station).</summary>
        public static string ObjectiveText(Database db)
        {
            var step = Step;
            if (step == null || step.objectiveText < 0) return "";
            var target = db.Stations.Find(s => s.index == Mission.station);
            return Localization.Get(step.objectiveText).Replace("#", target?.name ?? "");
        }
    }
}
