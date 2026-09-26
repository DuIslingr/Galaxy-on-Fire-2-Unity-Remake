// PlayerTurret.cs
// The turret on the player's ship (Reference/research/weapons_special.md 6): the turret-slot item (category 8) on the
// ship's slot-2 mount (weapons_hd.json), as its assembled *_ship_mounted prefab (pivot -> base + gun).
//   PlayerEgo::checkForTurret 0xa722c   yaw rate = attr17 * 1.5 / 200 * 2 pi / 4096 rad per ms, pitch 2 pi / 4096 rad per ms
//                                       limited to [-500, +70] * 2 pi / 4096 (the gun's pitch accumulator)
//   PlayerEgo::handleAutoTurret 0xa8ae0 180-182 (attr 16 = 1) aim and fire by themselves: every 3000 ms the nearest hostile,
//                                       active ship within 60000 units (the last unreachable one skipped), aim point = its
//                                       position + its heading * 1500 (a), fire when aligned (all turret guns on their own
//                                       reload); 500 ms without a shot stops the loop sound. Independent of the primaries.
//                                       Toggled with the HUD's auto-turret button (on at the start).
//   MGame::switchCamera / PlayerEgo::setTurretMode  the manual turrets (47-49, 224) work only in the turret view: the
//                                       camera button cycles chase -> turret view; the ship flies straight, the stick
//                                       aims the turret (360 deg yaw), the fire button fires it, primaries and secondaries
//                                       are silent. Auto turrets can't enter the view.
//   ObjectGun::update (turret branch)   bullets from the turret gun + R * (0, 0, 300) (48: x +-80 alternating, 181: z -300),
//                                       the muzzle flash at the gun's muzzle offset; the shot sound loops while firing.
//                                       The turret's own animations (the auto turrets' spinning barrels) only advance
//                                       while it fires and stand still otherwise.
// Remake: the turret view key is V / controller D-pad up / the touch turret button; auto-fire toggles with T / D-pad
// down / the same touch button. The turret camera's offsets were lost in the decompile (a: above and behind the turret).
// Plasma collectors (198-200, sort 35; weapons_special.md 6.5): the same turret on the same mount and view, but no gun: in
// the turret view the plasma stream (sn_plasma_stream_anim_add under the gun) shows and GasCloudField pulls the sparks in
// sight toward the turret (attr 49 u/ms, within attr 51 units).

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;
using UnityEngine.InputSystem;

namespace GoF2Remake.Flight
{
    public class PlayerTurret : MonoBehaviour
    {
        const float M = Gun.MetersPerUnit;
        const float PickMs = 3000f, IdleStopMs = 500f, AutoRangeUnits = 60000f, LeadUnits = 1500f;
        const float PitchUpUnits = 70f, PitchDownUnits = -500f;

        public InputAction viewAction = new InputAction("TurretView", InputActionType.Button);
        public InputAction autoAction = new InputAction("AutoTurret", InputActionType.Button);

        /// <summary>180-182: aims and fires by itself.</summary>
        public bool IsAuto { get; private set; }
        /// <summary>A plasma collector (sort 35): collects, never fires.</summary>
        public bool IsCollector { get; private set; }
        /// <summary>Collectors: attr 49 (pull speed, u/ms) and attr 51 (range, units).</summary>
        public int PullSpeed { get; private set; }
        public int CollectRange { get; private set; }
        /// <summary>PlayerEgo::getTurretPosition: the gun's world position (Unity).</summary>
        public Vector3 GunPosition => muzzle != null && muzzle.parent != null ? muzzle.parent.position : transform.position;
        /// <summary>The turret's aim (world), for the collector's scope.</summary>
        public Vector3 AimForward => aim != null ? aim.BarrelForward : transform.forward;
        public bool AutoEnabled { get; private set; } = true;
        public bool InTurretView { get; private set; }
        public int Item { get; private set; } = -1;
        /// <summary>A toggle message for the HUD (text 37 / remake strings).</summary>
        public event Action<string> Message;

        ShipController ship;
        WeaponSystem weapons;
        ChaseCamera chase;
        Gun gun;
        GunRig rig;
        TurretAim aim;
        Transform muzzle, camAnchor;
        AudioSource loop;
        Target target, unreachable;
        float pickMs = PickMs, idleMs;
        bool alternate;
        Vector3 bulletOffset;
        Visuals.PartAnimation[] anims;
        GameObject stream;
        AudioSource collectLoop;

