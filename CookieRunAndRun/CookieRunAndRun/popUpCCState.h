#pragma once
#include"GameState.h"
#include"mainMenu.h"
#include<vector>
class PopupCCState : public GameState
{
public:
	static PopupCCState* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new PopupCCState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }
	std::vector<GameObject*> m_obj;
	std::vector<GameObject*> m_cookie;
	bool popupCCState = false;

	static void select();
	static void selectBasic();
	static void selectCherry();
	static void selectZombie();

	bool selectCookie = false;	//최종선택
		//팝업내에서 선택
		bool selectBasicC = false;
		bool selectCherryC = false;
		bool selectZombieC = false;
private:
	static const std::string s_menuID;
	static PopupCCState* s_pInstance;
};