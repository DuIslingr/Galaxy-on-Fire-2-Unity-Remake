// GoF2CollisionVolume.cs
// The original's bounding volumes (BoundingAAB / BoundingSphere), what the player slides along and NPC fighters steer
// out of (Reference/research/ship_combat.md 2.9, npc_traffic_ai.md 5.7). Plain C#; GoF2Obstacle puts a list of them on
// a station, jumpgate or freighter. Volumes are never rotated (the original's are axis-aligned in world space): centre
// is a world-axis offset from the owner's position, all in Unity metres.
//   BoundingAAB::outerCollide 0xa3bea          inside when |p - centre| < half on every axis
//   BoundingAAB::projectCollisionOnSurface 0xa3c98   p moved onto the nearest of the 6 faces
//   BoundingSphere::outerCollide / projectCollisionOnSurface 0x17cd8c / 0x17ce64   |p - centre| < r; p moved onto the surface
//   BoundingVolume::staticProjectCollisionOnSurface 0x144c3c   two passes over the list, projecting p out of every volume
//                                              that contains it
// Data (Resources/GoF2Data, int arrays: count, then per volume type 1 = box (a, b, c, d, e, f) or 0 = sphere (a, b, c, d),
// stored Z-up):
//   PlayerStation::PlayerStation 0x146cf0      collision.json by station index (no entry: Vossk 1000; 109 / 110: static
//                                              2002): centre (-a, c, b) (the station's (0, pi, 0) turn is baked in),
//                                              box half (|d|, |f|, |e|), sphere r = |d| / 2; in the alien orbit x0.9 / x0.4
//   PlayerFixedObject::setWreckedMeshId 0x17f318 / Globals::getWreckCollision 0xf9210   wreck_collisions.json: battleship 0
//                                              (everything x2), Midorian freighter 1, Nivelian 2, Terran 3, Vossk 4;
//                                              centre (-a, c, b), box half 1.1 (|d|, |f|, |e|), sphere r = 0.6 |d|
//   Level::createShip 0xcf83c                  freighter boxes as code constants (Reference/tools/npc/freighter_boxes.py):
//                                              centre offset and full size in game space
//   PlayerJumpgate::PlayerJumpgate 0xb1a8c     one sphere of the gate radius (7500, Vossk system 11250) at the gate

