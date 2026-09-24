// Aspect.cs
// Field of view across aspect ratios. FOVs are authored for 16:9. Wider screens (21:9, 32:9) keep that
// vertical FOV and see more to the sides (Hor+); narrower ones (4:3, 16:10) widen the vertical FOV so the
// horizontal view never shrinks below the 16:9 one. The game is landscape only.

using UnityEngine;

namespace GoF2Remake.Visuals
{
    public static class Aspect
    {
        public const float Reference = 16f / 9f;

        public static float VerticalFov(float verticalFovAt16x9, float aspect, float maxVertical = 110f)
        {
            if (aspect >= Reference || aspect <= 0f) return verticalFovAt16x9;
            float halfH = Mathf.Atan(Mathf.Tan(verticalFovAt16x9 * 0.5f * Mathf.Deg2Rad) * Reference);
            float v = 2f * Mathf.Atan(Mathf.Tan(halfH) / aspect) * Mathf.Rad2Deg;
            return Mathf.Min(v, maxVertical);
        }
    }
}
