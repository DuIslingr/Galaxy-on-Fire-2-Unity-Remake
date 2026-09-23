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
        public float bankDegrees = 8f;
        public float bankPeriod = 14f;

        Vector3 startPos;
        Quaternion startRot;
        float travelled, wait;
        Renderer[] renderers;

        void Awake()
        {
            startPos = transform.position;
            startRot = transform.rotation;
            renderers = GetComponentsInChildren<Renderer>(true);
            wait = startDelay;
            SetVisible(wait <= 0f);
        }

        void Update()
        {
            if (wait > 0f)
            {
                wait -= Time.deltaTime;
                if (wait <= 0f) { travelled = 0f; SetVisible(true); }
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

        void SetVisible(bool on)
        {
            foreach (var r in renderers) if (r != null) r.enabled = on;
        }
    }
}
