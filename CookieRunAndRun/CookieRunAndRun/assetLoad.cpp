#include"assetLoad.h"

assetLoad* assetLoad::s_pInstance = 0;

bool assetLoad::assetLoads(SDL_Renderer* m_pRenderer) {
	//�⺻ ��Ű
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/run.png", "basicCookieRun", m_pRenderer)) return false;
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/jump1-1.png", "basicCookieJump1", m_pRenderer)) return false;	
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/jump.png", "basicCookieJump2", m_pRenderer)) return false;
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/slide.png", "basicCookieSlide", m_pRenderer)) return false;
	//xx ��Ű


	//�ٴ� ��������Ʈ
	if (!TheTextureManager::Instance()->load("assets/floors/level1Floor.png", "level1Floor", m_pRenderer)) return false;

	//��׶���
	if (!TheTextureManager::Instance()->backLoad("assets/background/stage1Back.jpg", "stage1Back", m_pRenderer)) return false;
	
	return true;
}