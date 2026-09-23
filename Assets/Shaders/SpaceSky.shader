// GoF2/SpaceSky: the flight-level skybox. Level::renderBG draws the stars sphere (opaque) and adds the nebula sphere
// on top, both rotated by the per-station R_sky. Here both layers are baked cubemaps (GoF2 > Bake Space Skies),
// added together and sampled through _SkyRotation (world direction -> baked cube direction), which the built-in
// Skybox/Cubemap can't do (Y rotation only). Set as RenderSettings.skybox, so it also drives ambient + reflections.
// Hand-written because Shader Graph has no skybox target.
Shader "GoF2/SpaceSky"
{
    Properties
    {
        [NoScaleOffset] _Stars ("Stars", Cube) = "black" {}
        [NoScaleOffset] _Nebula ("Nebula (added)", Cube) = "black" {}
        _Exposure ("Exposure", Float) = 1
    }
    SubShader
    {
        Tags { "Queue" = "Background" "RenderType" = "Background" "PreviewType" = "Skybox" }
        Cull Off ZWrite Off

        Pass
        {
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"

            TEXTURECUBE(_Stars);  SAMPLER(sampler_Stars);
            TEXTURECUBE(_Nebula); SAMPLER(sampler_Nebula);
            float4x4 _SkyRotation;   // world direction -> baked cube direction, set by GoF2SpaceLevel
            half _Exposure;

            struct Attributes { float4 positionOS : POSITION; };
            struct Varyings { float4 positionCS : SV_POSITION; float3 dir : TEXCOORD0; };

            Varyings vert(Attributes i)
            {
                Varyings o;
                o.positionCS = TransformObjectToHClip(i.positionOS.xyz);
                o.dir = mul((float3x3)_SkyRotation, i.positionOS.xyz);
                return o;
            }

            half4 frag(Varyings i) : SV_Target
            {
                half3 c = SAMPLE_TEXTURECUBE(_Stars, sampler_Stars, i.dir).rgb + SAMPLE_TEXTURECUBE(_Nebula, sampler_Nebula, i.dir).rgb;
                return half4(c * _Exposure, 1);
            }
            ENDHLSL
        }
    }
}
