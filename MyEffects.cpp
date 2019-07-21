#include "Constants.h"
#include "MyEffects.h"
USING_NS_CC;

MyEffects * MyEffects::create(char * fileName)
{
	auto effect = new MyEffects;
	if (effect && effect->initWithFile(fileName)) {
		effect->autorelease();
		return effect;

	}
	CC_SAFE_DELETE(effect);
	return nullptr;
}

void MyEffects::effectParams(Vec2 anchorPoint, float scaleX, float scaleY, Vec2 position, int TAG)
{
	this->setAnchorPoint(anchorPoint);
	this->setScaleX(scaleX);
	this->setScaleY(scaleY);
	this->setPosition(position);
	this->setTag(TAG);
}

void MyEffects::setEffectParams() {
	this->effectParams(kObjectMedium, 1.35, 1.35, kPlumePos,TAGplume);
}

void MyEffects::boomParams(float scaleX, float scaleY) {
	this->setScaleX(scaleX);
	this->setScaleY(scaleY);
	this->setVisible(false);
}

void MyEffects::setBoomParams() {
	this->boomParams(0.5, 0.5);
}


