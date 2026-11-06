// GoF2/Es2Planet: an orbit's planet as a lit sphere (World.Backdrop, stations.json "planetSphere"), after EVERSPACE 2's planet
// materials, read from their compiled base-pass pixel shaders (tools/shaders' ShaderDump in the es2 importer). Drawn in the
// backdrop pass like GoF2/Backdrop's quads: behind every opaque object, its depth on the far plane (a sphere: its back faces
// culled, so it needs no depth of its own). Lit here by the orbit's sun (_SunDir, _SunColor): ES2 lights it with the level's
// sun; the night side keeps a little ambient. In Resources so a build keeps it.
//
// _Look 0, M_Planet_Desert (its space form: the MPC_Environment's PlanetSurface 0):
//   UVs: u round the planet (x2), v a latitude stretch (0.5 (2v)^0.2 below the equator, 0.5 + 0.5 (1 - (2 - 2v)^0.2) above),
//   x5: the base layer; the detail layer x6 of that; the pole layer a projection from above (x5).
//   Surface: T_Planet_Rock_002_H_C_R (H height, C colour, R roughness) and _N, detail and base mixed by distance (here
//   _DetailMix); the normal flattened 70 % toward the surface.
//   Colour: overlay(C^2.2, tone x (1, 0.65, 0.4)), tone = 0.5 + 0.5 contrast20(T_Noise_016_M at (base + 0.25) x 2); x the rim
//   (1 + 3 (1 - N.V)^3), saturated.
//   Poles: where the pole projection's distance from the pole is under half T_Noise_016_M^1.5 (x 2), x10, saturated: the
//   colour (1, 1 - 0.7 (1 - s), 0.8 s), s = (T_Rocks_004_C^2 - 0.5) 0.5 + 0.5; its normal T_Rocks_004_N flattened 95 %; its
//   roughness 0.4 + 0.4 smoothstep((T_Rocks_004_C - 0.2) x 20). Metalness 0, specular 0.5.
// Left out: the parallax-occlusion relief of the detail layer (its height steps), the city lights (off on the desert), the
// distance fades of ES2's own planet scaling.
//
// _Look 1, M_Planet_GasSmooth (2026-11-06, es2_re planetmat): the desert's UVs; the base layer T_Planet_Gas_002_C_H (C, H)
//   overlaid with its detail layer (x DetailTiling 2) pulled toward 0.5 by distance (_DetailMix); colour lerp(Color, Color2,
//   H) (_Color1 / _Color2, linear), overlaid with C, its hue turned about the grey axis by Variation x 2 pi (_Variation), then
//   overlaid with (H - 0.5) x HeightOverlay 0.5 + 0.5; the poles as the desert's, overlaid with T_Rocks_004_C. Normals
//   T_Planet_Gas_002_N, base and detail, flattened FlattenNormal 0.9 toward the surface. Roughness 1, metalness 0.
// _Look 2, M_Planet_Gas: the base layer T_Planet_Gas_001_C_H's C, lerped with its detail (x DetailTiling 4) by distance,
//   squared; the bands contrast4(sqrt(T_Noise_001_M at (u, 4 v))) between SecondaryColor and BaseColor (_Color1 / _Color2),
//   its hue turned by Variation, overlaid with that C^2. Normals T_Planet_Gas_001_N, the detail flattened Param_1 0.6. No
//   poles. Roughness 1, metalness 0.
Shader "GoF2/Es2Planet"
{
    Properties
    {
        _Look ("Look (0 desert, 1 gas smooth, 2 gas)", Float) = 0
        _Color1 ("Gas: Color / SecondaryColor (linear)", Vector) = (0.02, 0.071433, 0.1, 0)
        _Color2 ("Gas: Color2 / BaseColor (linear)", Vector) = (0.166665, 0.487763, 0.5, 0)
        _Variation ("Gas: Variation (0..1, the hue x 2 pi)", Float) = 0
        _SurfaceMap ("Surface H_C_R", 2D) = "gray" {}
        _SurfaceNormal ("Surface normal (ES2's, DirectX)", 2D) = "bump" {}
        _CapNormal ("Pole normal (ES2's, DirectX)", 2D) = "bump" {}
        _CapColour ("Pole colour mask", 2D) = "gray" {}
        _Noise ("Noise mask", 2D) = "gray" {}
        _DetailMix ("Base layer share (1 = base only)", Range(0, 1)) = 0.6
        _SunDir ("Toward the sun (world)", Vector) = (0, 0, 1, 0)
        _SunColor ("Sun light", Color) = (1, 1, 1, 1)
        _Ambient ("Ambient", Float) = 0.03
        _Atmosphere ("Atmosphere rim colour (a: strength)", Color) = (0, 0, 0, 0)
        _Color ("Fade (a)", Color) = (1, 1, 1, 1)
        _Debug ("Debug: 1 albedo, 2 surface map, 3 sun colour", Float) = 0
    }
    SubShader
    {
        Tags { "Queue" = "Transparent-100" "RenderType" = "Transparent" "IgnoreProjector" = "True" }
        Blend SrcAlpha OneMinusSrcAlpha
        ZWrite Off
        ZTest LEqual
        Cull Back

        Pass
        {
            Tags { "LightMode" = "GoF2Backdrop" }
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"

            TEXTURE2D(_SurfaceMap); SAMPLER(sampler_SurfaceMap);
            TEXTURE2D(_SurfaceNormal);
            TEXTURE2D(_CapNormal);
            TEXTURE2D(_CapColour);
            TEXTURE2D(_Noise);
            CBUFFER_START(UnityPerMaterial)
                float _Look;
                float4 _Color1, _Color2;
                float _Variation;
                half _DetailMix;
                float4 _SunDir;
                half4 _SunColor;
                half _Ambient;
                half4 _Atmosphere;
                half4 _Color;
                float _Debug;
            CBUFFER_END

            struct Attributes { float4 positionOS : POSITION; };
            struct Varyings { float4 positionCS : SV_POSITION; float3 dirOS : TEXCOORD0; float3 positionWS : TEXCOORD1; };

            Varyings vert(Attributes i)
            {
                Varyings o;
                o.positionWS = TransformObjectToWorld(i.positionOS.xyz);
                o.positionCS = TransformWorldToHClip(o.positionWS);
                #if UNITY_REVERSED_Z
                    o.positionCS.z = o.positionCS.w * 1e-6;
                #else
                    o.positionCS.z = o.positionCS.w * (1 - 1e-6);
                #endif
                o.dirOS = i.positionOS.xyz;
                return o;
            }

            // ES2's contrast curve (its compiled shader's pow pair): 0.5 (2x)^p below the middle, 1 - 0.5 (2 - 2x)^p above
            half Contrast(half x, half p) { return x < 0.5 ? 0.5 * pow(saturate(2.0 * x), p) : 1.0 - 0.5 * pow(saturate(2.0 - 2.0 * x), p); }
            half Overlay(half b, half t) { return b >= 0.5 ? 1.0 - (1.0 - b) * 2.0 * (1.0 - t) : 2.0 * b * t; }
            // the hue turned 'angle' radians about the grey axis (ES2's HueShift: Rodrigues about (1, 1, 1) / sqrt 3)
            half3 HueRotate(half3 c, half angle)
            {
                const half3 k = half3(0.57735026, 0.57735026, 0.57735026);
                half dk = dot(k, c);
                half3 p = c - k * dk;
                half s, co;
                sincos(angle, s, co);
                return p * co + cross(k, p) * s + k * dk;
            }
            half3 Overlay3(half3 b, half3 t) { return half3(Overlay(b.r, t.r), Overlay(b.g, t.g), Overlay(b.b, t.b)); }
            half3 Unpack(half4 c, half flatten)
            {
                half2 xy = c.xy * 2.0 - 1.0;
                half3 n = half3(xy, sqrt(saturate(1.0 - dot(xy, xy))));
                return normalize(lerp(n, half3(0, 0, 1), flatten));
            }

            half4 frag(Varyings i) : SV_Target
            {
                float3 d = normalize(i.dirOS);
                // UVs (v 0 at the north pole)
                float u = atan2(d.x, d.z) / (2.0 * PI) + 0.5;
                // (the mip level from a u that doesn't wrap here: the wrap at u 0 / 1 would pick the smallest mip, a seam)
                float uAlt = frac(u + 0.5) - 0.5;
                float2 dU = float2(ddx(u), ddy(u)), dUAlt = float2(ddx(uAlt), ddy(uAlt));
                if (dot(dUAlt, dUAlt) < dot(dU, dU)) dU = dUAlt;
                float v = acos(clamp(d.y, -1.0, 1.0)) / PI;
                float g = v < 0.5 ? 0.5 * pow(saturate(2.0 * v), 0.2) : 0.5 + 0.5 * (1.0 - pow(saturate(2.0 - 2.0 * v), 0.2));
                float2 baseUv = float2(2.0 * u, 5.0 * g), detailUv = baseUv * 6.0;
                float2 gx = float2(2.0 * dU.x, 5.0 * ddx(g)), gy = float2(2.0 * dU.y, 5.0 * ddy(g));
                float2 poleUv = d.xz * 0.5 + 0.5;
                // the sphere's frame: east, north, out (object space)
                float3 east = normalize(cross(float3(0, 1, 0), d) + float3(1e-5, 0, 0));
                float3 north = cross(d, east);

                // the poles (every look but the banded gas)
                half pn = SAMPLE_TEXTURE2D(_Noise, sampler_SurfaceMap, poleUv * 2.0).r;
                half reach = max(0.5 * pow(max(pn, 1e-4), 1.5), 1e-4);
                half cap = _Look > 1.5 ? 0.0 : saturate(10.0 * max(1.0 - length(poleUv - 0.5) / reach, 0.0));
                half3 ncap = Unpack(SAMPLE_TEXTURE2D(_CapNormal, sampler_SurfaceMap, poleUv * 5.0), 0.95);
                half cc = SAMPLE_TEXTURE2D(_CapColour, sampler_SurfaceMap, poleUv * 5.0).r;
                half s = cc <= 2.98e-8 ? 0.25 : (cc * cc - 0.5) * 0.5 + 0.5;
                float3 view = normalize(GetCameraPositionWS() - i.positionWS);
                half3 albedo, nts;
                half rough, f;
                if (_Look < 0.5)
                {
                    half4 sd = SAMPLE_TEXTURE2D_GRAD(_SurfaceMap, sampler_SurfaceMap, detailUv, gx * 6.0, gy * 6.0);
                    half4 sb = SAMPLE_TEXTURE2D_GRAD(_SurfaceMap, sampler_SurfaceMap, baseUv, gx, gy);
                    half2 cr = lerp(sd.yz, sb.yz, _DetailMix);   // (colour, roughness)
                    half3 nd = Unpack(SAMPLE_TEXTURE2D_GRAD(_SurfaceNormal, sampler_SurfaceMap, detailUv, gx * 6.0, gy * 6.0), 0.0);
                    half3 nb = Unpack(SAMPLE_TEXTURE2D_GRAD(_SurfaceNormal, sampler_SurfaceMap, baseUv, gx, gy), 0.0);
                    nts = normalize(lerp(normalize(lerp(lerp(nd, nb, _DetailMix), half3(0, 0, 1), 0.7)), ncap, cap));
                    float3 n0 = normalize(TransformObjectToWorldDir(normalize(east * nts.x + north * nts.y + d * nts.z)));
                    half c = pow(max(cr.x, 1e-4), 2.2);
                    half tone = 0.5 + 0.5 * Contrast(SAMPLE_TEXTURE2D_GRAD(_Noise, sampler_SurfaceMap, (baseUv + 0.25) * 2.0, gx * 2.0, gy * 2.0).r, 20.0);
                    albedo = Overlay3(half3(c, c, c), tone * half3(1.0, 0.65, 0.4));
                    f = max(1.0 - saturate(dot(n0, view)), 1e-4);
                    albedo = saturate(albedo * (1.0 + 3.0 * f * f * f));
                    albedo = saturate(lerp(albedo, half3(1.0, 1.0 - 0.7 * (1.0 - s), 0.8 * s), cap));
                    half capRough = 0.4 + 0.4 * smoothstep(0.0, 1.0, saturate((cc - 0.2) * 20.0));
                    rough = saturate(lerp(cr.y, capRough, cap));
                }
                else if (_Look < 1.5)
                {
                    // the smooth gas giant (DetailTiling 2)
                    float2 dUv = baseUv * 2.0;
                    half2 b = SAMPLE_TEXTURE2D_GRAD(_SurfaceMap, sampler_SurfaceMap, baseUv, gx, gy).xy;
                    half2 dt = SAMPLE_TEXTURE2D_GRAD(_SurfaceMap, sampler_SurfaceMap, dUv, gx * 2.0, gy * 2.0).xy;
                    dt = dt + _DetailMix * (0.5 - dt);
                    half2 ch = half2(Overlay(b.x, dt.x), Overlay(b.y, dt.y));   // (C, H)
                    half3 col = lerp(_Color1.rgb, _Color2.rgb, ch.y);
                    col = Overlay3(col, half3(ch.x, ch.x, ch.x));
                    col = HueRotate(col, _Variation * 2.0 * PI);
                    half ho = (ch.y - 0.5) * 0.5 + 0.5;
                    half3 body = Overlay3(col, half3(ho, ho, ho));
                    half3 capCol = Overlay3(col, half3(s, s, s));
                    albedo = saturate(lerp(body, capCol, cap));
                    half3 nb = Unpack(SAMPLE_TEXTURE2D_GRAD(_SurfaceNormal, sampler_SurfaceMap, baseUv, gx, gy), 0.0);
                    half3 nd = Unpack(SAMPLE_TEXTURE2D_GRAD(_SurfaceNormal, sampler_SurfaceMap, dUv, gx * 2.0, gy * 2.0), _DetailMix);
                    half3 t1 = nb + half3(0, 0, 1), u1 = nd * half3(-1, -1, 1);
                    half3 rn = normalize(t1 * dot(t1, u1) / t1.z - u1);   // (the detail over the base: ES2's RNM blend)
                    nts = normalize(lerp(normalize(lerp(rn, half3(0, 0, 1), 0.9)), ncap, cap));
                    rough = 1.0;
                }
                else
                {
                    // the banded gas giant (DetailTiling 4)
                    float2 dUv = baseUv * 4.0;
                    half cb = SAMPLE_TEXTURE2D_GRAD(_SurfaceMap, sampler_SurfaceMap, baseUv, gx, gy).x;
                    half cd = SAMPLE_TEXTURE2D_GRAD(_SurfaceMap, sampler_SurfaceMap, dUv, gx * 4.0, gy * 4.0).x;
                    half c = lerp(cd, cb, _DetailMix);
                    c *= c;
                    half bandN = sqrt(max(SAMPLE_TEXTURE2D_GRAD(_Noise, sampler_SurfaceMap, float2(u, 4.0 * v), float2(dU.x, 4.0 * ddx(v)), float2(dU.y, 4.0 * ddy(v))).r, 0.0));
                    half t = Contrast(bandN, 4.0);
                    half3 col = HueRotate(lerp(_Color1.rgb, _Color2.rgb, t), _Variation * 2.0 * PI);
                    albedo = saturate(Overlay3(col, half3(c, c, c)));
                    half3 nb = Unpack(SAMPLE_TEXTURE2D_GRAD(_SurfaceNormal, sampler_SurfaceMap, baseUv, gx, gy), 0.0);
                    half3 nd = Unpack(SAMPLE_TEXTURE2D_GRAD(_SurfaceNormal, sampler_SurfaceMap, dUv, gx * 4.0, gy * 4.0), 0.6);
                    nts = normalize(lerp(nd, nb, _DetailMix));
                    rough = 1.0;
                }
                float3 nOS = normalize(east * nts.x + north * nts.y + d * nts.z);
                float3 n = normalize(TransformObjectToWorldDir(nOS));
                f = max(1.0 - saturate(dot(n, view)), 1e-4);

                // the sun: diffuse and a GGX highlight (specular 0.5: F0 0.04)
                float3 l = normalize(_SunDir.xyz);
                half nl = saturate(dot(n, l));
                float3 h = normalize(l + view);
                half a = max(rough * rough, 0.002), a2 = a * a;
                half nh = saturate(dot(n, h));
                half dd = nh * nh * (a2 - 1.0) + 1.0;
                half spec = a2 / (PI * dd * dd) * 0.04 * nl * 0.25;
                half3 lit = albedo * (_SunColor.rgb * nl + _Ambient) + _SunColor.rgb * spec;
                // the atmosphere's rim on the lit side (until its own shell is ported)
                half3 rim = _Atmosphere.rgb * _Atmosphere.a * 0.6 * pow(f, 8.0) * saturate(dot(normalize(TransformObjectToWorldDir(d)), l) * 1.5 + 0.3);   // (the limb only)
                if (_Debug > 2.5) return half4(_SunColor.rgb, 1);
                if (_Debug > 1.5) return half4(SAMPLE_TEXTURE2D(_SurfaceMap, sampler_SurfaceMap, baseUv).rgb, 1);
                if (_Debug > 0.5) return half4(albedo, 1);
                return half4(lit + rim, _Color.a);
            }
            ENDHLSL
        }
    }
}
