#include"playerAction.h"
PlayerAction* PlayerAction::s_pInstance = 0;

void PlayerAction::initAction(string run, string jump, string slide) {
	m_action.push_back(new Player(new LoaderParams(300, 508, 150, 100, run)));	//벡터 순서대로 행동이 정해져있음
	m_action.push_back(new Player(new LoaderParams(300, 508, 150, 100, jump)));	//player에 있어야하나?
	m_action.push_back(new Player(new LoaderParams(300, 508, 150, 100, slide)));
	TheInputHandler::Instance()->jump = false;
	TheInputHandler::Instance()->slide = false;
	TheInputHandler::Instance()->doubleJump = false;
}

void PlayerAction::draw() {
	if (TheInputHandler::Instance()->jump)  {	//점프모션
		m_action[1]->draw();
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {		//슬라이딩 모션
		m_action[2]->draw();
	}
	else {		//일반 달리기 모션
		m_action[0]->draw();
	}
}
void PlayerAction::update() {
	for (int i = 0; i < m_action.size(); i++) {
		m_action[i]->update();
	}

}
int PlayerAction::getAction() {
	if (TheInputHandler::Instance()->jump) {	//점프모션
		return 1;
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {		//슬라이딩 모션
		return 2;
	}
	else {		//일반 달리기 모션
		return 0;
	}
}
void PlayerAction::clean() {
	m_action.clear();
}