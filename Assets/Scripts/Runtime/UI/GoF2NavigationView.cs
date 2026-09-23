// GoF2NavigationView.cs
// The flight HUD's navigation visuals (Reference/research/autopilot_travel.md 1 and 4), driven by GoF2FlightHud:
//   landmarks near the screen centre (+-w/6): bracket 0x4f2 with the name, the station's "Tech level: N" and the distance
//     (Radar::calcDistance, from the camera); elsewhere only the jumpgate gets its icon 0x453 (off screen clamped to the
//     radar ellipse 657 x 491 around the centre); the station has no marker then
//   planets: the gate icon next to the jumpgate station's planet, the name only while the planet is in the lock box
//   lock ring and top plate for station / jumpgate / planet locks (race icon of the system for landmarks), shared with
//     GoF2MiningView's elements
//   autopilot (0x4b0 / lit 0x4b1) and fast-forward (0x541 / held 0x540) buttons on their pill (0x53f), touch only, shown
//     while the autopilot or an asteroid approach runs; fast-forward only while it is allowed
// Positions are HD pixels = panel units.

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class GoF2NavigationView
    {
        const float M = 0.05f;
        const float EllipseX = 657f, EllipseY = 491f;   // image 0x4c7, Radar::elipsoidIntersect

        class Marker
        {
            public GoF2Navigation.Target target;
            public VisualElement bracket, icon;
            public Label name, tech, distance;
        }

        readonly VisualElement layer, lockRing, lockPlate, lockClass, navButtons, fastForward, autopilotButton;
        readonly Label lockOre;
        readonly Texture2D[] lockFrames = new Texture2D[24];
        readonly Texture2D autopilotOff, autopilotOn, fastForwardOff, fastForwardOn;
        readonly List<Marker> markers = new List<Marker>();
        readonly Dictionary<int, Texture2D> raceIcons = new Dictionary<int, Texture2D>();
        GoF2Navigation built;
        string techLine;
        int systemRace, gateStation = -1;
        bool fastForwardPressed;

        public bool FastForwardPressed => fastForwardPressed;
        public event System.Action AutopilotButton;

        static Texture2D Tex(string name) => Resources.Load<Texture2D>("GoF2Hud/" + name);

        public GoF2NavigationView(VisualElement root)
        {
            for (int i = 0; i < 24; i++) lockFrames[i] = Tex($"lock_{i:00}");
            layer = root.Q("navMarkers");
            lockRing = root.Q("lockRing");
            lockPlate = root.Q("lockPlate");
            lockClass = root.Q("lockClass");
            lockOre = root.Q<Label>("lockOre");
            navButtons = root.Q("navButtons");
            fastForward = root.Q("fastForwardButton");
            autopilotButton = root.Q("autopilotButton");
            autopilotOff = Tex("autopilot");
            autopilotOn = Tex("autopilot_on");
            fastForwardOff = Tex("fastforward");
            fastForwardOn = Tex("fastforward_on");
            Image(root.Q("navButtonPill"), Tex("button_pill"));
            Image(fastForward, fastForwardOff);
            Image(autopilotButton, autopilotOn);

            // Fast-forward is hold-to-use (MGame::OnTouchEnd ends it on any release); the autopilot button is a tap.
            fastForward.RegisterCallback<PointerDownEvent>(e => { fastForwardPressed = true; fastForward.CapturePointer(e.pointerId); e.StopPropagation(); });
            fastForward.RegisterCallback<PointerUpEvent>(e => { fastForwardPressed = false; fastForward.ReleasePointer(e.pointerId); });
            fastForward.RegisterCallback<PointerCancelEvent>(e => fastForwardPressed = false);
            autopilotButton.RegisterCallback<PointerUpEvent>(e => { AutopilotButton?.Invoke(); e.StopPropagation(); });
            autopilotButton.RegisterCallback<PointerDownEvent>(e => e.StopPropagation());
        }

        static void Image(VisualElement e, Texture2D tex)
        {
            if (e == null || tex == null) return;
            e.style.backgroundImage = new StyleBackground(tex);
            e.style.width = tex.width;
            e.style.height = tex.height;
        }

        static Label Text(VisualElement parent, string cls)
        {
            var l = new Label { pickingMode = PickingMode.Ignore };
            l.AddToClassList("nav-label");
            if (cls != null) l.AddToClassList(cls);
            l.AddToClassList("gof-semibold");
            parent.Add(l);
            return l;
        }

        void Build(GoF2Navigation nav, int race, int jumpgateStation, int techLevel)
        {
            built = nav;
            systemRace = race;
            gateStation = jumpgateStation;
            techLine = $"{GoF2Localization.Get(133)}: {techLevel}";
            layer.Clear();
            markers.Clear();
            foreach (var t in nav.Targets)
            {
                var m = new Marker { target = t };
                if (t.kind != GoF2Navigation.Kind.Planet)
                {
                    m.bracket = new VisualElement { pickingMode = PickingMode.Ignore };
                    m.bracket.AddToClassList("nav-abs");
                    Image(m.bracket, Tex("bracket"));
                    layer.Add(m.bracket);
                }
                if (t.kind == GoF2Navigation.Kind.Jumpgate || (t.kind == GoF2Navigation.Kind.Planet && t.station == gateStation))
                {
                    m.icon = new VisualElement { pickingMode = PickingMode.Ignore };
                    m.icon.AddToClassList("nav-abs");
                    Image(m.icon, Tex("gate_icon"));
                    layer.Add(m.icon);
                }
                m.name = Text(layer, null);
                m.name.text = t.name;
                if (t.kind == GoF2Navigation.Kind.Station) { m.tech = Text(layer, "nav-label--dim"); m.tech.text = techLine; }
                if (t.kind != GoF2Navigation.Kind.Planet) m.distance = Text(layer, "nav-label--dim");
                markers.Add(m);
            }
        }

        /// <param name="race">The system's race (plate icon for landmarks).</param>
        public void Update(GoF2Navigation nav, Camera cam, bool touch, bool miningApproach, int race, int jumpgateStation, int techLevel)
        {
            bool show = nav != null && cam != null && layer.panel != null && !nav.Jumping;
            layer.style.display = show ? DisplayStyle.Flex : DisplayStyle.None;
            UpdateButtons(nav, touch, miningApproach);
            if (!show) return;
            if (built != nav) Build(nav, race, jumpgateStation, techLevel);

            var origin = layer.worldBound.position;
            float w = Screen.width, h = Screen.height;
            var centre = layer.layout.size / 2f;
            foreach (var m in markers)
            {
                var t = m.target;
                var sp = cam.WorldToScreenPoint(t.Position);
                bool onScreen = sp.z > 0f && sp.x >= 0f && sp.y >= 0f && sp.x <= w && sp.y <= h;
                bool nearCentre = onScreen && Mathf.Abs(sp.x - w / 2f) < w / 6f && Mathf.Abs(sp.y - h / 2f) < w / 6f;
                Vector2 p = onScreen ? RuntimePanelUtils.CameraTransformWorldToPanel(layer.panel, t.Position, cam) - origin : Vector2.zero;
                bool planet = t.kind == GoF2Navigation.Kind.Planet;

                if (m.bracket != null)
                {
                    m.bracket.style.display = nearCentre ? DisplayStyle.Flex : DisplayStyle.None;
                    if (nearCentre) Place(m.bracket, p.x - 40.5f, p.y - 40.5f);
                }
                if (planet)
                {
                    bool inBox = nav.Candidate == t;   // the name shows only while the planet is in the lock box
                    if (m.icon != null) { m.icon.style.display = onScreen ? DisplayStyle.Flex : DisplayStyle.None; Place(m.icon, p.x + 10f, p.y - 10f); }
                    m.name.style.display = onScreen && inBox ? DisplayStyle.Flex : DisplayStyle.None;
                    Place(m.name, p.x + (m.icon != null ? 24f : 10f), p.y - 10f);
                    continue;
                }

                // Landmarks: labels near the centre; elsewhere the jumpgate icon on the radar ellipse, the station nothing.
                bool station = t.kind == GoF2Navigation.Kind.Station;
                float lx = station ? 50f : 10f;
                m.name.style.display = nearCentre ? DisplayStyle.Flex : DisplayStyle.None;
                m.distance.style.display = nearCentre ? DisplayStyle.Flex : DisplayStyle.None;
                if (m.tech != null) m.tech.style.display = nearCentre ? DisplayStyle.Flex : DisplayStyle.None;
                if (nearCentre)
                {
                    Place(m.name, p.x + lx, p.y);
                    if (m.tech != null) Place(m.tech, p.x + lx, p.y + 30f);
                    Place(m.distance, p.x + lx, p.y + (station ? 60f : 30f));
                    m.distance.text = GoF2Navigation.FormatDistance((t.Position - cam.transform.position).magnitude / M);
                }
                if (m.icon != null)
                {
                    m.icon.style.display = nearCentre ? DisplayStyle.None : DisplayStyle.Flex;
                    if (!nearCentre)
                    {
                        Vector2 q = onScreen ? p : OffScreen(cam, t.Position, centre);
                        Place(m.icon, q.x - 13f, q.y - 13f);
                    }
                }
            }

            // Lock ring on the crosshair and the top plate (Radar::drawCurrentLock) for landmark / planet locks.
            var locking = nav.Candidate;
            if (locking != null && nav.LockFrame >= 0)
            {
                lockRing.EnableInClassList("lock-ring--shown", true);
                Image(lockRing, lockFrames[Mathf.Clamp(nav.LockFrame, 0, 23)]);
            }
            var locked = nav.Locked;
            if (locked != null)
            {
                lockPlate.EnableInClassList("lock-plate--shown", true);
                lockOre.text = locked.name;
                var icon = locked.kind == GoF2Navigation.Kind.Planet ? null : RaceIcon(systemRace);
                lockClass.style.display = icon != null ? DisplayStyle.Flex : DisplayStyle.None;
                Image(lockClass, icon);
            }
            else lockClass.style.display = DisplayStyle.Flex;
        }

        /// <summary>Radar::update for an object not on screen: its direction clamped onto the radar ellipse.</summary>
        static Vector2 OffScreen(Camera cam, Vector3 world, Vector2 centre)
        {
            var local = cam.transform.InverseTransformPoint(world);
            var d = new Vector2(local.x, -local.y);
            if (d.sqrMagnitude < 1e-6f) d = Vector2.down;
            float k = Mathf.Sqrt(d.x * d.x / (EllipseX * EllipseX) + d.y * d.y / (EllipseY * EllipseY));
            return centre + d / k;
        }

        Texture2D RaceIcon(int race)
        {
            int frame = race >= 0 && race <= 3 ? race : race == 8 ? 8 : 9;
            if (!raceIcons.TryGetValue(frame, out var t)) raceIcons[frame] = t = Tex($"race_{frame}");
            return t;
        }

        void UpdateButtons(GoF2Navigation nav, bool touch, bool miningApproach)
        {
            bool active = nav != null && (nav.Autopilot || miningApproach) && !nav.Jumping;
            navButtons.style.display = touch && active ? DisplayStyle.Flex : DisplayStyle.None;
            bool canFf = active && nav.CanFastForward;
            fastForward.style.visibility = canFf ? Visibility.Visible : Visibility.Hidden;
            if (!canFf) fastForwardPressed = false;
            Image(fastForward, fastForwardPressed && nav.FastForward ? fastForwardOn : fastForwardOff);
            Image(autopilotButton, active ? autopilotOn : autopilotOff);
        }

        static void Place(VisualElement e, float x, float y)
        {
            e.style.left = x;
            e.style.top = y;
        }
    }
}
