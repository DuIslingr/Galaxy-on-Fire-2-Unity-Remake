// GoF2/Cloak: the player's cloak (AbyssEngine::BumpShaderCloak, shader type 0xe; combat_equipment.md 1.6). The hull is
// lit like before, then dissolves by cloak_map.png into the screen behind it, refracted by the normal map with a slow
// wobble (x + n.x * 100 * sin(rate), y + n.y * 75 * cos(rate) at 1024x768), with a light-blue (0.6, 0.8, 1.0) edge.
// _AnimValue 0..0.5 dissolves the opaque hull, 0.5..0.75 blends into pure refraction (a glass silhouette).
// Rendered after the opaques and reads _CameraOpaqueTexture (the camera's opaque texture must be on).
Shader "GoF2/Cloak"
{
    Properties
    {
        _BaseMap ("Base", 2D) = "white" {}
        [Normal] _BumpMap ("Normal", 2D) = "bump" {}
        _CloakMap ("Cloak map", 2D) = "white" {}
        _AnimValue ("Anim value", Range(0, 1)) = 0
        _CloakRate ("Cloak rate", Float) = 0
    }
    SubShader
    {
        Tags { "Queue" = "Transparent" "RenderType" = "Transparent" "RenderPipeline" = "UniversalPipeline" }
        ZWrite On
        Cull Back

        Pass
        {
            Tags { "LightMode" = "UniversalForward" }
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Lighting.hlsl"
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/DeclareOpaqueTexture.hlsl"

            TEXTURE2D(_BaseMap); SAMPLER(sampler_BaseMap);
            TEXTURE2D(_BumpMap); SAMPLER(sampler_BumpMap);
            TEXTURE2D(_CloakMap); SAMPLER(sampler_CloakMap);
            CBUFFER_START(UnityPerMaterial)
                float4 _BaseMap_ST;
                float _AnimValue, _CloakRate;
            CBUFFER_END

            struct Attributes { float4 positionOS : POSITION; float3 normalOS : NORMAL; float4 tangentOS : TANGENT; float2 uv : TEXCOORD0; };
            struct Varyings
            {
                float4 positionCS : SV_POSITION;
                float2 uv : TEXCOORD0;
                float3 normalWS : TEXCOORD1;
                float4 tangentWS : TEXCOORD2;
            };

            Varyings vert(Attributes i)
            {
                Varyings o;
                o.positionCS = TransformObjectToHClip(i.positionOS.xyz);
                o.uv = i.uv;
                VertexNormalInputs n = GetVertexNormalInputs(i.normalOS, i.tangentOS);
                o.normalWS = n.normalWS;
                o.tangentWS = float4(n.tangentWS, i.tangentOS.w * GetOddNegativeScale());
                return o;
            }

            half4 frag(Varyings i) : SV_Target
            {
                half3 nTS = UnpackNormal(SAMPLE_TEXTURE2D(_BumpMap, sampler_BumpMap, i.uv));
                float3 bit = i.tangentWS.w * cross(i.normalWS, i.tangentWS.xyz);
                float3 nWS = normalize(mul(nTS, float3x3(i.tangentWS.xyz, bit, i.normalWS)));
                half3 albedo = SAMPLE_TEXTURE2D(_BaseMap, sampler_BaseMap, i.uv).rgb;
                Light main = GetMainLight();
                half3 lit = albedo * (main.color * saturate(dot(nWS, main.direction)) + SampleSH(nWS));

                float2 suv = GetNormalizedScreenSpaceUV(i.positionCS);
                float2 wobble = float2(nTS.x * 100.0 * sin(_CloakRate), nTS.y * 75.0 * cos(_CloakRate)) / float2(1024.0, 768.0);
                half3 refr = SampleSceneColor(saturate(suv + wobble));

                float d = SAMPLE_TEXTURE2D(_CloakMap, sampler_CloakMap, i.uv).r;
                float dissolve = saturate(_AnimValue * 2.0);
                float through = step(d - 0.025, dissolve) * step(0.001, dissolve);
                float edge = through * step(dissolve - 0.05, d);
                half3 col = lerp(lit, refr, through) + half3(0.6, 0.8, 1.0) * edge;
                col = lerp(col, refr, saturate((_AnimValue - 0.5) * 4.0));
                return half4(col, 1);
            }
            ENDHLSL
        }
    }
}
