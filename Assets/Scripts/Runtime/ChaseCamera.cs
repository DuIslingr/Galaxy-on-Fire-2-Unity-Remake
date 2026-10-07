// ChaseCamera.cs
// Damped third-person chase camera in the spirit of GoF2's TargetFollowCamera.
//
// Recovered facts:
//  * Two damping coefficients (TargetFollowCamera::update 0x186e40): +0x12c eases the camera position, +0x128 the
//    look-at point. Fixed 0.006 / 0.005 (TargetFollowCamera::resetShipHandling) except with the mouse cursor (PlayerEgo
//    ::update, Globals::mouseCursorActivated), where they depend on handling h (setShipHandling):
//      position  0.01h * 0.011 + 0.001        look-at  (1 - 0.01h) * 0.015 + 0.003
//    The exact damping curve (aproximateCooefficients..., a polynomial in dt) is approximated with exponentials.
//  * Boost (MGame::OnUpdate): the vertical FOV grows by 0.35 rad x the boost percentage, and
//    TargetFollowCamera::setBoostPercentage(pct, clamp(boost speed, 2, 8)) jitters the look-at point by
//    pct x n units per axis each frame. The radial blur on top (post effect 0x1400002) isn't reproduced.

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
        public float positionCoefficient = 0.006f;
        public float rotationCoefficient = 0.005f;

        [Header("Turn offset: camera slides sideways while turning")]
        public float turnSlideMeters = 1.5f;
        [Tooltip("Share of the original's dodge target offset (-3 x the yaw rate) the camera takes; 1 = as decoded (too wide at this scale).")]
        public float dodgeOffsetScale = 0.25f;
        [Tooltip("Share of the dodge's sideways move the camera takes back each frame (translateNoUpdate(-0.9 x the slide)).")]
        public float dodgeLag = 0.9f;

        [Header("Boost")]
        public float baseFov = 60f;
        [Tooltip("Degrees added at full boost: MGame::OnUpdate's 0.35 rad x the boost percentage.")]
        public float boostFovAdd = 20.05f;

        Camera cam;
        Vector3 slide;
        float shakeMs, shakeUnits, rumble;
        bool wasBoosting;

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
        /// <summary>A level script's look-at camera (CutsceneCamera) holds the camera: the launch / arrival camera leaves it
        /// alone and doesn't hand it back (LevelScript: M0 / M1 never end the fly-in, their scripts own the camera).</summary>
        [System.NonSerialized] public bool scriptCamera;

        void Awake() => cam = GetComponent<Camera>();

        void LateUpdate()
        {
            if (target == null) return;
            var ship = target.transform;
            var model = target.Model;
            float dtMs = Time.deltaTime * 1000f * TimeExtender.PlayerFactor;   // TargetFollowCamera gets the player's dt
            // TargetFollowCamera::update 0x186e40 does everything inside `if (0 < dt)`: paused, the camera neither follows,
            // shakes nor rumbles (the shake timer would never run out, the jitter piled up every frame).
            if (dtMs <= 0f) { rumble = 0f; return; }
            // Last frame's engine sway comes off first, so it never feeds into the easing below.
            if (lastSway != Quaternion.identity) { transform.rotation *= Quaternion.Inverse(lastSway); lastSway = Quaternion.identity; }
            if (constantRumble > 0f) rumble = Mathf.Max(rumble, constantRumble);
            // Remake: the same rumble on the controller / phone (Haptics; its own option, not the camera shake's): explosions,
            // the Liberator, the boost below; the boost's start as a pulse.
            bool boosting = model.IsBoosting;
            if (boosting && !wasBoosting) Haptics.Play(Haptics.Boost);
            wasBoosting = boosting;
            float boostRumble = boosting ? model.BoostVisualPercent * Mathf.Clamp(model.CurrentSpeed, 2f, 8f) / 50f : 0f;
            // Remake debug: a heavy hull's engines (ShipController.mass): how hard they work = the gap between the speed and
            // the one the throttle asks for (FlightModel.MoveSpeed eases toward it), plus the boost.
            float mass = target.mass;
            float strain = mass > 0f ? Mathf.Clamp01(Mathf.Abs((model.Braking ? 0f : model.Throttle * model.CurrentSpeed) - model.MoveSpeed) / FlightModel.BaseSpeed) : 0f;
            float engineRumble = mass * (0.06f + 0.25f * strain + 0.3f * model.BoostVisualPercent);
            Haptics.Rumble(Mathf.Max(rumble, Mathf.Max(boostRumble, engineRumble)));
            rumble *= GoF2Remake.Data.Settings.CameraShake;   // the camera shake option
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

            // VR: the camera is the pilot's seat (Vr.VrCockpit), rigidly with the ship: no lag, slide, shake or boost zoom.
            if (GoF2Remake.Vr.VrMode.Enabled)
            {
                transform.SetPositionAndRotation(ship.TransformPoint(GoF2Remake.Vr.VrCockpit.Seat), ship.rotation);
                rumble = 0f;
                shakeMs = 0f;
                if (cam != null) cam.fieldOfView = GoF2Remake.Visuals.Aspect.VerticalFov(baseFov, cam.aspect);
                return;
            }

            float posK = positionCoefficient, rotK = rotationCoefficient;
            if (handlingDependent)
            {
                float h = model.Handling;
                posK = 0.01f * h * 0.011f + 0.001f;
                rotK = (1f - 0.01f * h) * 0.015f + 0.003f;
            }
            if (mass > 0f) { posK *= Mathf.Lerp(1f, 0.35f, mass); rotK *= Mathf.Lerp(1f, 0.35f, mass); }   // a heavy, unhurried follow

            // Slide opposite to the turn, proportional to turn rate (approximation of the target offset).
            float maxRate = Mathf.Max(1f, 750f * model.Handling / 63f);
            Vector3 targetSlide = new Vector3(-model.YawRate / maxRate * turnSlideMeters,
                                              model.PitchRate / maxRate * turnSlideMeters * 0.5f, 0f);
            // PlayerEgo::updateManeuver: during a dodge the target offset's x is -3 x the yaw rate (game units; the game's
            // +x is the ship's left, the remake's -x), y and z kept. Taken literally that swings the camera ~45 m (about
            // 30 deg) at the peak here, far more than the dodge looks like: scaled by dodgeOffsetScale (tuned by eye).
            if (target.Maneuver.Active) targetSlide = new Vector3(3f * dodgeOffsetScale * model.YawRate * target.metersPerUnit, 0f, 0f);
            slide = Vector3.Lerp(slide, targetSlide, 1f - Mathf.Exp(-posK * dtMs));

            Vector3 desiredPos = ship.TransformPoint(offset + slide);
            Quaternion desiredRot = Quaternion.LookRotation(
                ship.TransformPoint(lookOffset) - desiredPos, ship.up);

            transform.position = Vector3.Lerp(transform.position, desiredPos, 1f - Mathf.Exp(-posK * dtMs));
            // ... and translateNoUpdate(-0.9 x the slide) every frame: the camera takes back most of the sideways move,
            // so the ship visibly slides across the view and the camera catches up afterwards.
            transform.position -= dodgeLag * target.ManeuverSlide;
            transform.position += target.StrafeSlide;   // handleShip: translateNoUpdate by the strafe, the camera keeps its place
            transform.rotation = Quaternion.Slerp(transform.rotation, desiredRot, 1f - Mathf.Exp(-rotK * dtMs));

            if (shakeMs > 0f)
            {
                shakeMs -= dtMs;
                float a = shakeUnits * target.metersPerUnit * GoF2Remake.Data.Settings.CameraShake;
                transform.position += new Vector3(Random.Range(-a, a), Random.Range(-a, a), Random.Range(-a, a));
            }
            if (boosting)
                rumble = Mathf.Max(rumble, boostRumble * GoF2Remake.Data.Settings.CameraShake);
            if (rumble > 0f)
            {
                // 50 units at the look-at point (about 690 units away) = about 4 degrees.
                var look = ship.TransformPoint(lookOffset);
                float j = rumble * 50f * target.metersPerUnit;
                look += new Vector3(Random.Range(-j, j), Random.Range(-j, j), Random.Range(-j, j));
                transform.rotation = Quaternion.LookRotation(look - transform.position, transform.up);
                rumble = 0f;
            }

            if (mass > 0f)
            {
                // The engine sway: a slow drift of the view (degrees), stronger while the engines strain and boost. The
                // jitters above are in game units at the look-at point, which a capital ship's camera, hundreds of metres
                // out, hardly shows.
                swaySeconds += dtMs / 1000f;
                float amp = mass * (0.12f + 0.5f * strain + 0.6f * model.BoostVisualPercent) * GoF2Remake.Data.Settings.CameraShake;
                if (amp > 0f)
                {
                    float s = swaySeconds * 0.6f;
                    lastSway = Quaternion.Euler((Mathf.PerlinNoise(s, 3.1f) - 0.5f) * 2f * amp, (Mathf.PerlinNoise(7.7f, s) - 0.5f) * 2f * amp,
                                                (Mathf.PerlinNoise(s * 0.7f, 11.3f) - 0.5f) * amp);
                    transform.rotation *= lastSway;
                }
            }
            if (cam != null)   // a heavy hull's boost pushes the view out less (it gathers speed slowly anyway)
                cam.fieldOfView = GoF2Remake.Visuals.Aspect.VerticalFov(baseFov + boostFovAdd * model.BoostVisualPercent * Mathf.Lerp(1f, 0.5f, mass), cam.aspect);
        }

        Quaternion lastSway = Quaternion.identity;
        float swaySeconds;

        /// <summary>Snap behind the ship (use after spawning / undocking).</summary>
        public void Snap()
        {
            if (target == null) return;
            var ship = target.transform;
            transform.position = ship.TransformPoint(offset);
            transform.rotation = Quaternion.LookRotation(ship.TransformPoint(lookOffset) - transform.position, ship.up);
            if (GoF2Remake.Vr.VrMode.Enabled) transform.SetPositionAndRotation(ship.TransformPoint(GoF2Remake.Vr.VrCockpit.Seat), ship.rotation);
            slide = Vector3.zero;
            lastSway = Quaternion.identity;
        }

        // Another camera script (free look, a cutscene) sets the rotation meanwhile: nothing of the sway to take off after it.
        void OnDisable() => lastSway = Quaternion.identity;
    }
}
