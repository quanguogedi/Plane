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
void GameMenuLayer::onEnter()
{
    CCBLayer::onEnter();
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(GameMenuLayer::RefreshProps), REFRESH_PROPS, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(GameMenuLayer::RefreshScore), REFRESH_SCORE, NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(GameMenuLayer::RefreshHp), REFRESH_HP, NULL);
}

void GameMenuLayer::onExit()
{
    CCBLayer::onExit();
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, REFRESH_PROPS);
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, REFRESH_SCORE);
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, REFRESH_HP);
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
    RefreshProps();
    RefreshScore();
    
}
void GameMenuLayer::RefreshProps()
{
    int killerCount = LocalArchiveData::GetInstance()->mKillerCount;
    int shieldCount = LocalArchiveData::GetInstance()->mShieldCount;
    
    mKillerLabel->setString(CCString::createWithFormat("%d",killerCount)->getCString());
    mShieldLabel->setString(CCString::createWithFormat("%d",shieldCount)->getCString());
}

void GameMenuLayer::RefreshScore()
{
    int score = DataManager::GetInstance()->GetScore();
    mScoreLabel->setString(CCString::createWithFormat("%d",score)->getCString());
}

void GameMenuLayer::RefreshHp()
{
    float hp = DataManager::GetInstance()->GetHpPCT();
    mHpSprite->setScaleX(hp);
}

void GameMenuLayer::PauseSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
//    CGameEvents::startFlipInterface(GAME_START);
    if (mDelegate)
    {
        mDelegate->OpenPauseLayer();
    }
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