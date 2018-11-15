#include"floor.h"

Floor::Floor(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
	myPosition = m_position.getX();
}
void Floor::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Floor::update()	//정상적인 방법이 아님
{
	m_velocity.setX(-6); // 2^3*3^2*19 = 1388
	if (m_position.getX() == myPosition - 1368) {
		m_position.setX(myPosition);
	}
	SDLGameObject::update();
}
void Floor::clean()
{
}