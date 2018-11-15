#pragma once
#include"SDLGameObject.h"
#include"InputHandler.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	bool peek = false;	//점프 꼭지점
private:
	void handleInput(); 
};