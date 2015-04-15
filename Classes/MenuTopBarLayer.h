//
//  MenuTopBarLayer.h
//  Plane
//
//  Created by KGB on 15/3/23.
//
//

#ifndef __Plane__MenuTopBarLayer__
#define __Plane__MenuTopBarLayer__

#include "CCBLayer.h"

class MenuTopBarLayer : public CCBLayer
{
public:
    virtual void onEnter();
    virtual void onExit();
    CREATE_FUNC(MenuTopBarLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void RefreshUI();
 
    void AddPowerSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void AddDiamondSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    
    
    void RefreshPower();
    void RefreshDiamond();
    void UpdateTime(float _time);
    
private:
    CCLabelBMFont* mTimeLabel;
    CCLabelBMFont* mPowerLabel;
    CCLabelBMFont* mDiamondLabel;
};


class MenuTopBarLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuTopBarLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MenuTopBarLayer);
};

#endif /* defined(__Plane__MenuTopBarLayer__) */
