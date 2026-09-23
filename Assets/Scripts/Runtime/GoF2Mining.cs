// GoF2Mining.cs
// Asteroid mining on the player's ship, from lock-on to ore in the cargo hold (Reference/research/mining.md):
//   Radar::draw 0x1554fc          lock: keep an asteroid inside a +-w/16 box around the crosshair for (scanner attr 29,
//                                 else 8000) - 200 ms; nearest in 3D wins; sound 26; no drill -> 541 "No drill installed."
//   MGame::OnTouchBegin 0x1a838c  action while locked: cargo full -> 322, else "Target: Asteroid" + sound 28 and the
//                                 autopilot takes the ship in; again = cancel ("Autopilot Off", sound 29); while mining = stop
//   PlayerEgo::approachAsteroid   steer dir += (to - dir) * dt * min(H + 2.7, 4) / 4096 at full throttle; the last 2000
//                                 units before scale * 2500: exhaust off, sound 2, the chase camera freezes, the model
//                                 pitches up (cumulative); then stop, asteroid spin off, a short settle, the minigame
//   MiningGame (GoF2MiningGame)   drill loop sound 1, sound 3 while off target
//   PlayerEgo::stopMining 0xade94 ore (capped to free cargo, hardcore halves an unfinished run) and on a full class-A run a
//                                 core (ore + 11) into the cargo, "12t Gold" messages, then the asteroid explodes (no crate)
// The HUD shows the lock ring, the ore plate, the minigame and the prompt; it forwards touch input and the action button.
// Not yet: stats / medals (Geologist, Miner, Ore Athlete), the Ultrascan class-A markers, the mining plant.

using System;
using GoF2Remake.Data;
using GoF2Remake.Visuals;
using UnityEngine;
using UnityEngine.InputSystem;

namespace GoF2Remake.Flight
{
    public class GoF2Mining : MonoBehaviour
    {
        public enum Phase { Idle, Approaching, Landing, Docked, Mining }

        const float M = 0.05f;
        const float CrosshairDistanceMeters = 22000f * M;   // same aim point as the HUD crosshair
        const float BaseSpeed = 2f;                          // units per ms at full throttle

        public Phase State { get; private set; } = Phase.Idle;
        public GoF2Target Candidate { get; private set; }
        public GoF2Target Locked { get; private set; }
        public GoF2Target Target { get; private set; }
        public GoF2MiningGame Game { get; private set; }
        /// <summary>Lock ring frame 0..23 (image 0x456), -1 = not shown.</summary>
        public int LockFrame { get; private set; } = -1;
        public bool HasDrill => drill != null;
        public int FreeCargo => GoF2Shop.FreeCargo(db);
        /// <summary>A HUD message (text id 546, 541, 322, "12t Gold" ...).</summary>
        public event Action<string> Message;

        /// <summary>What the action button does right now (null = nothing to do with mining).</summary>
        public string PromptText =>
            State == Phase.Mining ? GoF2Localization.Extra("hudMiningStop", "STOP MINING")
            : State != Phase.Idle ? GoF2Localization.Extra("hudMiningAbort", "ABORT")
            : Locked != null ? GoF2Localization.Extra("hudMine", "MINE") : null;

        GoF2Database db;
        GoF2ShipController ship;
        GoF2WeaponSystem weapons;
        GoF2ChaseCamera chase;
        GoF2CombatAudio sounds;
        AudioSource sfx, drillLoop;
        ItemData drill;
        int lockTimeMs = 8000;
        float lockTimer;
        bool noDrillShown, wasLocked;
        float dockDistance, pitchAccumulator;
        bool ready;
        Vector3 capturedUp;
        Vector2 touchInput;

