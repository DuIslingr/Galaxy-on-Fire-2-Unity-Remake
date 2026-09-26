// HangarTraffic.cs
// Remake-only: the hangar's other ships come and go (the original's parked ships never move, Level::createScene 0x17).
// The hangar starts with the original's parked ships (0..max, StationLevel). Every 12-35 s one ship either lands on a
// free parked-ship slot (a new one, picked like the parked ships: 70 % the hangar's race, else any race or pirates; the
// emptier the hangar, the likelier; parked at a random yaw like them) or takes off from its slot and leaves through
// the forcefield (HangarFlight). At most one flight is in the air at a time, the player's included, so nothing flies through
// anything: the traffic waits while the player lands or takes off, and a departing player holds over its pad while
// an NPC flight finishes (StationLevel). Never more ships than the original's parked maximum.
// Plain C#: StationLevel creates and ticks it (not in the owned Kaamo Club, whose parked ships are the stored hulls).

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;
using Random = UnityEngine.Random;
using Object = UnityEngine.Object;

namespace GoF2Remake.World
{
    public sealed class HangarTraffic
    {
        public sealed class Parked
        {
            public GameObject go;
            public int slot, ship;
        }

        const float MinGapMs = 12000f, MaxGapMs = 35000f;

        readonly StationTables.HangarLane lane;
        readonly int slotCount, max;
        readonly List<Parked> parked;
        readonly Database db;
        readonly Func<int> randomShip;
        readonly Func<int, int, Vector3> padPosition;                 // (slot, ship) -> the ship's parked pivot
        readonly Func<int, Vector3, Quaternion, GameObject> spawn;     // (ship, position, rotation) -> the ship

        HangarFlight flight;
        Parked flying;
        float nextMs;

        /// <summary>An NPC ship is in the air (its whole flight: the lane runs over the other pads).</summary>
        public bool Busy => flight != null;

        public HangarTraffic(StationTables.HangarLane lane, int slotCount, int max, List<Parked> parked, Database db,
                             Func<int> randomShip, Func<int, int, Vector3> padPosition, Func<int, Vector3, Quaternion, GameObject> spawn)
        {
            this.lane = lane;
            this.slotCount = slotCount;
            this.max = Mathf.Min(max, slotCount);
            this.parked = parked;
            this.db = db;
            this.randomShip = randomShip;
            this.padPosition = padPosition;
            this.spawn = spawn;
            nextMs = Random.Range(4000f, 12000f);
        }

        /// <summary>'playerFlying': the player's own flight is running or about to (then no new flight starts).</summary>
        public void Update(float dtMs, bool playerFlying)
        {
            if (flight != null)
            {
                flight.Update(dtMs / 1000f);
                if (!flight.Done) return;
                if (flight.arriving) parked.Add(flying);
                else if (flying.go != null) Object.Destroy(flying.go);
                flight = null;
                flying = null;
                nextMs = Random.Range(MinGapMs, MaxGapMs);
                return;
            }
            if (playerFlying || (nextMs -= dtMs) > 0f) return;
            nextMs = Random.Range(MinGapMs, MaxGapMs);
            parked.RemoveAll(p => p.go == null);
            // Landings are likelier the emptier the hangar is (80 % empty .. 20 % full), so it stays busy.
            bool canLand = parked.Count < max;
            bool land = canLand && (parked.Count == 0 || Random.value < Mathf.Lerp(0.8f, 0.2f, (float)parked.Count / max));
            if (land) Land();
            else if (parked.Count > 0) TakeOff(parked[Random.Range(0, parked.Count)]);
        }

        void Land()
        {
            var free = new List<int>();
            for (int i = 0; i < slotCount; i++) if (!parked.Exists(p => p.slot == i)) free.Add(i);
            if (free.Count == 0) return;
            int slot = free[Random.Range(0, free.Count)], ship = randomShip();
            var go = spawn(ship, lane.gate, Quaternion.identity);
            if (go == null) return;
            flying = new Parked { go = go, slot = slot, ship = ship };
            var engine = HangarFlight.AddEngine(go, false, db, ship, out float volume);
            // Parked at a random yaw like the ships already there (Level::createScene: nextInt(300) / 100 rad).
            var parkedYaw = OrbitLayout.RotationToUnity(new Vector3(0f, Random.Range(0, 300) / 100f, 0f));
            flight = HangarFlight.Arrival(go.transform, lane, padPosition(slot, ship), parkedYaw, engine, volume);
        }

        void TakeOff(Parked p)
        {
            if (p.go == null) return;
            parked.Remove(p);
            flying = p;
            foreach (var old in p.go.GetComponents<AudioSource>()) Object.Destroy(old);   // a ship that landed earlier
            var engine = HangarFlight.AddEngine(p.go, false, db, p.ship, out float volume);
            flight = HangarFlight.Departure(p.go.transform, lane, engine, volume);
        }

        /// <summary>The engine loops pause with their inactive ships in the lounge; start them again.</summary>
        public void ResumeAudio()
        {
            if (flight == null || flying?.go == null) return;
            var src = flying.go.GetComponent<AudioSource>();
            if (src != null && src.clip != null && !src.isPlaying && flying.go.activeInHierarchy) src.Play();
        }
    }
}
