// GoF2/WarpTunnel: the tube around the camera between the systems (Visuals.WarpTunnel, InterstellarSpace): three scrolling
// layers added over the sky, strongest in the middle of the tube and gone at its ends. The look of EVERSPACE 2's travel
// mode (additive, unlit, two-sided, noise run along the flight); its textures come from a mod's warp.json (Modding.ModWarp),
// else WarpTunnel makes its own. In Resources so a build keeps it: only code asks for it.
Shader "GoF2/WarpTunnel"
{
    Properties
    {
        _Noise ("Noise", 2D) = "black" {}
        _Detail ("Detail", 2D) = "white" {}
        _Streaks ("Streaks", 2D) = "black" {}
        [HDR] _Tint ("Tint", Color) = (0.55, 0.8, 1, 1)
        _Level ("Level", Float) = 0
        _Scroll ("Scroll", Float) = 0
    }
    SubShader
    {
        Tags { "Queue" = "Transparent+50" "RenderType" = "Transparent" "IgnoreProjector" = "True" }
        Blend One One
        ZWrite Off
        Cull Off

        Pass
        {
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma multi_compile_instancing
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"

            TEXTURE2D(_Noise); SAMPLER(sampler_Noise);
            TEXTURE2D(_Detail); SAMPLER(sampler_Detail);
            TEXTURE2D(_Streaks); SAMPLER(sampler_Streaks);
            CBUFFER_START(UnityPerMaterial)
                float4 _Noise_ST, _Detail_ST, _Streaks_ST;
                half4 _Tint;
                float _Level, _Scroll;
            CBUFFER_END

            struct Attributes { float4 positionOS : POSITION; float2 uv : TEXCOORD0; UNITY_VERTEX_INPUT_INSTANCE_ID };
            struct Varyings { float4 positionCS : SV_POSITION; float2 uv : TEXCOORD0; UNITY_VERTEX_OUTPUT_STEREO };

            Varyings vert(Attributes i)
            {
                Varyings o;
                UNITY_SETUP_INSTANCE_ID(i);
                UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o);
                o.positionCS = TransformObjectToHClip(i.positionOS.xyz);
                o.uv = i.uv;
                return o;
            }

            half4 frag(Varyings i) : SV_Target
            {
                UNITY_SETUP_STEREO_EYE_INDEX_POST_VERTEX(i);
                float along = i.uv.y;
                half noise = SAMPLE_TEXTURE2D(_Noise, sampler_Noise, float2(i.uv.x, along * 2 - _Scroll * 0.6)).r;
                half detail = SAMPLE_TEXTURE2D(_Detail, sampler_Detail, float2(i.uv.x * 2 + 0.13, along * 3 - _Scroll)).r;
                half streaks = SAMPLE_TEXTURE2D(_Streaks, sampler_Streaks, float2(i.uv.x * 6, along * 1.2 - _Scroll * 1.8)).r;
                half ends = smoothstep(0, 0.25, along) * smoothstep(1, 0.6, along);
                half glow = noise * detail * 2 + streaks * streaks * 1.5;
                return half4(_Tint.rgb * glow * ends * _Level, 0);
            }
            ENDHLSL
        }
    }
}
