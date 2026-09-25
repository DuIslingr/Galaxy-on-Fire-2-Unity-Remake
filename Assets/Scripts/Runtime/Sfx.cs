// Sfx.cs
// One-shot sound effects in space. Distances are kilometres, so instead of Unity's 3D rolloff the volume falls off
// linearly with the distance to the camera (the original plays FMOD events at the ship position when 3D sound is on).

using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public static class Sfx
    {
        public const float AudibleMeters = 3000f;   // silent beyond (60000 game units)
        /// <summary>An FMOD event's own volume (the FEV's LGCY data: lasers 0.13-0.29, engines 0.06-0.1, boosters 0.2) times
        /// this is the remake's source volume, matching the levels the remake's other sounds already play at.</summary>
        public const float EventGain = 4f;

        public static void PlayAt(AudioClip clip, Vector3 position, float volume = 1f)
        {
            if (clip == null) return;
            var cam = Camera.main;
            float d = cam != null ? Vector3.Distance(cam.transform.position, position) : 0f;
            float v = volume * Mathf.Clamp01(1f - d / AudibleMeters) * Settings.SfxVolume;
            if (v <= 0.01f) return;
            var go = new GameObject("Sfx " + clip.name);
            go.transform.position = position;
            var src = go.AddComponent<AudioSource>();
            src.clip = clip;
            src.volume = v;
            src.spatialBlend = 0f;
            src.Play();
            Object.Destroy(go, clip.length + 0.1f);
        }
    }
}
