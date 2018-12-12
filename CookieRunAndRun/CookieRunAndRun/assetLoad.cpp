#include"assetLoad.h"

assetLoad* assetLoad::s_pInstance = 0;

bool assetLoad::assetLoadsPlay(SDL_Renderer* m_pRenderer) {
	//기본 쿠키
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/run.png", "basicCookieRun", m_pRenderer)) return false;
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/jump1-1.png", "basicCookieJump1", m_pRenderer)) return false;	
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/jump.png", "basicCookieJump2", m_pRenderer)) return false;
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/slide.png", "basicCookieSlide", m_pRenderer)) return false;

	//xx 쿠키

	//yy 쿠키

	//바닥 스프라이트
	if (!TheTextureManager::Instance()->load("assets/floors/level1Floor.png", "level1Floor", m_pRenderer)) return false;			//아직하나뿐.. 패턴을 한개만 이용하는 방법 찾아보기

	//백그라운드
	if (!TheTextureManager::Instance()->backLoad("assets/background/stage1Back.jpg", "stage1Back", m_pRenderer)) return false;		//아직 하나뿐..
	
	return true;
}
bool assetLoad::assetLoadsMenu(SDL_Renderer* m_pRenderer) {
	//로딩화면
	if (!TheTextureManager::Instance()->load("assets/mainmenu/roading.jpg", "roading", m_pRenderer)) return false;				//게임실행시 로딩화면 (빌드시 초반 렉걸리는 시간동안만)
	if (!TheTextureManager::Instance()->load("assets/mainmenu/roadingBar.png", "roadingBar", m_pRenderer)) return false;

	//메인 메뉴
	if (!TheTextureManager::Instance()->load("assets/mainmenu/mainLobby_bg.png", "mainLobby_bg", m_pRenderer)) return false;	//메인메뉴의 로비 백그라운드 화면
	if (!TheTextureManager::Instance()->load("assets/mainmenu/changeChar_bg.png", "changeChar_bg", m_pRenderer)) return false;	//캐릭터 교체화면의 백그라운드 화면

	return true;
}