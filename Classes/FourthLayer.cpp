//
//  FourthLayer.cpp
//  Plane
//
//  Created by 杨延飞 on 14-11-23.
//
//

#include "FourthLayer.h"

#include "CCBManager.h"
#include "GameEvents.h"
#include "GameManager.h"

FourthLayer::~FourthLayer()
{
//    CC_SAFE_RELEASE(mHp);
}


void FourthLayer::onEnter()
{
    CCBLayer::onEnter();
}
void FourthLayer::onExit()
{
    CCBLayer::onExit();
}




bool FourthLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Hp", CCSprite*, mHp);
    return false;
}

SEL_MenuHandler FourthLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "ContinueSelector", FourthLayer::ContinueSelector);
    return NULL;
}

SEL_CCControlHandler FourthLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

void FourthLayer::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    
}



void FourthLayer::ContinueSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CGameEvents::startFlipInterface(GAME_MENU);
}