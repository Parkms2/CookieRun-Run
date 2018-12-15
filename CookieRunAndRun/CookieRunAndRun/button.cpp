#include"button.h"
#include"InputHandler.h"
MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) : SDLGameObject(pParams), m_callback(callback)
{
	firstPosition = this->m_position.getX();
}
void MenuButton::draw()
{
	SDLGameObject::draw(); // use the base class drawing
}
void MenuButton::update() {
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();
	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		if (TheInputHandler::Instance()->getMouseButtonState(0) && m_bReleased) {
			m_currentFrame = CLICKED;
			m_callback(); // call our callback function
			m_bReleased = false;
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(0)) {
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else {
		m_currentFrame = MOUSE_OUT;
	}

	if (this->m_width == 340) {
		if (this->m_position.getX() < firstPosition - 300) {
			this->m_velocity.setX(0);
		}
		else this->m_velocity.setX(-10);
	}
	SDLGameObject::update();
}
void MenuButton::clean()
{
	SDLGameObject::clean();
}