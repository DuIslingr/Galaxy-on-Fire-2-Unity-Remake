// GoF2Freelance.cs
// The player's freelance mission (Status missions[1]; Reference/research/freelance_missions.md 3.3, 4, 5). Plain C#:
//   Accept / Discard     SpaceLounge::onKeyPress tail: one mission at a time (a new one discards the old: the Secure
//                        Containers / Cabins leave the hold, passengers go home); Courier loads item 116 x amount
//                        (unsaleable), Passenger boards the passengers; Extreme pays a tenth up front
//   IsMissionOrbit       Status::departStation 0xb63e0: the target station's orbit is a mission orbit unless the type is
//                        8 / 14 (docking only), 11 or 13
//   CheckDocked          Status::missionCompleted / missionFailed (docked = true) 0xb924c / 0xb91f4
//   Succeed / Fail       ModStation::OnTouchEnd / MGame::OnTouchEnd after the dialog: payout (docked: reward + bonus of
//                        1 000 001 or more pays 6 666, the original's guard at 0xeaaee), standing +5 toward the client,
//                        missions completed +1, cargo clean-up; a failed Challenge takes the wager
//   ToReturnTrip         MGame::successCheck, Recovery / Salvage: the container is aboard, bring it to the client's station
//                        (the mission becomes a Passenger-like type 11 with status -1)
// Texts: success 373-377 + 216 (Shima 108: 458), failure 384-388 + 392, return trip 389.

