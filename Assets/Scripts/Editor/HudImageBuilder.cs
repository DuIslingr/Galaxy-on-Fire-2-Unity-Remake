// HudImageBuilder.cs  (Editor only)
// Menu "GoF2/Build HUD Images": cuts the flight HUD's mining and navigation images from the original interface atlases
// into Resources/GoF2Hud (loaded by name by MiningView / NavigationView). Rects: Reference/research/mining.md 3.1
// and 4.7, autopilot_travel.md 1 and 4, starmap_travel.md 11.3 (Android HD = gof2_interface_iphone4.png, plus the images the iPad-large build
// re-binds to gof2_interface2_ipad_large.png; top-left origin, verified by cropping). Sprite strips become numbered frames.

using System.IO;
using UnityEditor;
using UnityEngine;

namespace GoF2Remake.EditorTools
{
    public static class HudImageBuilder
    {
        public const string OutDir = ImportSettings.Root + "/Resources/GoF2Hud";
        const string AtlasDir = ImportSettings.Root + "/Textures/textures/";
        const string Main = "gof2_interface_iphone4.png", Ipad = "gof2_interface2_ipad_large.png", Low = "gof2_interface.png";

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
            (Low, "flare_0", 71, 934, 64, 64, 0, false),     // 1288 lens flare: big hexagon (space_backdrop.md)
            (Low, "flare_1", 160, 902, 64, 64, 0, false),    // 1289 small hexagon
            (Low, "flare_2", 285, 601, 64, 64, 0, false),    // 1290 glow
            (Ipad, "time_extender", 1904, 489, 109, 109, 0, false),     // 0x543 idle clock (combat_equipment.md 3.1)
            (Ipad, "time_extender_on", 1390, 489, 109, 109, 0, false),  // 0x542 active / pressed / flashing
            (Ipad, "emp_bar", 112, 2020, 114, 10, 0, false),            // 0x4d8 EMP bar frame under a near ship (4.1)
            (Ipad, "emp_fill", 1581, 89, 110, 6, 0, false),             // 0x4d7 white fill
            (Main, "autopilot_title", 1, 1982, 83, 51, 0, false),   // 0x4f4 autopilot menu title icon
            (Main, "race_0", 226, 90, 36, 36, 0, false),
            (Main, "race_1", 273, 1889, 36, 36, 0, false),
            (Main, "race_2", 272, 1650, 36, 36, 0, false),
            (Main, "race_3", 2002, 222, 36, 36, 0, false),
            (Main, "race_8", 250, 1010, 36, 36, 0, false),
            (Main, "race_9", 83, 1900, 36, 36, 0, false),
            // Star map (starmap_travel.md 11.3): rings 0x48a / 0x48c, "you are here" pulse 0x4fd, legend icons visited 0x4a2,
            // story 0x454, freelance 0x455, products 0x452; big race logos 0x4a6 0x4a3 0x4a5 0x4a4 (system header, orbit info).
            (Main, "map_ring", 269, 47, 99, 99, 0, false),
            (Main, "map_ring_selected", 317, 739, 143, 143, 0, false),
            (Main, "map_pulse", 1, 1607, 99, 99, 0, false),
            (Main, "map_visited", 326, 148, 21, 18, 0, false),
            (Main, "map_story", 475, 147, 26, 23, 0, false),
            (Main, "map_freelance", 547, 124, 26, 23, 0, false),
            (Main, "map_products", 370, 47, 20, 18, 0, false),
            (Main, "map_home", 249, 487, 18, 18, 0, false),       // 0x545 orange house (the owned Kaamo Club)
            (Main, "logo_0", 337, 1464, 93, 103, 0, false),
            (Main, "logo_1", 1875, 1137, 98, 89, 0, false),
            (Main, "logo_2", 1659, 35, 90, 90, 0, false),
            (Main, "logo_3", 825, 1425, 88, 97, 0, false),
            // Combat (ship_combat.md 7.9): ship markers per faction (red enemy, green friend, yellow neutral): dot 0x4cc
            // 0x4cd 0x4cb, locked ring 0x4c8 0x4ca 0x4c9, near bracket 0x4db 0x4d2 0x4dc, hull bar frame 0x4da 0x4d3 0x4d5 /
            // fill 0x4d9 0x4d4 0x4d6; crates 0x4f1 (far) 0x451 / 0x44d (off screen); player status (0x4ac/0x4ad shield
            // icon, 0x4aa/0x4ab hull icon, 0x4a9 plate, 0x4ae/0x4af shield bar, 0x4a7/0x524/0x4a8 hull + armor bar), hit
            // arcs 0x52c/0x52b (blue) 0x526/0x525 (red), message background 0x4c3.
            (Ipad, "ship_dot_enemy", 66, 1284, 36, 36, 0, false),
            (Ipad, "ship_dot_friend", 1761, 61, 36, 36, 0, false),
            (Ipad, "ship_dot_neutral", 292, 58, 36, 36, 0, false),
            (Ipad, "ship_ring_enemy", 232, 17, 58, 58, 0, false),
            (Ipad, "ship_ring_friend", 292, 1382, 58, 58, 0, false),
            (Ipad, "ship_ring_neutral", 38, 1748, 58, 58, 0, false),
            (Ipad, "ship_bracket_enemy", 292, 1294, 81, 81, 0, false),
            (Ipad, "ship_bracket_friend", 1, 1840, 81, 81, 0, false),
            (Ipad, "ship_bracket_neutral", 149, 17, 81, 81, 0, false),
            (Ipad, "ship_bar_enemy", 399, 89, 114, 10, 0, false),
            (Ipad, "ship_bar_friend", 1821, 89, 114, 10, 0, false),
            (Ipad, "ship_bar_neutral", 1329, 93, 114, 10, 0, false),
            (Ipad, "ship_fill_enemy", 1445, 93, 110, 6, 0, false),
            (Ipad, "ship_fill_friend", 399, 101, 110, 6, 0, false),
            (Ipad, "ship_fill_neutral", 1445, 101, 110, 6, 0, false),
            (Ipad, "crate_dot", 61, 455, 39, 39, 0, false),
            (Ipad, "crate_off", 366, 1214, 58, 58, 0, false),
            (Ipad, "crate_off_void", 295, 1578, 58, 58, 0, false),
            (Main, "status_shield", 511, 78, 41, 42, 0, false),
            (Main, "status_shield_hit", 503, 122, 41, 42, 0, false),
            (Main, "status_hull", 272, 749, 41, 42, 0, false),
            (Main, "status_hull_red", 250, 966, 41, 42, 0, false),
            (Ipad, "status_plate", 112, 1741, 247, 39, 0, false),
            (Ipad, "status_shield_frame", 829, 93, 248, 14, 0, false),
            (Ipad, "status_shield_fill", 149, 1, 248, 14, 0, false),
            (Ipad, "status_hull_frame", 579, 93, 248, 14, 0, false),
            (Ipad, "status_hull_fill", 1440, 195, 248, 14, 0, false),
            (Ipad, "status_armor_fill", 1079, 93, 248, 14, 0, false),
            (Ipad, "hit_side_blue", 112, 112, 324, 1000, 0, false),
            (Ipad, "hit_top_blue", 1012, 1670, 1000, 374, 0, false),
            (Ipad, "hit_side_red", 438, 1074, 325, 892, 0, false),
            (Ipad, "hit_top_red", 438, 112, 1000, 375, 0, false),
            (Main, "message_bg", 1601, 746, 392, 44, 0, false),
            (Ipad, "portrait_bg", 1459, 955, 160, 200, 0, false),     // 0x485 ImageFactory::reload (dialogue_cutscenes.md 1.3)
            (Ipad, "portrait_frame", 1879, 249, 160, 200, 0, false),  // 0x511
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
