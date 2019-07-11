#ifndef __TARGETS__
#define __TARGETS__

#include "cocos2d.h"
USING_NS_CC;

class Targets : public cocos2d::Sprite{
private:
	void targetParams();
	void physicTargetParams(float velocityLimit, int TAG, Vec2 velocity, int categoryBitmask, int collisionBitmask, int contactBitmask);
public:
	static Targets* createWithSpriteFrameName(char *fileName);
	void setPhysicTargetParams(float YvelocityLimit, int YTAG, Vec2 Yvelocity = Vec2(random(-1500, 1500), random(-1500, 1500)),
		int YcategoryBitmask = Target, int YcollisionBitmask = Target + Cannonballs, int YcontactBitmask = Cannonballs);
};

#endif // __TARGETS__