#include"popupCCBg.h"
#include"popUpCCState.h"
popupCCBg::popupCCBg(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
}
void popupCCBg::draw()
{
	SDLGameObject::draw();
}
void popupCCBg::update()
{

	if (!eyeClose) {
		if (PopupCCState::Instance()->selectBasicC || PopupCCState::Instance()->selectCherryC || PopupCCState::Instance()->selectZombieC) {
			dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[1])->m_position.setX(-300);
			dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[1])->m_position.setY(-300);
		}
		if (SDL_GetTicks() > nextTime) {
			nextTime = SDL_GetTicks() + eyeTime;
			eyeClosing = SDL_GetTicks() + eyeClosingTime;
			eyeClose = true;
		}
	}
	else if (eyeClose) {
		if (PopupCCState::Instance()->selectBasicC) {
			dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[1])->m_position.setX(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.getX() + 63);
			dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[1])->m_position.setY(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.getY() + 30);
		}
		else if (PopupCCState::Instance()->selectCherryC) {
			dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[1])->m_position.setX(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.getX() + 53);
			dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[1])->m_position.setY(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.getY() + 59);
		}
		else if (PopupCCState::Instance()->selectZombieC) {
			dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[1])->m_position.setX(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.getX() + 75);
			dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[1])->m_position.setY(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.getY() + 31);
		}
		if (eyeClosing < SDL_GetTicks()) {
			eyeClose = false;
		}
	}
	
	SDLGameObject::update();

}
void popupCCBg::clean()
{
}