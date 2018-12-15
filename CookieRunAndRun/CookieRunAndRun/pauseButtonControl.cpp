#include"pauseButtonControl.h"
#include"button.h"
#include"Game.h"
#include"popupPauseState.h"
pauseButtonControl* pauseButtonControl::s_pInstance = 0;

void pauseButtonControl::initButton() {
	m_obj.push_back(new MenuButton(new LoaderParams(453, 140, 374, 100, "pauseText"), justText));
	m_obj.push_back(new MenuButton(new LoaderParams(453, 280, 374, 100, "resumeButton"), s_resume));
	m_obj.push_back(new MenuButton(new LoaderParams(453, 420, 374, 100, "stopButton"), s_stop));
	finish = false;
	count = 0;
}
void pauseButtonControl::draw() {
	for (int i = 0; i < m_obj.size(); i++) {
		m_obj[i]->draw();
	}
}
void pauseButtonControl::update() {
	if (finish) {
		if (count == 2) {
			PopupPauseState::Instance()->delayOnExit();
		}
		count++;
		SDL_Delay(700);
	}
	for (int i = 0; i < m_obj.size(); i++) {
		m_obj[i]->update();
	}
}
void pauseButtonControl::clean() {
	m_obj.clear();
}

void pauseButtonControl::justText() {

}
void pauseButtonControl::s_resume() {
	TheGame::Instance()->getStateMachine()->finishPopupState(PopupPauseState::Instance());
}
void pauseButtonControl::s_stop() {
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
	PopupPauseState::Instance()->delayOnExit();
}