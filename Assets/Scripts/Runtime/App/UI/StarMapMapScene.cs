// StarMapMapScene.cs
// StarMap: a mod system's view as one 3D scene (systems.json "mapScene", part of the partial StarMap; its fields are in
// StarMap.cs). Remake (2026-11-22, the user's request: the GoF3 Systems mod's systems as Galaxy on Fire 3's map shows them).
// GoF3 has no planet per area: its map is one scene (every planet, moon, ring, orbit line, rock field and nebula) and the
// camera flies to the system's star (GalaxyMapCameraController::setStarFocus), the areas' rings standing on tags in it.
// The scene's model (ModStations.MapScene) is copied into the system root and turned, scaled and moved so that its own
// camera ("map_camera:<camera>", looking at "map_target:<camera>", up toward "map_up:<camera>") is the system view's
// camera; the camera's field of view becomes the scene's ("fov", vertical). Each station's planet object stays (its ring,
// name, picking and travel as before) but is held on its "map_area:<area>" node (stations.json "mapArea"), its planet and
// orbit hidden; the system's sun, the other suns and the galaxy background go while the scene shows. The scene fades in
// over the last quarter of the zoom (GoF2/ModUnlit's _Fade) and out over its first on the way back. A drag tilts it a
// little about its target, springing back (GoF3 leans its map with the device's tilt, GalaxyMapCameraController::
// updateUserInput, clamped and smoothed 0.9 / 0.1), instead of turning the planets round the sun; picking an area turns
// nothing (GoF3's areas are fixed).

using System.Collections.Generic;
using GoF2Remake.Modding;
using UnityEngine;

namespace GoF2Remake.UI
{
    public partial class StarMap
    {
        /// <summary>The most a drag leans a map scene, degrees.</summary>
        const float MapSceneTilt = 6f;
        /// <summary>The part of the zoom (ZoomEase) over which a map scene fades in.</summary>
        const float MapSceneFadeFrom = 0.75f;
        /// <summary>The system view's yaw at rest (BuildSystem: 4096 of 65536), degrees.</summary>
        const float RestYawDeg = 4096f / 65536f * 360f;

        bool HasMapScene => mapScene != null;

        /// <summary>BuildSystem: the system's map scene, if its mod gives it one and its model is loaded.</summary>
        void BuildMapScene(int system)
        {
            var spec = ModWorld.MapSceneOf(system);
            var template = ModStations.MapScene(spec);
            if (spec == null) return;
            if (template == null) { Debug.LogWarning($"StarMap: the map scene {spec.model} of system {system} isn't loaded"); return; }
            var go = Instantiate(template, systemRoot.transform, false);
            go.name = "Map scene";
            go.transform.localPosition = Vector3.zero; go.transform.localRotation = Quaternion.identity; go.transform.localScale = Vector3.one;
            Transform Node(string name) => FindDeep(go.transform, name);
            var c = Node("map_camera:" + spec.camera); var t = Node("map_target:" + spec.camera); var u = Node("map_up:" + spec.camera);
            if (c == null || t == null || u == null || (c.position - t.position).sqrMagnitude < 1e-8f)
            {
                Debug.LogWarning($"StarMap: the map scene {spec.model} has no camera \"{spec.camera}\" (map_camera / map_target / map_up)");
                Destroy(go);
                return;
            }
            SetLayer(go);
            go.SetActive(true);
            mapScene = go; mapSceneSpec = spec;
            mapSceneCam = go.transform.InverseTransformPoint(c.position);
            mapSceneTarget = go.transform.InverseTransformPoint(t.position);
            mapSceneUp = go.transform.InverseTransformPoint(u.position);
            mapSceneRenderers.Clear();
            mapSceneRenderers.AddRange(go.GetComponentsInChildren<Renderer>(true));
            mapSceneAreas.Clear();
            for (int k = 0; k < planets.Count; k++)
            {
                string area = ModWorld.MapAreaOf(planets[k].station);
                var node = area != null ? Node("map_area:" + area) : null;
                if (area != null && node == null) Debug.LogWarning($"StarMap: station {planets[k].station}'s mapArea \"{area}\" isn't in {spec.model}");
                mapSceneAreas.Add(node);
                // its own planet and orbit go: GoF3 draws only the area's ring there
                if (planetObjects[k] != null) foreach (var r in planetObjects[k].GetComponentsInChildren<Renderer>(true)) r.enabled = false;
                if (k < orbitObjects.Count && orbitObjects[k] != null) orbitObjects[k].gameObject.SetActive(false);
            }
            mapSceneHidden.Clear();
            foreach (var r in world.GetComponentsInChildren<Renderer>(true))
                if (r.enabled && !r.transform.IsChildOf(systemRoot.transform)) mapSceneHidden.Add(r);
            mapSceneNear = cam != null ? cam.nearClipPlane : 0f;
            mapSceneFade = -1f;
            SetMapSceneFade(0f);
        }

