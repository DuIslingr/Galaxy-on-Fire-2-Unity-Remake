// NpcDevices.cs
// Remake (2026-11-04, for mods, after Galaxy on Fire 3's boss devices; the GoF3 Ships importer's bosses): a Most Wanted
// criminal's devices (wanted.json "devices", Flight.NpcDeviceSpec / NpcDeviceState for when each starts), on its ship while it
// flies against the player. What each does (GoF3's boss device lore, BD_*_Lore):
//   teleport       it vanishes and comes out 'distance' from the player, outside the player's front 60 degrees, nose on
//                  them ("They teleport nearby, lined up for a devastating series of blasts"); a flash at both ends
//   frontShield,   while it runs, a hit from within 'shieldAngle' of the nose (the tail) is stopped ("blocking almost 100% of
//   backShield     all primary and secondary weapon damage. Can be defeated by attacking from a different vector")
//   energyAbsorber while it runs every hit is soaked, the hull mended by 'healPercent' of it ("It absorbs any and all weapon
//                  energy ... Then it redirects this energy into shield regeneration": GoF2's ships have no shield)
//   radarJammer    the player's radar for its time (Flight.RadarJam: no lock, no ship markers)
//   flashGrenade   thrown, it flashes 'delayMs' later: white over the player's view (Flight.ScreenFlash) for its time, as
//                  strong as the player looks at it (none from 90 degrees away)
//   mindControl    the player's wingmen turn on them for its time, each until the player hits it ("Can cause wingmen to
//                  attack their leader ... Shooting them can get them to regain their senses"; NpcShip.MindControl)
//   bombSpreader   a proximity mine behind it every 'bombEveryMs' while it runs, flung within 45 degrees (GoF3's spreadAngle;
//                  the rifts' RiftMine), each blasting the player's ship for 'damage' ("most of these devices scatter a
//                  large amount of mines")
//   mineLayer      a mine 'layBehind' its tail every 'bombEveryMs' while it runs (GoF3's boss mine layers: minesPerBurst
//                  'timeBetweenMines' apart), each chasing the player and going off near them (World.SeekerMine)
//   cloud          a cloud 'layBehind' its tail (GoF3's smart bombs' effect zones: Mudshark's nanobite fog) that slows the
//                  player's ship inside it and eats its hull (World.NpcCloud)
// The single player's game only: in multiplayer the authority runs them for its own player (the others see the teleport).

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;

namespace GoF2Remake.World
{
    public class NpcDevices : MonoBehaviour
    {
        const float M = 0.05f;
        const float TeleportFrontDeg = 60f;

        NpcShip ship;
        Traffic traffic;
        SpaceLevel level;
        readonly List<NpcDeviceState> states = new List<NpcDeviceState>();
        bool hit;

        public static NpcDevices Attach(NpcShip ship, Traffic traffic, List<NpcDeviceSpec> specs)
        {
            if (specs == null || specs.Count == 0) return null;
            var d = ship.gameObject.AddComponent<NpcDevices>();
            d.ship = ship;
            d.traffic = traffic;
            d.level = FindAnyObjectByType<SpaceLevel>();
            foreach (var s in specs) d.states.Add(new NpcDeviceState(s));
            ship.Target.Damaged += (t, dmg, byNpc) => d.hit = true;
            ship.Target.HitFilter = d.Filter;
            return d;
        }

        void Update()
        {
            if (ship == null || ship.Target == null || !ship.Target.Alive) { enabled = false; return; }
            var player = traffic != null ? traffic.Player : null;
            var view = new NpcDeviceState.View { hit = hit };
            hit = false;
            if (player != null && player.Alive && player.isActiveAndEnabled && ship.Target.hostileToPlayer && !ship.Asleep
                && ship.Current == NpcShip.State.Fly && !ship.Hp.empDisabled)
            {
                var d = player.transform.position - transform.position;
                view.playerNear = true;
                view.distance = d.magnitude / M;
                view.offNoseDeg = Vector3.Angle(transform.forward, d);
                view.playerFacingDeg = Vector3.Angle(player.transform.forward, -d);
            }
            float dt = Time.deltaTime * 1000f;
            foreach (var s in states)
            {
                if (s.Step(dt, view, Random.value, out bool flashed)) Begin(s, player);
                if (flashed && player != null && player.Alive) Flash(s, player);
                for (int i = 0; i < s.DueBombs; i++)
                    if (s.spec.kind == NpcDeviceSpec.Kind.MineLayer) SeekerMine.Lay(level, s.spec, transform.position - transform.forward * (s.spec.layBehind * M));
                    else if (s.spec.kind == NpcDeviceSpec.Kind.Cloud) NpcCloud.Lay(level, s.spec, transform.position - transform.forward * (s.spec.layBehind * M));
                    else RiftMine.Drop(level, null, transform.position, -transform.forward, s.spec.damage);
            }
        }

