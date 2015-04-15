//
//  BuyPowerLayer.cpp
//  Plane
//
//  Created by 姜彬彬 on 4/11/15.
//
//

#include "BuyPowerLayer.h"

bool BuyPowerLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    
    mIsTheDialog = true;
    mTouchLevel = 1;
    return true;
}

bool BuyPowerLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DiscLabel1", CCLabelTTF*, mDiscLabel1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DiscLabel2", CCLabelTTF*, mDiscLabel2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DiscLabel3", CCLabelTTF*, mDiscLabel3);
    return false;
}

SEL_MenuHandler BuyPowerLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "GetPowerSelecor", BuyPowerLayer::GetPowerSelecor);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "GiftSelector", BuyPowerLayer::GiftSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "BackSelector", BuyPowerLayer::BackSelector);
    
    return false;
}


//////////////////////////


void BuyPowerLayer::GetPowerSelecor(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->OpenBuyDiamondSureLayer();
    }
    
    
    //    int tag = ((CCMenuItem*)pSender)->getTag();
    //
    //    CCLog("DiamondShopLayer::OnTouchGetDiamondButton tag = %d", tag);
}

void BuyPowerLayer::GiftSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->OpenGiftLayer();
    }
}

void BuyPowerLayer::BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->HideLayer();
    }
}
