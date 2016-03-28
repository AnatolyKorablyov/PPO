#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui\CocosGUI.h"
#include "Definition.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
    auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

    scene->addChild(layer);
    return scene;
}


bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("road.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);

	this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY);

	playerCar = new PlayerCar(this);

	Vector<MenuItem*> itemsUI;
	auto leftButton = MenuItemImage::create("left.png", "left.png", CC_CALLBACK_1(GameScene::onTouchLeftButton, this));
	leftButton->setPosition(Point(100, 50));
	itemsUI.pushBack(leftButton);

	auto rightButton = MenuItemImage::create("right.png", "right.png", CC_CALLBACK_1(GameScene::onTouchRightButton, this));
	rightButton->setPosition(Point(0, 50));
	itemsUI.pushBack(rightButton);

	auto raceUI = Menu::createWithArray(itemsUI);
	this->addChild(raceUI, 1);

    return true;
}

void GameScene::SpawnPipe(float dt)
{
	slowDr.SpawnSlowDriver(this);
}


void GameScene::onTouchLeftButton(cocos2d::Ref *sender)
{
	playerCar->leftMove = true;
	playerCar->ControlCar();
	playerCar->leftMove = false;
}

void GameScene::onTouchRightButton(cocos2d::Ref *sender)
{
	playerCar->rightMove = true;
	playerCar->ControlCar();
	playerCar->rightMove = false;
}