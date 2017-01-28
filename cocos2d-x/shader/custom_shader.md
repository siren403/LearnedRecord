[출처:tistory blog](gnosy1590.tistory.com)

### cocos2d-x에서 셰이더롤 적용하는 방법
> ShaderCache에 셰이더를 등록하고 적용한다.

코드
```
GLProgram* shader = new GLProgram();
shader->initWithFilenames("SelectEffect.vsh", "SelectEffect.fsh");
shader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
shader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
shader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);

shader->link();
shader->updateUniforms();

//ShaderCache에 셰이더를 등록한다.
ShaderCache::getInstance()->addGLProgram(shader, "SelectEffect");

//등록한 셰이더를 불러와서 적용한다.
auto background = Sprite::create("background.png");
auto blur = ShaderManager::getInstance()->getBlurShader();
auto gp = GLProgramState::create(blur);
background->setGLProgram(blur);
background->setGLProgramState(gp);
gp->setUniformVec2("u_stepSize", Vec2(1.0/wndSize.width, 1.0/wndSize.height));
this->addChild(background);

```
> GLProgramState를 통해 셰이더에 각자 다른 uniform변수를 전달할 수 있다.

> 플랫폼에 따라 openGL, openGL ES 를 사용하는 경우가 있으므로 셰이더 코드를 작성할 때 유의해야 한다.
