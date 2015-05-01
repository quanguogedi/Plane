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
        
        if (DataManager::GetInstance()->GetLevelState())
        {
            DataManager::GetInstance()->SetLevelState(false);
            OpenUpgradeLayer();
            
        }
	
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

void CGameLevel::OpenGiftBagLayer()
{
    if (!mGiftBagLayer)
    {
        mGiftBagLayer = (GiftBagLayer*)CCBManager::LoadCCBByNameAndLoader("GiftBagLayer", GiftBagLayerLoader::loader());
        mGiftBagLayer->SetDelegate(this);
        addChild(mGiftBagLayer);
        
    }
    
    ShowLayer(mGiftBagLayer);
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
//    g_iGameLevel = pSender->m_uID;
    CGameEvents::startFlipInterface(GAME_START);
}

void CGameLevel::setLevelStart(CCObject* pSender)
{
	CGameEvents::startFlipInterface(GAME_START);
}



void CGameLevel::CCBLevelCallBack(CCObject *pSender)
{
//    g_iGameLevel = pSender->m_uID;
    CGameEvents::startFlipInterface(GAME_START);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
//    switch(g_iGameLevel)
//    {
//            
////        case LEVEL_ONE:
////            m_pSun->setPosition(ccp(45, size.height/2));
////            break;
////        case LEVEL_TWO:
////            m_pSun->setPosition(ccp(size.width/2, size.height - 100));
////            break;
////        case LEVEL_THREE:
////            m_pSun->setPosition(ccp(size.width - 45, size.height/2));
////            break;
////        default:
////            break;
//    }
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


void CGameLevel::OpenStartGameLayer()
{
    if (!mStartGameLayer)
    {
        mStartGameLayer = (StartGameLayer*)CCBManager::LoadCCBByNameAndLoader("StartGameLayer", StartGameLayerLoader::loader());
        mStartGameLayer->SetDelegate(this);
        addChild(mStartGameLayer);
        
    }
    ShowLayer(mStartGameLayer);
}

