// PlayerDevicesEffects.cs
// PlayerDevices, part: what each device does when fired (Flight.Device.Type), its shots, wave, beams and deflected shots.

using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public partial class PlayerDevices
    {
        const float M = Gun.MetersPerUnit;
        /// <summary>Explosion type 11 (the shock blast) at scale 1 is the shock blast's reach, 80000 units.</summary>
        const float ShockScaleUnits = 80000f;
        /// <summary>The Dia EMP Mk III (item 18): the EMP shots' gun and their look when the device has no fx of its own.</summary>
        const int EmpLookItem = 18;
        const float ShotLifetimeMs = 5000f, ShotSpeedUnits = 11.4f, DeflectLifetimeMs = 4000f, BeamShowMs = 400f;

        /// <summary>A gun the devices fire from: an EMP device's shots, or the shots the deflector turns back (one per look).</summary>
        sealed class Shot
        {
            public Entry e;
            public Gun gun;
            public GunRig rig;
            public float[] damage, emp;   // per bullet (the deflected shots carry their shooter's)
        }

        sealed class Wave
        {
            public Entry e;
            public Vector3 centre;
            public float ms;
            public readonly HashSet<Target> reached = new HashSet<Target>();
        }

        void SetupEffects()
        {
            fxRoot = new GameObject("Player device fx").transform;
            deflect = Deflect;
            var empItem = db.Item(EmpLookItem);
            foreach (var e in devices)
            {
                if ((e.rules.type != Device.Type.EmpShot && e.rules.type != Device.Type.ShieldDisruptor) || empItem == null) continue;
                float speed = e.item.HasAttr(13) ? e.item.Attr(13) : ShotSpeedUnits;
                float life = e.item.HasAttr(12) ? e.item.Attr(12) : ShotLifetimeMs;
                var s = new Shot { e = e, gun = new Gun(empItem, 0f, 1f, 2, life, speed, true) { owner = self } };
                s.rig = new GunRig(s.gun, WeaponFx.Load(e.item.index) ?? WeaponFx.Load(EmpLookItem), fxRoot, null);
                s.gun.Hit += (b, t, p) => OnShotHit(s, b, t, p);
                shots[e] = s;
            }
        }

        void DestroyEffects()
        {
            if (fxRoot != null) Destroy(fxRoot.gameObject);
            foreach (var b in beamPool) if (b != null) Destroy(b.gameObject);
        }

        /// <summary>What must hold before 'e' fires: the overcharger needs the shield it spends; a repair something to repair, the
        /// restock a selected secondary, the charger a cooldown to end (EVERSPACE 2's CanBeUsed of each consumable).</summary>
        bool CanFire(Entry e)
        {
            var hp = self.hitpoints;
            switch (e.rules.type)
            {
                case Device.Type.OverchargeArea:
                case Device.Type.OverchargeBeam:
                {
                    int cost = hp != null ? Device.OverchargeCost(hp.maxShield, e.shieldCost) : 0;
                    if (cost > 0 && hp.shield >= cost) return true;
                    Message?.Invoke(string.Format(Localization.Extra("deviceNoShield", "{0}: not enough shield"), e.name));
                    return false;
                }
                case Device.Type.HullRepair:
                    if (hp != null && hp.hull < hp.maxHull) return true;
                    Message?.Invoke(string.Format(Localization.Extra("deviceNothingToRepair", "{0}: nothing to repair"), e.name));
                    return false;
                case Device.Type.ArmorRepair:
                    if (hp != null && hp.maxArmor > 0 && hp.armor < hp.maxArmor) return true;
                    Message?.Invoke(string.Format(Localization.Extra("deviceNothingToRepair", "{0}: nothing to repair"), e.name));
                    return false;
                case Device.Type.Restock:
                    if (weapons != null && weapons.SelectedSecondary >= 0) return true;
                    Message?.Invoke(string.Format(Localization.Extra("deviceNoSecondary", "{0}: no secondary weapon selected"), e.name));
                    return false;
                case Device.Type.DeviceCharger:
                    foreach (var o in devices) if (o != e && o.rules.State == Device.Phase.Cooldown) return true;
                    Message?.Invoke(string.Format(Localization.Extra("deviceNoCooldowns", "{0}: no device is cooling down"), e.name));
                    return false;
                default:
                    return true;
            }
        }

        /// <summary>Remake: the points a repair device restores, 'percent' of the layer's maximum (rounded up, at least 1).</summary>
        public static int RepairPoints(int max, int percent) => max <= 0 ? 0 : Mathf.Max(1, Mathf.CeilToInt(max * Mathf.Clamp(percent, 0, 100) / 100f));

        // the sensor cloud: where it was dropped and its reach (Unity metres); the ship hidden by it this frame
        Entry cloud;
        Vector3 cloudCentre;
        bool hiddenByCloud;

        void Fire(Entry e)
        {
            var fx = WeaponFx.Load(e.item.index) ?? (e.rules.type <= Device.Type.ShieldDisruptor ? WeaponFx.Load(EmpLookItem) : null);
            Play(fx != null ? fx.Shot : null);
            var pos = transform.position;
            switch (e.rules.type)
            {
                case Device.Type.AreaEmp:
                    waves.Add(new Wave { e = e, centre = pos });
                    Explosion.Spawn(11, pos, transform.forward, e.radius / ShockScaleUnits, null, false);
                    break;
                case Device.Type.EmpShot:
                case Device.Type.ShieldDisruptor:
                    if (shots.TryGetValue(e, out var s))
                    {
                        int b = s.gun.TryFire(transform);
                        if (b >= 0) s.gun.SetTarget(b, weapons != null && weapons.LockTarget != null && weapons.LockTarget.Alive ? weapons.LockTarget : null);
                    }
                    break;
                case Device.Type.OverchargeArea:
                case Device.Type.OverchargeBeam:
                {
                    var hp = self.hitpoints;
                    int cost = Device.OverchargeCost(hp.maxShield, e.shieldCost);
                    hp.shield = Mathf.Max(0f, hp.shield - cost);
                    float dmg = Device.OverchargeDamage(cost, e.damagePercent);
                    bool beam = e.rules.type == Device.Type.OverchargeBeam;
                    float range = e.radius * M;
                    var all = Target.All;
                    for (int i = all.Count - 1; i >= 0; i--)
                    {
                        var t = all[i];
                        if (!Affects(t)) continue;
                        var to = t.transform.position - pos;
                        if (!Device.InCone(transform.forward, to, range, beam ? e.coneDeg : 180f)) continue;
                        if (beam) ShowBeam(t);
                        weapons?.DeviceHit(t, dmg, e.emp, to.normalized, e.item.index);
                    }
                    if (!beam) Explosion.Spawn(11, pos, transform.forward, e.radius / ShockScaleUnits, null, false);
                    break;
                }
                case Device.Type.StrikeCharge:
                    if (weapons != null) weapons.DamageBoost = Mathf.Max(1f, e.damagePercent / 100f);
                    break;
                case Device.Type.Deflector:
                    deflector = e;
                    self.Deflects = deflect;
                    break;
                case Device.Type.SensorCloud:
                    cloud = e;
                    cloudCentre = pos;
                    Explosion.Spawn(11, pos, transform.forward, e.radius / ShockScaleUnits, null, false);   // (the burst; the cloud itself isn't drawn yet)
                    break;
                case Device.Type.HullRepair:
                {
                    var hp = self.hitpoints;
                    if (hp == null) break;
                    hp.hull = Mathf.Min(hp.maxHull, hp.hull + RepairPoints(hp.maxHull, e.damagePercent));
                    self.hp = hp.hull;
                    break;
                }
                case Device.Type.ArmorRepair:
                {
                    var hp = self.hitpoints;
                    if (hp == null) break;
                    hp.armor = Mathf.Min(hp.maxArmor, hp.armor + RepairPoints(hp.maxArmor, e.damagePercent));
                    break;
                }
                case Device.Type.Restock:
                    weapons?.Restock(e.ammo);
                    break;
                case Device.Type.DeviceCharger:
                    foreach (var o in devices) if (o != e) o.rules.ResetCooldown();
                    break;
            }
        }

        /// <summary>A run's end (its time or Cancel).</summary>
        void End(Entry e)
        {
            switch (e.rules.type)
            {
                case Device.Type.StrikeCharge:
                    if (weapons != null) weapons.DamageBoost = 1f;
                    break;
                case Device.Type.Deflector:
                    if ((object)self.Deflects == (object)deflect) self.Deflects = null;
                    deflector = null;
                    break;
                case Device.Type.SensorCloud:
                    if (cloud == e) { cloud = null; Unhide(); }
                    break;
            }
        }

        /// <summary>The ship's own cloak's state back on Target.cloaked once the cloud no longer hides it.</summary>
        void Unhide()
        {
            if (!hiddenByCloud) return;
            hiddenByCloud = false;
            var cloak = GetComponent<PlayerCloak>();
            self.cloaked = cloak != null && cloak.Rules != null && cloak.Rules.Cloaked;
        }

        /// <summary>EVERSPACE 2's smoke bomb field: grown over GrowDuration to its radius, the ship inside it hidden (IsHiddenByActor).</summary>
        void UpdateCloud()
        {
            if (cloud == null || !cloud.rules.Active) { Unhide(); return; }
            float reach = Device.WaveRadius(cloud.rules.Timer, cloud.growMs, cloud.radius) * M;
            bool inside = (transform.position - cloudCentre).sqrMagnitude <= reach * reach;
            if (inside) { hiddenByCloud = true; self.cloaked = true; }
            else Unhide();
        }

        void UpdateEffects(float dtMs)
        {
            UpdateCloud();
            for (int w = waves.Count - 1; w >= 0; w--)
            {
                var wave = waves[w];
                wave.ms += dtMs;
                float r = Device.WaveRadius(wave.ms, wave.e.growMs, wave.e.radius) * M;
                Slow(wave.e, wave.centre, r, wave.reached);
                if (wave.ms >= wave.e.growMs) waves.RemoveAt(w);
            }
            var cam = Camera.main;
            foreach (var s in shots.Values) { s.gun.Update(dtMs, Target.All, null); s.rig.UpdateVisuals(dtMs, cam, transform.forward); }
            foreach (var s in deflected.Values) { s.gun.Update(dtMs, Target.All, null); s.rig.UpdateVisuals(dtMs, cam, transform.forward); }
            for (int i = beams.Count - 1; i >= 0; i--)
            {
                var (beam, to, ms) = beams[i];
                ms -= dtMs;
                if (ms <= 0f || to == null || beam == null)
                {
                    if (beam != null) beam.gameObject.SetActive(false);
                    beams.RemoveAt(i);
                    continue;
                }
                beams[i] = (beam, to, ms);
                PlaceBeam(beam, to);
            }
        }

        /// <summary>The EMP devices' slow on every hostile ship within 'radius' (metres) of 'centre' not yet in 'reached'.</summary>
        void Slow(Entry e, Vector3 centre, float radius, HashSet<Target> reached)
        {
            float factor = Device.SlowFactor(e.slowPercent);
            var all = Target.All;
            for (int i = all.Count - 1; i >= 0; i--)
            {
                var t = all[i];
                if (!Affects(t) || (reached != null && reached.Contains(t))) continue;
                var d = t.transform.position - centre;
                if (d.sqrMagnitude > radius * radius) continue;
                reached?.Add(t);
                t.lastPlayerWeapon = e.item.index;
                t.SlowBy?.Invoke(e.rules.durationMs, factor, true);
                if (e.emp > 0) weapons?.DeviceHit(t, 0f, e.emp, d.normalized, e.item.index);
            }
        }

        void OnShotHit(Shot s, int b, Target t, Vector3 p)
        {
            s.rig.ShowImpact(p);
            var e = s.e;
            var dir = s.gun.bullets[b].velocity.normalized;
            switch (e.rules.type)
            {
                case Device.Type.EmpShot:
                    Explosion.Spawn(11, p, dir, e.radius / ShockScaleUnits, null, false);
                    Slow(e, p, e.radius * M, null);
                    if (Affects(t) && t.SlowBy != null && (t.transform.position - p).sqrMagnitude > e.radius * M * e.radius * M)
                        t.SlowBy(e.rules.durationMs, Device.SlowFactor(e.slowPercent), true);   // a big hull whose centre lies beyond the radius
                    break;
                case Device.Type.ShieldDisruptor:
                {
                    var hp = t.hitpoints;
                    if (hp != null && hp.maxShield > 0 && t.RemoteDamage == null)
                    {
                        hp.shield = Mathf.Max(0f, hp.shield - e.damage);   // GoF3: the shield only
                        t.lastPlayerWeapon = e.item.index;
                    }
                    else
                    {
                        // No shield here (the NPCs) or another game's ship: another player's goes to their shield first.
                        float dmg = t.netShield >= 0f ? e.damage : e.damage * e.damagePercent / 100f;
                        weapons?.DeviceHit(t, dmg, e.emp, dir, e.item.index);
                    }
                    break;
                }
                default:   // a deflected shot
                    weapons?.DeviceHit(t, s.damage != null ? s.damage[b] : 0f, s.emp != null ? (int)s.emp[b] : 0, dir, e.item.index);
                    break;
            }
        }

        // ---- the Carom Deflector -------------------------------------------------------------------------------------

        /// <summary>Target.Deflects while the deflector runs: an enemy shot about to hit the ship flies back at its shooter,
        /// homing, at deviceDamagePercent of its damage (GoF3: x2); a beam is stopped (GoF3: "deflect just about everything").</summary>
        bool Deflect(Gun g, int i)
        {
            var e = deflector;
            if (e == null || g == null || g.Mirror) return false;   // another game's shot: a picture only (NetShotMirror)
            var shooter = g.owner;
            if ((object)shooter == null || shooter == self || shooter.isPlayer) return false;
            if (g.isBeam) return true;
            if (!deflected.TryGetValue(g.itemIndex, out var s))
            {
                var look = db.Item(g.itemIndex) ?? db.Item(g.lookIndex);
                if (look == null) return false;
                s = new Shot { e = e, gun = new Gun(look, 0f, 1f, 12, DeflectLifetimeMs, Mathf.Max(g.speedUnitsPerMs, ShotSpeedUnits), true) { owner = self } };
                s.damage = new float[s.gun.bullets.Length];
                s.emp = new float[s.gun.bullets.Length];
                s.rig = new GunRig(s.gun, WeaponFx.Load(g.itemIndex), fxRoot, null);
                s.gun.Hit += (b, t, p) => OnShotHit(s, b, t, p);
                deflected[g.itemIndex] = s;
            }
            s.e = e;
            var from = g.bullets[i].position;
            bool back = shooter != null && shooter.Alive;
            var dir = back ? shooter.transform.position - from : -g.bullets[i].velocity;
            if (dir.sqrMagnitude < 1e-8f) return true;
            s.gun.reloadAcc = s.gun.reloadMs + 1f;   // several in one frame
            int n = s.gun.TryFire(from, Quaternion.LookRotation(dir.normalized), false);
            if (n < 0) return true;   // the pool is full: the shot is gone all the same
            s.gun.SetTarget(n, back ? shooter : null);
            s.damage[n] = g.damage * e.damagePercent / 100f;
            s.emp[n] = g.emp * e.damagePercent / 100f;
            return true;
        }

        // ---- the overcharger beam's look (the transfusion beam, RepairBeam) -----------------------------------------

        void ShowBeam(Target t)
        {
            Transform beam = null;
            foreach (var b in beamPool) if (b != null && !b.gameObject.activeSelf) { beam = b; break; }
            if (beam == null)
            {
                var prefab = assets != null ? assets.transfusionBeam : null;
                if (prefab == null) return;
                var go = Instantiate(prefab);
                go.name = "Overcharger beam";
                GunRig.StripForFx(go);
                beam = go.transform;
                beamPool.Add(beam);
            }
            beam.gameObject.SetActive(true);
            PlaceBeam(beam, t);
            beams.Add((beam, t, BeamShowMs));
        }

        void PlaceBeam(Transform beam, Target t)
        {
            var d = t.transform.position - transform.position;
            if (d.sqrMagnitude < 1e-6f) return;
            beam.SetPositionAndRotation(transform.position, Quaternion.LookRotation(d, transform.up));
            beam.localScale = new Vector3(1f, 1f, d.magnitude / M);
        }
    }
}