using System;
using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Flight
{
    [Serializable]
    public sealed class GoF2CollisionVolume
    {
        const float M = 0.05f;

        public bool sphere;
        /// <summary>Offset from the owner's position (world axes, metres).</summary>
        public Vector3 centre;
        /// <summary>Box half extents (metres).</summary>
        public Vector3 half;
        /// <summary>Sphere radius (metres).</summary>
        public float radius;

        public static GoF2CollisionVolume Box(Vector3 centre, Vector3 half) => new GoF2CollisionVolume { centre = centre, half = half };
        public static GoF2CollisionVolume Sphere(Vector3 centre, float radius) => new GoF2CollisionVolume { sphere = true, centre = centre, radius = radius };

        /// <summary>outerCollide: 'p' relative to the owner.</summary>
        public bool Contains(Vector3 p)
        {
            var d = p - centre;
            if (sphere) return d.sqrMagnitude < radius * radius;
            return Mathf.Abs(d.x) < half.x && Mathf.Abs(d.y) < half.y && Mathf.Abs(d.z) < half.z;
        }

        /// <summary>projectCollisionOnSurface: 'p' (relative to the owner) moved onto the surface.</summary>
        public Vector3 Project(Vector3 p)
        {
            var d = p - centre;
            if (sphere)
            {
                float len = d.magnitude;
                if (len >= radius || len < 1e-6f) return p;
                return centre + d * (radius / len);
            }
            // The smallest of the 6 face distances wins (x-, x+, y-, y+, z-, z+ in the original's order).
            int axis = 0; float best = float.MaxValue, move = 0f;
            for (int a = 0; a < 3; a++)
            {
                float lo = d[a] + half[a], hi = d[a] - half[a];   // distance to the far / near face along this axis
                if (Mathf.Abs(hi) < best) { best = Mathf.Abs(hi); axis = a; move = hi; }
                if (Mathf.Abs(lo) < best) { best = Mathf.Abs(lo); axis = a; move = lo; }
            }
            p[axis] -= move;
            return p;
        }

        /// <summary>BoundingVolume::staticProjectCollisionOnSurface: two passes over the list.</summary>
        public static Vector3 ProjectOut(Vector3 p, IReadOnlyList<GoF2CollisionVolume> volumes)
        {
            for (int pass = 0; pass < 2; pass++)
                for (int i = 0; i < volumes.Count; i++)
                    if (volumes[i].Contains(p)) p = volumes[i].Project(p);
            return p;
        }

        // ---- data --------------------------------------------------------------------------------------------

        [Serializable] class Entry { public int id; public int[] values; }
        [Serializable] class EntryList { public Entry[] items; }

        static Dictionary<int, int[]> station, staticVolumes, wreck;

        static Dictionary<int, int[]> Load(string name)
        {
            var map = new Dictionary<int, int[]>();
            var text = Resources.Load<TextAsset>("GoF2Data/" + name);
            if (text == null) { Debug.LogWarning($"GoF2CollisionVolume: GoF2Data/{name} missing"); return map; }
            var list = JsonUtility.FromJson<EntryList>("{\"items\":" + text.text + "}");
            if (list?.items != null) foreach (var e in list.items) map[e.id] = e.values;
            return map;
        }

        static Vector3 ToUnity(float x, float y, float z) => new Vector3(x, y, -z) * M;

        /// <summary>A station's volumes (PlayerStation::PlayerStation), relative to the station at the origin.</summary>
        public static List<GoF2CollisionVolume> ForStation(int stationIndex, bool alienOrbit)
        {
            station ??= Load("collision");
            staticVolumes ??= Load("static_collisions");
            int[] v;
            if (stationIndex == 109 || stationIndex == 110) staticVolumes.TryGetValue(2002, out v);
            else if (!station.TryGetValue(stationIndex, out v)) station.TryGetValue(1000, out v);   // Vossk
            return Parse(v, alienOrbit ? 0.9f : 1f, alienOrbit ? 0.4f : 0.5f, 1f);
        }

        /// <summary>A freighter / battleship wreck's volumes (Globals::getWreckCollision).</summary>
        public static List<GoF2CollisionVolume> ForWreck(int ship, int race)
        {
            wreck ??= Load("wreck_collisions");
            int id = ship == 14 ? 0 : ship == 13 ? 4 : race == 3 ? 1 : race == 2 ? 2 : 3;
            wreck.TryGetValue(id, out var v);
            return Parse(v, 1.1f, 0.6f, id == 0 ? 2f : 1f);
        }

        static List<GoF2CollisionVolume> Parse(int[] v, float boxScale, float sphereScale, float doubled)
        {
            var list = new List<GoF2CollisionVolume>();
            if (v == null || v.Length == 0) return list;
            int count = v[0], i = 1;
            for (int n = 0; n < count && i < v.Length; n++)
            {
                int type = v[i];
                if (type == 1 && i + 6 < v.Length)
                {
                    var c = ToUnity(-v[i + 1], v[i + 3], v[i + 2]) * doubled;
                    var h = new Vector3(Mathf.Abs(v[i + 4]), Mathf.Abs(v[i + 6]), Mathf.Abs(v[i + 5])) * (boxScale * doubled * M);
                    list.Add(Box(c, h));
                    i += 7;
                }
                else if (type == 0 && i + 4 < v.Length)
                {
                    var c = ToUnity(-v[i + 1], v[i + 3], v[i + 2]) * doubled;
                    list.Add(Sphere(c, Mathf.Abs(v[i + 4]) * sphereScale * doubled * M));
                    i += 5;
                }
                else i++;   // unknown type: the original skips one int
            }
            return list;
        }

        // Level::createShip: BoundingAAB(pos, offset, full size) per kind-1 ship, game units, nose = game +Z.
        static readonly float[][] FreighterBoxes =
        {
            // Terran freighter (ship 15, race 0)
            new float[] { 0, -73, 123, 3000, 2860, 10430,   0, -280, -4257, 3470, 1815, 2200,   0, -770, -4279, 5220, 680, 2270 },
            // Vossk freighter (ship 13)
            new float[] { 0, 351, 5827, 3930, 1590, 2070,   0, 616, 4573, 4440, 2120, 1035,   0, 780, 3303, 4970, 2620, 1895,
                          0, 456, -309, 2695, 3530, 6600,   0, 248, -5587, 3325, 3020, 4205 },
            // Nivelian freighter (race 2)
            new float[] { 0, -85, 24, 4335, 1245, 10880,   0, 710, 292, 2990, 935, 11450,   0, 1510, -2886, 2750, 1010, 2750 },
            // Midorian freighter (race 3)
            new float[] { 0, -199, 4708, 980, 1530, 1240,   0, -14, -98, 4500, 1405, 8860 },
        };

        /// <summary>A freighter's boxes (Level::createShip): Terran / pirate 0, Vossk 1, Nivelian 2, Midorian 3.</summary>
        public static List<GoF2CollisionVolume> ForFreighter(int ship, int race)
        {
            int k = ship == 13 || race == 1 ? 1 : race == 2 ? 2 : race == 3 ? 3 : 0;
            var t = FreighterBoxes[k];
            var list = new List<GoF2CollisionVolume>();
            for (int i = 0; i + 5 < t.Length; i += 6)
                list.Add(Box(ToUnity(t[i], t[i + 1], t[i + 2]), new Vector3(t[i + 3], t[i + 4], t[i + 5]) * (0.5f * M)));
            return list;
        }
    }
}
