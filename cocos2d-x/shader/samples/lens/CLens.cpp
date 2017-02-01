#include "CLens.h"

bool CLens::init()
{
    if(!Node::init())
    {
        return false;
    }

    mSprite = Sprite::create("texture.png");
    this->addChild(mSprite);

    auto tGLProgram = GLProgram::createWithFilenames(
        "shader/ccPositionTextureColor_noMVP_vert.vsh",
         "shader/lens.fsh"
     );
	mGLState = GLProgramState::getOrCreateWithGLProgram(tGLProgram);
    mSprite->setGLProgramState(mGLState);

    mCurrentLensSize = 0.4f;
	mGLState->setUniformFloat("u_lensSize", mCurrentLensSize);
	mGLState->setUniformVec3("u_lensColor", Vec3(0.7,0.4,0.1));
	mCurrentLensOutLine = 0.01;
	mGLState->setUniformFloat("u_outLine", mCurrentLensOutLine);
	mCurrentLensInLine = 0.01;
	mGLState->setUniformFloat("u_inLine", mCurrentLensInLine);
	mGLState->setUniformVec2("u_resolution", visibleSize);
	mGLState->setUniformCallback("u_mouse", [this](GLProgram * tProg,Uniform * tUni)
	{
		tProg->setUniformLocationWith2f(
			tUni->location,
			this->mMousePos.x,
			this->mMousePos.y
		);
	});
	auto tMouseListener = EventListenerMouse::create();
	tMouseListener->onMouseMove = [this](EventMouse * tMouseEvent)
	{
		this->mMousePos = tMouseEvent->getLocation();
	};
	tMouseListener->onMouseScroll = [this](EventMouse * tMouseEvent)
	{
		float val = tMouseEvent->getScrollY() * 0.1;
		val = -val;
		this->mCurrentLensSize = clampf(
            this->mCurrentLensSize + val, 0, 5);
		this->mGLState->setUniformFloat(
            "u_lensSize",
            this->mCurrentLensSize
        );
	};
	tMouseListener->onMouseDown = [this](EventMouse * tMouseEvent)
	{
		bool isOutLine = false;

		if (isOutLine)
		{
			if (tMouseEvent->getMouseButton() == MOUSE_BUTTON_LEFT)
			{
				this->mCurrentLensOutLine += 0.01;
			}
			else if (tMouseEvent->getMouseButton() == MOUSE_BUTTON_RIGHT)
			{
				this->mCurrentLensOutLine -= 0.01;
			}
			this->mCurrentLensOutLine = clampf(this->mCurrentLensOutLine, 0, 1);
			this->mGLState->setUniformFloat("u_outLine", mCurrentLensOutLine);
		}
		else
		{
			if (tMouseEvent->getMouseButton() == MOUSE_BUTTON_LEFT)
			{
				mCurrentLensInLine += 0.01;
			}
			else if (tMouseEvent->getMouseButton() == MOUSE_BUTTON_RIGHT)
			{
				mCurrentLensInLine -= 0.01;
			}
			mCurrentLensInLine = clampf(mCurrentLensInLine, 0, 1);
			mGLState->setUniformFloat("u_inLine", mCurrentLensInLine);
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(
        tMouseListener,
        this
    );

    return true;
}
