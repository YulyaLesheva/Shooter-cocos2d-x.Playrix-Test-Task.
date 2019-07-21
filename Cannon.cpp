#include "Constants.h"
#include "Cannon.h"
USING_NS_CC;



Cannon* Cannon::createWithSpriteFrameName(char *fileName) {
	auto cannon = new Cannon;
	if (cannon && cannon->initWithFile(fileName)) {
		cannon->rotateCannon();
		cannon->autorelease();
		return cannon;
	}
	CC_SAFE_DELETE(cannon);
	return nullptr;
}

void Cannon::cannonParams(Vec2 anchorPoint, float scaleX, float scaleY, Vec2 position) {
	this->setAnchorPoint(anchorPoint);
	this->setScaleX(scaleX);
	this->setScaleY(scaleY);
	this->setPosition(position);
}

void Cannon::setCannonParams(Vec2 YanchorPoint, float YscaleX, float YscaleY, Vec2 Yposition) {
	this->cannonParams(YanchorPoint, YscaleX, YscaleY, Yposition);
}

float Cannon::changingAngle(Vec2 imageCenter, float coursorX, float coursorY, float calculatedAngle) {
	if ((calculatedAngle >= 0 && calculatedAngle <= 90) || (calculatedAngle >= 90 && calculatedAngle <= 180)) {
		calculatedAngle = calculatedAngle;
	}
	else if (calculatedAngle < 0 && calculatedAngle >= -90) {
		calculatedAngle = 270 + (90 + calculatedAngle);
	}
	else if (calculatedAngle < -90 && calculatedAngle >= -180) {
		calculatedAngle = 180 + (180 + calculatedAngle);
	}

	return calculatedAngle;
}

void Cannon::rotateCannon() {	
	auto _mouseListener = EventListenerMouse::create();
	_mouseListener->onMouseMove = [&](cocos2d::Event* event) {
		
	EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);
	Vec2 location = Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
	Vec2 offset = Vec2(location.x - kCannonPos.x, location.y - kCannonPos.y);
	float angleRadians = atan2f(offset.x, offset.y);
	angleRadians = CC_RADIANS_TO_DEGREES(-angleRadians);
	angleRadians = Cannon::changingAngle(kCannonPos, location.x, location.y, angleRadians);

	offset.normalize();
	setRotation(-angleRadians);

		return true;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_mouseListener, this);

}

