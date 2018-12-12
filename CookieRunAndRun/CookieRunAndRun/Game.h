#pragma once

#include"SDL.h"
#include<vector>
#include"TextureManager.h"
#include"GameObject.h"
#include"InputHandler.h"
#include"assetLoad.h"

#include"GameStateMachine.h"
#include"PlayState.h"
class Game {
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	static Game* Instance() {
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	GameStateMachine* m_pGameStateMachine;
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	static Game* s_pInstance;
	bool m_bRunning;
	int m_currentFrame;

	bool NowStart = true;
};
typedef Game TheGame;