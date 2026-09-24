// TouchStick.cs
// Floating virtual stick: pressing anywhere in the zone places the stick base under the finger, dragging moves
// the knob (up to 'radius' panel units) and Value becomes the offset / radius (up = +y, like W / stick up).
// Releasing hides it and returns to zero. One finger per stick; other fingers go to the other controls.

using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class TouchStick : PointerManipulator
    {
        readonly VisualElement stickBase, knob, ghost;
        readonly float radius;
        const float DeadZone = 0.08f;
        int pointerId = -1;
        Vector2 origin;

        public Vector2 Value { get; private set; }
        public bool Active => pointerId >= 0;

        public TouchStick(VisualElement zone, VisualElement stickBase, VisualElement knob, VisualElement ghost, float radius)
        {
            this.stickBase = stickBase;
            this.knob = knob;
            this.ghost = ghost;
            this.radius = radius;
            target = zone;
        }

        protected override void RegisterCallbacksOnTarget()
        {
            target.RegisterCallback<PointerDownEvent>(OnDown);
            target.RegisterCallback<PointerMoveEvent>(OnMove);
            target.RegisterCallback<PointerUpEvent>(OnUp);
            target.RegisterCallback<PointerCancelEvent>(OnCancel);
        }

        protected override void UnregisterCallbacksFromTarget()
        {
            target.UnregisterCallback<PointerDownEvent>(OnDown);
            target.UnregisterCallback<PointerMoveEvent>(OnMove);
            target.UnregisterCallback<PointerUpEvent>(OnUp);
            target.UnregisterCallback<PointerCancelEvent>(OnCancel);
        }

        void OnDown(PointerDownEvent e)
        {
            if (pointerId >= 0) return;
            pointerId = e.pointerId;
            target.CapturePointer(pointerId);
            // Keep the whole base inside the zone.
            var zone = target.contentRect;
            origin = new Vector2(Mathf.Clamp(e.localPosition.x, radius, Mathf.Max(radius, zone.width - radius)),
                                 Mathf.Clamp(e.localPosition.y, radius, Mathf.Max(radius, zone.height - radius)));
            stickBase.style.left = origin.x - radius;
            stickBase.style.top = origin.y - radius;
            stickBase.AddToClassList("stick-base--active");
            ghost?.AddToClassList("stick-ghost--hidden");
            SetKnob(e.localPosition);
            e.StopPropagation();
        }

        void OnMove(PointerMoveEvent e)
        {
            if (e.pointerId != pointerId) return;
            SetKnob(e.localPosition);
            e.StopPropagation();
        }

        void OnUp(PointerUpEvent e)
        {
            if (e.pointerId != pointerId) return;
            Release();
            e.StopPropagation();
        }

        void OnCancel(PointerCancelEvent e)
        {
            if (e.pointerId == pointerId) Release();
        }

        void SetKnob(Vector2 local)
        {
            var offset = Vector2.ClampMagnitude((Vector2)local - origin, radius);
            knob.style.translate = new Translate(offset.x, offset.y);
            var v = new Vector2(offset.x, -offset.y) / radius;   // panel y grows downward
            Value = v.magnitude < DeadZone ? Vector2.zero : v;
        }

        public void Release()
        {
            if (pointerId >= 0 && target.HasPointerCapture(pointerId)) target.ReleasePointer(pointerId);
            pointerId = -1;
            Value = Vector2.zero;
            knob.style.translate = new Translate(0f, 0f);
            stickBase.RemoveFromClassList("stick-base--active");
            ghost?.RemoveFromClassList("stick-ghost--hidden");
        }
    }
}
