#include "PlayerCar.h"
#include "Definition.h"

USING_NS_CC;

PlayerCar::PlayerCar(cocos2d::Layer *layer)
{
	m_visibleSize = Director::getInstance()->getVisibleSize();
	m_origin = Director::getInstance()->getVisibleOrigin();

	auto pinfo = AutoPolygon::generatePolygon("myCar.png");
	m_playerCar = Sprite::create(pinfo);
	m_playerCar->setPosition(Point(m_visibleSize.width / 2 + m_origin.x, 200));

	auto playerBody = PhysicsBody::createCircle(m_playerCar->getContentSize().width / 2);

	playerBody->setCollisionBitmask(BIRD_COLLISION_BITMASK);
	playerBody->setContactTestBitmask(true);

	//m_playerCar->setPhysicsBody(playerBody);

	layer->addChild(m_playerCar, 100);
}

void PlayerCar::ControlCar()
{
	if (leftMove)
	{
		m_playerCar->setPositionX(m_playerCar->getPositionX() - 10);
	}
	else if (rightMove)
	{
		m_playerCar->setPositionX(m_playerCar->getPositionX() + 10);
	}
}