        /// <summary>Level::createPlayer: the turret item of the current equipment, if the ship has a turret mount.</summary>
        public static PlayerTurret Attach(GameObject player, Database db, int shipIndex, IList<ItemStack> equipment, ChaseCamera chase)
        {
            var mounts = db.MountsOf(shipIndex, 2);
            if (mounts.Count == 0) return null;
            foreach (var e in equipment)
            {
                var it = db.Item(e.item);
                if (it == null || (it.categoryId != 8 && it.categoryId != 35)) continue;
                var fx = WeaponFx.Load(it.index);
                if (fx == null || fx.turretMounted == null) continue;
                var t = player.AddComponent<PlayerTurret>();
                t.Setup(it, fx, WeaponSystem.MountToLocal(mounts[0]), chase);
                return t;
            }
            return null;
        }

        /// <summary>The turret-slot item (category 8 / 35) of this equipment, or -1.</summary>
        public static int TurretItem(Database db, IList<ItemStack> equipment)
        {
            if (db == null || equipment == null) return -1;
            foreach (var e in equipment)
            {
                if (e == null) continue;
                var it = db.Item(e.item);
                if (it != null && (it.categoryId == 8 || it.categoryId == 35)) return it.index;
            }
            return -1;
        }

        /// <summary>CutScene::checkForTurret 0xa4594 (the hangar): the item's hangar_turret_item_N assembly (base + gun, the gun
        /// raised by its per-item offset) on the ship's slot-2 mount, turned (0, pi, 0) against the ship except the plasma
        /// collectors 198-200; still. Re-run after equipment changes. Null without a mount or turret.</summary>
        public static GameObject BuildStatic(Database db, int shipIndex, IList<ItemStack> equipment, Transform shipModel)
        {
            var mounts = db.MountsOf(shipIndex, 2);
            int item = TurretItem(db, equipment);
            if (mounts.Count == 0 || item < 0) return null;
            var prefab = Visuals.AssembledObject.LoadPrefab(db.AssemblyByName("hangar_turret_item_" + item));
            if (prefab == null) return null;
            var model = Instantiate(prefab, shipModel, false);
            model.name = "Turret";
            model.transform.localPosition = WeaponSystem.MountToLocal(mounts[0]);
            // A game-space turn relative to the ship: the import's 180 deg yaw cancels, (0, pi, 0) stays a half turn.
            model.transform.localRotation = item >= 198 && item <= 200 ? Quaternion.identity : Quaternion.Euler(0f, 180f, 0f);
            foreach (var a in model.GetComponentsInChildren<Visuals.PartAnimation>(true)) a.speed = 0f;
            return model;
        }

