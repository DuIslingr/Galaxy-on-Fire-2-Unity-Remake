// GoF2/ModEngineFlow: the exhaust cards of a mod's Galaxy on Fire 3 engine (EngineFx's cone, ships.json "engineFx"). GoF3
// draws them with its UVAnim flow (every engine's exhaust material: UVAnim_Enabled, FlowOnly, UVAnim_SpeedMultiplier /
// FlowStrength / FlowTiling): the texture is pushed around by a flow field that keeps moving, so the plume churns instead of
// standing still. Its flow map is named by GUID only, so the field here is smooth noise drifting down the exhaust, read the
// usual two-phase way (two copies of the texture, each pushed further along the field through its phase and faded out as it
// wraps). Otherwise as GoF2/Additive: the texture x vertex colour x _Color x _Glow, added on, fogged toward black.
Shader "GoF2/ModEngineFlow"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "white" {}
        _Color ("Colour", Color) = (1, 1, 1, 1)
        _Glow ("Glow", Float) = 1
        _FlowSpeed ("Flow speed (phases /s)", Float) = 1
        _FlowStrength ("Flow strength", Float) = 1
        _FlowTiling ("Flow tiling", Float) = 0.5
    }
    SubShader
    {
        Tags { "Queue" = "Transparent" "RenderType" = "Transparent" "IgnoreProjector" = "True" "RenderPipeline" = "UniversalPipeline" }
        Blend One One
        ZWrite Off
        ZTest LEqual
        Cull Off

        Pass
        {
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma multi_compile_instancing
            #pragma multi_compile_fog
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"

            TEXTURE2D(_MainTex); SAMPLER(sampler_MainTex);
            CBUFFER_START(UnityPerMaterial)
                float4 _MainTex_ST;
                half4 _Color;
                float _Glow, _FlowSpeed, _FlowStrength, _FlowTiling;
            CBUFFER_END

            struct Attributes { float4 positionOS : POSITION; float2 uv : TEXCOORD0; half4 color : COLOR; UNITY_VERTEX_INPUT_INSTANCE_ID };
            struct Varyings
            {
                float4 positionCS : SV_POSITION;
                float2 uv : TEXCOORD0;
                half4 color : COLOR;
                float fog : TEXCOORD1;
                UNITY_VERTEX_OUTPUT_STEREO
            };

            Varyings vert(Attributes i)
            {
                Varyings o;
                UNITY_SETUP_INSTANCE_ID(i);
                UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o);
                o.positionCS = TransformObjectToHClip(i.positionOS.xyz);
                o.uv = TRANSFORM_TEX(i.uv, _MainTex);
                o.color = i.color;
                o.fog = ComputeFogFactor(o.positionCS.z);
                return o;
            }

            float Hash(float2 p) { return frac(sin(dot(p, float2(127.1, 311.7))) * 43758.5453); }

            // Smooth value noise, 0..1.
            float Noise(float2 p)
            {
                float2 i = floor(p), f = frac(p);
                f = f * f * (3.0 - 2.0 * f);
                return lerp(lerp(Hash(i), Hash(i + float2(1, 0)), f.x), lerp(Hash(i + float2(0, 1)), Hash(i + float2(1, 1)), f.x), f.y);
            }

            half4 frag(Varyings i) : SV_Target
            {
                UNITY_SETUP_STEREO_EYE_INDEX_POST_VERTEX(i);
                float t = _Time.y * _FlowSpeed;
                // The field: noise at the flow's tiling (u runs down the exhaust, v across a card), drifting downstream.
                float2 p = float2(i.uv.x * 6.0, i.uv.y * 2.0) * (_FlowTiling * 4.0) - float2(t * 0.5, 0.0);
                float2 flow = (float2(Noise(p), Noise(p + float2(17.3, 5.1))) * 2.0 - 1.0) * (_FlowStrength * float2(0.05, 0.12));
                float ph0 = frac(t), ph1 = frac(t + 0.5);
                half4 a = SAMPLE_TEXTURE2D(_MainTex, sampler_MainTex, i.uv + flow * ph0);
                half4 b = SAMPLE_TEXTURE2D(_MainTex, sampler_MainTex, i.uv + flow * ph1);
                half4 tex = lerp(a, b, abs(0.5 - ph0) * 2.0);
                half4 c = tex * i.color * _Color;
                half3 rgb = c.rgb * c.a * _Glow;
                return half4(MixFogColor(rgb, half3(0, 0, 0), i.fog), 0);
            }
            ENDHLSL
        }
    }
}
