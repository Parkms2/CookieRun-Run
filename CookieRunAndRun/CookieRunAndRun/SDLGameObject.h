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
	virtual void clean();
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	int m_width;
	int m_height;
	int m_currentFrame;
protected:
	int m_currentRow;
	std::string m_textureID;
};
