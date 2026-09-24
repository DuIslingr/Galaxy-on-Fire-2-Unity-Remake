// GoF2Achievements.cs
// Medals (Achievements, checkForNewMedal 0x181ec0 on docking / countMedals 0x182444; Reference/research/lounge_ui.md 6.3):
// 45 medals, grade 0 none, 1 gold, 2 silver, 3 bronze; a counter against the thresholds [gold, silver, bronze]
// (0x259860, -1 = grade not used), the best grade is kept. Medal names 1507 + i, hints 1552 + i (# = the threshold of the
// earned grade). 0 Veteran is preset gold; 35 Champion comes with all other base medals; 36-44 are the Supernova medals.
// Counters the remake doesn't track yet stay 0 (booze 8 / 9, cloak 19, bombs 20, alien remains 21, the elite medals'
// special flags). Plain C#.

using System.Collections.Generic;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.Data
{
    public static class GoF2Achievements
    {
        public const int Count = 45, BaseCount = 36;

        /// <summary>DAT_00259860: [gold, silver, bronze] per medal.</summary>
        static readonly int[,] Thresholds =
        {
            { 0, -1, -1 }, { 5, 15, 30 }, { 11, 8, 5 }, { 11, 8, 5 }, { 250, 100, 50 }, { 200, 100, 25 }, { 1000, 500, 100 },
            { 25, 10, 3 }, { 1000, 100, 25 }, { 22, 16, 5 }, { 150, 100, 30 }, { 100, 50, 25 }, { 22, 10, 5 }, { 13, 6, 3 },
            { 13, 6, 3 }, { 20, 10, 5 }, { 50, 25, 5 }, { 100, 50, 10 }, { 50, 20, 5 }, { 5, 3, 2 }, { 50, 20, 5 },
            { 25, 10, 5 }, { 0, -1, -1 }, { 4, 3, 2 }, { 500, 200, 50 }, { 1000000, 500000, 125000 }, { 100, 50, 20 },
            { 20, 10, 3 }, { 1, -1, -1 }, { 250, 150, 50 }, { 0, -1, -1 }, { 500, 250, 100 }, { 50, -1, -1 }, { 10, -1, -1 },
            { 12, -1, -1 }, { 0, -1, -1 }, { 3000, -1, -1 }, { 50, -1, -1 }, { 10, -1, -1 }, { 20, -1, -1 }, { 100, -1, -1 },
            { 3, -1, -1 }, { 15, -1, -1 }, { 5, -1, -1 }, { 8, -1, -1 },
        };

        /// <summary>Achievements::getValue(i, grade): the threshold shown in the hint.</summary>
        public static int Threshold(int medal, int grade) => grade >= 1 && grade <= 3 ? Thresholds[medal, grade - 1] : 0;

        public static int Grade(int medal) => GoF2Session.Medals != null && medal < GoF2Session.Medals.Length ? GoF2Session.Medals[medal] : 0;

        /// <summary>The medal's counter, or null when the remake doesn't track it (the medal can't be earned yet).</summary>
        static int? Counter(GoF2Database db, int medal)
        {
            switch (medal)
            {
                case 1: return GoF2Session.LastArrivalHullPercent;                        // Survivor (<=)
                case 2: return GoF2Session.OreTypesMined.Count;
                case 3: return GoF2Session.CoreTypesMined.Count;
                case 4: return GoF2Session.Kills;
                case 5: return GoF2Session.ContainersDelivered;
                case 6: return GoF2Session.OreMined;
                case 7: return GoF2Session.CoresMined;
                case 10: return GoF2Session.JunkDestroyed;
                case 11: return GoF2Session.VisitedStations.Count;
                case 12: return SystemsVisited(db);
                case 13: return GoF2Session.UnlockedBlueprints.Count;
                case 14: return GoF2Session.Blueprints.FindAll(b => b.timesProduced > 0).Count;
                case 15: return (int)(GoF2Session.PlaySeconds / 3600f);
                case 16: return GoF2Session.FreelanceCompleted;
                case 17: return GoF2Session.JumpgatesUsed;
                case 18: return GoF2Session.PassengersDelivered;
                case 23: { int n = 0; foreach (var e in GoF2Session.Equipment) if (db.Item(e.item)?.TypeId == 0) n++; return n; }
                case 24: return GoF2Session.CratesSalvaged;
                case 25: return GoF2Session.HighestCredits;
                case 26: return GoF2Session.AgentsTalkedTo;
                case 27: return GoF2Session.WingmenHired;
                case 28: { int n = 0; for (int r = 0; r < 4; r++) if (GoF2Standing.IsEnemy(r)) n++; return n; }
                case 29: return GoF2Session.AsteroidsDestroyed;
                case 30: return GoF2Session.CampaignMission >= GoF2Story.GameWonIndex && !GoF2Session.FreePlay ? 1 : (int?)null;
                case 31: case 36: return GoF2Shop.FreeCargo(db);
                case 32: return GoF2Session.OffersDeclined;
                case 33: return GoF2Session.AcceptedBlindRisk;
                case 34: return GoF2Session.AcceptedBlindMap;
                case 39: return GoF2Session.BattleshipsDestroyed;
            }
            return null;
        }

        static int SystemsVisited(GoF2Database db)
        {
            var systems = new HashSet<int>();
            foreach (int st in GoF2Session.VisitedStations) systems.Add(db.Stations.Find(x => x.index == st)?.system ?? -1);
            systems.Remove(-1);
            return systems.Count;
        }

        /// <summary>checkForNewMedal + applyNewMedals (on docking): the medals whose grade improved.</summary>
        public static List<int> Check(GoF2Database db)
        {
            if (GoF2Session.Medals == null || GoF2Session.Medals.Length != Count) GoF2Session.Medals = new int[Count];
            var improved = new List<int>();
            if (GoF2Session.Medals[0] == 0) GoF2Session.Medals[0] = 1;   // Veteran: preset gold (Achievements::init)
            for (int i = 1; i < Count; i++)
            {
                if (i == 35) continue;
                var c = Counter(db, i);
                if (c == null) continue;
                int grade = 0;
                for (int g = 1; g <= 3 && grade == 0; g++)
                {
                    int t = Thresholds[i, g - 1];
                    if (t < 0) continue;
                    bool met = i == 1 ? c.Value <= t : (i == 30 || i == 22 || i == 35 ? c.Value > t - 1 && c.Value > 0 : c.Value >= t && (t > 0 || c.Value > 0));
                    if (met) grade = g;
                }
                if (grade != 0 && (GoF2Session.Medals[i] == 0 || grade < GoF2Session.Medals[i])) { GoF2Session.Medals[i] = grade; improved.Add(i); }
            }
            // countMedals: all other base medals earned -> 35 Champion.
            int earned = 0;
            for (int i = 0; i < BaseCount; i++) if (i != 35 && GoF2Session.Medals[i] != 0) earned++;
            if (earned == BaseCount - 1 && GoF2Session.Medals[35] == 0) { GoF2Session.Medals[35] = 1; improved.Add(35); }
            return improved;
        }

        public static bool GotAllMedals
        {
            get
            {
                if (GoF2Session.Medals == null) return false;
                for (int i = 0; i < BaseCount; i++) if (GoF2Session.Medals[i] == 0) return false;
                return true;
            }
        }

        /// <summary>StatusWindow's hint: 1552 + i with # = the earned grade's threshold.</summary>
        public static string Hint(int medal)
        {
            int grade = Grade(medal);
            return GoF2Localization.Get(1552 + medal).Replace("#", Threshold(medal, Mathf.Max(1, grade)).ToString("#,0"));
        }
    }
}
