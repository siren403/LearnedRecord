[출처:tistory blog](http://eastroot1590.tistory.com/entry/cocos2d-x%EC%9D%98-custom-shader%EB%A1%9C-Glow-%ED%9A%A8%EA%B3%BC%EB%82%B4%EA%B8%B0)
(gnosy1590.tistory.com)

### 원하는 결과물

![img_blur_ex](/cocos2d-x/shader/res/img_blur_ex.jpg)![img_blur_ex_2](/cocos2d-x/shader/res/img_blur_ex_2.jpg)

> 오브젝트가 선택됨을 나타내려고 주로 사용하는 방법이다.

* 방법
> shader를 이용해서 이미지의 외곽주변부의 fragment값을 조작하여 효과를 표현한다.

코드(Blur.fsh)
```
#ifdef GL_ES
precision lowp float;
#endif

varying vec2 v_texCoord;

uniform vec2 u_stepSize;

void main()
{
    vec4 color = texture2D(CC_Texture0, v_texCoord);
    vec4 result = vec4(0.0, 0.0, 0.0, 0.0);
    vec2 r_stepSize = vec2(u_stepSize.x, -u_stepSize.y);

    result += texture2D(CC_Texture0, v_texCoord -  -4.0 * u_stepSize) * 0.05;
    result += texture2D(CC_Texture0, v_texCoord -  -3.0 * u_stepSize) * 0.09;
    result += texture2D(CC_Texture0, v_texCoord -  -2.0 * u_stepSize) * 0.12;
    result += texture2D(CC_Texture0, v_texCoord -  -1.0 * u_stepSize) * 0.15;
    result += texture2D(CC_Texture0, v_texCoord -  0.0 * u_stepSize) * 0.16;
    result += texture2D(CC_Texture0, v_texCoord -  1.0 * u_stepSize) * 0.15;
    result += texture2D(CC_Texture0, v_texCoord -  2.0 * u_stepSize) * 0.12;
    result += texture2D(CC_Texture0, v_texCoord -  3.0 * u_stepSize) * 0.09;
    result += texture2D(CC_Texture0, v_texCoord -  4.0 * u_stepSize) * 0.05;

    result += texture2D(CC_Texture0, v_texCoord -  -4.0 * r_stepSize) * 0.05;
    result += texture2D(CC_Texture0, v_texCoord -  -3.0 * r_stepSize) * 0.09;
    result += texture2D(CC_Texture0, v_texCoord -  -2.0 * r_stepSize) * 0.12;
    result += texture2D(CC_Texture0, v_texCoord -  -1.0 * r_stepSize) * 0.15;
    result += texture2D(CC_Texture0, v_texCoord -  0.0 * r_stepSize) * 0.16;
    result += texture2D(CC_Texture0, v_texCoord -  1.0 * r_stepSize) * 0.15;
    result += texture2D(CC_Texture0, v_texCoord -  2.0 * r_stepSize) * 0.12;
    result += texture2D(CC_Texture0, v_texCoord -  3.0 * r_stepSize) * 0.09;
    result += texture2D(CC_Texture0, v_texCoord -  4.0 * r_stepSize) * 0.05;

    result /= 3.0;
    if(color.a >= 1.0)
        result = color;    // 원본 이미지 부분은 그대로
    else if(result.a > 0.0){
        result.rgb = vec3(result.a, result.a, result.a);    // 하얀색 빛
    }

    gl_FragColor = result;
}
```
> 현재 픽셀을 기준으로 X방향으로 거리에 따라 가중치를 줘서 새로운 색상값을 계산한다.

> 기존 이미지 부분은 원래 fragment색으로 되돌려줘서 주변광 처럼 보이도록 한다.


결과

![img_blur_result_1](/cocos2d-x/shader/res/img_blur_result_1.png)

> 이미지가 꽉 차있는 경우 shader가 외부까지 접근하지 못해서 효과가 잘린다.

보강 #1
> 기존 sprite보다 더 큰 rect에 똑같은 이미지를 그린 후 위와 같은 shader를 적용하면 잘려나가는 단점을 보완할 수 있다.

코드(cocos2d-x)
```
auto spr2 = Sprite::createWithTexture(spr->getTexture(), Rect(-10, -10, 84, 84));   // 기존 이미지는 (0,0,64,64)
spr2->setPosition(spr->getPosition());
auto blur = ShaderCache::getInstance()->getGLProgram("Blur");
auto gp = GLProgramState::create(blur);
spr2->setGLProgram(blur);
spr2->setGLProgramState(gp);
gp->setUniformVec2("u_stepSize", Vec2(0.03, 0.03));
this->addChild(spr2);
```
> 원본 이미지보다 가로세로 10씩 큰 rect로 sprite를 생성하여 shader를 적용한다.

> 이때 원본 이미지를 덮어씌우지 않기 위해 shader코드에서 원본 부분은 잘라낸다.

코드(Blur.fsh)
```
    result /= 3.0;
    if(color.a >= 1.0)
        result -= color;    // 원본 이미지 부분은 잘라낸다
```
> 위에서 사용한 코드에서 저 부분만 수정한다.

결과

![img_blur_result_2](/cocos2d-x/shader/res/img_blur_result_2.png)

> 이미지를 늘리는 과정에서 모서리에 맞닿아있는 픽셀이 늘어나게 확장된다.

보강 #2
> GL_CLAMP 방법을 GL_CLAMP_TO_BORDER로 변경한다.
[OpenGL]텍스쳐 래핑(Texture Wrapping) : http://gnosy1590.tistory.com/24 참고

결과

![img_blur_result_3_1](/cocos2d-x/shader/res/img_blur_result_3_1.png)![img_blur_result_3_2](/cocos2d-x/shader/res/img_blur_result_3_2.png)

> 후광(좌) 후광+원본(우)

> 비슷한 방법으로 sprite animation에도 적용이 가능하다. 단, plist를 생성할 때 이미지간 간격을 띄워주어야 한다.

단점
> 위 방법은 openGL에서 텍스쳐 래핑 모드를 변경하여 구현한 방법으로 GL_CLAMP_TO_BORDER 옵션이 사라진 openGL ES 에서는 사용할 수 없다.

> 애니메이션이 항상 실행되는 sprite에만 사용하거나 정적인 sprite는 모서리를 1픽셀씩 비워서 사용하도록 하자

TP:7A68B75B
