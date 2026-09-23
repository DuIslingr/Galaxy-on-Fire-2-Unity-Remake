// GoF2GalaxyMap.cs
// The star map's rules as plain C# (Reference/research/starmap_travel.md, helper Reference/tools/starmap/starmap_tables.py):
//   StarMap::StarMap 0xd6880        galaxy-view sun position per system (integer-truncated game units)
//   SolarSystem::systemIsInSystemRoutes 0x180c86   which systems the gate map can enter (the current one or a gate route)
//   SystemPathFinder 0x14062e..     BFS over jumpRoutesTo, only into visible systems; energy cells = gate jumps, 4 when the
//                                   gates can't reach it, x2 in hardcore (StarMap::OnTouchBegin)
//   StarMap::initStarSystem 0xd7810 system-view layout: java.util.Random(system * 1000), a free slot per station, radius
//                                   6400 + rand(5600) + 1600 (+ rand(5600) + 1600 per next planet), then one orbit yaw each
//   Ship::hasJumpDrive 0x1a39a4     item 85 fitted, or the integrated drive of ships 37 Cronus, 38 Typhon, 40 Nemesis
// Remake-only: the campaign takes the player out of gateless Mido; without it a new game would be stuck there, so in free
// play a ship in a system without a jumpgate counts as having a Khador Drive (it still needs energy cells).

