// ModCapitalShips.cs
// Remake mods: the mods' capital ships and freighters in the orbits' traffic (ships.json "traffic": { "capital": ... }; the
// GoF3 Ships mod's nine GoF3 capital ships). They fly the original's freighter path (NpcShip's freighter state: no fighter AI,
// world-axis collision boxes, hull x5, a wreck burn and a big explosion when they die), with the mod ship's own model:
//   "battleship"  parked in the capital ship special's place (TrafficPlan, npc_combat_specials.md 2.1: 30 % of the orbits with
//                 freighters): in Terran / Vossk systems instead of the Terran / Vossk battleship at the "Mod ships in traffic"
//                 chance, in Nivelian / Midorian systems (the original has none there) whenever the mods have one of that race.
//                 Hull x25 like the Terran battleship (Level::createShip); its turret items ("npcTurrets" on its turret mounts,
//                 NpcMountedTurrets) are armed although it is parked (the original's parked ship never fires).
//                 Pirate (8) and Void (9) warships are hostile instead: now and then one comes with a pirate raid (a third of the
//                 chance, parked 3 km beyond the raiders' point) and in the Void's own orbit (PickHostile, SpawnHostile).
//   "freighter"   one of the orbit's freighters (TrafficPlan's freighter loop) at the "Mod ships in traffic" chance, cruising
//                 game +Z at the freighters' 1 u/ms.
// Neither flies as a fighter (ModTraffic leaves them out). Their collision boxes (CollisionVolume.ForFreighter via ShipVolumes)
// are measured on the built model: the hull cut along its length into slices, a box round each (the original's freighters
// have 2-4 hand-made boxes); the shots and the player still meet the real hull (HullCollision) unless the ship collision option
// is Original. No wreck: the hull burns where it is, explodes at its "explosionScale" (else the battleship's x8 / a freighter's
// x6) and is gone. Not built for the capital ship enhancements (World.CapitalShips: escorts, resupply, fleet battles): those
// stay the game's own ships.

