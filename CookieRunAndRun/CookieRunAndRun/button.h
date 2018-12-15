#pragma once
#include"SDLGameObject.h"

enum button_state
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 0,
	CLICKED = 0
};

class MenuButton : public SDLGameObject
{
public:
	MenuButton(const LoaderParams* pParams, void(*callback)());
	virtual void draw();
	virtual void update();
	virtual void clean();

	void(*m_callback)();
	bool m_bReleased;
};