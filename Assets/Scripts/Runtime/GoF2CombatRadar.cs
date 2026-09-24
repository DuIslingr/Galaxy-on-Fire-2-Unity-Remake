// GoF2CombatRadar.cs
// The ship and salvage part of Radar::draw 0x1554fc (Reference/research/ship_combat.md 5.4, 7.1-7.4), on the player:
//   gate        only with a scanner (sort 17) mounted: without one no ship or crate locks at all
//   ship lock   a living NPC on screen inside the +-w/16 box around the crosshair, when nothing else is locking (no
//               autopilot, no landmark / planet / asteroid candidate); the ring fills over the scanner's attr 29 from
//               t = 0; on lock sound 26 (when the target changes). The lock is sticky: kept after the ship leaves the box
//               until it dies or another lock completes. Homing missiles fly at it (GoF2WeaponSystem.LockTarget).
//   salvage     a crate in the box: ring after 500 ms, locked after the tractor beam's attr 24 (TractorBeam::update);
//               without a tractor beam "No tractor beam." (540). The beam (projectile_068..070 / v_194) pulls the crate at
//               10 u/ms, sound 0 loops; within 400 units it is captured (sound 4): the first non-empty cargo entry, capped
//               to the free cargo (at least 1) -> "<n>t <item>" or "Cargo hold is full." (322).
// Not yet: the auto modes of AB-3 / AB-4 (attr 23), stealing cargo from EMP-disabled ships, the scanner cargo readout.

