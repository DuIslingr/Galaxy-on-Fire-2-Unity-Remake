// ModShipBuilder.cs
// A mod's ship as the game's other ships are (an AssembledObject template), built at run time from its glTF model and
// its ships.json entry: the run-time port of PR #34's CustomShipBuilder (the Editor tool that baked the remake's own ships):
//   - the model as "hull", turned by modelYaw and scaled to modelLength game units nose to tail; a "materials" entry
//     replaces the model's material on the renderers (name contains 'mesh') / submeshes it names (ModMaterials.FromSpec);
//   - the player's engine glow at every exhaust mount (slotType 3; playerVariantParts like *_engine_glow_add): the
//     Phantom's glow shape (a 12-segment disc and a flared ring 0.87 r behind it, radius x1.31) on the shared glow
//     sprite (mat_34813, centre uv (0.46, 0.947)); no exhaust mounts = no flame (ShipExhaust uses the same mounts);
//   - each "throttleGlow" / "extraGlows" entry: the hull triangles under the lit part of its mask, pushed 'offset' out,
//     additive, driven by ThrottleGlow (with its trails), plus an empty engine_state player part;
//   - no NPC engine parts; one LOD level culled at 80000 units like the generic ships.

using System.Collections.Generic;
using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;
using UnityEngine.Rendering;

namespace GoF2Remake.Modding
{
    public static class ModShipBuilder
    {
        const float M = 0.05f;               // metres per game unit (ShipController.metersPerUnit)
        const float CullDistance = 80000f;   // game units, the generic ships' last visible distance
        const float ReferenceFov = 60f;
        const float GlowMaskThreshold = 0.08f;

        /// <summary>The template for 'c' around the instantiated glTF scene 'model' (re-parented as the hull).</summary>
        public static GameObject Build(CustomShipData c, ModInfo mod, GameObject model)
        {
            var root = new GameObject(c.assembly);
            var asm = root.AddComponent<AssembledObject>();
            asm.origin = $"mod {mod.Id}";
            asm.lodDistancesGameUnits = new float[0];
            asm.lastVisibleDistanceGameUnits = CullDistance;

            model.name = "hull";
            model.transform.SetParent(root.transform, false);
            model.transform.localPosition = Vector3.zero;
            model.transform.localRotation = Quaternion.Euler(0f, c.modelYaw, 0f);
            var renderers = model.GetComponentsInChildren<Renderer>(true);
            var specs = c.materials ?? new List<CustomShipMaterial>();
            var mats = new Material[specs.Count];
            for (int i = 0; i < specs.Count; i++) mats[i] = ModMaterials.FromSpec(mod, specs[i], $"{c.assembly} {specs[i].mesh}{specs[i].submesh}");
            if (specs.Count > 0)
                foreach (var r in renderers)
                {
                    var mesh = MeshOf(r);
                    var assigned = r.sharedMaterials;
                    int count = Mathf.Max(1, mesh != null ? mesh.subMeshCount : assigned.Length);
                    if (assigned.Length != count) System.Array.Resize(ref assigned, count);
                    for (int s = 0; s < count; s++) { var m = MaterialFor(specs, mats, r.name, s); if (m != null) assigned[s] = m; }
                    r.sharedMaterials = assigned;
                }
            foreach (var r in renderers) { r.shadowCastingMode = ShadowCastingMode.On; r.receiveShadows = true; }
            float length = BoundsIn(root.transform, renderers).size.z;
            if (length > 0f) model.transform.localScale *= c.modelLength * M / length;

            var parts = new List<GameObject>();
            var glow = BuildEngineGlow(c);
            if (glow != null) parts.Add(glow);
            var glowSpecs = new List<CustomThrottleGlow> { c.throttleGlow };
            if (c.extraGlows != null) glowSpecs.AddRange(c.extraGlows);
            GameObject engineState = null;
            for (int gi = 0; gi < glowSpecs.Count; gi++)
            {
                var tg = BuildThrottleGlow(c, mod, glowSpecs[gi], gi == 0 ? "" : "_" + (gi + 1), root.transform, renderers);
                if (tg == null) continue;
                tg.transform.SetParent(root.transform, false);
                if (engineState == null) { engineState = new GameObject("engine_state"); parts.Add(engineState); }
                tg.GetComponent<ThrottleGlow>().engineState = engineState;
            }
            foreach (var p in parts) p.transform.SetParent(root.transform, false);
            asm.playerVariantParts = parts.ToArray();
            asm.npcVariantParts = new GameObject[0];
            asm.conditionalParts = new GameObject[0];
            asm.conditions = new string[0];

            var group = root.AddComponent<LODGroup>();
            group.SetLODs(new[] { new LOD(0.5f, root.GetComponentsInChildren<Renderer>(true)) });
            group.RecalculateBounds();
            float tanHalf = Mathf.Tan(ReferenceFov * 0.5f * Mathf.Deg2Rad);
            float h = Mathf.Clamp01(group.size / (2f * CullDistance * M * tanHalf));
            group.SetLODs(new[] { new LOD(h, root.GetComponentsInChildren<Renderer>(true)) });
            return root;
        }

