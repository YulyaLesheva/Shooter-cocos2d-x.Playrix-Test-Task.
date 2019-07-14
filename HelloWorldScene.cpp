#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "StaticObjects.h"
#include "Cannon.h"
#include "Constants.h"
#include "Targets.h"
#include "Aim.h"
#include "Cannonball.h"
#include "MyEffects.h"
USING_NS_CC;


Scene* HelloWorld::createScene()
{	
	Scene *scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
	HelloWorld *layer = HelloWorld::create();
	scene->addChild(layer);

	return scene;
}

bool HelloWorld::init()
{
	initWithPhysics();
	createNodes();
	createBackGround(_bgNode);
	createCannon(_bgNode);
	addAim(_bgNode);
	gameListeners();
	checkCollision();
	createTargets(_targetNode);
	_acceptTouches = true;

	this->schedule(schedule_selector(HelloWorld::update), 1.0f);
	

    if ( !Scene::init())
    {
        return false;
    }
    return true;
}

void HelloWorld::createBackGround(CCNode *node){

	_phWorld = getPhysicsWorld();

	_backbackground = StaticObjects::createWithSpriteFrameName("backbackground1.png");
	_backbackground->setStaticParams(Vec2(kObjectMedium), kZeroscaleX, kZeroscaleY, Vec2(kScreenMedium));
	node->addChild(_backbackground, yForeground);

	_background = StaticObjects::createWithSpriteFrameName("background.png");
	_background->setStaticParams(Vec2(kObjectMedium), kZeroscaleX, kZeroscaleY, Vec2(kScreenMedium));
	node->addChild(_background, yBackground);

	_clock = StaticObjects::createWithSpriteFrameName("Clock.png");
	_clock->setStaticParams(Vec2(kObjectMedium), kscaleX, kscaleY, Vec2(kClockPos));
	node->addChild(_clock, yForeground);

	_score = StaticObjects::createWithSpriteFrameName("Score1.png");
	_score->setStaticParams(Vec2(kObjectMedium), kscaleX, kscaleY, Vec2(kScorePos));
	node->addChild(_score, yForeground);

	_restart = StaticObjects::createWithSpriteFrameName("restart.png");
	_restart->getRestartParams();
	node->addChild(_restart, yBackground);

	_scoreDisplay = CCLabelBMFont::create("0", "fontfont.fnt", 220);
	_scoreDisplay->setPosition(kScoreNumsPos);
	node->addChild(_scoreDisplay, yForeground);

	_timer = CCLabelBMFont::create(" ", "fontfont.fnt", 220);
	_timer->setPosition(kTimerPos);
	node->addChild(_timer, yForeground);
}

void HelloWorld::createNodes(){
	
	_bgNode = CCNode::create();
	this->addChild(_bgNode);
	_targetNode = CCNode::create();
	this->addChild(_targetNode);

}

void HelloWorld::createCannon(CCNode *node) {
	_stand = StaticObjects::createWithSpriteFrameName("Stand1.png");
	_stand->setStaticParams(Vec2(kObjectMedium), kscaleX, kscaleY, Vec2(kStandPos));
	node->addChild(_stand, yForeground);

	_cannon = Cannon::createWithSpriteFrameName("Cannon.png");
	_cannon->setCannonParams(kObjectMedium, kScaleTargetX, kScaleTargetY, kCannonPos);
	node->addChild(_cannon, yMiddleground);

}

void HelloWorld::createTargets(CCNode *node, int maxBomb, int yellowTargetNumber, int pinkTargetNumber) {
	
	for (int i = 0; i < random(1, maxBomb); i++) {
		_target = Targets::createWithSpriteFrameName("Bomb.png");
		_target->setPhysicTargetParams(400, TAGbomb);
		_targetNode->addChild(_target, yBackground);
	}

	for (int i = 0; i < yellowTargetNumber; i++) {
		_target = Targets::createWithSpriteFrameName("Target.png");
		_target->setPhysicTargetParams(400, TAGyellowTarget);
		_targetNode->addChild(_target, yBackground);

	}

	for (int i = 0; i < pinkTargetNumber; i++) {

		_target = Targets::createWithSpriteFrameName("Target2.png");
		_target->setPhysicTargetParams(800, TAGpinkTarget);
		_targetNode->addChild(_target, yBackground);
	}

}

