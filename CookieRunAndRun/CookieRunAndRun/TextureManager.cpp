#include"TextureManager.h"
#include<SDL_image.h>
TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(string fileName, string id, SDL_Renderer* pRenderer) {
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0) return false;
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	if (pTexture != 0) {
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}
bool TextureManager::backLoad(string fileName, string id, SDL_Renderer* pRenderer) {
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0) return false;
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	SDL_SetTextureAlphaMod(pTexture, 80);			//반투명 정도 0~255
	SDL_SetTextureBlendMode(pTexture, SDL_BLENDMODE_BLEND);
	if (pTexture != 0) {
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}
bool TextureManager::screenShotLoad(string id, SDL_Surface* screenShot, SDL_Renderer* pRenderer) {
	if (screenShot == 0) return false;
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, screenShot);
	SDL_FreeSurface(screenShot);
	if (pTexture != 0) {
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}
bool TextureManager::blurImageDraw(SDL_Surface *image, int blur_extent) {
	if (image == 0) return false;
	for (int y = 0; y < image->h; y++) {
		for (int x = 0; x < (image->pitch / 4); x++) {
			Uint32 color = ((Uint32*)image->pixels)[(y * (image->pitch / 4)) + x];

			Uint8 r = 0, g = 0, b = 0, a = 0;
			SDL_GetRGBA(color, image->format, &r, &g, &b, &a);

			Uint32 rb = 0, gb = 0, bb = 0, ab = 0;

			for (int yo = -blur_extent; yo <= blur_extent; yo++) {
				for (int xo = -blur_extent; xo <= blur_extent; xo++) {
					if (y + yo >= 0 && x + xo >= 0 && y + yo < image->h && x + xo < (image->pitch / 4)) {
						Uint32 colOth = ((Uint32*)image->pixels)[((y + yo) * (image->pitch / 4)) + (x + xo)];
						Uint8 ro = 0, go = 0, bo = 0, ao = 0;
						SDL_GetRGBA(colOth, image->format, &ro, &go, &bo, &ao);
						rb += ro;
						gb += go;
						bb += bo;
						ab += ao;
					}
				}
			}
			r = (Uint8)(rb / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			g = (Uint8)(gb / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			b = (Uint8)(bb / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			a = (Uint8)(ab / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			color = (r) | (g << 8) | (b << 16) | (a <<24); 
			((Uint32*)image->pixels)[(y * (image->pitch / 4)) + x] = color;
		}
	}
	return true;
}
void TextureManager::draw(string id, int x, int y, int width, int height, int current, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;	//소스파일정보
	SDL_Rect destRect;	//출력정보
	srcRect.x = width * current;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
void TextureManager::drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
