//
//  LevelBottomLayer.h
//  Plane
//
//  Created by 姜彬彬 on 4/12/15.
//
//

#ifndef __Plane__LevelBottomLayer__
#define __Plane__LevelBottomLayer__
#include "CCBLayer.h"

class LevelBottomLayer : public CCBLayer
{
public:
    virtual bool init();
    CREATE_FUNC(LevelBottomLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
private:
    void UpgradeSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//强化战机
    void GiftSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    
};


class LevelBottomLayerLoader : public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LevelBottomLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(LevelBottomLayer);
};

#endif /* defined(__Plane__LevelBottomLayer__) */
