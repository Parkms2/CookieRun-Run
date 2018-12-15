#pragma once
#include<vector>
#include "Player.h"
class PlayerAction {
public:
	PlayerAction() {}
	static PlayerAction* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new PlayerAction();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void initAction();
	void draw();
	void update();
	void clean();
	std::vector<GameObject*> m_action;
	int getPosition();
private:
	static PlayerAction* s_pInstance;
};

typedef PlayerAction ThePlayerAction;