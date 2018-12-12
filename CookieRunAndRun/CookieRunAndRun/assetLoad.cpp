#include"assetLoad.h"

assetLoad* assetLoad::s_pInstance = 0;

bool assetLoad::assetLoadsPlay(SDL_Renderer* m_pRenderer) {
	//�⺻ ��Ű
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/run.png", "basicCookieRun", m_pRenderer)) return false;
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/jump1-1.png", "basicCookieJump1", m_pRenderer)) return false;	
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/jump.png", "basicCookieJump2", m_pRenderer)) return false;
	if (!TheTextureManager::Instance()->load("assets/characters/basicsCookie/slide.png", "basicCookieSlide", m_pRenderer)) return false;

	//xx ��Ű

	//yy ��Ű

	//�ٴ� ��������Ʈ
	if (!TheTextureManager::Instance()->load("assets/floors/level1Floor.png", "level1Floor", m_pRenderer)) return false;			//�����ϳ���.. ������ �Ѱ��� �̿��ϴ� ��� ã�ƺ���

	//��׶���
	if (!TheTextureManager::Instance()->backLoad("assets/background/stage1Back.jpg", "stage1Back", m_pRenderer)) return false;		//���� �ϳ���..
	
	return true;
}
bool assetLoad::assetLoadsMenu(SDL_Renderer* m_pRenderer) {
	//�ε�ȭ��
	if (!TheTextureManager::Instance()->load("assets/mainmenu/roading.jpg", "roading", m_pRenderer)) return false;				//���ӽ���� �ε�ȭ�� (����� �ʹ� ���ɸ��� �ð����ȸ�)
	if (!TheTextureManager::Instance()->load("assets/mainmenu/roadingBar.png", "roadingBar", m_pRenderer)) return false;

	//���� �޴�
	if (!TheTextureManager::Instance()->load("assets/mainmenu/mainLobby_bg.png", "mainLobby_bg", m_pRenderer)) return false;	//���θ޴��� �κ� ��׶��� ȭ��
	if (!TheTextureManager::Instance()->load("assets/mainmenu/changeChar_bg.png", "changeChar_bg", m_pRenderer)) return false;	//ĳ���� ��üȭ���� ��׶��� ȭ��

	return true;
}