// Cheats.cs
// Remake-only testing tools behind the main menu's Debug panel (F10 / LB + RB held / five taps on the version text) and, once that
// has been opened, the in-flight pause menu's Debug page. Toggles live in PlayerPrefs (they stay on across scenes and
// restarts); actions change the running game's Session (and the live ship in flight). Nothing here is in the original.
//   God mode         the player takes no damage, the gamma pool doesn't drain, volatile goods don't blow up
//   Infinite ammo    secondaries (missiles, mines, bombs...) aren't used up
//   No secondary cooldown  a secondary fires again at once (its reload time skipped; the ones still in flight count)
//   One-hit kills    the player's shots destroy whatever they hit (story ships the script keeps invulnerable excepted)
//   Instant locks    scanner / station / planet / asteroid locks complete at once
//   Free shopping    items and ships cost nothing
//   Free jumps       Khador jumps and the cloak need no energy cells
// Plain C#: the hooks read the flags (Target, PlayerHealth, VolatileCargo, WeaponSystem, CombatRadar, Mining,
// Navigation, Hangar, GalaxyMap, PlayerCloak).

using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.Data
{
    public static class Cheats
    {
        /// <summary>The Debug panel has been opened once: the pause menu shows its Debug page from then on.</summary>
        public static bool Unlocked { get => Get("unlocked"); set => Set("unlocked", value); }

        public static bool GodMode { get => Get("godMode"); set => Set("godMode", value); }
        public static bool InfiniteAmmo { get => Get("infiniteAmmo"); set => Set("infiniteAmmo", value); }
        public static bool NoSecondaryCooldown { get => Get("noSecondaryCooldown"); set => Set("noSecondaryCooldown", value); }
        public static bool OneHitKills { get => Get("oneHitKills"); set => Set("oneHitKills", value); }
        public static bool InstantLocks { get => Get("instantLocks"); set => Set("instantLocks", value); }
        public static bool FreeShopping { get => Get("freeShopping"); set => Set("freeShopping", value); }
        public static bool FreeJumps { get => Get("freeJumps"); set => Set("freeJumps", value); }

        /// <summary>The lock time a scanner check should use ('ms' = the normal one).</summary>
        public static int LockMs(int ms) => InstantLocks ? 0 : ms;

        // ---- actions ----------------------------------------------------------------------------------------------

        public static void AddCredits(int amount)
        {
            Session.Credits = (int)Mathf.Min((long)Session.Credits + amount, 999999999L);
        }

        /// <summary>Hull, shield and armor full (the live ship too, in flight), the gamma pool refilled.</summary>
        public static void Repair()
        {
            Session.PlayerHull = Session.PlayerArmor = -1;
            Session.PlayerShield = -1f;
            if (Session.PlayerGamma >= 0f) Session.PlayerGamma = 100f;
            var health = Object.FindAnyObjectByType<PlayerHealth>();
            if (health == null || health.Dead) return;
            var hp = health.Hp;
            hp.hull = hp.maxHull;
            hp.armor = hp.maxArmor;
            hp.shield = hp.maxShield;
            health.Target.hp = hp.hull;
            health.RefillGamma();
        }

        /// <summary>Every system visible on the star map (Session.SystemVisible).</summary>
        public static void RevealAllSystems()
        {
            if (Session.SystemVisible == null) return;
            for (int i = 0; i < Session.SystemVisible.Length; i++) Session.SystemVisible[i] = true;
        }

        /// <summary>Both standing axes neutral and every station's grudge forgotten (no race hostile but pirates / Void).</summary>
        public static void MakePeace()
        {
            if (Session.Standing != null) for (int i = 0; i < Session.Standing.Length; i++) Session.Standing[i] = 0;
            Session.AttackedStations.Clear();
        }

        /// <summary>'amount' units of any item into the hold (a secondary's amount is its ammo once mounted).</summary>
        public static void GiveItem(int item, int amount) => Shop.AddToCargo(item, amount);

        /// <summary>Docked: 'amount' of the item into the hold, then mounted like the hangar does (a one-per-ship item swaps
        /// the mounted one into the hold); the result text.</summary>
        public static string GiveAndMount(Database db, StationStock stock, int item, int amount)
        {
            GiveItem(item, amount);
            if (stock == null) return Localization.Extra("cheatMountDocked", "Mounting works while docked; it is in the hold.");
            var hangar = new Hangar(db, stock);
            switch (hangar.CanMount(item, out int swapWith))
            {
                case Hangar.Result.Ok: hangar.Mount(item); return Localization.Extra("cheatMounted", "Mounted.");
                case Hangar.Result.Swap: hangar.Swap(swapWith, item); return Localization.Extra("cheatMountedSwap", "Mounted; the old one is in the hold.");
                case Hangar.Result.NoFreeSlot: return Localization.Extra("cheatNoSlot", "No free slot: it is in the hold.");
                default: return Localization.Extra("cheatNotMountable", "Not mountable: it is in the hold.");
            }
        }

        /// <summary>'amount' more Energy Cells (122) in the hold.</summary>
        public static void AddEnergyCells(int amount) => Shop.AddToCargo(GalaxyMap.EnergyCellItem, amount);

        /// <summary>Every mounted secondary back to a full stack of 50 (missiles, mines, bombs...).</summary>
        public static void RefillAmmo(Database db)
        {
            foreach (var e in Session.Equipment)
                if (db.Item(e.item)?.TypeId == 1) e.amount = Mathf.Max(e.amount, 50);   // the gun rigs share these stacks
        }

        static bool Get(string key) { try { return PlayerPrefs.GetInt("cheat_" + key, 0) != 0; } catch { return false; } }
        static void Set(string key, bool on) { PlayerPrefs.SetInt("cheat_" + key, on ? 1 : 0); PlayerPrefs.Save(); }
    }
}
