#include"pauseDraw.h"
#include"Game.h"
#include"pauseButtonControl.h"
pauseDraw::pauseDraw(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
}
void pauseDraw::draw()
{
	if (this->m_height == 107) {
		m_currentFrame = ThepauseButtonControl::Instance()->count;
	}
	SDLGameObject::draw(); // we now use SDLGameObject
}
void pauseDraw::update()	//정상적인 방법이 아님
{
	SDLGameObject::update();
}
void pauseDraw::clean()
{
}