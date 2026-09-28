// NetHangar.cs
// Multiplayer: the other players docked at the local player's station, in its hangar (StationLevel adds it while a session
// runs; the ships are HangarTraffic's guests). Where each other player is (NetPlayer) decides:
//   docking here from this station's orbit        flies in and parks on a free slot
//   already docked here when this player arrives  parked at once (so is one who came another way: a load, a new ship)
//   taking off (their own take-off started)        takes off and flies out
//   gone another way (a jump, a load, left)        gone at once
// A player whose ship changes while docked (bought another) gets the new one parked in place of the old.

using System.Collections.Generic;
using GoF2Remake.World;
using UnityEngine;

namespace GoF2Remake.Multiplayer
{
    public sealed class NetHangar : MonoBehaviour
    {
        sealed class Seen
        {
            public NetPlayer.Place place;
            public int station, ship;
        }

        StationLevel level;
        readonly Dictionary<ulong, Seen> seen = new Dictionary<ulong, Seen>();
        readonly HashSet<ulong> present = new HashSet<ulong>();
        readonly List<ulong> gone = new List<ulong>();
        bool first = true;

        public void Setup(StationLevel stationLevel) => level = stationLevel;

        void Update()
        {
            var traffic = level != null ? level.Traffic : null;
            if (traffic == null || level.Layout == null) return;
            int here = level.Layout.stationIndex;
            present.Clear();
            foreach (var p in NetPlayer.All)
            {
                if (p == null || p.IsOwner || !p.IsSpawned) continue;
                ulong id = p.OwnerClientId;
                present.Add(id);
                bool known = seen.TryGetValue(id, out var before);
                bool dockedHere = p.InHangar && p.Station == here;
                if (dockedHere)
                {
                    if (known && before.ship != p.ShipIndex && traffic.HasGuest((long)id)) traffic.GuestLeaves((long)id, false);   // another ship
                    if (p.Where == NetPlayer.Place.Hangar && !traffic.HasGuest((long)id))
                    {
                        // Flies in only when seen docking from this orbit (not on this player's own arrival).
                        bool fly = !first && known && before.place == NetPlayer.Place.Space && before.station == here;
                        traffic.GuestArrives((long)id, p.ShipIndex, fly);
                    }
                    else if (p.Where == NetPlayer.Place.Departing) traffic.GuestLeaves((long)id, true);
                }
                else if (traffic.HasGuest((long)id))
                {
                    // Launched straight into this orbit (their flights off): still a take-off here; else just gone.
                    bool launched = p.InSpace && p.Station == here;
                    traffic.GuestLeaves((long)id, launched);
                }
                if (!known) seen[id] = before = new Seen();
                before.place = p.Where;
                before.station = p.Station;
                before.ship = p.ShipIndex;
            }
            // Players who left the session.
            gone.Clear();
            foreach (var id in seen.Keys) if (!present.Contains(id)) gone.Add(id);
            foreach (var id in gone)
            {
                traffic.GuestLeaves((long)id, false);
                seen.Remove(id);
            }
            first = false;
        }
    }
}
