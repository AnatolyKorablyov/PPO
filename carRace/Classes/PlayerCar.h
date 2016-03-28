#pragma once
#include "cocos2d.h"
#include <string>

class PlayerCar
{
public:
	PlayerCar(cocos2d::Layer *layer);
	void ControlCar();
	bool leftMove = false;
	bool rightMove = false;
private:
	cocos2d::Size m_visibleSize;
	cocos2d::Vec2 m_origin;
	cocos2d::Sprite *m_playerCar;
};

