#include "GameOver.h"
#include "GameEvents.h"
#include "FourthLayer.h"
#include "CCBManager.h"
CCScene* CGameOver::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        CGameOver *layer = CGameOver::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

bool CGameOver::init()
{
    bool bRet = false;

    do{
        CC_BREAK_IF(!CBaseScene::init());
        
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		
		/**	����	*/
		CCSprite *pBackGround = CCSprite::create("res/ui_bj_01.png");
		CC_BREAK_IF(! pBackGround);
//        pBackGround->setScale(2.5f);
		pBackGround->setPosition(ccp(size.width/2, size.height/2));
		this->addChild(pBackGround, 0);
        
        CCNode * fourthLayer = CCBManager::LoadCCBByNameAndLoader("FourthLayer",FourthLayerLoader::loader());
        this->addChild(fourthLayer,1);

		/**	���÷��ذ�ť	*/
		CCMenuItemImage *pBack = CCMenuItemImage::create();       
		pBack->initWithTarget(this, menu_selector(CGameOver::back));      
		pBack->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Back.png"));  
		pBack->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Back.png"));
		pBack->setPosition(ccp(size.width - 39, 21));

		/**	��Ӳ˵�	*/
		CCMenu *pMenu = CCMenu::create(pBack, NULL);
		pMenu->setPosition(ccp(0, 0));
//		this->addChild(pMenu, 6);

		bRet = true;
	}while(0);

	return bRet;
}

void CGameOver::back(CCObject* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Music/Title.mp3", true);
	CGameEvents::startFlipInterface(GAME_MENU);
}