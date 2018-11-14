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
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));// 화살표 윗키누르면 if(윗키눌렀음) 3장나눔 하고 다시 bool false로 변경 - 흠
	SDLGameObject::update();
}
void Player::clean()
{
}
void Player::handleInput() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) || jump) {
		jump = true;
		if (m_position.getY() == 130) {
			peek = true;
		}
		else if (m_position.getY() == 300) {
			peek = false;
		}
		if (m_position.getY() > 130 && !peek) {
			m_velocity.setY(-10);
		}
		if (m_position.getY() < 300 && peek) {
			m_velocity.setY(10);
		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
}