        internal static Mesh MeshOf(Renderer r) => r is SkinnedMeshRenderer s ? s.sharedMesh : r.GetComponent<MeshFilter>()?.sharedMesh;

        internal static Bounds BoundsIn(Transform root, Renderer[] renderers)
        {
            bool any = false;
            var b = new Bounds();
            foreach (var r in renderers)
            {
                var mesh = MeshOf(r);
                if (mesh == null) continue;
                var mb = mesh.bounds;
                var m = root.worldToLocalMatrix * r.transform.localToWorldMatrix;
                for (int i = 0; i < 8; i++)
                {
                    var p = m.MultiplyPoint3x4(mb.center + Vector3.Scale(mb.extents, new Vector3((i & 1) == 0 ? -1 : 1, (i & 2) == 0 ? -1 : 1, (i & 4) == 0 ? -1 : 1)));
                    if (!any) { b = new Bounds(p, Vector3.zero); any = true; } else b.Encapsulate(p);
                }
            }
            return b;
        }

        /// <summary>The entry for a renderer's submesh: one naming that submesh first, else the first for every submesh
        /// (submesh -1); its 'mesh' must be part of the renderer's name (empty = any). Null = keep the model's own.</summary>
        internal static Material MaterialFor(List<CustomShipMaterial> specs, Material[] mats, string rendererName, int submesh)
        {
            string n = rendererName.ToLowerInvariant();
            int any = -1;
            for (int i = 0; i < specs.Count; i++)
            {
                var e = specs[i];
                if (!string.IsNullOrEmpty(e.mesh) && !n.Contains(e.mesh.ToLowerInvariant())) continue;
                if (e.submesh == submesh) return mats[i];
                if (e.submesh < 0 && any < 0) any = i;
            }
            return any >= 0 ? mats[any] : null;
        }

