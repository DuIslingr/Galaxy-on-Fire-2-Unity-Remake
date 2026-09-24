// GoF2TrafficPlan.cs
// Which NPC ships an orbit gets (Level::createMission 0xbda70, empty-mission branch; Reference/research/
// npc_traffic_ai.md 2.2-2.4), as plain C# spawn specs in game units. Random per visit (the original reseeds its
// java.util.Random with time(NULL)), so UnityEngine.Random.
//   raiders    chance 90 / 65 / 35 / 10 % by security (one lower on Extreme); count rnd(4) (Extreme rnd(6) + 2, x2)
//              + rank / 4; 75 % pirates else the system's enemy race; one ship model for the group; around
//              (rnd +-50000, 0, 50000..100000) +-20000
//   jumpers    rnd(2) system-race fighters, created dead; the level relaunches them from the station (GoF2Traffic)
//   freighters rnd(5) at (+-(20000..80000), +-20000, +-80000), flying game +Z; none at Var Hastra (78)
//   local      security + rnd(2) + freighters / 4 system-race fighters around (+-10000, +-10000, 20000..50000) +-20000;
//              at least 7 at a station whose race the player attacked; 4 when nothing else spawned
//   special    stations 100, 101, 108, 10: nothing; 102-104: rnd(5) + 3 pirates; Loma (black market): rnd(4) + 6
//              pirates; systems 32 / 33 (pirate loot orbits): rnd(4) + 10 pirates
// Not yet: Wanted targets and their wingmen, the Terran battleship / carrier and Vossk battleship specials with turrets,
// pirate outposts, late-campaign Specters, freelance missions, the Void / alien orbit.

using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public enum GoF2NpcGroup { Local, Jumper, Freighter, Raider }

    public class GoF2SpawnSpec
    {
        public GoF2NpcGroup group;
        public int race, ship;
        public bool freighter;
        public Vector3 position;   // game units
        public GoF2Route route;    // null = the default patrol
        public bool startsDead;    // jumpers
        // Campaign levels (Level::createCampaignMission, campaign_levels_a.md 1.2):
        public bool asleep;        // setToSleep: waits until the player is within +-25 000 or a target within +-50 000
        public bool inactive;      // setInitActive(false): waits until the level script wakes it
        public bool alwaysEnemy, alwaysFriend;
        public int hitpoints = -1; // Player::setHitpoints / setMaxHitpoints override (-1 = the createShip formula)
        public bool noLoot;        // KIPlayer+0x4c / +0x48 = 0: no cargo, no crate
        public int nameText = -1;  // KIPlayer+0x18: the name the lock plate shows (text id)
    }

    public static class GoF2TrafficPlan
    {
        static Vector3 Jitter() => new Vector3(Random.Range(0, 40000) - 20000, Random.Range(0, 40000) - 20000, Random.Range(0, 40000) - 20000);

        public static List<GoF2SpawnSpec> Build(GoF2Database db, int station, SystemData system)
        {
            var list = new List<GoF2SpawnSpec>();
            if (system == null || station == 100 || station == 101 || station == 108 || station == 10) return list;
            int sysRace = Mathf.Clamp(system.raceId, 0, 3);
            bool hardcore = GoF2Session.IsExtreme;
            int rank = GoF2Session.Rank;

            // Pirate-only orbits.
            int pirateOnly = station >= 102 && station <= 104 ? Random.Range(0, 5) + 3
                           : system.index == 25 ? Random.Range(0, 4) + 6
                           : system.index == 32 || system.index == 33 ? Random.Range(0, 4) + 10 : 0;
            if (pirateOnly > 0)
            {
                AddRaiders(list, pirateOnly, GoF2Standing.Pirate, RaiderSpawn());
                return list;
            }

            int r100 = Random.Range(0, 100);
            int sec = system.securityLevel;
            int secEff = sec >= 1 && hardcore ? sec - 1 : sec;
            bool raidersOn = r100 < GoF2NpcTables.RaiderChance(secEff);
            var raiderSpawn = RaiderSpawn();
            int raiderRace = Random.Range(0, 100) < 75 ? GoF2Standing.Pirate : GoF2Standing.EnemyRaceOf(sysRace);
            int raiders = raidersOn ? Random.Range(0, 4) : 0;
            if (raiders > 0)
            {
                if (hardcore) raiders = Random.Range(0, 6) + 2;
                raiders = (int)(raiders * (hardcore ? 2f : 1f));
                raiders += rank / 4;
            }
            if (secEff == 3 && raidersOn && !hardcore) raiders = Random.Range(0, 2) + 1;

            int jumpers = 0, freighters = 0, x = 0;
            if (station != 78) { jumpers = Random.Range(0, 2); freighters = Random.Range(0, 5); x = Random.Range(0, 2); }
            int local = secEff + x + freighters / 4;
            if (GoF2Session.AttackedStations.Contains(station)) local = Mathf.Max(local, 7);
            if (jumpers + local + freighters + raiders == 0) local = 4;

            // 1 local fighters around one point in front of the station
            var wpLocal = new Vector3(Random.Range(0, 20000) - 10000, Random.Range(0, 20000) - 10000, Random.Range(0, 30000) + 20000);
            for (int i = 0; i < local; i++)
                list.Add(new GoF2SpawnSpec { group = GoF2NpcGroup.Local, race = sysRace, ship = GoF2NpcTables.RandomFighter(sysRace), position = wpLocal + Jitter() });
            // 2 jumpers (dead until relaunched from the station), each with a far one-point route
            for (int i = 0; i < jumpers; i++)
            {
                var route = new GoF2Route(false);
                route.points.Add(new Vector3(Random.Range(0, 400000) - 200000, Random.Range(0, 200000) - 100000, Random.Range(0, 100000) + 50000));
                list.Add(new GoF2SpawnSpec { group = GoF2NpcGroup.Jumper, race = sysRace, ship = GoF2NpcTables.RandomFighter(sysRace), route = route, startsDead = true });
            }
            // 3 freighters
            for (int i = 0; i < freighters; i++)
            {
                var (ship, race) = GoF2NpcTables.RandomFreighter(sysRace);
                float s = Random.value < 0.5f ? -1f : 1f;
                list.Add(new GoF2SpawnSpec
                {
                    group = GoF2NpcGroup.Freighter, race = race, ship = ship, freighter = true,
                    position = new Vector3(s * (Random.Range(0, 60000) - 80000), Random.Range(0, 40000) - 20000, Random.Range(0, 160000) - 80000),
                });
            }
            // 4 raiders
            AddRaiders(list, raiders, raiderRace, raiderSpawn);
            return list;
        }

        static Vector3 RaiderSpawn() => new Vector3(Random.Range(0, 100000) - 50000, 0f, Random.Range(0, 50000) + 50000);

        static void AddRaiders(List<GoF2SpawnSpec> list, int n, int race, Vector3 spawn)
        {
            int ship = GoF2NpcTables.RandomFighter(race);   // one model for the whole group
            for (int i = 0; i < n; i++)
                list.Add(new GoF2SpawnSpec { group = GoF2NpcGroup.Raider, race = race, ship = ship, position = spawn + Jitter() });
        }
    }
}
