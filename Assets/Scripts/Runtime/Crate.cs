// Crate.cs
// A cargo container left by a destroyed ship (KIPlayer::createCrate 0xb2e2c, Reference/research/ship_combat.md 5.4):
// the race's container mesh at the explosion, drifting along a random direction at bombForce = 50..50.49 units per
// (30 fps) frame, x0.98 per frame until < 0.05, spinning slowly; gone 60 s after the death. Only a tractor beam collects it
// (CombatRadar: salvage lock, pull at 10 u/ms, captured within 400 units; the first non-empty entry). A crate stolen from
// a living (EMP-disabled) ship (KIPlayer::createCrate(0) from TractorBeam::update) carries that ship's cargo and is
// gone once captured: what is left stays aboard the ship.

using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public class Crate : MonoBehaviour
    {
        const float M = 0.05f, LifetimeMs = 60000f;

        public readonly List<ItemStack> loot = new List<ItemStack>();
        public int race;
        /// <summary>Being pulled by the tractor beam (no drift).</summary>
        public bool pulled;
        /// <summary>The living ship whose cargo this is (a steal), null for a wreck's crate.</summary>
        public World.NpcShip stolenFrom;
        /// <summary>Player+0x5d of the ship it came from (a friend: Level::stealFriendCargo) / a mission container (116 / 117).</summary>
        public bool fromFriend, missionCrate;

        /// <summary>A fixed object's crate: the 60 s start when its wreck animation ends (state 4).</summary>
        public void DelayExpiry(float ms) => ageMs -= ms;

        Vector3 drift;
        float force, ageMs;

        public bool HasLoot => loot.Exists(s => s.amount > 0);

        public void Setup(IEnumerable<ItemStack> cargo, int race)
        {
            foreach (var s in cargo) if (s.amount > 0) loot.Add(s.Clone());
            this.race = race;
            drift = new Vector3(Random.Range(0, 200) - 100, Random.Range(0, 200) - 100, Random.Range(0, 200) - 100).normalized;
            force = 50f + Random.Range(0, 50) * 0.01f;
        }

        void Update()
        {
            float dtMs = Time.deltaTime * 1000f, frames = dtMs / 33.3f;
            ageMs += dtMs;
            if (ageMs > LifetimeMs || !HasLoot) { Destroy(gameObject); return; }
            if (!pulled && force > 0.05f)
            {
                transform.position += drift * force * frames * M;
                force *= Mathf.Pow(0.98f, frames);
            }
            transform.Rotate(0f, dtMs / 2f / 65536f * 360f * frames, 0f, Space.Self);
        }
    }
}
