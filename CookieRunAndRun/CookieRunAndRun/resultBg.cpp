#include"resultBg.h"
ResultBg::ResultBg(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
}
void ResultBg::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void ResultBg::update()	//�������� ����� �ƴ�
{
	SDLGameObject::update();
}
void ResultBg::clean()
{
}