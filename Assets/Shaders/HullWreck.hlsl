// HullWreck.hlsl
// GoF2 remake (2026-11-11, after Chorus's wreck materials: MF_WreckBurn's Burn_Amount / Burn_Temperature / Burn_Tiling and
// the masters' Dissolve / DissolveWidth / DissolveBoost, which its wrecks' anim blueprints drive over the wreck's life):
// a wreck piece's burn and disintegration (World.WreckBreakup sets _WreckFx / _WreckBurnColor per piece with a property
// block). The pattern is value noise in the piece's object space (it sticks to the piece as it turns), _WreckFx.z cells a
// unit. Burn: _WreckFx.x of the piece glows where the noise is high (more of it as the amount rises), in _WreckBurnColor.
// Disintegration: what the noise leaves under _WreckFx.y is cut away (every depth pass alike), its edge glowing over
// _WreckFx.w of the noise at twice the burn colour (DissolveBoost 2). The hot spots, the noise's highs, go last.
#ifndef GOF2_HULL_WRECK_INCLUDED
#define GOF2_HULL_WRECK_INCLUDED

float HullWreckHash(float3 p)
{
    p = frac(p * 0.3183099 + 0.1);
    p *= 17.0;
    return frac(p.x * p.y * p.z * (p.x + p.y + p.z));
}

float HullWreckNoise(float3 x)
{
    float3 i = floor(x);
    float3 f = frac(x);
    f = f * f * (3.0 - 2.0 * f);
    return lerp(lerp(lerp(HullWreckHash(i), HullWreckHash(i + float3(1, 0, 0)), f.x),
                     lerp(HullWreckHash(i + float3(0, 1, 0)), HullWreckHash(i + float3(1, 1, 0)), f.x), f.y),
                lerp(lerp(HullWreckHash(i + float3(0, 0, 1)), HullWreckHash(i + float3(1, 0, 1)), f.x),
                     lerp(HullWreckHash(i + float3(0, 1, 1)), HullWreckHash(i + float3(1, 1, 1)), f.x), f.y), f.z);
}

// 0..1, two octaves, in the piece's object space
float HullWreckPattern(float3 positionWS)
{
    float3 p = TransformWorldToObject(positionWS) * _WreckFx.z;
    return HullWreckNoise(p) * 0.65 + HullWreckNoise(p * 2.7 + 17.0) * 0.35;
}

// the disintegrated part cut away
void HullWreckClip(float3 positionWS)
{
    if (_WreckFx.y > 0.0) clip(HullWreckPattern(positionWS) - _WreckFx.y);
}

// the burn's and the cut edge's glow
half3 HullWreckEmission(float3 positionWS)
{
    if (_WreckFx.x <= 0.0 && _WreckFx.y <= 0.0) return 0;
    float n = HullWreckPattern(positionWS);
    half heat = (half)(smoothstep(0.75 - 0.35 * _WreckFx.x, 0.95, n) * _WreckFx.x);
    half edge = _WreckFx.y > 0.0 ? (half)(1.0 - saturate((n - _WreckFx.y) / max(_WreckFx.w, 1e-3))) : 0;
    return (half3)_WreckBurnColor.rgb * (heat + edge * 2.0h);
}

// a depth pass's world position from its pixel (their varyings carry none)
float3 HullWreckPixelToWorld(float4 positionCS)
{
    return ComputeWorldSpacePosition(positionCS.xy / _ScaledScreenParams.xy, positionCS.z, UNITY_MATRIX_I_VP);
}

#endif