        static GameObject BuildEngineGlow(CustomShipData c)
        {
            var exhausts = c.mounts?.Where(m => m.slotType == 3).ToList();
            var mat = ModAssets.Get()?.engineGlow;
            if (exhausts == null || exhausts.Count == 0 || mat == null) return null;
            const int Segments = 12;
            var uvCentre = new Vector2(0.46f, 0.947f);
            const float UvDisc = 0.0254f, UvRing = 0.048f;
            float r = c.engineGlowRadius * M, ringR = r * 1.31f, back = r * 0.87f;
            var verts = new List<Vector3>();
            var uvs = new List<Vector2>();
            var tris = new List<int>();
            foreach (var m in exhausts)
            {
                var o = WeaponSystem.MountToLocal(m);
                int centre = verts.Count;
                verts.Add(o); uvs.Add(uvCentre);
                int disc = verts.Count;
                for (int i = 0; i < Segments; i++)
                {
                    float a = i * Mathf.PI * 2f / Segments;
                    var d = new Vector2(Mathf.Sin(a), Mathf.Cos(a));
                    verts.Add(o + new Vector3(d.x * r, d.y * r, 0f)); uvs.Add(uvCentre + d * UvDisc);
                }
                int ring = verts.Count;
                for (int i = 0; i < Segments; i++)
                {
                    float a = i * Mathf.PI * 2f / Segments;
                    var d = new Vector2(Mathf.Sin(a), Mathf.Cos(a));
                    verts.Add(o + new Vector3(d.x * ringR, d.y * ringR, -back)); uvs.Add(uvCentre + d * UvRing);
                }
                for (int i = 0; i < Segments; i++)
                {
                    int j = (i + 1) % Segments;
                    tris.AddRange(new[] { centre, disc + i, disc + j });
                    tris.AddRange(new[] { disc + i, ring + i, ring + j, disc + i, ring + j, disc + j });
                }
            }
            var mesh = new Mesh { name = c.assembly + "_engine_glow" };
            mesh.SetVertices(verts);
            mesh.SetUVs(0, uvs);
            mesh.SetTriangles(tris, 0);
            mesh.RecalculateNormals();
            mesh.RecalculateBounds();
            var go = new GameObject("engine_glow");
            go.AddComponent<MeshFilter>().sharedMesh = mesh;
            var mr = go.AddComponent<MeshRenderer>();
            mr.sharedMaterial = mat;
            mr.shadowCastingMode = ShadowCastingMode.Off;
            mr.receiveShadows = false;
            return go;
        }

