#include"resultBg.h"
ResultBg::ResultBg(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
}
void ResultBg::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void ResultBg::update()	//정상적인 방법이 아님
{
	SDLGameObject::update();
}
void ResultBg::clean()
{
}