        public void Setup(GoF2Database database, GoF2ShipController controller, GoF2WeaponSystem weaponSystem, GoF2ChaseCamera chaseCamera)
        {
            db = database;
            ship = controller;
            weapons = weaponSystem;
            chase = chaseCamera;
            sounds = GoF2CombatAudio.Load();
            drill = GoF2Shop.FirstMounted(db, 19);
            var scanner = GoF2Shop.FirstMounted(db, 17);
            lockTimeMs = scanner != null && scanner.HasAttr(29) ? scanner.Attr(29) : 8000;   // Radar::Radar
            sfx = gameObject.AddComponent<AudioSource>();
            sfx.playOnAwake = false;
            drillLoop = gameObject.AddComponent<AudioSource>();
            drillLoop.playOnAwake = false;
            drillLoop.loop = true;
            drillLoop.clip = sounds != null ? sounds.miningDrill : null;
        }

        /// <summary>Touch stick for the drill (+y = up on the stick).</summary>
        public void SetTouchInput(Vector2 v) => touchInput = v;

        // ---- per frame ---------------------------------------------------------------------------------------

        void Update()
        {
            if (db == null) return;
            float dtMs = Time.deltaTime * 1000f;
            switch (State)
            {
                case Phase.Idle: UpdateLock(dtMs); break;
                case Phase.Approaching:
                case Phase.Landing:
                case Phase.Docked:
                    if (Target == null || !Target.Alive) { Say(GoF2Localization.Get(571) + " " + GoF2Localization.Get(39)); Undock(); break; }
                    Approach(dtMs);
                    break;
                case Phase.Mining: UpdateMining(dtMs); break;
            }
        }

        /// <summary>Radar::draw, asteroid part: box around the crosshair, nearest in 3D, lock timer.</summary>
        void UpdateLock(float dtMs)
        {
            var cam = Camera.main;
            GoF2Target best = null;
            if (cam != null)
            {
                var c = cam.WorldToScreenPoint(ship.transform.position + ship.transform.forward * CrosshairDistanceMeters);
                float r = Screen.width / 16f, bestDist = float.MaxValue;
                if (c.z > 0f)
                    foreach (var t in GoF2Target.All)
                    {
                        if (t == null || !t.Alive || t.oreItem < 0) continue;
                        var p = cam.WorldToScreenPoint(t.transform.position);
                        if (p.z <= 0f || p.x < 0f || p.y < 0f || p.x > Screen.width || p.y > Screen.height) continue;
                        if (Mathf.Abs(p.x - c.x) >= r || Mathf.Abs(p.y - c.y) >= r) continue;
                        float d = (t.transform.position - ship.transform.position).sqrMagnitude;
                        if (d < bestDist) { bestDist = d; best = t; }
                    }
            }
            if (best != Candidate) { Candidate = best; lockTimer = 0f; noDrillShown = false; }
            if (Candidate == null) { Locked = null; LockFrame = -1; wasLocked = false; return; }

            lockTimer += dtMs;
            LockFrame = lockTimer > 500f ? Mathf.Min(23, (int)(23f * (lockTimer - 500f) / Mathf.Max(1f, lockTimeMs - 500f))) : -1;
            if (lockTimer > lockTimeMs - 200f)
            {
                if (drill == null)
                {
                    if (!noDrillShown) Say(GoF2Localization.Get(541));   // No drill installed.
                    noDrillShown = true;
                    Locked = null;
                }
                else
                {
                    Locked = Candidate;
                    LockFrame = 23;
                    if (!wasLocked) Play(sounds?.targetLock);
                }
            }
            else Locked = null;
            wasLocked = Locked != null;
        }

        /// <summary>The HUD action button / Enter / controller X (the original's fire button while locked or mining).</summary>
        public void Interact()
        {
            switch (State)
            {
                case Phase.Idle:
                    if (Locked == null) return;
                    if (GoF2Shop.FreeCargo(db) < 1) { Say(GoF2Localization.Get(322)); return; }   // Cargo hold is full.
                    Say(GoF2Localization.Get(546) + ": " + GoF2Localization.Get(550));            // Target: Asteroid
                    Play(sounds?.autopilotOn);
                    StartApproach(Locked);
                    break;
                case Phase.Mining:
                    FinishMining();   // stop early: keeps the ore so far
                    break;
                default:
                    Say(GoF2Localization.Get(571) + " " + GoF2Localization.Get(39));              // Autopilot Off
                    Play(sounds?.autopilotOff);
                    Undock();
                    break;
            }
        }

