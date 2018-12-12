#pragma once
#include "GameState.h"
#include"MenuState.h"
#include"PlayState.h"
class GameStateMachine
{
public:
	void firstState();
	void changeState(GameState* pState);
	void pushState(GameState *pState);
	void popState();
	virtual void update();
	virtual void render();

protected:
	std::vector<GameState*> m_gameStates;

private:
	GameState* m_currentState;
	GameState* m_prevState;
};