using System.Collections.Generic;
using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class ModCapitalShips
    {
        public const string Battleship = "battleship", Freighter = "freighter";

        /// <summary>How many boxes a hull is cut into along its length.</summary>
        const int Slices = 8;
        static readonly Quaternion GameForward = Quaternion.Euler(0f, 180f, 0f);   // NpcShip.GameForward

        static readonly Dictionary<int, List<CollisionVolume>> volumes = new Dictionary<int, List<CollisionVolume>>();
        static int volumeRevision = -1;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { volumes.Clear(); volumeRevision = -1; }

        /// <summary>A ship's "traffic.capital" kind ("battleship" / "freighter"), null for a fighter or a game ship.</summary>
        public static string KindOf(int ship)
        {
            var c = CustomShips.Get(ship);
            string k = c?.traffic?.capital;
            return string.Equals(k, Battleship, System.StringComparison.OrdinalIgnoreCase) ? Battleship
                 : string.Equals(k, Freighter, System.StringComparison.OrdinalIgnoreCase) ? Freighter : null;
        }

        /// <summary>TrafficPlan's capital ship special: a mod battleship of 'race' (-1: none). 'replacing' = the game's own
        /// capital ship would come (Terran / Vossk): only at the "Mod ships in traffic" chance; else (a race the original has
        /// none for) whenever there is one, the option not Off.</summary>
        public static int PickCapital(int race, bool replacing)
        {
            // (no random draw without a candidate: the game's own traffic rolls stay as they were)
            float chance = Settings.ModShipTrafficChance;
            if (chance <= 0f || !Has(race, Battleship) || (replacing && Random.value >= chance)) return -1;
            return PickOf(race, Battleship);
        }

        /// <summary>A hostile mod warship of 'race' (pirates, the Void) to come with that race's raiders: at 'share' of the "Mod
        /// ships in traffic" chance, -1 = none (no random draw without a candidate).</summary>
        public static int PickHostile(int race, float share)
        {
            float chance = Settings.ModShipTrafficChance * share;
            if (chance <= 0f || !Has(race, Battleship) || Random.value >= chance) return -1;
            return PickOf(race, Battleship);
        }

        /// <summary>A hostile warship's spawn: 'ship' at 'position' (game units), always the player's enemy.</summary>
        public static SpawnSpec SpawnHostile(int ship, int race, Vector3 position)
        {
            var s = Spawn(ship, race, position);
            s.alwaysEnemy = true;
            return s;
        }

        /// <summary>A mod capital ship of 'kind' may fly for 'race' now (the option not Off).</summary>
        public static bool Has(int race, string kind) => Settings.ModShipTrafficChance > 0f && Candidates(race, kind).Count > 0;

        /// <summary>TrafficPlan's freighter loop: the game's 'fallback' freighter, or now and then a mod freighter of 'race'
        /// (at the "Mod ships in traffic" chance).</summary>
        public static int PickFreighter(int race, int fallback)
        {
            float chance = Settings.ModShipTrafficChance;
            if (chance <= 0f || !Has(race, Freighter) || Random.value >= chance) return fallback;
            int ship = PickOf(race, Freighter);
            return ship >= 0 ? ship : fallback;
        }

        /// <summary>The mods' capital ships of 'kind' for 'race' (its own "race", or "traffic.races"), weighted.</summary>
        public static List<(int ship, float weight)> Candidates(int race, string kind)
        {
            var list = new List<(int, float)>();
            var db = Database.Shared;
            foreach (var c in CustomShips.All)
            {
                float weight = c.traffic != null ? c.traffic.weight : 1f;
                if (weight <= 0f || KindOf(c.index) != kind || !CustomShips.Offered(c.index) || db.Ship(c.index) == null) continue;
                bool flies = c.traffic?.races != null && c.traffic.races.Length > 0 ? c.traffic.races.Contains(race) : c.race == race;
                if (!flies || !ModUnlocks.ShipAvailable(c.index) || ModTraffic.HullLength(c.index) <= 0f) continue;   // (not built yet)
                list.Add((c.index, weight));
            }
            return list;
        }

        static int PickOf(int race, string kind)
        {
            var pool = Candidates(race, kind);
            if (pool.Count == 0) return -1;
            float total = pool.Sum(p => p.weight), at = Random.value * total;
            foreach (var (ship, weight) in pool) { if ((at -= weight) <= 0f) return ship; }
            return pool[pool.Count - 1].ship;
        }

        /// <summary>The spawn of a mod capital ship of 'kind' at 'position' (game units).</summary>
        public static SpawnSpec Spawn(int ship, int race, Vector3 position)
        {
            bool parkedShip = KindOf(ship) != Freighter;
            return new SpawnSpec
            {
                group = parkedShip ? NpcGroup.Special : NpcGroup.Freighter, race = race, ship = ship, freighter = true,
                stationary = parkedShip, modCapital = true, position = position,
                hitpoints = Mathf.Max(1, Mathf.RoundToInt((parkedShip ? NpcTables.Hull(1, 14) : NpcTables.Hull(1, ship)) * Mathf.Max(0.05f, CustomShips.Get(ship)?.hullFactor ?? 1f))),
                name = parkedShip ? GameNames.Ship(ship) : null,
            };
        }

        /// <summary>CollisionVolume.ShipVolumes: a mod ship's boxes (world axes, metres, relative to the NPC's root, which faces
        /// game +Z) measured on its built model; null for a game ship or one not built yet.</summary>
        public static List<CollisionVolume> HullVolumes(int ship, int race)
        {
            if (!CustomShips.IsCustom(ship)) return null;
            if (volumeRevision != ModManager.Revision) { volumes.Clear(); volumeRevision = ModManager.Revision; }
            if (volumes.TryGetValue(ship, out var have)) return Copy(have);
            GameObject template = null;
            foreach (var (index, _, t) in ModShips.Built) if (index == ship && t != null) { template = t; break; }
            if (template == null) return null;
            var made = Measure(template, GameForward);
            if (made == null) return null;
            volumes[ship] = made;
            return Copy(made);
        }

        static List<CollisionVolume> Copy(List<CollisionVolume> l) =>
            l.Select(v => v.sphere ? CollisionVolume.Sphere(v.centre, v.radius) : CollisionVolume.Box(v.centre, v.half)).ToList();

        /// <summary>The model cut along its longest axis into Slices boxes round its points (the hull meshes only: not the
        /// glow / engine / additive layers), turned by 'frame' (an NPC's root facing game +Z: GameForward; a turning
        /// obstacle's own frame: identity).</summary>
        public static List<CollisionVolume> Measure(GameObject template, Quaternion frame)
        {
            var root = template.transform.worldToLocalMatrix;
            var points = new List<Vector3>();
            foreach (var mf in template.GetComponentsInChildren<MeshFilter>(true))
            {
                var mesh = mf.sharedMesh;
                if (mesh == null || !IsHull(mf.name) || !IsHull(mf.transform.parent != null ? mf.transform.parent.name : "")) continue;
                var m = root * mf.transform.localToWorldMatrix;
                if (mesh.isReadable)
                {
                    var verts = mesh.vertices;
                    int step = Mathf.Max(1, verts.Length / 20000);   // a sample is enough for boxes
                    for (int i = 0; i < verts.Length; i += step) points.Add(m.MultiplyPoint3x4(verts[i]));
                }
                else
                {
                    var b = mesh.bounds;
                    for (int i = 0; i < 8; i++)
                        points.Add(m.MultiplyPoint3x4(b.center + Vector3.Scale(b.extents, new Vector3((i & 1) * 2 - 1, (i & 2) - 1, (i & 4) / 2f - 1))));
                }
            }
            if (points.Count == 0) return null;
            // Cut along the longest axis (a ship's length; a station may lie along x).
            var all = new Bounds(points[0], Vector3.zero);
            foreach (var p in points) all.Encapsulate(p);
            int axis = all.size.x >= all.size.y && all.size.x >= all.size.z ? 0 : all.size.y >= all.size.z ? 1 : 2;
            float lo = all.min[axis];
            float step2 = Mathf.Max(0.001f, all.size[axis] / Slices);
            var boxes = new Bounds?[Slices];
            foreach (var p in points)
            {
                int k = Mathf.Clamp((int)((p[axis] - lo) / step2), 0, Slices - 1);
                if (boxes[k] is Bounds b) { b.Encapsulate(p); boxes[k] = b; } else boxes[k] = new Bounds(p, Vector3.zero);
            }
            var list = new List<CollisionVolume>();
            for (int k = 0; k < Slices; k++)
            {
                if (!(boxes[k] is Bounds b)) continue;
                // The whole slice along the axis (its points may all sit at one end), its points' cross-section, at least 2 m.
                Vector3 min = b.min, max = b.max;
                min[axis] = lo + k * step2;
                max[axis] = lo + (k + 1) * step2;
                b.SetMinMax(min, max);
                var size = Vector3.Max(b.size, new Vector3(2f, 2f, 2f));
                var world = frame * b.center;
                var half = frame * (size * 0.5f);
                list.Add(CollisionVolume.Box(world, new Vector3(Mathf.Abs(half.x), Mathf.Abs(half.y), Mathf.Abs(half.z))));
            }
            return list;
        }

        static bool IsHull(string name)
        {
            string n = name.ToLowerInvariant();
            return !(n.StartsWith("engine") || n.Contains("_add") || n.Contains("glow") || n.Contains("exhaust") || n.Contains("thruster")
                     || n.Contains("_lod_gen"));
        }
    }
}
