//
//  GameOverLayer.h
//  Plane
//
//  Created by 杨延飞 on 15/5/1.
//
//

#ifndef __Plane__GameOverLayer__
#define __Plane__GameOverLayer__
#include "Common.h"
#include "CCBLayer.h"

class GameOverLayer : public CCBLayer
{
public:
    virtual bool init();
    CREATE_FUNC(GameOverLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void RefreshUI();
    
    
    void MenuSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
private:
    CCSprite * mBgSprite;
    CCSprite * mWinSign;
    CCSprite * mLoseSign;
    CCLabelBMFont * mScoreLabel;
    CCLabelBMFont * mDiamondLabel;
    
};


class GameOverLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameOverLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameOverLayer);
};

#endif /* defined(__Plane__GameOverLayer__) */
