#include"pauseDraw.h"
#include"Game.h"
#include"blur.h"
#include"popupPauseState.h"
pauseDraw::pauseDraw(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	sshot = SDL_CreateRGBSurface(0, 1280, 720, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	sshot2 = SDL_CreateRGBSurface(0, 1280, 720, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

	SDL_RenderReadPixels(TheGame::Instance()->getRenderer(), NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
	TheBlur::Instance()->gaussBlur_4(sshot, 23);
	TheTextureManager::Instance()->screenShotLoad("sshot", sshot, TheGame::Instance()->getRenderer());

	SDL_RenderReadPixels(TheGame::Instance()->getRenderer(), NULL, SDL_PIXELFORMAT_ARGB8888, sshot2->pixels, sshot2->pitch);
	TheTextureManager::Instance()->screenShotLoad("sshot2", sshot2, TheGame::Instance()->getRenderer());
	m_currentFrame = 0;
}
void pauseDraw::draw()
{
	if (this->m_height == 107) {
		m_currentFrame = PopupPauseState::Instance()->count;
	}
	SDLGameObject::draw(); // we now use SDLGameObject
}
void pauseDraw::update()	//정상적인 방법이 아님
{
	SDLGameObject::update();
}
void pauseDraw::clean()
{
}
