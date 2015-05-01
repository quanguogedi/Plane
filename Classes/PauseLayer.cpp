//
//  PauseLayer.cpp
//  Plane
//
//  Created by 杨延飞 on 15/4/23.
//
//

#include "PauseLayer.h"

#include "GameEvents.h"
bool PauseLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    mIsTheDialog = true;
    mTouchLevel = 1;
    return true;
}

bool PauseLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "CloseItem", CCMenuItemImage*, mCloseItem);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "OpenItem", CCMenuItemImage*, mOpenItem);
    return false;
}

SEL_MenuHandler PauseLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "GiftSelector", PauseLayer::GiftSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "ContinueSelector", PauseLayer::ContinueSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "BackMainSelector", PauseLayer::BackMainSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "OpenMusicSelector", PauseLayer::OpenMusicSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "CloseMusicSelector", PauseLayer::CloseMusicSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "BuyKillerSelector", PauseLayer::BuyKillerSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "ButShieldSelector", PauseLayer::BuyShieldSelector);
    
    return false;
}

void PauseLayer::RefreshUI()
{
    if (LocalArchiveData::GetInstance()->mMusicEnable)
    {
        mCloseItem->setVisible(true);
        mOpenItem->setVisible(false);
    }else
    {
        mCloseItem->setVisible(false);
        mOpenItem->setVisible(true);
    }
}

void PauseLayer::GiftSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->OpenGiftBagLayer();
    }
}

void PauseLayer::ContinueSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        CCArray * array = CCDirector::sharedDirector()->getRunningScene()->getChildByTag(12306)->getChildren();
        CCObject *object = NULL;
        CCARRAY_FOREACH(array, object)
        {
            CCLayer * layer = (CCLayer*)object;
            if (layer != this)
            {
                layer->onEnter();
            }
            
        }
        mDelegate->HideLayer();
    }
}
void PauseLayer::BackMainSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CGameEvents::startFlipInterface(GAME_LEVEL);
}
void PauseLayer::OpenMusicSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    LocalArchiveData::GetInstance()->SaveMusicEnable(true);
    LocalArchiveData::GetInstance()->SaveSoundEnable(true);
    
    mOpenItem->setVisible(false);
    mCloseItem->setVisible(true);
}
void PauseLayer::CloseMusicSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    LocalArchiveData::GetInstance()->SaveMusicEnable(false);
    LocalArchiveData::GetInstance()->SaveSoundEnable(false);
    
    mOpenItem->setVisible(true);
    mCloseItem->setVisible(false);
}
void PauseLayer::BuyKillerSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    
}
void PauseLayer::BuyShieldSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    
}








