// PlayerCollision.cs
// PlayerEgo::calcCollision 0xab550 (Reference/research/ship_combat.md 2.9), on the player ship. Runs after the ship has
// moved each frame, like PlayerEgo::update, over the landmarks, then the NPC ships, then the asteroids:
//   station, jumpgate, freighters (Obstacle)   the ship is put on the surface of the volumes it is inside
//                                              (projectCollisionOnSurface) and keeps flying, so it slides along them;
//                                              camera hit() (shake 1000 ms, +-6 units); no damage
//   NPC fighters                               none: the player flies through them (they have no volumes)
//   asteroids                                  the asteroid is destroyed (damage 9999, normal death), the player takes
//                                              20 (shield -> armor -> hull), camera hit(); no push
// Collision is off during the launch / arrival camera and the jump scenes (PlayerEgo+0x144, set by the level), while
// mining (PlayerEgo+0x356 with a mining phase 1-3) and once dead.
// The 1000 ms jitter of the ship model after a hit (PlayerEgo+0x328 / +0x32c, +-0.006 units) is too small to see and
// isn't reproduced.

using System;
using UnityEngine;

namespace GoF2Remake.Flight
{
    [DefaultExecutionOrder(50)]   // after ShipController has moved the ship
    public class PlayerCollision : MonoBehaviour
    {
        /// <summary>Set by the level each frame: launch / arrival camera, jump scenes (collision off).</summary>
        [NonSerialized] public bool off;
        /// <summary>Set by the level: the autopilot flies into the jumpgate's sphere to use it (SystemJump).</summary>
        [NonSerialized] public bool ignoreGate;
        /// <summary>This frame the ship touched the station (MGame::dockEvent: with the autopilot to it, that docks).</summary>
        public bool TouchingStation { get; private set; }

        PlayerHealth health;
        ChaseCamera chase;
        Mining mining;

        public void Setup(PlayerHealth playerHealth, ChaseCamera chaseCamera, Mining miningSystem)
        {
            health = playerHealth;
            chase = chaseCamera;
            mining = miningSystem;
        }

        void Update()
        {
            TouchingStation = false;
            if (off || health == null || health.Dead) return;
            if (mining != null && mining.State != Mining.Phase.Idle) return;
            CheckObstacles(true);
            CheckObstacles(false);
            CheckAsteroids();
        }

        void Hit()
        {
            if (chase != null && chase.enabled) chase.Shake(1000f, 6f);   // TargetFollowCamera::hit
        }

        void CheckObstacles(bool landmarks)
        {
            var all = Obstacle.All;
            for (int i = 0; i < all.Count; i++)
            {
                var o = all[i];
                if (o == null || o.landmark != landmarks || !o.Active) continue;
                if (ignoreGate && o.cubeIsContact) continue;
                var pos = transform.position;
                if (!o.Touches(pos, out _)) continue;
                transform.position = o.PushOut(pos);
                if (o.isStation) TouchingStation = true;
                Hit();
            }
        }

        /// <summary>The asteroid part: the asteroid is destroyed, the player takes 20.</summary>
        void CheckAsteroids()
        {
            var pos = transform.position;
            var all = Target.All;
            for (int i = all.Count - 1; i >= 0; i--)
            {
                var t = all[i];
                if (t == null || !t.isAsteroid || !t.Alive) continue;
                if (!t.Contains(pos)) continue;
                t.Damage(9999f);
                if (!health.invulnerable) health.Target.Damage(20f);
                Hit();
            }
        }
    }
}
