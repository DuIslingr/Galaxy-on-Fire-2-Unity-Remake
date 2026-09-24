// GoF2NpcShip.cs
// One NPC ship (KIPlayer + Player), Reference/research/npc_traffic_ai.md 4-6 and ship_combat.md 2-5. Created by
// GoF2Traffic from a GoF2SpawnSpec.
// Fighters (PlayerFighter::update 0xf0d90):
//   relations   hostile = pirates / Void / Specters, or an enemy race by the standing, or turned / alarmed; friend by the
//               standing (recomputed every frame)
//   targeting   enemy list = the player (index 0) + ships of other races; attack whatever is inside the +-50000 box; every
//               5 s: 20 % start / stop flying straight, 30 % re-roll the target else back to the player; neutral and
//               friendly ships never keep the player but attack the first race-hostile ship; no target -> the patrol
//               route (a finished route -> toward the player without firing)
//   steering    speed 2 u/ms (boost 5.5), heading += normalize(dir - fwd) * dt * 48 / 65536, snap when within L1 0.0625;
//               inside +-8000 of the target it steers along its own right vector (circles away), so it never fires
//               close up; visual bank up to 33 deg from the averaged turn, auto-level after 750 ms
//   firing      target inside the +-0.0076 cone (ship-space unit vector x / y) and +-35000 per axis; one NPC gun
//   boost       5 % per 5 s, or after losing 40 % of the hull, for 5..8 s (x1.05 / x0.95 per 30 fps frame)
//   avoidance   inside the first landmark's volumes (station, gate), then the first ship's (freighters): heading +=
//               (away - fwd) * speed * 0.03 plus an extra step (fighters fly through asteroids and each other)
//   death       sound 20, 1.5..3 s tumbling along the death direction, then Explosion type 0, the hull 300 ms more,
//               a crate with the cargo; gone once the explosion ended and the crate is gone (60 s)
// Damage smoke (PlayerFighter::update 0xf1b0e): below 33 % of the hull a fighter trails the prologue's smoke and fire
//   (GoF2ShipSmoke), off again when repaired to 33 %; they keep running through the death tumble and stop at the explosion.
// Freighters (PlayerFixedObject): unarmed, fly game +Z at 1 u/ms, never turn, x5 hull; death: their wreck animation
// (cargo_*_explosion_anim, ~10 s, still moving), then a x6 explosion; the crate appears at once; the wreck then stays
// where it is (state 4) with its wreck volumes. Their boxes (GoF2Obstacle, Level::createShip) are what bullets hit, the
// player slides along and fighters steer out of.
// Friendly fire (Player::damage): hits by the player on system-race / attack-race ships add up: > 33 % of the hull ->
// radio "Hold your fire!", >= 50 % -> this ship turns hostile, >= 66 % -> the whole race turns hostile (10 / 25 / 40 % on
// Extreme). NPC bullets never hit their own race; a non-hostile NPC's stray hit on the player does 20 %.
// Directions: "right" is Unity's transform.right (the original's mirrored model space may circle the other way).

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;

namespace GoF2Remake.World
{
    public class GoF2NpcShip : MonoBehaviour
    {
        const float M = 0.05f;
        public enum State { Fly = 1, Dying = 3, Dead = 4, JumpingOut = 6 }

        public GoF2SpawnSpec Spec { get; private set; }
        public int Race => Spec.race;
        public bool IsFreighter => Spec.freighter;
        public GoF2Target Target { get; private set; }
        public GoF2Hitpoints Hp => Target.hitpoints;
        public State Current { get; private set; } = State.Fly;
        /// <summary>Dead and cleaned up (inactive): the level may relaunch it.</summary>
        public bool Gone => !gameObject.activeSelf;
        public bool IsJumper => Spec.group == GoF2NpcGroup.Jumper;

