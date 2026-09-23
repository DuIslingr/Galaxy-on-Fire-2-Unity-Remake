// GoF2HudImageBuilder.cs  (Editor only)
// Menu "GoF2/Build HUD Images": cuts the flight HUD's mining images from the original interface atlas into
// Resources/GoF2Hud (loaded by name by GoF2MiningView). Rects: Reference/research/mining.md 3.1 and 4.7 (Android HD =
// gof2_interface_iphone4.png, top-left origin, verified by cropping); sprite strips are split into numbered frames.

using System.IO;
using UnityEditor;
using UnityEngine;

namespace GoF2Remake.EditorTools
{
    public static class GoF2HudImageBuilder
    {
        public const string OutDir = GoF2ImportSettings.Root + "/Resources/GoF2Hud";
        const string Atlas = GoF2ImportSettings.Root + "/Textures/textures/gof2_interface_iphone4.png";

        // name, x, y, w, h, frames (0 = single image), wrap (marquee strips repeat)
        static readonly (string name, int x, int y, int w, int h, int frames, bool repeat)[] Images =
        {
            ("lock", 1, 179, 1920, 80, 24, false),      // 0x456 lock ring, 24 frames 80x80
            ("plate", 1601, 793, 408, 57, 0, false),    // 0x4c4 target plate
            ("class", 447, 2002, 180, 29, 5, false),    // 0x44e class letters A B C D E, 36x29
            ("disc_even_s", 1, 1900, 40, 40, 0, false), // 0x4e2 disc quadrants (top-left quarter of a disc)
            ("disc_even_m", 1, 379, 140, 140, 0, false),   // 0x4dd
            ("disc_even_l", 639, 934, 250, 250, 0, false), // 0x4de
            ("disc_odd_s", 543, 884, 40, 40, 0, false),    // 0x4e1
            ("disc_odd_m", 337, 1720, 140, 140, 0, false), // 0x4df
            ("disc_odd_l", 893, 935, 250, 250, 0, false),  // 0x4e0
            ("core_void", 181, 1607, 89, 66, 0, false),    // 0x522 core of Void Crystals
            ("core", 545, 739, 80, 79, 0, false),          // 0x523 core of the other ores
            ("drill_ring", 1934, 660, 81, 81, 0, false),   // 0x4e7
            ("drill", 639, 855, 660, 66, 10, false),       // 0x4e6 drill bit, 10 frames 66x66
            ("energy_frame", 651, 261, 408, 34, 0, false), // 0x4e3
            ("energy_fill", 614, 1634, 388, 14, 0, false), // 0x4e8
            ("energy_label", 375, 160, 27, 8, 0, false),   // 0x4ed
            ("strip_red", 1452, 1, 194, 11, 0, true),      // 0x4eb scrolling data strips
            ("strip_orange", 162, 1, 194, 12, 0, true),    // 0x4ec
            ("strip_blue", 1706, 147, 103, 18, 0, true),   // 0x4e4 depth strip next to the drill
            ("ore_box", 337, 2002, 108, 45, 0, false),     // 0x4e5 box behind the ore amount
        };

        [MenuItem("GoF2/Build HUD Images", priority = 15)]
        public static void Build()
        {
            if (!File.Exists(Atlas)) { Debug.LogError($"GoF2: {Atlas} missing"); return; }
            var src = new Texture2D(2, 2, TextureFormat.RGBA32, false);
            src.LoadImage(File.ReadAllBytes(Atlas));
            Directory.CreateDirectory(OutDir);
            var written = new System.Collections.Generic.List<(string path, bool repeat)>();
            foreach (var im in Images)
            {
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
            Object.DestroyImmediate(src);
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
