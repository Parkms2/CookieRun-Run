#pragma once
#include<vector>
#include"background.h"


class BackgroundControl {
public:
	BackgroundControl() {}
	static BackgroundControl* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new BackgroundControl();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void initBackground();
	void draw();
	void update();
	void clean();
	std::vector<GameObject*> m_back;
private:
	static BackgroundControl* s_pInstance;
};

typedef BackgroundControl TheBackgroundControl;
