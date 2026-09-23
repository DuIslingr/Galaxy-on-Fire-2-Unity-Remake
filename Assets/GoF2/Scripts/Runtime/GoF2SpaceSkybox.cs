// GoF2SpaceSkybox.cs
// The space background, drawn the way the original does it (Level::createSpace / Level::renderBG): the
// stars layer (skybox_stars with texture skybox_stars_00(systemIndex % 3)) first, then the nebula mesh
// skybox_0XX (texture = SolarSystem textureIndex) added on top, both centred on the camera and never
// occluding anything (GoF2/SkyUnlit + GoF2/SkyAdditive: ZTest Always, ZWrite off, background queue).
// The game's low-res reflection cubemap (cubemap_skybox_0XX) becomes the Unity skybox so URP gets
// matching ambient light and reflections; it is fully covered by the sky meshes.

using UnityEngine;
using UnityEngine.Rendering;

namespace GoF2Remake.Visuals
{
    [DisallowMultipleComponent]
    [ExecuteAlways]
    public class GoF2SpaceSkybox : MonoBehaviour
    {
        [Tooltip("Camera the sky follows (defaults to Camera.main).")]
        public Camera targetCamera;

        public Mesh starsMesh;
        public Texture starsTexture;
        public Mesh nebulaMesh;
        public Texture nebulaTexture;
        [Tooltip("cubemap_skybox_0XX: ambient light and reflections.")]
        public Cubemap reflectionCubemap;

        [Tooltip("GoF2/SkyUnlit, GoF2/SkyAdditive and Skybox/Cubemap.")]
        public Shader skyUnlitShader;
        public Shader skyAdditiveShader;
        public Shader skyboxShader;

        [Range(0f, 4f)] public float nebulaBrightness = 1f;
        [Range(0f, 4f)] public float starsBrightness = 1f;
        [Range(0f, 8f)] public float ambientIntensity = 1f;

        Transform root;
        Material starsMat, nebulaMat, skyboxMat;

        void OnEnable() => Build();
        void OnDisable() => Teardown();
        void OnValidate() { if (isActiveAndEnabled) { Teardown(); Build(); } }

        void Build()
        {
            if (nebulaMesh == null || skyUnlitShader == null || skyAdditiveShader == null) return;
            root = new GameObject("GoF2 Sky") { hideFlags = HideFlags.HideAndDontSave }.transform;
            if (starsMesh != null) starsMat = Layer(starsMesh, skyUnlitShader, starsTexture, starsBrightness, 1000);
            nebulaMat = Layer(nebulaMesh, skyAdditiveShader, nebulaTexture, nebulaBrightness, 1001);

            if (reflectionCubemap != null && skyboxShader != null)
            {
                skyboxMat = new Material(skyboxShader) { name = "GoF2 Reflection Sky", hideFlags = HideFlags.HideAndDontSave };
                skyboxMat.SetTexture("_Tex", reflectionCubemap);
                RenderSettings.skybox = skyboxMat;
                RenderSettings.ambientMode = AmbientMode.Skybox;
                RenderSettings.ambientIntensity = ambientIntensity;
                RenderSettings.defaultReflectionMode = DefaultReflectionMode.Skybox;
                DynamicGI.UpdateEnvironment();
            }
        }

        Material Layer(Mesh mesh, Shader shader, Texture tex, float glow, int queue)
        {
            var go = new GameObject(mesh.name) { hideFlags = HideFlags.HideAndDontSave };
            go.transform.SetParent(root, false);
            go.AddComponent<MeshFilter>().sharedMesh = mesh;
            var mat = new Material(shader) { renderQueue = queue, hideFlags = HideFlags.HideAndDontSave };
            mat.SetTexture("_MainTex", tex);
            mat.SetFloat("_Glow", glow);
            var r = go.AddComponent<MeshRenderer>();
            r.sharedMaterial = mat;
            r.shadowCastingMode = ShadowCastingMode.Off;
            r.receiveShadows = false;
            r.allowOcclusionWhenDynamic = false;
            return mat;
        }

        void LateUpdate()
        {
            if (root == null) return;
            var cam = targetCamera != null ? targetCamera : Camera.main;
            if (cam != null) root.position = cam.transform.position;
        }

        void Teardown()
        {
            if (RenderSettings.skybox == skyboxMat && skyboxMat != null) RenderSettings.skybox = null;
            DestroyNow(starsMat); DestroyNow(nebulaMat); DestroyNow(skyboxMat);
            if (root != null) DestroyNow(root.gameObject);
            root = null; starsMat = nebulaMat = skyboxMat = null;
        }

        static void DestroyNow(Object o)
        {
            if (o == null) return;
            if (Application.isPlaying) Destroy(o); else DestroyImmediate(o);
        }
    }
}
