//
//  BaseMenu.h
//  Gobang
//
//  Created by KGB on 14-4-15.
//
//

#ifndef __Gobang__BaseLayer__
#define __Gobang__BaseLayer__
#include "Common.h"
#include "CCBDelegate.h"


class CCBLayer : public CCLayer, public CCBSelectorResolver, public CCBMemberVariableAssigner, public CCNodeLoaderListener,public CCBAnimationManagerDelegate
{
public:
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    CREATE_FUNC(CCBLayer);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode){ return false; };
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName){ return NULL; };
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName){ return NULL; };
    
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader){};
   
    virtual void completedAnimationSequenceNamed(const char * name){};
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void Update(float time){};
    
    virtual void RefreshUI(){};
    virtual bool PlayAnimantionByName(const char * _name);
    virtual bool PlayShowAnimation();
    virtual bool PlayHideAnimation();
    virtual void Show();
    virtual void Hide();
    
    
    void SetDelegate(CCBDelegate * _delegate);
    CCBDelegate * GetDelegate();
    
    bool GetIsTheLast();
    bool GetIsTheDialog();
protected:
    CCBDelegate * mDelegate;
    CCArray * mChildrenCCB;
    bool mIsTheLast;//用来控制android back事件
    bool mIsTheDialog;//如果为真 前面的界面就不用隐藏
    int mTouchLevel;//触摸级别
    CCMenu * mMenu;
};


class CCBLoader : public CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CCBLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CCBLayer);
};


#endif /* defined(__Gobang__BaseLayer__) */
