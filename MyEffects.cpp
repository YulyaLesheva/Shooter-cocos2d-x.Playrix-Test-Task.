#include "Constants.h"
#include "MyEffects.h"
USING_NS_CC;

MyEffects * MyEffects::create(char * fileName)
{
	auto effect = new MyEffects;
	if (effect && effect->initWithFile(fileName)) {
		///effect->setEffectParams();
		effect->autorelease();
		return effect;

	}
	CC_SAFE_DELETE(effect);
	return nullptr;
}

void MyEffects::effectParams(Vec2 anchorPoint, float scaleX, float scaleY, Vec2 position, int TAG)
{
	setAnchorPoint(anchorPoint);
	setScaleX(scaleX);
	setScaleY(scaleY);
	setPosition(position);
	setTag(TAG);
}

void MyEffects::setEffectParams() {
	effectParams(kObjectMedium, 1.35, 1.35, kPlumePos,TAGplume);
}

void MyEffects::boomParams(float scaleX, float scaleY) {
	setScaleX(scaleX);
	setScaleY(scaleY);
	setVisible(false);
}

void MyEffects::setBoomParams() {
	boomParams(0.5, 0.5);
}