        [System.NonSerialized] public bool alwaysEnemy, turnedEnemy, alwaysFriend;
        /// <summary>setToSleep / setInitActive(false): no flying or shooting until woken (Wake, or the player close by).</summary>
        public bool Asleep { get; private set; }
        /// <summary>PlayerFighter: a sleeping hostile ship is invisible after the tutorial (index &gt; 1): no model, no marker,
        /// no lock.</summary>
        public bool Hidden => forcedHidden || (Asleep && Target.hostileToPlayer && GoF2Session.CampaignMission > 1);
        bool forcedHidden;

        /// <summary>KIPlayer::setVisible (cutscenes): hidden ships have no model, marker or lock.</summary>
        public void SetVisible(bool visible)
        {
            forcedHidden = !visible;
            if (modelGo != null && Current == State.Fly) modelGo.SetActive(!Hidden);
        }

        /// <summary>The engine exhaust meshes (cutscenes: "exhaust hidden" while the pirates wait).</summary>
        public void SetExhaust(bool on) => modelGo?.GetComponent<GoF2AssembledObject>()?.SetExhaust(on, false);

        /// <summary>The engine loop (PlayerFighter: no NPC engine sound in index 1).</summary>
        public void SetEngineSound(bool on)
        {
            if (engine == null || engine.clip == null) return;
            if (on && !engine.isPlaying) engine.Play(); else if (!on) engine.Stop();
        }
        bool inactive;
        [System.NonSerialized] public List<GoF2Target> enemies = new List<GoF2Target>();

        GoF2Traffic traffic;
        GoF2Database db;
        GoF2CombatAssets assets;
        Transform model;
        GameObject modelGo;
        GoF2Route route;
        GoF2Gun gun;
        GoF2GunRig rig;
        AudioSource engine, sfx;
        List<GoF2Stack> loot = new List<GoF2Stack>();
        int damageByPlayer;

        // flight
        float speed = GoF2NpcTables.BaseSpeed, targetSpeed;
        bool boosting, panic;
        float boostTimer, boostDuration, reselectTimer = 0f, jumpMs;
        int lastHull, damageSinceBoost;
        bool drift, attacking, followingWaypoint;
        int targetIdx = -1;
        GoF2Target target;
        float bank, bankTarget, levelTimer = 750f;
        bool levelling;
        readonly float[] turnRing = new float[5];
        int ringIndex, ringFilled;

        // death
        float dyingMs, deadMs;
        Vector3 spinAxis, deathDir;
        GoF2Explosion explosion;
        GameObject wreck;
        GoF2Crate crate;
        GoF2Obstacle obstacle;
        GoF2ShipSmoke smoke;
        bool smoking;   // PlayerFighter +0x1f4

        static Vector3 ToUnity(Vector3 game) => new Vector3(game.x, game.y, -game.z) * M;
        static Vector3 ToGame(Vector3 unity) => new Vector3(unity.x, unity.y, -unity.z) / M;
        /// <summary>Game rotation identity: facing game +Z = Unity -Z.</summary>
        static readonly Quaternion GameForward = Quaternion.Euler(0f, 180f, 0f);

