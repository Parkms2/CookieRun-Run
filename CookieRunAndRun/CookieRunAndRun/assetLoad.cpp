#include"assetLoad.h"

assetLoad* assetLoad::s_pInstance = 0;

bool assetLoad::assetLoads(SDL_Renderer* m_pRenderer) {
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/run.png", "basicCookieRun", m_pRenderer)) return false;
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/jump1-1.png", "basicCookieJump1", m_pRenderer)) return false;	
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/jump1-2.png", "basicCookieJump2", m_pRenderer)) return false;
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/slide.png", "basicCookieSlide", m_pRenderer)) return false;
	return true;
}