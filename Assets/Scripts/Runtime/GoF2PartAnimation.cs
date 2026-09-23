// GoF2PartAnimation.cs
// Plays the original keyframe animation stored in each model's .gof2mesh.json sidecar
// (station rings, rotating parts, animated FX). Attached automatically by "GoF2/Build Materials And Prefabs".
//
// Keyframe times are milliseconds. The original stores position in a Z-up layout that the engine swaps
// to Y-up (engine = (c0, c2, -c1)); engine -> Unity is (x, y, -z) once the import step has turned the
// models to face +Z (GoF2ModelOrientationPostprocessor). Rotation axis mapping could not be
// fully confirmed from the decompiled code, so it is exposed below: if a part spins around the wrong
// axis, change the rotation mapping in the inspector.

using System;
using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Visuals
{
    [Serializable] public class GoF2Key { public float t; public float v; }
    [Serializable] public class GoF2Channel { public string target; public GoF2Key[] keys; }
    [Serializable] public class GoF2Part
    {
        public string name, parent;
        public int vertices;
        public float[] pivot, bsphere;
        public bool hasUV, hasNormals, hasColors;
        public GoF2Channel[] channels;
    }
    [Serializable] public class GoF2MeshMeta
    {
        public string source;
        public int version, flags;
        public bool truncated;
        public GoF2Part[] parts;
    }

    /// <summary>Which recovered channel drives a Unity axis, and with which sign.</summary>
    [Serializable] public struct AxisMap { public int source; public float sign; }

    public class GoF2PartAnimation : MonoBehaviour
    {
        public TextAsset meta;
        public bool play = true;
        public bool loop = true;
        public float speed = 1f;
        [Tooltip("Must match the model import scale (GoF2ImportSettings.ModelScale).")]
        public float metersPerUnit = 0.05f;

        [Header("Axis mapping (source channel 0/1/2 = file X/Y/Z)")]
        public AxisMap[] positionMap = { new AxisMap { source = 0, sign = 1 }, new AxisMap { source = 2, sign = 1 }, new AxisMap { source = 1, sign = 1 } };
        public AxisMap[] rotationMap = { new AxisMap { source = 0, sign = -1 }, new AxisMap { source = 2, sign = -1 }, new AxisMap { source = 1, sign = -1 } };
        public bool rotationInRadians = true;

        class Track { public Transform tr; public GoF2Key[][] pos = new GoF2Key[3][]; public GoF2Key[][] rot = new GoF2Key[3][]; public GoF2Key[][] scl = new GoF2Key[3][]; public Vector3 basePos; public Quaternion baseRot; public Vector3 baseScale; }
        readonly List<Track> tracks = new List<Track>();
        float timeMs, lengthMs;

        void Awake()
        {
            if (meta == null) return;
            var m = JsonUtility.FromJson<GoF2MeshMeta>(meta.text);
            if (m == null || m.parts == null) return;
            var byName = new Dictionary<string, Transform>();
            foreach (var t in GetComponentsInChildren<Transform>(true)) if (!byName.ContainsKey(t.name)) byName[t.name] = t;

            foreach (var p in m.parts)
            {
                if (p.channels == null || p.channels.Length == 0) continue;
                if (!byName.TryGetValue(p.name, out var tr)) continue;
                var tk = new Track { tr = tr, basePos = tr.localPosition, baseRot = tr.localRotation, baseScale = tr.localScale };
                foreach (var c in p.channels)
                {
                    if (c.keys == null || c.keys.Length == 0 || string.IsNullOrEmpty(c.target) || c.target.Length < 4) continue;
                    int axis = "XYZ".IndexOf(c.target[3]);
                    if (axis < 0) continue;
                    if (c.target.StartsWith("pos")) tk.pos[axis] = c.keys;
                    else if (c.target.StartsWith("rot")) tk.rot[axis] = c.keys;
                    else if (c.target.StartsWith("scl")) tk.scl[axis] = c.keys;
                    lengthMs = Mathf.Max(lengthMs, c.keys[c.keys.Length - 1].t);
                }
                tracks.Add(tk);
            }
            enabled = tracks.Count > 0 && lengthMs > 0f;
        }

        static float Eval(GoF2Key[] k, float t, float fallback)
        {
            if (k == null || k.Length == 0) return fallback;
            if (t <= k[0].t) return k[0].v;
            for (int i = 1; i < k.Length; i++)
                if (t <= k[i].t)
                {
                    float span = k[i].t - k[i - 1].t;
                    return span <= 0f ? k[i].v : Mathf.Lerp(k[i - 1].v, k[i].v, (t - k[i - 1].t) / span);
                }
            return k[k.Length - 1].v;
        }

        static Vector3 Map(float[] src, AxisMap[] map) =>
            new Vector3(src[map[0].source] * map[0].sign, src[map[1].source] * map[1].sign, src[map[2].source] * map[2].sign);

        void Update()
        {
            if (!play) return;
            timeMs += Time.deltaTime * 1000f * speed;
            if (timeMs > lengthMs) timeMs = loop ? timeMs % Mathf.Max(1f, lengthMs) : lengthMs;

            foreach (var tk in tracks)
            {
                if (tk.pos[0] != null || tk.pos[1] != null || tk.pos[2] != null)
                {
                    var p = new[] { Eval(tk.pos[0], timeMs, 0), Eval(tk.pos[1], timeMs, 0), Eval(tk.pos[2], timeMs, 0) };
                    tk.tr.localPosition = tk.basePos + Map(p, positionMap) * metersPerUnit;
                }
                if (tk.rot[0] != null || tk.rot[1] != null || tk.rot[2] != null)
                {
                    var r = new[] { Eval(tk.rot[0], timeMs, 0), Eval(tk.rot[1], timeMs, 0), Eval(tk.rot[2], timeMs, 0) };
                    var e = Map(r, rotationMap) * (rotationInRadians ? Mathf.Rad2Deg : 1f);
                    tk.tr.localRotation = tk.baseRot * Quaternion.Euler(e);
                }
                if (tk.scl[0] != null || tk.scl[1] != null || tk.scl[2] != null)
                {
                    var s = new[] { Eval(tk.scl[0], timeMs, 1), Eval(tk.scl[1], timeMs, 1), Eval(tk.scl[2], timeMs, 1) };
                    var v = new Vector3(s[positionMap[0].source], s[positionMap[1].source], s[positionMap[2].source]);
                    tk.tr.localScale = Vector3.Scale(tk.baseScale, v);
                }
            }
        }
    }
}
