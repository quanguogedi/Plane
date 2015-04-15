//
//  MenuBottomLayer.h
//  Plane
//
//  Created by 姜彬彬 on 14-11-22.
//
//

#ifndef __Plane__MenuBottomLayer_
#define __Plane__MenuBottomLayer_

#include "CCBLayer.h"

class MenuBottomLayer : public CCBLayer
{
public:
    virtual bool init();
    CREATE_FUNC(MenuBottomLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    void StartGameSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//开始游戏
    void ChallengeSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//挑战模式
    void UpgradeSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//强化战机
    void AchievementSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//成就
    void SettingSelector(CCObject *pSender, CCControlEvent pCCControlEvent);//设置
    
    
};

class MenuBottomLayerLoader : public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuBottomLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MenuBottomLayer);
};

#endif /* defined(__Plane__MenuBottomLayer__) */
