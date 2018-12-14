#pragma once
#include"GameState.h"
#include"mainMenu.h"
#include<vector>
class PopupPauseState : public GameState
{
public:
	static PopupPauseState* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new PopupPauseState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }
	bool stopUpdate = false;
	std::vector<GameObject*> m_obj;
private:
	static const std::string s_menuID;
	static PopupPauseState* s_pInstance;
};