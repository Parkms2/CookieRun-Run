#include"floorControl.h"
FloorControl* FloorControl::s_pInstance = 0;

void FloorControl::initFloor() {
	m_floor.push_back(new Floor(new LoaderParams(0, 608, 1368, 112, "level1Floor")));
	m_floor.push_back(new Floor(new LoaderParams(1368, 608, 1368, 112, "level1Floor")));
}
void FloorControl::draw()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_floor.size(); i++) {
		m_floor[i]->draw();
	}
}
void FloorControl::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_floor.size(); i++) {
	m_floor[i]->update();
	}
}
void FloorControl::clean(){

}