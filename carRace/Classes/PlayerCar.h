#pragma once
#include "cocos2d.h"
#include <string>

class PlayerCar
{
public:
	PlayerCar(cocos2d::Layer *layer);
	void ControlCarWithTouch(float pos);
	float m_gasoline;
	cocos2d::Sprite *m_playerSprite;
private:
	cocos2d::Size m_visibleSize;
	cocos2d::Vec2 m_origin;
	
};

