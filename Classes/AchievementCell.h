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
    
    virtual void onEnter();
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    void GetSelector(CCObject *pSender, CCControlEvent pCCControlEvent);

public:
    void SetCell(PrototypeAchievementData* data);
    
    
private:
    CCLabelTTF* mNameLabel;
    CCLabelTTF* mDescLabel;
    CCLabelTTF* mResultLabel;
    CCLabelTTF* mProgressLabel;
    
    CCSprite * mFinishSprite;
    CCSprite * mProgressSprite;
    CCSprite * mProgressBar;
};


class AchievementCellLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(AchievementCellLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(AchievementCell);
};

#endif /* defined(__Plane__AchievementCell__) */
