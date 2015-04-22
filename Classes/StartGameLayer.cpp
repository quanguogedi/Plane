//
//  StartGameLayer.cpp
//  Plane
//
//  Created by 姜彬彬 on 4/22/15.
//
//

#include "StartGameLayer.h"
#include "GameEvents.h"
bool StartGameLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    mIsTheDialog = true;
    mTouchLevel = 1;
    return true;
}

bool StartGameLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    return false;
}

SEL_MenuHandler StartGameLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "StartSelector", StartGameLayer::StartSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "CloseSelector", StartGameLayer::CloseSelector);
    
    return false;
}

void StartGameLayer::RefreshUI()
{
    
}

void StartGameLayer::StartSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CGameEvents::startFlipInterface(GAME_START);
}

void StartGameLayer::CloseSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->HideLayer();
    }
}










