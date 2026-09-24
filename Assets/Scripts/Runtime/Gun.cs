// Gun.cs
// One weapon on one mount, like the original's Gun (Reference/research/weapons.md): a fixed pool of bullets,
// a reload timer, straight flight along the ship's nose (no convergence, no lead, no aim assist), and the
// original's hit test. Plain C#: WeaponSystem feeds it the ship pose and targets and draws the bullets.
//   Gun::shootAt 0x17d518   spawn at ship + R * (mount + (0, 0, 100)), velocity = R * forward * speed, spread
//   Gun::update 0x17e940    reload += dt; bullets move; lifetime = attr 12 ms ("range" is a time); rockets and
//                           missiles coast and still hit for 2000 ms after their lifetime
//   Gun::calcCharacterCollision 0x17e154  axis-aligned cube |target - bullet + vel| < radius on every axis
//   RocketGun::seekEnemy 0x18bd70  missiles steer 1/6 of the error per (30 fps) frame toward the locked target
//   Level::assignGuns 0xcb638  NPC guns: 4 bullets, 16 u/ms, 3000 ms, the race's reload and damage, mount at the ship
//                           centre (the item only gives the look); 'owner' is never hit by its own bullets
// Units: positions in Unity metres, times in ms, velocities in metres per ms (game speed u/ms * 0.05).

