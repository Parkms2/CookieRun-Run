//#include"TextTTF.h"
//
//
//TextTTF::TextTTF(){
//
//}
//void TextTTF::load(int _size, SDL_Renderer* pRenderer)
//{
//	size = _size;
//
//
//	font = TTF_OpenFont("assets/font/RixToyStory.ttf", size);
//	color = { 255, 255, 255 };
//	wchar_t unicode[100] = L"현재 점수";
//	surface = TTF_RenderUNICODE_Solid(font, (Uint16*)unicode, color);
//	texture = SDL_CreateTextureFromSurface(pRenderer, surface);
//	SDL_RenderCopy(pRenderer, texture, NULL, NULL);
//	texW = 0;
//	texH = 0;
//	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
//	dstrect = { 1190, 80, texW, texH };
//
//
//	Renderer = pRenderer;
//}
//void TextTTF::load2(int _size, SDL_Renderer* pRenderer)
//{
//	size = _size;
//
//
//	font = TTF_OpenFont("assets/font/RixToyStory.ttf", size);
//	color = { 255, 255, 255 };
//
//
//	wchar_t unicode[100] = L"현재 점수";
//	surface = TTF_RenderUNICODE_Solid(font, (Uint16*)unicode, color);
//	texture = SDL_CreateTextureFromSurface(pRenderer, surface);
//	SDL_RenderCopy(pRenderer, texture, NULL, NULL);
//	texW = 0;
//	texH = 0;
//	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
//	dstrect = { 1190, 80, texW, texH };
//
//
//	Renderer = pRenderer;
//}
//
//void TextTTF::draw()
//{
//	SDL_RenderCopy(Renderer, texture, NULL, &dstrect);
//}
//
//void TextTTF::clean()
//{
//	delete Renderer;
//	delete texture;
//	delete msg;
//
//	TTF_CloseFont(font);
//}