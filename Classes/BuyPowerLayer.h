//
//  BuyPowerLayer.h
//  Plane
//
//  Created by 姜彬彬 on 4/11/15.
//
//

#ifndef __Plane__BuyPowerLayer__
#define __Plane__BuyPowerLayer__

#include "CCBLayer.h"

class BuyPowerLayer : public CCBLayer
{
public:
    
    virtual bool init();
    CREATE_FUNC(BuyPowerLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    void GetPowerSelecor(CCObject *pSender, CCControlEvent pCCControlEvent);
    void GiftSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
private:
    
    CCLabelTTF * mDiscLabel1;
    CCLabelTTF * mDiscLabel2;
    CCLabelTTF * mDiscLabel3;
    
};


class BuyPowerLayerLoader : public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BuyPowerLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(BuyPowerLayer);
};

#endif /* defined(__Plane__BuyPowerLayer__) */
