//
//  MenuBottomLayer.cpp
//  Plane
//
//  Created by 杨延飞 on 14-11-22.
//
//


#include "MenuBottomLayer.h"
#include "GameEvents.h"

bool MenuBottomLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    
    mIsTheLast = true;
    
    return true;
}

bool MenuBottomLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Power", CCSprite*, mPower);
    return false;
}

SEL_MenuHandler MenuBottomLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "StartGameSelector", MenuBottomLayer::StartGameSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "ChallengeSelector", MenuBottomLayer::ChallengeSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "UpgradeSelector", MenuBottomLayer::UpgradeSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "AchievementSelector", MenuBottomLayer::AchievementSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "SettingSelector", MenuBottomLayer::SettingSelector);

    return NULL;
}


void MenuBottomLayer::StartGameSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CGameEvents::startFlipInterface(GAME_LEVEL);
}

void MenuBottomLayer::ChallengeSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLog("ChallengeSelector");
}


void MenuBottomLayer::UpgradeSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if(mDelegate)
    {
        mDelegate->OpenUpgradeLayer();
    }
}


void MenuBottomLayer::AchievementSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if(mDelegate)
    {
        mDelegate->OpenAchievementLayer();
    }
}

void MenuBottomLayer::SettingSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if(mDelegate)
    {
        mDelegate->OpenSettingLayer();
    }
}


