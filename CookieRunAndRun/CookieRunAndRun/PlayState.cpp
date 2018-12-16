#include "PlayState.h"
#include"popupPauseState.h"
#include"floorControl.h"
#include"backgroundControl.h"
#include"inGameUi.h"
#include"chooseCookie.h"
#include"resultState.h"
const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;
void PlayState::update()
{
	if (PopupPauseState::Instance()->stopUpdate) {	//일시정지면 실행
		PopupPauseState::Instance()->update();
	}
	else if (ResultState::Instance()->resultTime) {	//게임끝났으면 실행
		ResultState::Instance()->update();
	}
	else {
		TheBackgroundControl::Instance()->update();
		TheFloorControl::Instance()->update();
		ThechooseCookie::Instance()->update();
		TheInGameUi::Instance()->update();
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
			TheGame::Instance()->getStateMachine()->PopupState(PopupPauseState::Instance());
		}
		if (nextTime < SDL_GetTicks()) {
			hp -= 6;
			score += 100;
			nextTime = SDL_GetTicks() + timeLeft;
		}
		if (hp <= 0) {
			TheGame::Instance()->getStateMachine()->PopupState(ResultState::Instance());
		}
	}

}
void PlayState::render()
{
	if (PopupPauseState::Instance()->stopUpdate) { //일시정지면 실행
		PopupPauseState::Instance()->render();
	}
	else if (ResultState::Instance()->resultTime) {	//게임끝났으면 실행
		ResultState::Instance()->render();
	}
	else {
		TheBackgroundControl::Instance()->draw();
		TheFloorControl::Instance()->draw();
		TheInGameUi::Instance()->draw();
		ThechooseCookie::Instance()->draw();
	}
}
bool PlayState::onEnter()
{
	TheAssetLoad::Instance()->assetLoadsPlay(TheGame::Instance()->getRenderer());	//모든 에셋 소스를 로드시켜줌
	ThechooseCookie::Instance()->initAction();
	TheFloorControl::Instance()->initFloor();
	TheBackgroundControl::Instance()->initBackground();
	TheInGameUi::Instance()->initInGameUi();
	//hp = 743;
	hp = 50;
	score = 0;
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	ThechooseCookie::Instance()->clean();
	TheFloorControl::Instance()->clean();
	TheBackgroundControl::Instance()->clean();
	TheInGameUi::Instance()->clean();
	std::cout << "exiting PlayState\n";
	return true;
}