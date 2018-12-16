#pragma once
#include"GameState.h"
#include"mainMenu.h"

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }
	static MenuState* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new MenuState();
			return s_pInstance;
		}
		return s_pInstance;
	}

	std::vector<GameObject*> main_bg;
	std::vector<GameObject*> m_effect;
	mainMenu* loadingBg;
	mainMenu* loadingBar;

	int effectRender;
	int effectPosition;
private:
	static const std::string s_menuID;
	static MenuState* s_pInstance;
	static void gamestart();
	static void changeCookie();
	static void dnsQKfakdrpa();
	static void recode();

	int nextTime = 0;
	int timeLeft = 300;
};