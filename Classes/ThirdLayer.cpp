//
//  ThirdLayer.cpp
//  Plane
//
//  Created by 杨延飞 on 14-11-23.
//
//

#include "ThirdLayer.h"
#include "CCBManager.h"
#include "GameEvents.h"
#include "GameManager.h"

ThirdLayer::~ThirdLayer()
{
    CC_SAFE_RELEASE(mHp);
}


void ThirdLayer::onEnter()
{
    CCBLayer::onEnter();
    scheduleUpdate();
}
void ThirdLayer::onExit()
{
    CCBLayer::onExit();
    unscheduleUpdate();
}

void ThirdLayer::update(float dt)
{
    ShowHp();
}

void ThirdLayer::ShowHp()
{
    int iHp = CGameManager::getPlayer()->getHp();
    int iHpMax = CGameManager::getPlayer()->getHpMax();
    float minX = mHp->getTextureRect().getMinX();
    float minY = mHp->getTextureRect().getMinY();
    float widths = 307;
    float height = mHp->boundingBox().size.height;
    mHp->setTextureRect(CCRectMake(minX,minY,widths*(float)iHp/iHpMax,height));
}


bool ThirdLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Hp", CCSprite*, mHp);
    return false;
}

SEL_MenuHandler ThirdLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "PauseSelector", ThirdLayer::PauseSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "ExitSelector", ThirdLayer::ExitSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "ContinueSelector", ThirdLayer::ContinueSelector);
    return NULL;
}

SEL_CCControlHandler ThirdLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

void ThirdLayer::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    
}



void ThirdLayer::PauseSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCDirector::sharedDirector()->pause();
    CCBAnimationManager *   actionManager = (CCBAnimationManager*)getUserObject();
    actionManager->setDelegate(this);
    actionManager->runAnimationsForSequenceNamed("PauseIn");
    
}
void ThirdLayer::ExitSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCDirector::sharedDirector()->resume();
    
    CGameEvents::startFlipInterface(GAME_MENU);
}

void ThirdLayer::ContinueSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCDirector::sharedDirector()->resume();
    CCBAnimationManager *   actionManager = (CCBAnimationManager*)getUserObject();
    actionManager->setDelegate(this);
    actionManager->runAnimationsForSequenceNamed("PauseOut");
}