        public void Setup(GoF2Traffic owner, GoF2Database database, GoF2SpawnSpec spec, GameObject prefab, Transform fxRoot)
        {
            traffic = owner;
            db = database;
            Spec = spec;
            assets = GoF2CombatAssets.Load();
            transform.SetPositionAndRotation(ToUnity(spec.position), GameForward);
            if (prefab != null)
            {
                modelGo = Instantiate(prefab, transform, false);
                modelGo.GetComponent<GoF2AssembledObject>()?.SetPlayerVariant(false);
                model = modelGo.transform;
            }

            int kind = spec.freighter ? 1 : 0;
            Target = gameObject.AddComponent<GoF2Target>();
            Target.isShip = true;
            Target.race = spec.race;
            Target.customDeath = true;
            Target.radius = GoF2NpcTables.HitRadiusUnits * M;
            Target.hitpoints = new GoF2Hitpoints(GoF2NpcTables.Hull(kind, spec.ship));
            Target.hitpoints.SetEmp(GoF2NpcTables.Emp(kind), GoF2NpcTables.EmpRecoveryMs(kind));
            if (spec.hitpoints > 0) Target.hitpoints = new GoF2Hitpoints(spec.hitpoints);
            Target.hp = Target.maxHp = Target.hitpoints.maxHull;
            alwaysEnemy = spec.alwaysEnemy;
            alwaysFriend = spec.alwaysFriend;
            Asleep = spec.asleep || spec.inactive;
            inactive = spec.inactive;
            if (spec.freighter)
            {
                obstacle = gameObject.AddComponent<GoF2Obstacle>();
                obstacle.projectFromVolume = false;
                obstacle.volumes = GoF2CollisionVolume.ForFreighter(spec.ship, spec.race);
                Target.boxes = LocalBoxes(obstacle.volumes);
            }
            Target.Damaged += OnDamaged;
            Target.Died += OnDied;
            lastHull = Hp.hull;
            if (!spec.freighter) smoke = new GoF2ShipSmoke(transform);

            if (!spec.freighter && spec.ship != 51)
            {
                var item = db.Item(GoF2NpcTables.GunItem(spec.race));
                if (item != null)
                {
                    gun = new GoF2Gun(item, GoF2NpcTables.GunDamage(spec.race), GoF2NpcTables.GunReloadMs, GoF2NpcTables.GunPool,
                                      GoF2NpcTables.GunLifetimeMs, GoF2NpcTables.GunSpeed) { owner = Target };
                    rig = new GoF2GunRig(gun, GoF2WeaponFx.Load(item.index), fxRoot, null, 2);
                    gun.Hit += OnGunHit;
                }
            }
            route = (spec.route ?? GoF2Route.DefaultPatrol(spec.race)).Clone();
            loot = spec.noLoot ? new List<GoF2Stack>() : GoF2NpcTables.RollLoot(db, spec.freighter);

            sfx = gameObject.AddComponent<AudioSource>();
            Setup3D(sfx);
            engine = gameObject.AddComponent<AudioSource>();
            Setup3D(engine);
            engine.loop = true;
            engine.clip = assets != null ? GoF2CombatAssets.Pick(spec.freighter ? assets.freighterEngines : assets.enemyEngines) : null;
            engine.volume = 0.6f * GoF2Settings.SfxVolume;
            if (engine.clip != null) engine.Play();

            if (spec.startsDead) SetDead();
        }

        static void Setup3D(AudioSource s)
        {
            s.playOnAwake = false;
            s.spatialBlend = 1f;
            s.rolloffMode = AudioRolloffMode.Linear;
            s.minDistance = 20f;
            s.maxDistance = 1500f;
            s.dopplerLevel = 0f;
        }

        /// <summary>The world-axis boxes as local hit boxes (GoF2Target.Contains) for the ship's fixed rotation.</summary>
        static Bounds[] LocalBoxes(List<GoF2CollisionVolume> volumes)
        {
            var inv = Quaternion.Inverse(GameForward);
            var list = new List<Bounds>();
            foreach (var v in volumes)
            {
                if (v.sphere) continue;
                var size = inv * (v.half * 2f);
                list.Add(new Bounds(inv * v.centre, new Vector3(Mathf.Abs(size.x), Mathf.Abs(size.y), Mathf.Abs(size.z))));
            }
            return list.ToArray();
        }

