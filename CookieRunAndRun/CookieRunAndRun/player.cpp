#include"Player.h"

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
		m_currentFrame = int(((SDL_GetTicks() / 100) % 3));// 화살표 윗키누르면 if(윗키눌렀음) 3장나눔 하고 다시 bool false로 변경 - 흠
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
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
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)||TheInputHandler::Instance()->jump) {
		if (m_position.getY() <= 348) {	//346 352 ... 382 ...  502 508
			m_velocity.setY(0);
			peek = true;
		}
		if (m_position.getY() > 348 && !peek) {
			m_velocity.setY(-6);
		}
		else if (m_position.getY() < 508 && peek) {
			m_velocity.setY(6);
		}
		else if (m_position.getY() == 508 || m_position.getY() == 514) {
			peek = false;
			TheInputHandler::Instance()->jump = false;
		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		m_position.setY(558);
	}
}