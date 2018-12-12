#include"mainMenu.h"

mainMenu::mainMenu(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
}
void mainMenu::draw()
{
	SDLGameObject::draw();
}
void mainMenu::update()
{
	SDLGameObject::update();
}
//void mainMenu::update2()
//{
//	//m_position.setX(-1300);
//	//m_position.setY(698);
//	if (m_position.getX() >= 0) {
//		m_velocity.setX(0);
//	}
//	else m_velocity.setX(10);
//	SDLGameObject::update();
//}
void mainMenu::clean()
{
	SDLGameObject::clean();
}