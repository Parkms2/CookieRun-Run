#include "game.h"
#include<SDL_image.h>

Game* Game::s_pInstance = 0;

bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			m_bRunning = true;
			SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

			TheAssetLoad::Instance()->assetLoads(m_pRenderer);	//모든 에셋 소스를 로드시켜줌
			ThePlayerAction::Instance()->initAction();
			TheFloorControl::Instance()->initFloor();
			TheBackgroundControl::Instance()->initBackground();
		}
		else return false;
	}
	return true;
}
void Game::render() {
	SDL_RenderClear(m_pRenderer);
	TheBackgroundControl::Instance()->draw();
	TheFloorControl::Instance()->draw();
	ThePlayerAction::Instance()->draw();
	SDL_RenderPresent(m_pRenderer);
}
void Game::update() {
	TheBackgroundControl::Instance()->update();
	TheFloorControl::Instance()->update();
	ThePlayerAction::Instance()->update();
}	

void Game::handleEvents() {
	TheInputHandler::Instance()->update();
}
void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
	//TheInputHandler::Instance()->clean();
}
void Game::quit() {
	m_bRunning = false;
}