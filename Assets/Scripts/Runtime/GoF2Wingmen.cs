// GoF2Wingmen.cs
// Hired wingmen (SpaceLounge::onKeyPress, offer 6; Reference/research/freelance_missions.md 3.3): the agent and its 0-2
// friends fly with the player for a 600 000 ms contract (Status+0xd4 count, +0x2c race, +0x30 contract). Plain C#.

using System.Collections.Generic;

namespace GoF2Remake.Data
{
    public static class GoF2Wingmen
    {
        public const float ContractMs = 600000f;

        public static bool Hired => GoF2Session.Wingmen.Count > 0 && GoF2Session.WingmanContractMs > 0f;

        /// <summary>setWingmen(names), wingman race, contract 600 000 ms.</summary>
        public static void Hire(GoF2Agent agent)
        {
            var names = new List<string> { agent.name };
            names.AddRange(agent.wingmen);
            GoF2Session.Wingmen = names;
            GoF2Session.WingmanRace = agent.race;
            GoF2Session.WingmanContractMs = ContractMs;
        }

        public static void Dismiss()
        {
            GoF2Session.Wingmen = new List<string>();
            GoF2Session.WingmanContractMs = 0f;
        }
    }
}
