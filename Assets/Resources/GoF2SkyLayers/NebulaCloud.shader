// GoF2/NebulaCloud: the local nebula clouds (World.NebulaClouds; Options > Graphics "Nebula clouds"). Remake, 2026-11-14, the
// user: EVERSPACE 2's sky methods in the base game. As ES2's local nebulae draw their pieces (M_Nebula_Local_Parent, read from
// its compiled shader): each piece a flat sprite at a random turn, its light a radial falloff times one channel of a tiled
// greyscale mask (its own scale and offset from the piece's random values), at two octaves, the smaller of the two; faded
// where the sprite is seen edge-on (its Fresnel fade) and near the camera; brighter toward the sun (forward scattering, ^32).
// The mask is the remake's own (Resources/GoF2SkyLayers/cloud_masks.png, Reference/tools/sky/nebula_clouds.py), the colours
// the orbit's own sky's. Added (not ES2's): a piece past the level's far plane (15 km) is drawn at 95 % of it, in its own
// direction, so the clouds reach past what the camera draws. Premultiplied: light added, a little of what is behind covered
// (ES2's are translucent), so they show against a bright sky too; the pieces aren't sorted (alike in colour, their order hardly
// shows).
// Vertex data: uv the sprite's corner, uv1 its random values, normal its facing, colour its tint (a: its mask channel / 2).
Shader "GoF2/NebulaCloud"
{
    Properties
    {
        [NoScaleOffset] _Masks ("Cloud masks (r g b)", 2D) = "black" {}
        _Intensity ("Intensity", Float) = 0.2
        _Absorb ("Covers what is behind", Float) = 0.5
        _Tiling ("Mask tiling", Float) = 2.5
        _Exponent ("Density exponent", Float) = 2.2
        _FresnelMin ("Edge-on fade", Float) = 0.1
        _NearFade ("Near fade (m)", Float) = 400
        _SunScatter ("Toward the sun", Float) = 1.5
        _SunDir ("Toward the sun (world)", Vector) = (0, 0, 1, 0)
        _SunColor ("Sun colour", Color) = (1, 1, 1, 1)
    }
    SubShader
    {
        Tags { "Queue" = "Transparent-50" "RenderType" = "Transparent" "RenderPipeline" = "UniversalPipeline" "IgnoreProjector" = "True" }
        Blend One OneMinusSrcAlpha
        ZWrite Off
        Cull Off

        Pass
        {
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma multi_compile_instancing
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"

            TEXTURE2D(_Masks); SAMPLER(sampler_Masks);
            CBUFFER_START(UnityPerMaterial)
                float _Intensity, _Absorb, _Tiling, _Exponent, _FresnelMin, _NearFade, _SunScatter;
                float4 _SunDir, _SunColor;
            CBUFFER_END

            struct Attributes { float4 positionOS : POSITION; float3 normalOS : NORMAL; float2 uv : TEXCOORD0; float4 rnd : TEXCOORD1; half4 color : COLOR; UNITY_VERTEX_INPUT_INSTANCE_ID };
            struct Varyings
            {
                float4 positionCS : SV_POSITION; float2 uv : TEXCOORD0; float4 rnd : TEXCOORD1; float3 normalWS : TEXCOORD2;
                float4 view : TEXCOORD3; half4 color : COLOR; UNITY_VERTEX_OUTPUT_STEREO
            };

            Varyings vert(Attributes i)
            {
                Varyings o;
                UNITY_SETUP_INSTANCE_ID(i);
                UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o);
                float3 w = TransformObjectToWorld(i.positionOS.xyz);
                float3 v = w - _WorldSpaceCameraPos;
                float dist = length(v);
                float lim = _ProjectionParams.z * 0.95;
                if (dist > lim) w = _WorldSpaceCameraPos + v * (lim / dist);   // past the far plane: drawn just inside it
                o.positionCS = TransformWorldToHClip(w);
                o.uv = i.uv;
                o.rnd = i.rnd;
                o.normalWS = TransformObjectToWorldNormal(i.normalOS);
                o.view = float4(v / max(dist, 1e-3), dist);
                o.color = i.color;
                return o;
            }

            half Channel(half3 t, half c) { return c < 0.25 ? t.r : c < 0.75 ? t.g : t.b; }

            half4 frag(Varyings i) : SV_Target
            {
                UNITY_SETUP_STEREO_EYE_INDEX_POST_VERTEX(i);
                float radial = max(1.0 - 2.0 * length(i.uv - 0.5), 0.0);
                if (radial <= 0) return 0;
                // ES2: the mask at uv x 0.3 x its scale x (0.25 + 0.75 x random.x), offset by random.zw, and again finer (ES2's x 2; x 1.6
                // here, its grain read as dust), the smaller
                float2 t = i.uv * 0.3 * _Tiling * (0.25 + 0.75 * i.rnd.x) + i.rnd.zw;
                half ch = i.color.a;
                half m = min(Channel(SAMPLE_TEXTURE2D(_Masks, sampler_Masks, t).rgb, ch), Channel(SAMPLE_TEXTURE2D(_Masks, sampler_Masks, t * 1.6 + i.rnd.y).rgb, ch));
                half dens = saturate(radial * m * 2.0);
                dens = dens <= 0 ? 0 : pow(dens, _Exponent);
                float facing = abs(dot(normalize(i.normalWS), i.view.xyz));
                dens *= saturate((facing - _FresnelMin) / max(1.0 - _FresnelMin, 1e-3));   // edge-on: gone
                dens *= saturate((i.view.w - _NearFade) / max(_NearFade, 1.0));          // at the camera: gone
                float toSun = saturate((dot(i.view.xyz, _SunDir.xyz) + 1.0) * 0.5);
                half3 col = i.color.rgb * (1.0 + _SunScatter * pow(toSun, 32.0) * _SunColor.rgb);
                return half4(col * dens * _Intensity, saturate(dens * _Absorb));   // (premultiplied: it covers a little of what is behind)
            }
            ENDHLSL
        }
    }
}
