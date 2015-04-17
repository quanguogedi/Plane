//
//  AchievementLayer.h
//  Plane
//
//  Created by KGB on 15/3/25.
//
//

#ifndef __Plane__AchievementLayer__
#define __Plane__AchievementLayer__

#include "CCBLayer.h"


class AchievementLayer : public CCBLayer, public CCScrollViewDelegate
{
public:
    virtual bool init();
    CREATE_FUNC(AchievementLayer);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView *view){};
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView *view){};
    void BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    
private:
    void InitAchievementList();
    
    
private:
    CCSprite * mBorderSprite;
    CCLabelTTF* mDiamondLabel;
    
    CCScrollView* mAchievemenListScrollView;
    CCNode* mContainerNode;
};

class AchievementLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(AchievementLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(AchievementLayer);
};

#endif /* defined(__Plane__AchievementLayer__) */
