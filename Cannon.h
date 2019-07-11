#ifndef __HELLOWORLD_SCENE_CANNON__
#define __HELLOWORLD_SCENE_CANNON__

#include "cocos2d.h"
USING_NS_CC;


class Cannon : public cocos2d::Sprite
{
private:
	void cannonParams(Vec2 anchorPoint, float scaleX, float scaleY, Vec2 position);
	float changingAngle(Vec2 imageCenter, float coursorX, float coursorY, float calculatedAngle);
	void rotateCannon();
public:
	static Cannon* createWithSpriteFrameName(char *fileName);
	void setCannonParams(Vec2 YanchorPoint, float YscaleX, float YscaleY, Vec2 Yposition);

};

#endif // __HELLOWORLD_SCENE_CANNON__