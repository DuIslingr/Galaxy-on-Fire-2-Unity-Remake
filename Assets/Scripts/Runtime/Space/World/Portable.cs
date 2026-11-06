// Portable.cs
// Remake (2026-11-06, for mods): a thing the player's ship carries to a socket (World.EnergySocket), after EVERSPACE 2's
// portable objects (BP_Portable_Component: the action key grabs it within reach, it hangs behind the ship in a magnetic
// field, the action key lets it go): an energy sphere from a dispenser (BP_Portable_EnergyOrb, gone after the dispenser's
// EnergyOrbLifetime 40 s unless socketed) or an energy coil lying in the orbit (BP_Portable_EnergyCoil, stays). Grabbing and
// letting go: World.CarryPuzzle. Let go it keeps its momentum (PortableComponent::Detach bKeepMomentum); thrown (Detach bFling:
// bAllowFlinging, FlingStrength 20 000 cm/s, BP_Portable_EnergyCoil's and the common value) it flies on ahead of the ship at
// FlingMs more, slowing with the rift mines' damping (UE linear damping 0.2). Drawn as the rift's spheres (RiftHazards.Sphere): a white-blue glowing sphere, an orange coil.

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.World
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public class Portable : MonoBehaviour
    {
        /// <summary>BP_EnergyOrb_Dispenser's EnergyOrbLifetime (s); how far behind the ship it hangs (m); its size (m).</summary>
        public const float OrbLifeS = 40f, CarryBehindM = 30f, RadiusM = 4f, FlingMs = 200f * 3.6f, Damping = 0.2f;
        static readonly Color OrbColor = new Color(1.6f, 2.2f, 3f, 0.9f), CoilColor = new Color(3f, 1.4f, 0.3f, 0.9f);

        public static readonly List<Portable> All = new List<Portable>();
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() => All.Clear();

        public bool Coil { get; private set; }
        /// <summary>The ship carrying it, null = loose.</summary>
        public Transform Carrier { get; private set; }
        /// <summary>In a socket for good.</summary>
        public bool Socketed { get; private set; }
        public OrbDispenser From { get; private set; }
        float lifeS = -1f;
        Target marker;
        /// <summary>Its motion (m/s): followed while carried, its own while loose.</summary>
        public Vector3 Velocity { get; private set; }

        void OnEnable() => All.Add(this);
        void OnDisable() => All.Remove(this);
        void OnDestroy() { if (marker != null) Target.RadarObjects.Remove(marker); }

        public static Portable Make(Transform parent, Vector3 at, bool coil, OrbDispenser from = null)
        {
            var go = RiftHazards.Sphere(parent, at, coil ? RadiusM * 0.8f : RadiusM, coil ? CoilColor : OrbColor, coil ? "Energy coil" : "Energy sphere");
            if (coil) go.transform.localScale = new Vector3(RadiusM * 1.2f, RadiusM * 2.4f, RadiusM * 1.2f);
            var p = go.AddComponent<Portable>();
            p.Coil = coil;
            p.From = from;
            if (!coil) p.lifeS = OrbLifeS;
            var t = p.marker = go.AddComponent<Target>();
            t.hp = t.maxHp = 1f;
            t.invulnerable = true;
            t.radius = RadiusM;
            t.displayName = coil ? Localization.Extra("energyCoil", "Energy coil") : Localization.Extra("energySphere", "Energy sphere");
            t.plateNameOnly = t.plateNoIcon = true;
            Target.RadarObjects.Add(t);
            return p;
        }

        public void Grab(Transform ship) { if (!Socketed) Carrier = ship; }

        /// <summary>Let go with its momentum; 'fling' throws it on along the ship's nose at FlingMs more.</summary>
        public void Release(bool fling = false)
        {
            if (Carrier == null) return;
            Velocity = Thrown(Velocity, Carrier.forward, fling);
            Carrier = null;
        }

        /// <summary>Its velocity once let go: kept, plus FlingMs along 'forward' when flung.</summary>
        public static Vector3 Thrown(Vector3 velocity, Vector3 forward, bool fling) => fling ? velocity + forward.normalized * FlingMs : velocity;

        /// <summary>Into 'socket' for good: it sits there, off the radar.</summary>
        public void Seat(Transform socket)
        {
            Carrier = null;
            Socketed = true;
            Velocity = Vector3.zero;
            lifeS = -1f;
            transform.position = socket.position;
            if (marker != null) { Target.RadarObjects.Remove(marker); Destroy(marker); marker = null; }
        }

        /// <summary>Where a carried one hangs: CarryBehindM behind the ship and a little below.</summary>
        public static Vector3 CarryPoint(Vector3 shipPos, Vector3 forward, Vector3 up) => shipPos - forward * CarryBehindM - up * (CarryBehindM * 0.2f);

        void Update()
        {
            float dt = Time.deltaTime;
            if (lifeS >= 0f && (lifeS -= dt) <= 0f)
            {
                Explosion.Spawn(transform.position, 0.3f, false);   // (the sphere fizzles out)
                Destroy(gameObject);
                return;
            }
            if (Socketed || dt <= 0f) return;
            if (Carrier == null)
            {
                transform.position += Velocity * dt;
                Velocity *= Mathf.Exp(-Damping * dt);
                return;
            }
            var was = transform.position;
            var to = CarryPoint(Carrier.position, Carrier.forward, Carrier.up);
            transform.position = Vector3.Lerp(was, to, 1f - Mathf.Exp(-4f * dt));   // (the magnetic field's pull)
            Velocity = (transform.position - was) / dt;
        }
    }
}
