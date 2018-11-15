#include"Background.h"

Background::Background(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
	myPosition = m_position.getX();
}
void Background::draw()
{
	SDLGameObject::draw();
}
void Background::update()	//�������� ����� �ƴ�
{
	m_velocity.setX(-1); // 2^3*3^2*19 = 1388
	if (m_position.getX() == myPosition - 1280) {
		m_position.setX(myPosition);
	}
	SDLGameObject::update();

}
void Background::clean()
{
}