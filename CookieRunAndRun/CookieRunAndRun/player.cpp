#include"Player.h"
#include"popUpCCState.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	if (TheInputHandler::Instance()->jump) {
		if (PopupCCState::Instance()->selectCherryC) {
			m_currentFrame = 0;
		}
		else if (PopupCCState::Instance()->selectZombieC) {
			m_position.setX(281);
			m_currentFrame = 0;
		}
		else m_currentFrame = int(((SDL_GetTicks() / 100) % 3));// 화살표 윗키누르면 if(윗키눌렀음) 3장나눔 하고 다시 bool false로 변경 - 흠
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		m_position.setY(508);
		m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
	}
	else {
		m_position.setY(508);
		m_currentFrame = int(((SDL_GetTicks() / 100) % 4));// 화살표 윗키누르면 if(윗키눌렀음) 3장나눔 하고 다시 bool false로 변경 - 흠
	}
	SDLGameObject::update();
}
void Player::clean()
{
}
void Player::handleInput() {
	if ((TheInputHandler::Instance()->jump || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) && !TheInputHandler::Instance()->slide) {
		if (m_position.getY() <= 368) {	//점프의 정점
			m_velocity.setY(0);
			peek = true;
		}
		if (m_position.getY() > 368 && !peek) {		//위로 올라감
			m_velocity.setY(-6);
		}
		else if (m_position.getY() < 508 && peek) {	//아래로 내려감
			m_velocity.setY(6);
		}
		else if (m_position.getY() == 508 || m_position.getY() == 514) {	//점프후 다시 내려옴
			peek = false;
			TheInputHandler::Instance()->jump = false;
			if(PopupCCState::Instance()->selectZombieC) m_position.setX(300);
		}

		//더블점프는 구현 어떻게 할까?
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN) && !TheInputHandler::Instance()->jump) {	//슬라이딩
	}
}