#include"BackgroundControl.h"
BackgroundControl* BackgroundControl::s_pInstance = 0;

void BackgroundControl::initBackground() {
	m_back.push_back(new Background(new LoaderParams(0, 0, 1280, 640, "stage1Back")));
	m_back.push_back(new Background(new LoaderParams(1280, 0, 1280, 640, "stage1Back")));
}
void BackgroundControl::draw()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_back.size(); i++) {
		m_back[i]->draw();
	}
}
void BackgroundControl::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_back.size(); i++) {
		m_back[i]->update();
	}
}
void BackgroundControl::clean() {

}