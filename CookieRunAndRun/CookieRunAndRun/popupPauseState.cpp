#include"popupPauseState.h"
#include"Game.h"
#include"pauseDraw.h"
const std::string PopupPauseState::s_menuID = "POPUPPAUSE";
PopupPauseState* PopupPauseState::s_pInstance = 0;

void PopupPauseState::update() {
	for (int i = 0; i < m_obj.size(); i++) {
		m_obj[i]->update();
	}
}

void PopupPauseState::render() {
	for (int i = 0; i < m_obj.size(); i++) {
		m_obj[i]->draw();
	}
}

bool PopupPauseState::onEnter()
{
	m_obj.push_back(new pauseDraw(new LoaderParams(0, 0, 1280, 720, "sshot")));
	stopUpdate = true;
	std::cout << "entering PopupPauseState\n";
	return true;
}

bool PopupPauseState::onExit()
{
	stopUpdate = false;
	std::cout << "exiting PopupPauseState\n";
	return true;
}