// GoF2Session.cs
// Choices made in the main menu that the game scenes read (MenuTouchWindow: startGOF2 / startValkyrie /
// startSupernova, difficulty stored at options+0x2c: Normal 0.5, Extreme 1.5).

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
    }
}