        // ---- approach (PlayerEgo::dockToAsteroid 0xab9b4 / approachAsteroid 0xaba90) --------------------------

        void StartApproach(GoF2Target asteroid)
        {
            Target = asteroid;
            State = Phase.Approaching;
            dockDistance = asteroid.scale * 2500f;
            pitchAccumulator = 0f;
            ready = false;
            ship.externalControl = true;   // player steering off
            ship.SetThrottle(1f);          // MGame::OnUpdate forces full throttle while docking
            if (weapons != null) weapons.Blocked = true;
        }

        void Approach(float dtMs)
        {
            var tr = ship.transform;
            Vector3 toTarget = Target.transform.position - tr.position;
            float d = toTarget.magnitude / M;
            if (d >= dockDistance)
            {
                // moveToPosition 0xa8720: turn = min(handling + 2.7, 4), dir += (to - dir) * dt * turn / 4096.
                float turn = Mathf.Min(ship.stats.handling / 100f + 2.7f, 4f);
                var dir = (tr.forward + (toTarget.normalized - tr.forward) * (dtMs * turn / 4096f)).normalized;
                tr.rotation = Quaternion.LookRotation(dir, Vector3.up);
                float step = Mathf.Min(dtMs * BaseSpeed, d - dockDistance + 1f) * M;
                tr.position += tr.forward * step;
                ship.ExternalSpeedMetersPerSecond = Time.deltaTime > 0f ? step / Time.deltaTime : 0f;
            }
            else ship.ExternalSpeedMetersPerSecond = 0f;

            if (State == Phase.Approaching && d < dockDistance + 2000f) BeginLanding();

            if (State == Phase.Landing)
            {
                // Pitch the model up until its nose is within 0.2 rad of its old up vector (cumulative, like the original,
                // normalised to its ~20 ms frames).
                var model = ship.visualModel;
                if (model != null && Vector3.Angle(model.forward, capturedUp) * Mathf.Deg2Rad > 0.2f && pitchAccumulator > -1024f)
                {
                    pitchAccumulator -= 0.35f * dtMs;
                    model.localRotation *= Quaternion.Euler(pitchAccumulator / 65536f * 360f * (dtMs / 20f), 0f, 0f);
                }
                else ready = true;
                if (ready && d < dockDistance)
                {
                    State = Phase.Docked;
                    var spin = Target.GetComponent<GoF2Spin>();
                    if (spin != null) spin.enabled = false;
                }
            }
            else if (State == Phase.Docked)
            {
                if (pitchAccumulator > -1024f) { pitchAccumulator -= dtMs / 2f; return; }   // settle
                StartMinigame();
            }
        }

        void BeginLanding()
        {
            State = Phase.Landing;
            SetExhaust(false);
            Play(sounds?.miningLanding);
            if (chase != null) chase.enabled = false;   // TargetFollowCamera::setActive(false): the camera stays put
            capturedUp = ship.visualModel != null ? ship.visualModel.up : ship.transform.up;
        }

        void StartMinigame()
        {
            Game = new GoF2MiningGame(Target.quality, Target.oreItem, drill.Attr(32), drill.Attr(33), GoF2Session.CampaignMission <= 4);
            Game.InsideChanged += inside =>
            {
                if (inside) { if (!drillLoop.isPlaying) drillLoop.Play(); }
                else { drillLoop.Stop(); Play(sounds?.miningDrillBroken); }
            };
            Target.radius = 0f;   // Player radius 0: can't be hit or collided while mined
            State = Phase.Mining;
            drillLoop.volume = GoF2Settings.SfxVolume;
            drillLoop.Play();
        }

        // ---- minigame -------------------------------------------------------------------------------------------

        void UpdateMining(float dtMs)
        {
            if (Target == null || !Target.Alive) { Say(GoF2Localization.Get(539)); FinishMining(); return; }   // asteroid gone
            Game.SetInput(ReadDrillInput());
            // FMOD parameter 0 = (LAYER_SPEEDS[layer] - 5) / 33 * 3: the remake raises the pitch (mapping unknown).
            drillLoop.pitch = 1f + (GoF2MiningGame.LayerSpeeds[Game.Layer] - 5f) / 33f * 0.3f;
            if (Game.Update(dtMs)) return;
            if (Game.Lost) Say(GoF2Localization.Get(539));   // Mining failed.
            FinishMining();
        }

