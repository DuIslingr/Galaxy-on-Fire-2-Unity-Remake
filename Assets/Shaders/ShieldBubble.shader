// GoF2/ShieldBubble: the emergency system's bubble (mesh 14374 v_shield, material 27150; AbyssEngine::SimpleRefractionShader,
// combat_equipment.md 2). The sphere itself is invisible: it shows the screen behind it, pushed by the noise texture's
// xy toward the rim (coord = fragCoord + (noise.xy - 0.5) * rim * 180 px at 1024x768, rim = smoothstep(0, 1, 1 - N.V)).
// _Anim scrolls the noise (mesh+0x24 += dt * 0.001). Reads _CameraOpaqueTexture (the camera's opaque texture must be on).
Shader "GoF2/ShieldBubble"
{
    Properties
    {
        _NoiseMap ("Noise", 2D) = "gray" {}
        _Anim ("Anim", Float) = 0
        _Strength ("Strength", Float) = 1
    }
    SubShader
    {
        Tags { "Queue" = "Transparent+10" "RenderType" = "Transparent" "RenderPipeline" = "UniversalPipeline" }
        ZWrite Off
        Cull Back

        Pass
        {
            Tags { "LightMode" = "UniversalForward" }
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/DeclareOpaqueTexture.hlsl"

            TEXTURE2D(_NoiseMap); SAMPLER(sampler_NoiseMap);
            CBUFFER_START(UnityPerMaterial)
                float4 _NoiseMap_ST;
                float _Anim, _Strength;
            CBUFFER_END

            struct Attributes { float4 positionOS : POSITION; float3 normalOS : NORMAL; float2 uv : TEXCOORD0; };
            struct Varyings { float4 positionCS : SV_POSITION; float2 uv : TEXCOORD0; float3 normalWS : TEXCOORD1; float3 viewWS : TEXCOORD2; };

            Varyings vert(Attributes i)
            {
                Varyings o;
                float3 ws = TransformObjectToWorld(i.positionOS.xyz);
                o.positionCS = TransformWorldToHClip(ws);
                o.uv = i.uv;
                o.normalWS = TransformObjectToWorldNormal(i.normalOS);
                o.viewWS = GetWorldSpaceViewDir(ws);
                return o;
            }

            half4 frag(Varyings i) : SV_Target
            {
                half4 noise = SAMPLE_TEXTURE2D(_NoiseMap, sampler_NoiseMap, i.uv + float2(_Anim * 0.05, _Anim * 0.03));
                float rim = smoothstep(0.0, 1.0, 1.0 - saturate(dot(normalize(i.viewWS), normalize(i.normalWS))));
                float2 suv = GetNormalizedScreenSpaceUV(i.positionCS);
                float2 offset = (noise.xy - 0.5) * rim * 180.0 * _Strength / float2(1024.0, 768.0);
                return half4(SampleSceneColor(saturate(suv + offset)), 1);
            }
            ENDHLSL
        }
    }
}