        static Transform FindDeep(Transform root, string name)
        {
            if (root.name == name) return root;
            for (int i = 0; i < root.childCount; i++)
                if (FindDeep(root.GetChild(i), name) is Transform found) return found;
            return null;
        }

        /// <summary>DestroySystem: what the scene hid comes back.</summary>
        void DestroyMapScene()
        {
            if (mapScene == null && mapSceneHidden.Count == 0) return;
            foreach (var r in mapSceneHidden) if (r != null) r.enabled = true;
            mapSceneHidden.Clear();
            if (cam != null && mapSceneNear > 0f) cam.nearClipPlane = mapSceneNear;
            mapScene = null; mapSceneSpec = null;
            mapSceneAreas.Clear(); mapSceneRenderers.Clear();
            mapSceneFade = -1f;
        }

        void SetMapSceneFade(float f)
        {
            if (Mathf.Approximately(f, mapSceneFade)) return;
            mapSceneFade = f;
            SetFade(mapSceneRenderers, f);
            if (mapScene != null) mapScene.SetActive(f > 0f);
            bool galaxy = f < 0.5f;
            foreach (var r in mapSceneHidden) if (r != null) r.enabled = galaxy;
        }

        static MaterialPropertyBlock fadeBlock;
        static readonly int FadeId = Shader.PropertyToID("_Fade");

        /// <summary>GoF2/ModUnlit's _Fade on these renderers only (a property block: the system view's copy of a scene and the
        /// galaxy view's share its materials).</summary>
        static void SetFade(List<Renderer> renderers, float f)
        {
            if (fadeBlock == null) fadeBlock = new MaterialPropertyBlock();
            foreach (var r in renderers)
            {
                if (r == null) continue;
                r.GetPropertyBlock(fadeBlock);
                fadeBlock.SetFloat(FadeId, f);
                r.SetPropertyBlock(fadeBlock);
            }
        }

        // ---- the galaxy view's nebulae ------------------------------------------------------------------------------

