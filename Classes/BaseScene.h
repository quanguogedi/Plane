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
    
    /**	创建函数	*/
    CREATE_FUNC(CBaseScene);
    
    virtual void HideLayer();
    
    virtual void ShowLayer(CCBLayer * _layer);
    
    
    virtual void SwitchToPrevScene(){};//返回到上一个场景
    
public:
    stack<CCBLayer*> mLayerStack;
};

#endif /* defined(__Plane__BaseScene__) */
