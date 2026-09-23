// GoF2MenuCamera.cs
// Slow cinematic camera for the main menu background: orbits a target at a fixed distance with a gentle
// vertical bob and a subtle handheld-style drift. The original menu (mode-2 space level) just looks at a
// station; this keeps that idea but adds motion so the scene feels alive.

using UnityEngine;

namespace GoF2Remake.Visuals
{
    [DisallowMultipleComponent]
    public class GoF2MenuCamera : MonoBehaviour
    {
        public Transform target;
        [Tooltip("Offset from the target the camera looks at (metres, target space).")]
        public Vector3 lookOffset;
        public float distance = 250f;
        public float height = 40f;
        [Tooltip("Orbit speed in degrees per second.")]
        public float orbitSpeed = 1.5f;
        public float startAngle = 30f;
        [Tooltip("Vertical bob amplitude (metres) and period (seconds).")]
        public float bobAmplitude = 12f;
        public float bobPeriod = 40f;
        [Tooltip("Handheld drift: rotation noise in degrees.")]
        public float driftDegrees = 0.6f;
        public float driftSpeed = 0.08f;
        [Tooltip("Turns the view left so the target sits right of centre, clear of the menu column.")]
        public float framingYaw = 12f;
        [Tooltip("Vertical FOV at 16:9; adapted to other aspect ratios by GoF2Aspect.")]
        public float verticalFov16x9 = 50f;

        float angle;
        Camera cam;

        void OnEnable()
        {
            angle = startAngle;
            cam = GetComponent<Camera>();
        }

        /// <summary>Restarts the orbit at startAngle and moves the camera there now (spawners read its position).</summary>
        public void ResetOrbit()
        {
            angle = startAngle;
            if (cam == null) cam = GetComponent<Camera>();
            Place();
        }

        void LateUpdate()
        {
            angle += orbitSpeed * Time.deltaTime;
            Place();
        }

        void Place()
        {
            float aspect = cam != null ? cam.aspect : GoF2Aspect.Reference;
            if (cam != null) cam.fieldOfView = GoF2Aspect.VerticalFov(verticalFov16x9, aspect);
            if (target == null) return;
            float t = Time.time;
            float y = height + Mathf.Sin(t * 2f * Mathf.PI / Mathf.Max(1f, bobPeriod)) * bobAmplitude;
            var offset = Quaternion.Euler(0f, angle, 0f) * new Vector3(0f, 0f, -distance);
            var focus = target.TransformPoint(lookOffset);
            transform.position = target.position + offset + Vector3.up * y;

            var look = Quaternion.LookRotation(focus - transform.position, Vector3.up);
            var drift = Quaternion.Euler(
                (Mathf.PerlinNoise(t * driftSpeed, 0.1f) - 0.5f) * 2f * driftDegrees,
                (Mathf.PerlinNoise(0.3f, t * driftSpeed) - 0.5f) * 2f * driftDegrees,
                (Mathf.PerlinNoise(t * driftSpeed, 0.7f) - 0.5f) * driftDegrees);
            transform.rotation = look * Quaternion.Euler(0f, -framingYaw, 0f) * drift;
        }
    }
}
