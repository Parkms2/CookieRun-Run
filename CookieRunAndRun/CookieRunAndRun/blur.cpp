#include"blur.h"
#include <algorithm>
Blur* Blur::s_pInstance = 0;

void Blur::gaussBlur_4(SDL_Surface* image, double r) {
	SDL_Surface* image2 = image;
	int w = image->w;
	int h = image->h;
	int* bxs = boxesForGauss(r, 3);
	boxBlur_4(image, image2, w, h, (bxs[0] - 1) / 2);
	boxBlur_4(image2, image, w, h, (bxs[1] - 1) / 2);
	boxBlur_4(image, image2, w, h, (bxs[2] - 1) / 2);
	//image = image2;
}
void Blur::boxBlur_4(SDL_Surface* image, SDL_Surface* image2,int w, int h, int r) {
	image2 = image;
	boxBlurH_4(image2, image, w, h, r);
	boxBlurT_4(image, image2, w, h, r);
}
void Blur::boxBlurH_4(SDL_Surface* image, SDL_Surface* image2, int w, int h, int r) {
	double iarr = (double)1 / (r + r + 1);
	Uint32* scl = (Uint32*)image->pixels;
	Uint32* tcl = (Uint32*)image2->pixels;
	for (int i = 0; i < h; i++) {
		Uint8 ra = 0, ga = 0, ba= 0, aa = 0;
		Uint8 rb = 0, gb = 0, bb = 0, ab = 0;

		int ti = i * w, li = ti, ri = ti + r;
		SDL_GetRGBA(scl[ti], image->format, &ra, &ga, &ba, &aa);
		SDL_GetRGBA(scl[ti + w - 1], image->format, &rb, &gb, &bb, &ab);

		unsigned currennt_r = ra * (r + 1);
		unsigned currennt_g = ga * (r + 1);
		unsigned currennt_b = ba * (r + 1);

		for (int j = 0; j < r; j++) {
			Uint8 rc = 0, gc = 0, bc = 0, ac = 0;
			SDL_GetRGBA(scl[ti + j], image->format, &rc, &gc, &bc, &ac);
			currennt_r += rc;
			currennt_g += gc;
			currennt_b += bc;
		}
		for (int j = 0; j <= r; j++) {
			Uint8 rc = 0, gc = 0, bc = 0, ac = 0;
			SDL_GetRGBA(scl[ri++], image->format, &rc, &gc, &bc, &ac);
			currennt_r += (rc - ra);
			currennt_g += (gc - ga);
			currennt_b += (bc - ba);
			setColor(image2, ti++, currennt_r*iarr, currennt_g*iarr, currennt_b*iarr);
		}
		for (int j = r + 1; j < w - r; j++) {
			Uint8 rc = 0, gc = 0, bc = 0, ac = 0;
			SDL_GetRGBA(scl[ri++], image->format, &rc, &gc, &bc, &ac);
			Uint8 rd = 0, gd = 0, bd = 0, ad = 0;
			SDL_GetRGBA(scl[li++], image->format, &rd, &gd, &bd, &ad);
			currennt_r += (rc - rd);
			currennt_g += (gc - gd);
			currennt_b += (bc - bd);
			setColor(image2, ti++, currennt_r*iarr, currennt_g*iarr, currennt_b*iarr);
		}
		for (int j = w - r; j < w; j++) {
			Uint8 rc = 0, gc = 0, bc = 0, ac = 0;
			SDL_GetRGBA(scl[li++], image->format, &rc, &gc, &bc, &ac);
			currennt_r += (rb - rc);
			currennt_g += (gb - gc);
			currennt_b += (bb - bc);
			setColor(image2, ti++, currennt_r*iarr, currennt_g*iarr, currennt_b*iarr);
		}
	}
}
void Blur::boxBlurT_4(SDL_Surface* image, SDL_Surface* image2, int w, int h, int r) {
	Uint32* scl = (Uint32*)image->pixels;
	Uint32* tcl = (Uint32*)image2->pixels;
	double iarr = (double)1 / (r + r + 1);
	for (int i = 0; i < w; i++) {
		Uint8 ra = 0, ga = 0, ba = 0, aa = 0;
		Uint8 rb = 0, gb = 0, bb = 0, ab = 0;
		int ti = i, li = ti, ri = ti + r * w;
		SDL_GetRGBA(scl[ti], image->format, &ra, &ga, &ba, &aa);
		SDL_GetRGBA(scl[ti + w * (h - 1)], image->format, &rb, &gb, &bb, &ab);

		unsigned currennt_r = ra * (r + 1);
		unsigned currennt_g = ga * (r + 1);
		unsigned currennt_b = ba * (r + 1);

		for (int j = 0; j < r; j++) {
			Uint8 rc = 0, gc = 0, bc = 0, ac = 0;
			SDL_GetRGBA(scl[ti + j * w], image->format, &rc, &gc, &bc, &ac);
			currennt_r += rc;
			currennt_g += gc;
			currennt_b += bc;
		}
		for (int j = 0; j <= r; j++) {
			Uint8 rc = 0, gc = 0, bc = 0, ac = 0;
			SDL_GetRGBA(scl[ri], image->format, &rc, &gc, &bc, &ac);
			currennt_r += rc - ra;
			currennt_g += gc - ga;
			currennt_b += bc - ba;
			setColor(image2, ti, currennt_r*iarr, currennt_g*iarr, currennt_b*iarr);
			ri += w;
			ti += w;
		}
		for (int j = r + 1; j < h - r; j++) {
			Uint8 rc = 0, gc = 0, bc = 0, ac = 0;
			SDL_GetRGBA(scl[ri], image->format, &rc, &gc, &bc, &ac);
			Uint8 rd = 0, gd = 0, bd = 0, ad = 0;
			SDL_GetRGBA(scl[li], image->format, &rd, &gd, &bd, &ad);
			currennt_r += (rc - rd);
			currennt_g += (gc - gd);
			currennt_b += (bc - bd);
			setColor(image2, ti, currennt_r*iarr, currennt_g*iarr, currennt_b*iarr);
			li += w;
			ri += w;
			ti += w;
		}
		for (int j = h - r; j < h; j++) {
			Uint8 rc = 0, gc = 0, bc = 0, ac = 0;
			SDL_GetRGBA(scl[li], image->format, &rc, &gc, &bc, &ac);
			currennt_r += (rb - rc);
			currennt_g += (gb - gc);
			currennt_b += (bb - bc);
			setColor(image2, ti, currennt_r*iarr, currennt_g*iarr, currennt_b*iarr);
			li += w;
			ti += w;
		}
	}
}
int* Blur::boxesForGauss(double  sigma, int n) {
		double  wIdeal = sqrt((12 * sigma*sigma / n) + 1);
		int wl = floor(wIdeal);
		if (wl % 2 == 0) wl--;
		int wu = wl + 2;

		double  mIdeal = (12 * sigma*sigma - n * wl*wl - 4 * n*wl - 3 * n) / (-4 * wl - 4);
		int m = round(mIdeal);
		int* sizes = new int[n];
		for (int i = 0; i < n; i++) {
			sizes[i] = (i < m ? wl : wu);
		}
		return sizes;
}
void Blur::setColor(SDL_Surface *image, int i, Uint8 r, Uint8 g, Uint8 b) {
	Uint32 *pixels = (Uint32 *)image->pixels;            // Get the pixels from the Surface
	pixels[i] = SDL_MapRGB(image->format, r, g, b);
}