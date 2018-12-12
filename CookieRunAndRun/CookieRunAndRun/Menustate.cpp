#include "MenuState.h"
#include"mainMenu.h"
#include"Game.h"
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

	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	return true;
}