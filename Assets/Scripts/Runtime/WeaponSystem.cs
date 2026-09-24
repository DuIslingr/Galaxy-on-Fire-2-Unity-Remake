// WeaponSystem.cs
// The player's weapons (weapons.md): one Gun per equipped weapon item on its ship mount (weapons_hd.json,
// Gun::setOffset(weaponPos[type][slot])), their projectiles, muzzle flashes, impacts and sounds.
//   Primary (MGame::OnUpdate -> PlayerEgo::shoot -> Player::shoot): while fire is held every primary gun fires on
//     its own reload; all together on the first frame, no alternation between mounts.
//   Secondary (MGame::OnTouchEnd): one missile per press, on release; ammo = item amount.
//   Hits: primary damage (attr 9) to the target; rockets/missiles kill asteroids instantly (damage 9999).
// Input (Input System, editable in the inspector): fire = Left Ctrl / left mouse / gamepad right trigger,
// missile = F / right mouse / gamepad left trigger. Touch: FlightHud calls SetPrimaryHeld / FireSecondary.

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Visuals;
using UnityEngine;
using UnityEngine.InputSystem;

namespace GoF2Remake.Flight
{
    [RequireComponent(typeof(ShipController))]
    public class WeaponSystem : MonoBehaviour
    {
        const float M = Gun.MetersPerUnit;

        public bool useBuiltInInput = true;
        public InputAction firePrimaryAction = new InputAction("FirePrimary", InputActionType.Button);
        public InputAction fireSecondaryAction = new InputAction("FireSecondary", InputActionType.Button);
        [Range(0f, 1f)] public float shotVolume = 0.7f;

        class Rig
        {
            public GunRig visuals;
            public Gun gun => visuals.gun;
            public WeaponFx fx => visuals.fx;
            public AudioSource loop;
        }

        readonly List<Rig> rigs = new List<Rig>();
        Transform fxRoot;
        AudioSource shotSource;
        bool touchPrimary;

        /// <summary>Remaining missiles/rockets of the selected secondary weapon (-1 = none equipped).</summary>
        public int SecondaryAmmo { get; private set; } = -1;
        public string SecondaryName { get; private set; } = "";
        /// <summary>No firing (asteroid docking and mining block the guns, MGame::OnTouchBegin).</summary>
        public bool Blocked { get; set; }
        ItemStack secondaryStack;
        /// <summary>Raised when a player bullet hits something (the crosshair turns orange for 200 ms).</summary>
        public event Action Hit;
        /// <summary>Locked target for homing missiles (the radar's ship lock, CombatRadar).</summary>
        public Target LockTarget { get; set; }
        /// <summary>The player's own hittable object: never hit by its own guns.</summary>
        public Target Owner
        {
            get => owner;
            set { owner = value; foreach (var r in rigs) r.gun.owner = value; }
        }
        Target owner;

        public bool HasPrimary => rigs.Exists(r => !r.gun.isSecondary);

        void Awake()
        {
            AddDefaultBindings();
            shotSource = gameObject.AddComponent<AudioSource>();
            shotSource.playOnAwake = false;
            shotSource.spatialBlend = 0f;
        }

        void OnEnable() { firePrimaryAction.Enable(); fireSecondaryAction.Enable(); }
        void OnDisable() { firePrimaryAction.Disable(); fireSecondaryAction.Disable(); StopLoops(); }

        void OnDestroy()
        {
            if (fxRoot != null) Destroy(fxRoot.gameObject);
        }

        void AddDefaultBindings()
        {
            if (firePrimaryAction.bindings.Count == 0)
            {
                firePrimaryAction.AddBinding("<Keyboard>/leftCtrl");
                firePrimaryAction.AddBinding("<Mouse>/leftButton");
                firePrimaryAction.AddBinding("<Gamepad>/rightTrigger");
            }
            if (fireSecondaryAction.bindings.Count == 0)
            {
                fireSecondaryAction.AddBinding("<Keyboard>/f");
                fireSecondaryAction.AddBinding("<Mouse>/rightButton");
                fireSecondaryAction.AddBinding("<Gamepad>/leftTrigger");
            }
        }

        /// <summary>Level::createPlayer: one gun per equipped primary/secondary item on the ship's mounts.</summary>
        public void Setup(Database db, int shipIndex, IList<ItemStack> equipment)
        {
            fxRoot = new GameObject("Player weapon fx").transform;
            var primaryMounts = db.MountsOf(shipIndex, 0);
            var secondaryMounts = db.MountsOf(shipIndex, 1);
            int p = 0, s = 0;
            for (int e = 0; e < equipment.Count; e++)
            {
                var item = db.Item(equipment[e].item);
                if (item == null) continue;
                bool secondary = item.type == "secondary";
                if (item.type != "primary" && !secondary) continue;
                var mounts = secondary ? secondaryMounts : primaryMounts;
                int slot = secondary ? s++ : p++;
                if (slot >= mounts.Count) { Debug.LogWarning($"WeaponSystem: no free {(secondary ? "secondary" : "primary")} mount for {item.name}"); continue; }
                var gun = new Gun(item, MountToLocal(mounts[slot]), secondary);
                var rig = BuildRig(gun);
                rigs.Add(rig);
                if (secondary && SecondaryAmmo < 0)
                {
                    SecondaryAmmo = equipment[e].amount;
                    SecondaryName = item.name;
                    secondaryStack = equipment[e];
                }
            }
        }