        /// <summary>BuildWorld: for each map scene model three or more visible systems share, its "map_galaxy" group (the
        /// GoF3 Systems mod: GoF3's nebula sheets) behind those systems: a copy of the scene with only that group on,
        /// fitted onto their suns (each system's "map_target:&lt;camera&gt;" on its sun: least squares, the scene's own two
        /// in-plane axes scaled apart, its third, the depth, by their mean; turned the way that keeps it unmirrored). It
        /// shows in the galaxy view and goes over the zoom into a system (UpdateMapGalaxies).</summary>
        void BuildMapGalaxies()
        {
            mapGalaxies.Clear();
            mapGalaxyFade = -1f;
            var groups = new Dictionary<string, List<(int system, ModWorld.MapScene spec)>>();
            foreach (var s in db.Systems)
            {
                if (s.index >= suns.Length || suns[s.index] == null) continue;
                var spec = ModWorld.MapSceneOf(s.index);
                if (spec == null) continue;
                if (!groups.TryGetValue(spec.Key, out var list)) groups[spec.Key] = list = new List<(int, ModWorld.MapScene)>();
                list.Add((s.index, spec));
            }
            foreach (var list in groups.Values)
            {
                if (list.Count < 3) continue;
                var template = ModStations.MapScene(list[0].spec);
                if (template == null || FindDeep(template.transform, "map_galaxy") == null) continue;
                var go = Instantiate(template, world.transform, false);
                go.name = "Map galaxy";
                go.transform.localPosition = Vector3.zero; go.transform.localRotation = Quaternion.identity; go.transform.localScale = Vector3.one;
                var group = FindDeep(go.transform, "map_galaxy");
                for (var t = group; t != go.transform; t = t.parent)
                    for (int i = 0; i < t.parent.childCount; i++)
                        if (t.parent.GetChild(i) != t) t.parent.GetChild(i).gameObject.SetActive(false);
                var from = new List<Vector3>(); var to = new List<Vector3>();
                foreach (var (system, spec) in list)
                {
                    var star = FindDeep(go.transform, "map_target:" + spec.camera);
                    if (star == null) continue;
                    from.Add(go.transform.InverseTransformPoint(star.position));
                    to.Add(suns[system].localPosition);
                }
                if (from.Count < 3 || !FitOntoSuns(from, to, out var rot, out var scale, out var pos)) { Destroy(go); continue; }
                go.transform.localRotation = rot; go.transform.localScale = scale; go.transform.localPosition = pos;
                SetLayer(go);
                go.SetActive(true);
                mapGalaxies.Add((go, new List<Renderer>(group.GetComponentsInChildren<Renderer>(true))));
            }
        }

        /// <summary>A rotation, a scale along the scene's own axes and a position taking 'from' (scene space) onto 'to' (the
        /// map's), least squares: the scene's two axes along which its stars spread most map onto the map's x / y (the
        /// suns' plane), the third onto its depth.</summary>
        static bool FitOntoSuns(List<Vector3> from, List<Vector3> to, out Quaternion rot, out Vector3 scale, out Vector3 pos)
        {
            rot = Quaternion.identity; scale = Vector3.one; pos = Vector3.zero;
            int n = from.Count;
            Vector3 pm = Vector3.zero, qm = Vector3.zero;
            for (int i = 0; i < n; i++) { pm += from[i]; qm += to[i]; }
            pm /= n; qm /= n;
            var spread = Vector3.zero;
            for (int i = 0; i < n; i++) { var d = from[i] - pm; spread += Vector3.Scale(d, d); }
            int normal = spread.x <= spread.y && spread.x <= spread.z ? 0 : spread.y <= spread.z ? 1 : 2;
            int a = normal == 0 ? 1 : 0, b = normal == 2 ? 1 : 2;
            // least squares: (q - qm).xy = A (p_a - pm_a, p_b - pm_b)
            double saa = 0, sab = 0, sbb = 0, sxa = 0, sxb = 0, sya = 0, syb = 0;
            for (int i = 0; i < n; i++)
            {
                double da = from[i][a] - pm[a], db = from[i][b] - pm[b], dx = to[i].x - qm.x, dy = to[i].y - qm.y;
                saa += da * da; sab += da * db; sbb += db * db; sxa += dx * da; sxb += dx * db; sya += dy * da; syb += dy * db;
            }
            double det = saa * sbb - sab * sab;
            if (System.Math.Abs(det) < 1e-9) return false;
            var colA = new Vector2((float)((sxa * sbb - sxb * sab) / det), (float)((sya * sbb - syb * sab) / det));
            var colB = new Vector2((float)((sxb * saa - sxa * sab) / det), (float)((syb * saa - sya * sab) / det));
            float sa = colA.magnitude, sb = colB.magnitude;
            if (sa < 1e-6f || sb < 1e-6f) return false;
            var r0 = colA / sa;
            var r1 = colB - Vector2.Dot(colB, r0) * r0;
            if (r1.sqrMagnitude < 1e-12f) return false;
            r1.Normalize();
            var m = Matrix4x4.identity;
            m.SetColumn(a, new Vector4(r0.x, r0.y, 0f, 0f));
            m.SetColumn(b, new Vector4(r1.x, r1.y, 0f, 0f));
            m.SetColumn(normal, new Vector4(0f, 0f, 1f, 0f));
            if (m.determinant < 0f) m.SetColumn(normal, new Vector4(0f, 0f, -1f, 0f));
            rot = m.rotation;
            var s = Vector3.one; s[a] = sa; s[b] = sb; s[normal] = (sa + sb) * 0.5f;
            scale = s;
            pos = qm - rot * Vector3.Scale(s, pm);
            return true;
        }

