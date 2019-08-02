#include "cocos2d.h"
USING_NS_CC;

const Vec2 kObjectMedium = Vec2(0.5f, 0.5f);
const Vec2 kClockPos = Vec2(1205.0f,515.0f);
const Vec2 kTimerPos = Vec2(kClockPos.x, kClockPos.y-70.0f);

const Vec2 kStandPos = Vec2(632.5f, 35.0f);
const Vec2 kScorePos = Vec2(60.0f, 520.0f);
const Vec2 kScoreNumsPos = Vec2(kScorePos.x,kScorePos.y -70.0f);
const Vec2 kCannonPos = Vec2(kStandPos.x, kStandPos.y + 75.0f);
const Vec2 kScreenMedium = Vec2(1265 * 0.5f, 768 * 0.5f);
const Vec2 kPlumePos = Vec2(kCannonPos.x-309, 0.0);

const float kscaleX = 0.5f;
const float kscaleY = 0.5f;
const float kZeroscaleX = 1.0f;
const float kZeroscaleY = 1.0f;
const float kScaleTargetX = 0.15f;
const float kScaleTargetY = 0.15f;
const float kplayScreenStartX = 120.5f;
const float kplayScreenEndX = 1265 - 120.5f;

const Size kScreenSize = Size(1265.0f, 768.0f);
const Size kplayScreen = Size(1024.0f, 768.0f);
const int TAGbomb = 69;
const int TAGcannonball = 5;
const int TAGyellowTarget = 11;
const int TAGpinkTarget = 22;
const int TAGedges = 40;
const int TAGplume = 99;

const int PINK_VALUE = 100;
const int YELLOW_VALUE = 1;


enum PhysicsCategory
{
	None = 0, ///0
	Target = (1 << 0),///1
	Cannonballs = (1 << 2),///4
	EdgeScreen = (1 << 3),///8
};

enum 
{
	yBackground,
	yMiddleground,
	yForeground,
};