#pragma warning(disable : 4996)
#include"inGameUi.h"
#include"UiBg.h"
#include"button.h"
#include"Game.h"
#include"popupPauseState.h"
InGameUi* InGameUi::s_pInstance = 0;

void InGameUi::initInGameUi() {
	m_UI.push_back(new MenuButton(new LoaderParams(1200, 10, 55, 55, "pauseBtton"), pauseBtton));
	m_UI.push_back(new UiBg(new LoaderParams(239, 50, 802, 54, "hpBarBg")));
	m_UI.push_back(new UiBg(new LoaderParams(291, 62, 743, 30, "hpBar")));
	m_UI.push_back(new UiBg(new LoaderParams(1023, 54, 23, 45, "removeHp")));


	font = TTF_OpenFont("assets/font/RixToyStory.ttf", 25);
	color = { 255, 255, 255 };
	wchar_t unicode[100] = L"���� ����";
	surface = TTF_RenderUNICODE_Solid(font, (Uint16*)unicode, color);
	texture = SDL_CreateTextureFromSurface(TheGame::Instance()->getRenderer(), surface);
	SDL_RenderCopy(TheGame::Instance()->getRenderer(), texture, NULL, NULL);
	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	dstrect = { 1190, 80, texW, texH };

}
void InGameUi::draw()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_UI.size(); i++) {
		m_UI[i]->draw();
	}
	if (!PopupPauseState::Instance()->stopUpdate) {	//�Ͻ������� ����
		SDL_RenderCopy(TheGame::Instance()->getRenderer(), texture, NULL, &dstrect);
		SDL_RenderCopy(TheGame::Instance()->getRenderer(), texture2, NULL, &dstrect2);
	}
}
void InGameUi::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_UI.size(); i++) {
		m_UI[i]->update();
	}
	if (!PopupPauseState::Instance()->stopUpdate) {	//�Ͻ������� ����
		char s1[100];
		int num1 = PlayState::Instance()->score;
		sprintf(s1, "%d", num1);
		surface2 = TTF_RenderText_Solid(font, (char*)s1, color);
		texture2 = SDL_CreateTextureFromSurface(TheGame::Instance()->getRenderer(), surface2);
		SDL_RenderCopy(TheGame::Instance()->getRenderer(), texture2, NULL, NULL);
		int texW2 = 0;
		int texH2 = 0;
		SDL_QueryTexture(texture2, NULL, NULL, &texW2, &texH2);
		dstrect2 = { 1190, 110, texW2, texH2 };
	}
}
void InGameUi::clean() {
	m_UI.clear();
}
void InGameUi::pauseBtton() {
	TheGame::Instance()->getStateMachine()->PopupState(PopupPauseState::Instance());
}