        /// <summary>KIPlayer::revive: full hull, new cargo, base speed, back on its route, at 'position' (Unity).</summary>
        public void Revive(Vector3 position)
        {
            gameObject.SetActive(true);
            transform.SetPositionAndRotation(position, GameForward);
            if (modelGo != null) { modelGo.SetActive(true); model.localRotation = Quaternion.identity; }
            if (wreck != null) Destroy(wreck);
            if (obstacle != null) obstacle.volumes = GoF2CollisionVolume.ForFreighter(Spec.ship, Spec.race);
            Target.Revive();
            lastHull = Hp.hull;
            damageSinceBoost = 0;
            damageByPlayer = 0;
            smoking = false;
            smoke?.Clear();
            Current = State.Fly;
            speed = GoF2NpcTables.BaseSpeed;
            boosting = panic = false;
            targetSpeed = 0f;
            jumpMs = 0f;
            attacking = false;
            targetIdx = -1;
            route = (Spec.route ?? GoF2Route.DefaultPatrol(Spec.race)).Clone();
            loot = GoF2NpcTables.RollLoot(db, Spec.freighter);
            crate = null;
            if (engine != null && engine.clip != null) engine.Play();
        }

        /// <summary>KIPlayer::setDead: inactive until relaunched.</summary>
        void SetDead()
        {
            Current = State.Dead;
            rig?.HideAll();
            smoking = false;
            smoke?.Clear();
            if (wreck != null) Destroy(wreck);
            gameObject.SetActive(false);
        }

        // ---- per frame -------------------------------------------------------------------------------------

        void Update()
        {
            float dtMs = Time.deltaTime * 1000f;
            if (dtMs <= 0f) return;
            if (gun != null)
            {
                gun.Update(dtMs, enemies, null);
                rig.UpdateVisuals(dtMs, Camera.main, transform.forward);
            }
            if (Current == State.Dead) { UpdateDead(dtMs); return; }
            if (Current == State.Dying) { UpdateSmoke(); UpdateDying(dtMs); return; }
            UpdateRelations();
            Hp.Update(dtMs);
            UpdateSmoke();
            if (Asleep) { UpdateSleep(); return; }
            if (Current == State.JumpingOut) { UpdateJumpOut(dtMs); return; }
            if (IsFreighter)
            {
                if (!Hp.empDisabled) transform.position += transform.forward * GoF2NpcTables.FreighterSpeed * dtMs * M;
                return;
            }
            reselectTimer += dtMs;
            boostTimer += dtMs;
            UpdateTargeting();
            if (IsJumper && followingWaypoint) { jumpMs += dtMs; if (jumpMs >= 20000f) { jumpMs = 0f; Current = State.JumpingOut; } }
            else jumpMs = 0f;
            UpdateBoost(dtMs);
            Steer(dtMs);
            Avoid(true, dtMs);
            Avoid(false, dtMs);
        }

        /// <summary>PlayerFighter::update 0xf1b0e..0xf1bc0: smoke and fire switch on when the hull drops below a third of its
        /// maximum and off when it is back at a third; only the crossings act.</summary>
        void UpdateSmoke()
        {
            if (smoke == null) return;
            bool low = Hp.hull < 0.33f * Hp.maxHull;
            if (low == smoking) return;
            smoking = low;
            smoke.SetEmitting(low);
        }

        /// <summary>§4.2: hostile / friend flags for the markers and the AI.</summary>
        void UpdateRelations()
        {
            int r = Race;
            bool alwaysHostile = r == GoF2Standing.Pirate || r == GoF2Standing.Void || r == GoF2Standing.Specter;
            bool hostile = alwaysHostile || GoF2Standing.IsEnemy(r);
            bool friend = !alwaysHostile && GoF2Standing.IsFriend(r);
            if (alwaysFriend) { hostile = false; friend = true; }
            if (turnedEnemy || alwaysEnemy) { hostile = true; friend = false; }
            Target.hostileToPlayer = hostile;
            Target.friendToPlayer = friend;
        }

        bool InBox(GoF2Target t)
        {
            var d = t.transform.position - transform.position;
            float r = GoF2NpcTables.DetectRange * M;
            return Mathf.Abs(d.x) < r && Mathf.Abs(d.y) < r && Mathf.Abs(d.z) < r;
        }

        static bool Valid(GoF2Target t) => t != null && t.Targetable;

