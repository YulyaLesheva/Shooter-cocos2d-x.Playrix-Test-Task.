#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "cocos2d.h"

USING_NS_CC;


AppDelegate::AppDelegate()
{
	CCSize kScreenSize = CCSize(1265,768);
}

AppDelegate::~AppDelegate() 
{

}

bool AppDelegate::applicationDidFinishLaunching() {

	CCDirector* yDirector = CCDirector::sharedDirector();
	CCEGLView* yGlView = yDirector->getOpenGLView();
	
	if (!yGlView) {
		yGlView = GLViewImpl::createWithRect("Game", Rect(0, 0, 1265, 768), 1.0);
		yDirector->setOpenGLView(yGlView);
	}
	
	CCSize designSize = CCSize(1265, 768);
	
	yDirector->getOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::FIXED_HEIGHT);

	yDirector->setAnimationInterval(1.0 / 60);
	// turn on display FPS
	yDirector->setDisplayStats(false);

	
	CCScene *yHelloworld = HelloWorld::createScene();
	yDirector->runWithScene(yHelloworld);

	return true;

}


// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
  

}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
  

}