void HelloWorld::addAim(CCNode *node) {

	_aim = Aim::createWithSpriteFrameName("Aim.png");
	_aim->setAimParams(kObjectMedium, kscaleX, kscaleY);
	node->addChild(_aim, yBackground);
}

bool HelloWorld::cannonShooting(cocos2d::Touch *touch, cocos2d::Event *event) {

	if (!_acceptTouches) return false;

	Vec2 touchLocation = touch->getLocation();
	Vec2 offset = touchLocation - _cannon->getPosition();

	if (touchLocation.x < kplayScreenStartX || touchLocation.x > kplayScreenEndX) {
		return true;
	}



	_cannonball = Cannonball::createWithSpriteFrameName("Cannonball.png");
	_cannonball->setPhysicCannonballParams();
	_bgNode->addChild(_cannonball, yBackground);

	_newEffect = MyEffects::create("bike.plist");
	_newEffect->setPosition(kPlumePos);
	_cannonball->addChild(_newEffect);
	
	offset.normalize();

	auto shootAmount = offset * 1024;
	auto realDest = shootAmount + _cannonball->getPosition();
	auto actionMove = MoveTo::create(1.0f, Vec2(realDest));
	auto actionRemove = RemoveSelf::create();

	_cannonball->runAction(Sequence::create(actionMove, actionRemove, nullptr));

	return true;

}

void HelloWorld::gameListeners(){
	
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::cannonShooting, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::checkCollision() {
	
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = [&](PhysicsContact &contact) {

		_yellowBoom = MyEffects::create("yellow.plist");
		_yellowBoom->setBoomParams();
		_targetNode->addChild(_yellowBoom);

		_redBoom = MyEffects::create("coolred.plist");
		_redBoom->setBoomParams();
		_targetNode->addChild(_redBoom);

		_pinkBoom = MyEffects::create("pink.plist");
		_pinkBoom->setBoomParams();
		_targetNode->addChild(_pinkBoom);

		auto bodyA = contact.getShapeA()->getBody();
		auto bodyB = contact.getShapeB()->getBody();

		bodyA->getNode()->removeFromParent();
		bodyB->getNode()->removeFromParent();

		int tagFirst = bodyA->getTag();
		int tagSecong = bodyB->getTag();

		auto delay = DelayTime::create(0.5);
		auto remove = RemoveSelf::create();
		
		if (tagFirst== TAGyellowTarget || tagSecong == TAGyellowTarget) {

			raiseScore(1);

			_yellowBoom->setVisible(true);
			_yellowBoom->setPosition(bodyA->getPosition());
			_yellowBoom->runAction(Sequence::create(delay, remove, nullptr));

		}
		else if (tagFirst == TAGpinkTarget || tagSecong == TAGpinkTarget) {
			
			raiseScore(100);
			_pinkBoom->setVisible(true);
			_pinkBoom->setPosition(bodyA->getPosition());
			_pinkBoom->runAction(Sequence::create(delay, remove, nullptr));

		}

		else {
			_redBoom->setVisible(true);
			_redBoom->setPosition(bodyA->getPosition());
			_redBoom->runAction(Sequence::create(delay, CallFunc::create(std::bind(&HelloWorld::stopGame, this)), remove, nullptr));
		}
		return true;
	
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

void HelloWorld::update(float dt) {

	_phWorld->setUpdateRate(1000.0);
	
	if (_time > 0) {
		_time -= dt;

		CCString *value = CCString::createWithFormat("%i", _time);
		_timer->setString((value->getCString()));
	}
	if (_time <= 0 || _myScore == 1010) {
		stopGame();
	}

}

void HelloWorld::raiseScore(int score) {

	_myScore += score; 
	CCString *value = CCString::createWithFormat("%i", _myScore);
	_scoreDisplay->setString((value->getCString()));

}

void HelloWorld::startGame() {
	_myScore = 0;
	_time = 30;
	_timer->setVisible(true);
	_restart->setVisible(false);
	_acceptTouches = true;
	createTargets(_targetNode);

}

void HelloWorld::stopGame() {
	_acceptTouches = false;
	_targetNode->removeAllChildren();
	_restart->setVisible(true);
	_timer->setVisible(false);

	auto eventListener = EventListenerTouchOneByOne::create();
	eventListener->onTouchBegan = [&](Touch* touch, Event* event) {
		Vec2 touchLocation = touch->getLocation();
		if (touchLocation.y >= 0) {
			startGame();
		}
		return true;
	};
	eventListener->setSwallowTouches(true);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);

}