        /// <summary>State 5 (sleeping): wakes when the player comes within +-25 000 per axis or any listed target within
        /// +-50 000; hostile sleepers stay hidden after the tutorial (PlayerFighter, index &gt; 1). An inactive ship only
        /// wakes by script.</summary>
        void UpdateSleep()
        {
            bool hide = Hidden;
            if (modelGo != null && modelGo.activeSelf == hide) modelGo.SetActive(!hide);
            Target.untargetable = true;
            if (inactive) return;
            foreach (var e in enemies)
            {
                if (!Valid(e)) continue;
                var d = e.transform.position - transform.position;
                float r = (e.isPlayer ? 25000f : 50000f) * M;
                if (Mathf.Abs(d.x) < r && Mathf.Abs(d.y) < r && Mathf.Abs(d.z) < r) { Wake(); return; }
            }
        }

        /// <summary>KIPlayer vtable +0x0c: awake (visible, flying, attacking).</summary>
        public void Wake()
        {
            Asleep = inactive = false;
            Target.untargetable = false;
            if (modelGo != null && Current == State.Fly) modelGo.SetActive(!forcedHidden);
        }

        /// <summary>Places the ship (Unity world position) facing 'forward'.</summary>
        public void Place(Vector3 position, Vector3 forward)
        {
            transform.SetPositionAndRotation(position, Quaternion.LookRotation(forward, Vector3.up));
        }

        /// <summary>§5.3 target selection.</summary>
        void UpdateTargeting()
        {
            int n = enemies.Count;
            int idx = targetIdx;
            if (idx >= n) idx = -1;
            if (!attacking) idx = -1;
            else if (idx >= 0 && !Valid(enemies[idx])) attacking = false;
            bool pirate = Race == GoF2Standing.Pirate;
            if (reselectTimer < 5001f)
            {
                if (!attacking)
                    for (int i = 0; i < n; i++)
                        if (Valid(enemies[i]) && ((!pirate && turnedEnemy) || InBox(enemies[i]))) { idx = i; attacking = true; break; }
            }
            else
            {
                drift = !drift && Random.Range(0, 100) < 20;
                reselectTimer = 0f;
                if (Random.Range(0, 100) < 30 && n > 1)
                {
                    attacking = false;
                    for (int k = 0; k < 5; k++)
                    {
                        int i = Random.Range(0, n);
                        if (Valid(enemies[i]) && ((!pirate && turnedEnemy) || InBox(enemies[i]))) { idx = i; attacking = true; break; }
                    }
                    if (!attacking) idx = 0;
                }
                else idx = 0;
                if (n > 0 && Valid(enemies[idx])) { if (!InBox(enemies[idx]) && !(turnedEnemy && idx == 0)) idx = -1; }
                else { idx = -1; attacking = false; }
            }
            if (!Target.hostileToPlayer && idx == 0) { idx = 1; attacking = false; }
            if (idx > 0)
            {
                idx = -1;
                for (int i = 1; i < n; i++)
                {
                    var e = enemies[i];
                    if (!Valid(e)) continue;
                    if (GoF2Standing.RacesHostile(Race, e.race)) { idx = i; attacking = true; break; }
                }
            }
            targetIdx = idx;
            followingWaypoint = false;
            target = null;
            if (idx < 0 || idx >= n)
            {
                var wp = route.Waypoint;
                if (wp == null) { target = null; targetPos = traffic.Player != null ? traffic.Player.transform.position : transform.position; }
                else { route.Update(ToGame(transform.position)); wp = route.Waypoint; targetPos = wp.HasValue ? ToUnity(wp.Value) : transform.position; followingWaypoint = true; }
            }
            else { target = enemies[idx]; targetPos = target.transform.position; }
        }

        Vector3 targetPos;

