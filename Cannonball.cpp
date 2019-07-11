#include "Constants.h"
#include "Cannonball.h"
USING_NS_CC;

Cannonball* Cannonball::createWithSpriteFrameName(char *fileName) {
	
	auto cannonball = new Cannonball;
	if (cannonball && cannonball->initWithFile(fileName)){
		cannonball->cannonballParams();
		cannonball->autorelease();

		return cannonball;
	}
	CC_SAFE_DELETE(cannonball);
	return nullptr;
}

void Cannonball::cannonballParams() {
	setAnchorPoint(kObjectMedium);
	setScale(kScaleTargetX, kScaleTargetY);
	setPosition(kCannonPos);
}

void Cannonball::physicCannonballParams(int TAG, int categoryBitmask, int collisionBitmask, int contactBitmask) {
	auto pb = PhysicsBody::createCircle(100, PhysicsMaterial(0.2f, 1.3f, 0.0f), Vec2::ZERO);
	setPhysicsBody(pb);
	pb->setGravityEnable(true);
	pb->setTag(TAG);
	pb->setCategoryBitmask(categoryBitmask);
	pb->setCollisionBitmask(collisionBitmask);
	pb->setContactTestBitmask(contactBitmask);
}

void Cannonball::setPhysicCannonballParams(int YTAG, int YcategoryBitmask, int YcollisionBitmask, int YcontactBitmask) {
	physicCannonballParams(YTAG, YcategoryBitmask, YcollisionBitmask, YcontactBitmask);
}