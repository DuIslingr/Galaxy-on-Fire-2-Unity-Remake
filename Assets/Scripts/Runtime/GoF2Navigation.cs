// GoF2Navigation.cs
// Target locks on the station, the jumpgate and the other stations' planets, the autopilot, the planet jump and
// fast-forward (Reference/research/autopilot_travel.md):
//   Radar::draw 0x1554fc          landmarks (station, jumpgate): on screen, within +-w/6 of the centre and +-w/16 of the
//                                 crosshair; planets (not the current station's own): +-w/32 of the crosshair, also during
//                                 the autopilot. Lock after the scanner's lock time (attr 29, 8000 ms without), sound 26.
//                                 Landmarks beat planets, planets beat asteroids (GoF2Mining asks BlocksAsteroidLock).
//   MGame::OnTouchBegin 0x1a838c  action: landmark locked -> autopilot ("Target: Var Hastra Station", sound 28);
//                                 planet locked -> planet jump, no confirmation
//   PlayerEgo::update / setAutoPilot  steering by moveToPosition (GoF2ShipController.autopilotTarget), throttle reset to
//                                 100 % once, stick ignored, throttle / boost / guns still work; the autopilot button (here
//                                 the action prompt) turns it off ("Autopilot Off", sound 29)
//   MGame::dockEvent 0x1afebc     autopilot to the station docks within 16000 units (GoF2SpaceLevel)
//   PlayerEgo::dockToPlanet       sound 5, the camera freezes and looks at the ship, straight on at 8 u/ms, after 3000 ms
//                                 the level reloads in the target station's orbit (arrival: GoF2SpaceLevel)
//   MGame+0x160 fast-forward      held button: the whole game runs 5x (Time.timeScale) while the autopilot or an asteroid
//                                 approach runs and the target is >= 20000 units away; releasing, arriving or the
//                                 autopilot ending stops it (no hostile ships exist yet)
//   Hud::initHudMenu(3) 0x18e080  the autopilot menu (autopilot button while the autopilot is off; the game pauses):
//                                 549 "Asteroid field" (not in the alien orbit; flies to the field centre and, like the
//                                 original, keeps going until switched off), "<name> Station" (not in empty orbits),
//                                 547 "Jumpgate" (gate orbit only); each "Target: X" + sound 28 (MGame::OnTouchEnd)
// Not yet: menu entries for route waypoints, a programmed destination and docking targets, the jumpgate's star map and
// inter-system travel (reaching the gate turns the autopilot off with "Not available."), mission restrictions.

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.World;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace GoF2Remake.Flight
{
    public class GoF2Navigation : MonoBehaviour
    {
        public enum Kind { Station, Jumpgate, Planet, AsteroidField }

        public class Target
        {
            public Kind kind;
            public Transform transform;      // null for fixed positions
            public Vector3 fixedPosition;
            public int station = -1;         // planets: the station it leads to
            public string name;
            public Vector3 Position => transform != null ? transform.position : fixedPosition;
        }

        const float M = 0.05f;
        const float CrosshairDistanceMeters = 22000f * M;
        public const float AboutToReachUnits = 20000f;   // PlayerEgo+0x330
        const float FastForwardScale = 5f;
        const float PlanetJumpMs = 3000f, PlanetJumpSpeed = 8f;   // dockToPlanet: 8 u/ms for 3 s

        public string spaceScene = "Space";

        public readonly List<Target> Targets = new List<Target>();
        /// <summary>Level::getAsteroidWaypoint: the field centre (menu only, never locked), null in the alien orbit.</summary>
        public Target AsteroidField { get; private set; }
        /// <summary>The autopilot menu is open: the game is paused.</summary>
        public bool MenuOpen { get; private set; }
        public Target Candidate { get; private set; }
        public Target Locked { get; private set; }
        public float LockTimer { get; private set; }
        public int LockTimeMs { get; private set; } = 8000;
        public Target AutopilotTarget { get; private set; }
        public bool Autopilot => AutopilotTarget != null;
        public bool GoingToStation => AutopilotTarget?.kind == Kind.Station;
        public bool Jumping { get; private set; }
        public bool FastForward { get; private set; }
        /// <summary>Lock ring frame 0..23 (no 500 ms delay for landmarks and planets), -1 = none.</summary>
        public int LockFrame => Candidate == null ? -1 : Locked != null ? 23 : Mathf.Min(23, (int)(23f * LockTimer / Mathf.Max(1, LockTimeMs)));
        /// <summary>Radar: the asteroid lock needs no landmark / planet candidate or lock and no autopilot.</summary>
        public bool BlocksAsteroidLock => Candidate != null || Locked != null || Autopilot || Jumping;
        public bool AboutToReach { get; private set; }
        public event Action<string> Message;

        /// <summary>The action prompt text (null = nothing to do here).</summary>
        public string PromptText =>
            Jumping ? null
            : Autopilot ? GoF2Localization.Extra("hudAutopilotOff", "AUTOPILOT OFF")
            : Locked == null ? null
            : Locked.kind == Kind.Planet ? GoF2Localization.Extra("hudJump", "JUMP")
            : GoF2Localization.Extra("hudAutopilot", "AUTOPILOT");

        GoF2ShipController ship;
        GoF2Mining mining;
        GoF2ChaseCamera chase;
        GoF2WeaponSystem weapons;
        GoF2CombatAudio sounds;
        AudioSource sfx;
        bool wasLocked, fastForwardHeld;
        float jumpMs, gateRadiusUnits = GoF2OrbitLayout.GateRadius;
        Target jumpTarget;

        public void Setup(GoF2Database db, GoF2OrbitLayout layout, GoF2Backdrop backdrop, GoF2ShipController controller,
                          GoF2Mining miningSystem, GoF2ChaseCamera chaseCamera, GoF2WeaponSystem weaponSystem)
        {
            ship = controller;
            mining = miningSystem;
            chase = chaseCamera;
            weapons = weaponSystem;
            sounds = GoF2CombatAudio.Load();
            sfx = gameObject.AddComponent<AudioSource>();
            sfx.playOnAwake = false;
            var scanner = GoF2Shop.FirstMounted(db, 17);
            LockTimeMs = scanner != null && scanner.HasAttr(29) ? scanner.Attr(29) : 8000;
            gateRadiusUnits = layout.JumpgateRadius;

            // Level::getLandmarks: [0] station (none in empty orbits), [1] the visible jumpgate (gate orbit only).
            var st = db.Stations.Find(s => s.index == layout.stationIndex);
            if (layout.hasStation && st != null)
                Targets.Add(new Target { kind = Kind.Station, fixedPosition = Vector3.zero, station = st.index,
                                         name = st.index == 101 ? st.name : $"{st.name} {GoF2Localization.Get(136)}" });
            if (layout.hasJumpgate)
                Targets.Add(new Target { kind = Kind.Jumpgate, fixedPosition = GoF2OrbitLayout.ToUnity(layout.jumpgate), name = GoF2Localization.Get(547) });
            if (layout.systemIndex >= 0)
                AsteroidField = new Target { kind = Kind.AsteroidField, fixedPosition = GoF2OrbitLayout.ToUnity(layout.asteroidCentre), name = GoF2Localization.Get(549) };
            // StarSystem::getPlanetTargets: the other stations' planets (the orbit planet is the current station's own).
            if (backdrop != null)
                foreach (var (station, t, orbit) in backdrop.PlanetTargets)
                    if (!orbit && station != layout.stationIndex)
                        Targets.Add(new Target { kind = Kind.Planet, transform = t, station = station,
                                                 name = db.Stations.Find(s => s.index == station)?.name ?? "" });
        }

        void OnDisable()
        {
            MenuOpen = false;
            SetFastForward(false);
            ApplyTimeScale();
        }

        // ---- autopilot menu (Hud::initHudMenu(3)) ------------------------------------------------------------

        /// <summary>The menu's entries in the original's order: asteroid field, station, jumpgate.</summary>
        public List<Target> MenuEntries()
        {
            var list = new List<Target>();
            if (AsteroidField != null) list.Add(AsteroidField);
            var station = Targets.Find(t => t.kind == Kind.Station);
            if (station != null) list.Add(station);
            var gate = Targets.Find(t => t.kind == Kind.Jumpgate);
            if (gate != null) list.Add(gate);
            return list;
        }

        /// <summary>MGame::OnTouchEnd, autopilot button: only while nothing else flies the ship; pauses the game.</summary>
        public bool CanOpenMenu => !Autopilot && !Jumping && (mining == null || mining.State == GoF2Mining.Phase.Idle);

        public void OpenMenu()
        {
            if (!CanOpenMenu) return;
            MenuOpen = true;
            if (weapons != null) weapons.Blocked = true;
            ApplyTimeScale();
        }

        public void CloseMenu()
        {
            if (!MenuOpen) return;
            MenuOpen = false;
            if (weapons != null) weapons.Blocked = false;
            ApplyTimeScale();
        }

        /// <summary>A menu entry: "Target: X" + sound 28, autopilot on, the menu closes and the game resumes.</summary>
        public void ChooseMenuEntry(Target target)
        {
            CloseMenu();
            if (target == null) return;
            Say($"{GoF2Localization.Get(546)}: {target.name}");
            Play(sounds?.autopilotOn);
            SetAutopilot(target);
        }

        /// <summary>Touch button / key held for fast-forward (checked every frame).</summary>
        public void SetFastForwardHeld(bool held) => fastForwardHeld = held;

        /// <summary>MGame::OnTouchBegin key 0x100: allowed while the autopilot or an asteroid approach runs, not within
        /// 20000 units of the target (and no hostile ships, none exist yet).</summary>
        public bool CanFastForward
        {
            get
            {
                if (Jumping) return false;
                if (Autopilot) return !AboutToReach;
                if (mining != null && mining.Target != null && mining.State == GoF2Mining.Phase.Approaching)
                    return (mining.Target.transform.position - ship.transform.position).magnitude / M >= AboutToReachUnits;
                return false;
            }
        }

        // ---- per frame -----------------------------------------------------------------------------------------

        void Update()
        {
            if (ship == null) return;
            float dtMs = Time.deltaTime * 1000f;
            if (Jumping) { UpdateJump(dtMs); return; }
            if (Autopilot)
            {
                AboutToReach = (AutopilotTarget.Position - ship.transform.position).magnitude / M < AboutToReachUnits;
                if (AutopilotTarget.kind == Kind.Jumpgate && (AutopilotTarget.Position - ship.transform.position).magnitude < gateRadiusUnits * M)
                {
                    // Level::collideStream -> dockToStream: the star map / inter-system travel doesn't exist yet.
                    Say(GoF2Localization.Get(528));
                    SetAutopilot(null);
                }
            }
            if (MenuOpen) return;   // paused
            UpdateLock(dtMs);
            SetFastForward(fastForwardHeld && CanFastForward);
        }

        void LateUpdate()
        {
            // dockToPlanet: TargetFollowCamera look-at mode, the camera stays put and keeps looking at the ship.
            if (!Jumping) return;
            var cam = Camera.main;
            if (cam != null) cam.transform.rotation = Quaternion.LookRotation(ship.transform.position - cam.transform.position, ship.transform.up);
        }

        /// <summary>Radar::draw, landmark and planet blocks.</summary>
        void UpdateLock(float dtMs)
        {
            var cam = Camera.main;
            Target best = null;
            bool miningBusy = mining != null && (mining.State != GoF2Mining.Phase.Idle || mining.Locked != null);
            if (cam != null && !miningBusy)
            {
                var c = cam.WorldToScreenPoint(ship.transform.position + ship.transform.forward * CrosshairDistanceMeters);
                float w = Screen.width, h = Screen.height;
                float box = w / 16f, centre = w / 6f, planetBox = w / 32f;
                if (c.z > 0f)
                {
                    // Landmarks first (not during the autopilot), then planets (also during the autopilot).
                    foreach (var t in Targets)
                    {
                        if (t.kind == Kind.Planet || Autopilot) continue;
                        var p = cam.WorldToScreenPoint(t.Position);
                        if (p.z <= 0f || p.x < 0f || p.y < 0f || p.x > w || p.y > h) continue;
                        if (Mathf.Abs(p.x - w / 2f) >= centre || Mathf.Abs(p.y - h / 2f) >= centre) continue;
                        if (Mathf.Abs(p.x - c.x) < box && Mathf.Abs(p.y - c.y) < box) { best = t; break; }
                    }
                    if (best == null)
                        foreach (var t in Targets)
                        {
                            if (t.kind != Kind.Planet || t == AutopilotTarget) continue;
                            var p = cam.WorldToScreenPoint(t.Position);
                            if (p.z <= 0f || p.x < 0f || p.y < 0f || p.x > w || p.y > h) continue;
                            if (Mathf.Abs(p.x - c.x) < planetBox && Mathf.Abs(p.y - c.y) < planetBox) { best = t; break; }
                        }
                }
            }
            if (best != Candidate) { Candidate = best; LockTimer = 0f; }
            if (Candidate == null) { Locked = null; wasLocked = false; return; }
            LockTimer += dtMs;
            Locked = LockTimer > LockTimeMs ? Candidate : null;   // strict >, no -200 ms here
            if (Locked != null && !wasLocked) Play(sounds?.targetLock);
            wasLocked = Locked != null;
        }

        /// <summary>The action prompt / Enter / controller X.</summary>
        public void Interact()
        {
            if (Jumping) return;
            if (Autopilot)
            {
                Say(GoF2Localization.Get(571) + " " + GoF2Localization.Get(39));   // Autopilot Off
                Play(sounds?.autopilotOff);
                SetAutopilot(null);
                return;
            }
            if (Locked == null) return;
            if (Locked.kind == Kind.Planet) StartJump(Locked);
            else
            {
                Say($"{GoF2Localization.Get(546)}: {Locked.name}");                 // Target: Var Hastra Station
                Play(sounds?.autopilotOn);
                SetAutopilot(Locked);
            }
        }

        /// <summary>PlayerEgo::setAutoPilot: throttle to 100 % when turning on; turning off clears the locks.</summary>
        public void SetAutopilot(Target target)
        {
            AutopilotTarget = target;
            ship.autopilotTarget = target != null ? () => target.Position : null;
            if (target != null) ship.SetThrottle(1f);
            Locked = Candidate = null;
            LockTimer = 0f;
            AboutToReach = false;
        }

        // ---- planet jump (PlayerEgo::dockToPlanet 0xadd20) ----------------------------------------------------

        void StartJump(Target planet)
        {
            SetAutopilot(null);
            jumpTarget = planet;
            Jumping = true;
            jumpMs = 0f;
            ship.externalControl = true;
            if (weapons != null) weapons.Blocked = true;
            if (chase != null) chase.enabled = false;
            Play(sounds?.jumpToPlanet);
        }

        void UpdateJump(float dtMs)
        {
            // Straight on along the current heading, no steering, 8 u/ms regardless of the throttle.
            float step = dtMs * PlanetJumpSpeed * M;
            ship.transform.position += ship.transform.forward * step;
            ship.ExternalSpeedMetersPerSecond = Time.deltaTime > 0f ? step / Time.deltaTime : 0f;
            jumpMs += dtMs;
            if (jumpMs <= PlanetJumpMs) return;
            // MGame::OnUpdate: departStation(planet's station), stream-out arrival, reload the level in that orbit.
            weapons?.StoreAmmo();
            GoF2Session.PreviousStationIndex = GoF2Session.StationIndex;
            GoF2Session.StationIndex = jumpTarget.station;
            GoF2Session.ArrivedByTravel = true;
            GoF2Session.LaunchedFromStation = false;
            SetFastForward(false);
            enabled = false;
            if (Application.CanStreamedLevelBeLoaded(spaceScene)) SceneManager.LoadScene(spaceScene);
        }

        // ---- fast-forward ------------------------------------------------------------------------------------

        void SetFastForward(bool on)
        {
            FastForward = on;
            ApplyTimeScale();
        }

        void ApplyTimeScale()
        {
            float scale = MenuOpen ? 0f : FastForward ? FastForwardScale : 1f;
            if (Time.timeScale != scale) Time.timeScale = scale;
        }

        void Say(string text) => Message?.Invoke(text);

        void Play(AudioClip clip)
        {
            if (clip != null) sfx.PlayOneShot(clip, GoF2Settings.SfxVolume);
        }

        /// <summary>Radar::calcDistance 0x15827c: M = 8 * floor(d / 128); "624m" below 1000, else "6.2km".</summary>
        public static string FormatDistance(float units)
        {
            int m = 8 * (int)(units / 128f);
            if (m < 1000) return m + "m";
            int frac = m % 1000;
            return $"{m / 1000}.{(frac >= 100 ? frac.ToString()[0] : '0')}km";
        }
    }
}