        /// <summary>Stick, WASD / arrows or the controller's left stick; +y = down on screen for the minigame.</summary>
        Vector2 ReadDrillInput()
        {
            var v = new Vector2(touchInput.x, -touchInput.y);
            var kb = Keyboard.current;
            if (kb != null)
            {
                var k = new Vector2((kb.dKey.isPressed || kb.rightArrowKey.isPressed ? 1 : 0) - (kb.aKey.isPressed || kb.leftArrowKey.isPressed ? 1 : 0),
                                    (kb.sKey.isPressed || kb.downArrowKey.isPressed ? 1 : 0) - (kb.wKey.isPressed || kb.upArrowKey.isPressed ? 1 : 0));
                if (k.sqrMagnitude > v.sqrMagnitude) v = k;
            }
            var pad = Gamepad.current;
            if (pad != null)
            {
                var s = pad.leftStick.ReadValue();
                if (s.sqrMagnitude > 0.02f && s.sqrMagnitude > v.sqrMagnitude) v = new Vector2(s.x, -s.y);
            }
            return Vector2.ClampMagnitude(v, 1f);
        }

        /// <summary>PlayerEgo::stopMining: ore (and a core) into the cargo, messages, the asteroid explodes, undock.</summary>
        void FinishMining()
        {
            if (Game != null && Target != null)
            {
                int ore = Target.oreItem, core = Target.CoreItem;
                int free = GoF2Shop.FreeCargo(db);
                int n = Game.Lost ? 0 : Game.OreAmount;
                if (GoF2Session.IsExtreme && !Game.Won) n /= 2;
                n = Mathf.Min(n, free);
                if (free < 1) Say(GoF2Localization.Get(322));
                else
                {
                    if (Game.GotCore)
                    {
                        GoF2Shop.AddToCargo(core, 1);
                        Say($"1t {GoF2Localization.Get(1274 + core)}");
                        n = Mathf.Min(n, GoF2Shop.FreeCargo(db));
                    }
                    if (n > 0)
                    {
                        GoF2Shop.AddToCargo(ore, n);
                        Say($"{n}t {GoF2Localization.Get(1274 + ore)}");
                    }
                    if (GoF2Shop.FreeCargo(db) <= 0) Say(GoF2Localization.Get(322));
                }
                Target.Explode();   // HP -1: the asteroid's explosion and sound 21, no crate
            }
            Undock();
        }

        /// <summary>dockToAsteroid(null): spin back on, camera and controls back, the model upright, sounds off.</summary>
        void Undock()
        {
            if (Target != null && Target.Alive)
            {
                var spin = Target.GetComponent<GoF2Spin>();
                if (spin != null) spin.enabled = true;
            }
            State = Phase.Idle;
            Target = null;
            Game = null;
            Locked = Candidate = null;
            LockFrame = -1;
            lockTimer = 0f;
            ship.externalControl = false;
            ship.ExternalSpeedMetersPerSecond = 0f;
            if (ship.visualModel != null) ship.visualModel.localRotation = Quaternion.identity;
            if (weapons != null) weapons.Blocked = false;
            if (chase != null) chase.enabled = true;   // damped catch-up from where it stopped
            SetExhaust(true);
            drillLoop.Stop();
        }

        void SetExhaust(bool on)
        {
            var asm = ship.visualModel != null ? ship.visualModel.GetComponent<GoF2AssembledObject>() : null;
            if (asm?.playerVariantParts != null) foreach (var p in asm.playerVariantParts) if (p != null) p.SetActive(on);
        }

        void Say(string text) => Message?.Invoke(text);

        void Play(AudioClip clip)
        {
            if (clip != null) sfx.PlayOneShot(clip, GoF2Settings.SfxVolume);
        }
    }
}
