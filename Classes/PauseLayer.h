//
//  PauseLayer.h
//  Plane
//
//  Created by 杨延飞 on 15/4/23.
//
//

#ifndef __Plane__PauseLayer__
#define __Plane__PauseLayer__
#include "Common.h"
#include "CCBLayer.h"

class PauseLayer : public CCBLayer
{
public:
    virtual bool init();
    CREATE_FUNC(PauseLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void RefreshUI();
    
    void GiftSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void ContinueSelector(CCObject *pSender,CCControlEvent pCCControlEvent);
    void BackMainSelector(CCObject *pSender,CCControlEvent pCCControlEvent);
    void OpenMusicSelector(CCObject *pSender,CCControlEvent pCCControlEvent);
    void CloseMusicSelector(CCObject *pSender,CCControlEvent pCCControlEvent);
    void BuyKillerSelector(CCObject *pSender,CCControlEvent pCCControlEvent);
    void BuyShieldSelector(CCObject *pSender,CCControlEvent pCCControlEvent);
    
private:
    CCMenuItemImage * mCloseItem;
    CCMenuItemImage * mOpenItem;
    
};


class PauseLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(PauseLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(PauseLayer);
};
#endif /* defined(__Plane__PauseLayer__) */
