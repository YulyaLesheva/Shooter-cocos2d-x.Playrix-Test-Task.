#include "Constants.h"
#include "Targets.h"
USING_NS_CC;

Targets* Targets::createWithSpriteFrameName(char *fileName) {
	auto target = new Targets;
	if (target && target ->initWithFile(fileName)) {
		
		///if (fileName == "Target.png") { target->setYellowPhysicTargetParams(); }
		///else { target->setPinkPhysicTargetParams(); }
		target->targetParams();
		///target->setYellowPhysicTargetParams();
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

	setAnchorPoint(kObjectMedium);
	setScaleX(kScaleTargetX);
	setScaleY(kScaleTargetY);
	setPosition(Vec2(x, y));
}

void Targets::physicTargetParams(float velocityLimit, int TAG, Vec2 velocity, int categoryBitmask, int collisionBitmask, int contactBitmask) {
	auto pb = PhysicsBody::createCircle(112, PhysicsMaterial(0.2f, 1.3f, 0.1f), Vec2::ZERO);
	setPhysicsBody(pb);
	pb->setGravityEnable(false);
	pb->setVelocity(velocity);
	pb->setVelocityLimit(velocityLimit);
	pb->setTag(TAG);
	pb->setCategoryBitmask(categoryBitmask);
	pb->setCollisionBitmask(collisionBitmask);
	pb->setContactTestBitmask(contactBitmask);

}

void Targets::setPhysicTargetParams(float YvelocityLimit, int YTAG, Vec2 Yvelocity,
	int YcategoryBitmask, int YcollisionBitmask, int YcontactBitmask) {
	physicTargetParams( YvelocityLimit, YTAG, Yvelocity, YcategoryBitmask, YcollisionBitmask, YcontactBitmask);
}