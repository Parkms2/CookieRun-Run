#pragma once
#include"SDL.h"
#include<map>
using namespace std;

class TextureManager {
private:
	TextureManager() {};
	static TextureManager* s_pInstance;
	map < string, SDL_Texture* > m_textureMap;
public:

	~TextureManager() {};

	bool load(string fileName, string id, SDL_Renderer* pRenderer);
	bool backLoad(string fileName, string id, SDL_Renderer* pRenderer);
	bool screenShotLoad(string id, SDL_Surface* screenShot, SDL_Renderer* pRenderer);
	bool blurImageDraw(SDL_Surface *image, int blur_extent);	//이미지를 블러처리 해줌      (블러처리할 이미지, 블러 강도)
	void draw(string id, int x, int y, int width, int height, int current, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	static TextureManager* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
};

typedef TextureManager TheTextureManager;