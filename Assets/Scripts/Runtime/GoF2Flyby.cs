// GoF2Flyby.cs
// Background traffic for menus: flies an object along its forward axis at a constant speed with a slow
// banking sway, and restarts from its start point after 'length' metres (optionally after a pause).
// Ships in the original fly at 2 game units/ms (100 m/s at 0.05 m per unit); menu traffic uses a
// fraction of that so it reads well behind the UI.

using UnityEngine;

namespace GoF2Remake.Visuals
{
    [DisallowMultipleComponent]
    public class GoF2Flyby : MonoBehaviour
    {
        [Tooltip("Metres per second.")]
        public float speed = 40f;
        [Tooltip("Distance flown before restarting (metres).")]
        public float length = 1500f;
        [Tooltip("Seconds hidden before the next pass.")]
        public float pause = 6f;
        [Tooltip("Seconds of delay before the first pass.")]
        public float startDelay;
        [Tooltip("Fraction of the first pass already flown at start (0 = flies in from the start point).")]
        [Range(0f, 1f)] public float startProgress;
        public float bankDegrees = 8f;
        public float bankPeriod = 14f;

        /// <summary>Optional: picks a new lane (start, heading, length) before every pass, e.g. relative to a moving camera.</summary>
        public System.Func<(Vector3 start, Quaternion rotation, float length)> nextLane;

        Vector3 startPos;
        Quaternion startRot;
        float travelled, wait;
        Renderer[] renderers;

        void Start()   // not Awake: spawners set the fields right after AddComponent
        {
            startPos = transform.position;
            startRot = transform.rotation;
            NewLane();
            travelled = startProgress * length;   // first pass only: start part-way, already in view
            transform.SetPositionAndRotation(startPos + startRot * Vector3.forward * travelled, startRot);
            renderers = GetComponentsInChildren<Renderer>(true);
            wait = startDelay;
            SetVisible(wait <= 0f);
        }

        void Update()
        {
            if (wait > 0f)
            {
                wait -= Time.deltaTime;
                if (wait <= 0f) { travelled = 0f; NewLane(); SetVisible(true); }
                return;
            }
            travelled += speed * Time.deltaTime;
            float bank = Mathf.Sin(Time.time * 2f * Mathf.PI / Mathf.Max(1f, bankPeriod)) * bankDegrees;
            transform.SetPositionAndRotation(startPos + startRot * Vector3.forward * travelled, startRot * Quaternion.Euler(0f, 0f, bank));
            if (travelled >= length)
            {
                wait = Mathf.Max(0.01f, pause);
                SetVisible(false);
                transform.SetPositionAndRotation(startPos, startRot);
            }
        }

        void NewLane()
        {
            if (nextLane == null) return;
            var lane = nextLane();
            startPos = lane.start;
            startRot = lane.rotation;
            length = lane.length;
            transform.SetPositionAndRotation(startPos, startRot);
        }

        void SetVisible(bool on)
        {
            foreach (var r in renderers) if (r != null) r.enabled = on;
        }
    }
}