        void Setup(ItemData item, WeaponFx fx, Vector3 mountLocal, ChaseCamera chaseCamera)
        {
            ship = GetComponent<ShipController>();
            weapons = GetComponent<WeaponSystem>();
            chase = chaseCamera;
            Item = item.index;
            IsAuto = item.Attr(16) == 1;
            IsCollector = item.categoryId == 35;
            PullSpeed = item.Attr(49);
            CollectRange = item.Attr(51);
            // On the ship's model, so it banks and tumbles (death) with the hull.
            var parent = ship != null && ship.visualModel != null ? ship.visualModel : transform;
            var model = Instantiate(fx.turretMounted, parent, false);
            model.name = "Turret";
            model.transform.localPosition = mountLocal;
            GunRig.StripForFx(model);
            anims = model.GetComponentsInChildren<Visuals.PartAnimation>(true);
            foreach (var a in anims) a.speed = 0f;   // still until the first shot
            if (IsCollector)
                foreach (Transform t in model.GetComponentsInChildren<Transform>(true))
                    if (t.name.Contains("plasma_stream")) { stream = t.gameObject; stream.SetActive(false); }
            var pivot = model.transform.Find("pivot");
            Transform gunNode = null;
            if (pivot != null) foreach (Transform c in pivot) if (c.name.Contains("_gun")) gunNode = c;
            if (pivot == null || gunNode == null) { Debug.LogWarning("PlayerTurret: no pivot / gun in " + fx.turretMounted.name); enabled = false; return; }
            // The gun faces backwards in the pivot (the assembly's (0, pi, 0)); start turned to the ship's nose.
            bool backwards = Vector3.Dot(gunNode.forward, transform.forward) < 0f;
            aim = new TurretAim(pivot, gunNode, backwards ? Mathf.PI : 0f)
            {
                yawRatePerMs = item.Attr(17, 100) * 1.5f / 200f * TurretAim.RadPerMs,
                pitchRatePerMs = TurretAim.RadPerMs,
                pitchMin = PitchDownUnits * TurretAim.RadPerMs,
                pitchMax = PitchUpUnits * TurretAim.RadPerMs,
            };
            // Muzzle flash at the gun's muzzle offset; bullets from the gun + (0, 0, 300) (48: x 80, 181: z -300).
            float muzzleZ = item.index switch { 47 => 260f, 48 => 170f, 49 => 200f, 180 => 172f, 181 => 190f, 182 => 150f, 224 => 147f, _ => 200f };
            muzzle = new GameObject("Turret muzzle").transform;
            muzzle.SetParent(gunNode, false);
            muzzle.localPosition = new Vector3(0f, 0f, muzzleZ) * M;
            bulletOffset = item.index == 48 ? new Vector3(80f, 0f, 300f) : item.index == 181 ? new Vector3(0f, 0f, -300f) : new Vector3(0f, 0f, 300f);
            gun = new Gun(item, Vector3.zero, false) { owner = GetComponent<Target>() };
            var fxRoot = new GameObject("Turret fx").transform;
            rig = new GunRig(gun, fx, fxRoot, muzzle);
            gun.Hit += OnHit;
            if (fx.shot != null)
            {
                loop = gameObject.AddComponent<AudioSource>();
                loop.clip = fx.shot;
                loop.loop = fx.shotLoops;
                loop.playOnAwake = false;
                loop.spatialBlend = 0f;
            }
            camAnchor = new GameObject("Turret camera").transform;
            camAnchor.SetParent(pivot, false);
            camAnchor.localPosition = gunNode.localPosition;
            if (viewAction.bindings.Count == 0) { viewAction.AddBinding("<Keyboard>/t"); viewAction.AddBinding("<Gamepad>/dpad/up"); }
            if (autoAction.bindings.Count == 0) { autoAction.AddBinding("<Keyboard>/y"); autoAction.AddBinding("<Gamepad>/dpad/down"); }
            viewAction.Enable();
            autoAction.Enable();
        }

        void OnDestroy()
        {
            viewAction.Disable();
            autoAction.Disable();
            if (InTurretView) SetTurretView(false);
        }

        /// <summary>The touch turret button: toggles auto-fire, or the turret view for a manual turret.</summary>
        public void Toggle()
        {
            if (IsAuto) SetAuto(!AutoEnabled);
            else SetTurretView(!InTurretView);
        }

        /// <summary>MGame::OnTouchEnd auto-turret button: HUD event 0x20 / 0x21.</summary>
        public void SetAuto(bool on, bool announce = true)
        {
            if (!IsAuto || AutoEnabled == on) return;
            AutoEnabled = on;
            if (!on) StopShooting();
            if (announce) Message?.Invoke(Localization.Get(37) + (on ? ": " + Localization.Extra("on", "On") : ": " + Localization.Extra("off", "Off")));
        }

        /// <summary>PlayerEgo::setTurretMode: refused for auto turrets, while mining or while the guns are blocked.</summary>
        public void SetTurretView(bool on)
        {
            if (on && (IsAuto || weapons == null || weapons.Blocked || Time.timeScale <= 0f)) return;
            if (InTurretView == on) return;
            InTurretView = on;
            if (weapons != null) weapons.TurretView = on;
            if (ship != null) ship.steeringLocked = on;
            if (chase != null)
            {
                chase.follow = on ? camAnchor : null;
                chase.followOffset = new Vector3(0f, 6f, -14f);
                chase.followLookOffset = new Vector3(0f, 2f, 40f);
                chase.followRigid = true;
                chase.followUsesUp = true;
                if (!on) chase.Snap();
            }
            if (!on) StopShooting();
            if (stream != null) stream.SetActive(on);
            if (IsCollector)
            {
                // PlayerEgo::setTurretMode: 2255 (Extractor_Loop_01, event volume 0.047) loops while collecting.
                if (collectLoop == null)
                {
                    collectLoop = gameObject.AddComponent<AudioSource>();
                    collectLoop.playOnAwake = false; collectLoop.loop = true; collectLoop.spatialBlend = 0f;
                    collectLoop.clip = SupernovaAssets.Load()?.extractorLoop;
                }
                collectLoop.volume = 0.047f * Sfx.EventGain * Settings.SfxVolume;
                if (on && collectLoop.clip != null) collectLoop.Play(); else collectLoop.Stop();
            }
        }

