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
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) || TheInputHandler::Instance()->jump) {	//점프 방식부터 잘못된듯
		//한번 눌림이아니라 아주 잠깐 키다운이 되는 상황 -> 한번 누르기만 하면 실행되는걸로 바꾸기
		if (m_position.getY() <= 368) {
			m_velocity.setY(0);
			peek = true;
		}
		if (m_position.getY() > 368 && !peek) {
			m_velocity.setY(-6);
		}
		else if (m_position.getY() < 508 && peek) {
			m_velocity.setY(6);
		}
		else if (m_position.getY() == 508 || m_position.getY() == 514) {
			peek = false;
			TheInputHandler::Instance()->jump = false;
		}

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {		//이방식 뭔가 이상함 -> 키다운 방식을 버튼클릭방식으로
			TheInputHandler::Instance()->jump = false;
			TheInputHandler::Instance()->doubleJump = true;
		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && TheInputHandler::Instance()->doubleJump) {	//흠..
		if (m_position.getY() > 368) {
			m_velocity.setY(-6);
		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		m_position.setY(558);
	}
}