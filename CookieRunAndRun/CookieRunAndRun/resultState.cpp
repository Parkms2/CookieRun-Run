#include"resultState.h"
#include"Game.h"
#include"button.h"
#include"playerAction.h"
#include"resultBg.h"
#include"PlayState.h"
const std::string ResultState::s_menuID = "RESULTSTATE";
ResultState* ResultState::s_pInstance = 0;

void ResultState::update() {
	for (int i = 0; i < m_obj.size(); i++) {
		m_obj[i]->update();
	}
}

void ResultState::render() {
	for (int i = 0; i < m_obj.size(); i++) {
		m_obj[i]->draw();
	}
}

bool ResultState::onEnter()
{
	PlayState::Instance()->hp = 0;
	resultTime = true;
	TheAssetLoad::Instance()->assetResultState(TheGame::Instance()->getRenderer());
	m_obj.push_back(new ResultBg(new LoaderParams(0, 0, 1280, 720, "result1")));
	m_obj.push_back(new ResultBg(new LoaderParams(494, 62, 292, 75, "result2")));
	m_obj.push_back(new ResultBg(new LoaderParams(187, 139, 907, 415, "result3")));
	std::cout << "entering PopupPauseState\n";
	return true;
}
bool ResultState::onExit()
{
	m_obj.clear();
	resultTime = false;
	//m_obj.erase(m_obj.begin() + 2);
	return true;
}