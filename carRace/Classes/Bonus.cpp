#include "Bonus.h"
#include "Definition.h"

USING_NS_CC;

CBonus::CBonus()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}


CBonus::~CBonus()
{
}

void CBonus::SpawnBonus(cocos2d::Layer *layer)
{
	auto Gasoline = Sprite::create("benzin.png");
	auto GasolineBody = PhysicsBody::createBox(Gasoline->getContentSize());

	auto random = CCRANDOM_0_1();

	if (random < LOWER_SCREEN_PIPE_THRESHOLD)
	{
		random = float(LOWER_SCREEN_PIPE_THRESHOLD);
	}
	else if (random > UPPER_SCREEN_PIPE_THRESHOLD)
	{
		random = float(UPPER_SCREEN_PIPE_THRESHOLD);
	}

	auto topPipePosition = random * visibleSize.width;
	GasolineBody->setDynamic(false);
	GasolineBody->setContactTestBitmask(true);
	GasolineBody->setContactTestBitmask(BONUS_CONTACT_BITMASK);
	GasolineBody->setCollisionBitmask(BONUS_CONTACT_BITMASK);

	Gasoline->setPosition(topPipePosition + origin.x, visibleSize.height - 20);
	Gasoline->setPhysicsBody(GasolineBody);

	layer->addChild(Gasoline);

	auto topPipeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(0, -visibleSize.width * 2));
	Gasoline->runAction(topPipeAction);

}

