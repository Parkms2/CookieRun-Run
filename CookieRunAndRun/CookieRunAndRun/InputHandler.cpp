#include"InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;
Vector2D* m_mousePosition = new Vector2D(0, 0);

InputHandler::InputHandler() {
	for (int i = 0; i < 3; i++) {
		m_mouseButtonStates.push_back(false);
	}
}
void InputHandler::clean() {
	// ���� �߰� 
}
void InputHandler::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}
}
bool InputHandler::isKeyDown(SDL_Scancode key) {
	if (m_keystates != 0) {
		if (m_keystates[key] == 1) {
			if (m_keystates[key] == m_keystates[SDL_SCANCODE_UP] && jump == false && slide == false) {
				jump = true;
			}
			if (m_keystates[key] == m_keystates[SDL_SCANCODE_DOWN] && jump == false && slide == false) {	//�����̵��� ������ �Ǵ°� �����ϱ�����
				slide = true;
			}
			else if (m_keystates[key] != m_keystates[SDL_SCANCODE_DOWN] && slide == true) {		//�����̵� ������ slide = false
				slide = false;
			}
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}
bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}
void InputHandler::onMouseButtonDown(SDL_Event event) {
	if (event.button.button == SDL_BUTTON_LEFT) {
		m_mouseButtonStates[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE) {
		m_mouseButtonStates[MIDDLE] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT) {
		m_mouseButtonStates[RIGHT] = true;
	}
}
void InputHandler::onMouseButtonUp(SDL_Event event) {
	if (event.button.button == SDL_BUTTON_LEFT) {
		m_mouseButtonStates[LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE) {
		m_mouseButtonStates[MIDDLE] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT) {
		m_mouseButtonStates[RIGHT] = false;
	}
}
void InputHandler::onKeyDown() {
	m_keystates = SDL_GetKeyboardState(0);
}
void InputHandler::onKeyUp() {
	m_keystates = SDL_GetKeyboardState(0);
}