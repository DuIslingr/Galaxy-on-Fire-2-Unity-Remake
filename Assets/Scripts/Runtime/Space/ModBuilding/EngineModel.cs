// EngineModel.cs
// Remake mods: a Galaxy on Fire 3 engine effect as the game itself draws it (ships.json "engineFx": { "meshes":
// "fx/engines/<name>.json" }), written by the GoF3 importer (tools/engine_meshes.py) from an engine scene: each part's mesh
// (positions, normals, UVs, vertex colours, a sprite's corner offsets), its place in the engine's frame (GoF3 units, +z
// backward along the exhaust), its textures, the options of the shader variant GoF3 compiled for its material (sprite,
// texture or colour, luminance alpha, flow map, UV scroll, colourise, angle blend, pulsate, vertex wobble, additive or alpha)
// with the material's values, and its animations ("loop": the Nivelian spiral's turn; "ignite": the Terran engine's burst;
// "off": the capital engines' flicker out). EngineFx draws the parts at every exhaust with GoF2/ModEngineMesh.

using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Modding
{
    [System.Serializable] public class EngineModelFile
    {
        public string source;
        public EnginePart[] parts;
    }

    [System.Serializable] public class EnginePart
    {
        public string name;
        public float[] pos, rot, scale;          // in the engine's frame: GoF3 units, quaternion x y z w
        public float[] v, n, uv, c, o;           // positions, normals, UV, colours (rgba 0..1), a sprite's offsets (2 per vertex)
        public int[] i;
        public string texture, flowMap;          // the mod's PNGs
        public bool sprite, useTex, lumAlpha, rgbFromDc, mulDc, flow, scrollDirect, scrollFlow, colorizeVtx, pulsate, vertexAnim, opaqueVtxAlpha, cullBack;
        public int colorize, angle, blend = 2;   // colourise 0 / 1 / 2; angle 0 none, 1 |N.E|, 2 -N.E, 3 N.E; blend 2 additive, 1 alpha
        public float opacity = 1f, colorizeMul = 1f, angleMin, angleMax = 1f, pulseMin, pulseMax = 1f, pulseFreq = 1f;
        public float flowTiling = 1f, flowStrength, vaFreq, vaStrength, alpha = 1f;
        public string tint;                      // which exhaust style colour recolours it: "main" or "second" (default: "second"
                                                 // for GoF3's helix, a part named "...spiral", else "main"; EngineFx)
        public float intensity;                  // GoF2/ModEngineMesh's _Intensity (how much brighter than its formula GoF3
                                                 // shows the part); 0 = the shader's 4
        public float[] diffuse, c1, c2, uvSpeed;
        public EngineAnim[] anims;
    }

    [System.Serializable] public class EngineAnim
    {
        public string kind;                      // "loop", "ignite", "off"
        public float length;                     // ms
        public EngineChannel[] channels;
    }

    [System.Serializable] public class EngineChannel
    {
        public string name;                      // "rotation.x".."w", "translation.x".."z", "scale.x".."z", "alpha"
        public float[] keys;                     // time (ms), value, time, value...

        public float Sample(float ms)
        {
            if (keys == null || keys.Length < 2) return 0f;
            if (ms <= keys[0]) return keys[1];
            for (int k = 2; k + 1 < keys.Length; k += 2)
                if (ms <= keys[k])
                {
                    float t0 = keys[k - 2], t1 = keys[k];
                    return Mathf.Lerp(keys[k - 1], keys[k + 1], t1 > t0 ? (ms - t0) / (t1 - t0) : 1f);
                }
            return keys[keys.Length - 1];
        }
    }

    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class EngineModels
    {
        static readonly Dictionary<string, EngineModelFile> cache = new Dictionary<string, EngineModelFile>();
        static int revision = -1;

        /// <summary>The mod's engine part file, read once per set of mods; null (with a warning on the mod) when it is
        /// missing or unreadable.</summary>
        public static EngineModelFile Get(ModInfo mod, string path)
        {
            if (mod?.Source == null || string.IsNullOrEmpty(path)) return null;
            if (revision != ModManager.Revision) { cache.Clear(); revision = ModManager.Revision; }
            string key = mod.Id + "|" + path;
            if (cache.TryGetValue(key, out var have)) return have;
            EngineModelFile file = null;
            try
            {
                var text = mod.Source.ReadText(path);
                if (text == null) mod.Warnings.Add($"engineFx: {path} isn't in the mod");
                else
                {
                    file = JsonUtility.FromJson<EngineModelFile>(text);
                    if (file?.parts == null || file.parts.Length == 0) { mod.Warnings.Add($"engineFx: {path} has no parts"); file = null; }
                }
            }
            catch (System.Exception e) when (!(e is System.OutOfMemoryException))
            {
                mod.Warnings.Add($"engineFx: {path}: {e.Message}");   // (a damaged zip entry or bad JSON: the cards' engine then)
                file = null;
            }
            cache[key] = file;
            return file;
        }

        /// <summary>The PNGs the file's parts use (for preloading): the textures in colour space as GoF3 read them (raw),
        /// so linear; the flow maps likewise.</summary>
        public static IEnumerable<string> Textures(ModInfo mod, string path)
        {
            var f = Get(mod, path);
            if (f?.parts == null) yield break;
            foreach (var p in f.parts)
            {
                if (!string.IsNullOrEmpty(p.texture)) yield return p.texture;
                if (!string.IsNullOrEmpty(p.flowMap)) yield return p.flowMap;
            }
        }
    }
}
