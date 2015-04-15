//
//  SecondSelector.cpp
//  Plane
//
//  Created by 杨延飞 on 14-11-23.
//
//

#include "SecondLayer.h"
#include "CCBManager.h"
#include "GameEvents.h"

//#include "UpgradePlaneDataLayer.h"

SecondLayer::~SecondLayer()
{
    CC_SAFE_RELEASE(mPower);
    
}
bool SecondLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Power", CCSprite*, mPower);
    return false;
}

SEL_MenuHandler SecondLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "AddPowerSelector",SecondLayer::AddPowerSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "DepotSelector", SecondLayer::DepotSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "BackSelector", SecondLayer::BackSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "BossSelector", SecondLayer::BossSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "CopterSelector", SecondLayer::CopterSelector);
    return NULL;
}

SEL_CCControlHandler SecondLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

void SecondLayer::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
//    UpgradePlaneDataLayer* mUpgradePlaneDataLayer = (UpgradePlaneDataLayer*)CCBManager::LoadCCBByNameAndLoader("UpgradePlaneDataLayer", UpgradePlaneDataLayerLoader::loader());
//    mUpgradePlaneDataLayer->RefreshUI();
//    
//    addChild(mUpgradePlaneDataLayer);
}

void SecondLayer::onEnter()
{
    CCBLayer::onEnter();
    
}
void SecondLayer::onExit()
{
    CCBLayer::onExit();
}

void SecondLayer::AddPowerSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLog("SecondLayer::AddPowerSelector()");
}
void SecondLayer::DepotSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLog("SecondLayer::DepotSelector()");
}
void SecondLayer::BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CGameEvents::startFlipInterface(GAME_MENU);
}
void SecondLayer::BossSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLog("SecondLayer::BossSelector()");
}
void SecondLayer::CopterSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLog("SecondLayer::CopterSelector()");
}
