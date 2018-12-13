#include "PlayState.h"
#include"popupPauseState.h"
#include"Player.h"
#include"floorControl.h"
#include"backgroundControl.h"
#include"playerAction.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;
void PlayState::update()
{
	TheBackgroundControl::Instance()->update();
	TheFloorControl::Instance()->update();
	ThePlayerAction::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGameStateMachine::Instance()->changeState(PopupPauseState::Instance());
	}
}
void PlayState::render()
{
	TheBackgroundControl::Instance()->draw();
	TheFloorControl::Instance()->draw();
	ThePlayerAction::Instance()->draw();
}
bool PlayState::onEnter()
{
	TheAssetLoad::Instance()->assetLoadsPlay(TheGame::Instance()->getRenderer());	//모든 에셋 소스를 로드시켜줌
	ThePlayerAction::Instance()->initAction();
	TheFloorControl::Instance()->initFloor();
	TheBackgroundControl::Instance()->initBackground();
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}