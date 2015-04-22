#include "GameLevel.h"
#include "GameEvents.h"
#include "CCRadioMenu.h"
#include "SecondLayer.h"



CCScene* CGameLevel::scene()
{
	CCScene * scene = NULL;
	do 
	{
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		CGameLevel *layer = CGameLevel::create();
		CC_BREAK_IF(! layer);

		scene->addChild(layer);
	} while (0);
    
    

	return scene;
}

bool CGameLevel::init()
{
	bool bRet = false;
	do{
		CC_BREAK_IF(! CBaseScene::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();
        
        CCSprite* pSprite = CCSprite::create("res/ui_bj_02.png");
        pSprite->setScale(1.34);
        pSprite->setPosition(ccp(size.width/2, size.height/2));
        this->addChild(pSprite);
        
        
        
        
        
        
        
        InitBottomLayer();
        
//        mMenuTopBarLayer = (MenuTopBarLayer*)CCBManager::LoadCCBByNameAndLoader("MenuTopBarLayer", MenuTopBarLayerLoader::loader());
//        mMenuTopBarLayer->SetDelegate(this);
//        addChild(mMenuTopBarLayer);
//        
//        mLevelBottomLayer = (LevelBottomLayer*)CCBManager::LoadCCBByNameAndLoader("LevelBottomLayer", LevelBottomLayerLoader::loader());
//        mLevelBottomLayer->SetDelegate(this);
//        addChild(mLevelBottomLayer);
        
        
        
		// 选关列表
//		CCSpriteFrameCache *pCache = CCSpriteFrameCache::sharedSpriteFrameCache();
//		pCache->addSpriteFramesWithFile("Image/GameLevel.plist");

//		// 选关背景
//		CCSpriteFrame* pBG = pCache->spriteFrameByName("GameLevelBG.png");
//		CCSprite* pSprite = CCSprite::createWithSpriteFrame(pBG);
//        pSprite->setScale(2.5f);
//		pSprite->setPosition(ccp(size.width/2, size.height/2));
//		this->addChild(pSprite, 0);
//		
//		/**背景特效	*/
//		CCParticleSystemQuad *emitter = new CCParticleSystemQuad();
//		emitter->autorelease();
//		emitter->initWithFile("Image/Phoenix.plist");
//		emitter->setPosition(ccp(size.width/2, size.height/2));
//        emitter->setScale(2.5f);
//		this->addChild(emitter, 1);
//
        
//        SecondLayer* secondLayer = (SecondLayer*)CCBManager::LoadCCBByNameAndLoader("SecondLayer", SecondLayerLoader::loader());
//        this->addChild(secondLayer);
        
//        mLevelListLayer = LevelListLayer::create();
//        mLevelListLayer->SetScrollHeight(1280 * 3);
//        addChild(mLevelListLayer);
//
//		/**	关卡一按钮	*/
//		cocos2d::CCMenuItemImage *pLevelOne = cocos2d::CCMenuItemImage::create();
//		pLevelOne->initWithTarget(this, menu_selector(CGameLevel::setLevelMode));
//		pLevelOne->setNormalSpriteFrame(pCache->spriteFrameByName("ui_001_barrier_01.png"));
//		pLevelOne->setSelectedSpriteFrame(pCache->spriteFrameByName("ui_001_barrier_01.png"));
//		pLevelOne->setPosition(ccp(size.width*0.14f, size.height/2));
////        pLevelOne->setScale(2.5f);
//		pLevelOne->m_uID = LEVEL_ONE;
//        
//        CCSprite * one1 = CCSprite::createWithSpriteFrameName("ui_001_barrier_00.png");
//        one1->setPosition(ccp(pLevelOne->getContentSize().width*0.5,pLevelOne->getContentSize().height*0.5));
//        pLevelOne->addChild(one1);
//        CCSprite * one2 = CCSprite::createWithSpriteFrameName("w_barrier_1.png");
//        one2->setPosition(ccp(one1->boundingBox().getMidX(),one1->boundingBox().getMidY()));
//        one1->addChild(one2);
//        
//
//		/**	关卡二按钮	*/
//		cocos2d::CCMenuItemImage *pLevelTwo = cocos2d::CCMenuItemImage::create();
//		pLevelTwo->initWithTarget(this, menu_selector(CGameLevel::setLevelMode));
//		pLevelTwo->setNormalSpriteFrame(pCache->spriteFrameByName("ui_001_barrier_01.png"));
//		pLevelTwo->setSelectedSpriteFrame(pCache->spriteFrameByName("ui_001_barrier_01.png"));
//		pLevelTwo->setPosition(ccp(size.width/2, size.height*0.8f));
////        pLevelTwo->setScale(2.5f);
//		pLevelTwo->m_uID = LEVEL_TWO;
//
//        CCSprite * two1 = CCSprite::createWithSpriteFrameName("ui_001_barrier_00.png");
//        two1->setPosition(ccp(pLevelTwo->getContentSize().width*0.5,pLevelTwo->getContentSize().height*0.5));
//        pLevelTwo->addChild(two1);
//        CCSprite * two2 = CCSprite::createWithSpriteFrameName("w_barrier_2.png");
//        two2->setPosition(ccp(two1->boundingBox().getMidX(),two1->boundingBox().getMidY()));
//        two1->addChild(two2);
//        
//        
//		/**	关卡三按钮	*/
//		cocos2d::CCMenuItemImage *pLevelThree = cocos2d::CCMenuItemImage::create();
//		pLevelThree->initWithTarget(this, menu_selector(CGameLevel::setLevelMode));
//		pLevelThree->setNormalSpriteFrame(pCache->spriteFrameByName("ui_001_barrier_01.png"));
//		pLevelThree->setSelectedSpriteFrame(pCache->spriteFrameByName("ui_001_barrier_01.png"));
//		pLevelThree->setPosition(ccp(size.width*0.86f, size.height * 2));
////        pLevelThree->setScale(2.5f);
//		pLevelThree->m_uID = LEVEL_THREE;
//        
//        
//        CCSprite * three1 = CCSprite::createWithSpriteFrameName("ui_001_barrier_00.png");
//        three1->setPosition(ccp(pLevelThree->getContentSize().width*0.5,pLevelThree->getContentSize().height*0.5));
//        pLevelThree->addChild(three1);
//        CCSprite * three2 = CCSprite::createWithSpriteFrameName("w_barrier_3.png");
//        three2->setPosition(ccp(three1->boundingBox().getMidX(),three1->boundingBox().getMidY()));
//        three1->addChild(three2);
//
//		/**	游戏开始按钮	*/
//		cocos2d::CCMenuItemImage *pStart = cocos2d::CCMenuItemImage::create();
//		pStart->initWithTarget(this, menu_selector(CGameLevel::setLevelStart));
//		pStart->setNormalSpriteFrame(pCache->spriteFrameByName("GameStartNormal.png")); 
//		pStart->setSelectedSpriteFrame(pCache->spriteFrameByName("GameStartSelected.png"));
//        pStart->setScale(1.5f);
//		pStart->setPosition(ccp(size.width/2, size.height*0.2f));
//
//		/**	返回按钮	*/
////		CCMenuItemImage *pBack = CCMenuItemImage::create();       
////		pBack->initWithTarget(this, menu_selector(CGameLevel::back));      
////		pBack->setNormalSpriteFrame(pCache->spriteFrameByName("Back.png"));  
////		pBack->setSelectedSpriteFrame(pCache->spriteFrameByName("Back.png"));
////		pBack->setAnchorPoint(ccp(1,0));
////        pBack->setScale(1.5f);
////		//pBack->setPosition(ccp(size.width - 39, 21));
////		pBack->setPosition(ccp(size.width, 0));
//
//		/** 创建单项按钮管理对象 CCMenu	*/
//		CCRadioMenu *pRadioMenu = CCRadioMenu::create(pLevelOne, pLevelTwo, pLevelThree, NULL);
//		pRadioMenu->setPosition(ccp(0,0));
//		pRadioMenu->setSelectedItem_(pLevelOne);
//		pLevelOne->selected();   
//		g_iGameLevel = LEVEL_ONE;
////		this->addChild(pRadioMenu,2);
//
//        mLevelListLayer->AddSubCell(pRadioMenu);
        
		/**	菜单	*/
//		CCMenu *pMenu = CCMenu::create(pStart, pBack, NULL);
//		pMenu->setPosition(ccp(0, 0));
//		this->addChild(pMenu, 3);

//		/**	选中特效	*/
//		m_pSun = CCParticleSun::create();
//		pSprite->addChild(m_pSun, 1);
//		m_pSun->setTexture(CCTextureCache::sharedTextureCache()->addImage("Image/Fire.png") );
//		m_pSun->setPosition(ccp(45, size.height/2));
//		m_pSun->setStartSize(110);
	
		bRet = true;
	}
	while(0);

	return bRet;
}

void CGameLevel::SwitchToPrevScene()
{
    CGameEvents::startFlipInterface(GAME_MENU);
}

void CGameLevel::OpenBuyPowerLayer()
{
    if (!mBuyPowerLayer)
    {
        mBuyPowerLayer = (BuyPowerLayer*)CCBManager::LoadCCBByNameAndLoader("BuyPowerLayer", BuyPowerLayerLoader::loader());
        addChild(mBuyPowerLayer);
        mBuyPowerLayer->SetDelegate(this);
    }
    
    ShowLayer(mBuyPowerLayer);
}

void CGameLevel::OpenBuyDiamondLayer()
{
    if (!mBuyDiamondLayer)
    {
        mBuyDiamondLayer = (BuyDiamondLayer*)CCBManager::LoadCCBByNameAndLoader("BuyDiamondLayer", BuyDiamondLayerLoader::loader());
        addChild(mBuyDiamondLayer);
        mBuyDiamondLayer->SetDelegate(this);
    }
    
    ShowLayer(mBuyDiamondLayer);
    
}

void CGameLevel::OpenGiftLayer()
{
    CCLog("OpenGiftLayer");
}

void CGameLevel::OpenUpgradeLayer()
{
    if (!mUpgradeLayer)
    {
        CCArray * ccbNameArr = CCArray::create();
        CCArray * loaderArr = CCArray::create();
        
        ccbNameArr->addObject(CCString::create("UpgradeLayer"));
        ccbNameArr->addObject(CCString::create("PlaneDisplayLayer"));
        ccbNameArr->addObject(CCString::create("PlanAttributeLayer"));
        ccbNameArr->addObject(CCString::create("MenuTopBarLayer"));
        
        
        loaderArr->addObject(UpgradeLayerLoader::loader());
        loaderArr->addObject(PlaneDisplayLayerLoader::loader());
        loaderArr->addObject(PlanAttributeLayerLoader::loader());
        loaderArr->addObject(MenuTopBarLayerLoader::loader());
        
        mUpgradeLayer = (UpgradeLayer*)CCBManager::LoadCCBByNameAndLoader(ccbNameArr, loaderArr);
        mUpgradeLayer->SetDelegate(this);
        addChild(mUpgradeLayer);
        
    }
    ShowLayer(mUpgradeLayer);
}

void CGameLevel::setLevelMode(CCObject* pSender)
{
    g_iGameLevel = pSender->m_uID;
    CGameEvents::startFlipInterface(GAME_START);
//	g_iGameLevel = pSender->m_uID;
//	CCSize size = CCDirector::sharedDirector()->getWinSize();
//	switch(g_iGameLevel)
//	{
//	case LEVEL_ONE:
//		m_pSun->setPosition(ccp(45, size.height/2));
//		break;
//	case LEVEL_TWO:
//		m_pSun->setPosition(ccp(size.width/2, size.height - 100));
//		break;
//	case LEVEL_THREE:
//		m_pSun->setPosition(ccp(size.width - 45, size.height/2));
//		break;
//	default:
//		break;
//	}
}

void CGameLevel::setLevelStart(CCObject* pSender)
{
	CGameEvents::startFlipInterface(GAME_START);
}



void CGameLevel::CCBLevelCallBack(CCObject *pSender)
{
    g_iGameLevel = pSender->m_uID;
    CGameEvents::startFlipInterface(GAME_START);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    switch(g_iGameLevel)
    {
            
//        case LEVEL_ONE:
//            m_pSun->setPosition(ccp(45, size.height/2));
//            break;
//        case LEVEL_TWO:
//            m_pSun->setPosition(ccp(size.width/2, size.height - 100));
//            break;
//        case LEVEL_THREE:
//            m_pSun->setPosition(ccp(size.width - 45, size.height/2));
//            break;
//        default:
//            break;
    }
}

void CGameLevel::InitBottomLayer()
{
    
    CCArray * ccbNameArr = CCArray::create();
    CCArray * loaderArr = CCArray::create();
    
    ccbNameArr->addObject(CCString::create("LevelBottomLayer"));
    ccbNameArr->addObject(CCString::create("MenuTopBarLayer"));
    
    loaderArr->addObject(LevelBottomLayerLoader::loader());
    loaderArr->addObject(MenuTopBarLayerLoader::loader());
    
    LevelBottomLayer * layer = (LevelBottomLayer*)CCBManager::LoadCCBByNameAndLoader(ccbNameArr, loaderArr);
    layer->SetDelegate(this);
    addChild(layer);
    ShowLayer(layer);
}

