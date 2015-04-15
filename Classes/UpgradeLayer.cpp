//
//  UpgradeLayer.cpp
//  Plane
//
//  Created by ml on 15-1-19.
//
//

#include "UpgradeLayer.h"
#include "GameData.h"
#include "PrototypeDataManager.h"
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
    int currentPlaneType = GameDataManager::GetSingleton().GetCurrentPlane();
    PlayerPlaneData* planeData = GameDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType);
    
    char strNum[16];
    //
    int attack = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mAttackLevel)->mAttack;
    //    sprintf(strNum, "%d", attack);
    //    mAtk1Label->setString(strNum);
    //
    int subMissileAttack = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mSubMissileAttackLevel)->mSubMissileAttack;
    //    sprintf(strNum, "%d", subMissileAttack);
    //    mAtk2Label->setString(strNum);
    //
    int hp = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mPlaneHPLevel)->mPlaneHP;
    //    sprintf(strNum, "%d", hp);
    //    mHPLabel->setString(strNum);
    //
    int wingAgttack = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mWingAttackLevel)->mWingAttack;
    //    sprintf(strNum, "%d", wingAgttack);
    //    mAtk3Label->setString(strNum);
    //
    int fight = attack + subMissileAttack + hp + wingAgttack;
    //    sprintf(strNum, "%d", fight);
    //    mFightPointLabel->setString(strNum);
    
    int stautsValue = 0;
    int stautsNextLevelValue = 0;
    switch (mCurrentTab)
    {
        case 1:
        {
            stautsValue = attack;
            PrototypePlaneData* nextLevelData = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mAttackLevel + 1);
            if(nextLevelData)
            {
                stautsNextLevelValue = nextLevelData->mAttack;
            }
        }
            break;
        case 2:
        {
            stautsValue = subMissileAttack;
            PrototypePlaneData* nextLevelData = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mSubMissileAttackLevel + 1);
            if(nextLevelData)
            {
                stautsNextLevelValue = nextLevelData->mSubMissileAttack;
            }
        }
            break;
        case 3:
        {
            stautsValue = hp;
            PrototypePlaneData* nextLevelData = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mPlaneHPLevel + 1);
            if(nextLevelData)
            {
                stautsNextLevelValue = nextLevelData->mPlaneHP;
            }
        }
            break;
        case 4:
        {
            stautsValue = wingAgttack;
            PrototypePlaneData* nextLevelData = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mWingAttackLevel + 1);
            if(nextLevelData)
            {
                stautsNextLevelValue = nextLevelData->mWingAttack;
            }
        }
            break;
        default:
            break;
    }
    
    if (stautsNextLevelValue)
    {
        sprintf(strNum, "%d->%d", stautsValue, stautsNextLevelValue);
    }
    else
    {
        sprintf(strNum, "MAX");
    }
    
    mValueLabel->setString(strNum);
    
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
    CCLog("Upgrade tab = %d", mCurrentTab);
    int currentPlane = GameDataManager::GetSingleton().GetCurrentPlane();
    
    GameDataManager::GetSingleton().PlaneUpgrade(currentPlane, mCurrentTab);
    
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
}

/////////////////////////////////////

/////////////////////////////////////////////



