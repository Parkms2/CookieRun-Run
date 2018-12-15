#include"popupPauseState.h"
#include"Game.h"
#include"pauseDraw.h"
#include"button.h"
#include"playerAction.h"
#include"blur.h"
#include"pauseButtonControl.h"

const std::string PopupPauseState::s_menuID = "POPUPPAUSE";
PopupPauseState* PopupPauseState::s_pInstance = 0;

void PopupPauseState::update() {
	for (int i = 0; i < m_obj.size(); i++) {
		m_obj[i]->update();
	}
	ThepauseButtonControl::Instance()->update();
}

void PopupPauseState::render() {
	for (int i = 0; i < m_obj.size(); i++) {
		m_obj[i]->draw();
	}
	ThepauseButtonControl::Instance()->draw();
}

bool PopupPauseState::onEnter()
{
	int x = dynamic_cast<SDLGameObject*>(PlayerAction::Instance()->m_action[PlayerAction::Instance()->getPosition()])->m_position.getX();
	int y = dynamic_cast<SDLGameObject*>(PlayerAction::Instance()->m_action[PlayerAction::Instance()->getPosition()])->m_position.getY();

	TheAssetLoad::Instance()->assetLoadsPopupPause(TheGame::Instance()->getRenderer());
	sshot = SDL_CreateRGBSurface(0, 1280, 720, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	sshot2 = SDL_CreateRGBSurface(0, 1280, 720, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(TheGame::Instance()->getRenderer(), NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
	TheBlur::Instance()->fastblur(sshot, 13);
	TheTextureManager::Instance()->screenShotLoad("sshot", sshot, TheGame::Instance()->getRenderer());
	SDL_RenderReadPixels(TheGame::Instance()->getRenderer(), NULL, SDL_PIXELFORMAT_ARGB8888, sshot2->pixels, sshot2->pitch);
	TheTextureManager::Instance()->screenShotLoad("sshot2", sshot2, TheGame::Instance()->getRenderer());

	m_obj.push_back(new pauseDraw(new LoaderParams(0, 0, 1280, 720, "sshot2")));
	m_obj.push_back(new pauseDraw(new LoaderParams(x-30, y-110, 90, 107, "resumeTimer")));
	m_obj.push_back(new pauseDraw(new LoaderParams(0, 0, 1280, 720, "sshot")));



	ThepauseButtonControl::Instance()->initButton();

	stopUpdate = true;
	std::cout << "entering PopupPauseState\n";
	return true;
}
bool PopupPauseState::delayOnExit()
{
	m_obj.clear();
	stopUpdate = false;
	std::cout << "exiting PopupPauseState\n";
	return true;
}
bool PopupPauseState::onExit()
{
	ThepauseButtonControl::Instance()->finish = true;
	m_obj.erase(m_obj.begin() + 2);
	ThepauseButtonControl::Instance()->clean();
	return true;
}