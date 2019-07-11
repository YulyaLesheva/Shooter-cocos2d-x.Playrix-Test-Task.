#ifndef __AIM__
#define __AIM__

#include "cocos2d.h"
USING_NS_CC;

class Aim : public cocos2d::Sprite {
private:
	void aimParams(Vec2 anchorPoint, float scaleX, float scaleY);
	void onMouseMove();
public:
	static Aim* createWithSpriteFrameName(char *fileName);
	void setAimParams(Vec2 YanchorPoint, float YscaleX, float YscaleY);
};


#endif // __AIM__