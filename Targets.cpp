#include "Constants.h"
#include "Targets.h"
USING_NS_CC;

Targets* Targets::createWithSpriteFrameName(char *fileName) {
	auto target = new Targets;
	if (target && target ->initWithFile(fileName)) {
		
		target->targetParams();
		target->autorelease();
		return target;
	}
	CC_SAFE_DELETE(target);
	return nullptr;
}

void Targets::targetParams() {
	
	int x, y;
	x = (random(kplayScreenStartX, kplayScreenEndX));
	y = (random(50, 718));

	this->setAnchorPoint(kObjectMedium);
	this->setScaleX(kScaleTargetX);
	this->setScaleY(kScaleTargetY);
	this->setPosition(Vec2(x, y));
}

void Targets::physicTargetParams(float velocityLimit, int TAG, int categoryBitmask, int collisionBitmask, int contactBitmask) {
	auto pb = PhysicsBody::createCircle(112, PhysicsMaterial(0.2f, 1.3f, 0.1f), Vec2::ZERO);
	this->setPhysicsBody(pb);
	pb->setVelocity(Vec2(random(-1500, 1500), random(-1500, 1500)));
	pb->setGravityEnable(false);
	pb->setVelocityLimit(velocityLimit);
	pb->setTag(TAG);
	pb->setCategoryBitmask(categoryBitmask);
	pb->setCollisionBitmask(collisionBitmask);
	pb->setContactTestBitmask(contactBitmask);

}

void Targets::setPhysicTargetParams(float YvelocityLimit, int YTAG, 
	int YcategoryBitmask, int YcollisionBitmask, int YcontactBitmask) {
	this->physicTargetParams(YvelocityLimit, YTAG, YcategoryBitmask, YcollisionBitmask, YcontactBitmask);
}