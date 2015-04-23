#include "Effect.h"

using namespace std;

void CEffect::sharedExplosion()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("res/Image/explosion.plist");
	CCArray *animFrames = CCArray::create();
	char str[64] = {0};
	for (int i = 1; i < 35; i++) {
		sprintf(str, "explosion_%02d.png", i); 
		CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		animFrames->addObject(frame);
	}
	CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames, 0.04f);
	CCAnimationCache::sharedAnimationCache()->addAnimation(animation, "Explosion");

}

void CEffect::sharedGold()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("res/Image/Item.plist");
	CCArray *animFrames = CCArray::create();
	char str[64] = {0};
	for (int i = 1; i < 8; i++) {
		sprintf(str, "Gold_%02d.png", i);
		CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		animFrames->addObject(frame);
	}
	CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames, 0.2f);	
	CCAnimationCache::sharedAnimationCache()->addAnimation(animation, "Gold");

}