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
	if (!PopupPauseState::Instance()->stopUpdate) {	//�Ͻ������� �ƴϸ� ����
		TheBackgroundControl::Instance()->update();
		TheFloorControl::Instance()->update();
		ThePlayerAction::Instance()->update();
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
			TheGame::Instance()->getStateMachine()->PopupState(PopupPauseState::Instance());
		}
	}
	else if (PopupPauseState::Instance()->stopUpdate) {	//�Ͻ������� ����
		PopupPauseState::Instance()->update();
	}
}
void PlayState::render()
{
	if (!PopupPauseState::Instance()->stopUpdate) {	//�Ͻ������� �ƴϸ� ����
		TheBackgroundControl::Instance()->draw();
		TheFloorControl::Instance()->draw();
		ThePlayerAction::Instance()->draw();
	}
	else if (PopupPauseState::Instance()->stopUpdate) { //�Ͻ������� ����
		PopupPauseState::Instance()->render();
	}
}
bool PlayState::onEnter()
{
	TheAssetLoad::Instance()->assetLoadsPlay(TheGame::Instance()->getRenderer());	//��� ���� �ҽ��� �ε������
	ThePlayerAction::Instance()->initAction();
	TheFloorControl::Instance()->initFloor();
	TheBackgroundControl::Instance()->initBackground();
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	ThePlayerAction::Instance()->clean();
	TheFloorControl::Instance()->clean();
	TheBackgroundControl::Instance()->clean();
	std::cout << "exiting PlayState\n";
	return true;
}