        void Begin(NpcDeviceState s, Target player)
        {
            string name = ship.Target.displayName ?? Standing.RaceName(ship.Race);
            switch (s.spec.kind)
            {
                case NpcDeviceSpec.Kind.Teleport: Teleport(s.spec, player); break;
                case NpcDeviceSpec.Kind.FrontShield:
                    Say(string.Format(Localization.Extra("bossFrontShield", "{0}: front shield up"), name)); break;
                case NpcDeviceSpec.Kind.BackShield:
                    Say(string.Format(Localization.Extra("bossBackShield", "{0}: back shield up"), name)); break;
                case NpcDeviceSpec.Kind.EnergyAbsorber:
                    Say(string.Format(Localization.Extra("bossEnergyAbsorber", "{0}: energy absorber on. Hold your fire!"), name)); break;
                case NpcDeviceSpec.Kind.RadarJammer:
                    RadarJam.Start(s.spec.durationMs);
                    Say(Localization.Extra("bossRadarJammer", "Radar jammed!")); break;
                case NpcDeviceSpec.Kind.FlashGrenade:
                    Say(string.Format(Localization.Extra("bossFlashGrenade", "{0} threw a flash grenade: look away!"), name)); break;
                case NpcDeviceSpec.Kind.MindControl:
                    var wingmen = traffic != null ? traffic.LivingWingmen : null;
                    if (wingmen == null || wingmen.Count == 0) break;
                    foreach (var w in wingmen) w.MindControl(s.spec.durationMs);
                    Say(string.Format(Localization.Extra("bossMindControl", "{0} took over your wingmen! Hit them to wake them up."), name)); break;
                case NpcDeviceSpec.Kind.BombSpreader:
                case NpcDeviceSpec.Kind.MineLayer:
                    Say(string.Format(Localization.Extra("bossBombSpreader", "{0} is laying mines!"), name)); break;
                case NpcDeviceSpec.Kind.Cloud:
                    Say(string.Format(Localization.Extra("bossCloud", "{0} released a cloud: keep out of it!"), name)); break;
            }
        }

        void Say(string text) => traffic?.Warn(text);

        /// <summary>Out 'distance' from the player in a direction outside their front 60 degrees, nose on them.</summary>
        void Teleport(NpcDeviceSpec spec, Target player)
        {
            if (player == null) return;
            var p = player.transform.position;
            var dir = Random.onUnitSphere;
            for (int i = 0; i < 12 && Vector3.Angle(player.transform.forward, dir) < TeleportFrontDeg; i++) dir = Random.onUnitSphere;
            if (Vector3.Angle(player.transform.forward, dir) < TeleportFrontDeg) dir = -player.transform.forward;
            var to = p + dir * (Random.Range(spec.distanceMin, spec.distanceMax) * M);
            Explosion.Spawn(transform.position, 0.4f, false);
            transform.SetPositionAndRotation(to, Quaternion.LookRotation(p - to, player.transform.up));
            Explosion.Spawn(to, 0.4f);
        }

        void Flash(NpcDeviceState s, Target player)
        {
            Explosion.Spawn(transform.position, 0.3f);
            float facing = Vector3.Angle(player.transform.forward, transform.position - player.transform.position);
            float a = s.FlashOpacity(facing);
            if (a > 0.02f) ScreenFlash.Start(a, s.spec.durationMs);
        }

        /// <summary>Target.HitFilter: the shields stop what comes at their side, the absorber soaks everything.</summary>
        float Filter(float amount, Vector3 hitVector)
        {
            if (amount <= 0f) return amount;
            foreach (var s in states)
            {
                if (!s.Active) continue;
                if (s.spec.kind == NpcDeviceSpec.Kind.EnergyAbsorber)
                {
                    var hp = ship.Hp;
                    if (hp != null && s.spec.healShare > 0f)
                    {
                        hp.hull = Mathf.Min(hp.maxHull, hp.hull + Mathf.Max(1, Mathf.RoundToInt(amount * s.spec.healShare)));
                        ship.Target.hp = hp.hull;
                    }
                    return 0f;
                }
                if (hitVector.sqrMagnitude > 1e-6f) amount *= s.ShieldPass(Vector3.Angle(transform.forward, -hitVector));
            }
            return amount;
        }
    }
}
