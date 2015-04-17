//
//  AchievementCell.cpp
//  Plane
//
//  Created by KGB on 15/3/25.
//
//

#include "AchievementCell.h"

void AchievementCell::onEnter()
{
    CCBLayer::onEnter();
    mMenu->setTouchPriority(-133);
}

bool AchievementCell::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "NameLabel", CCLabelTTF*, mNameLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DescLabel", CCLabelTTF*, mDescLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ResultLabel", CCLabelTTF*, mResultLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ProgressLabel", CCLabelTTF*, mProgressLabel);

    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "FinishSprite",  CCSprite*, mFinishSprite);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ProgressSprite",  CCSprite*, mProgressSprite);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ProgressBar",  CCSprite*, mProgressBar);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu",  CCMenu*, mMenu);
    
 
    return false;
}

SEL_MenuHandler AchievementCell::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "GetSelector", AchievementCell::GetSelector);
    return false;
}

void AchievementCell::SetCell(PrototypeAchievementData* data)
{
    mNameLabel->setString(data->mName);
    mDescLabel->setString(data->mDesc);
    
    char result[64];
    sprintf(result, "%d", data->mResultDiamond);
    mResultLabel->setString(result);
    
    char num[64];
    sprintf(num, "X/%d", data->mConditionNum);
    mProgressLabel->setString(num);
}

/////////////////////

void AchievementCell::GetSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLog("AchievementCell  get selector");
}
