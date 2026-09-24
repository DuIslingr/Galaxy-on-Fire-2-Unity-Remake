// ChaseCamera.cs
// Damped third-person chase camera in the spirit of GoF2's TargetFollowCamera.
//
// Recovered facts:
//  * Two damping coefficients (position, rotation). In touch mode they are fixed:
//    0.005 and 0.006 (TargetFollowCamera::resetShipHandling).
//  * In mouse/controller mode they depend on handling h (setShipHandling):
//      a = (1 - 0.01h) * 0.015 + 0.003
//      b = 0.01h * 0.011 + 0.001
//    Which coefficient drives position vs rotation is my best reading, and the exact damping curve
//    (the original fits a polynomial to a damping function) is approximated here with exponentials.
//  * Boost widens the view (camera gets boost percentage and an 2..8 intensity).

using UnityEngine;

namespace GoF2Remake.Flight
{
    public class ChaseCamera : MonoBehaviour
    {
        public ShipController target;

        [Header("Placement (meters, ship local space)")]
        public Vector3 offset = new Vector3(0f, 2.5f, -9f);
        public Vector3 lookOffset = new Vector3(0f, 1f, 6f);

        [Header("Damping (per millisecond coefficients, like the original)")]
        public bool handlingDependent = false; // false = touch-mode constants
        public float positionCoefficient = 0.005f;
        public float rotationCoefficient = 0.006f;

        [Header("Turn offset: camera slides sideways while turning")]
        public float turnSlideMeters = 1.5f;

        [Header("Boost")]
        public float baseFov = 60f;
        public float boostFovAdd = 12f;

        Camera cam;
        Vector3 slide;
        float shakeMs, shakeUnits, rumble;

        /// <summary>TargetFollowCamera::hit / hitSmall: the camera position jitters rnd(2a) - a units per axis per frame
        /// ('ms' 1000 / a 6 when the player is hit, 50 / 2 per own shot).</summary>
        public void Shake(float ms, float amplitudeUnits)
        {
            if (ms >= shakeMs) { shakeMs = ms; shakeUnits = amplitudeUnits; }
        }

        /// <summary>TargetFollowCamera::setRumblePercentage (explosions, each frame): the look-at point jitters by
        /// p * (rnd(100) - 50) units per axis. The strongest caller this frame wins.</summary>
        public void Rumble(float p) => rumble = Mathf.Max(rumble, p);

        /// <summary>TargetFollowCamera on another object (the Liberator; the turret view): the camera sits at
        /// follow.TransformPoint(followOffset) looking at follow.TransformPoint(followLookOffset), world up unless
        /// followUsesUp; 'followRigid' snaps instead of easing. Null = behind the ship.</summary>
        [System.NonSerialized] public Transform follow;
        [System.NonSerialized] public Vector3 followOffset, followLookOffset;
        [System.NonSerialized] public bool followRigid, followUsesUp;
        /// <summary>A constant rumble on top (PlayerEgo::update: 0.2 while the Liberator is steered).</summary>
        [System.NonSerialized] public float constantRumble;

        void Awake() => cam = GetComponent<Camera>();

        void LateUpdate()
        {
            if (target == null) return;
            var ship = target.transform;
            var model = target.Model;
            float dtMs = Time.deltaTime * 1000f * TimeExtender.PlayerFactor;   // TargetFollowCamera gets the player's dt
            if (constantRumble > 0f) rumble = Mathf.Max(rumble, constantRumble);
            if (follow != null)
            {
                var fp = follow.TransformPoint(followOffset);
                var fr = Quaternion.LookRotation(follow.TransformPoint(followLookOffset) - fp, followUsesUp ? follow.up : Vector3.up);
                float k = followRigid ? 1f : 1f - Mathf.Exp(-0.01f * dtMs);
                transform.position = Vector3.Lerp(transform.position, fp, k);
                transform.rotation = Quaternion.Slerp(transform.rotation, fr, k);
                if (rumble > 0f)
                {
                    float j = rumble * 0.6f;
                    transform.rotation *= Quaternion.Euler(Random.Range(-j, j), Random.Range(-j, j), 0f);
                    rumble = 0f;
                }
                if (cam != null) cam.fieldOfView = GoF2Remake.Visuals.Aspect.VerticalFov(baseFov, cam.aspect);
                return;
            }

            float posK = positionCoefficient, rotK = rotationCoefficient;
            if (handlingDependent)
            {
                float h = model.Handling;
                posK = (1f - 0.01f * h) * 0.015f + 0.003f;
                rotK = 0.01f * h * 0.011f + 0.001f;
            }

            // Slide opposite to the turn, proportional to turn rate (approximation of the target offset).
            float maxRate = Mathf.Max(1f, 750f * model.Handling / 63f);
            Vector3 targetSlide = new Vector3(-model.YawRate / maxRate * turnSlideMeters,
                                              model.PitchRate / maxRate * turnSlideMeters * 0.5f, 0f);
            slide = Vector3.Lerp(slide, targetSlide, 1f - Mathf.Exp(-posK * dtMs));

            Vector3 desiredPos = ship.TransformPoint(offset + slide);
            Quaternion desiredRot = Quaternion.LookRotation(
                ship.TransformPoint(lookOffset) - desiredPos, ship.up);

            transform.position = Vector3.Lerp(transform.position, desiredPos, 1f - Mathf.Exp(-posK * dtMs));
            transform.rotation = Quaternion.Slerp(transform.rotation, desiredRot, 1f - Mathf.Exp(-rotK * dtMs));

            if (shakeMs > 0f)
            {
                shakeMs -= dtMs;
                float a = shakeUnits * target.metersPerUnit;
                transform.position += new Vector3(Random.Range(-a, a), Random.Range(-a, a), Random.Range(-a, a));
            }
            if (rumble > 0f)
            {
                // 50 units at the look-at point (about 690 units away) = about 4 degrees.
                var look = ship.TransformPoint(lookOffset);
                float j = rumble * 50f * target.metersPerUnit;
                look += new Vector3(Random.Range(-j, j), Random.Range(-j, j), Random.Range(-j, j));
                transform.rotation = Quaternion.LookRotation(look - transform.position, transform.up);
                rumble = 0f;
            }

            if (cam != null)
                cam.fieldOfView = GoF2Remake.Visuals.Aspect.VerticalFov(baseFov + boostFovAdd * model.BoostVisualPercent, cam.aspect);
        }

        /// <summary>Snap behind the ship (use after spawning / undocking).</summary>
        public void Snap()
        {
            if (target == null) return;
            var ship = target.transform;
            transform.position = ship.TransformPoint(offset);
            transform.rotation = Quaternion.LookRotation(ship.TransformPoint(lookOffset) - transform.position, ship.up);
            slide = Vector3.zero;
        }
    }
}
