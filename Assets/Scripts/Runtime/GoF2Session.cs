// GoF2Session.cs
// Choices made in the main menu that the game scenes read (MenuTouchWindow: startGOF2 / startValkyrie /
// startSupernova, difficulty stored at options+0x2c: Normal 0.5, Extreme 1.5), and the player's state (the
// original's Status). Until there is a save system, a new game starts like Status::resetGame 0xba78c: 0 credits,
// ship 10 "Phantom" at station 78 "Var Hastra" (system 15 Mido) with the starting equipment, empty cargo.

using System.Collections.Generic;

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
        /// Status+0x1e8, the campaign mission. Shop stock, ship dealers and several locks depend on it. There is no
        /// campaign yet, so the remake plays as if past the tutorial: 20 unlocks the hangar (5), map (9), lounge (13) and
        /// the Mido ship dealer (16), and skips the tutorial's free-gear-only shop at Var Hastra (&lt; 7).
        /// </summary>
        public const int FreePlayMission = 20;
        public static int CampaignMission = FreePlayMission;

        /// <summary>Current station (Status::getStation): one flight level = one station orbit.</summary>
        public static int StationIndex = 78;

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

        /// <summary>Status::resetGame: 2x Nirai Charged Pulse, 6 Edo missiles, Fluxed Matter Shield, T'yol,
        /// Telta Ecoscan, Synchrotron Boost.</summary>
        static List<GoF2Stack> StartEquipment() => new List<GoF2Stack>
        {
            new GoF2Stack(2, 1), new GoF2Stack(2, 1), new GoF2Stack(36, 6),
            new GoF2Stack(54, 1), new GoF2Stack(59, 1), new GoF2Stack(82, 1), new GoF2Stack(73, 1),
        };

        public static void ResetNewGame()
        {
            StationIndex = 78;
            ShipIndex = 10;
            Equipment = StartEquipment();
            Cargo = new List<GoF2Stack>();
            Credits = 0;
            CampaignMission = FreePlayMission;
            RecentStations = new List<GoF2StationStock>();
            LastDepartureTime = -1f;
            SeenItems = new HashSet<int>();
            LowestKnownPrice = new Dictionary<int, (int, int)>();
            HighestKnownPrice = new Dictionary<int, (int, int)>();
            ArrivedByTravel = false;
            LaunchedFromStation = false;
        }
    }
}
