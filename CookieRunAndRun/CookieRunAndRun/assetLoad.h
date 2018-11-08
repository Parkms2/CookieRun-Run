#pragma once
#include"Game.h"
class assetLoad {
private:
	static assetLoad* s_pInstance;
public:
	static assetLoad* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new assetLoad();
			return s_pInstance;
		}
		return s_pInstance;
	}
	bool assetLoads(SDL_Renderer* m_pRenderer);
};
typedef assetLoad TheAssetLoad;