        /// <summary>§5.4 fire, turn, bank, move.</summary>
        void Steer(float dtMs)
        {
            var dir = targetPos - transform.position;
            if (target != null && !followingWaypoint)
            {
                float r = GoF2NpcTables.BreakOffRange * M;
                if (Mathf.Abs(dir.x) < r && Mathf.Abs(dir.y) < r && Mathf.Abs(dir.z) < r) dir = transform.right;
            }
            if (dir.sqrMagnitude < 1e-8f) dir = transform.forward;
            var dirN = dir.normalized;
            var local = transform.InverseTransformDirection(dirN);

            if (attacking && !followingWaypoint && target != null)
            {
                if (target.untargetable) attacking = false;
                else
                {
                    var d = targetPos - transform.position;
                    float fr = GoF2NpcTables.FireRange * M;
                    if (Mathf.Abs(local.x) < GoF2NpcTables.FireCone && Mathf.Abs(local.y) < GoF2NpcTables.FireCone
                        && Mathf.Abs(d.x) < fr && Mathf.Abs(d.y) < fr && Mathf.Abs(d.z) < fr)
                    {
                        if (gun == null || !target.Targetable) attacking = false;
                        else if (gun.TryFire(transform) >= 0)
                        {
                            var clip = assets != null && assets.shots != null && assets.shots.Length == 5 ? assets.shots[GoF2NpcTables.ShotSound(Race)] : null;
                            if (clip != null) sfx.PlayOneShot(clip, 0.8f * GoF2Settings.SfxVolume);
                        }
                    }
                }
            }

            var fwd = transform.forward;
            if (!drift && !Hp.empDisabled)
            {
                var delta = dirN - fwd;
                var h = delta.sqrMagnitude > 1e-10f ? (fwd + delta.normalized * (dtMs * 48f / 65536f)).normalized : dirN;
                var diff = h - dirN;
                if (Mathf.Abs(diff.x) + Mathf.Abs(diff.y) + Mathf.Abs(diff.z) < 0.0625f) h = dirN;
                float a = Mathf.Acos(Mathf.Clamp(Vector3.Dot(fwd, h), -1f, 1f));
                if (Vector3.Dot(transform.right, h) > 0f) a = -a;
                turnRing[ringIndex] = a * 33.3f / dtMs;   // per 30 fps frame, like the original's samples
                ringIndex = (ringIndex + 1) % turnRing.Length;
                if (ringFilled < turnRing.Length) ringFilled++;
                float avg = 0f;
                for (int i = 0; i < ringFilled; i++) avg += turnRing[i];
                avg /= ringFilled;
                bankTarget = Mathf.Clamp(avg * 750f * 15.139f, -750f, 750f);
                transform.rotation = Quaternion.LookRotation(h, transform.up);
            }
            else { bankTarget = 0f; ringFilled = 0; }

            // Bank toward the target at dt * 1.25 / 3.9 per ms; after 750 ms at the target the roll levels out.
            float step = dtMs * 1.25f / 3.9f;
            float before = bank;
            bank = Mathf.MoveTowards(bank, bankTarget, step);
            if (Mathf.Approximately(bank, before)) { levelTimer -= dtMs; if (levelTimer <= 0f) levelling = true; }
            else levelTimer = 750f;
            if (model != null) model.localRotation = Quaternion.AngleAxis(bank * Mathf.PI / 4096f * Mathf.Rad2Deg, Vector3.forward);
            if (levelling) Roll(dtMs);

            if (!Hp.empDisabled) transform.position += transform.forward * speed * dtMs * M;
        }

        /// <summary>PlayerFighter::roll: brings right.y to 0 with up.y > 0 at 0.00075 rad/ms (0.00025 near level).</summary>
        void Roll(float dtMs)
        {
            float rx = transform.right.y, uy = transform.up.y;
            if (Mathf.Abs(rx) < 0.015f && uy > 0f) { levelling = false; return; }
            float rate = uy < 0f || Mathf.Abs(rx) > 0.3f ? 0.00075f : 0.00025f;
            if (rx >= 0f) rate = -rate;
            transform.Rotate(0f, 0f, rate * Mathf.Min(dtMs, 60f) * Mathf.Rad2Deg, Space.Self);
        }

