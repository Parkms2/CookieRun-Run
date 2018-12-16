#include"chooseCookie.h"
#include"playerAction.h"
#include"popUpCCState.h"

//쿠키계속추가

chooseCookie* chooseCookie::s_pInstance = 0;

void chooseCookie::initAction() {
	if (PopupCCState::Instance()->selectBasicC) {
		ThePlayerAction::Instance()->initAction("basicCookieRun", "basicCookieJump1", "basicCookieSlide");
	}
	else if (PopupCCState::Instance()->selectCherryC) {
		ThePlayerAction::Instance()->initAction("cherryCookieRun", "cherryCookieJump", "cherryCookieSlide");
	}
	else if (PopupCCState::Instance()->selectZombieC) {
		ThePlayerAction::Instance()->initAction("zombieCookieRun", "zombieCookieJump", "zombieCookieSlide");
	}

}
void chooseCookie::draw() {
	ThePlayerAction::Instance()->draw();
}
void chooseCookie::update() {
	ThePlayerAction::Instance()->update();
}
int chooseCookie::getAction() {
	return ThePlayerAction::Instance()->getAction();
}
void chooseCookie::clean() {
	ThePlayerAction::Instance()->clean();
}