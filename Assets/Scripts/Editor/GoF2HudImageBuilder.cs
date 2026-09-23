// GoF2HudImageBuilder.cs  (Editor only)
// Menu "GoF2/Build HUD Images": cuts the flight HUD's mining and navigation images from the original interface atlases
// into Resources/GoF2Hud (loaded by name by GoF2MiningView / GoF2NavigationView). Rects: Reference/research/mining.md 3.1
// and 4.7, autopilot_travel.md 1 and 4 (Android HD = gof2_interface_iphone4.png, plus the images the iPad-large build
// re-binds to gof2_interface2_ipad_large.png; top-left origin, verified by cropping). Sprite strips become numbered frames.

using System.IO;
using UnityEditor;
using UnityEngine;

namespace GoF2Remake.EditorTools
{
    public static class GoF2HudImageBuilder
    {
        public const string OutDir = GoF2ImportSettings.Root + "/Resources/GoF2Hud";
        const string AtlasDir = GoF2ImportSettings.Root + "/Textures/textures/";
        const string Main = "gof2_interface_iphone4.png", Ipad = "gof2_interface2_ipad_large.png";

        // atlas, name, x, y, w, h, frames (0 = single image), wrap (marquee strips repeat)
        static readonly (string atlas, string name, int x, int y, int w, int h, int frames, bool repeat)[] Images =
        {
            (Main, "lock", 1, 179, 1920, 80, 24, false),      // 0x456 lock ring, 24 frames 80x80
            (Main, "plate", 1601, 793, 408, 57, 0, false),    // 0x4c4 target plate
            (Main, "class", 447, 2002, 180, 29, 5, false),    // 0x44e class letters A B C D E, 36x29
            (Main, "disc_even_s", 1, 1900, 40, 40, 0, false), // 0x4e2 disc quadrants (top-left quarter of a disc)
            (Main, "disc_even_m", 1, 379, 140, 140, 0, false),   // 0x4dd
            (Main, "disc_even_l", 639, 934, 250, 250, 0, false), // 0x4de
            (Main, "disc_odd_s", 543, 884, 40, 40, 0, false),    // 0x4e1
            (Main, "disc_odd_m", 337, 1720, 140, 140, 0, false), // 0x4df
            (Main, "disc_odd_l", 893, 935, 250, 250, 0, false),  // 0x4e0
            (Main, "core_void", 181, 1607, 89, 66, 0, false),    // 0x522 core of Void Crystals
            (Main, "core", 545, 739, 80, 79, 0, false),          // 0x523 core of the other ores
            (Main, "drill_ring", 1934, 660, 81, 81, 0, false),   // 0x4e7
            (Main, "drill", 639, 855, 660, 66, 10, false),       // 0x4e6 drill bit, 10 frames 66x66
            (Main, "energy_frame", 651, 261, 408, 34, 0, false), // 0x4e3
            (Main, "energy_fill", 614, 1634, 388, 14, 0, false), // 0x4e8
            (Main, "energy_label", 375, 160, 27, 8, 0, false),   // 0x4ed
            (Main, "strip_red", 1452, 1, 194, 11, 0, true),      // 0x4eb scrolling data strips
            (Main, "strip_orange", 162, 1, 194, 12, 0, true),    // 0x4ec
            (Main, "strip_blue", 1706, 147, 103, 18, 0, true),   // 0x4e4 depth strip next to the drill
            (Main, "ore_box", 337, 2002, 108, 45, 0, false),     // 0x4e5 box behind the ore amount
            // Navigation (autopilot_travel.md): bracket 0x4f2, jumpgate icon 0x453, autopilot 0x4b0 / 0x4b1, fast-forward
            // 0x541 / 0x540 and their pill 0x53f, race icons 0x4a1 0x49c 0x49f 0x49e (Terran, Vossk, Nivelian, Midorian),
            // 0x4a0 pirates, 0x49d void.
            (Ipad, "bracket", 292, 1653, 81, 81, 0, false),
            (Ipad, "gate_icon", 1776, 17, 26, 26, 0, false),
            (Ipad, "autopilot", 1, 515, 109, 109, 0, false),
            (Ipad, "autopilot_on", 1097, 782, 109, 109, 0, false),
            (Ipad, "fastforward", 1120, 1295, 109, 109, 0, false),
            (Ipad, "fastforward_on", 1208, 782, 109, 109, 0, false),
            (Ipad, "button_pill", 1740, 112, 126, 293, 0, false),
            (Main, "race_0", 226, 90, 36, 36, 0, false),
            (Main, "race_1", 273, 1889, 36, 36, 0, false),
            (Main, "race_2", 272, 1650, 36, 36, 0, false),
            (Main, "race_3", 2002, 222, 36, 36, 0, false),
            (Main, "race_8", 250, 1010, 36, 36, 0, false),
            (Main, "race_9", 83, 1900, 36, 36, 0, false),
        };

        [MenuItem("GoF2/Build HUD Images", priority = 15)]
        public static void Build()
        {
            var atlases = new System.Collections.Generic.Dictionary<string, Texture2D>();
            Directory.CreateDirectory(OutDir);
            var written = new System.Collections.Generic.List<(string path, bool repeat)>();
            foreach (var im in Images)
            {
                if (!atlases.TryGetValue(im.atlas, out var src))
                {
                    string file = AtlasDir + im.atlas;
                    if (!File.Exists(file)) { Debug.LogError($"GoF2: {file} missing"); continue; }
                    src = new Texture2D(2, 2, TextureFormat.RGBA32, false);
                    src.LoadImage(File.ReadAllBytes(file));
                    atlases[im.atlas] = src;
                }
                int n = Mathf.Max(1, im.frames), fw = im.w / n;
                for (int f = 0; f < n; f++)
                {
                    string path = im.frames > 0 ? $"{OutDir}/{im.name}_{f:00}.png" : $"{OutDir}/{im.name}.png";
                    var px = src.GetPixels(im.x + f * fw, src.height - im.y - im.h, fw, im.h);   // rects are top-left based
                    var o = new Texture2D(fw, im.h, TextureFormat.RGBA32, false);
                    o.SetPixels(px);
                    o.Apply();
                    File.WriteAllBytes(path, o.EncodeToPNG());
                    Object.DestroyImmediate(o);
                    written.Add((path, im.repeat));
                }
            }
            foreach (var t in atlases.Values) Object.DestroyImmediate(t);
            AssetDatabase.Refresh();
            foreach (var (path, repeat) in written)
            {
                var ti = (TextureImporter)AssetImporter.GetAtPath(path);
                if (ti == null) continue;
                ti.textureType = TextureImporterType.Default;
                ti.mipmapEnabled = false;
                ti.alphaIsTransparency = true;
                ti.npotScale = TextureImporterNPOTScale.None;
                ti.wrapMode = repeat ? TextureWrapMode.Repeat : TextureWrapMode.Clamp;
                ti.textureCompression = TextureImporterCompression.Uncompressed;
                ti.SaveAndReimport();
            }
            Debug.Log($"GoF2: {written.Count} HUD images in {OutDir}.");
        }
    }
}
