//
//  AchievementCell.h
//  Plane
//
//  Created by KGB on 15/3/25.
//
//

#ifndef __Plane__AchievementCell__
#define __Plane__AchievementCell__

#include "CCBLayer.h"
#include "PrototypeDataManager.h"

class AchievementCell : public CCBLayer
{
public:
    CREATE_FUNC(AchievementCell);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);

public:
    void SetCell(PrototypeAchievementData* data);
    
private:
    void OnTouchGetResultButton(CCObject *pSender, CCControlEvent pCCControlEvent);
    
private:
    CCLabelTTF* mNameLabel;
    CCLabelTTF* mDescLabel;
    CCLabelTTF* mResultLabel;
    
    CCNode* mProgressNode;
    CCLabelTTF* mProgressLabel;
    
    CCNode* mGetNode;
    
    CCNode* mFinishedNode;
};


class AchievementCellLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(AchievementCellLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(AchievementCell);
};

#endif /* defined(__Plane__AchievementCell__) */
