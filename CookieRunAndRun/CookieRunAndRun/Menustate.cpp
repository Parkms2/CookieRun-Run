#include "MenuState.h"
#include"mainMenu.h"
#include"Game.h"
#include"button.h"

const std::string MenuState::s_menuID = "MENU";
MenuState* MenuState::s_pInstance = 0;
void MenuState::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i < main_bg.size(); i++) {
		main_bg[i]->update();
	}
}

void MenuState::render()
{

	for (std::vector<GameObject*>::size_type i = 0; i < main_bg.size(); i++) {
		main_bg[i]->draw();
	}
}

bool MenuState::onEnter()
{
	TheAssetLoad::Instance()->assetLoadsMenu(TheGame::Instance()->getRenderer());	//모든 에셋 소스를 로드시켜줌
	main_bg.push_back(new mainMenu(new LoaderParams(-60, 0, 1340, 720, "mainLobby_bg")));
	main_bg.push_back(new MenuButton(new LoaderParams(1280, 130, 340, 82, "1gamestart"), gamestart));
	main_bg.push_back(new MenuButton(new LoaderParams(1280, 230, 340, 82, "2changeCookie"), gamestart));
	main_bg.push_back(new MenuButton(new LoaderParams(1280, 330, 340, 82, "3dnsQKfakdrpa"), gamestart));
	main_bg.push_back(new MenuButton(new LoaderParams(1280, 430, 340, 82, "4recode"), gamestart));

	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::gamestart() {
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}