#include "MenuState.h"
#include"mainMenu.h"
#include"Game.h"
#include"button.h"
#include"popUpCCState.h"
const std::string MenuState::s_menuID = "MENU";
MenuState* MenuState::s_pInstance = 0;
void MenuState::update()
{
	if (!PopupCCState::Instance()->popupCCState) {
		for (int i = 0; i < main_bg.size(); i++) {
			main_bg[i]->update();
		}
		for (int i = 0; i < m_effect.size(); i++) {
			m_effect[i]->update();
		}
		if (nextTime < SDL_GetTicks()) {
			effectRender = rand() % 3;
			effectPosition = rand() % 170 + 520;
			if (effectRender == 0) {
				m_effect.push_back(new mainMenu(new LoaderParams(effectPosition, 450, 35, 34, "effect2")));
			}
			else if (effectRender == 1) {
				m_effect.push_back(new mainMenu(new LoaderParams(effectPosition, 450, 32, 32, "effect3")));
			}
			else if (effectRender == 2) {
				m_effect.push_back(new mainMenu(new LoaderParams(effectPosition, 450, 38, 30, "effect4")));
			}
			nextTime = SDL_GetTicks() + timeLeft;
		}
	}
	PopupCCState::Instance()->update();
}

void MenuState::render()
{

	for (int i = 0; i < main_bg.size(); i++) {
		main_bg[i]->draw();
	}
	for (int i = 0; i < m_effect.size(); i++) {
		m_effect[i]->draw();
	}
	PopupCCState::Instance()->render();
}

bool MenuState::onEnter()
{
	TheAssetLoad::Instance()->assetLoadsMenu(TheGame::Instance()->getRenderer());	//모든 에셋 소스를 로드시켜줌
	main_bg.push_back(new mainMenu(new LoaderParams(-60, 0, 1340, 720, "mainLobby_bg")));
	main_bg.push_back(new MenuButton(new LoaderParams(1280, 130, 340, 82, "1gamestart"), gamestart));
	main_bg.push_back(new MenuButton(new LoaderParams(1280, 230, 340, 82, "2changeCookie"), changeCookie));
	//main_bg.push_back(new MenuButton(new LoaderParams(1280, 330, 340, 82, "3dnsQKfakdrpa"), dnsQKfakdrpa));
	//main_bg.push_back(new MenuButton(new LoaderParams(1280, 430, 340, 82, "4recode"), recode));


	m_effect.push_back(new mainMenu(new LoaderParams(455, 180, 350, 350, "effect1")));


	if (PopupCCState::Instance()->selectBasicC) PopupCCState::Instance()->selectBasic();
	else if (PopupCCState::Instance()->selectCherryC) PopupCCState::Instance()->selectCherry();
	else if (PopupCCState::Instance()->selectZombieC) PopupCCState::Instance()->selectZombie();
	dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.setX(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.getX() + 213);
	dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.setY(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.getY() - 40);

	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	main_bg.clear();
	m_effect.clear();
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::gamestart() {
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}
void MenuState::changeCookie() {
	TheGame::Instance()->getStateMachine()->PopupState(PopupCCState::Instance());
}
void MenuState::dnsQKfakdrpa() {

}
void MenuState::recode() {

}