using System.Collections.Generic;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.Data
{
    public static class GoF2Freelance
    {
        public enum DockResult { None, Success, Failure }

        public const int Documents = 115, SecureContainer = 116, SecureCabin = 117;

        public static GoF2FreelanceMission Mission => GoF2Session.FreelanceMission;
        public static bool Active => Mission != null && !Mission.IsEmpty;

        // ---- passengers -------------------------------------------------------------------------------------

        /// <summary>Ship::getMaxPassengers (Ship+0x44): the mounted cabins' sizes (category 20: 3 / 5 / 10).</summary>
        public static int MaxPassengers(GoF2Database db)
        {
            int n = 0;
            foreach (var e in GoF2Session.Equipment)
            {
                var it = db.Item(e.item);
                if (it != null && it.categoryId == 20) n += it.Stat("cabinSize");
            }
            return n;
        }

        // ---- accepting --------------------------------------------------------------------------------------

        /// <summary>The checks before the confirmation: free cargo for Courier (337), cabins for Passenger (338); null = ok.</summary>
        public static string AcceptRefusal(GoF2Database db, GoF2FreelanceMission m)
        {
            if (m.type == GoF2MissionType.Courier)
            {
                int free = GoF2Shop.FreeCargo(db) + (Active ? ContainersAboard() : 0);
                if (free < m.amount) return GoF2Localization.Get(337).Replace("#Q", m.amount.ToString());
            }
            if (m.type == GoF2MissionType.Passenger && MaxPassengers(db) < m.amount)
                return GoF2Localization.Get(338).Replace("#Q", m.amount.ToString());
            return null;
        }

        /// <summary>Extreme: a tenth of reward + bonus up front (203 when short).</summary>
        public static int UpFrontCost(GoF2FreelanceMission m) => GoF2Session.IsExtreme ? m.Total / 10 : 0;

        static int ContainersAboard()
        {
            int n = 0;
            foreach (var s in GoF2Session.Cargo) if (s.item == SecureContainer || s.item == SecureCabin) n += s.amount;
            return n;
        }

        /// <summary>After "Yes": the mission becomes the player's (a copy; the agent keeps its offer, marked accepted).</summary>
        public static void Accept(GoF2Database db, GoF2Agent agent)
        {
            if (Active) Discard();
            var m = agent.mission.Clone();
            GoF2Session.Credits -= UpFrontCost(m);
            m.textIds = new List<int>(agent.textIds);
            if (m.type == GoF2MissionType.Courier)
            {
                GoF2Shop.AddToCargo(SecureContainer, m.amount);
                GoF2Session.Unsaleable.Add(SecureContainer);
            }
            if (m.type == GoF2MissionType.Passenger) GoF2Session.Passengers = m.amount;
            GoF2Session.FreelanceMission = m;
            GoF2Session.InformerKilled = GoF2Session.InformerFailed = false;
            agent.accepted = true;
        }

        /// <summary>A discarded or failed mission: containers out of the hold, passengers home, no mission.</summary>
        public static void Discard()
        {
            ClearCargo();
            GoF2Session.Passengers = 0;
            GoF2Session.InformerKilled = GoF2Session.InformerFailed = false;
            GoF2Session.FreelanceMission = new GoF2FreelanceMission();
        }

        static void ClearCargo()
        {
            foreach (int item in new[] { SecureContainer, SecureCabin })
            {
                int n = 0;
                foreach (var s in GoF2Session.Cargo) if (s.item == item) n += s.amount;
                GoF2Shop.RemoveFromCargo(item, n);
                GoF2Session.Unsaleable.Remove(item);
            }
        }

        // ---- in space ---------------------------------------------------------------------------------------

        /// <summary>Status::departStation: does arriving at 'station' make its orbit the mission orbit?</summary>
        public static bool IsMissionOrbit(int station)
        {
            if (!Active || Mission.target != station) return false;
            int t = Mission.type;
            return t != GoF2MissionType.Purchase && t != GoF2MissionType.StolenGoods && t != GoF2MissionType.Passenger && t != GoF2MissionType.Informer;
        }

        /// <summary>Recovery / Salvage won in space: the container is aboard (unsaleable), take it to the client.</summary>
        public static void ToReturnTrip()
        {
            var m = Mission;
            GoF2Session.Unsaleable.Add(m.type == GoF2MissionType.Recovery ? SecureCabin : SecureContainer);
            m.type = GoF2MissionType.Passenger;
            m.target = m.clientStation;
            m.status = -1;
            m.won = false;
            m.textIds = new List<int> { 803 };
        }

        // ---- docking ----------------------------------------------------------------------------------------

        /// <summary>Status::missionCompleted / missionFailed with docked = true.</summary>
        public static DockResult CheckDocked(int station)
        {
            if (!Active) return DockResult.None;
            var m = Mission;
            switch (m.type)
            {
                case GoF2MissionType.Courier:
                case GoF2MissionType.Passenger:
                    return station == m.target ? DockResult.Success : DockResult.None;
                case GoF2MissionType.Purchase:
                    return station == m.target && CargoCount(m.good) >= m.amount ? DockResult.Success : DockResult.None;
                case GoF2MissionType.Informer:
                    if (GoF2Session.InformerFailed) return DockResult.Failure;
                    return GoF2Session.InformerKilled ? DockResult.Success : DockResult.None;
                case GoF2MissionType.StolenGoods:
                    return station == m.clientStation && CargoCount(Documents) > 0 ? DockResult.Success : DockResult.None;
            }
            return DockResult.None;
        }

        static int CargoCount(int item)
        {
            int n = 0;
            foreach (var s in GoF2Session.Cargo) if (s.item == item) n += s.amount;
            return n;
        }

        /// <summary>ModStation::OnInitialize: the Stolen goods mission's documents wait in the target station's shop.</summary>
        public static void OnEnterStation(GoF2StationStock stock)
        {
            if (!Active || Mission.type != GoF2MissionType.StolenGoods || stock == null || stock.station != Mission.target) return;
            if (stock.items.Find(r => r.item == Documents) == null) GoF2Shop.InsertStock(stock, new GoF2Stack(Documents, 1));
        }

        // ---- results ----------------------------------------------------------------------------------------

        /// <summary>DialogueWindow::loadContent mode 1 (freelance): 373-377 + 216, Shima 458; Challenge 370 with the score.</summary>
        public static string SuccessText(int playerKills = 0, int rivalKills = 0)
        {
            var m = Mission;
            if (m.target == 108) return GoF2Localization.Get(458);
            if (m.type == GoF2MissionType.Challenge)
                return GoF2Localization.Get(370).Replace("#Q1", playerKills.ToString()).Replace("#Q2", rivalKills.ToString());
            return GoF2Localization.Get(373 + Random.Range(0, 5)) + "\n\n" + GoF2Localization.Get(216);
        }

        /// <summary>Mode 2: 384-388 + 392.</summary>
        public static string FailureText() => GoF2Localization.Get(384 + Random.Range(0, 5)) + "\n\n" + GoF2Localization.Get(392);

        /// <summary>389: Recovery / Salvage won, return to the client's station.</summary>
        public static string ReturnText(GoF2Database db) =>
            GoF2Localization.Get(389).Replace("#S", db.Stations.Find(s => s.index == Mission.clientStation)?.name ?? "");

        /// <summary>Success after the dialog: cargo clean-up and statistics per type, missions +1, standing +5 toward the
        /// client (Standing::applyMissionCompleted), reward + bonus paid. Returns the amount paid.</summary>
        public static int Succeed(bool docked)
        {
            var m = Mission;
            switch (m.type)
            {
                case GoF2MissionType.Purchase: GoF2Shop.RemoveFromCargo(m.good, m.amount); break;
                case GoF2MissionType.Passenger: GoF2Session.PassengersDelivered += m.status == -1 ? 0 : GoF2Session.Passengers; break;
                case GoF2MissionType.Courier: GoF2Session.ContainersDelivered += m.amount; break;
                case GoF2MissionType.StolenGoods: GoF2Shop.RemoveFromCargo(Documents, 1); break;
            }
            int pay = m.Total;
            if (docked && pay >= 1000001) pay = 6666;
            GoF2Standing.ApplyDelict(m.clientRace, -5);
            GoF2Session.FreelanceCompleted++;
            GoF2Session.Credits += pay;
            Discard();
            return pay;
        }

        /// <summary>Failure after the dialog: a lost Challenge costs the wager; the mission is gone.</summary>
        public static void Fail()
        {
            if (Mission.type == GoF2MissionType.Challenge) GoF2Session.Credits -= Mission.reward;
            Discard();
        }
    }
}
