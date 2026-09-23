// GoF2Explosion.cs
// Explosion type 0 (Explosion::Explosion 0xb4a90, Reference/research/ship_combat.md 5.3): explosion_anim_lookat_alpha
// (+ its _add child), 4500 ms, always facing the camera, plus 3..9 explosion_debris_anim_add streaks (addFireStreaks:
// random rotation, scale 0.5..0.99), sound 18 or 19 at random. setScaling(s) scales it (freighter wrecks x6, the
// battleship x8). During the first 2000 ms it rumbles the camera: p = (1 - min(d, 30000) / 30000) * (1 - t / 2000)
// (Explosion::update 0xb5768 -> TargetFollowCamera::setRumblePercentage).

using GoF2Remake.Visuals;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public class GoF2Explosion : MonoBehaviour
    {
        const float M = 0.05f, RumbleMs = 2000f, RumbleRange = 30000f;

        Transform blast;
        float lengthMs = 4500f, ageMs;

        public float LengthMs => lengthMs;
        public bool Finished => ageMs >= lengthMs;

        /// <summary>Spawns a type-0 explosion (null when the combat assets are missing).</summary>
        public static GoF2Explosion Spawn(Vector3 position, float scale = 1f, bool sound = true)
        {
            var assets = GoF2CombatAssets.Load();
            if (assets == null || assets.explosion == null) return null;
            var root = new GameObject("Explosion");
            root.transform.position = position;
            var e = root.AddComponent<GoF2Explosion>();
            var b = Instantiate(assets.explosion, root.transform, false);
            b.transform.localScale *= scale;
            GoF2GunRig.StripForFx(b);
            e.blast = b.transform;
            float len = GoF2PartAnimation.PlayOnce(b);
            if (len > 0f) e.lengthMs = len;
            if (assets.debris != null)
            {
                int n = 3 + Random.Range(0, 7);
                for (int i = 0; i < n; i++)
                {
                    var d = Instantiate(assets.debris, root.transform, false);
                    d.transform.localRotation = Quaternion.Euler(Random.Range(0, 360), Random.Range(0, 360), 0f);
                    d.transform.localScale *= Random.Range(50, 100) * 0.01f * scale;
                    GoF2GunRig.StripForFx(d);
                    e.lengthMs = Mathf.Max(e.lengthMs, GoF2PartAnimation.PlayOnce(d));
                }
            }
            if (sound) GoF2Sfx.PlayAt(Random.value < 0.5f ? GoF2CombatAssets.Pick(assets.explosionBig) : GoF2CombatAssets.Pick(assets.explosionMid), position);
            return e;
        }

        void LateUpdate()
        {
            ageMs += Time.deltaTime * 1000f;
            var cam = Camera.main;
            if (cam != null && blast != null) blast.rotation = cam.transform.rotation;   // "_lookat" meshes
            if (cam != null && ageMs < RumbleMs)
            {
                float d = (cam.transform.position - transform.position).magnitude / M;
                float p = (1f - Mathf.Min(d, RumbleRange) / RumbleRange) * (1f - ageMs / RumbleMs);
                var chase = cam.GetComponent<GoF2ChaseCamera>();
                if (chase != null) chase.Rumble(p);
            }
            if (ageMs >= lengthMs + 200f) Destroy(gameObject);
        }
    }
}