        /// <summary>Writes the remaining missiles back to the mounted stack (docking saves the ship to Status).</summary>
        public void StoreAmmo()
        {
            if (secondaryStack != null) secondaryStack.amount = UnityEngine.Mathf.Max(0, SecondaryAmmo);
        }

        /// <summary>Mount position (game space, ship-relative) -> Unity ship space: (-x, y, z) * 0.05 (the models are
        /// imported mirrored and turned 180 degrees, so ship-local offsets flip x, not z).</summary>
        static Vector3 MountToLocal(WeaponMount m) =>
            m.position_engine != null && m.position_engine.Length >= 3
                ? new Vector3(-m.position_engine[0], m.position_engine[1], m.position_engine[2]) * M
                : Vector3.zero;

        Rig BuildRig(Gun gun)
        {
            var rig = new Rig { visuals = new GunRig(gun, WeaponFx.Load(gun.itemIndex), fxRoot, transform) };
            var fx = rig.fx;
            if (fx != null && fx.shotLoops && fx.shot != null)
            {
                rig.loop = gameObject.AddComponent<AudioSource>();
                rig.loop.clip = fx.shot;
                rig.loop.loop = true;
                rig.loop.playOnAwake = false;
                rig.loop.spatialBlend = 0f;
            }
            gun.owner = owner;
            gun.Hit += (i, target, point) => OnHit(rig, i, target, point);
            return rig;
        }

        // ---- input ------------------------------------------------------------------------------------------

        /// <summary>Touch: hold to fire the primary guns.</summary>
        public void SetPrimaryHeld(bool held) => touchPrimary = held;

        /// <summary>Touch / release of the missile button: fire one secondary (MGame::OnTouchEnd).</summary>
        public bool FireSecondary()
        {
            if (SecondaryAmmo <= 0 || Blocked) return false;
            foreach (var r in rigs)
            {
                if (!r.gun.isSecondary) continue;
                int b = r.gun.TryFire(transform);
                if (b < 0) continue;
                SecondaryAmmo--;
                PlayShot(r);
                return true;
            }
            return false;
        }

        // ---- per frame ----------------------------------------------------------------------------------------

        void Update()
        {
            float dtMs = Time.deltaTime * 1000f;
            bool primaryHeld = !Blocked && (touchPrimary || (useBuiltInInput && firePrimaryAction.IsPressed()));
            if (!Blocked && useBuiltInInput && fireSecondaryAction.WasReleasedThisFrame()) FireSecondary();

            var cam = Camera.main;
            foreach (var r in rigs)
            {
                var gun = r.gun;
                if (!gun.isSecondary && primaryHeld)
                {
                    int b = gun.TryFire(transform);
                    if (b >= 0) OnShot(r);
                }
                gun.Update(dtMs, Target.All, LockTarget);
                r.visuals.UpdateVisuals(dtMs, cam, transform.forward);
                if (r.loop != null)
                {
                    bool firing = primaryHeld && !gun.isSecondary;
                    if (firing && !r.loop.isPlaying) { r.loop.volume = shotVolume * Settings.SfxVolume; r.loop.Play(); }
                    else if (!firing && r.loop.isPlaying) r.loop.Stop();
                }
            }
        }

        void OnShot(Rig r)
        {
            if (r.loop == null) PlayShot(r);
            r.visuals.OnShot();
        }

        void PlayShot(Rig r)
        {
            if (r.fx != null && r.fx.shot != null) shotSource.PlayOneShot(r.fx.shot, shotVolume * Settings.SfxVolume);
        }

        void OnHit(Rig r, int bullet, Target target, Vector3 point)
        {
            // Rockets, missiles (and bombs) destroy asteroids outright; everything else deals its damage (attr 9).
            bool missile = r.gun.isSecondary;
            bool wasAlive = target.Alive;
            target.Damage(missile && target.isAsteroid ? 9999f : r.gun.damage, false, r.gun.bullets[bullet].velocity);
            if (wasAlive && !target.Alive && target.isAsteroid) Session.AsteroidsDestroyed++;   // Status+0xd8
            // Player::damageEmp (EMP weapons, empDamage): disabling a ship of races 0..3 costs standing 2 (applyDelict).
            if (r.gun.emp > 0f && target.hitpoints != null && target.isShip && target.Alive && target.hitpoints.DamageEmp((int)r.gun.emp)
                && target.race >= 0 && target.race <= 3 && !target.hostileToPlayer)
                Standing.ApplyDelict(target.race, 2);
            r.visuals.ShowImpact(point);
            Hit?.Invoke();
        }

        void StopLoops()
        {
            foreach (var r in rigs) if (r.loop != null) r.loop.Stop();
        }
    }
}
