//
//  BaseScene.h
//  Plane
//
//  Created by 姜彬彬 on 4/10/15.
//
//

#ifndef __Plane__BaseScene__
#define __Plane__BaseScene__

#include "Common.h"
#include "CCBLayer.h"
#include "CCBDelegate.h"
#include <stack>


class CBaseScene : public CCLayer,public CCBDelegate
{
public:
    
    /**	场景	*/
    static CCScene* scene();
    
    /**	初始化函数	*/
    virtual bool init();
    
    virtual void onEnter();
    virtual void onExit();
    /**	创建函数	*/
    CREATE_FUNC(CBaseScene);
    
    virtual void HideLayer();
    
    virtual void ShowLayer(CCBLayer * _layer);
    
    
    virtual void SwitchToPrevScene(){};//返回到上一个场景
    
    virtual void update(float _time);
    void UpdateBg(float _time);
    
public:
    stack<CCBLayer*> mLayerStack;
    CCSprite * mBgSprite1;
    CCSprite * mBgSprite2;
};

#endif /* defined(__Plane__BaseScene__) */
