//
//  GiftBagLayer.cpp
//  Plane
//
//  Created by 杨延飞 on 15/5/1.
//
//

#include "GiftBagLayer.h"


bool GiftBagLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    
    mIsTheDialog = true;
    mTouchLevel = 1;
    return true;
}

bool GiftBagLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    return false;
}

SEL_MenuHandler GiftBagLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "FastGetSelector", GiftBagLayer::FastGetSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "CloseSelector", GiftBagLayer::CloseSelector);
    
    return false;
}


//////////////////////////


void GiftBagLayer::FastGetSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
 
}


void GiftBagLayer::CloseSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->HideLayer();
    }
}
