// The star map's suns (StarMap.GammaSun): each texel's colour raised to a power, so the glow's dim tail fades out the
// way the original's does. The original adds the sun planes in gamma space, where its last few percent of brightness
// vanish against the dark map well inside the plane; added in the remake's linear space (and x _Glow 2.5) the same tail
// stayed visible out to where the image ends, a ring round every sun. The bright core keeps its brightness. Blitted once
// per texture into a render texture the map's sun material copies use.
Shader "Hidden/GoF2/SunGamma"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "white" {}
        _Power ("Power", Float) = 2.2
    }
    SubShader
    {
        ZTest Always Cull Off ZWrite Off
        Pass
        {
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "UnityCG.cginc"
            sampler2D _MainTex;
            float _Power;
            struct v2f { float4 pos : SV_POSITION; float2 uv : TEXCOORD0; };
            v2f vert(appdata_img v) { v2f o; o.pos = UnityObjectToClipPos(v.vertex); o.uv = v.texcoord; return o; }
            float4 frag(v2f i) : SV_Target
            {
                float4 c = tex2D(_MainTex, i.uv);
                return float4(pow(saturate(c.rgb), _Power), c.a);
            }
            ENDHLSL
        }
    }
}
