// CheatsCatalog.cs
// The Admin rows (remake-only, see Cheats) as OptionDefs, so the main menu's Admin panel, the pause menu's and the
// station system menu's Admin pages build them with OptionControl like the options. Toggles everywhere; the actions
// only where a game runs (the pause menu and the station), 'notify' reports what they did.

using System;
using System.Collections.Generic;
using GoF2Remake.Data;

namespace GoF2Remake.UI
{
    public static class CheatsCatalog
    {
        static string X(string key, string english) => Localization.Extra(key, english);

        public static List<OptionDef> Toggles() => new List<OptionDef>
        {
            Toggle("cheatGod", () => X("cheatGodMode", "God mode"), () => Cheats.GodMode, v => Cheats.GodMode = v),
            Toggle("cheatAmmo", () => X("cheatInfiniteAmmo", "Infinite ammo"), () => Cheats.InfiniteAmmo, v => Cheats.InfiniteAmmo = v),
            Toggle("cheatOneHit", () => X("cheatOneHitKills", "One-hit kills"), () => Cheats.OneHitKills, v => Cheats.OneHitKills = v),
            Toggle("cheatLocks", () => X("cheatInstantLocks", "Instant locks"), () => Cheats.InstantLocks, v => Cheats.InstantLocks = v),
            Toggle("cheatShop", () => X("cheatFreeShopping", "Free shopping"), () => Cheats.FreeShopping, v => Cheats.FreeShopping = v),
            Toggle("cheatJumps", () => X("cheatFreeJumps", "Free jumps (no energy cells)"), () => Cheats.FreeJumps, v => Cheats.FreeJumps = v),
        };

        public static List<OptionDef> Actions(Database db, Action<string> notify) => new List<OptionDef>
        {
            Button("cheat100k", () => X("cheatCredits100k", "+100 000 credits"), () => { Cheats.AddCredits(100000); notify?.Invoke(Credits()); }),
            Button("cheat1m", () => X("cheatCredits1m", "+1 000 000 credits"), () => { Cheats.AddCredits(1000000); notify?.Invoke(Credits()); }),
            Button("cheatRepair", () => X("cheatRepair", "Repair ship"), () => { Cheats.Repair(); notify?.Invoke(X("cheatRepaired", "Hull, shield and armor repaired.")); }),
            Button("cheatAmmoRefill", () => X("cheatRefillAmmo", "Refill secondaries (50 each)"), () => { Cheats.RefillAmmo(db); notify?.Invoke(X("cheatRefilled", "Secondaries refilled.")); }),
            Button("cheatCells", () => X("cheatEnergyCells", "+20 energy cells"), () => { Cheats.AddEnergyCells(20); notify?.Invoke(X("cheatCellsAdded", "20 energy cells added to the hold.")); }),
            Button("cheatReveal", () => X("cheatRevealMap", "Reveal all systems"), () => { Cheats.RevealAllSystems(); notify?.Invoke(X("cheatRevealed", "Every system is on the star map.")); }),
            Button("cheatPeace", () => X("cheatMakePeace", "Make peace with all races"), () => { Cheats.MakePeace(); notify?.Invoke(X("cheatPeaceMade", "Standing neutral with every race.")); }),
        };

        static string Credits() => $"{X("cheatCreditsNow", "Credits")}: {Session.Credits:N0}";

        static OptionDef Toggle(string id, Func<string> label, Func<bool> get, Action<bool> set) =>
            new OptionDef { id = id, page = OptionPage.Gameplay, kind = OptionKind.Toggle, label = label, getBool = get, setBool = set };

        static OptionDef Button(string id, Func<string> label, Action action) =>
            new OptionDef { id = id, page = OptionPage.Gameplay, kind = OptionKind.Button, label = label, action = action };
    }
}
