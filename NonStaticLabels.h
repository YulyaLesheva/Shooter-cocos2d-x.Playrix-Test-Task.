#ifndef __NONSTATICLABELS__
#define __NONSTATICLABELS__

#include "cocos2d.h"
USING_NS_CC;

class NonStaticLabels : public cocos2d::Label{
private:
public: 
	void labelparams(Vec2 position, Label font);
	
};


#endif // __NONSTATICLABELS__