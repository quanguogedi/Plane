//
//  UpgradeLayer.cpp
//  Plane
//
//  Created by ml on 15-1-19.
//
//

#include "UpgradeLayer.h"
#include "CCBManager.h"
#include "PlaneNotification.h"

bool UpgradeLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    
    mCurrentTab = 1;
    return true;
}

bool UpgradeLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{

    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ValueLabel", CCLabelTTF*, mValueLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "NameLabel", CCLabelTTF*, mNameLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DiamondLabel", CCLabelTTF*, mDiamondLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DiscLabel", CCLabelTTF*, mDiscLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Sign", CCSprite*, mSign);
    
    return false;
}

SEL_MenuHandler UpgradeLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "ChooseTargetSelector", UpgradeLayer::ChooseTargetSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "UpgradeSelector", UpgradeLayer::UpgradeSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "BackSelector", UpgradeLayer::BackSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "UpgradeMaxSelector", UpgradeLayer::UpgradeMaxSelector);
    return NULL;
}


////////////////////////////

void UpgradeLayer::RefreshUI()
{
    UpgradeData * data = DataManager::GetInstance()->GetUpgradeData(mCurrentTab);
    mNameLabel->setString(data->mName);
    mDiscLabel->setString(data->mDisc);
    mDiamondLabel->setString(CCString::createWithFormat("%d",data->mUpCost)->getCString());
    if (data->mIsCanUp)
    {
        mValueLabel->setString(CCString::createWithFormat("%d>%d",data->mCurrValue,data->mNextValue)->getCString());
//        mDiamondLabel->setString(CCString::createWithFormat("%d",data->mUpCost)->getCString());
    }else
    {
        mValueLabel->setString("MAX");
//        mDiamondLabel->setString(CCString::createWithFormat("%d",data->mUpCost)->getCString());
    }
    
    
    mDiamondLabel->setString(CCString::createWithFormat("%d",data->mUpCost)->getCString());
    
    
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REFRESH_PLANATTRIBUTE,CCString::createWithFormat("%d",mCurrentTab));
}


void UpgradeLayer::ChooseTargetSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCMenuItem* button = (CCMenuItem*)pSender;
    mSign->setPosition(button->getPosition());
    mCurrentTab = button->getTag();
    RefreshUI();
}

void UpgradeLayer::UpgradeSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
//    CCLog("Upgrade tab = %d", mCurrentTab);
//    int currentPlane = GameDataManager::GetSingleton().GetCurrentPlane();
//    
//    GameDataManager::GetSingleton().PlaneUpgrade(currentPlane, mCurrentTab);
    DataManager::GetInstance()->SavaUpgradeData(mCurrentTab);
    RefreshUI();
}

void UpgradeLayer::BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if(mDelegate)
    {
        mDelegate->HideLayer();
    }
}

void UpgradeLayer::UpgradeMaxSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLog("UpgradeMax tab = %d", mCurrentTab);
    DataManager::GetInstance()->SavaUpgradeData(mCurrentTab,true);
    RefreshUI();
}

/////////////////////////////////////

/////////////////////////////////////////////



