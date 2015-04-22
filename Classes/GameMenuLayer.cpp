//
//  GameMenuLayer.cpp
//  Plane
//
//  Created by 姜彬彬 on 4/22/15.
//
//

#include "GameMenuLayer.h"
bool GameMenuLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    
    return true;
}

bool GameMenuLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "HpSprite", CCSprite*, mHpSprite);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ScoreLabel", CCLabelBMFont *,mScoreLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "KillerLabel", CCLabelTTF*, mKillerLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ShieldLabel", CCLabelTTF*, mShieldLabel);
    return false;
}

SEL_MenuHandler GameMenuLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "PauseSelector", GameMenuLayer::PauseSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "KillerSelector", GameMenuLayer::KillerSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "ShieldSelector", GameMenuLayer::ShieldSelector);
    
    return false;
}

void GameMenuLayer::RefreshUI()
{
    RefreshPropLabel();
    
}
void GameMenuLayer::RefreshPropLabel()
{
    
}

void GameMenuLayer::PauseSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
//    CGameEvents::startFlipInterface(GAME_START);
}

void GameMenuLayer::KillerSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
//    if (mDelegate)
//    {
//        mDelegate->HideLayer();
//    }
}

void GameMenuLayer::ShieldSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    //    if (mDelegate)
    //    {
    //        mDelegate->HideLayer();
    //    }
}