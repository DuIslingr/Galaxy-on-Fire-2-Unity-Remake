// UiImageSlots.cs
// Feature: docs/notes/player-assets.md "Stylesheet images": the interface images the stylesheets name by path (the Original
// interface style's pieces UI/Original/og_*, the flight HUD's crosshairs, the plasma gun's, the campaign cards) are cut from the original's
// atlases or made from its pieces, so a build without the originals hasn't them. stripped_checkout.py puts a 4 x 4
// placeholder of its own at each such path (the original's .meta kept: the stylesheets' references hold), and this fills
// each placeholder texture with the real image once the player's copy is converted (after every scene load: Unity may
// unload and reload the assets), so every state the stylesheets give (hover, focus, pressed) draws it:
//   an exact rectangle of an atlas of the converted copy (found by matching the project's images: Crops), the HUD images
//   the converter cut (GoF2Hud), else the common pack's copy of the remake's processed pieces (Resources/GoF2UiSlots).

using System.Collections.Generic;
using System.IO;
using GoF2Remake.Data;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace GoF2Remake.UI
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class UiImageSlots
    {
        /// <summary>Exact rectangles (x, y from the top left) of the converted copy's atlases (Textures/textures/<atlas>.png).</summary>
        static readonly Dictionary<string, (string atlas, int x, int y, int w, int h)> Crops = new Dictionary<string, (string, int, int, int, int)>
        {
            ["crosshair"] = ("gof2_interface_iphone4", 392, 78, 81, 81),
            ["crosshair_hit"] = ("gof2_interface_iphone4", 1835, 1231, 81, 81),
            ["og_check"] = ("gof2_interface_iphone4", 1764, 337, 66, 63),
            ["og_check_on"] = ("gof2_interface_iphone4", 1696, 337, 66, 63),
            ["og_footer"] = ("gof2_interface_iphone4", 317, 261, 332, 74),
            ["og_header"] = ("gof2_interface_iphone4", 1601, 684, 332, 60),
            ["og_panel_bg"] = ("gof2_interface_iphone4", 317, 417, 320, 320),
            ["og_title_plate"] = ("gof2_interface_iphone4", 317, 1340, 274, 60),
        };

        /// <summary>The images the converter cuts into Resources/GoF2Hud.</summary>
        static readonly HashSet<string> Hud = new HashSet<string> { "plasma_crosshair", "plasma_crosshair_idle" };

        /// <summary>The remake's processed pieces, from the common pack (Resources/GoF2UiSlots/<name>.png in the copy).</summary>
        public static readonly string[] FromPack =
        {
            "og_action",
            "og_action_on",
            "og_button",
            "og_button_on",
            "og_buy",
            "og_buy_on",
            "og_fl_back",
            "og_fl_back_on",
            "og_fl_bar",
            "og_fl_bar_on",
            "og_fl_next",
            "og_fl_next_on",
            "og_frame",
            "og_hg_back",
            "og_hg_back_on",
            "og_hg_bar",
            "og_hg_footer",
            "og_hg_help",
            "og_hg_infotab",
            "og_hg_plate",
            "og_hg_row",
            "og_hg_row_on",
            "og_hg_steel",
            "og_hg_steel_on",
            "og_launch",
            "og_launch_on",
            "og_mm_back",
            "og_mm_back_on",
            "og_mm_section",
            "og_plate",
            "og_row",
            "og_row_on",
            "og_sell",
            "og_sell_on",
            "og_st_back",
            "og_st_back_on",
            "og_st_button",
            "og_st_button_on",
            "og_st_launch",
            "og_st_launch_on",
            "og_tab",
            "og_tab_on",
            "og_tab_press",
            "og_title",
        };

        static bool hooked;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() => hooked = false;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        static void Hook()
        {
            if (hooked) return;
            hooked = true;
            SceneManager.sceneLoaded += (_, __) => Fill();
        }

        /// <summary>Every placeholder texture loaded now (4 x 4, one of the slots' names) given its image; how many.</summary>
        public static int Fill()
        {
            if (OriginalSetup.BuiltIn || !GameContent.Installed) return 0;
            int n = 0;
            foreach (var t in Resources.FindObjectsOfTypeAll<Texture2D>())
            {
                if (t == null || t.width > 4 || t.height > 4) continue;
                var png = ImageOf(t.name);
                if (png == null) continue;
                if (t.LoadImage(png, false)) n++;
            }
            return n;
        }

        /// <summary>The PNG bytes of a slot's image (null: not a slot, or the copy hasn't it).</summary>
        public static byte[] ImageOf(string name)
        {
            var menu = OriginalTextures.MenuImage(name);   // (the campaign cards, the FISHLABS logo)
            if (menu != null) return menu.EncodeToPNG();
            if (Crops.TryGetValue(name, out var c))
            {
                var t = OriginalTextures.Crop(c.atlas, c.x, c.y, c.w, c.h, name);
                return t != null ? t.EncodeToPNG() : null;
            }
            string rel = Hud.Contains(name) ? $"Resources/GoF2Hud/{name}.png"
                       : System.Array.IndexOf(FromPack, name) >= 0 ? $"Resources/GoF2UiSlots/{name}.png" : null;
            var file = rel != null ? GameContent.CachePath(rel) : null;
            return file != null ? File.ReadAllBytes(file) : null;
        }
    }
}
