#include "AppDelegate.h"
#include "SimpleAudioEngine.h"
#include "SplashScene.h"

USING_NS_CC;

using namespace CocosDenshion;

AppDelegate::AppDelegate() 
{

}

AppDelegate::~AppDelegate() 
{
}

void AppDelegate::initGLContextAttrs()
{
	GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() 
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("car_race");
		glview->setFrameSize(480, 800);
        director->setOpenGLView(glview);
    }
    director->getOpenGLView()->setDesignResolutionSize(768, 1280, ResolutionPolicy::NO_BORDER);
	
	director->setDisplayStats(false);
    director->setAnimationInterval(1.0 / 60);
    FileUtils::getInstance()->addSearchPath("res");

    auto scene = SplashScene::createScene();
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() 
{
    Director::getInstance()->stopAnimation();
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground() 
{
    Director::getInstance()->startAnimation();
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
