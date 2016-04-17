#pragma once
#include "cocos2d.h"

class CBonus
{
public:
	CBonus();
	~CBonus();
	void SpawnBonus(cocos2d::Layer *layer);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *m_slowDriver;
};

