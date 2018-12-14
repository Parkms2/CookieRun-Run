#include"pauseDraw.h"
#include"Game.h"
pauseDraw::pauseDraw(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	sshot = SDL_CreateRGBSurface(0, 1280, 720, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(TheGame::Instance()->getRenderer(), NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
	TheTextureManager::Instance()->blurImageDraw(sshot, 1);
	TheTextureManager::Instance()->screenShotLoad("sshot", sshot, TheGame::Instance()->getRenderer());
	m_currentFrame = 0;
}
void pauseDraw::draw()
{

	SDLGameObject::draw(); // we now use SDLGameObject
}
void pauseDraw::update()	//�������� ����� �ƴ�
{
	SDLGameObject::update();
}
void pauseDraw::clean()
{
}