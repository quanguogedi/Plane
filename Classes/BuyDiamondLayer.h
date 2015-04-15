//
//  BuyDiamondLayer.h
//  Plane
//
//  Created by 姜彬彬 on 4/10/15.
//
//

#ifndef __Plane__BuyDiamondLayer__
#define __Plane__BuyDiamondLayer__
#include "CCBLayer.h"

class BuyDiamondLayer : public CCBLayer
{
public:
    virtual bool init();
    CREATE_FUNC(BuyDiamondLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
private:
    CCLabelTTF * mDiscLabel1;
    CCLabelTTF * mDiscLabel2;
    CCLabelTTF * mDiscLabel3;
    
    
    void GetDiamondSelecor(CCObject *pSender, CCControlEvent pCCControlEvent);
    void GiftSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    
};


class BuyDiamondLayerLoader : public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BuyDiamondLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(BuyDiamondLayer);
};

#endif /* defined(__Plane__BuyDiamondLayer__) */
