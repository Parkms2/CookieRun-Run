#pragma once
#include"SDLGameObject.h"

class popupCCBg : public SDLGameObject
{
public:
	popupCCBg(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	bool eyeClose = true;

	int eyeTime = 5000;
	int nextTime = 0;

	int eyeClosing = 0;
	int eyeClosingTime = 130;
};