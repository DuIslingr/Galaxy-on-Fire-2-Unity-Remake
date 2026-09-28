// NetCrate.cs
// Multiplayer: an orbit authority's crate (a destroyed ship's container) shown to the other players in that orbit (NetOrbit
// asks NetState to spawn one per crate; the host spawns it owned by that player). For the others it is a real Crate (the
// race's container model, the same loot, `remote`: no drift or expiry of its own) while they are in that orbit, so their
// radar marks it and their tractor beam locks and pulls it; it follows the owner's crate until their own beam pulls it.
// One player gets it: the host keeps the claim (the first player whose beam starts pulling; Crate.PullStarted). The others'
// crates are claimedByOther (their radar leaves it, a beam already on it lets go), and the claimant's capture waits until
// the claim is confirmed (captureBlocked). Another player's capture destroys the owner's crate (and so everyone's); the
// owner's own capture or the crate's expiry despawns it (NetOrbit). A claimant who leaves loses the claim.

using System.Collections.Generic;
using System.Linq;
using System.Text;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using Unity.Collections;
using Unity.Netcode;
using UnityEngine;

namespace GoF2Remake.Multiplayer
{
    public sealed class NetCrate : NetworkBehaviour
    {
        const ulong NoClaim = ulong.MaxValue;

        static readonly NetworkVariableReadPermission Read = NetworkVariableReadPermission.Everyone;
        static readonly NetworkVariableWritePermission Owner = NetworkVariableWritePermission.Owner;

        readonly NetworkVariable<int> station = new NetworkVariable<int>(-1);   // server-written at spawn
        readonly NetworkVariable<int> localId = new NetworkVariable<int>(-1);
        readonly NetworkVariable<ulong> claimant = new NetworkVariable<ulong>(NoClaim);   // server-written
        readonly NetworkVariable<Vector3> position = new NetworkVariable<Vector3>(default, Read, Owner);
        readonly NetworkVariable<Quaternion> rotation = new NetworkVariable<Quaternion>(Quaternion.identity, Read, Owner);
        readonly NetworkVariable<int> race = new NetworkVariable<int>(-1, Read, Owner);
        readonly NetworkVariable<FixedString512Bytes> loot = new NetworkVariable<FixedString512Bytes>(default, Read, Owner);   // "item:amount,..."
        readonly NetworkVariable<bool> fromFriend = new NetworkVariable<bool>(false, Read, Owner);
        readonly NetworkVariable<bool> missionCrate = new NetworkVariable<bool>(false, Read, Owner);

        readonly NetSmoothing smoothing = new NetSmoothing();
        Crate crate;          // the owner: the real crate; the others: the copy (while in the orbit)
        bool reported;
        int pendingStation = -1, pendingId = -1;

        public int Station => station.Value;
        /// <summary>Host: when it was spawned (NetState's sweep waits for its owner's position to arrive).</summary>
        public float SpawnedAt { get; private set; }

        /// <summary>Host, before spawning: the orbit and the owner's crate id (written in OnNetworkSpawn).</summary>
        public void Init(int stationIndex, int id)
        {
            pendingStation = stationIndex;
            pendingId = id;
        }

        public override void OnNetworkSpawn()
        {
            DontDestroyOnLoad(gameObject);
            if (IsServer)
            {
                station.Value = pendingStation;
                localId.Value = pendingId;
                SpawnedAt = Time.unscaledTime;
            }
            if (!IsOwner) return;
            crate = NetOrbit.Current != null && NetOrbit.Current.Station == station.Value ? NetOrbit.Current.Crate(localId.Value) : null;
            if (crate == null) return;
            NetOrbit.Current.Register(this, crate);
            position.Value = crate.transform.position;
            rotation.Value = crate.transform.rotation;
            race.Value = crate.race;
            loot.Value = Encode(crate.loot);
            fromFriend.Value = crate.fromFriend;
            missionCrate.Value = crate.missionCrate;
            crate.PullStarted = () => ClaimRpc();
        }

        public override void OnNetworkDespawn()
        {
            if (!IsOwner && crate != null) Destroy(crate.gameObject);
        }

