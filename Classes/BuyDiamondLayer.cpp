//
//  BuyDiamondLayer.cpp
//  Plane
//
//  Created by 姜彬彬 on 4/10/15.
//
//

#include "BuyDiamondLayer.h"

bool BuyDiamondLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    
    mIsTheDialog = true;
    mTouchLevel = 1;
    return true;
}

bool BuyDiamondLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DiscLabel1", CCLabelTTF*, mDiscLabel1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DiscLabel2", CCLabelTTF*, mDiscLabel2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DiscLabel3", CCLabelTTF*, mDiscLabel3);
    return false;
}

SEL_MenuHandler BuyDiamondLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "GetDiamondSelecor", BuyDiamondLayer::GetDiamondSelecor);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "GiftSelector", BuyDiamondLayer::GiftSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "BackSelector", BuyDiamondLayer::BackSelector);
    
    return false;
}


//////////////////////////

void BuyDiamondLayer::GetDiamondSelecor(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->OpenBuyDiamondSureLayer();
    }
    
    
//    int tag = ((CCMenuItem*)pSender)->getTag();
//    
//    CCLog("DiamondShopLayer::OnTouchGetDiamondButton tag = %d", tag);
}

void BuyDiamondLayer::GiftSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->OpenGiftBagLayer();
    }
}

void BuyDiamondLayer::BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->HideLayer();
    }
}