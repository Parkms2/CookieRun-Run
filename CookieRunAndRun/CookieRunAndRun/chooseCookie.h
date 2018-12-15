#pragma once
#include"Player.h"

class chooseCookie {
public:
	static chooseCookie* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new chooseCookie();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void initAction(string a, string b, string slide);
	//string run;
	//string jump;
	//string slide;

	void draw();
	void update();
	void clean();
	int getAction();
private:
	static chooseCookie* s_pInstance;
};

typedef chooseCookie ThechooseCookie;