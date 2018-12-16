#pragma once
#include"SDLGameObject.h"

class ResultBg : public SDLGameObject
{
public:
	ResultBg(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};