        static GameObject BuildThrottleGlow(CustomShipData c, ModInfo mod, CustomThrottleGlow tg, string suffix, Transform root, Renderer[] renderers)
        {
            if (tg == null || string.IsNullOrEmpty(tg.mask)) return null;
            var template = ModAssets.Get()?.engineGlow;
            var maskTex = ModMaterials.Texture(mod, tg.mask, false, true);
            if (maskTex == null || template == null) return null;
            float Lit(Vector2 uv) { var p = maskTex.GetPixelBilinear(uv.x, uv.y); return Mathf.Max(p.r, Mathf.Max(p.g, p.b)); }
            var verts = new List<Vector3>();
            var normals = new List<Vector3>();
            var uvs = new List<Vector2>();
            float offset = tg.offset * M;
            foreach (var r in renderers)
            {
                if (!string.IsNullOrEmpty(tg.mesh) && !r.name.ToLowerInvariant().Contains(tg.mesh.ToLowerInvariant())) continue;
                var mesh = MeshOf(r);
                if (mesh == null || !mesh.isReadable) continue;
                var mv = mesh.vertices;
                var mn = mesh.normals;
                var mu = mesh.uv;
                if (mu == null || mu.Length != mv.Length) continue;
                bool hasNormals = mn != null && mn.Length == mv.Length;
                var m = root.worldToLocalMatrix * r.transform.localToWorldMatrix;
                for (int s = 0; s < mesh.subMeshCount; s++)
                {
                    if (tg.submesh >= 0 && s != tg.submesh) continue;
                    var t = mesh.GetTriangles(s);
                    for (int i = 0; i + 2 < t.Length; i += 3)
                    {
                        Vector2 a = mu[t[i]], b = mu[t[i + 1]], d = mu[t[i + 2]];
                        if (Mathf.Max(Mathf.Max(Lit(a), Lit(b)), Mathf.Max(Lit(d), Lit((a + b + d) / 3f))) <= GlowMaskThreshold) continue;
                        for (int k = 0; k < 3; k++)
                        {
                            int v = t[i + k];
                            var n = hasNormals ? m.MultiplyVector(mn[v]).normalized : Vector3.zero;
                            verts.Add(m.MultiplyPoint3x4(mv[v]) + n * offset);
                            normals.Add(n);
                            uvs.Add(mu[v]);
                        }
                    }
                }
            }
            if (verts.Count == 0)
            {
                string w = $"ships.json: \"{c.name}\": no hull triangle under the glow mask {tg.mask}";
                if (!mod.Warnings.Contains(w)) mod.Warnings.Add(w);
                return null;
            }
            var glowMesh = new Mesh { name = c.assembly + "_throttle_glow" + suffix };
            if (verts.Count > 65535) glowMesh.indexFormat = IndexFormat.UInt32;
            glowMesh.SetVertices(verts);
            glowMesh.SetNormals(normals);
            glowMesh.SetUVs(0, uvs);
            glowMesh.SetTriangles(Enumerable.Range(0, verts.Count).ToArray(), 0);
            glowMesh.RecalculateBounds();

            var tint = tg.color != null && tg.color.Length >= 3 ? new Color(tg.color[0], tg.color[1], tg.color[2], 1f) : Color.white;
            var mat = new Material(template) { name = c.assembly + "_throttle_glow" + suffix };
            mat.SetTexture("_MainTex", maskTex);
            mat.SetTextureScale("_MainTex", Vector2.one);
            mat.SetTextureOffset("_MainTex", Vector2.zero);
            mat.SetColor("_Color", tint);
            mat.SetFloat("_Glow", tg.idle);
            mat.SetFloat("_UseVertexColor", 0f);
            mat.DisableKeyword("_USEVERTEXCOLOR_ON");

            var go = new GameObject("throttle_glow" + suffix);
            go.AddComponent<MeshFilter>().sharedMesh = glowMesh;
            var mr = go.AddComponent<MeshRenderer>();
            mr.sharedMaterial = mat;
            mr.shadowCastingMode = ShadowCastingMode.Off;
            mr.receiveShadows = false;
            var g = go.AddComponent<ThrottleGlow>();
            g.color = tint;
            g.idle = tg.idle;
            g.full = tg.full;
            g.boost = tg.boost;
            if (tg.trailWidth > 0f && tg.trailCount > 0)
            {
                // trailCount trails across the glow's width on its rear edge, sized by an ellipse (sqrt(1 - t^2), at least 0.15).
                float minX = verts.Min(v => v.x), maxX = verts.Max(v => v.x);
                int n = Mathf.Max(1, tg.trailCount);
                float slice = (maxX - minX) / n;
                var points = new List<Vector3>();
                var profile = new List<float>();
                for (int i = 0; i < n; i++)
                {
                    float x = n == 1 ? (minX + maxX) * 0.5f : Mathf.Lerp(minX + slice * 0.5f, maxX - slice * 0.5f, i / (float)(n - 1));
                    var inSlice = verts.Where(v => Mathf.Abs(v.x - x) <= slice * 0.5f).ToList();
                    if (inSlice.Count == 0) continue;
                    float rearZ = inSlice.Min(v => v.z);
                    float sliceDepth = inSlice.Max(v => v.z) - rearZ;
                    var edge = inSlice.Where(v => v.z <= rearZ + sliceDepth * 0.1f).ToList();
                    points.Add(new Vector3(x, edge.Average(v => v.y), rearZ));
                    float t = (x - (minX + maxX) * 0.5f) / ((maxX - minX) * 0.5f);
                    profile.Add(Mathf.Max(0.15f, Mathf.Sqrt(Mathf.Max(0f, 1f - t * t))));
                }
                g.trailPoints = points.ToArray();
                g.trailProfile = profile.ToArray();
            }
            else if (tg.trailWidth > 0f)
            {
                // A trail from the glow's rear end on each side (the rearmost 3 % of its length, averaged per side).
                float minZ = verts.Min(v => v.z), maxZ = verts.Max(v => v.z);
                float cut = minZ + (maxZ - minZ) * 0.03f;
                var rear = verts.Where(v => v.z <= cut).ToList();
                var points = new List<Vector3>();
                foreach (var side in new[] { rear.Where(v => v.x < 0f).ToList(), rear.Where(v => v.x >= 0f).ToList() })
                    if (side.Count > 0) points.Add(new Vector3(side.Average(v => v.x), side.Average(v => v.y), minZ));
                g.trailPoints = points.ToArray();
                g.trailProfile = new float[0];
            }
            if (tg.trailWidth > 0f)
            {
                g.trailWidth = tg.trailWidth * M;
                g.trailTime = tg.trailTime > 0f ? tg.trailTime : 0.6f;
                g.trailBrightness = tg.trailBrightness > 0f ? tg.trailBrightness : 0.3f;
            }
            return go;
        }
    }
}
