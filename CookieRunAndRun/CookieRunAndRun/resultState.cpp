#pragma warning(disable : 4996)
#include"resultState.h"
#include"Game.h"
#include"button.h"
#include"playerAction.h"
#include"resultBg.h"
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
	SDL_RenderCopy(TheGame::Instance()->getRenderer(), texture, NULL, &dstrect);
	SDL_RenderCopy(TheGame::Instance()->getRenderer(), texture2, NULL, &dstrect2);
}

bool ResultState::onEnter()
{
	PlayState::Instance()->hp = 0;

	resultTime = true;
	TheAssetLoad::Instance()->assetResultState(TheGame::Instance()->getRenderer());
	m_obj.push_back(new ResultBg(new LoaderParams(187, 139, 907, 415, "result3")));
	m_obj.push_back(new ResultBg(new LoaderParams(0, 0, 1280, 720, "result1")));
	m_obj.push_back(new ResultBg(new LoaderParams(494, 62, 292, 75, "result2")));
	m_obj.push_back(new MenuButton(new LoaderParams(1048, 465, 93, 115, "result4"), goFirst));


	font = TTF_OpenFont("assets/font/RixToyStory.ttf", 50);
	color = { 255, 255, 255 };
	myscore = PlayState::Instance()->score;
	char s1[100];
	sprintf(s1, "%d", myscore);
	surface = TTF_RenderText_Solid(font, (char*)s1, color);
	texture = SDL_CreateTextureFromSurface(TheGame::Instance()->getRenderer(), surface);
	SDL_RenderCopy(TheGame::Instance()->getRenderer(), texture, NULL, NULL);
	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	dstrect = { 400, 300, texW, texH };

	wchar_t unicode[100] = L"최종 스코어";
	surface2 = TTF_RenderUNICODE_Solid(font, (Uint16*)unicode, color);
	texture2 = SDL_CreateTextureFromSurface(TheGame::Instance()->getRenderer(), surface2);
	SDL_RenderCopy(TheGame::Instance()->getRenderer(), texture2, NULL, NULL);
	int texW2 = 0;
	int texH2 = 0;
	SDL_QueryTexture(texture2, NULL, NULL, &texW2, &texH2);
	dstrect2 = { 400, 200, texW2, texH2 };
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

void ResultState::goFirst() {
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
	ResultState::Instance()->onExit();
}