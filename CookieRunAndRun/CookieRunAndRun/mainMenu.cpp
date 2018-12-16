#include"mainMenu.h"
#include"MenuState.h"

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
	for (int i = 0; i < MenuState::Instance()->m_effect.size(); i++) {
		if (dynamic_cast<SDLGameObject*>(MenuState::Instance()->m_effect[i])->m_width == 32
			|| dynamic_cast<SDLGameObject*>(MenuState::Instance()->m_effect[i])->m_width == 35
			|| dynamic_cast<SDLGameObject*>(MenuState::Instance()->m_effect[i])->m_width == 38) {
			if (dynamic_cast<SDLGameObject*>(MenuState::Instance()->m_effect[i])->m_position.getY() <= 240) {
				MenuState::Instance()->m_effect.erase(MenuState::Instance()->m_effect.begin() + i);
			}
			else dynamic_cast<SDLGameObject*>(MenuState::Instance()->m_effect[i])->m_velocity.setY(-1);
		}
	}
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