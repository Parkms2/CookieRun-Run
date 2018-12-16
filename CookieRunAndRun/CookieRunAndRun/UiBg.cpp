#include"UiBg.h"
#include"inGameUi.h"
#include"PlayState.h"

UiBg::UiBg(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
}
void UiBg::draw()
{
	SDLGameObject::draw();
}
void UiBg::update()
{
	if (dynamic_cast<SDLGameObject*>(InGameUi::Instance()->m_UI[3])->m_position.getX() > 280) {
		if (dynamic_cast<SDLGameObject*>(InGameUi::Instance()->m_UI[3])->m_width == 23) {
			dynamic_cast<SDLGameObject*>(InGameUi::Instance()->m_UI[3])->m_position.setX(280 + PlayState::Instance()->hp);

		}
	}
	SDLGameObject::update();

}
void UiBg::clean()
{
}