        void Update()
        {
            if (aim == null) return;
            float dtMs = Time.deltaTime * 1000f;
            if (gun.owner == null) gun.owner = GetComponent<Target>();   // the player's Target comes after the turret
            bool halted = Time.timeScale <= 0f || (weapons != null && weapons.Blocked);
            if (!halted)
            {
                // The view key (V / D-pad up) is the camera button now: FreeLookCamera cycles standard / turret / free look.
                if (viewAction.WasPressedThisFrame() && !IsAuto && GetComponent<FreeLookCamera>() == null) SetTurretView(!InTurretView);
                if (autoAction.WasPressedThisFrame() && IsAuto) SetAuto(!AutoEnabled);
            }
            bool dead = GetComponent<Target>() is Target me && !me.Alive;
            if (InTurretView && ((weapons != null && weapons.Blocked) || dead)) SetTurretView(false);
            if (dead) { StopShooting(); foreach (var a in anims) if (a != null) a.speed = 0f; gun.Update(dtMs, Target.All, null); rig.UpdateVisuals(dtMs, Camera.main, aim.BarrelForward); return; }

            bool fire = false;
            if (!halted && InTurretView)
            {
                aim.Drive(ship != null ? ship.SteerInput : Vector2.zero, dtMs);
                // The camera turns with the turret, at half the gun's pitch.
                camAnchor.rotation = Quaternion.LookRotation(Vector3.Slerp(Vector3.ProjectOnPlane(aim.BarrelForward, transform.up), aim.BarrelForward, 0.5f), transform.up);
                fire = weapons != null && weapons.FireHeld && !IsCollector;   // a collector collects by aiming (GasCloudField)
                if (IsCollector) foreach (var a in anims) if (a != null) a.speed = 1f;
            }
            else if (!halted && IsAuto && AutoEnabled && GetComponent<Target>() is Target self && self.Alive)
                fire = AutoAim(dtMs);

            if (fire)
            {
                var off = bulletOffset;
                if (Item == 48) { off.x = alternate ? -80f : 80f; alternate = !alternate; }
                int b = gun.TryFire(muzzle.parent.TransformPoint(new Vector3(-off.x, off.y, off.z) * M), Quaternion.LookRotation(aim.BarrelForward, aim.BarrelUp), false);
                if (b >= 0)
                {
                    rig.OnShot();
                    idleMs = 0f;
                    if (loop != null && (!loop.isPlaying || !loop.loop)) { loop.volume = 0.7f * Settings.SfxVolume; loop.Play(); }
                }
            }
            idleMs += dtMs;
            if (idleMs > IdleStopMs && loop != null && loop.loop && loop.isPlaying) loop.Stop();
            // The animations run only while shots are going out (within one reload of the last shot).
            float animSpeed = idleMs <= gun.reloadMs + 50f || (IsCollector && InTurretView) ? 1f : 0f;
            foreach (var a in anims) if (a != null) a.speed = animSpeed;
            gun.Update(dtMs, Target.All, null);
            rig.UpdateVisuals(dtMs, Camera.main, aim.BarrelForward);
        }

        /// <summary>handleAutoTurret: re-pick every 3 s, turn toward the lead point, fire when aligned.</summary>
        bool AutoAim(float dtMs)
        {
            pickMs += dtMs;
            if (pickMs >= PickMs || target == null || !target.Alive || !target.isActiveAndEnabled)
            {
                pickMs = 0f;
                target = PickTarget();
            }
            if (target == null) return false;
            var at = target.transform.position + target.transform.forward * LeadUnits * M;
            bool aligned = aim.Step(at, dtMs);
            if (aim.LimitHit) { unreachable = target; target = null; pickMs = PickMs; return false; }
            return aligned;
        }

        Target PickTarget()
        {
            Target best = null;
            float bestD = AutoRangeUnits * M;
            foreach (var t in Target.All)
            {
                if (t == null || !t.isShip || !t.hostileToPlayer || !t.Alive || t == unreachable || t.untargetable || !t.isActiveAndEnabled) continue;
                float d = (t.transform.position - transform.position).magnitude;
                if (d < bestD) { bestD = d; best = t; }
            }
            if (best == null) unreachable = null;
            return best;
        }

        void OnHit(int bullet, Target t, Vector3 point)
        {
            t.Damage(gun.damage, false, gun.bullets[bullet].velocity);
            rig.ShowImpact(point);
        }

        void StopShooting()
        {
            if (loop != null && loop.isPlaying) loop.Stop();
        }
    }
}
