#pragma once
#include<vector>
#include"SDLGameObject.h"
#include"TextureManager.h"
#include<SDL_ttf.h>
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

	TTF_Font * font;
	SDL_Color color;
	SDL_Surface * surface;
	SDL_Texture * texture;
	SDL_Rect dstrect;

	SDL_Surface * surface2;
	SDL_Texture * texture2;
	SDL_Rect dstrect2;

private:
	static InGameUi* s_pInstance;
};

typedef InGameUi TheInGameUi;