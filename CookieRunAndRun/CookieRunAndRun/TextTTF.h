#include<SDL_ttf.h>



class TextTTF {
public:
	TextTTF();
	TTF_Font * font;
	SDL_Color color;
	SDL_Surface * surface;
	SDL_Texture * texture;
	SDL_Rect dstrect;
	int texW = 0;
	int texH = 0;
	int size;
	void load(int _size, SDL_Renderer* pRenderer);
	void load2(int _size, SDL_Renderer* pRenderer);
	void draw();
	void clean();
	SDL_Renderer* Renderer;
};