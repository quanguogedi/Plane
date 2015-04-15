//
//  FourthLayer.h
//  Plane
//
//  Created by 杨延飞 on 14-11-23.
//
//

#ifndef __Plane__FourthLayer__
#define __Plane__FourthLayer__

#include "CCBLayer.h"

class FourthLayer:public CCBLayer
{
public:
    CREATE_FUNC(FourthLayer);
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
    void ContinueSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    
    
private:
    ~FourthLayer();
};



class FourthLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(FourthLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(FourthLayer);
};
#endif /* defined(__Plane__FourthLayer__) */
