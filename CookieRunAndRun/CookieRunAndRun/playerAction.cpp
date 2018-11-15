#include"playerAction.h"
PlayerAction* PlayerAction::s_pInstance = 0;

void PlayerAction::initAction() {
	m_action.push_back(new Player(new LoaderParams(300, 508, 150, 100, "basicCookieRun")));	//벡터 순서대로 행동이 정해져있음
	m_action.push_back(new Player(new LoaderParams(300, 508, 150, 100, "basicCookieJump1")));	//player에 있어야하나?
	m_action.push_back(new Player(new LoaderParams(300, 508, 150, 100, "basicCookieJump2")));
	m_action.push_back(new Player(new LoaderParams(300, 508, 150, 100, "basicCookieSlide")));
}

void PlayerAction::draw() {
	if (TheInputHandler::Instance()->jump) {
		m_action[1]->draw();
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		m_action[3]->draw();
	}
	else {
		m_action[0]->draw();
	}
}
void PlayerAction::update() {
	m_action[0]->update();
	m_action[1]->update();
	m_action[3]->update();
}