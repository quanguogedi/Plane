//
//  GameOverLayer.cpp
//  Plane
//
//  Created by 杨延飞 on 15/5/1.
//
//

#include "GameOverLayer.h"
#include "GameEvents.h"
bool GameOverLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    return true;
}

bool GameOverLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "BgSprite", CCSprite*, mBgSprite);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "WinSign", CCSprite*, mWinSign);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "LoseSign", CCSprite*, mLoseSign);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ScoreLabel", CCLabelBMFont*, mScoreLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DiamondLabel", CCLabelBMFont*, mDiamondLabel);
    return false;
}

SEL_MenuHandler GameOverLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "MenuSelector", GameOverLayer::MenuSelector);
    
    return false;
}

void GameOverLayer::RefreshUI()
{
    if (DataManager::GetInstance()->GetResult())
    {
        mWinSign->setVisible(true);
        
        mScoreLabel->setString(CCString::createWithFormat("%d",DataManager::GetInstance()->GetScore())->getCString());
        mDiamondLabel->setString(CCString::createWithFormat("%d",DataManager::GetInstance()->GetDiamond())->getCString());
        
        for (int i = 1; i <= DataManager::GetInstance()->GetStar(); i++)
        {
            mBgSprite->getChildByTag(i)->getChildByTag(1)->setVisible(true);
        }
    }else
    {
        mLoseSign->setVisible(true);
    }
    
}

void GameOverLayer::MenuSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    int tag = ((CCMenuItemImage*)pSender)->getTag();
    
    if (tag == 2)
    {
        DataManager::GetInstance()->SetLevelState(true);
    }
    
    CGameEvents::startFlipInterface(GAME_LEVEL);
}


