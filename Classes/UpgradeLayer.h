//
//  UpgradeLayer.h
//  Plane
//
//  Created by ml on 15-1-19.
//
//

#ifndef __Plane__UpgradeLayer__
#define __Plane__UpgradeLayer__

#include "CCBLayer.h"

//#include "UpgradePlaneDataLayer.h"




class UpgradeLayer : public CCBLayer
{
public:
    virtual bool init();
    CREATE_FUNC(UpgradeLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual void RefreshUI();
    
    void RefreshValue();
    void RefreshDisc();
    
    
    void UpgradeSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void UpgradeMaxSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void ChooseTargetSelector(CCObject *pSender, CCControlEvent pCCControlEvent);

    
private:
    CCLabelTTF* mValueLabel;
    CCLabelTTF* mNameLabel;
    CCLabelTTF* mDiamondLabel;
    CCLabelTTF* mDiscLabel;
    CCSprite * mBgSprite;
    CCSprite * mSign;
    CCMenu * mTargetMenu;
    int mCurrentTab;
};

class UpgradeLayerLoader : public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(UpgradeLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(UpgradeLayer);
};

#endif /* defined(__Plane__UpgradeLayer__) */