        /// <summary>§5.5 boost and panic.</summary>
        void UpdateBoost(float dtMs)
        {
            float frames = dtMs / 33.3f;
            if (Hp.hull < lastHull)
            {
                damageSinceBoost += lastHull - Hp.hull;
                lastHull = Hp.hull;
                if (damageSinceBoost >= 0.4f * Hp.maxHull) { damageSinceBoost = 0; boostTimer = 10000f; panic = true; }
            }
            if (boostTimer > 5000f && !boosting)
            {
                boostTimer = 0f;
                if (panic || Random.Range(0, 100) < 5)
                {
                    boostDuration = 5000f + Random.Range(0, 3000);
                    boosting = true;
                    targetSpeed = GoF2NpcTables.BoostSpeed;
                }
            }
            if (!boosting) return;
            if (boostTimer > boostDuration) { boostTimer = 0f; panic = false; targetSpeed = GoF2NpcTables.BaseSpeed; }
            if (targetSpeed <= 0f) return;
            speed *= Mathf.Pow(speed < targetSpeed ? 1.05f : 0.95f, frames);
            if (speed >= GoF2NpcTables.BoostSpeed || speed < GoF2NpcTables.BaseSpeed)
            {
                speed = targetSpeed;
                if (Mathf.Approximately(targetSpeed, GoF2NpcTables.BaseSpeed)) { boosting = false; targetSpeed = 0f; }
            }
        }

        /// <summary>§5.7 (PlayerFighter::update, +0x13a): the first landmark / ship whose volumes contain the fighter turns it
        /// away (direction += (away - fwd) * speed * 0.03, up = world up) and moves it one extra step.</summary>
        void Avoid(bool landmarks, float dtMs)
        {
            var all = GoF2Obstacle.All;
            var pos = transform.position;
            for (int i = 0; i < all.Count; i++)
            {
                var o = all[i];
                if (o == null || o.landmark != landmarks || !o.Active) continue;
                if (!o.Touches(pos, out int index)) continue;
                var p = o.ProjectionVector(pos, index);
                if (p == Vector3.zero) continue;
                var fwd = transform.forward;
                var dir = (fwd + (p - fwd) * speed * 0.03f).normalized;
                transform.rotation = Quaternion.LookRotation(dir, Vector3.up);
                transform.position += transform.forward * speed * dtMs * M;
                return;
            }
        }

        /// <summary>State 6: x1.1 per (30 fps) frame, gone above 100 u/ms.</summary>
        void UpdateJumpOut(float dtMs)
        {
            speed *= Mathf.Pow(1.1f, dtMs / 33.3f);
            transform.position += transform.forward * speed * dtMs * M;
            if (speed > 100f) SetDead();
        }

        // ---- combat ----------------------------------------------------------------------------------------

        void OnGunHit(int bullet, GoF2Target hit, Vector3 point)
        {
            float dmg = gun.damage;
            if (hit.isPlayer && !Target.hostileToPlayer) dmg = (int)(dmg * 0.2f);   // stray fire from a non-hostile ship
            hit.Damage(dmg, true, gun.bullets[bullet].velocity);
            rig.ShowImpact(point);
        }

        /// <summary>Player::damage friendly-fire bookkeeping (§4.5), hits by the player only.</summary>
        void OnDamaged(GoF2Target t, int dmg, bool byNpc)
        {
            if (byNpc || alwaysEnemy || Race == GoF2Standing.Void || Race == GoF2Standing.Specter) return;
            if (Target.hostileToPlayer && !turnedEnemy) return;
            if (Race != traffic.SystemRace && Race != traffic.AttackRace) return;
            damageByPlayer += dmg;
            bool hc = GoF2Session.IsExtreme;
            float max = Hp.maxHull;
            if (damageByPlayer > max * (hc ? 0.10f : 0.33f)) traffic.FriendTurnedEnemy(Race);
            if (damageByPlayer >= max * (hc ? 0.25f : 0.50f)) turnedEnemy = true;
            if (damageByPlayer >= max * (hc ? 0.40f : 0.66f)) traffic.AlarmAllFriends(Race, true);
        }

