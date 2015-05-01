//
//  GiftBagLayer.h
//  Plane
//
//  Created by 杨延飞 on 15/5/1.
//
//

#ifndef __Plane__GiftBagLayer__
#define __Plane__GiftBagLayer__

#include "CCBLayer.h"

class GiftBagLayer : public CCBLayer
{
public:
    
    virtual bool init();
    CREATE_FUNC(GiftBagLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    void FastGetSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void CloseSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
private:
    
    
};


class GiftBagLayerLoader : public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GiftBagLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GiftBagLayer);
};

#endif /* defined(__Plane__GiftBagLayer__) */
