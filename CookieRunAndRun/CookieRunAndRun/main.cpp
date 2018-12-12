#include"game.h"

Game* g_game = 0;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int DELAY_TIME = 1000.0f / FPS;
	Uint32 frameStart, frameTime;
	int frameTick = 0; 
	int prevFrameTick = 0;
	std::cout << "game init attempt...\n";
	if (TheGame::Instance()->init("��! ��Ű��!", 100, 100,1280, 720, false)) {
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
			//if (frameStart - prevFrameTick >= 1000) {	//������ üŷ
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
	std::cout << "game closing...\n";
	TheGame::Instance()->clean();
	return 0;
}