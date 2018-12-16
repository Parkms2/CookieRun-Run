#pragma once
#include<vector>
#include"SDLGameObject.h"
#include"TextureManager.h"

class InGameUi {
public:
	InGameUi() {}
	static InGameUi* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InGameUi();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void initInGameUi();
	void draw();
	void update();
	void clean();
	static void pauseBtton();
	std::vector<GameObject*> m_UI;
private:
	static InGameUi* s_pInstance;
};

typedef InGameUi TheInGameUi;