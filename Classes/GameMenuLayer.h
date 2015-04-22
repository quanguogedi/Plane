//
//  GameMenuLayer.h
//  Plane
//
//  Created by 姜彬彬 on 4/22/15.
//
//

#ifndef __Plane__GameMenuLayer__
#define __Plane__GameMenuLayer__

#include "Common.h"
#include "CCBLayer.h"

class GameMenuLayer : public CCBLayer
{
public:
    virtual bool init();
    CREATE_FUNC(GameMenuLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void RefreshUI();
    
    void RefreshPropLabel();
    
    void PauseSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void ShieldSelector(CCObject *pSender,CCControlEvent pCCControlEvent);
    void KillerSelector(CCObject *pSender,CCControlEvent pCCControlEvent);
private:
    CCSprite * mHpSprite;
    CCLabelBMFont * mScoreLabel;
    CCLabelTTF * mKillerLabel;
    CCLabelTTF * mShieldLabel;
    
};


class GameMenuLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameMenuLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameMenuLayer);
};

#endif /* defined(__Plane__GameMenuLayer__) */
