#pragma once
#include"GameObject.h"
#include "Vector2D.h"


class SDLGameObject : public GameObject {
public:
	SDLGameObject() {}
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void draw2();
	virtual void update();
	virtual void cookieUpdate();//행동별 이미지 변경?
	virtual void clean();
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};
