

#include "GameMenu.h"
#include "GameEvents.h"

CCScene* CGameMenu::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        CGameMenu *layer = CGameMenu::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CGameMenu::init()
{
    bool bRet = false;
    do{
        
		CC_BREAK_IF(! CBaseScene::init());
        InitBackGround();
        InitBottomLayer();
        InitDisPlayLayer();
        
		bRet = true;
	}
	while(0);

    return bRet;
}
void CGameMenu::OpenBuyPowerLayer()
{
    if (!mBuyPowerLayer)
    {
        mBuyPowerLayer = (BuyPowerLayer*)CCBManager::LoadCCBByNameAndLoader("BuyPowerLayer", BuyPowerLayerLoader::loader());
        mBuyPowerLayer->SetDelegate(this);
        addChild(mBuyPowerLayer);
        
    }
    
    ShowLayer(mBuyPowerLayer);
}

void CGameMenu::OpenBuyDiamondLayer()
{
    if (!mBuyDiamondLayer)
    {
        mBuyDiamondLayer = (BuyDiamondLayer*)CCBManager::LoadCCBByNameAndLoader("BuyDiamondLayer", BuyDiamondLayerLoader::loader());
         mBuyDiamondLayer->SetDelegate(this);
        addChild(mBuyDiamondLayer);
       
    }
    
    ShowLayer(mBuyDiamondLayer);
    
}



void CGameMenu::OpenBuyDiamondSureLayer()
{
    CCLog("OpenBuyDiamonSureLayer");

}

void CGameMenu::OpenGiftLayer()
{
    CCLog("OpenGiftLayer");
}

void CGameMenu::OpenUpgradeLayer()
{
    if (!mUpgradeLayer)
    {
        CCArray * ccbNameArr = CCArray::create();
        CCArray * loaderArr = CCArray::create();
        
        ccbNameArr->addObject(CCString::create("UpgradeLayer"));
        ccbNameArr->addObject(CCString::create("PlanAttributeLayer"));
        ccbNameArr->addObject(CCString::create("MenuTopBarLayer"));

        
        loaderArr->addObject(UpgradeLayerLoader::loader());
        loaderArr->addObject(PlanAttributeLayerLoader::loader());
        loaderArr->addObject(MenuTopBarLayerLoader::loader());
        
        mUpgradeLayer = (UpgradeLayer*)CCBManager::LoadCCBByNameAndLoader(ccbNameArr, loaderArr);
        mUpgradeLayer->SetDelegate(this);
        addChild(mUpgradeLayer);
        
    }
    ShowLayer(mUpgradeLayer);
}

void CGameMenu::OpenAchievementLayer()
{
    if (!mAchievementLayer)
    {
        mAchievementLayer = (AchievementLayer*)CCBManager::LoadCCBByNameAndLoader("AchievementLayer", AchievementLayerLoader::loader());
        mAchievementLayer->SetDelegate(this);
        addChild(mAchievementLayer);
    }
    ShowLayer(mAchievementLayer);
}

void CGameMenu::OpenSettingLayer()
{
    if (!mSettingsLayer) {
        mSettingsLayer = (SettingsLayer*)CCBManager::LoadCCBByNameAndLoader("SettingsLayer", SettingsLayerLoader::loader());
        mSettingsLayer->SetDelegate(this);
        addChild(mSettingsLayer);
    }
    ShowLayer(mSettingsLayer);
}

//////////////////////////////


void CGameMenu::InitBackGround()
{
    CCSize size = CCDirector::sharedDirector()->getWinSize();
//    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("res/Resources/ui_beijing.plist", "res/Resources/ui_beijing.png");
    
    mBgSprite1 = CCSprite::create("res/ui_bj_01.png");
    mBgSprite1->setScale(size.height/mBgSprite1->getContentSize().height);
    mBgSprite1->setPosition(ccp(size.width/2, size.height/2));
    addChild(mBgSprite1);
    
    
    mBgSprite2 = CCSprite::create("res/ui_bj_01.png");
    mBgSprite2->setScale(size.height/mBgSprite2->getContentSize().height);    mBgSprite2->setPosition(ccp(size.width/2, -size.height/2));
    mBgSprite2->setFlipY(true);
    addChild(mBgSprite2);
}

//void CGameMenu::InitTopLayer()
//{
//    MenuTopBarLayer * layer = (MenuTopBarLayer*)CCBManager::LoadCCBByNameAndLoader("MenuTopBarLayer", MenuTopBarLayerLoader::loader());
//    layer->SetDelegate(this);
//    addChild(layer);
//}


void CGameMenu::InitBottomLayer()
{
    CCArray * ccbNameArr = CCArray::create();
    CCArray * loaderArr = CCArray::create();
    
    ccbNameArr->addObject(CCString::create("MenuBottomLayer"));
    ccbNameArr->addObject(CCString::create("PlanAttributeLayer"));
    ccbNameArr->addObject(CCString::create("MenuTopBarLayer"));
    
    loaderArr->addObject(MenuBottomLayerLoader::loader());
    loaderArr->addObject(PlanAttributeLayerLoader::loader());
    loaderArr->addObject(MenuTopBarLayerLoader::loader());
    
    MenuBottomLayer * layer = (MenuBottomLayer*)CCBManager::LoadCCBByNameAndLoader(ccbNameArr, loaderArr);
    layer->SetDelegate(this);
    addChild(layer);
    ShowLayer(layer);
}
void CGameMenu::InitDisPlayLayer()
{
    PlaneDisplayLayer * layer = (PlaneDisplayLayer*)CCBManager::LoadCCBByNameAndLoader("PlaneDisplayLayer", PlaneDisplayLayerLoader::loader());
    layer->SetDelegate(this);
    addChild(layer);
}




