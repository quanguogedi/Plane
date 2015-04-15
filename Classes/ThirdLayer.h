//
//  ThirdLayer.h
//  Plane
//
//  Created by 杨延飞 on 14-11-23.
//
//

#ifndef __Plane__ThirdLayer__
#define __Plane__ThirdLayer__

#include "CCBLayer.h"

class ThirdLayer:public CCBLayer
{
public:
    CREATE_FUNC(ThirdLayer);
    
    virtual void onEnter();
    virtual void onExit();
    virtual void update(float dt);
    void ShowHp();//显示血量
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
    void PauseSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//暂停按钮事件
    void ExitSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//退出按钮事件
    void ContinueSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//继续按钮事件
    
    
private:
    ~ThirdLayer();
    CCSprite * mHp;//血条
};



class ThirdLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ThirdLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ThirdLayer);
};

#endif /* defined(__Plane__ThirdLayer__) */
