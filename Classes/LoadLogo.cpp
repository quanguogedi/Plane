
#include "GameEvents.h"
#include "LoadLogo.h"


CCScene* CLoadLogo::scene()
{
	CCScene * scene = NULL;
	do 
	{
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		CLoadLogo *layer = CLoadLogo::create();
		CC_BREAK_IF(! layer);
        
		scene->addChild(layer);
	} while (0);

	return scene;
}

bool CLoadLogo::init()
{
	do{
		CC_BREAK_IF(! CBaseScene::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCSprite* pSprite = CCSprite::create("res/ui_bj_01.png");
		CC_BREAK_IF(! pSprite);

		pSprite->setPosition(ccp(size.width/2, size.height/2));
		this->addChild(pSprite, 0);
        
        CCLabelTTF * label = CCLabelTTF::create("这不是我们的logo", "Arial", 50);
        label->setPosition(ccp(size.width*0.5, size.height*0.5));
        this->addChild(label,10);

		this->scheduleOnce(schedule_selector(CLoadLogo::makeTransition), 1.5f);
	}
	while(0);

	return true;
}

void CLoadLogo::makeTransition(float dt)
{
//    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Image/Shield.plist");//old
//    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Image/Missile.plist");//old
//    
//    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("res/Resources/002_ef_001.plist");
//    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("res/Resources/003_enemy_a.plist");
//    
//	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Music/Title.mp3", true);
	CGameEvents::startFlipInterface(GAME_MENU);
}