using System;
using GoF2Remake.Data;
using GoF2Remake.World;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public class GoF2CombatRadar : MonoBehaviour
    {
        const float M = 0.05f, CrosshairDistanceMeters = 22000f * M, PullSpeed = 10f, CaptureUnits = 400f, SalvageRingDelay = 500f;

        public bool HasScanner { get; private set; }
        /// <summary>The lock candidate: a GoF2Target (ship) or null.</summary>
        public GoF2Target Candidate { get; private set; }
        public GoF2Crate CrateCandidate { get; private set; }
        /// <summary>The sticky ship lock.</summary>
        public GoF2Target Locked { get; private set; }
        public GoF2Crate Salvaging { get; private set; }
        /// <summary>Lock ring frame 0..23, -1 = none.</summary>
        public int LockFrame { get; private set; } = -1;
        /// <summary>A ship or crate candidate exists (blocks the asteroid lock, GoF2Navigation.ShipLockActive).</summary>
        public bool Busy => Candidate != null || CrateCandidate != null;
        public event Action<string, int> Message;   // text, colour (0 white, 1 red, 2 green)

        GoF2Database db;
        GoF2ShipController ship;
        GoF2Navigation nav;
        GoF2Mining mining;
        GoF2WeaponSystem weapons;
        GoF2PlayerHealth health;
        GoF2Traffic traffic;
        GoF2CombatAssets assets;
        AudioSource sfx, beamLoop;
        int lockTimeMs = 8000, tractorItem = -1, tractorLockMs;
        float timer;
        bool noTractorShown;
        Transform beam;
        float beamLength = 1f;

        public void Setup(GoF2Database database, GoF2ShipController controller, GoF2Navigation navigation, GoF2Mining miningSystem,
                          GoF2WeaponSystem weaponSystem, GoF2PlayerHealth playerHealth, GoF2Traffic trafficManager)
        {
            db = database;
            ship = controller;
            nav = navigation;
            mining = miningSystem;
            weapons = weaponSystem;
            health = playerHealth;
            traffic = trafficManager;
            assets = GoF2CombatAssets.Load();
            var scanner = GoF2Shop.FirstMounted(db, 17);
            HasScanner = scanner != null;
            lockTimeMs = scanner != null && scanner.HasAttr(29) ? scanner.Attr(29) : 8000;
            var tractor = GoF2Shop.FirstMounted(db, 13);
            if (tractor != null) { tractorItem = tractor.index; tractorLockMs = tractor.Attr(24); }
            sfx = gameObject.AddComponent<AudioSource>();
            sfx.playOnAwake = false;
            beamLoop = gameObject.AddComponent<AudioSource>();
            beamLoop.playOnAwake = false;
            beamLoop.loop = true;
            beamLoop.clip = assets != null ? assets.tractorLoop : null;
            var beamPrefab = assets != null && tractorItem >= 0 ? assets.Tractor(tractorItem) : null;
            if (beamPrefab != null)
            {
                var go = Instantiate(beamPrefab);
                go.name = "Tractor beam";
                GoF2GunRig.StripForFx(go);
                beamLength = 1f;
                foreach (var mf in go.GetComponentsInChildren<MeshFilter>()) if (mf.sharedMesh != null) beamLength = Mathf.Max(beamLength, mf.sharedMesh.bounds.size.z);
                beam = go.transform;
                go.SetActive(false);
            }
        }

        void OnDestroy()
        {
            if (beam != null) Destroy(beam.gameObject);
        }

        void Update()
        {
            float dtMs = Time.deltaTime * 1000f;
            if (Locked != null && !Locked.Alive) Locked = null;
            if (weapons != null) weapons.LockTarget = Locked;
            UpdateSalvage(dtMs);
            if (!HasScanner || health == null || health.Dead || nav == null || nav.Paused || nav.MenuOpen) { Candidate = null; CrateCandidate = null; LockFrame = -1; Publish(); return; }

            bool blocked = nav.Autopilot || nav.Jumping || nav.Candidate != null || nav.Locked != null
                           || (mining != null && (mining.State != GoF2Mining.Phase.Idle || mining.Candidate != null));
            GoF2Target best = null;
            GoF2Crate bestCrate = null;
            var cam = Camera.main;
            if (!blocked && cam != null)
            {
                var c = cam.WorldToScreenPoint(transform.position + transform.forward * CrosshairDistanceMeters);
                float box = Screen.width / 16f, bestD = float.MaxValue;
                if (c.z > 0f)
                {
                    if (traffic != null)
                        foreach (var s in traffic.Ships)
                        {
                            if (s.Gone || !s.Target.Alive || s.Hidden) continue;
                            if (InBox(cam, c, box, s.transform.position, out float d) && d < bestD) { bestD = d; best = s.Target; }
                        }
                    if (best == null)
                    {
                        bestD = float.MaxValue;
                        foreach (var cr in FindObjectsByType<GoF2Crate>(FindObjectsInactive.Exclude))
                            if (cr != Salvaging && InBox(cam, c, box, cr.transform.position, out float d) && d < bestD) { bestD = d; bestCrate = cr; }
                    }
                }
            }
            if (best != Candidate || bestCrate != CrateCandidate) { Candidate = best; CrateCandidate = bestCrate; timer = 0f; noTractorShown = false; }
            LockFrame = -1;
            if (Candidate != null)
            {
                timer += dtMs;
                LockFrame = Mathf.Min(23, (int)(23f * timer / Mathf.Max(1, lockTimeMs)));
                if (timer > lockTimeMs && Locked != Candidate)
                {
                    Locked = Candidate;
                    if (assets != null && assets.targetLock != null) sfx.PlayOneShot(assets.targetLock, GoF2Settings.SfxVolume);
                }
            }
            else if (CrateCandidate != null)
            {
                timer += dtMs;
                int lt = Mathf.Max(tractorLockMs, (int)SalvageRingDelay + 1);
                if (timer > SalvageRingDelay) LockFrame = Mathf.Min(23, (int)(23f * (timer - SalvageRingDelay) / (lt - SalvageRingDelay)));
                if (timer > lt)
                {
                    if (tractorItem < 0) { if (!noTractorShown) { noTractorShown = true; Message?.Invoke(GoF2Localization.Get(540), 0); } }
                    else if (Salvaging == null) { Salvaging = CrateCandidate; Salvaging.pulled = true; if (beamLoop.clip != null) beamLoop.Play(); CrateCandidate = null; }
                }
            }
            Publish();
        }

        void Publish()
        {
            if (nav != null) nav.ShipLockActive = Busy;
        }

        static bool InBox(Camera cam, Vector3 crosshair, float box, Vector3 world, out float dist)
        {
            dist = 0f;
            var p = cam.WorldToScreenPoint(world);
            if (p.z <= 0f || p.x < 0f || p.y < 0f || p.x > Screen.width || p.y > Screen.height) return false;
            if (Mathf.Abs(p.x - crosshair.x) >= box || Mathf.Abs(p.y - crosshair.y) >= box) return false;
            dist = p.z;
            return true;
        }

        /// <summary>TractorBeam::update: pull the crate in, capture it within 400 units.</summary>
        void UpdateSalvage(float dtMs)
        {
            if (Salvaging == null)
            {
                if (beam != null && beam.gameObject.activeSelf) beam.gameObject.SetActive(false);
                if (beamLoop.isPlaying) beamLoop.Stop();
                return;
            }
            var to = transform.position - Salvaging.transform.position;
            float dist = to.magnitude;
            if (dist / M < CaptureUnits) { Capture(Salvaging); return; }
            Salvaging.transform.position += to / dist * Mathf.Min(dist, PullSpeed * dtMs * M);
            if (beam != null)
            {
                beam.gameObject.SetActive(true);
                beam.position = transform.position;
                beam.rotation = Quaternion.LookRotation(-to, transform.up);
                beam.localScale = new Vector3(1f, 1f, dist / beamLength);
            }
        }

        /// <summary>KIPlayer::captureCrate: the first non-empty entry into the cargo hold.</summary>
        void Capture(GoF2Crate crate)
        {
            Salvaging = null;
            if (beamLoop.isPlaying) beamLoop.Stop();
            if (assets != null && assets.tractorClose != null) sfx.PlayOneShot(assets.tractorClose, GoF2Settings.SfxVolume);
            var entry = crate.loot.Find(s => s.amount > 0);
            if (entry == null) { Destroy(crate.gameObject); return; }
            int free = GoF2Shop.FreeCargo(db);
            if (free <= 0) { Message?.Invoke(GoF2Localization.Get(322), 1); crate.pulled = false; return; }
            int n = Mathf.Max(1, Mathf.Min(entry.amount, free));
            GoF2Shop.AddToCargo(entry.item, n);
            entry.amount -= n;
            Message?.Invoke($"{n}t {GoF2Localization.Get(1274 + entry.item)}", 2);
            if (!crate.HasLoot) Destroy(crate.gameObject);
            else crate.pulled = false;
        }
    }
}
