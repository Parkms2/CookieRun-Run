#pragma once
#include "SDL.h"
#include"Vector2D.h"
#include"Game.h"
class InputHandler {
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	void onKeyDown();
	void onKeyUp();


	const Uint8* m_keystates;
	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};
	std::vector<bool> m_mouseButtonStates;
	bool jump = false;

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
};


typedef InputHandler TheInputHandler;
