// WeaponSystem.cs
// The player's weapons (weapons.md, weapons_special.md): one Gun per equipped weapon item on its ship mount
// (weapons_hd.json, Gun::setOffset(weaponPos[type][slot])), their projectiles, muzzle flashes, impacts and sounds.
//   Primary (MGame::OnUpdate -> PlayerEgo::shoot -> Player::shoot): while fire is held every primary gun fires on
//     its own reload; all together on the first frame, no alternation between mounts. Weapon mods (sort 28,
//     Ship::refreshValue, the last one wins): reload x (1 - attr39/100), damage x (1 + attr40/100), primaries only.
//   Beams (items 9-11, 228): hitscan on the nearest target inside the crosshair box, on screen and < 60000 units
//     (Radar::draw's KIPlayer+0x6f; other objects inside a +-24000 cube).
//   Secondary (MGame::OnTouchEnd, on release): Player::shoot first ignites every bomb in flight (EMP bombs, nukes,
//     ionizing), whatever is selected; otherwise the selected item's first ready gun fires. The selection
//     (PlayerEgo+0x10c, saved as Status+0xf4) keeps the item while it is mounted; no automatic switch when it runs empty.
//     Remake: a cycle key (G / controller D-pad right / the touch caption) instead of the HUD quick menu.
//     Ammo = the mounted stack's amount: 1 per missile / bomb / mine / blast, 1 per cluster salvo.
//   Hits: primary damage (attr 9) to the target; rockets / missiles / bombs kill asteroids instantly (9999). Area hits
//     (Gun::ignite) go the same way (hull damage + EMP); the shock blast pushes NPC ships away (PlayerFighter::initPush).
//   BombGun::update: in hardcore mode the player takes damage * clamp((mag/2 - d)/(mag/2) * 0.5, 0, 1) (shock blast x0.2).
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
        const float BeamRangeUnits = 60000f, BeamObjectCubeUnits = 24000f;

        public bool useBuiltInInput = true;
        public InputAction firePrimaryAction = new InputAction("FirePrimary", InputActionType.Button);
        public InputAction fireSecondaryAction = new InputAction("FireSecondary", InputActionType.Button);
        public InputAction cycleSecondaryAction = new InputAction("CycleSecondary", InputActionType.Button);
        [Range(0f, 1f)] public float shotVolume = 0.7f;

        class Rig
        {
            public GunRig visuals;
            public Gun gun => visuals.gun;
            public WeaponFx fx => visuals.fx;
            public AudioSource loop;
            /// <summary>Secondaries: the mounted stack this gun draws its ammo from (Gun+0xf4).</summary>
            public ItemStack stack;
        }

        readonly List<Rig> rigs = new List<Rig>();
        Database db;
        Transform fxRoot;
        AudioSource shotSource;
        bool touchPrimary;
        /// <summary>A fire button pressed while the game was paused or the guns blocked (e.g. the mouse click on a dialogue's
        /// Next): ignored until it is released, so it neither fires when the game resumes nor launches a missile on release.</summary>
        bool primaryLatched, secondaryLatched;

        /// <summary>The selected secondary item (-1 = none); the HUD shows it with its ammo.</summary>
        public int SelectedSecondary { get; private set; } = -1;
        /// <summary>Remaining missiles/rockets of the selected secondary weapon (-1 = none equipped).</summary>
        public int SecondaryAmmo
        {
            get
            {
                if (SelectedSecondary < 0) return -1;
                int n = 0;
                foreach (var r in rigs) if (r.gun.isSecondary && r.gun.itemIndex == SelectedSecondary && r.stack != null) n += Mathf.Max(0, r.stack.amount);
                return n;
            }
        }
        public string SecondaryName => SelectedSecondary >= 0 ? UI.ItemInfo.ItemName(SelectedSecondary) : "";
        /// <summary>More than one secondary item is mounted (the HUD offers the switch).</summary>
        public bool CanCycleSecondary { get { int n = 0, last = -1; foreach (var r in rigs) if (r.gun.isSecondary && r.gun.itemIndex != last) { last = r.gun.itemIndex; n++; } return n > 1; } }
        /// <summary>No firing (asteroid docking and mining block the guns, MGame::OnTouchBegin).</summary>
        public bool Blocked { get; set; }
        /// <summary>Raised when a player bullet hits something (the crosshair turns orange for 200 ms).</summary>
        public event Action Hit;
        /// <summary>A bomb, mine or blast went off (the explosion's world position).</summary>
        public event Action<Vector3> Detonated;
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
        /// <summary>PlayerEgo::setTurretMode: the fire button fires the turret; primaries and secondaries are silent.</summary>
        [NonSerialized] public bool TurretView;
        /// <summary>The fire button is held this frame (not paused, not latched): the turret view fires with it.</summary>
        public bool FireHeld { get; private set; }

        void Awake()
        {
            AddDefaultBindings();
            shotSource = gameObject.AddComponent<AudioSource>();
            shotSource.playOnAwake = false;
            shotSource.spatialBlend = 0f;
        }

        void OnEnable() { firePrimaryAction.Enable(); fireSecondaryAction.Enable(); cycleSecondaryAction.Enable(); }
        void OnDisable() { firePrimaryAction.Disable(); fireSecondaryAction.Disable(); cycleSecondaryAction.Disable(); StopLoops(); }

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
            if (cycleSecondaryAction.bindings.Count == 0)
            {
                cycleSecondaryAction.AddBinding("<Keyboard>/g");
                cycleSecondaryAction.AddBinding("<Gamepad>/dpad/right");
            }
        }

        /// <summary>Level::createPlayer: one gun per equipped primary/secondary item on the ship's mounts.</summary>
        public void Setup(Database db, int shipIndex, IList<ItemStack> equipment)
        {
            this.db = db;
            fxRoot = new GameObject("Player weapon fx").transform;
            var primaryMounts = db.MountsOf(shipIndex, 0);
            var secondaryMounts = db.MountsOf(shipIndex, 1);
            // Ship::refreshValue, sort 28: the last mounted weapon mod sets both factors.
            float fireRate = 1f, damageFactor = 1f;
            foreach (var e in equipment)
            {
                var it = db.Item(e.item);
                if (it != null && it.categoryId == 28) { fireRate = 1f - it.Attr(39) / 100f; damageFactor = 1f + it.Attr(40) / 100f; }
            }
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
                if (!secondary)
                {
                    // Level::createPlayer: damage = int(attr9 * damageFactor), reload = int(attr11 * fireRate), type-0 items only.
                    gun.damage = (int)(gun.damage * damageFactor);
                    gun.reloadMs = Mathf.Max(1f, (int)(gun.reloadMs * fireRate));
                }
                if (gun.isBeam) gun.AutoAim = BeamTarget;
                var rig = BuildRig(gun);
                if (secondary) rig.stack = equipment[e];
                rigs.Add(rig);
            }
            // MGame::OnInitialize: keep the saved selection while that item is mounted, else the first secondary slot.
            int saved = Session.SelectedSecondary;
            SelectedSecondary = rigs.Exists(r => r.gun.isSecondary && r.gun.itemIndex == saved) ? saved
                              : rigs.Find(r => r.gun.isSecondary)?.gun.itemIndex ?? -1;
            Session.SelectedSecondary = SelectedSecondary;
        }

        /// <summary>Writes the remaining ammo back to the mounted stacks (they are the stacks themselves: nothing to copy).</summary>
        public void StoreAmmo() { }

        /// <summary>Mount position (game space, ship-relative) -> Unity ship space: (-x, y, z) * 0.05 (the models are
        /// imported mirrored and turned 180 degrees, so ship-local offsets flip x, not z).</summary>
        public static Vector3 MountToLocal(WeaponMount m) =>
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
            gun.AreaHit += (target, dmg, emp, center) => OnAreaHit(rig, target, dmg, emp, center);
            gun.Ignited += point => OnIgnited(rig, point);
            return rig;
        }

        // ---- input ------------------------------------------------------------------------------------------

        /// <summary>Touch: hold to fire the primary guns.</summary>
        public void SetPrimaryHeld(bool held) => touchPrimary = held;

        /// <summary>Touch / release of the missile button (MGame::OnTouchEnd -> Player::shoot(1)): detonate the bombs in
        /// flight, else fire the selected secondary.</summary>
        public bool FireSecondary()
        {
            if (Blocked || TurretView) return false;
            bool detonated = false;
            foreach (var r in rigs) if (r.gun.isSecondary && r.gun.BombInFlight) { r.gun.Detonate(); detonated = true; }
            if (detonated) return true;
            if (SelectedSecondary < 0) return false;
            foreach (var r in rigs)
            {
                if (!r.gun.isSecondary || r.gun.itemIndex != SelectedSecondary || r.stack == null || r.stack.amount <= 0) continue;
                if (r.gun.kind == Gun.Kind.Sentry && !SentryGun.CanDeploy) return false;   // Level+0x6c > 2: refused, no cost
                int b = r.gun.TryFire(transform);
                if (b < 0) continue;
                if (r.gun.kind == Gun.Kind.Sentry)
                {
                    // SentryGun::update: the deploy "bullet" places the next free sentry object; it isn't drawn.
                    SentryGun.Deploy(db, r.gun.itemIndex, r.gun.bullets[b].position, transform.rotation, FindAnyObjectByType<World.Traffic>());
                    r.gun.bullets[b].timer = -1e9f;
                }
                r.stack.amount--;
                PlayShot(r);
                r.visuals.OnShot();
                return true;
            }
            return false;
        }

        /// <summary>Remake: the next mounted secondary item (the original picks it in the HUD quick menu).</summary>
        public void CycleSecondary()
        {
            var items = new List<int>();
            foreach (var r in rigs) if (r.gun.isSecondary && !items.Contains(r.gun.itemIndex)) items.Add(r.gun.itemIndex);
            if (items.Count == 0) return;
            int i = items.IndexOf(SelectedSecondary);
            SelectedSecondary = items[(i + 1) % items.Count];
            Session.SelectedSecondary = SelectedSecondary;
        }

        // ---- per frame ----------------------------------------------------------------------------------------

        void Update()
        {
            float dtMs = Time.deltaTime * 1000f;
            // The game is paused (Time.timeScale 0: dialogues, the autopilot menu, the star map): no firing at all.
            bool halted = Blocked || Time.timeScale <= 0f;
            bool primaryPressed = useBuiltInInput && firePrimaryAction.IsPressed();
            bool secondaryPressed = useBuiltInInput && fireSecondaryAction.IsPressed();
            if (halted) { primaryLatched |= primaryPressed; secondaryLatched |= secondaryPressed; }
            if (!primaryPressed) primaryLatched = false;
            bool primaryHeld = !halted && (touchPrimary || (primaryPressed && !primaryLatched));
            FireHeld = primaryHeld;
            if (TurretView) primaryHeld = false;
            if (!halted && !TurretView && useBuiltInInput && fireSecondaryAction.WasReleasedThisFrame() && !secondaryLatched) FireSecondary();
            if (!secondaryPressed) secondaryLatched = false;
            if (!halted && useBuiltInInput && cycleSecondaryAction.WasPressedThisFrame()) CycleSecondary();

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

        /// <summary>Radar::draw's auto-aim flag (KIPlayer+0x6f) for the beams: the nearest target (to the player) on screen,
        /// inside the +-w/16 box around the crosshair, within 60000 units (ships) or a +-24000 cube (other objects).</summary>
        Target BeamTarget()
        {
            var cam = Camera.main;
            if (cam == null) return null;
            var aim = cam.WorldToScreenPoint(transform.position + transform.forward * 22000f * M);
            float box = Screen.width / 16f, best = float.MaxValue;
            Target found = null;
            foreach (var t in Target.All)
            {
                if (t == null || t == owner || !t.Alive || t.untargetable || !t.isActiveAndEnabled) continue;
                var d = t.transform.position - transform.position;
                if (t.isShip ? d.magnitude >= BeamRangeUnits * M
                             : Mathf.Abs(d.x) >= BeamObjectCubeUnits * M || Mathf.Abs(d.y) >= BeamObjectCubeUnits * M || Mathf.Abs(d.z) >= BeamObjectCubeUnits * M) continue;
                var p = cam.WorldToScreenPoint(t.transform.position);
                if (p.z <= 0f || Mathf.Abs(p.x - aim.x) >= box || Mathf.Abs(p.y - aim.y) >= box) continue;
                float dist = d.sqrMagnitude;
                if (dist < best) { best = dist; found = t; }
            }
            return found;
        }

        void OnHit(Rig r, int bullet, Target target, Vector3 point)
        {
            // Rockets, missiles and bombs destroy asteroids outright; everything else deals its damage (attr 9).
            bool missile = r.gun.isSecondary;
            bool wasAlive = target.Alive;
            target.Damage(missile && target.isAsteroid ? 9999f : r.gun.damage, false, r.gun.bullets[bullet].velocity);
            if (wasAlive && !target.Alive && target.isAsteroid) Session.AsteroidsDestroyed++;   // Status+0xd8
            ApplyEmp(target, (int)r.gun.emp);
            r.visuals.ShowImpact(point);
            Hit?.Invoke();
        }

        /// <summary>Gun::ignite on one target: hull damage and EMP, the shock blast's push.</summary>
        void OnAreaHit(Rig r, Target target, int dmg, int emp, Vector3 center)
        {
            bool wasAlive = target.Alive;
            if (dmg > 0) target.Damage(dmg, false, (target.transform.position - center).normalized);
            if (wasAlive && !target.Alive && target.isAsteroid) Session.AsteroidsDestroyed++;
            ApplyEmp(target, emp);
            if (r.gun.kind == Gun.Kind.ShockBlast && target.isShip)
                target.GetComponent<World.NpcShip>()?.InitPush(center, r.gun.magnitude * M);
            if (dmg > 0) Hit?.Invoke();
        }

        /// <summary>Player::damageEmp (EMP weapons): disabling a ship of races 0..3 costs standing 2 (applyDelict).</summary>
        static void ApplyEmp(Target target, int emp)
        {
            if (emp > 0 && target.hitpoints != null && target.isShip && target.Alive && target.hitpoints.DamageEmp(emp)
                && target.race >= 0 && target.race <= 3 && !target.hostileToPlayer)
                Standing.ApplyDelict(target.race, 2);
        }

        /// <summary>BombGun / MineGun / ObjectGun: the explosion, the counter, hardcore self-damage.</summary>
        void OnIgnited(Rig r, Vector3 point)
        {
            var gun = r.gun;
            int type = r.fx != null ? r.fx.explosionType : 0;
            if (type >= 0) Explosion.Spawn(type, point, transform.forward, 1f, r.fx != null ? r.fx.explosionSound : null, false);
            if (gun.kind == Gun.Kind.ScatterGun) return;
            if (gun.kind == Gun.Kind.Nuke) Session.BombsDetonated++;   // Status+200
            if (Session.IsExtreme && owner != null && (gun.IsBomb || gun.kind == Gun.Kind.ShockBlast))
            {
                float half = gun.magnitude * 0.5f;
                float d = (point - transform.position).magnitude / M;
                float f = Mathf.Clamp01((half - d) / half * 0.5f) * (gun.kind == Gun.Kind.ShockBlast ? 0.2f : 1f);
                if (f > 0f && gun.damage > 0f) owner.Damage((int)(f * gun.damage), false, (transform.position - point).normalized);
            }
            Detonated?.Invoke(point);
        }

        void StopLoops()
        {
            foreach (var r in rigs) if (r.loop != null) r.loop.Stop();
        }
    }
}
