//
//  StartGameLayer.h
//  Plane
//
//  Created by 姜彬彬 on 4/22/15.
//
//

#ifndef __Plane__StartGameLayer__
#define __Plane__StartGameLayer__


#include "Common.h"
#include "CCBLayer.h"

class StartGameLayer : public CCBLayer
{
public:
    virtual bool init();
    CREATE_FUNC(StartGameLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void RefreshUI();
    
    void StartSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void CloseSelector(CCObject *pSender,CCControlEvent pCCControlEvent);

    
};


class StartGameLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(StartGameLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(StartGameLayer);
};

#endif /* defined(__Plane__StartGameLayer__) */
