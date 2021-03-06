#include"game.h"
#include<ctime>
#include<SDL_ttf.h>
Game* g_game = 0;

int main(int argc, char* argv[])
{
	srand((unsigned int)time(0));
	TTF_Init();
	const int FPS = 60;
	const int DELAY_TIME = 1000.0f / FPS;
	Uint32 frameStart, frameTime;
	int frameTick = 0; 
	int prevFrameTick = 0;
	std::cout << "game init attempt...\n";
	if (TheGame::Instance()->init("와! 쿠키런!", 100, 100,1280, 720, false)) {
		std::cout << "game init success!\n";

		while (TheGame::Instance()->running()) {
			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < DELAY_TIME) {
				SDL_Delay((int)(DELAY_TIME - frameTime));
				//frameTick++;
			}
			//if (frameStart - prevFrameTick >= 1000) {	//프레임 체킹
			//	cout << frameTick << endl;
			//	frameTick = 0;
			//	prevFrameTick = frameStart;
			//}
		}

	}
	else {
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	TTF_Quit();
	std::cout << "game closing...\n";
	TheGame::Instance()->clean();
	return 0;
}