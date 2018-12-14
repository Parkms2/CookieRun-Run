#pragma once
#include"TextureManager.h"
#include<SDL_image.h>
#include <algorithm>

class Blur {
public:
	static Blur* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Blur();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void gaussBlur_4(SDL_Surface* image, double r);
	void boxBlur_4(SDL_Surface* image, SDL_Surface* image2, int w, int h, int r);
	void boxBlurH_4(SDL_Surface* image, SDL_Surface* image2, int w, int h, int r);
	void boxBlurT_4(SDL_Surface* image, SDL_Surface* image2, int w, int h, int r);
	int* boxesForGauss(double sigma, int n);
	void setColor(SDL_Surface *image, int i, Uint8 r, Uint8 g, Uint8 b);
private:
	static Blur* s_pInstance;
};

typedef Blur TheBlur;