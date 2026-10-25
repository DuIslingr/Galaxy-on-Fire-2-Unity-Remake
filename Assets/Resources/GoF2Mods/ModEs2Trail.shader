// GoF2/ModEs2Trail: EVERSPACE 2's customization engine trails (the "Engine trail" / "Booster trail" choices,
// DT_ShipExhaustParticles) on a mod ship's engines (Modding.Es2Trails, driven by Modding.Es2EngineVfx), each kind its
// material's own formula transcribed from its compiled shader (2026-10-25: the materials' SP_PCD3D_SM5 pixel shaders
// disassembled; the ES2 importer's research/engine_trails.md has every formula and where it comes from). Units in the
// formulas are EVERSPACE 2's centimetres (a Unity metre is 100 / _Es2Scale of them). _Kind picks one:
//    0 Glitter (M_Vehicle_EngineTrail_Player_Glitter): a camera-facing sprite twinkling by T_Pattern_Barcode_001;
//    1 Smoke (M_..._Smoke): a lit sprite, T_Sphere_001_N's normal, T_SmokeSeamless_001_H's colour, T_SmokePuff_002_M's
//      opacity, a combustion glow fading with the particle's age;
//    2 Bubbles (M_..._Bubbles): a sphere-normal sprite with a highlight, popping by UE's texture-based simplex noise;
//    3 Sparks (M_Particle_Spark_001): a stadium on a velocity-aligned sprite;
//    4 Dark trail (M_..._DarkTrail), 5 Fire trail (M_..._FireTrail), 6 Speed lines (M_..._Lines), 7 the Lightning ribbon
//      (M_..._Lightning): ribbons;
//    8 the Lightning arcs (MI_Particle_Lightning_Arc): sprites growing out of a pivot at their left edge;
//    9 the cross shapes (M_Vehicle_EngineTrail_CrossShape): the Rings / Squares / Triangles meshes, two sided;
//   10 the veils (M_Vehicle_EngineTrail_Player_Veil, Ion Veils): a ribbon shaped by its dynamic parameters.
// Every material is alpha blended (BLEND_TranslucentGreyTransmittance) and unlit but Smoke; the emissive is x _Gain (EVERSPACE
// 2's exposure, its EmissiveExposureCompensation included, against the remake's: ModMaterials.Es2FlameGain / 1000).
// Geometry (built on the CPU each frame, object space): POSITION the anchor (a sprite's centre or pivot, a ribbon point, a
// mesh vertex), NORMAL a sprite's velocity / a ribbon's tangent / a mesh's normal, TEXCOORD0 the uv (a ribbon's U0, V),
// TEXCOORD1 a sprite's half size / a ribbon's (half width, side), TEXCOORD2 (rotation in radians, MaterialRandom, relative
// time, a ribbon's U1), TEXCOORD3 the dynamic parameter, COLOR the particle colour (HDR) and alpha.
Shader "GoF2/ModEs2Trail"
{
    Properties
    {
        _Kind ("Kind", Float) = 0
        _Gain ("EVERSPACE 2's emissive to the remake's", Float) = 0.3
        _Es2Scale ("Unity metres per EVERSPACE 2 metre", Float) = 3.6
        _SoftParticles ("The camera's depth texture is there (soft particles)", Float) = 0
        _MainTex ("Texture (noise, barcode, smoke colour)", 2D) = "white" {}
        _MaskTex ("Mask (smoke opacity)", 2D) = "white" {}
        _NormalTex ("Normal (T_Sphere_001_N)", 2D) = "bump" {}
        _GradTex ("UE's PerlinNoiseGradientTexture", 2D) = "grey" {}
        _Noise3D ("UE's PerlinNoise3DTexture", 3D) = "grey" {}
    }
    SubShader
    {
        Tags { "Queue" = "Transparent" "RenderType" = "Transparent" "IgnoreProjector" = "True" "RenderPipeline" = "UniversalPipeline" }
        Blend SrcAlpha OneMinusSrcAlpha
        ZWrite Off
        Cull Off

        Pass
        {
            Tags { "LightMode" = "UniversalForward" }
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma multi_compile_instancing
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Lighting.hlsl"
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/DeclareDepthTexture.hlsl"

            TEXTURE2D(_MainTex); SAMPLER(sampler_MainTex);
            TEXTURE2D(_MaskTex); SAMPLER(sampler_MaskTex);
            TEXTURE2D(_NormalTex); SAMPLER(sampler_NormalTex);
            TEXTURE2D(_GradTex); SAMPLER(sampler_GradTex);
            TEXTURE3D(_Noise3D); SAMPLER(sampler_Noise3D);
            CBUFFER_START(UnityPerMaterial)
                float4 _MainTex_ST, _MaskTex_ST, _NormalTex_ST, _GradTex_ST;
                float _Kind, _Gain, _Es2Scale, _SoftParticles;
            CBUFFER_END

            struct Attributes
            {
                float4 positionOS : POSITION; float3 normalOS : NORMAL; float2 uv : TEXCOORD0; float2 size : TEXCOORD1;
                float4 extra : TEXCOORD2; float4 dyn : TEXCOORD3; float4 color : COLOR; UNITY_VERTEX_INPUT_INSTANCE_ID
            };
            struct Varyings
            {
                float4 positionCS : SV_POSITION; float2 uv : TEXCOORD0; float4 color : COLOR; float3 positionWS : TEXCOORD1;
                float4 extra : TEXCOORD2; float4 dyn : TEXCOORD3; float3 normalWS : TEXCOORD4; float3 tangentWS : TEXCOORD5;
                float3 bitangentWS : TEXCOORD6; float2 size : TEXCOORD7; UNITY_VERTEX_OUTPUT_STEREO
            };

            // UE's x / ((1 / b - 2)(1 - x) + 1) (MF_Bias)
            float Bias(float x, float b) { return x / ((1.0 / max(b, 1e-4) - 2.0) * (1.0 - x) + 1.0); }
            // UE's pow with its zero guard (pow of <= 2.98e-8 is 0)
            float Pw(float x, float e) { return x <= 2.98023295e-08 ? 0 : pow(x, e); }
            // a pixel's view depth in EVERSPACE 2's cm
            float DepthCm(float3 positionWS) { return -TransformWorldToView(positionWS).z * 100.0 / max(_Es2Scale, 1e-4); }

            // UE's texture-based simplex noise (Random.ush SimplexNoise3D_TEX), View.PerlinNoiseGradientTexture
            float3 Grad(float3 c) { return SAMPLE_TEXTURE2D_LOD(_GradTex, sampler_GradTex, (c.xy + c.z * float2(17, 89) + 0.5) * 0.0078125, 0).rgb * 2 - 1; }
            float Simplex(float3 p)
            {
                float3 o = p + dot(p, 1.0 / 3.0);
                float3 i0 = floor(o), f = o - i0;
                float mx = max(f.z, max(f.y, f.x)), mn = min(f.z, min(f.y, f.x));
                float3 i3 = i0 + 1, i1 = i0 + (f == mx ? 1 : 0), i2 = i0 + (f != mn ? 1 : 0);
                float3 c[4] = { i0, i3, i1, i2 };
                float sum = 0;
                [unroll] for (int k = 0; k < 4; k++)
                {
                    float3 d = p - (c[k] - dot(c[k], 1.0 / 6.0));
                    float w = max(0.6 - dot(d, d), 0);
                    w *= w; w *= w;
                    sum += w * dot(Grad(c[k]), d);
                }
                return sum * 32;
            }

            // UE's texture-based gradient noise (View.PerlinNoise3DTexture: gradient x 127 + 127, alpha 127 + dot(gradient,
            // texel)), tiling every 15, hardware-filtered at the quintic-smoothed coordinate
            float GradientNoise(float3 p, float freq, float ampMul, bool turbulence)
            {
                float sum = 0, amp = 1;
                [loop] for (int k = 0; k < 6; k++)
                {
                    float3 m = frac(p * (1.0 / 15.0)) * 15;
                    float3 f = frac(m), c = m - f;
                    float3 s = f * f * f * (f * (f * 6 - 15) + 10) + c;
                    float4 t = SAMPLE_TEXTURE3D_LOD(_Noise3D, sampler_Noise3D, s * 0.0625 + 0.03125, 0) * 255;
                    float v = dot(m, t.xyz * (1.0 / 127.0) - 1) - (t.w - 127);
                    sum += amp * (turbulence ? abs(v) : v);
                    p *= freq; amp *= ampMul;
                }
                return sum;
            }

            Varyings vert(Attributes i)
            {
                Varyings o = (Varyings)0;
                UNITY_SETUP_INSTANCE_ID(i);
                UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o);
                int kind = (int)round(_Kind);
                float3 p = TransformObjectToWorld(i.positionOS.xyz);
                float scale = length(float3(UNITY_MATRIX_M[0].x, UNITY_MATRIX_M[1].x, UNITY_MATRIX_M[2].x));
                float3 toCam = normalize(_WorldSpaceCameraPos - p);
                float2 c = i.uv * 2 - 1;
                float3 nrm = toCam, tan = UNITY_MATRIX_V[0].xyz, bit = UNITY_MATRIX_V[1].xyz;
                if (kind == 0 || kind == 1 || kind == 2 || kind == 8)
                {
                    // facing the camera (FaceCamera), turned by the sprite's rotation; the arcs' pivot is their left edge
                    float3 up0 = UNITY_MATRIX_V[1].xyz;
                    float3 right = normalize(cross(up0, toCam));
                    float3 up = cross(toCam, right);
                    float sn, cs; sincos(i.extra.x, sn, cs);
                    float3 r = right * cs + up * sn, u = -right * sn + up * cs;
                    float2 corner = kind == 8 ? float2(i.uv.x * 2, c.y) : c;
                    // (UE's v runs down the sprite)
                    p += (r * corner.x * i.size.x - u * corner.y * i.size.y) * scale;
                    tan = r; bit = -u;
                }
                else if (kind == 3)
                {
                    // velocity aligned: v along the velocity, u across it facing the camera
                    float3 axis = normalize(TransformObjectToWorldDir(i.normalOS));
                    float3 side = cross(axis, toCam);
                    side = length(side) > 1e-5 ? normalize(side) : normalize(cross(axis, float3(0, 1, 0.01)));
                    p += (side * c.x * i.size.x + axis * c.y * i.size.y) * scale;
                }
                else if (kind == 9)
                {
                    nrm = TransformObjectToWorldNormal(i.normalOS);
                }
                else
                {
                    // a ribbon point: across its tangent, facing the camera
                    float3 axis = TransformObjectToWorldDir(i.normalOS);
                    float3 side = cross(axis, toCam);
                    side = length(side) > 1e-5 ? normalize(side) : float3(0, 0, 0);
                    p += side * i.size.x * i.size.y * scale;
                }
                o.positionCS = TransformWorldToHClip(p);
                o.positionWS = p;
                o.uv = i.uv;
                o.color = i.color;
                o.extra = i.extra;
                o.dyn = i.dyn;
                o.normalWS = nrm; o.tangentWS = tan; o.bitangentWS = bit;
                o.size = i.size;
                return o;
            }

            float SceneFadeCm(float4 positionCS, float3 positionWS, float perCm)
            {
                if (_SoftParticles < 0.5) return 1;
                float2 suv = positionCS.xy / _ScaledScreenParams.xy;
                float scene = LinearEyeDepth(SampleSceneDepth(suv), _ZBufferParams) * 100.0 / max(_Es2Scale, 1e-4);
                return saturate((scene - DepthCm(positionWS)) * perCm);
            }

            half4 frag(Varyings i, bool front : SV_IsFrontFace) : SV_Target
            {
                UNITY_SETUP_STEREO_EYE_INDEX_POST_VERTEX(i);
                int kind = (int)round(_Kind);
                float2 uv = i.uv;
                float t = _Time.y;
                float alpha = i.color.a;
                float3 col = i.color.rgb;
                float3 V = normalize(_WorldSpaceCameraPos - i.positionWS);

                if (kind == 0)   // Glitter
                {
                    float b = SAMPLE_TEXTURE2D_LOD(_MainTex, sampler_MainTex, float2(t * 0.5 + i.extra.y, 0), 0).r;
                    float tw = b <= 2.98023295e-08 ? 0 : saturate((sqrt(b) - 0.5) * 2);
                    float3 e = col * tw * 40 + col;
                    float r = max(1 - length(0.5 - uv) * 2, 0);
                    float a = r / ((1.0 / (0.05 - 0.04375 * tw) - 2) * (1 - r) + 1);
                    a = a <= 2.98023295e-08 ? 0 : a * a * a * alpha;
                    float dist = length(i.positionWS - _WorldSpaceCameraPos) * 100.0 / max(_Es2Scale, 1e-4);
                    return half4(e * _Gain, saturate(a * min(dist * 0.002, 1)));
                }
                if (kind == 1)   // Smoke
                {
                    float2 n2 = UnpackNormal(SAMPLE_TEXTURE2D(_NormalTex, sampler_NormalTex, uv)).xy;
                    float3 nt = float3(n2, sqrt(max(1 - dot(n2, n2), 0)));
                    float3 N = normalize(nt.x * i.tangentWS + nt.y * i.bitangentWS + nt.z * i.normalWS);
                    float s = 1 - i.extra.z;
                    float glow = s / (1 + (1 - s) * 18);
                    float3 e = glow <= 2.98023295e-08 ? 0 : pow(glow, 2.5) * col;
                    float h = SAMPLE_TEXTURE2D(_MainTex, sampler_MainTex, uv * 0.5 + i.dyn.x).r;
                    float baseC = saturate((i.extra.y * 0.5 + 0.5) * 0.3 * (h <= 2.98023295e-08 ? 0 : sqrt(h)));
                    Light L = GetMainLight();
                    float3 lit = SampleSH(N) + L.color * saturate(dot(N, L.direction));
                    float op = SAMPLE_TEXTURE2D(_MaskTex, sampler_MaskTex, uv).r * alpha;
                    op = saturate(op * SceneFadeCm(i.positionCS, i.positionWS, 0.005));
                    return half4(baseC * lit + e * _Gain, op);
                }
                if (kind == 2)   // Bubbles
                {
                    float2 n2 = UnpackNormal(SAMPLE_TEXTURE2D(_NormalTex, sampler_NormalTex, uv)).xy;
                    float nz = sqrt(max(1 - dot(n2, n2), 0));
                    float3 N = n2.x * i.tangentWS + n2.y * i.bitangentWS + nz * i.normalWS;
                    float3 H = normalize(V + 0.1);
                    float spec = saturate((saturate(dot(H, N)) - 0.95) * 20);
                    spec = spec <= 2.98023295e-08 ? 0 : spec * spec * 10;
                    float3 e = spec + col;
                    float r = max(1 - length(0.5 - uv) * 2, 0);
                    float edge = 1 - r;
                    float e3 = edge <= 2.98023295e-08 ? 0 : edge * edge * edge;
                    float turb = abs(Simplex(float3(n2 * 0.5 * e3, i.dyn.x)));
                    float keep = edge * (1 - turb) >= 1 - alpha ? 1 : 0;
                    float fr = max(abs(1 - max(dot(N, V), 0)), 1e-4);
                    fr = fr * fr * fr * 0.98 + 0.02;
                    return half4(e * _Gain, saturate(fr * min(r * 50, 1) * keep));
                }
                if (kind == 3)   // Sparks
                {
                    float2 s = normalize(i.size.yx);
                    float2 q = max((uv - (1 - s)) / s, min(uv / s, 0.5));
                    float d = length(0.5 - q) * 2;
                    float a = min(max(1 - d, 0) * 10, 1);
                    a = a <= 2.98023295e-08 || alpha <= 2.98023295e-08 ? 0 : min(alpha * alpha * a * a, 1);
                    return half4(col * _Gain, a);
                }
                float across = max(1 - abs(uv.y * 2 - 1), 0);
                float u1 = i.extra.w;
                if (kind == 4)   // Dark trail
                {
                    float v = uv.y <= 0.5 ? uv.y : 1.5 - uv.y;
                    float2 nuv = float2(-t * 0.7 + uv.x * 0.15, v * 0.3) + i.dyn.x;
                    float n = 1 - SAMPLE_TEXTURE2D(_MainTex, sampler_MainTex, nuv).r;
                    float ex = n <= 2.98023295e-08 ? 0 : n * n * n;
                    float p = Pw(across, 1.0 / max(ex, 1e-6));
                    float k = 1 - p;
                    float3 e = k <= 2.98023295e-08 ? 0 : pow(k, 32) * col;
                    float A = Pw(Bias(across, p), 1.5);
                    float z = saturate(u1);
                    float tail = min((1 - z) * 5, 1);
                    float along = z <= 2.98023295e-08 || tail <= 2.98023295e-08 ? 0 : tail * tail * pow(z, 2.5);
                    float cam = saturate((DepthCm(i.positionWS) - 24) * 0.005);
                    cam = cam <= 2.98023295e-08 ? 0 : cam * cam;
                    return half4(e * _Gain, saturate(cam * A * along * alpha));
                }
                if (kind == 5)   // Fire trail
                {
                    float2 b = float2(-t * 3 + uv.x * 0.5, uv.y * 0.5) + i.dyn.x;
                    float n1 = SAMPLE_TEXTURE2D(_MainTex, sampler_MainTex, b + float2(0, t * 0.7)).r;
                    float n2 = SAMPLE_TEXTURE2D(_MainTex, sampler_MainTex, b + float2(-t * 0.7, 0) + 0.5).r;
                    float m = min(n1, n2) * across;
                    m = m <= 2.98023295e-08 ? 0 : m * m;
                    float s = saturate(1 - u1);
                    float g = Pw(s / (1 + (1 - s) * 18), 1.5);
                    float head = min((1 - s) * 10, 1);
                    float along = head <= 2.98023295e-08 ? 0 : head * head * g;
                    float soft = SceneFadeCm(i.positionCS, i.positionWS, 0.002);
                    soft = soft <= 2.98023295e-08 ? 0 : soft * soft;
                    return half4(col * _Gain, saturate(soft * m * along * alpha));
                }
                if (kind == 6)   // Speed lines
                {
                    float2 nuv = float2(uv.x * 0.05 - t * 0.2, uv.y) * 0.25 + i.dyn.x;
                    float n = SAMPLE_TEXTURE2D(_MainTex, sampler_MainTex, nuv).r;
                    n = n <= 2.98023295e-08 ? 0 : sqrt(n);
                    n = saturate((n - 0.3) * (1.0 / 0.7));
                    float s = saturate(1 - u1);
                    float head = min((1 - s) * 10, 1);
                    float along = head <= 2.98023295e-08 ? 0 : s / (1 + (1 - s) * 18) * head * head;
                    return half4(col * _Gain, saturate(n * across * along * alpha));
                }
                if (kind == 7)   // the Lightning ribbon
                {
                    float3 np = float3(float2(uv.x - t * 2, uv.y * 0.25) * 2, t * 5) + i.dyn.x;
                    float n = GradientNoise(np, 2, 0.5, true) * 2 - 1;
                    float s = saturate(1 - u1);
                    float d = Pw(1 - s, 0.25) * 0.5;
                    float y = n * d + uv.y;
                    float band = min(max(1 - abs(y * 2 - 1), 0) * 1.01010096, 1);
                    band = band / ((1 - band) * 98 + 1);
                    band = band <= 2.98023295e-08 ? 0 : band * band;
                    float g = Pw(s / (1 + (1 - s) * 18), 1.5);
                    float head = min((1 - s) * 20, 1);
                    float along = head <= 2.98023295e-08 ? 0 : head * head * g;
                    return half4(col * _Gain, saturate(band * along * alpha));
                }
                if (kind == 8)   // the Lightning arcs
                {
                    float n = GradientNoise(float3((uv + i.dyn.xy) * 3, 3), 3, 1.0 / 3.0, false);
                    float s = saturate(1 - uv.x);
                    // (0.25 x the second dynamic parameter's x, 1, + 0.05)
                    float amp = Pw(1 - s, 0.2) * 0.3;
                    float y = n * amp + uv.y;
                    float band = max(1 - abs(y * 2 - 1), 0);
                    float cam = DepthCm(i.positionWS) > 24 ? 1 : 0;
                    float core = Pw(saturate((band - (1 - 0.05 * cam)) / (0.05 * cam + 1e-6)), 16);
                    float e = (1 - i.dyn.z) * 1.2 - 0.1;
                    float w = smoothstep(e - 0.05, e + 0.05, s);
                    float k = 1 - w;
                    float glow = k <= 2.98023295e-08 ? 0 : k * k * 1000;
                    float3 c3 = col * core * glow + col;
                    float fl = SAMPLE_TEXTURE2D_LOD(_MainTex, sampler_MainTex, float2(t, 0), 0).r;
                    fl = fl <= 2.98023295e-08 ? 0 : sqrt(fl);
                    float a2 = alpha <= 2.98023295e-08 ? 0 : alpha * alpha;
                    float body = i.dyn.w * Bias(band, 2e-4 * cam) + core;
                    float len = max(1 - abs(uv.x * 2 - 1), 0);
                    len = len <= 2.98023295e-08 ? 0 : len * len * w;
                    return half4(c3 * _Gain, saturate(a2 * body * len * cam * fl));
                }
                if (kind == 9)   // the cross shapes
                {
                    float g = uv.x / ((1 - uv.x) * 3 + 1);
                    float g3 = g <= 2.98023295e-08 ? 0 : g * g * g * alpha;
                    float cam = saturate((DepthCm(i.positionWS) - 24) * 0.002);
                    float3 N = normalize(i.normalWS) * (front ? 1 : -1);
                    float f = abs(dot(N, V));
                    f = f <= 2.98023295e-08 ? 0 : f * f;
                    return half4(col * _Gain, saturate(f * cam * g3));
                }
                // the veils: across Bias(a, Dyn.x)^Dyn.y, along Bias(1 - u, Dyn.z)^Dyn.w x min(20 u, 1)^2
                {
                    float A = Pw(Bias(across, i.dyn.x), i.dyn.y);
                    float b = saturate(1 - uv.x);
                    float B = Pw(Bias(b, i.dyn.z), i.dyn.w);
                    float head = min((1 - b) * 20, 1);
                    float op = A * B * head * head * alpha;
                    float dist = DepthCm(i.positionWS) * 0.01;
                    op = saturate(op * saturate((dist - 0.24) * 0.2));
                    return half4(col * _Gain, op);
                }
            }
            ENDHLSL
        }
    }
}
