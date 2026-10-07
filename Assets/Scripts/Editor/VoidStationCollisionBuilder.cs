// VoidStationCollisionBuilder.cs
// Menu "GoF2/Build/Void Station Collision": Resources/GoF2Data/void_station_extra.json, the remake's extra collision boxes
// for the Void station in the alien orbit (#37). The station is shown at its held full-size pose (the hull x10.065, 13.6 km
// across, OrbitBuilder.SpawnStation / PartAnimation.HoldAllAfterOneOff); the original's 1001 volumes reach +-5.5 km, so its
// outer blades and lower spire had no collision (in the original too). The builder puts the prefab in that pose, rasterises
// its solid hull's triangles (not the additive or emissive layers) into 400 m cells, keeps the cells whose centre none of
// the 1001 volumes contains, merges runs along x and writes them as boxes (centre, half size; Unity metres, relative to the
// station, which stands at the origin unrotated). CollisionVolume.ForStation adds them in the alien orbit (not to the
// battlestation's 1003). Run it again after changing the station's model or its animation.

using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.IO;
using System.Reflection;
using System.Text;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using GoF2Remake.World;
using UnityEditor;
using UnityEngine;

namespace GoF2Remake.EditorTools
{
    public static class VoidStationCollisionBuilder
    {
        const string PrefabPath = "Assets/Resources/Assembled/main/stations/station_void.prefab";
        const string OutPath = "Assets/Resources/GoF2Data/void_station_extra.json";
        const float Cell = 400f;

        [MenuItem("GoF2/Build/Void Station Collision", priority = 208)]
        public static void Build()
        {
            var prefab = AssetDatabase.LoadAssetAtPath<GameObject>(PrefabPath);
            if (prefab == null) { Debug.LogError($"VoidStationCollisionBuilder: {PrefabPath} missing"); return; }
            var go = Object.Instantiate(prefab);
            go.hideFlags = HideFlags.HideAndDontSave;
            try
            {
                go.transform.SetPositionAndRotation(Vector3.zero, OrbitLayout.RotationToUnity(new Vector3(0f, Mathf.PI, 0f)));
                // PartAnimation.Awake doesn't run outside Play mode: parse the keys, then hold the in-game pose.
                var awake = typeof(PartAnimation).GetMethod("Awake", BindingFlags.Instance | BindingFlags.NonPublic);
                foreach (var a in go.GetComponentsInChildren<PartAnimation>(true)) awake?.Invoke(a, null);
                PartAnimation.HoldAllAfterOneOff(go);

                var cells = new HashSet<Vector3Int>();
                foreach (var mf in go.GetComponentsInChildren<MeshFilter>(true))
                {
                    var mesh = mf.sharedMesh;
                    if (mesh == null || mf.name.Contains("_add") || mf.name.Contains("emissive")) continue;
                    var v = mesh.vertices;
                    var t = mesh.triangles;
                    var tr = mf.transform;
                    for (int i = 0; i + 2 < t.Length; i += 3)
                    {
                        var a = tr.TransformPoint(v[t[i]]);
                        var b = tr.TransformPoint(v[t[i + 1]]);
                        var c = tr.TransformPoint(v[t[i + 2]]);
                        float len = Mathf.Max((b - a).magnitude, (c - a).magnitude, (c - b).magnitude);
                        int n = Mathf.Clamp(Mathf.CeilToInt(len / (Cell * 0.5f)), 1, 400);   // a sample every 200 m along the longest edge
                        for (int u = 0; u <= n; u++)
                            for (int w = 0; w <= n - u; w++)
                            {
                                var p = a + (b - a) * (u / (float)n) + (c - a) * (w / (float)n);
                                cells.Add(new Vector3Int(Mathf.FloorToInt(p.x / Cell), Mathf.FloorToInt(p.y / Cell), Mathf.FloorToInt(p.z / Cell)));
                            }
                    }
                }

                CollisionVolume.ClearVoidStationExtras();
                var original = VoidBase();
                var missed = new List<Vector3Int>();
                foreach (var k in cells)
                {
                    var centre = ((Vector3)k + Vector3.one * 0.5f) * Cell;
                    bool covered = false;
                    foreach (var vol in original) if (vol.Contains(centre)) { covered = true; break; }
                    if (!covered) missed.Add(k);
                }
                missed.Sort((p, q) => p.y != q.y ? p.y.CompareTo(q.y) : p.z != q.z ? p.z.CompareTo(q.z) : p.x.CompareTo(q.x));

                var sb = new StringBuilder("{\"cell\":").Append(Cell.ToString(CultureInfo.InvariantCulture)).Append(",\"boxes\":[");
                int boxes = 0;
                for (int i = 0; i < missed.Count;)
                {
                    int j = i;
                    while (j + 1 < missed.Count && missed[j + 1].y == missed[i].y && missed[j + 1].z == missed[i].z && missed[j + 1].x == missed[j].x + 1) j++;
                    float x0 = missed[i].x * Cell, x1 = (missed[j].x + 1) * Cell;
                    var centre = new Vector3((x0 + x1) * 0.5f, (missed[i].y + 0.5f) * Cell, (missed[i].z + 0.5f) * Cell);
                    var half = new Vector3((x1 - x0) * 0.5f, Cell * 0.5f, Cell * 0.5f);
                    if (boxes > 0) sb.Append(',');
                    sb.Append(string.Join(",", new[] { centre.x, centre.y, centre.z, half.x, half.y, half.z }.Select(f => f.ToString("0.#", CultureInfo.InvariantCulture))));
                    boxes++;
                    i = j + 1;
                }
                sb.Append("]}");
                File.WriteAllText(OutPath, sb.ToString());
                AssetDatabase.ImportAsset(OutPath);
                CollisionVolume.ClearVoidStationExtras();
                Debug.Log($"VoidStationCollisionBuilder: {cells.Count} hull cells, {missed.Count} outside the 1001 volumes -> {boxes} boxes in {OutPath}");
            }
            finally
            {
                Object.DestroyImmediate(go);
            }
        }

        /// <summary>The original's 1001 volumes alone (the extras left out).</summary>
        static List<CollisionVolume> VoidBase()
        {
            var all = CollisionVolume.ForStation(-1, true);
            int extras = CollisionVolume.VoidStationExtras().Count;
            return all.GetRange(0, Mathf.Max(0, all.Count - extras));
        }
    }
}