        /// <summary>A beam started pulling it: the claim, if nobody has it yet.</summary>
        [Rpc(SendTo.Server)]
        void ClaimRpc(RpcParams rpc = default)
        {
            if (claimant.Value == NoClaim) claimant.Value = rpc.Receive.SenderClientId;
        }

        /// <summary>The claimant's capture: the owner's crate is gone (and with it everyone's).</summary>
        [Rpc(SendTo.Server)]
        void CapturedRpc(RpcParams rpc = default)
        {
            if (claimant.Value == rpc.Receive.SenderClientId) RemoveRpc();
        }

        [Rpc(SendTo.Owner)]
        void RemoveRpc()
        {
            if (crate != null) Destroy(crate.gameObject);
        }

        /// <summary>A copy for this player (in the crate's orbit): built once the owner's values are here.</summary>
        void BuildCopy()
        {
            if (crate != null || race.Value < 0) return;
            var assets = CombatAssets.Load();
            var prefab = assets != null ? assets.Crate(race.Value) : null;
            var go = prefab != null ? Instantiate(prefab, position.Value, rotation.Value) : new GameObject();
            go.name = "Crate (other player's)";
            crate = go.AddComponent<Crate>();
            crate.remote = true;
            crate.race = race.Value;
            crate.fromFriend = fromFriend.Value;
            crate.missionCrate = missionCrate.Value;
            foreach (var s in Decode(loot.Value.ToString())) crate.loot.Add(s);
            crate.PullStarted = () => ClaimRpc();
            smoothing.Push(position.Value);
            smoothing.Snap();
        }

        void Update()
        {
            if (!IsSpawned) return;
            ulong me = NetworkManager.LocalClientId;
            // A claimant who left loses the claim.
            if (IsServer && claimant.Value != NoClaim && !NetworkManager.ConnectedClientsIds.Contains(claimant.Value)) claimant.Value = NoClaim;
            if (IsOwner)
            {
                if (crate == null) return;   // NetOrbit asks for the despawn
                ApplyClaim(me);
                if ((position.Value - crate.transform.position).sqrMagnitude > 0.0001f) position.Value = crate.transform.position;
                if (Quaternion.Angle(rotation.Value, crate.transform.rotation) > 0.5f) rotation.Value = crate.transform.rotation;
                return;
            }
            var local = NetPlayer.Local;
            bool here = local != null && local.InSpace && local.Station == station.Value;
            if (!here)
            {
                // Not in its orbit (any more): no copy (built again on coming back while it still exists).
                if (crate != null) Destroy(crate.gameObject);
                crate = null;
                copyAlive = false;
                return;
            }
            if (crate == null)
            {
                if (copyAlive)
                {
                    // The copy went while here: this player captured it; the owner removes its crate, once.
                    copyAlive = false;
                    if (!reported && claimant.Value == me) { reported = true; CapturedRpc(); }
                    return;
                }
                if (!reported) BuildCopy();
                return;
            }
            copyAlive = true;
            ApplyClaim(me);
            if (!crate.pulled)
            {
                if (position.Value != lastPosition) { smoothing.Push(position.Value); lastPosition = position.Value; }
                smoothing.Apply(crate.transform, rotation.Value);
            }
        }

        bool copyAlive;
        Vector3 lastPosition;

        void ApplyClaim(ulong me)
        {
            crate.claimedByOther = claimant.Value != NoClaim && claimant.Value != me;
            crate.captureBlocked = claimant.Value != me;
        }

        static string Encode(List<ItemStack> stacks)
        {
            var sb = new StringBuilder();
            foreach (var s in stacks)
            {
                if (s.amount <= 0) continue;
                if (sb.Length > 0) sb.Append(',');
                sb.Append(s.item).Append(':').Append(s.amount);
                if (sb.Length > 480) break;
            }
            return sb.ToString();
        }

        static IEnumerable<ItemStack> Decode(string text)
        {
            foreach (var part in text.Split(','))
            {
                var kv = part.Split(':');
                if (kv.Length == 2 && int.TryParse(kv[0], out int item) && int.TryParse(kv[1], out int amount) && amount > 0)
                    yield return new ItemStack(item, amount);
            }
        }
    }
}
