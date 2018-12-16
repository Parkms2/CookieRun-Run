#include"inGameUi.h"
#include"UiBg.h"
#include"button.h"
#include"Game.h"
#include"popupPauseState.h"

InGameUi* InGameUi::s_pInstance = 0;

void InGameUi::initInGameUi() {
	m_UI.push_back(new MenuButton(new LoaderParams(1200, 10, 55, 55, "pauseBtton"), pauseBtton));
	m_UI.push_back(new UiBg(new LoaderParams(239, 50, 802, 54, "hpBarBg")));
	m_UI.push_back(new UiBg(new LoaderParams(291, 62, 743, 30, "hpBar")));
	m_UI.push_back(new UiBg(new LoaderParams(1023, 54, 23, 45, "removeHp")));
}
void InGameUi::draw()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_UI.size(); i++) {
		m_UI[i]->draw();
	}
}
void InGameUi::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_UI.size(); i++) {
		m_UI[i]->update();
	}
}
void InGameUi::clean() {
	m_UI.clear();
}
void InGameUi::pauseBtton() {
	TheGame::Instance()->getStateMachine()->PopupState(PopupPauseState::Instance());
}