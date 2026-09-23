// GoF2Session.cs
// Choices made in the main menu that the game scenes read (MenuTouchWindow: startGOF2 / startValkyrie /
// startSupernova, difficulty stored at options+0x2c: Normal 0.5, Extreme 1.5), and where the player is.
// Until there is a save system (Status), a new game starts like Status::resetGame 0xba78c: ship 10 "Phantom"
// at station 78 "Var Hastra" (system 15 Mido) with the starting equipment.

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

        /// <summary>Current station (Status::getStation): one flight level = one station orbit.</summary>
        public static int StationIndex = 78;

        /// <summary>Player ship index (ships.json) and installed item indices (items.json), Status::resetGame.</summary>
        public static int ShipIndex = 10;
        public static int[] Equipment = { 2, 2, 54, 59, 82, 73, 36 };
        /// <summary>Amount per Equipment entry (secondary ammo: Edo x6).</summary>
        public static int[] EquipmentAmounts = { 1, 1, 1, 1, 1, 1, 6 };

        /// <summary>Level::initStreamOutPosition: false = undocking from the station, true = arriving by travel.</summary>
        public static bool ArrivedByTravel;

        public static void ResetNewGame()
        {
            StationIndex = 78;
            ShipIndex = 10;
            Equipment = new[] { 2, 2, 54, 59, 82, 73, 36 };
            EquipmentAmounts = new[] { 1, 1, 1, 1, 1, 1, 6 };
            ArrivedByTravel = false;
        }
    }
}
