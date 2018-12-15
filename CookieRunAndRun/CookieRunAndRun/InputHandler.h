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
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear 
	bool isKeyDown(SDL_Scancode key);

	Vector2D* m_mousePosition;
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();
	void onMouseMove(SDL_Event event);
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
	bool slide = false;
	bool doubleJump = false;
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
};


typedef InputHandler TheInputHandler;
