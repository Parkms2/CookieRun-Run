#include"popUpCCState.h"
#include"popupCCBg.h"
#include"button.h"

const std::string PopupCCState::s_menuID = "PopupCCState";
PopupCCState* PopupCCState::s_pInstance = 0;

void PopupCCState::update() {
	for (int i = 0; i < m_obj.size(); i++) {
		m_obj[i]->update();
	}
	for (int i = 0; i < m_cookie.size(); i++) {
		if (i == 0)m_cookie[i]->update();
	}
}

void PopupCCState::render() {
	for (int i = 0; i < m_obj.size(); i++) {
		m_obj[i]->draw();
	}
	for (int i = 0; i < m_cookie.size(); i++) {
		m_cookie[i]->draw();
	}
}

bool PopupCCState::onEnter()
{
	m_cookie.clear();
	popupCCState = true;
	selectCookie = false;
	m_obj.push_back(new popupCCBg(new LoaderParams(0, 0, 1280, 720, "PopupChangeCookie")));
	m_obj.push_back(new MenuButton(new LoaderParams(712, 157, 108, 108, "selectBasicCookie"), selectBasic));
	m_obj.push_back(new MenuButton(new LoaderParams(840, 157, 108, 108, "selectCherry1Cookie"), selectCherry));
	m_obj.push_back(new MenuButton(new LoaderParams(968, 157, 108, 108, "selectZombieCookie"), selectZombie));
	m_obj.push_back(new MenuButton(new LoaderParams(199, 569, 429, 100, "chooseButton"), select));
	m_obj.push_back(new popupCCBg(new LoaderParams(-300, -300, 113, 113, "nowCookie")));

	if (selectBasicC) selectBasic();
	else if (selectCherryC) selectCherry();
	else if (selectZombieC) selectZombie();
	std::cout << "entering PopupCCState\n";
	return true;
}
bool PopupCCState::onExit()
{
	m_obj.clear();
	popupCCState = false;

	std::cout << "exiting PopupCCState\n";
	return true;
}
void PopupCCState::select() {
	PopupCCState::Instance()->selectCookie = true;
	dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.setX(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.getX() + 213);
	dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.setY(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_cookie[0])->m_position.getY() - 40);
	PopupCCState::Instance()->onExit();
}
void PopupCCState::selectBasic() {
	PopupCCState::Instance()->selectBasicC = true;
	PopupCCState::Instance()->selectCherryC = false;
	PopupCCState::Instance()->selectZombieC = false;
	PopupCCState::Instance()->m_cookie.clear();
	PopupCCState::Instance()->m_cookie.push_back(new popupCCBg(new LoaderParams(317, 310, 186, 199, "lobbyBasic1")));
	PopupCCState::Instance()->m_cookie.push_back(new popupCCBg(new LoaderParams(-300, -300, 79, 39, "lobbyBasic2")));
	if (PopupCCState::Instance()->popupCCState) {
		dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[5])->m_position.setX(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[1])->m_position.getX() - 2);
		dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[5])->m_position.setY(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[1])->m_position.getY() - 3);
	}
}
void PopupCCState::selectCherry() {
	PopupCCState::Instance()->selectBasicC = false;
	PopupCCState::Instance()->selectCherryC = true;
	PopupCCState::Instance()->selectZombieC = false;
	PopupCCState::Instance()->m_cookie.clear();
	PopupCCState::Instance()->m_cookie.push_back(new popupCCBg(new LoaderParams(317, 310, 198, 217, "lobbyCherry1")));
	PopupCCState::Instance()->m_cookie.push_back(new popupCCBg(new LoaderParams(-300, -300, 74, 36, "lobbyCherry2")));
	if (PopupCCState::Instance()->popupCCState) {
		dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[5])->m_position.setX(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[2])->m_position.getX() - 2);
		dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[5])->m_position.setY(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[2])->m_position.getY() - 3);
	}
}
void PopupCCState::selectZombie() {
	PopupCCState::Instance()->selectBasicC = false;
	PopupCCState::Instance()->selectCherryC = false;
	PopupCCState::Instance()->selectZombieC = true;
	PopupCCState::Instance()->m_cookie.clear();
	PopupCCState::Instance()->m_cookie.push_back(new popupCCBg(new LoaderParams(302, 330, 188, 191, "lobbyZombie1")));
	PopupCCState::Instance()->m_cookie.push_back(new popupCCBg(new LoaderParams(-300, -300, 93, 49, "lobbyZombie2")));
	if (PopupCCState::Instance()->popupCCState) {
		dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[5])->m_position.setX(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[3])->m_position.getX() - 2);
		dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[5])->m_position.setY(dynamic_cast<SDLGameObject*>(PopupCCState::Instance()->m_obj[3])->m_position.getY() - 3);
	}
}