using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Data
{
    public static class GoF2GalaxyMap
    {
        public const int KhadorDriveItem = 85, EnergyCellItem = 122;
        public const int ChargeMs = 5000;   // item 85 attr 37

        /// <summary>DAT_00254484: map planet scale per station texture index (x16 / 65536).</summary>
        static readonly int[] PlanetScale = { 320, 192, 256, 256, 192, 256, 192, 192, 320, 256, 192, 192, 320, 256, 320, 256, 256, 256, 320,
                                              192, 320, 256, 256, 0, 256, 256, 192, 256 };

        /// <summary>DAT_0025451c: security colours, 0 Dangerous .. 3 Secure (texts 402..405).</summary>
        public static readonly Color32[] SecurityColours = { new Color32(255, 42, 0, 255), new Color32(255, 108, 0, 255), new Color32(237, 237, 0, 255), new Color32(0, 237, 0, 255) };

        public struct Planet
        {
            public int station, slot, angle, radius, textureIndex;
            public float scale, orbitYaw;
            public bool ring, gate;
        }

        /// <summary>Status::getSystemVisibilities, set up from systems.json initiallyVisible on first use.</summary>
        public static bool[] Visibility(GoF2Database db)
        {
            int n = 0;
            foreach (var s in db.Systems) n = Mathf.Max(n, s.index + 1);
            if (GoF2Session.SystemVisible == null || GoF2Session.SystemVisible.Length < n)
            {
                var v = new bool[n];
                foreach (var s in db.Systems) v[s.index] = s.initiallyVisible;
                GoF2Session.SystemVisible = v;
            }
            return GoF2Session.SystemVisible;
        }

        public static bool IsVisible(GoF2Database db, int system)
        {
            var v = Visibility(db);
            return system >= 0 && system < v.Length && v[system];
        }

        /// <summary>SolarSystem::hasNoOwner: no race icon, race line or logo.</summary>
        public static bool HasOwner(int system) => system != 23 && system != 24 && system != 26 && system != 32 && system != 33;

        /// <summary>The galaxy-view sun sprite position (game units).</summary>
        public static Vector3 SunPosition(SystemData s)
        {
            var p = s.mapPosition;
            return new Vector3((int)((100 - p.x) / 100.0 * 14000.0) - 10000,
                               (int)((100 - p.y) / 100.0 * 13000.0) - 9000,
                               (int)((100 - p.z) / 100.0 * 6000.0) + 1000);
        }

        public static bool IsInRoutes(SystemData from, int to) => from != null && (from.index == to || from.jumpRoutesTo.Contains(to));

        /// <summary>SystemPathFinder::getSystemPath: [a .. b] through visible systems, null if unreachable or a == b.</summary>
        public static List<int> SystemPath(GoF2Database db, int a, int b)
        {
            if (a == b) return null;
            var visible = Visibility(db);
            var prev = new Dictionary<int, int> { [a] = -1 };
            var queue = new Queue<int>();
            queue.Enqueue(a);
            while (queue.Count > 0)
            {
                int n = queue.Dequeue();
                if (n == b)
                {
                    var path = new List<int> { b };
                    while (prev[path[path.Count - 1]] >= 0) path.Add(prev[path[path.Count - 1]]);
                    path.Reverse();
                    return path;
                }
                var sys = db.Systems.Find(s => s.index == n);
                if (sys == null) continue;
                foreach (int m in sys.jumpRoutesTo)
                    if (m >= 0 && m < visible.Length && visible[m] && !prev.ContainsKey(m)) { prev[m] = n; queue.Enqueue(m); }
            }
            return null;
        }

        /// <summary>StarMap::OnTouchBegin: energy cells for a Khador jump from system a to b ('noGate': the target has no gate
        /// route at all, warning 581).</summary>
        public static int EnergyCells(GoF2Database db, int a, int b, out bool noGate)
        {
            noGate = false;
            var path = SystemPath(db, a, b);
            int n = path != null ? path.Count - 1 : 0;
            if (n == 0 && a != b)
            {
                n = 4;
                var target = db.Systems.Find(s => s.index == b);
                noGate = target == null || target.jumpRoutesTo.Count == 0;
            }
            return GoF2Session.IsExtreme ? n * 2 : n;
        }

        public static int CellsInCargo() => GoF2Session.Cargo.Find(s => s.item == EnergyCellItem)?.amount ?? 0;

        public static void RemoveCells(int n)
        {
            var stack = GoF2Session.Cargo.Find(s => s.item == EnergyCellItem);
            if (stack == null) return;
            stack.amount -= n;
            if (stack.amount <= 0) GoF2Session.Cargo.Remove(stack);
        }

        /// <summary>Ship::hasJumpDriveIntegrated.</summary>
        public static bool HasIntegratedDrive(int ship) => ship == 37 || ship == 38 || ship == 40;

        /// <summary>Ship::hasJumpDrive, plus the remake's free-play rule for gateless systems (see the file header).</summary>
        public static bool HasJumpDrive(GoF2Database db)
        {
            if (HasIntegratedDrive(GoF2Session.ShipIndex) || GoF2Session.Equipment.Exists(e => e.item == KhadorDriveItem)) return true;
            if (GoF2Session.CampaignMission != GoF2Session.FreePlayMission) return false;
            int system = db.Stations.Find(s => s.index == GoF2Session.StationIndex)?.system ?? -1;
            return (db.Systems.Find(s => s.index == system)?.jumpgateStation ?? 0) < 0;
        }

        /// <summary>StarMap::initStarSystem: the system view's planets in station order (same layout on every visit).</summary>
        public static List<Planet> SystemLayout(GoF2Database db, SystemData sys)
        {
            var list = new List<Planet>();
            if (sys == null) return list;
            int n = sys.stations.Count;
            var rnd = new GoF2JavaRandom(sys.index * 1000L);
            var used = new bool[n + 1];
            int radius = 6400;
            foreach (int station in sys.stations)
            {
                int slot;
                do slot = rnd.NextInt(n + 1); while (used[slot]);
                used[slot] = true;
                radius += rnd.NextInt(5600) + 1600;
                int tex = db.Stations.Find(s => s.index == station)?.textureIndex ?? 0;
                list.Add(new Planet
                {
                    station = station, slot = slot, angle = slot * (65536 / (n + 1)), radius = radius, textureIndex = tex,
                    scale = (tex >= 0 && tex < PlanetScale.Length ? PlanetScale[tex] : 256) * 16 / 65536f,
                    ring = tex == 9 || tex == 16 || tex == 21 || station == 120 || station == 126 || station == 130 || station == 132,
                    gate = station == sys.jumpgateStation,
                });
            }
            for (int k = 0; k < list.Count; k++)   // the orbit loop runs after all planets
            {
                var p = list[k];
                p.orbitYaw = rnd.NextInt(3141) / 1000f;
                list[k] = p;
            }
            return list;
        }
    }
}
