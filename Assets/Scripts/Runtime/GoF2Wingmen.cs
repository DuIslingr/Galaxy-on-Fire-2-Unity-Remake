// GoF2Wingmen.cs
// Hired wingmen (SpaceLounge::onKeyPress offer 6, Level::createWingmen / wingmanDied, ModStation::checkHints;
// Reference/research/wingmen_wanted.md 1): the agent and its 0-2 friends fly with the player (GoF2Traffic.SpawnWingmen,
// GoF2NpcShip wingman mode). The 600 000 ms contract runs down only while flying; at 0 they keep flying until the next
// docking, where they say goodbye (313) and leave. A dead wingman leaves the contract for good. Plain C#.

using System.Collections.Generic;

namespace GoF2Remake.Data
{
    public static class GoF2Wingmen
    {
        public const float ContractMs = 600000f;

        public static bool Hired => GoF2Session.Wingmen.Count > 0;
        public static bool Expired => Hired && GoF2Session.WingmanContractMs < 1f;

        /// <summary>setWingmen(names), race, contract 600 000 ms, the agent's portrait, hired += friends + 1.</summary>
        public static void Hire(GoF2Agent agent)
        {
            var names = new List<string> { agent.name };
            names.AddRange(agent.wingmen);
            GoF2Session.Wingmen = names;
            GoF2Session.WingmanRace = agent.race;
            GoF2Session.WingmanContractMs = ContractMs;
            GoF2Session.WingmanPortrait = agent.portrait != null ? (int[])agent.portrait.Clone() : new int[5];
            GoF2Session.WingmenHired += names.Count;
        }

        /// <summary>Level::wingmanDied: the name leaves the list; the last one ends the contract.</summary>
        public static void Died(string name)
        {
            GoF2Session.Wingmen.Remove(name);
            if (GoF2Session.Wingmen.Count == 0) Dismiss();
        }

        /// <summary>setWingmen(null): names, portrait and contract cleared.</summary>
        public static void Dismiss()
        {
            GoF2Session.Wingmen = new List<string>();
            GoF2Session.WingmanContractMs = 0f;
        }
    }
}
