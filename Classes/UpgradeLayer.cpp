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
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "BgSprite", CCSprite*, mBgSprite);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Sign", CCSprite*, mSign);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "TargetMenu", CCMenu*, mTargetMenu);
    
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
    RefreshDisc();

    for (int i = 1; i < 5; i ++)
    {
        CCNode * node = mBgSprite->getChildByTag(i);

        UpgradeData * data =DataManager::GetInstance()->GetUpgradeData(i);
        
        //更改贴图
        CCMenuItemImage * item = (CCMenuItemImage*)mTargetMenu->getChildByTag(i);
        item->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(data->mSmallFile));
        
        for (int j = 1; j < data->mCurrLevel; j++)
        {
            CCSprite * sp = (CCSprite*)node->getChildByTag(j);
            sp->setVisible(true);
        }
    }
}

void UpgradeLayer::RefreshValue()
{
    CCNode * node = mBgSprite->getChildByTag(mCurrentTab);
    UpgradeData * data = DataManager::GetInstance()->GetUpgradeData(mCurrentTab);

    for (int i = 1; i < data->mCurrLevel; i++)
    {
        CCSprite * sp = (CCSprite*)node->getChildByTag(i);
        sp->setVisible(true);
    }
    
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REFRESH_PLANATTRIBUTE,CCString::createWithFormat("%d",mCurrentTab));
 
}



void UpgradeLayer::RefreshDisc()
{
    UpgradeData * data = DataManager::GetInstance()->GetUpgradeData(mCurrentTab);
    if (data)
    {
        mNameLabel->setString(data->mName);
        mDiscLabel->setString(data->mDisc);
        mDiamondLabel->setString(CCString::createWithFormat("%d",data->mUpCost)->getCString());
        if (data->mIsCanUp)
        {
            mValueLabel->setString(CCString::createWithFormat("%d>%d",data->mCurrValue,data->mNextValue)->getCString());
        }else
        {
            mValueLabel->setString("MAX");
        }
    }
    
}


void UpgradeLayer::ChooseTargetSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCMenuItem* button = (CCMenuItem*)pSender;
    mSign->setPosition(button->getPosition());
    mCurrentTab = button->getTag();
    
    RefreshDisc();
}

void UpgradeLayer::UpgradeSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{

    UpgradeData * data = DataManager::GetInstance()->GetUpgradeData(mCurrentTab);
    
    if (data->mIsCanUp)
    {
        DataManager::GetInstance()->SavaUpgradeData(mCurrentTab);
        RefreshDisc();
        RefreshValue();
        
    }else
    {
        CCLog("已经升至满级");
    }
}

void UpgradeLayer::UpgradeMaxSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    
    UpgradeData * data = DataManager::GetInstance()->GetUpgradeData(mCurrentTab);
    
    if (data->mIsCanUp)
    {
        DataManager::GetInstance()->SavaUpgradeData(mCurrentTab,true);
        RefreshDisc();
        RefreshValue();
        
    }else
    {
        CCLog("已经升至满级");
    }
    CCLog("UpgradeMax tab = %d", mCurrentTab);
    
}


void UpgradeLayer::BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if(mDelegate)
    {
        mDelegate->HideLayer();
    }
}



/////////////////////////////////////

/////////////////////////////////////////////



