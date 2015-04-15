//
//  AchievementCell.cpp
//  Plane
//
//  Created by KGB on 15/3/25.
//
//

#include "AchievementCell.h"


bool AchievementCell::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "nameLabel", CCLabelTTF*, mNameLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "descLabel", CCLabelTTF*, mDescLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "resultLabel", CCLabelTTF*, mResultLabel);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "progressNode",  CCNode*, mProgressNode);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "progressLabel", CCLabelTTF*, mProgressLabel);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "getNode",  CCNode*, mGetNode);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "finishedNode", CCNode*, mFinishedNode);
 
    return false;
}

SEL_MenuHandler AchievementCell::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "OnTouchGetResultButton", AchievementCell::OnTouchGetResultButton);
    return false;
}

SEL_CCControlHandler AchievementCell::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    
    return false;
}

void AchievementCell::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    
}

//////////////////

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

void AchievementCell::OnTouchGetResultButton(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    
}
