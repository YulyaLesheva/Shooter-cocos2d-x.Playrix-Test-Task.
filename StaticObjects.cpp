#include "StaticObjects.h"
#include "Constants.h"
USING_NS_CC;

StaticObjects* StaticObjects::createWithSpriteFrameName(char *fileName) {
	auto staticObject = new StaticObjects;
	if (staticObject && staticObject->initWithFile(fileName)) {
		if (fileName == "backbackground1.png") {
			staticObject->physicsBGParams();
		}
		staticObject->autorelease();
		return staticObject;
	}
	CC_SAFE_DELETE(staticObject);
	return nullptr;
}

void StaticObjects::staticParams(Vec2 anchorPoint, float scaleX, float scaleY, Vec2 position) {
	setAnchorPoint(anchorPoint);
	setScale(scaleX, scaleY);
	setPosition(position);
}

void StaticObjects::physicsBGParams() {
	auto pb = PhysicsBody::createEdgeBox(kplayScreen, PhysicsMaterial(10.0f, 2.0f, 0.0f), 3);
	setPhysicsBody(pb);
	setPosition(Vec2(kplayScreen*0.5, kplayScreen*0.5));
}

void StaticObjects::setStaticParams(Vec2 YanchorPoint, float YscaleX, float YscaleY, Vec2 Yposition) {
	staticParams(YanchorPoint, YscaleX, YscaleY, Yposition);
}

void StaticObjects::restartParams() {
	setVisible(false);
	staticParams(kObjectMedium, kZeroscaleX, kZeroscaleY, kScreenMedium);
}

void StaticObjects::getRestartParams() {
	return restartParams();
}
