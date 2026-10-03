// NetAggression.cs
// Remake multiplayer: the players who attacked this player. Another player is neutral (a yellow marker) until they hit this
// player's ship with their weapons or an EMP (NetPlayer.HitRpc / EmpRpc, never an NPC's shot, never a squadmate: those
// can't hit); then they are an enemy here, like an NPC the player shot that turned on them: a red marker, and this
// player's auto turret, the turrets riding on a debug hull and the deployed sentry guns fire at them
// (PlayerTurret.PickTarget, SentryGun: whatever is hostileToPlayer; NetPlayer sets the flag on their ship each frame).
// It lasts 120 s from their last hit (every hit starts it again), or until one of the two is destroyed (or the session
// ends). Shooting someone doesn't make them a target by itself (a stray bullet mustn't start a turret fight): they become
// one by shooting back.

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

        /// <summary>'attacker' hit this player's ship: an enemy for the next 120 s (again from every hit).</summary>
        public static void Mark(ulong attacker) => until[attacker] = Time.unscaledTime + HostileSeconds;

        /// <summary>'client' hit this player within the last 120 s, and neither has been destroyed since.</summary>
        public static bool IsHostile(ulong client) => until.TryGetValue(client, out float t) && Time.unscaledTime < t;

        /// <summary>That player was destroyed: no longer an enemy.</summary>
        public static void Forget(ulong client) => until.Remove(client);

        /// <summary>This player died, or the session ended: nobody is an enemy any more.</summary>
        public static void Clear() => until.Clear();
    }
}