        /// <summary>Update: the galaxy view's nebulae fade out over the zoom into a system and stay off in its view.</summary>
        void UpdateMapGalaxies()
        {
            if (mapGalaxies.Count == 0) return;
            float f = systemView && zoomDir == 0 ? 0f : zoomDir != 0 ? 1f - ZoomEase : 1f;
            if (Mathf.Approximately(f, mapGalaxyFade)) return;
            mapGalaxyFade = f;
            foreach (var (go, renderers) in mapGalaxies)
            {
                if (go == null) continue;
                go.SetActive(f > 0f);
                SetFade(renderers, f);
            }
        }

        /// <summary>UpdateSystemTransforms: the scene where the system view's camera sees it from its own camera, tilted by the
        /// drag; the planets on their areas; the fade and the field of view along the zoom.</summary>
        void UpdateMapScene()
        {
            if (mapScene == null || cam == null || zoomSystem < 0) return;
            float e = systemView && zoomDir == 0 ? 1f : zoomDir != 0 ? Mathf.Clamp01((ZoomEase - MapSceneFadeFrom) / (1f - MapSceneFadeFrom)) : 0f;
            SetMapSceneFade(e);
            // the field of view: the galaxy's until the fade starts, the scene's once it shows
            cam.fieldOfView = Mathf.Lerp(cam.fieldOfView, mapSceneSpec.fov, e);
            cam.nearClipPlane = e > 0f ? Mathf.Min(mapSceneNear, 0.5f) : mapSceneNear;

            // the drag's lean, springing back when let go
            if (pointer < 0)
            {
                float k = Mathf.Pow(0.9f, Time.unscaledDeltaTime * 60f);
                yaw = 4096f + Mathf.DeltaAngle(RestYawDeg, yaw / 65536f * 360f) * k / 360f * 65536f;
                pitch = -4096f + (pitch + 4096f) * k;
            }
            float lim = MapSceneTilt / 360f * 65536f;
            float dy = Mathf.Clamp(Mathf.DeltaAngle(RestYawDeg, yaw / 65536f * 360f) / 360f * 65536f, -lim, lim), dp = Mathf.Clamp(pitch + 4096f, -lim, lim);
            yaw = Mathf.Repeat(4096f + dy, 65536f); pitch = -4096f + dp;

            // the scene's camera onto the system view's (world space of the map: systemRoot's parent)
            Vector3 pc = U(SystemCameraGame(zoomSystem)), pt = U(SunGame(zoomSystem));
            Vector3 fw = (pt - pc).normalized;
            var viewWorld = Quaternion.LookRotation(fw, Vector3.up);
            Vector3 fl = (mapSceneTarget - mapSceneCam).normalized;
            var viewLocal = Quaternion.LookRotation(fl, mapSceneUp - mapSceneCam);
            var q = viewWorld * Quaternion.Inverse(viewLocal);
            float s = (pc - pt).magnitude / Mathf.Max(1e-6f, (mapSceneCam - mapSceneTarget).magnitude);
            var tilt = Quaternion.AngleAxis(dy / 65536f * 360f, Vector3.up) * Quaternion.AngleAxis(-dp / 65536f * 360f, viewWorld * Vector3.right);
            var rot = tilt * q;
            var tr = mapScene.transform;
            tr.localRotation = rot;
            tr.localScale = Vector3.one * s;
            tr.localPosition = pt - rot * (mapSceneTarget * s);

            // each station on its area
            for (int k = 0; k < planetObjects.Count && k < mapSceneAreas.Count; k++)
            {
                var pl = planetObjects[k];
                if (pl == null) continue;
                pl.position = mapSceneAreas[k] != null ? mapSceneAreas[k].position : systemRoot.transform.TransformPoint(pt);
            }
        }

