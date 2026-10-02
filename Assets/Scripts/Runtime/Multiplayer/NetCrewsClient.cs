// NetCrewsClient.cs
// Remake-only: a player's side of the crews (NetCrews): who holds which station (NetState.Claims, read again when it
// changes) for the star map, the station's header and the orbit information; the crew bank's deposits (the server asks,
// the game pays from its credits and answers) and payouts; the home station a destroyed member respawns at
// (NetPlayer.CrewHome).

using System.Collections.Generic;
using GoF2Remake.Data;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class NetCrewsClient
    {
        static string parsedFrom;
        static readonly Dictionary<int, (string tag, string name)> owners = new Dictionary<int, (string, string)>();

        [UnityEngine.RuntimeInitializeOnLoadMethod(UnityEngine.RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { parsedFrom = null; owners.Clear(); }

        static void Refresh()
        {
            string text = NetGame.Active && NetState.Instance != null ? NetState.Instance.Claims : "";
            if (text == parsedFrom) return;
            parsedFrom = text;
            owners.Clear();
            foreach (var line in text.Split('\n'))
            {
                var parts = line.Split('|');
                if (parts.Length >= 3 && int.TryParse(parts[0], out int station)) owners[station] = (parts[1], parts[2]);
            }
        }

        /// <summary>The crew holding 'station' (its tag and name), false = nobody (or no session).</summary>
        public static bool Owner(int station, out string tag, out string name)
        {
            Refresh();
            if (owners.TryGetValue(station, out var o)) { tag = o.tag; name = o.name; return true; }
            tag = name = null;
            return false;
        }

        /// <summary>"[TAG] Name" of the station's crew, "" = none.</summary>
        public static string OwnerText(int station) => Owner(station, out string tag, out string name) ? $"[{tag}] {name}" : "";

        /// <summary>The first crew tag holding a station in 'system' (the star map's galaxy view), null = none.</summary>
        public static string SystemTag(Database db, int system)
        {
            Refresh();
            foreach (var pair in owners)
            {
                var st = db.Stations.Find(s => s.index == pair.Key);
                if (st != null && st.system == system) return pair.Value.tag;
            }
            return null;
        }

        /// <summary>The local player's crew home (respawn), -1 = none.</summary>
        public static int Home => NetPlayer.Local != null ? NetPlayer.Local.CrewHome : -1;

        /// <summary>The server asks for a crew deposit: paid from the credits if there are enough; the answer either way.</summary>
        internal static void OnCharge(int token, int amount)
        {
            bool paid = amount > 0 && Session.Credits >= amount;
            if (paid) Session.Credits -= amount;
            NetState.Instance?.ChargedRpc(token, paid);
            if (paid) { NetProfileClient.Upload(); RefreshStationCredits(); }
        }

        static void RefreshStationCredits() => UnityEngine.Object.FindAnyObjectByType<UI.StationMenu>()?.RefreshCredits();

        /// <summary>Credits from the crew bank.</summary>
        internal static void OnGrant(int amount)
        {
            if (amount <= 0) return;
            Session.Credits += amount;
            NetChat.Notice(string.Format(Localization.Extra("mpCrewGranted", "+{0:N0} credits from the crew bank."), amount));
            NetProfileClient.Upload();
            RefreshStationCredits();
        }
    }
}
