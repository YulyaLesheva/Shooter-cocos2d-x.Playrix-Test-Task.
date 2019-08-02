#ifndef __CANNONBALL__
#define __CANNONBALL__

#include "cocos2d.h"
USING_NS_CC;

class Cannonball : public cocos2d::Sprite 
{
private:
	void physicCannonballParams(int TAG, int categoryBitmask, int collisionBitmask, int contactBitmask);
	void cannonballParams();
public:
	static Cannonball* createWithSpriteFrameName(char *fileName);
	void setPhysicCannonballParams(int YTAG = TAGcannonball, int YcategoryBitmask =  Cannonballs, int YcollisionBitmask = None, int YcontactBitmask = Target);
};


#endif // __CANNONBALL__