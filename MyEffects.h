#ifndef __MYEFFECTS__
#define __MYEFFECTS__

#include "cocos2d.h"
USING_NS_CC;

class MyEffects : public ParticleSystemQuad {
private:
	void boomParams(float scaleX, float scaleY);
	void effectParams(Vec2 anchorPoint, float scaleX, float scaleY, Vec2 position, int TAG);
public:
	static MyEffects* create(char *fileName);
	void setEffectParams();
	void setBoomParams();

};

#endif // __MYEFFECTS__