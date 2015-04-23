//
//  MenuTopBarLayer.cpp
//  Plane
//
//  Created by KGB on 15/3/23.
//
//

#include "MenuTopBarLayer.h"


void MenuTopBarLayer::onEnter()
{
    CCBLayer::onEnter();
    
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(MenuTopBarLayer::RefreshPower),REFRESH_POWER, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(MenuTopBarLayer::RefreshDiamond), REFRESH_DIAMOND, NULL);
}

void MenuTopBarLayer::onExit()
{
    CC_SAFE_RELEASE(mTimeLabel);
    CC_SAFE_RELEASE(mPowerLabel);
    CC_SAFE_RELEASE(mDiamondLabel);
    
    
    CCBLayer::onExit();
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, REFRESH_POWER);
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, REFRESH_DIAMOND);
}

bool MenuTopBarLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "TimeLabel", CCLabelBMFont*, mTimeLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "PowerLabel", CCLabelBMFont*, mPowerLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DiamondLabel", CCLabelBMFont*, mDiamondLabel);
    
    return false;
}

SEL_MenuHandler MenuTopBarLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "AddPowerSelector", MenuTopBarLayer::AddPowerSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "AddDiamondSelector", MenuTopBarLayer::AddDiamondSelector);
    
    return false;
}


void MenuTopBarLayer::RefreshUI()
{
    RefreshPower();
    RefreshDiamond();
}
/////////////////////////

void MenuTopBarLayer::AddPowerSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->OpenBuyPowerLayer();
    }
}

void MenuTopBarLayer::AddDiamondSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->OpenBuyDiamondLayer();
    }
}


void MenuTopBarLayer::RefreshPower()
{
//    int currPower = GameDataManager::GetInstance()->GetCurrentPower();
//    int maxPower = GameDataManager::GetInstance()->GetMaxPower();
    
////    CCString * str = CCString::createWithFormat("%d/%d",currPower,maxPower);
//    CCString * str = CCString::createWithFormat("%d",currPower);
//    mPowerLabel->setString(str->getCString());
}

void MenuTopBarLayer::RefreshDiamond()
{
    int diamond = LocalArchiveData::GetInstance()->mDiamondCount;
    
    CCString * str = CCString::createWithFormat("%d",diamond);
    mDiamondLabel->setString(str->getCString());
}

void MenuTopBarLayer::UpdateTime(float _time)
{
    int time = 180;
    int fen = time/60;
    int miao = time%60;
    CCString * str = CCString::createWithFormat("%02d:%02d",fen,miao);
    mTimeLabel->setString(str->getCString());
}



















