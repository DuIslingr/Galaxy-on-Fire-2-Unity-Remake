// PointDefense.cs
// Remake, for mods (EVERSPACE 2's Missile Defense System; the original has no point defense): equipment with the stat
// "missileDefense" (attr 131, a reach in game units) lets the ship's auto turrets shoot down the homing missiles flying at
// it. While one is within the reach, an auto turret (PlayerTurret) turns to it instead of its ship target, leading it by
// the turret's shot's travel time, and fires when aligned; each shot fired at a missile destroys it when the shot arrives
// (that travel time later), with the rocket impact's burst (GunRig.ShowImpact's SET_EXPLOSION_MANUALLY_BIG). A missile is
// claimed by one shot only, so several turrets spread over a salvo. The missiles are the ones IncomingMissiles reports:
// those homing on the local player that still hold their lock. Multiplayer: another game's missile drawn here (Gun.Mirror)
// is left alone: its real copy flies in the shooter's game, which applies its hit.

using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class PointDefense
    {
        /// <summary>The item attribute (Modding.ItemStats "missileDefense").</summary>
        public const int Attribute = 131;

        static readonly List<IncomingMissiles.Missile> incoming = new List<IncomingMissiles.Missile>();
        static readonly Dictionary<(Gun, int), float> claimed = new Dictionary<(Gun, int), float>();   // -> when it dies (Time.time)
        static readonly List<(Gun, int)> due = new List<(Gun, int)>();
        static int collectedFrame = -1, tickedFrame = -1;

        /// <summary>The burst where a missile is shot down (the rocket impact's); tests set their own.</summary>
        public static System.Action<Vector3> Exploded = at => ShipBurn.ManualBurst(at, 1.5f, 2000f, 3000f, 500f);

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        public static void ResetStatics() { incoming.Clear(); claimed.Clear(); collectedFrame = tickedFrame = -1; }

        /// <summary>The reach of the mounted equipment's missile defense in game units (the longest), 0 = none.</summary>
        public static float ReachUnits(Database db)
        {
            if (db == null) return 0f;
            int best = 0;
            foreach (var e in Session.Equipment)
            {
                var it = db.Item(e.item);
                if (it != null) best = Mathf.Max(best, it.Attr(Attribute));
            }
            return best;
        }

        /// <summary>The nearest missile within 'reachMeters' of 'from' that no shot is on yet. False = none.</summary>
        public static bool Pick(Vector3 from, float reachMeters, out IncomingMissiles.Missile missile)
        {
            if (collectedFrame != Time.frameCount) { IncomingMissiles.Collect(incoming); collectedFrame = Time.frameCount; }
            missile = default;
            float best = reachMeters * reachMeters;
            bool found = false;
            foreach (var m in incoming)
            {
                if (m.gun == null || m.gun.Mirror || claimed.ContainsKey((m.gun, m.index)) || !m.gun.IsActive(m.index)) continue;
                float d = (m.position - from).sqrMagnitude;
                if (d > best) continue;
                best = d; missile = m; found = true;
            }
            return found;
        }

        /// <summary>Where to aim at 'm' for a shot of 'shotSpeed' metres per ms from 'from', and the shot's flight time (ms).</summary>
        public static Vector3 Lead(IncomingMissiles.Missile m, Vector3 from, float shotSpeed, out float flightMs)
        {
            flightMs = shotSpeed > 1e-5f ? Vector3.Distance(m.position, from) / shotSpeed : 0f;
            var at = m.position + m.velocity * flightMs;   // one refinement: the time to where it will be
            flightMs = shotSpeed > 1e-5f ? Vector3.Distance(at, from) / shotSpeed : 0f;
            return m.position + m.velocity * flightMs;
        }

        /// <summary>A shot is on its way to 'm': it is destroyed 'flightMs' from now.</summary>
        public static void Claim(IncomingMissiles.Missile m, float flightMs)
        {
            if (m.gun != null) claimed[(m.gun, m.index)] = Time.time + flightMs / 1000f;
        }

        /// <summary>The claimed missiles whose shot has arrived go (once a frame, whichever turret calls first).</summary>
        public static void Tick()
        {
            if (tickedFrame == Time.frameCount || claimed.Count == 0) return;
            tickedFrame = Time.frameCount;
            due.Clear();
            foreach (var kv in claimed) if (Time.time >= kv.Value) due.Add(kv.Key);
            foreach (var key in due)
            {
                claimed.Remove(key);
                var (gun, i) = key;
                if (!gun.IsActive(i)) continue;   // it hit, ran out or was shaken off meanwhile
                var at = gun.ShootDown(i);
                Exploded?.Invoke(at);
            }
        }
    }
}