        // ---- the player check (PlayerAssetsCheck -gof2map) -----------------------------------------------------------

        /// <summary>The map is built (its 3D world), so ShowSystemNow can run.</summary>
        public bool WorldReady => world != null && cam != null;

        /// <summary>PlayerAssetsCheck: straight into a system's view (no zoom), as RevealMap opens the current one.</summary>
        public bool ShowSystemNow(int system)
        {
            if (!WorldReady || system < 0 || system >= suns.Length) return false;
            DestroySystem();
            selected = centred = zoomSystem = system;
            BuildSystem(system);
            FillSystemHeader(system);
            systemView = true;
            zoomDir = 0;
            fade = 0f;
            UpdateCamera();
            UpdateSystemTransforms();
            return true;
        }

        /// <summary>PlayerAssetsCheck: the galaxy view centred on a system (no glide), or the full-map overview.</summary>
        public bool ShowGalaxyNow(int system, bool overviewOn)
        {
            if (!WorldReady) return false;
            if (systemView || zoomSystem >= 0) { DestroySystem(); if (zoomSystem >= 0 && suns[zoomSystem] != null) suns[zoomSystem].localScale = Vector3.one * sunScale; }
            systemView = false; zoomDir = 0; zoomSystem = -1; fade = 255f;
            overview = overviewOn; overviewT = overviewOn ? 1f : 0f;
            if (system >= 0 && system < suns.Length && suns[system] != null)
            {
                Select(system);
                var g = SunGame(system);
                pan = new Vector2(g.x, g.y) / 20f - start;
                autoCentre = false;
            }
            UpdateCamera();
            UpdateMapGalaxies();
            return true;
        }

        /// <summary>The galaxy view's map scene nebulae (PlayerAssetsCheck).</summary>
        public string MapGalaxyReport()
        {
            int r = 0; foreach (var (go, rs) in mapGalaxies) if (go != null && go.activeSelf) r += rs.Count;
            return $"{mapGalaxies.Count} map galax{(mapGalaxies.Count == 1 ? "y" : "ies")}, {r} renderers on, fade {mapGalaxyFade:0.##}";
        }

        /// <summary>PlayerAssetsCheck: closed without a destination.</summary>
        public void CloseForCheck() => Close(new StarMapResult { station = -1 });

        /// <summary>The system shows a map scene and how many of its stations stand on an area node (PlayerAssetsCheck).</summary>
        public string MapSceneReport()
        {
            if (mapScene == null) return "no map scene";
            int lost = 0;
            foreach (var r in mapScene.GetComponentsInChildren<Renderer>(true))
                foreach (var m in r.sharedMaterials)
                    if (m != null && (m.shader == null || !m.shader.isSupported || m.shader.name == "Hidden/InternalErrorShader")) { lost++; break; }
            int placed = 0;
            foreach (var a in mapSceneAreas) if (a != null) placed++;
            return $"map scene {mapSceneSpec.model} camera {mapSceneSpec.camera}, {placed} of {planets.Count} stations on areas, " +
                   $"{mapScene.GetComponentsInChildren<Renderer>(true).Length} renderers ({lost} with a lost shader), fade {mapSceneFade:0.##}, fov {cam.fieldOfView:0.#}";
        }
    }
}
