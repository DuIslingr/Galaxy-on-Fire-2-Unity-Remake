// Explosion.cs
// The original's Explosion (Explosion::Explosion 0xb4a90, Reference/research/ship_combat.md 5.3, weapons_special.md 3.4):
//   type 0   explosion_anim_lookat_alpha (+ its _add child), 4500 ms, always facing the camera, plus 3..9
//            explosion_debris_anim_add streaks for ships (addFireStreaks: random rotation, scale 0.5..0.99; bombs and mines
//            have none), sound 18 or 19 at random (weapons: their own sound). setScaling(s) scales it (freighter wrecks
//            x6, the battleship x8, the Pirate Outposts x8)
//   type 7   explosion_emp_anim_lookat_add, 2000 ms (EMP bombs)
//   type 8-10 v_scattergun_000_explosion_lookat_anim_add (scatter guns), random roll 0..3.14 rad, scale 0.6..0.99 and
//            animation speed 0.7..1.29 (Explosion::setScaling / start)
//   type 11  the shock blast: sn_shock_blast_glow (camera-facing) + sn_shock_blast_sphere facing the ship's direction,
//            setScaling(50000), played at half speed
//   type 13  sn_fireworks_lookat_anim_add, setScaling(0.25)
// During the first 2000 ms it rumbles the camera: p = (1 - min(d, 30000) / 30000) * (1 - t / 2000)
// (Explosion::update 0xb5768 -> TargetFollowCamera::setRumblePercentage).

using System.Collections.Generic;
using GoF2Remake.Visuals;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public class Explosion : MonoBehaviour
    {
        const float M = 0.05f, RumbleMs = 2000f, RumbleRange = 30000f;

        readonly List<Transform> lookAt = new List<Transform>();
        float lengthMs = 4500f, ageMs;
        bool rumble = true;

        public float LengthMs => lengthMs;
        public bool Finished => ageMs >= lengthMs;

        /// <summary>Spawns a type-0 ship explosion (null when the combat assets are missing).</summary>
        public static Explosion Spawn(Vector3 position, float scale = 1f, bool sound = true)
        {
            var assets = CombatAssets.Load();
            var clip = sound && assets != null ? (Random.value < 0.5f ? CombatAssets.Pick(assets.explosionBig) : CombatAssets.Pick(assets.explosionMid)) : null;
            return Spawn(0, position, Vector3.forward, scale, clip, true);
        }

        /// <summary>An explosion of the given type; 'forward' orients the shock-blast sphere; 'debris' = the type-0 fire streaks.</summary>
        public static Explosion Spawn(int type, Vector3 position, Vector3 forward, float scale, AudioClip sound, bool debris)
        {
            var assets = CombatAssets.Load();
            if (assets == null) return null;
            var root = new GameObject($"Explosion {type}");
            root.transform.position = position;
            var e = root.AddComponent<Explosion>();
            e.lengthMs = 0f;
            float speed = 1f;
            switch (type)
            {
                case 7:
                    e.Add(assets.explosionEmp, scale, true, speed);
                    break;
                case 8: case 9: case 10:
                {
                    // Explosion::start: random roll and scale; setScaling: random animation speed.
                    speed = 0.7f + Random.Range(0, 60) / 100f;
                    var t = e.Add(assets.explosionScatter, scale * (0.6f + Random.Range(0, 40) / 100f), true, speed);
                    if (t != null) t.GetChild(0).localRotation = Quaternion.Euler(0f, 0f, Random.Range(0, 3141) / 1000f * Mathf.Rad2Deg);
                    break;
                }
                case 11:
                    e.Add(assets.shockGlow, 50000f * scale, true, 0.5f);
                    var sphere = e.Add(assets.shockSphere, 50000f * scale, false, 0.5f);
                    if (sphere != null) sphere.rotation = Quaternion.LookRotation(forward, Vector3.up);
                    break;
                case 13:
                    e.Add(assets.fireworksBurst, 0.25f * scale, true, speed);
                    break;
                default:
                    e.Add(assets.explosion, scale, true, speed);
                    if (debris && assets.debris != null)
                    {
                        int n = 3 + Random.Range(0, 7);
                        for (int i = 0; i < n; i++)
                        {
                            var d = Instantiate(assets.debris, root.transform, false);
                            d.transform.localRotation = Quaternion.Euler(Random.Range(0, 360), Random.Range(0, 360), 0f);
                            // addFireStreaks: 0.5..0.99, never scaled again (Explosion::setScaling 0xb4ee0 scales only the
                            // blast and its _add, the streaks just get its animation speed): a freighter's x6 made them huge lines.
                            d.transform.localScale *= Random.Range(50, 100) * 0.01f;
                            GunRig.StripForFx(d);
                            foreach (var a in d.GetComponentsInChildren<PartAnimation>(true)) a.applyMaterialChannels = true;   // fade as they stretch
                            e.lengthMs = Mathf.Max(e.lengthMs, PartAnimation.PlayOnce(d));
                        }
                    }
                    break;
            }
            if (e.lengthMs <= 0f) e.lengthMs = 2000f;
            e.rumble = type != 8 && type != 9 && type != 10;   // the scatter bursts are updated without a camera
            if (sound != null) Sfx.PlayAt(sound, position);
            return e;
        }

        /// <summary>One part: a pivot (for the camera-facing turn) holding the mesh, its animation at 'speed'.</summary>
        Transform Add(GameObject prefab, float scale, bool faceCamera, float speed)
        {
            if (prefab == null) return null;
            var pivot = new GameObject(prefab.name).transform;
            pivot.SetParent(transform, false);
            var go = Instantiate(prefab, pivot, false);
            go.transform.localScale *= scale;
            GunRig.StripForFx(go);
            foreach (var a in go.GetComponentsInChildren<PartAnimation>(true)) { a.speed = speed; a.applyMaterialChannels = true; }   // their `extra` fade-out
            float len = PartAnimation.PlayOnce(go) / Mathf.Max(0.05f, speed);
            lengthMs = Mathf.Max(lengthMs, len);
            if (faceCamera) lookAt.Add(pivot);
            return pivot;
        }

        void LateUpdate()
        {
            ageMs += Time.deltaTime * 1000f;
            var cam = Camera.main;
            if (cam != null) foreach (var t in lookAt) if (t != null) t.rotation = cam.transform.rotation;   // "_lookat" meshes
            if (rumble && cam != null && ageMs < RumbleMs)
            {
                float d = (cam.transform.position - transform.position).magnitude / M;
                float p = (1f - Mathf.Min(d, RumbleRange) / RumbleRange) * (1f - ageMs / RumbleMs);
                var chase = cam.GetComponent<ChaseCamera>();
                if (chase != null) chase.Rumble(p);
            }
            if (ageMs >= lengthMs + 200f) Destroy(gameObject);
        }
    }
}
