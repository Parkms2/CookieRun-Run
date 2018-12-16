#pragma once
#include"SDLGameObject.h"

class UiBg : public SDLGameObject
{
public:
	UiBg(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
};