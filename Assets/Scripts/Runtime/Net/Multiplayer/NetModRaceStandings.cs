// NetModRaceStandings.cs
// Remake-only: each player's standings toward mods'races in a session (Session.ModRaceStanding, Modding.ModRaces),
// shared like the game races' axes (NetPlayer.Standing0 / Standing1): an orbit authority's mod race ships treat another
// player by that player's own standing (NetOrbit.HostileTo -> Standing.IsEnemyWith). Without it the authority judged
// everyone by its own standings.
// The owner's NetPlayer carries them as "key=value;key=value" (mod race keys "mod_id:id"; the race numbers can differ
// between games). Packed again only when they change (ModRaces.StandingRevision, or a loaded save's new table).
// Not the multiplayer factions of players (NetFactions): those are the server's guilds.

using System.Collections.Generic;
using System.Globalization;
using System.Text;
using GoF2Remake.Data;
using Unity.Collections;
using UnityEngine;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class NetModRaceStandings
    {
        static Dictionary<string, int> sentTable;   // the Session table last sent (a load or a new game replaces it)
        static int sentRevision = -1;
        static bool warnedFull;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { sentTable = null; sentRevision = -1; warnedFull = false; }

        /// <summary>The owner, every frame: true with the local standings packed when they changed since the last call.</summary>
        public static bool Changed(out FixedString4096Bytes packed)
        {
            packed = default;
            if (ReferenceEquals(sentTable, Session.ModRaceStanding) && sentRevision == Modding.ModRaces.StandingRevision) return false;
            sentTable = Session.ModRaceStanding;
            sentRevision = Modding.ModRaces.StandingRevision;
            packed = Encode(Session.ModRaceStanding);
            return true;
        }

        /// <summary>Forces the next Changed to pack them again (a new NetPlayer: its variable starts empty).</summary>
        public static void Resend() => sentRevision = -1;

        public static FixedString4096Bytes Encode(IReadOnlyDictionary<string, int> standings)
        {
            var sb = new StringBuilder();
            var packed = new FixedString4096Bytes();
            foreach (var kv in standings)
            {
                int before = sb.Length;
                sb.Append(kv.Key).Append('=').Append(kv.Value.ToString(CultureInfo.InvariantCulture)).Append(';');
                if (Encoding.UTF8.GetByteCount(sb.ToString()) > FixedString4096Bytes.UTF8MaxLengthInBytes)
                {
                    sb.Length = before;   // the rest stay this game's (the others see them at theraces' start)
                    if (!warnedFull) { warnedFull = true; Debug.LogWarning("Multiplayer: too many mod race standings to share; some are left out."); }
                    break;
                }
            }
            packed.CopyFromTruncated(sb.ToString());
            return packed;
        }

        /// <summary>Another player's: the variable's text into their table (cleared first).</summary>
        public static void Decode(in FixedString4096Bytes packed, Dictionary<string, int> into)
        {
            into.Clear();
            foreach (var entry in packed.ToString().Split(';'))
            {
                int eq = entry.LastIndexOf('=');
                if (eq <= 0) continue;
                if (int.TryParse(entry.Substring(eq + 1), NumberStyles.Integer, CultureInfo.InvariantCulture, out int v))
                    into[entry.Substring(0, eq)] = Mathf.Clamp(v, -100, 100);
            }
        }
    }
}
