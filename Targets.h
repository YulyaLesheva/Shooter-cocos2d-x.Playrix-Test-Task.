#ifndef __TARGETS__
#define __TARGETS__

#include "cocos2d.h"
USING_NS_CC;

class Targets : public cocos2d::Sprite
{
private:
	void targetParams();
	void physicTargetParams(float velocityLimit, int TAG, int categoryBitmask, int collisionBitmask, int contactBitmask);
public:
	static Targets* createWithSpriteFrameName(char *fileName);
	void setPhysicTargetParams(float YvelocityLimit, int YTAG,
		int YcategoryBitmask = Target, int YcollisionBitmask = Target + Cannonballs, int YcontactBitmask = Cannonballs);
};

#endif // __TARGETS__