#pragma once
#include"SDL.h"
#include<iostream>
#include"TextureManager.h"
#include"LoaderParams.h"

class GameObject {
public:
	GameObject() {}
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};
