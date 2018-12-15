#pragma once
#pragma once
#include<vector>
#include"background.h"


class pauseButtonControl {
public:
	pauseButtonControl() {}
	static pauseButtonControl* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new pauseButtonControl();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void initButton();
	void draw();
	void update();
	void clean();
	std::vector<GameObject*> m_obj;
	int count;
	bool finish;
private:
	static pauseButtonControl* s_pInstance;
	static void justText();
	static void s_resume();
	static void s_stop();

};

typedef pauseButtonControl ThepauseButtonControl;
