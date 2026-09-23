// GoF2GunRig.cs
// The visuals of one GoF2Gun (weapons.md 5): a projectile instance per bullet slot (ObjectGun), the muzzle flash on the
// mount, a small pool of impact effects. Plain C#, shared by the player's GoF2WeaponSystem and the NPC ships.
// Blasters and thermo guns face the camera; lasers, cannons and rockets point along their flight. Projectiles shrink over
// their last 1000 ms (GoF2Gun.VisualScale). Effects never cast shadows or cull by LOD.

using GoF2Remake.Visuals;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public class GoF2GunRig
    {
        public readonly GoF2Gun gun;
        public readonly GoF2WeaponFx fx;
        readonly Transform[] projectiles;
        readonly bool billboard;
        readonly GameObject muzzle;
        readonly float muzzleLength;
        float muzzleMs;
        readonly GameObject[] impacts;
        readonly float[] impactMs;
        readonly float impactLength;
        int nextImpact;

        /// <param name="fxRoot">Parent of the projectiles and impacts (world space).</param>
        /// <param name="muzzleParent">The ship (null = no muzzle flash).</param>
        public GoF2GunRig(GoF2Gun gun, GoF2WeaponFx fx, Transform fxRoot, Transform muzzleParent, int impactPool = 4)
        {
            this.gun = gun;
            this.fx = fx;
            billboard = gun.kind == GoF2Gun.Kind.Blaster || gun.kind == GoF2Gun.Kind.Thermo;
            projectiles = new Transform[gun.bullets.Length];
            if (fx != null && fx.projectile != null)
                for (int i = 0; i < projectiles.Length; i++)
                {
                    var go = Object.Instantiate(fx.projectile, fxRoot);
                    go.name = $"{fx.projectile.name} {i}";
                    StripForFx(go);
                    go.SetActive(false);
                    projectiles[i] = go.transform;
                }
            if (fx != null && fx.muzzleFlash != null && muzzleParent != null)
            {
                muzzle = Object.Instantiate(fx.muzzleFlash, muzzleParent, false);
                muzzle.transform.localPosition = gun.mountLocal;
                StripForFx(muzzle);
                muzzleLength = Mathf.Max(80f, MaxLength(muzzle));
                muzzle.SetActive(false);
            }
            if (fx != null && fx.impact != null && impactPool > 0)
            {
                impacts = new GameObject[impactPool];
                impactMs = new float[impactPool];
                for (int i = 0; i < impactPool; i++)
                {
                    impacts[i] = Object.Instantiate(fx.impact, fxRoot);
                    StripForFx(impacts[i]);
                    impacts[i].SetActive(false);
                }
                impactLength = Mathf.Max(200f, MaxLength(impacts[0]));
            }
        }

        public static float MaxLength(GameObject go)
        {
            float l = 0f;
            foreach (var a in go.GetComponentsInChildren<GoF2PartAnimation>(true)) l = Mathf.Max(l, a.LengthMs);
            return l;
        }

        public static void StripForFx(GameObject go)
        {
            foreach (var r in go.GetComponentsInChildren<Renderer>(true))
            {
                r.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
                r.receiveShadows = false;
            }
            foreach (var lg in go.GetComponentsInChildren<LODGroup>(true)) lg.enabled = false;
        }

        /// <summary>A shot left the gun: the muzzle flash.</summary>
        public void OnShot()
        {
            if (muzzle == null) return;
            muzzle.SetActive(true);
            GoF2PartAnimation.PlayOnce(muzzle);
            muzzleMs = muzzleLength;
        }

        /// <summary>A bullet hit something at 'point'.</summary>
        public void ShowImpact(Vector3 point)
        {
            if (impacts == null) return;
            int i = nextImpact;
            nextImpact = (nextImpact + 1) % impacts.Length;
            var go = impacts[i];
            go.SetActive(true);
            go.transform.position = point;
            GoF2PartAnimation.PlayOnce(go);
            impactMs[i] = impactLength;
        }

        public void UpdateVisuals(float dtMs, Camera cam, Vector3 fallbackForward)
        {
            for (int i = 0; i < projectiles.Length; i++)
            {
                var t = projectiles[i];
                if (t == null) continue;
                bool active = gun.IsActive(i);
                if (t.gameObject.activeSelf != active) t.gameObject.SetActive(active);
                if (!active) continue;
                ref var b = ref gun.bullets[i];
                var rot = billboard && cam != null
                    ? cam.transform.rotation
                    : Quaternion.LookRotation(b.velocity.sqrMagnitude > 1e-9f ? b.velocity : fallbackForward, b.up);
                t.SetPositionAndRotation(b.position, rot);
                t.localScale = Vector3.one * gun.VisualScale(i);
            }
            if (muzzle != null && muzzleMs > 0f)
            {
                muzzleMs -= dtMs;
                if (muzzleMs <= 0f) muzzle.SetActive(false);
            }
            if (impacts != null)
                for (int i = 0; i < impacts.Length; i++)
                {
                    if (impactMs[i] <= 0f) continue;
                    impactMs[i] -= dtMs;
                    if (impactMs[i] <= 0f) impacts[i].SetActive(false);
                    else if (cam != null) impacts[i].transform.rotation = cam.transform.rotation;   // "_lookat" meshes
                }
        }

        /// <summary>Hides every projectile (a dead or sleeping ship).</summary>
        public void HideAll()
        {
            foreach (var t in projectiles) if (t != null) t.gameObject.SetActive(false);
            for (int i = 0; i < gun.bullets.Length; i++) gun.bullets[i].timer = -1e9f;
        }
    }
}
