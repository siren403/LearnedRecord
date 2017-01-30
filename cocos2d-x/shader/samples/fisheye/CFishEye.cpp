#include "CFishEye.h"

bool CFishEye::init()
{
    if(!Node::init())
    {
        return false;
    }

    mSprite = Sprite::create("texture.png");
    this->addChild(mSprite);

    auto tGLProgram = GLProgram::createWithFilenames("shader/ccPositionTextureColor_noMVP_vert.vsh", "shader/fisheye.fsh");
	auto tGLState = GLProgramState::getOrCreateWithGLProgram(tGLProgram);

	mSprite->setGLProgramState(tGLState);

	//todo : set uniform variables
	tGLState->setUniformTexture("u_tex", tTex);
	tGLState->setUniformFloat("u_aperture", 178.0);//default value

	tGLState->setUniformCallback("u_aperture", [](GLProgram * tGLProgram, Uniform * tUniform)
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

    return true;
}
