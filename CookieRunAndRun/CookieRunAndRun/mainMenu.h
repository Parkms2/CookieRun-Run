#pragma once
#include"SDLGameObject.h"

class mainMenu : public SDLGameObject
{
public:
	mainMenu(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	int myPosition;
private:
};