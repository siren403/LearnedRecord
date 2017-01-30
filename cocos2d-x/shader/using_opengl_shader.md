### cocos2d-x 3.x opengl shader

* 스프라이트 생성
```
mSprite = Sprite::create("HelloWorld.png");
this->addChild(mSprite);
```
* GLProgram, GLState 생성
```
auto tGLProgram =
    GLProgram::createWithFilenames(
    "shader/ccPositionTextureColor_noMVP_vert.vsh",
     "shader/default_shader.fsh");

auto tGLState = GLProgramState::getOrCreateWithGLProgram(tGLProgram);
mSprite->setGLProgramState(tGLState);
```
> GLProgram을 통해 생성한 GLProgramState로 uniform variable에
값을 전달하거나 Callback함수를 등록하여 프레임마다 전달 할 수 있다.

> 생성한 GLProgram은 GLProgramCache에 추가하여
다른객체에서 셰이더사용시 중복생성이 필요없도록 할 수
있다.

> GLProgramState도 각 객체가 별도로 생성하여 다른
값들을 전달하여 사용 할 수 있다.

```
tGLState->setUniformVec4(
    "u_color",
    Vec4(1.0, 1.0, 1.0, 1.0));

auto tTex = TextureCache::getInstance()->addImage("CloseSelected.png");

tGLState->setUniformTexture("u_tex", tTex);
tGLState->setUniformFloat("u_aperture", 178.0);

tGLState->setUniformCallback(
    "u_aperture",
    [](GLProgram * tGLProgram, Uniform * tUniform)
{
	static float df = 1;
	static float min = 0;
	static float max = 300;
	static float u_aperture = min;
	u_aperture += df;
	if (u_aperture >= max || u_aperture <= min)
	{
		df = -df;
	}
	tGLProgram->setUniformLocationWith1f(tUniform->location, u_aperture);
});
```
