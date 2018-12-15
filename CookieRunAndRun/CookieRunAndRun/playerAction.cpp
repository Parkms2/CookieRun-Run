#include"playerAction.h"
PlayerAction* PlayerAction::s_pInstance = 0;

void PlayerAction::initAction() {
	m_action.push_back(new Player(new LoaderParams(300, 508, 150, 100, "basicCookieRun")));	//���� ������� �ൿ�� ����������
	m_action.push_back(new Player(new LoaderParams(300, 508, 150, 100, "basicCookieJump1")));	//player�� �־���ϳ�?
	m_action.push_back(new Player(new LoaderParams(300, 508, 150, 100, "basicCookieSlide")));
	TheInputHandler::Instance()->jump = false;
	TheInputHandler::Instance()->slide = false;
	TheInputHandler::Instance()->doubleJump = false;
}

void PlayerAction::draw() {
	if (TheInputHandler::Instance()->jump)  {	//�������
		m_action[1]->draw();
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {		//�����̵� ���
		m_action[2]->draw();
	}
	else {		//�Ϲ� �޸��� ���
		m_action[0]->draw();
	}
}
void PlayerAction::update() {
	m_action[0]->update();
	m_action[1]->update();
	m_action[2]->update();
}
int PlayerAction::getPosition() {
	if (TheInputHandler::Instance()->jump) {	//�������
		return 1;
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {		//�����̵� ���
		return 2;
	}
	else {		//�Ϲ� �޸��� ���
		return 0;
	}
}
void PlayerAction::clean() {
	m_action.clear();
}