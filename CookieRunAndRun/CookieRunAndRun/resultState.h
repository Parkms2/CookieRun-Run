#pragma once
#include"GameState.h"
#include"mainMenu.h"
#include<vector>
#include<SDL_ttf.h>
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
	int myscore;

public:
	TTF_Font * font;
	SDL_Color color;
	SDL_Surface * surface;
	SDL_Texture * texture;
	SDL_Rect dstrect;
	SDL_Surface * surface2;
	SDL_Texture * texture2;
	SDL_Rect dstrect2;
private:
	static const std::string s_menuID;
	static ResultState* s_pInstance;

};