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
	
	bool _acceptTouches;

	void addAim();
	void createTargets(int maxBomb=1, int yellowTargetNumber=1, int pinkTargetNumber=1);
	void createCannon();
	void createBackGround();
	void initValuesFromTxt();
	void startGame();
	void stopGame();
	void superShooting();
	void createNodes();
	void checkCollision();
	void raiseScore(int score);
	virtual void createCannonball();

	int _time;
	int _countTarget;
	int _maxBomb;
	int _myScore = 0;
	int _highScore;

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
	
	Targets *_target;
	Targets *_1target;
	Targets *_2target;
	
	Aim *_aim;
	
	MyEffects *_newEffect;
	MyEffects *_yellowBoom;
	MyEffects *_pinkBoom;
	MyEffects *_redBoom;
	
	CCLabelBMFont *_timer;
	CCLabelBMFont *_scoreDisplay;
	

	PhysicsWorld *_phWorld;

public:
	static Scene* createScene();
    virtual bool init();
	virtual void goTimer(float dt);
	void update(float dt);

    // implement the "static create()" method manually
    
	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