using System;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public class Gun
    {
        public enum Kind { Laser = 0, Blaster = 1, AutoCannon = 2, Thermo = 3, Rocket = 4, Missile = 5, ScatterGun = 25, ClusterMissile = 40 }

        public struct Bullet
        {
            public Vector3 position, velocity, up;
            public float timer;        // ms left; <= limit = free
            public bool Active(float limit) => timer > limit;
        }

        public const float MetersPerUnit = 0.05f;
        const float CoastMs = 2000f;          // rockets/missiles keep flying (and hitting) past their lifetime
        const float SpawnForwardUnits = 100f; // offset = mount + (0, 0, 100)

        public readonly int itemIndex;
        public readonly Kind kind;
        public readonly int categoryId;
        public float damage;
        /// <summary>EMP per hit (attr 10); settable for the wingmen's Dia EMP Mk III.</summary>
        public float emp;
        public readonly float reloadMs, lifetimeMs, speedUnitsPerMs;
        public readonly Vector3 mountLocal;   // Unity metres, ship space
        public readonly Bullet[] bullets;
        public readonly bool isSecondary;
        /// <summary>The ship carrying the gun (never hit by it).</summary>
        public Target owner;
        public float reloadAcc;               // ms since the last shot
        public float spreadError;             // Gun+0xe0: 2 auto-cannon/scatter, 20 thermo, 0 otherwise

        /// <summary>Raised when a bullet hits: (bullet index, target, hit point).</summary>
        public event Action<int, Target, Vector3> Hit;

        public bool Homing => kind == Kind.Missile || kind == Kind.ClusterMissile || kind == Kind.Thermo;
        bool Coasts => kind == Kind.Rocket || kind == Kind.Missile || kind == Kind.ClusterMissile;
        float FreeLimit => Coasts ? -CoastMs : 0f;
        public bool Ready => reloadAcc > reloadMs;

        public Gun(ItemData item, Vector3 mountLocal, bool secondary)
        {
            itemIndex = item.index;
            categoryId = item.categoryId;
            kind = (Kind)item.categoryId;
            isSecondary = secondary;
            damage = item.Stat("damage");
            emp = item.Stat("empDamage");
            reloadMs = Mathf.Max(1, item.Stat("loadingTimeMs", 500));
            lifetimeMs = item.Stat("range", 2000);
            speedUnitsPerMs = item.Stat("projectileSpeed", 20);
            this.mountLocal = mountLocal;
            // Level::createGun: pool sizes and spread per sort.
            int pool = kind switch
            {
                Kind.AutoCannon or Kind.ScatterGun => 25,
                Kind.Rocket or Kind.Missile or Kind.ClusterMissile => 5,
                _ => 20,
            };
            spreadError = kind switch { Kind.AutoCannon or Kind.ScatterGun => 2f, Kind.Thermo => 20f, _ => 0f };
            bullets = new Bullet[pool];
            for (int i = 0; i < pool; i++) bullets[i].timer = -1e9f;
            reloadAcc = reloadMs + 1f;   // ready at start
        }

        /// <summary>Level::assignGuns: an NPC gun with the look of 'visualItem' and the generic NPC stats.</summary>
        public Gun(ItemData visualItem, float damage, float reloadMs, int pool, float lifetimeMs, float speedUnitsPerMs)
        {
            itemIndex = visualItem.index;
            categoryId = visualItem.categoryId;
            kind = (Kind)visualItem.categoryId;
            this.damage = damage;
            this.reloadMs = Mathf.Max(1f, reloadMs);
            this.lifetimeMs = lifetimeMs;
            this.speedUnitsPerMs = speedUnitsPerMs;
            mountLocal = Vector3.zero;
            bullets = new Bullet[pool];
            for (int i = 0; i < pool; i++) bullets[i].timer = -1e9f;
            reloadAcc = UnityEngine.Random.Range(0f, this.reloadMs);
        }

        public bool IsActive(int i) => bullets[i].Active(FreeLimit);

        /// <summary>Gun::shootAt: returns the bullet index, or -1 when reloading or the pool is exhausted.</summary>
        public int TryFire(Transform ship)
        {
            if (!Ready) return -1;
            int free = -1;
            for (int i = 0; i < bullets.Length; i++) if (bullets[i].timer <= FreeLimit) { free = i; break; }
            if (free < 0) return -1;

            var dir = Vector3.forward;
            if (spreadError > 0f)
            {
                // each axis += rnd(int(err)) * 0.01 - err * 0.005, i.e. uniform in [-err/200, err/200)
                float e = spreadError;
                dir += new Vector3(UnityEngine.Random.Range(0, (int)e) * 0.01f - e * 0.005f,
                                   UnityEngine.Random.Range(0, (int)e) * 0.01f - e * 0.005f, 0f);
            }
            ref var b = ref bullets[free];
            b.position = ship.TransformPoint(mountLocal + Vector3.forward * SpawnForwardUnits * MetersPerUnit);
            b.velocity = ship.TransformDirection(dir.normalized) * speedUnitsPerMs * MetersPerUnit;
            b.up = ship.up;
            b.timer = lifetimeMs;
            reloadAcc = 0f;
            return free;
        }

        /// <summary>Gun::update: move bullets, home missiles, test hits. 'lockTarget' may be null.</summary>
        public void Update(float dtMs, System.Collections.Generic.IReadOnlyList<Target> targets, Target lockTarget)
        {
            reloadAcc += dtMs;
            float limit = FreeLimit;
            // Missiles: 1/6 of the error per 33 ms frame, made frame-rate independent.
            float steer = Homing && lockTarget != null && lockTarget.Alive ? 1f - Mathf.Pow(5f / 6f, dtMs / 33.3f) : 0f;
            for (int i = 0; i < bullets.Length; i++)
            {
                ref var b = ref bullets[i];
                if (b.timer <= limit) continue;
                if (steer > 0f)
                {
                    float speed = b.velocity.magnitude;
                    var desired = (lockTarget.transform.position - b.position).normalized;
                    var cur = b.velocity / Mathf.Max(speed, 1e-6f);
                    b.velocity = Vector3.Normalize(cur + (desired - cur) * steer) * speed;
                }
                b.timer -= dtMs;
                b.position += b.velocity * dtMs;
                if (targets != null) TestHits(i, ref b, targets);
            }
        }

        void TestHits(int i, ref Bullet b, System.Collections.Generic.IReadOnlyList<Target> targets)
        {
            for (int t = 0; t < targets.Count; t++)
            {
                var target = targets[t];
                if (target == null || target == owner || !target.Alive) continue;
                if (!target.Contains(b.position - b.velocity)) continue;   // |target - bullet + vel| < r, like the original
                var point = b.position;
                b.timer = -1e9f;   // gone
                Hit?.Invoke(i, target, point);
                return;
            }
        }

        /// <summary>Render scale: projectiles shrink linearly over their last 1000 ms (ObjectGun); rockets and
        /// missiles keep their size while coasting (the original's scale goes negative there).</summary>
        public float VisualScale(int i) => Coasts ? 1f : Mathf.Clamp01(bullets[i].timer / 1000f);
    }
}
