// ModLoading.cs
// Remake mods: what the main menu's loading screen shows (UI.ModLoadingView) while the mods that are on load in the
// background: their ship models (ModShips, all at once), stations and rooms (ModStations), weapon fx (ModWeapons), music
// (ModMusic) and sound effects (ModSounds). Busy until all are done; Progress weighs each ship as four steps, each
// station three, each weapon two and each track or sound one.

using System.Collections.Generic;

namespace GoF2Remake.Modding
{
    public static class ModLoading
    {
        /// <summary>Something of the mods is still loading.</summary>
        public static bool Busy => !ModShips.Ready || !ModStations.Ready || !ModWeapons.Ready || !ModMusic.Ready || !ModSounds.Ready;

        /// <summary>How far it is, 0..1.</summary>
        public static float Progress
        {
            get
            {
                float shipWeight = ModShips.Count * 4f, stationWeight = ModStations.Count * 3f + 1f, weaponWeight = ModWeapons.Count * 2f;
                float musicWeight = ModMusic.Count, soundWeight = ModSounds.Count;
                float total = shipWeight + stationWeight + weaponWeight + musicWeight + soundWeight;
                float music = ModMusic.Count > 0 ? (ModMusic.Count - ModMusic.Loading) / (float)ModMusic.Count : 1f;
                float sounds = ModSounds.Count > 0 ? (ModSounds.Count - ModSounds.Loading) / (float)ModSounds.Count : 1f;
                float weapons = ModWeapons.Count > 0 ? ModWeapons.Done / (float)ModWeapons.Count : 1f;
                return (ModShips.Progress * shipWeight + ModStations.Progress * stationWeight + weapons * weaponWeight
                        + music * musicWeight + sounds * soundWeight) / total;
            }
        }

        /// <summary>What is loading now, in words (the ship being built, else the music).</summary>
        public static string Line
        {
            get
            {
                var parts = new List<string>();
                if (!ModShips.Ready && ModShips.Count > 0)
                    parts.Add(string.Format(Data.Localization.Extra("modsLoadingShips", "Ships {0} / {1}"), ModShips.Done, ModShips.Count)
                              + (ModShips.Current != null ? ": " + ModShips.Current : ""));
                if (!ModStations.Ready && ModStations.Count > 0)
                    parts.Add(string.Format(Data.Localization.Extra("modsLoadingStations", "Stations {0} / {1}"), ModStations.Done, ModStations.Count)
                              + (ModStations.Current != null ? ": " + ModStations.Current : ""));
                if (!ModWeapons.Ready && ModWeapons.Count > 0)
                    parts.Add(string.Format(Data.Localization.Extra("modsLoadingWeapons", "Weapons {0} / {1}"), ModWeapons.Done, ModWeapons.Count));
                if (!ModSounds.Ready && ModSounds.Count > 0)
                    parts.Add(string.Format(Data.Localization.Extra("modsLoadingSounds", "Sounds {0} / {1}"), ModSounds.Count - ModSounds.Loading, ModSounds.Count));
                if (!ModMusic.Ready && ModMusic.Count > 0)
                    parts.Add(string.Format(Data.Localization.Extra("modsLoadingMusic", "Music {0} / {1}"), ModMusic.Count - ModMusic.Loading, ModMusic.Count));
                return string.Join("   ·   ", parts);
            }
        }
    }
}
