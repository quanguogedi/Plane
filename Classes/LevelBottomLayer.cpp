//
//  LevelBottomLayer.cpp
//  Plane
//
//  Created by 姜彬彬 on 4/12/15.
//
//

#include "LevelBottomLayer.h"

bool LevelBottomLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    
    mIsTheLast = true;
    return true;
}

bool LevelBottomLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    return false;
}

SEL_MenuHandler LevelBottomLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "UpgradeSelector", LevelBottomLayer::UpgradeSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "GiftSelector", LevelBottomLayer::GiftSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "BackSelector", LevelBottomLayer::BackSelector);
    
    return false;
}


//////////////////////////

void LevelBottomLayer::UpgradeSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if(mDelegate)
    {
        mDelegate->OpenUpgradeLayer();
    }
}

void LevelBottomLayer::GiftSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->OpenGiftLayer();
    }
}

void LevelBottomLayer::BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->HideLayer();
    }
}
