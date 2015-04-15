//
//  SecondSelector.h
//  Plane
//
//  Created by 杨延飞 on 14-11-23.
//
//

#ifndef __Plane__SecondSelector__
#define __Plane__SecondSelector__
#include "CCBLayer.h"

class SecondLayer:public CCBLayer
{
public:
    CREATE_FUNC(SecondLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
    virtual void onEnter();
    virtual void onExit();
    
    void AddPowerSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//添加体力按钮事件
    void DepotSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//仓库按钮事件
    void BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//返回按钮事件
    void BossSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//Boss模式按钮事件
    void CopterSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//活动关卡按钮事件
private:
    ~SecondLayer();
    CCSprite * mPower;//体力条
};



class SecondLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SecondLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(SecondLayer);
};

#endif /* defined(__Plane__SecondSelector__) */
