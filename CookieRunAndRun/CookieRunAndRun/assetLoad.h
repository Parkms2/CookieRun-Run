#pragma once
#include"Game.h"
class assetLoad {
public:
	static assetLoad* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new assetLoad();
			return s_pInstance;
		}
		return s_pInstance;
	}
	bool assetLoadsPlay(SDL_Renderer* m_pRenderer);
	bool assetLoadsMenu(SDL_Renderer* m_pRenderer);
	bool assetLoadsPopupPause(SDL_Renderer* m_pRenderer);
	bool assetResultState(SDL_Renderer* m_pRenderer);
private:
	static assetLoad* s_pInstance;
};
typedef assetLoad TheAssetLoad;

