// GoF2/ModUnlit: a mod model's unlit material (a glTF material whose "extras" carry "unlit", ModMaterials.UnlitFromGltf),
// first for the GoF3 Systems mod's star map scenes (systems.json "mapScene"): Galaxy on Fire 3's map materials as its GLSL
// draws them, worked in gamma like GoF3 (its framebuffer isn't sRGB) and turned back to linear for the blend:
//   colour = texture x _Color (GoF3: Opacity, or DiffuseColor x Opacity without a texture) [x vertex colour]
//   colorize (GoF3's VFX shaders, Colorize_Options 2): c = lerp(vertex colour or _Color1, _Color2, colour.r);
//            colour.rgb *= colour.rgb + c.rgb (1 - colour.rgb) _ColorizeMul; colour.rgb *= c.a
//            (Colorize_Options 1, _ColorizeMode 1: colour *= c x _ColorizeMul)
//   alpha x _Alpha; + the rim (GoF3's RimEffect: clamp(N.E + 1), E the eye's direction to the vertex, remapped from
//   _Rim.x .. _Rim.y, x _RimColor); the texture scrolls by _Scroll (UV a second); clamped to 0..1 like GoF3's LDR
//   framebuffer (no bloom off its additive layers); everything x _Fade (StarMap's fade, per renderer by a property block).
// The blend is GoF3's BlendStateDescriptor of the material's BlendMode (_SrcBlend / _DstBlend / _BlendOp), with its depth
// write and cull. In Resources so a build keeps it (ModMaterials loads it by name).
Shader "GoF2/ModUnlit"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "white" {}
        _Color ("Colour (gamma)", Color) = (1, 1, 1, 1)
        [Toggle] _UseVertexColor ("Vertex colours", Float) = 0
        [Toggle] _Colorize ("Colorize", Float) = 0
        [Toggle] _ColorizeVertex ("Colorize from vertex colours", Float) = 1
        _ColorizeMode ("Colorize mode (0 tint, 1 multiply)", Float) = 0
        _Color1 ("Colorize colour 1", Color) = (1, 1, 1, 1)
        _Color2 ("Colorize colour 2", Color) = (1, 1, 1, 1)
        _ColorizeMul ("Colorize multiplier", Float) = 1
        _Alpha ("Alpha", Float) = 1
        _RimColor ("Rim colour", Color) = (0, 0, 0, 0)
        _Rim ("Rim (min, max)", Vector) = (0, 1, 0, 0)
        _Scroll ("Scroll (UV / s)", Vector) = (0, 0, 0, 0)
        _Fade ("Fade", Float) = 1
        [Enum(UnityEngine.Rendering.BlendMode)] _SrcBlend ("Source blend", Float) = 1
        [Enum(UnityEngine.Rendering.BlendMode)] _DstBlend ("Destination blend", Float) = 0
        [Enum(UnityEngine.Rendering.BlendOp)] _BlendOp ("Blend op", Float) = 0
        [Toggle] _ZWrite ("Depth write", Float) = 1
        [Enum(UnityEngine.Rendering.CullMode)] _Cull ("Cull", Float) = 2
    }
    SubShader
    {
        Tags { "RenderType" = "Transparent" "Queue" = "Transparent" "IgnoreProjector" = "True" "RenderPipeline" = "UniversalPipeline" }
        Blend [_SrcBlend] [_DstBlend]
        BlendOp [_BlendOp]
        ZWrite [_ZWrite]
        Cull [_Cull]

        Pass
        {
            Tags { "LightMode" = "UniversalForward" }
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"

            TEXTURE2D(_MainTex); SAMPLER(sampler_MainTex);
            CBUFFER_START(UnityPerMaterial)
                float4 _MainTex_ST;
                half4 _Color, _Color1, _Color2, _RimColor;
                float _UseVertexColor, _Colorize, _ColorizeVertex, _ColorizeMode, _ColorizeMul, _Alpha, _Fade;
                float4 _Rim, _Scroll;
                float _SrcBlend, _DstBlend, _BlendOp, _ZWrite, _Cull;
            CBUFFER_END

            // sRGB <-> linear (the exact curves; the URP of this Editor has no LinearToSRGB in Core.hlsl)
            half3 ToGamma(half3 c) { c = max(c, 0.0); return lerp(1.055 * pow(c, 1.0 / 2.4) - 0.055, c * 12.92, step(c, 0.0031308)); }
            half3 ToLinear(half3 c) { c = max(c, 0.0); return lerp(pow((c + 0.055) / 1.055, 2.4), c / 12.92, step(c, 0.04045)); }

            struct Attributes { float4 positionOS : POSITION; float3 normalOS : NORMAL; float2 uv : TEXCOORD0; half4 color : COLOR; };
            struct Varyings { float4 positionCS : SV_POSITION; float2 uv : TEXCOORD0; half4 color : COLOR; half rim : TEXCOORD1; };

            Varyings vert(Attributes i)
            {
                Varyings o;
                float3 positionWS = TransformObjectToWorld(i.positionOS.xyz);
                o.positionCS = TransformWorldToHClip(positionWS);
                o.uv = TRANSFORM_TEX(i.uv, _MainTex) + _Scroll.xy * _Time.y;
                o.color = i.color;
                float3 n = normalize(TransformObjectToWorldNormal(i.normalOS));
                float3 e = normalize(positionWS - GetCameraPositionWS());
                float r = saturate(dot(n, e) + 1.0);
                float span = _Rim.y - _Rim.x;
                o.rim = saturate((r - _Rim.x) / (abs(span) < 1e-5 ? 1e-5 : span));
                return o;
            }

            half4 frag(Varyings i) : SV_Target
            {
                half4 t = SAMPLE_TEXTURE2D(_MainTex, sampler_MainTex, i.uv);
                half4 c = half4(ToGamma(t.rgb), t.a) * _Color;
                if (_UseVertexColor > 0.5) c *= i.color;
                if (_Colorize > 0.5)
                {
                    half4 k = lerp(_ColorizeVertex > 0.5 ? i.color : _Color1, _Color2, c.r);
                    if (_ColorizeMode > 0.5) c *= k * _ColorizeMul;
                    else
                    {
                        c.rgb *= c.rgb + k.rgb * (1.0 - c.rgb) * _ColorizeMul;
                        c.rgb *= k.a;
                    }
                }
                c.a *= _Alpha;
                c.rgb += i.rim * _RimColor.rgb;
                c = saturate(c) * _Fade;
                return half4(ToLinear(c.rgb), c.a);
            }
            ENDHLSL
        }
    }
}
