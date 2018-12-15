#pragma once
#include"SDLGameObject.h"

class pauseDraw : public SDLGameObject
{
public:
	pauseDraw(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	SDL_Surface *sshot;
	SDL_Surface *sshot2;
};