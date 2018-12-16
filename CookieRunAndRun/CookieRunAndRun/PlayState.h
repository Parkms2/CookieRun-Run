#pragma once
#include "GameState.h"
class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	static PlayState* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	int hp = 744;
	int score = 0;
private:
	static const std::string s_playID;
	static PlayState* s_pInstance;

	int nextTime = 0;
	int timeLeft = 400;
};