// GoF2/HazardVolume: the view from inside an orbit's hazard volume (World.HazardLooks; stations.json "orbit.hazards"), after
// EVERSPACE 2's fields' post-process materials, drawn by the volume's sphere (Unity's primitive, radius 0.5) from inside
// only (Cull Front, ZTest Always: over everything while the camera is within it; nothing from outside, where ES2's
// fields are only their particles):
//   _Mode 1  frost      M_Condition_Frozen_PostProcess: frost (T_Grunge_Frost_001) creeping in from the screen's edges,
//                       its Opacity the buildup (_Amount 0..1); here a procedural frost of cells and fine grain
//   _Mode 2  radiation  M_Condition_Radiated_PostProcess: RadiationColor (1, 1, 0.39) dots (T_Pattern_Dots_002) over drifting
//                       noise (T_Noise_010_M); here a screen grid of dots under a value noise, _Amount its opacity
Shader "GoF2/HazardVolume"
{
    Properties
    {
        _Color ("Color", Color) = (1, 1, 0.39, 1)
        _Mode ("Mode (1 frost, 2 radiation)", Float) = 1
        _Amount ("Amount", Float) = 0
        _DotPixels ("Dot spacing (pixels at 1080p)", Float) = 7
    }
    SubShader
    {
        Tags { "Queue" = "Transparent+50" "RenderType" = "Transparent" "RenderPipeline" = "UniversalPipeline" "IgnoreProjector" = "True" }
        ZWrite Off
        ZTest Always
        Cull Front
        Blend SrcAlpha OneMinusSrcAlpha

        Pass
        {
            Tags { "LightMode" = "UniversalForward" }
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"

            CBUFFER_START(UnityPerMaterial)
                float4 _Color;
                float _Mode, _Amount, _DotPixels;
            CBUFFER_END

            struct Attributes { float4 positionOS : POSITION; };
            struct Varyings { float4 positionCS : SV_POSITION; };

            Varyings vert(Attributes i)
            {
                Varyings o;
                o.positionCS = TransformObjectToHClip(i.positionOS.xyz);
                return o;
            }

            float Hash(float2 p) { p = frac(p * float2(0.3183099, 0.3678794)) * 17.0; return frac(p.x * p.y * (p.x + p.y)); }

            float Noise(float2 x)
            {
                float2 i = floor(x), f = frac(x);
                f = f * f * (3.0 - 2.0 * f);
                return lerp(lerp(Hash(i), Hash(i + float2(1, 0)), f.x), lerp(Hash(i + float2(0, 1)), Hash(i + float2(1, 1)), f.x), f.y);
            }

            // the distance to the nearest of a jittered grid's points: ice cells
            float Cells(float2 p)
            {
                float2 i = floor(p), f = frac(p);
                float d = 1.0;
                for (int y = -1; y <= 1; y++)
                    for (int x = -1; x <= 1; x++)
                    {
                        float2 g = float2(x, y);
                        float2 o = float2(Hash(i + g), Hash(i + g + 17.0));
                        d = min(d, length(g + o - f));
                    }
                return d;
            }

            // 1 with the camera inside the sphere (object radius 0.5), else 0
            float CameraInside() { return step(length(TransformWorldToObject(_WorldSpaceCameraPos)), 0.5); }

            half4 frag(Varyings i) : SV_Target
            {
                float inside = CameraInside();
                float2 uv = i.positionCS.xy / _ScreenParams.xy;
                float aspect = _ScreenParams.x / _ScreenParams.y;
                float2 p = float2((uv.x - 0.5) * aspect, uv.y - 0.5);
                float a;
                if (_Mode < 1.5)
                {
                    // frost: from the edges inward as the buildup grows, ragged by the cells and a fine grain
                    float edge = length(p / float2(aspect * 0.5, 0.5));   // 0 the centre, 1 the edges' middles, ~1.4 the corners
                    float cells = Cells(p * 9.0);
                    float grain = Noise(p * 90.0) * 0.5 + Noise(p * 23.0) * 0.5;
                    float reach = 1.35 - _Amount * 0.95;   // where the frost begins: the corners at first, most of the view at the full buildup
                    float frost = smoothstep(reach, reach + 0.35, edge + (grain - 0.5) * 0.35);
                    a = frost * (0.35 + 0.45 * smoothstep(0.05, 0.45, cells)) * saturate(_Amount * 1.5) * 0.85;
                }
                else
                {
                    // radiation: a dot grid at screen pixels, faded by drifting noise
                    float2 px = i.positionCS.xy * (1080.0 / _ScreenParams.y) / _DotPixels;
                    float spot = smoothstep(0.38, 0.22, length(frac(px) - 0.5));
                    float n = Noise(p * 3.0 + _Time.y * 0.15) * 0.6 + Noise(p * 7.0 - _Time.y * 0.1) * 0.4;
                    a = spot * smoothstep(0.35, 0.75, n) * _Amount;
                }
                return half4(_Color.rgb, saturate(a * _Color.a * inside));
            }
            ENDHLSL
        }
    }
}
