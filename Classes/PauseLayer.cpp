//
//  PauseLayer.cpp
//  Plane
//
//  Created by 杨延飞 on 15/4/23.
//
//

#include "PauseLayer.h"

#include "GameEvents.h"
bool PauseLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    mIsTheDialog = true;
    mTouchLevel = 1;
    return true;
}

bool PauseLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    return false;
}

SEL_MenuHandler PauseLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "StartSelector", StartGameLayer::StartSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "CloseSelector", StartGameLayer::CloseSelector);
    
    return false;
}

void PauseLayer::RefreshUI()
{
    
}

void PauseLayer::StartSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CGameEvents::startFlipInterface(GAME_START);
}

void PauseLayer::CloseSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->HideLayer();
    }
}