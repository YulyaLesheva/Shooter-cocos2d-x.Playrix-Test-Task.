#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class StaticObjects;
class Cannon;
class Targets;
class Aim;
class Cannonball;
class MyEffects;



class HelloWorld : public cocos2d::Scene
{
private:
	void addAim();
	void createTargets(int maxBomb=3, int yellowTargetNumber=10, int pinkTargetNumber=10);
	void createCannon();
	void createBackGround();
	int _time=30;
	int _myScore = 0;

	StaticObjects *_background;
	StaticObjects *_backbackground;
	StaticObjects *_stand;
	StaticObjects *_clock;	
	StaticObjects *_score;
	StaticObjects *_restart;
	Cannon *_cannon;
	Cannonball *_cannonball;
	CCNode *_bgNode;
	CCNode *_fgNode;
	CCNode *_targetNode;
	CCSize _designSizeMedium;
	CCSize _designSize;
	Vec2 _screenMedium;
	Targets *_target;
	Targets *_1target;
	Targets *_2target;
	Size *_targetSize;
	Aim *_aim;
	MyEffects *_newEffect;
	PhysicsWorld *_phWorld;
	MyEffects *_yellowBoom;
	MyEffects *_pinkBoom;
	MyEffects *_redBoom;
	CCLabelBMFont *_timer;
	CCLabelBMFont *_scoreDisplay;
	bool _acceptTouches;
	void superShooting();
	void standart();
	int _highScore;
public:
	static Scene* createScene();
    virtual bool init();
	virtual void goTimer(float dt);
	void createNodes();
	void checkCollision();
	void raiseScore(int score);
	void startGame();
	void stopGame();
	void getTxt();
	void update(float dt);

    // implement the "static create()" method manually
    
	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
