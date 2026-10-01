// CombatView.cs
// The flight HUD's combat visuals (Reference/research/ship_combat.md 6.1, 7), driven by FlightHud:
//   ship markers (Radar::draw ship loop, only with a scanner): faction colour red enemy / green friend / yellow neutral;
//     off screen a dot (ring when locked) on the radar ellipse 657 x 491; on screen far (any axis > 24000 units from the
//     camera) the dot / ring, plus the distance for the locked ship at (-61, +61); near: the hull bar (114 x 10 frame at
//     (-59, +63), 110 x 6 fill) and, when locked, the faction bracket 81 x 81
//   crates: far a white diamond 0x4f1, near the white bracket 0x4f2, off screen the box 0x451 (0x44d Void)
//   ship lock: the lock ring on the crosshair (24 frames, from t = 0; crates after 500 ms) and the top plate
//     "<race> NN%" with the race icon (Radar::drawCurrentLock)
//   player status (Hud::draw, top left): shield icon (red 500 ms after a hit) + cyan bar, hull icon (red once the armor is
//     gone) + red hull bar with the yellow armor bar over it
//   hit arcs: blue while the shield holds, red without, 300 ms, on the ellipse's left / right / top / bottom
// Positions are HD pixels = panel units.

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.World;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class CombatView
    {
        const float M = 0.05f, NearUnits = 24000f;
        const float EllipseX = 657f, EllipseY = 491f;

        class Marker
        {
            public VisualElement dot, bar, fill, bracket, emp, empFill;
            public Label distance;
            public bool used;
        }

        readonly VisualElement layer, lockRing, lockPlate, lockClass, statusPanel, shieldRow, shieldIcon, shieldFill, hullIcon, hullFill, armorFill;
        readonly Label lockOre;
        readonly VisualElement[] arcs = new VisualElement[4];
        readonly Texture2D[] lockFrames = new Texture2D[24];
        readonly Dictionary<Object, Marker> markers = new Dictionary<Object, Marker>();
        readonly Dictionary<string, Texture2D> textures = new Dictionary<string, Texture2D>();
        static readonly string[] Faction = { "enemy", "friend", "neutral" };

        Texture2D Tex(string name)
        {
            if (!textures.TryGetValue(name, out var t)) textures[name] = t = Resources.Load<Texture2D>("GoF2Hud/" + name);
            return t;
        }

        public CombatView(VisualElement root)
        {
            for (int i = 0; i < 24; i++) lockFrames[i] = Tex($"lock_{i:00}");
            layer = root.Q("combatMarkers");
            lockRing = root.Q("lockRing");
            lockPlate = root.Q("lockPlate");
            lockClass = root.Q("lockClass");
            lockOre = root.Q<Label>("lockOre");
            statusPanel = root.Q("statusPanel");
            shieldRow = root.Q("shieldRow");
            shieldIcon = root.Q("shieldIcon");
            shieldFill = root.Q("shieldFill");
            hullIcon = root.Q("hullIcon");
            hullFill = root.Q("hullFill");
            armorFill = root.Q("armorFill");
            arcs[0] = root.Q("arcLeft");
            arcs[1] = root.Q("arcRight");
            arcs[2] = root.Q("arcTop");
            arcs[3] = root.Q("arcBottom");
            foreach (var plate in statusPanel.Query(className: "status-plate").ToList()) Image(plate, Tex("status_plate"), false);
            Image(root.Q("shieldFrame"), Tex("status_shield_frame"), false);
            Image(root.Q("hullFrame"), Tex("status_hull_frame"), false);
            shieldFill.style.backgroundImage = new StyleBackground(Tex("status_shield_fill"));
            hullFill.style.backgroundImage = new StyleBackground(Tex("status_hull_fill"));
            armorFill.style.backgroundImage = new StyleBackground(Tex("status_armor_fill"));
        }

        static void Image(VisualElement e, Texture2D tex, bool size = true)
        {
            if (e == null || tex == null) return;
            e.style.backgroundImage = new StyleBackground(tex);
            if (!size) return;
            e.style.width = tex.width;
            e.style.height = tex.height;
        }

        static void Place(VisualElement e, float x, float y)
        {
            e.style.left = x;
            e.style.top = y;
        }

        VisualElement NewImage()
        {
            var e = new VisualElement { pickingMode = PickingMode.Ignore };
            e.AddToClassList("nav-abs");
            e.style.display = DisplayStyle.None;
            layer.Add(e);
            return e;
        }

        Marker Get(Object key)
        {
            if (!markers.TryGetValue(key, out var m))
            {
                m = new Marker { dot = NewImage(), bar = NewImage(), fill = NewImage(), bracket = NewImage(), emp = NewImage(), empFill = NewImage() };
                m.distance = new Label { pickingMode = PickingMode.Ignore };
                m.distance.AddToClassList("combat-label");
                m.distance.AddToClassList("gof-semibold");
                m.distance.style.display = DisplayStyle.None;
                layer.Add(m.distance);
                markers[key] = m;
            }
            m.used = true;
            return m;
        }

        static void Show(VisualElement e, bool on) => e.style.display = on ? DisplayStyle.Flex : DisplayStyle.None;

        /// <param name="plateFree">No landmark / asteroid owns the top plate this frame.</param>
        /// <param name="markersOff">Hide the ship / crate markers only (the launch / arrival camera).</param>
        public void Update(CombatRadar radar, Traffic traffic, PlayerHealth health, Camera cam, bool cinematic, bool plateFree, bool markersOff = false)
        {
            UpdateStatus(health, cinematic);
            foreach (var m in markers.Values) m.used = false;
            bool show = radar != null && radar.HasScanner && cam != null && layer.panel != null && !cinematic && !markersOff && health != null && !health.Dead;
            layer.style.display = show ? DisplayStyle.Flex : DisplayStyle.None;
            if (show)
            {
                var origin = layer.worldBound.position;
                var centre = layer.layout.size / 2f;
                if (traffic != null)
                    foreach (var s in traffic.Ships)
                    {
                        // Radar::draw skips inactive players: a sleeping ship (KIPlayer::setToSleep) has no marker until it
                        // wakes, e.g. a pirate outpost until an enemy comes within its +-50 000 box.
                        if (s.Gone || !s.Target.Alive || s.Hidden || s.Asleep || s.RadarHidden || s.DockingType > 0) continue;
                        int f = s.Target.hostileToPlayer ? 0 : s.Target.friendToPlayer ? 1 : 2;
                        DrawShip(Get(s), s.transform.position, f, s.Target.HullFraction, radar.Locked == s.Target, cam, origin, centre);
                        DrawEmp(Get(s), s.Hp != null ? s.Hp.EmpFraction : 1f);
                    }
                foreach (var o in Target.NetShips)   // multiplayer: the other players, the host's ships on a client
                    if (o != null && o.Alive && !o.untargetable)
                        DrawShip(Get(o), o.transform.position, o.hostileToPlayer ? 0 : o.friendToPlayer ? 1 : 2, o.HullFraction, radar.Locked == o, cam, origin, centre);
                foreach (var o in Target.RadarObjects)
                    if (o != null && o.Alive && !o.untargetable)
                        DrawShip(Get(o), o.transform.position, o.hostileToPlayer ? 0 : 2, 1f, radar.Locked == o, cam, origin, centre, true);
                foreach (var c in Object.FindObjectsByType<Crate>(FindObjectsInactive.Exclude))
                    DrawCrate(Get(c), c.transform.position, c.race == 9, cam, origin, centre);

                // Lock ring and plate for ships / crates (after the navigation view, which owns them otherwise).
                if (radar.LockFrame >= 0)
                {
                    lockRing.EnableInClassList("lock-ring--shown", true);
                    Image(lockRing, lockFrames[Mathf.Clamp(radar.LockFrame, 0, 23)]);
                }
                var locked = radar.Locked;
                if (plateFree && locked != null)
                {
                    lockPlate.EnableInClassList("lock-plate--shown", true);
                    // Radar::drawCurrentLock 0x158548: "<name or race> NN%"; the Hijacker / the Informer their name alone; a Most
                    // Wanted criminal in its own colour.
                    string who = string.IsNullOrEmpty(locked.displayName) ? RaceName(locked.race) : locked.displayName;
                    lockOre.text = locked.plateNameOnly && !string.IsNullOrEmpty(locked.displayName) ? locked.displayName : $"{who} {Mathf.RoundToInt(locked.HullFraction * 100f)}%";
                    lockOre.EnableInClassList("lock-ore--wanted", locked.plateWanted);
                    var icon = !locked.plateNoIcon && (locked.race >= 0 && locked.race <= 3 || locked.race == 8 || locked.race == 9) ? Tex($"race_{locked.race}") : null;
                    lockClass.style.display = icon != null ? DisplayStyle.Flex : DisplayStyle.None;
                    Image(lockClass, icon);
                }
            }
            List<Object> gone = null;
            foreach (var kv in markers)
            {
                var m = kv.Value;
                if (m.used) continue;
                if (kv.Key == null)   // destroyed (a collected or expired crate): drop its elements
                {
                    m.dot.RemoveFromHierarchy(); m.bar.RemoveFromHierarchy(); m.fill.RemoveFromHierarchy();
                    m.bracket.RemoveFromHierarchy(); m.distance.RemoveFromHierarchy(); m.emp.RemoveFromHierarchy(); m.empFill.RemoveFromHierarchy();
                    (gone ??= new List<Object>()).Add(kv.Key);
                    continue;
                }
                Show(m.dot, false); Show(m.bar, false); Show(m.fill, false); Show(m.bracket, false); Show(m.distance, false);
                Show(m.emp, false); Show(m.empFill, false);
            }
            if (gone != null) foreach (var k in gone) markers.Remove(k);
        }

        static string RaceName(int race) => race switch
        {
            >= 0 and <= 3 => Localization.Get(406 + race),
            8 => Localization.Get(414),
            9 => Localization.Get(415),
            _ => "???",
        };

        bool Project(Camera cam, Vector3 world, Vector2 origin, Vector2 centre, out Vector2 p, out bool near)
        {
            var sp = cam.WorldToScreenPoint(world);
            bool onScreen = sp.z > 0f && sp.x >= 0f && sp.y >= 0f && sp.x <= Screen.width && sp.y <= Screen.height;
            var d = (world - cam.transform.position) / M;
            near = Mathf.Abs(d.x) <= NearUnits && Mathf.Abs(d.y) <= NearUnits && Mathf.Abs(d.z) <= NearUnits;
            if (onScreen)
            {
                // Viewport -> panel (the camera fills the screen): exact on screen and in offscreen captures.
                var v = cam.WorldToViewportPoint(world);
                var size = layer.panel.visualTree.layout.size;
                p = new Vector2(v.x * size.x, (1f - v.y) * size.y) - origin;
            }
            else p = OffScreen(cam, world, centre);
            return onScreen;
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

        void DrawShip(Marker m, Vector3 world, int faction, float hull, bool locked, Camera cam, Vector2 origin, Vector2 centre, bool dotOnly = false)
        {
            bool onScreen = Project(cam, world, origin, centre, out var p, out bool near);
            string f = Faction[faction];
            bool bar = onScreen && near && !dotOnly;
            Show(m.bar, bar);
            Show(m.fill, bar);
            Show(m.bracket, bar && locked);
            Show(m.dot, !bar);
            Show(m.distance, !bar && onScreen && locked);
            if (bar)
            {
                Image(m.bar, Tex($"ship_bar_{f}"));
                Image(m.fill, Tex($"ship_fill_{f}"));
                Place(m.bar, p.x - 59f, p.y + 63f);
                Place(m.fill, p.x - 58f, p.y + 65f);
                m.fill.style.width = Mathf.Clamp01(hull) * 110f;
                if (locked) { Image(m.bracket, Tex($"ship_bracket_{f}")); Place(m.bracket, p.x - 40.5f, p.y - 40.5f); }
            }
            else
            {
                var tex = Tex(locked ? $"ship_ring_{f}" : $"ship_dot_{f}");
                Image(m.dot, tex);
                if (tex != null) Place(m.dot, p.x - tex.width / 2f, p.y - tex.height / 2f);
                if (onScreen && locked)
                {
                    m.distance.text = Navigation.FormatDistance((world - cam.transform.position).magnitude / M);
                    Place(m.distance, p.x - 61f, p.y + 61f);
                }
            }
        }

        /// <summary>Radar::draw (ship_combat.md 7.2): a near ship's EMP bar 8 px under its hull bar while EMP &lt; max.</summary>
        void DrawEmp(Marker m, float emp)
        {
            bool on = m.bar.style.display.value == DisplayStyle.Flex && emp < 1f;
            Show(m.emp, on);
            Show(m.empFill, on);
            if (!on) return;
            Image(m.emp, Tex("emp_bar"));
            Image(m.empFill, Tex("emp_fill"));
            float x = m.bar.style.left.value.value, y = m.bar.style.top.value.value + 18f;
            Place(m.emp, x, y);
            Place(m.empFill, x + 2f, y + 2f);
            m.empFill.style.width = Mathf.Clamp01(emp) * 110f;
        }

        void DrawCrate(Marker m, Vector3 world, bool voidCrate, Camera cam, Vector2 origin, Vector2 centre)
        {
            bool onScreen = Project(cam, world, origin, centre, out var p, out bool near);
            Show(m.bar, false); Show(m.fill, false); Show(m.distance, false); Show(m.bracket, false);
            Show(m.emp, false); Show(m.empFill, false);
            Show(m.dot, true);
            var tex = !onScreen ? Tex(voidCrate ? "crate_off_void" : "crate_off") : near ? Tex("bracket") : Tex("crate_dot");
            Image(m.dot, tex);
            if (tex != null) Place(m.dot, p.x - tex.width / 2f, p.y - tex.height / 2f);
        }

        void UpdateStatus(PlayerHealth health, bool cinematic)
        {
            bool show = health != null && health.Target != null && !cinematic && !health.Dead;
            statusPanel.style.display = show ? DisplayStyle.Flex : DisplayStyle.None;
            for (int i = 0; i < 4; i++) arcs[i].EnableInClassList("hit-arc--shown", show && health.ArcMs[i] > 0f);
            if (!show) return;
            var hp = health.Hp;
            shieldRow.style.display = health.HasShield ? DisplayStyle.Flex : DisplayStyle.None;
            Image(shieldIcon, Tex(health.ShieldHitMs > 0f ? "status_shield_hit" : "status_shield"));
            Image(hullIcon, Tex(hp.armor > 0 ? "status_hull" : "status_hull_red"));
            shieldFill.style.width = hp.ShieldFraction * 248f;
            hullFill.style.width = hp.HullFraction * 248f;
            armorFill.style.display = health.HasArmor ? DisplayStyle.Flex : DisplayStyle.None;
            armorFill.style.width = hp.ArmorFraction * 248f;

            // Hit arcs: blue with the shield up, red without; left mirrored, bottom flipped.
            bool blue = hp.shield > 0f;
            for (int i = 0; i < 4; i++)
            {
                if (health.ArcMs[i] <= 0f) continue;
                var tex = Tex(i < 2 ? (blue ? "hit_side_blue" : "hit_side_red") : (blue ? "hit_top_blue" : "hit_top_red"));
                if (tex == null) continue;
                var a = arcs[i];
                Image(a, tex);
                float w = tex.width, h = tex.height;
                switch (i)
                {
                    case 0: Place(a, -EllipseX - w / 2f, -h / 2f); a.style.scale = new Scale(new Vector3(-1f, 1f, 1f)); break;
                    case 1: Place(a, EllipseX - w / 2f, -h / 2f); break;
                    case 2: Place(a, -w / 2f, -EllipseY - h / 2f); break;
                    default: Place(a, -w / 2f, EllipseY - h / 2f); a.style.scale = new Scale(new Vector3(1f, -1f, 1f)); break;
                }
            }
        }
    }
}
