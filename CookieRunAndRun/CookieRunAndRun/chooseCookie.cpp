#include"chooseCookie.h"
#include"playerAction.h"
//쿠키계속추가

chooseCookie* chooseCookie::s_pInstance = 0;

void chooseCookie::initAction(string run, string jump, string slide) {
	ThePlayerAction::Instance()->initAction(run, jump, slide);
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