//
//  PlanAttributeLayer.cpp
//  Plane
//
//  Created by 姜彬彬 on 4/11/15.
//
//

#include "PlanAttributeLayer.h"

void PlanAttributeLayer::onEnter()
{
    CCBLayer::onEnter();
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(PlanAttributeLayer::RefreshAttribute),REFRESH_PLANATTRIBUTE, NULL);

}

void PlanAttributeLayer::onExit()
{
    CCBLayer::onExit();
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, REFRESH_PLANATTRIBUTE);
}

bool PlanAttributeLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "AtkLabel1", CCLabelTTF*, mAtkLabel1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "AtkLabel2", CCLabelTTF*, mAtkLabel2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "AtkLabel3", CCLabelTTF*, mAtkLabel3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "AtkLabel4", CCLabelTTF*, mAtkLabel4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "HpLabel", CCLabelTTF*, mHpLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "AtkSprite1", CCSprite*, mAtkSprite1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "AtkSprite2", CCSprite*, mAtkSprite2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "AtkSprite3", CCSprite*, mAtkSprite3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "AtkSprite4", CCSprite*, mAtkSprite4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "HpSprite", CCSprite*, mHpSprite);
    
    
    return false;
}



void PlanAttributeLayer::RefreshUI()
{
    int currentPlaneType = GameDataManager::GetSingleton().GetCurrentPlane();
    PlayerPlaneData* planeData = GameDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType);
    
    int attack = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mAttackLevel)->mAttack;
    
    int maxAttack = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, 6)->mAttack;
    
    mAtkLabel1->setString(CCString::createWithFormat("%d",attack)->getCString());
    mAtkSprite1->setScaleX(0);
    mAtkSprite1->runAction(CCSequence::create(CCDelayTime::create(0.2),CCScaleTo::create(0.3, (float)attack/maxAttack,1),NULL));
    
    int subMissileAttack = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mSubMissileAttackLevel)->mSubMissileAttack;
    
    int maxSubMissileAttack = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, 6)->mSubMissileAttack;
    
    mAtkLabel2->setString(CCString::createWithFormat("%d",subMissileAttack)->getCString());
    mAtkSprite2->setScaleX(0);
    mAtkSprite2->runAction(CCSequence::create(CCDelayTime::create(0.2),CCScaleTo::create(0.3, (float)subMissileAttack/maxSubMissileAttack,1),NULL));

    int hp = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mPlaneHPLevel)->mPlaneHP;
    
    int maxHp = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType,6)->mPlaneHP;
  
    mHpLabel->setString(CCString::createWithFormat("%d",hp)->getCString());
    mHpSprite->setScaleX(0);
    mHpSprite->runAction(CCSequence::create(CCDelayTime::create(0.2),CCScaleTo::create(0.3, (float)hp/maxHp,1),NULL));

    
    int wingAgttack = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, planeData->mWingAttackLevel)->mWingAttack;
    int maxWingAgttack = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType, 6)->mWingAttack;

    mAtkLabel3->setString(CCString::createWithFormat("%d",wingAgttack)->getCString());
    mAtkSprite3->setScaleX(0);
    mAtkSprite3->runAction(CCSequence::create(CCDelayTime::create(0.2),CCScaleTo::create(0.3, (float)wingAgttack/maxWingAgttack,1),NULL));
    
    int fight = attack + subMissileAttack + hp + wingAgttack;
    int maxFight = maxAttack + maxSubMissileAttack + maxHp + maxWingAgttack;

    mAtkLabel4->setString(CCString::createWithFormat("%d",fight)->getCString());
    mAtkSprite4->setScaleX(0);
    mAtkSprite4->runAction(CCSequence::create(CCDelayTime::create(0.2),CCScaleTo::create(0.3, (float)fight/maxFight,1),NULL));
}

void PlanAttributeLayer::RefreshAttribute(cocos2d::CCObject *_obj)
{
    CCLog("-----------%d",(((CCString*)_obj)->intValue()));
}

