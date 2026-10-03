// NetAggression.cs
// Remake multiplayer: the players this player is fighting. Another player is neutral (a yellow marker) until one of the two
// hits the other with weapons or an EMP: then both are enemies to each other, like an NPC the player shot that turned on
// them (the victim's game marks the attacker, NetPlayer.HitRpc / EmpRpc; the attacker's game marks the victim,
// NetPlayer's RemoteDamage / RemoteEmp; never an NPC's shot, never a squadmate: those can't hit): a red marker, and the
// auto turret, the turrets riding on a debug hull and the deployed sentry guns fire at them (PlayerTurret.PickTarget,
// SentryGun: whatever is hostileToPlayer; NetPlayer sets the flag on their ship each frame). It lasts 120 s from the last
// hit either way (every hit starts it again), or until one of the two is destroyed (or the session ends).

using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class NetAggression
    {
        public const float HostileSeconds = 120f;

        /// <summary>Attacker client id -> until when it is an enemy (unscaled time).</summary>
        static readonly Dictionary<ulong, float> until = new Dictionary<ulong, float>();

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() => until.Clear();

        /// <summary>'attacker' hit this player's ship, or this player hit theirs: an enemy for the next 120 s (again from every hit).</summary>
        public static void Mark(ulong attacker) => until[attacker] = Time.unscaledTime + HostileSeconds;

        /// <summary>'client' hit this player within the last 120 s, and neither has been destroyed since.</summary>
        public static bool IsHostile(ulong client) => until.TryGetValue(client, out float t) && Time.unscaledTime < t;

        /// <summary>That player was destroyed: no longer an enemy.</summary>
        public static void Forget(ulong client) => until.Remove(client);

        /// <summary>This player died, or the session ended: nobody is an enemy any more.</summary>
        public static void Clear() => until.Clear();
    }
}
