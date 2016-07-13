### 문제

UITexture의 Material의 Property에 값을 전달해도 바로 갱신되지 않음

    //.cs
    UITexture UITex;
    UITex.material.SetColor("_Color",Color.red);

### 해결

dynamicMaterial을 사용하여 값을 지정해주어야 실시간으로 적용

    dynamicMaterial은 실제로 지오메트리를 그리기 위해 drawCall에서 동적으로 
    생성해서 사용되는 Material.(Instantiated material)

### 소스

    //.cs
    UITexture UITex;
    UITex.drawCall.dynamicMaterial.SetColor("_Color",Color.red);


