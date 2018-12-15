#include"popupPauseState.h"
#include"Game.h"
#include"pauseDraw.h"
#include"button.h"
#include"playerAction.h"
const std::string PopupPauseState::s_menuID = "POPUPPAUSE";
PopupPauseState* PopupPauseState::s_pInstance = 0;

void PopupPauseState::update() {
	if (finish) {
		if (count == 2) {
			delayOnExit();
		}
		count++;
		SDL_Delay(700);
	}
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
	int x = dynamic_cast<SDLGameObject*>(PlayerAction::Instance()->m_action[PlayerAction::Instance()->getPosition()])->m_position.getX();
	int y = dynamic_cast<SDLGameObject*>(PlayerAction::Instance()->m_action[PlayerAction::Instance()->getPosition()])->m_position.getY();
	TheAssetLoad::Instance()->assetLoadsPopupPause(TheGame::Instance()->getRenderer());
	m_obj.push_back(new pauseDraw(new LoaderParams(0, 0, 1280, 720, "sshot2")));
	m_obj.push_back(new pauseDraw(new LoaderParams(x-30, y-120, 90, 107, "resumeTimer")));
	m_obj.push_back(new pauseDraw(new LoaderParams(0, 0, 1280, 720, "sshot")));
	m_obj.push_back(new MenuButton(new LoaderParams(453, 140, 374, 100, "pauseText"), justText));
	m_obj.push_back(new MenuButton(new LoaderParams(453, 280, 374, 100, "resumeButton"), s_resume));
	m_obj.push_back(new MenuButton(new LoaderParams(453, 420, 374, 100, "stopButton"), s_stop));
	stopUpdate = true;
	std::cout << "entering PopupPauseState\n";
	finish = false;
	count = 0;
	return true;
}
void PopupPauseState::justText() {

}
void PopupPauseState::s_resume() {
	TheGame::Instance()->getStateMachine()->finishPopupState(PopupPauseState::Instance());
}
void PopupPauseState::s_stop() {
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
	PopupPauseState::Instance()->delayOnExit();
}
bool PopupPauseState::delayOnExit()
{
	m_obj.clear();
	stopUpdate = false;
	std::cout << "exiting PopupPauseState\n";
	return true;
}
bool PopupPauseState::onExit()
{
	finish = true;
	for (int i = 2; i < 6; i++) {
		m_obj.erase(m_obj.begin() + 2);
	}
	return true;
}