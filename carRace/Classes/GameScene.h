#pragma once
#include "cocos2d.h"
#include "SlowDriver.h"
#include "PlayerCar.h"

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
    CREATE_FUNC(GameScene);
private:
	void SetPhysicsWorld(cocos2d::PhysicsWorld *world)
	{
		sceneWorld = world;
	};
	void SpawnPipe(float dt);

	void onTouchLeftButton(cocos2d::Ref *sender);
	void onTouchRightButton(cocos2d::Ref *sender);
	cocos2d::PhysicsWorld *sceneWorld;
	SlowDriver slowDr;
	PlayerCar *playerCar;
};