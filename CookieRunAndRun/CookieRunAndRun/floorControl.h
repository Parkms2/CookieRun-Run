#pragma once
#include<vector>
#include"SDLGameObject.h"
#include"floor.h"
#include"TextureManager.h"

class FloorControl{
public:
	FloorControl() {}
	static FloorControl* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new FloorControl();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void initFloor();
	void draw();
	void update();
	void clean();
	std::vector<GameObject*> m_floor;
private:
	static FloorControl* s_pInstance;
};

typedef FloorControl TheFloorControl;