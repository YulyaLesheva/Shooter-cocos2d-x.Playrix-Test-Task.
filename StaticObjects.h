#ifndef __HELLOWORLD_SCENE_STATICOBJECTS__
#define __HELLOWORLD_SCENE_STATICOBJECTS__

#include "cocos2d.h"
USING_NS_CC;


class StaticObjects : public cocos2d::Sprite
{
private:
	void staticParams(Vec2 anchorPoint, float scaleX, float scaleY, Vec2 position);
	void restartParams();
	void physicsBGParams();
public:
	static StaticObjects* createWithSpriteFrameName(char *fileName);
	void setStaticParams(Vec2 YanchorPoint, float YscaleX, float YscaleY, Vec2 Yposition);
	void getRestartParams();
	void tryToCreate();
};

#endif // __HELLOWORLD_SCENE_STATICOBJECTS__
