#include"popupPauseState.h"

const std::string PopupPauseState::s_menuID = "POPUPPAUSE";
PopupPauseState* PopupPauseState::s_pInstance = 0;

void PopupPauseState::update() {
}

void PopupPauseState::render() {

}

bool PopupPauseState::onEnter()
{
	std::cout << "entering PopupPauseState\n";
	return true;
}

bool PopupPauseState::onExit()
{
	std::cout << "exiting PopupPauseState\n";
	return true;
}