#include "Constants.h"
#include "Aim.h"
USING_NS_CC;

Aim* Aim::createWithSpriteFrameName(char *fileName) {
	auto aim = new Aim;
	if ( aim && aim->initWithFile(fileName)) {
		aim->onMouseMove();
		aim->autorelease();
		return aim;
	}
	CC_SAFE_DELETE(aim);
	return nullptr;
}

void Aim::onMouseMove() {

	auto _mouseListener = EventListenerMouse::create();
	_mouseListener->onMouseMove = [&](cocos2d::Event* event) {
	EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);
	setPosition(Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY()));
		return true;
	 };
	
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_mouseListener, this);
}

void Aim::setAimParams(Vec2 YanchorPoint, float YscaleX, float YscaleY) {
	this->aimParams(YanchorPoint, YscaleX, YscaleY);
}

void Aim::aimParams(Vec2 anchorPoint, float scaleX, float scaleY) {
	this->setAnchorPoint(anchorPoint);
	this->setScaleX(scaleX);
	this->setScaleY(scaleY);
}