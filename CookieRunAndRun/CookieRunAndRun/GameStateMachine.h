#pragma once
#include "GameState.h"
#include"MenuState.h"
#include"PlayState.h"
class GameStateMachine {
public:
	static GameStateMachine* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new GameStateMachine();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void firstState();
	void changeState(GameState* pState);
	void pushState(GameState *pState);
	void popState();
	virtual void update();
	virtual void render();

protected:
	std::vector<GameState*> m_gameStates;

private:
	static GameStateMachine* s_pInstance;
	GameState* m_currentState;
	GameState* m_prevState;
};

typedef GameStateMachine TheGameStateMachine;