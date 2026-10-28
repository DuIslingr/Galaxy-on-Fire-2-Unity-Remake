// MobileStations.cs
// Remake mods: stations that move (stations.json "mobile", ModWorld.MobileSpec; the GoF3 Ships mod's Manticore, GoF3's Hades).
// A mobile station has no planet: it cruises through the orbits of its route's stations in turn ("route", any systems; default
// its own system's; "any": it roams every system, "systemMinutes" in one, its orbits there in turn, then another system in an
// order drawn per round), "stayMinutes" in each, and is docked at where it is (World.MobileStation in the flight level, its own hangar and bar
// in the station scene like any station). Where it is follows the clock (UTC: the same for every player of a session, and it
// moves on while the game is closed): the stay number n = seconds / stay picks the route's (n + station) % count-th stop, and
// in that orbit it crosses a straight course of speed x stay sideways past the orbit's station (its middle 6-8 km out within
// 50 deg of the station's front, the course square to that direction, so the hull never sweeps through the station), the
// place, height and direction drawn from a java.util.Random seeded by the station and n. Launching from it puts the player in the orbit it is in by
// then (SpaceLevel), beside it.
// Positions are game units (the orbit's station at the origin, game +z in front of it).

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class MobileStations
    {
        static readonly DateTime Epoch = new DateTime(2026, 1, 1, 0, 0, 0, DateTimeKind.Utc);

        /// <summary>Tests: the clock in seconds instead of UTC.</summary>
        public static Func<double> ClockOverride;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { ClockOverride = null; }

        /// <summary>Seconds since 2026-01-01 UTC.</summary>
        public static double Clock => ClockOverride != null ? ClockOverride() : (DateTime.UtcNow - Epoch).TotalSeconds;

        static double StaySeconds(ModWorld.MobileSpec m) => Math.Max(60.0, m.stayMinutes * 60.0);

        /// <summary>The orbit (a station of its system) the mobile station is in at 'seconds'; -1 = nowhere (no route).</summary>
        public static int HostAt(int mobile, double seconds) => HostAt(ModWorld.MobileOf(mobile), mobile, seconds);

        /// <summary>The same for a spec (ModWorld.Apply, while the database is being loaded).</summary>
        public static int HostAt(ModWorld.MobileSpec m, int mobile, double seconds)
        {
            if (m == null || m.route.Count == 0) return -1;
            long n = (long)Math.Floor(seconds / StaySeconds(m));
            if (m.roam && m.roamSystems.Count > 0)
            {
                // A visit of StaysPerSystem stays in one system, its orbits in turn, then another system.
                int per = StaysPerSystem(m);
                long v = FloorDiv(n, per);
                var orbits = m.roamSystems[RoamSystemAt(m, mobile, v)].orbits;
                return orbits[(int)Mod(n - v * per + mobile, orbits.Count)];
            }
            return m.route[(int)Mod(n + mobile, m.route.Count)];
        }

        /// <summary>Remake mods ("route": "any"): the stations a roaming station never stops at: the story's places (Kothar's
        /// deep science 100, the Valkyrie's 101, Skavac / the supernova system / Alda's empty or burning orbits) and the
        /// Kaamo Club's siege orbit.</summary>
        public static readonly int[] RoamSkip = { 100, 101, 102, 103, 104, 108, 109, 110, 111, 112, 113, 132, 133, 134 };

        static int StaysPerSystem(ModWorld.MobileSpec m) => Math.Max(1, (int)Math.Round(m.systemMinutes / Math.Max(1f, m.stayMinutes)));

        static long FloorDiv(long a, long b) => a >= 0 ? a / b : -((-a + b - 1) / b);
        static long Mod(long a, long b) => ((a % b) + b) % b;

        /// <summary>The roamSystems entry of visit 'v': every system once per round in an order of its own (the station and
        /// the round seed it), never the same system twice in a row across rounds.</summary>
        static int RoamSystemAt(ModWorld.MobileSpec m, int mobile, long v)
        {
            int count = m.roamSystems.Count;
            long round = FloorDiv(v, count);
            int k = (int)(v - round * count);
            var order = RoundOrder(mobile, round, count);
            if (count > 2 && order[0] == RoundOrder(mobile, round - 1, count)[count - 1]) (order[0], order[1]) = (order[1], order[0]);
            return order[k];
        }

        static int[] RoundOrder(int mobile, long round, int count)
        {
            var order = new int[count];
            for (int i = 0; i < count; i++) order[i] = i;
            var rnd = new JavaRandom(mobile * 7919L + round * 104729L + 17L);
            for (int i = count - 1; i > 0; i--) { int j = rnd.NextInt(i + 1); (order[i], order[j]) = (order[j], order[i]); }
            return order;
        }

        /// <summary>Seconds until it leaves the system it is in at 'seconds' (a route: the orbit).</summary>
        public static double LeavesSystemIn(int mobile, double seconds)
        {
            var m = ModWorld.MobileOf(mobile);
            if (m == null) return 0;
            double stay = StaySeconds(m);
            double block = m.roam && m.roamSystems.Count > 0 ? stay * StaysPerSystem(m) : stay;
            return block - (seconds - Math.Floor(seconds / block) * block);
        }

        public static int HostNow(int mobile) => HostAt(mobile, Clock);

        /// <summary>The mobile stations in the orbit of 'station' at 'seconds'.</summary>
        public static List<int> AtOrbit(int station, double seconds)
        {
            var list = new List<int>();
            foreach (int mobile in ModWorld.Mobiles()) if (HostAt(mobile, seconds) == station) list.Add(mobile);
            return list;
        }

        /// <summary>Its course in its current orbit at 'seconds' (game units, game space): where it is and its heading (unit,
        /// level). The course runs on past the stay's end (the level keeps it in the orbit it was found in).</summary>
        public static void CourseAt(int mobile, double seconds, out Vector3 position, out Vector3 heading)
        {
            position = new Vector3(0f, 0f, 150000f);
            heading = Vector3.right;
            var m = ModWorld.MobileOf(mobile);
            if (m == null) return;
            double stay = StaySeconds(m);
            long n = (long)Math.Floor(seconds / stay);
            var rnd = new JavaRandom(mobile * 7919L + n * 104729L);
            // The course's middle 6-8 km out within 50 deg of the station's front, crossed sideways (a tangent), so the hull
            // never sweeps through the station: its nearest pass is the middle.
            float bearing = (rnd.NextInt(1000) / 1000f * 100f - 50f) * Mathf.Deg2Rad;
            float distance = rnd.NextInt(40000) + 120000f;
            var centre = new Vector3(Mathf.Sin(bearing) * distance, rnd.NextInt(30000) - 15000, Mathf.Cos(bearing) * distance);
            float sign = rnd.NextInt(2) == 0 ? 1f : -1f;
            heading = new Vector3(Mathf.Cos(bearing), 0f, -Mathf.Sin(bearing)) * sign;
            float length = m.speed * (float)(stay * 1000.0);   // game units over the stay
            float t = (float)((seconds - n * stay) / stay);   // 0..1 through the stay
            position = centre + heading * (length * (t - 0.5f));
        }

        /// <summary>Game units per second it moves.</summary>
        public static float SpeedUnitsPerSecond(int mobile) => (ModWorld.MobileOf(mobile)?.speed ?? 0f) * 1000f;
    }
}
