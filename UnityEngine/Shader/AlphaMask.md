### 용도
- MainTexture를 AlphaTexture의 Masking영역대로 처리하여 랜더링

### 참조 문서
- 소스 출처
    https://bensilvis.com/unity3d-unlit-alpha-mask-shader/
- 주석 참조
    http://docs.unity3d.com/kr/current/Manual/SL-ShaderPrograms.html
    http://mgun.tistory.com/1844

### 소스 
    //경로 지정
    Shader "Custom/Unlit/AlphaMask" {

    //Material Inspector에 나타낼 프로퍼티
    Properties {
        //색상
        _Color("Color",Color) = (1,1,1,1)
        //텍스쳐
        _MainTex("Base (RGB)",2D) = "white"{}
        _AlphaTex("Alpha mask (R)",2D) = "white"{}
    }
    SubShader {
        Tags{"Queue"="Transparent" "IgnoreProjector"="True" "RenderType"="Transparent"}
        LOD 100

        ZWrite off
        Blend SrcAlpha OneMinusSrcAlpha

        Pass{

            //cg start
            CGPROGRAM
                //정점 쉐이더의 함수 이름 정의 [name:vert]
                #pragma vertex vert
                //Fragment 쉐이더의 함수 이름 정의 [name:frag]
                #pragma fragment frag

                //TRANSFORM_TEX가 정의 되어있는 곳
                #include "UnityCG.cginc"

                //todo...
                struct appdata_t{
                    float4 vertex : POSITION;
                    float2 texcoord : TEXCOORD0;
                };

                //todo...
                struct v2f {
                    float4 vertex : SV_POSITION;
                    half2 texcoord : TEXCOORD0;
                };

                //Properties의 값을 받아오기
                float4 _Color;
                sampler2D _MainTex;
                sampler2D _AlphaTex;

                // Transforms 2D UV by scale/bias property
                //#define TRANSFORM_TEX(tex,name) (tex.xy * name##_ST.xy + name##_ST.zw)
                //TRANSFORM_TEX 매크로에 필요한 tiling,offset값
                float4 _MainTex_ST;

                v2f vert(appdata_t v)
                {
                    v2f o;
                    o.vertex = mul(UNITY_MATRIX_MVP, v.vertex);
                    o.texcoord = TRANSFORM_TEX(v.texcoord, _MainTex);
                    return o;
                }

                fixed4 frag(v2f i):SV_Target
                {
                    fixed4 col = tex2D(_MainTex,i.texcoord);
                    col = col * _Color;
                    fixed4 col2 = tex2D(_AlphaTex,i.texcoord);

                    return fixed4(col.r,col.g,col.b,col2.r*_Color.a);
                }
            ENDCG
        }
    }
    FallBack "Diffuse"
}