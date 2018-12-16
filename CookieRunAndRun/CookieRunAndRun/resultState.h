#pragma once
#include"GameState.h"
#include"mainMenu.h"
#include<vector>
class ResultState : public GameState
{
public:
	static ResultState* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new ResultState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	static void goFirst();
	virtual std::string getStateID() const { return s_menuID; }
	std::vector<GameObject*> m_obj;
	bool resultTime = false;
private:
	static const std::string s_menuID;
	static ResultState* s_pInstance;

};