        /// <summary>Hull &lt; 1: the dying state (§5.10) / the freighter wreck (§6).</summary>
        void OnDied(GoF2Target t)
        {
            traffic.OnShipDied(this, !Target.killedByNpc);
            Current = State.Dying;
            deathDir = transform.forward;
            if (engine != null) engine.Stop();
            GoF2Sfx.PlayAt(assets != null ? GoF2CombatAssets.Pick(assets.shipDestroyed) : null, transform.position);
            if (IsFreighter)
            {
                dyingMs = 10000f;
                var wreckPrefab = assets != null && assets.wrecks != null && assets.wrecks.Length == 5
                    ? assets.wrecks[Spec.ship == 14 ? 4 : Race == 1 ? 1 : Race == 2 ? 2 : Race == 3 ? 3 : 0] : null;
                if (wreckPrefab != null && model != null)
                {
                    wreck = Instantiate(wreckPrefab, transform, false);
                    // The wreck meshes face the other way (the original turns them (0, pi, 0), which its wreck collision
                    // data has baked in, like the stations').
                    wreck.transform.localRotation = model.localRotation * Quaternion.Euler(0f, 180f, 0f);
                    float len = GoF2PartAnimation.PlayOnce(wreck);
                    if (len > 0f) dyingMs = len;
                    modelGo.SetActive(false);
                }
                DropCrate();
            }
            else
            {
                dyingMs = 1500f + Random.Range(0, 1500);
                spinAxis = new Vector3(Random.Range(0, 200) - 100, Random.Range(0, 200) - 100, Random.Range(0, 200) - 100).normalized;
            }
        }

        void UpdateDying(float dtMs)
        {
            float frames = dtMs / 33.3f;
            if (IsFreighter) transform.position += transform.forward * GoF2NpcTables.FreighterSpeed * dtMs * M;
            else
            {
                transform.Rotate(spinAxis, 0.05f * frames * Mathf.Rad2Deg, Space.World);
                transform.position += deathDir * speed * dtMs * M;
            }
            dyingMs -= dtMs;
            if (dyingMs > 0f) return;
            explosion = GoF2Explosion.Spawn(transform.position, IsFreighter ? (Spec.ship == 14 ? 8f : 6f) : 1f);
            Current = State.Dead;
            smoke?.SetEmitting(false);   // the end of the tumble: Explosion::start, smoke and fire off
            deadMs = 0f;
            if (obstacle != null) obstacle.volumes = GoF2CollisionVolume.ForWreck(Spec.ship, Race);   // setWreckedMeshId
            if (!IsFreighter) DropCrate();
        }

        void DropCrate()
        {
            if (loot.Count == 0 || assets == null) return;
            var prefab = assets.Crate(Race);
            var go = prefab != null ? Instantiate(prefab, transform.position, Random.rotation) : new GameObject("Crate");
            go.name = "Crate";
            crate = go.AddComponent<GoF2Crate>();
            crate.Setup(loot, Race);
            Target.crate = crate;
        }

        void UpdateDead(float dtMs)
        {
            deadMs += dtMs;
            if (IsFreighter && wreck != null) return;   // state 4: the wreck stays for the rest of the level
            if (deadMs > 300f)
            {
                if (modelGo != null && modelGo.activeSelf) modelGo.SetActive(false);
                if (wreck != null) Destroy(wreck);
            }
            bool exploded = explosion == null || explosion.Finished;
            if (exploded && crate == null && deadMs > 300f) SetDead();
        }
    }
}
