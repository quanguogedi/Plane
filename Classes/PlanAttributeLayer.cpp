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
//    int currentPlaneType = GameDataManager::GetSingleton().GetCurrentPlane();
//    PlayerPlaneData* planeData = GameDataManager::GetSingleton().GetPlayerPlaneData(currentPlaneType);
//    
    UpgradeData * data1 = DataManager::GetInstance()->GetUpgradeData(1);
    UpgradeData * data2 = DataManager::GetInstance()->GetUpgradeData(2);
    UpgradeData * data3 = DataManager::GetInstance()->GetUpgradeData(3);
    UpgradeData * data4 = DataManager::GetInstance()->GetUpgradeData(4);
    
    

    
    mAtkLabel1->setString(CCString::createWithFormat("%d",data1->mCurrValue)->getCString());
    mAtkSprite1->setScaleX(0);
    mAtkSprite1->runAction(CCSequence::create(CCDelayTime::create(0.2),CCScaleTo::create(0.3, (float)data1->mCurrValue/data1->mMaxValue,1),NULL));
    
    
    mAtkLabel2->setString(CCString::createWithFormat("%d",data2->mCurrValue)->getCString());
    mAtkSprite2->setScaleX(0);
    mAtkSprite2->runAction(CCSequence::create(CCDelayTime::create(0.2),CCScaleTo::create(0.3, (float)data2->mCurrValue/data2->mMaxValue,1),NULL));


    mHpLabel->setString(CCString::createWithFormat("%d",data3->mCurrValue)->getCString());
    mHpSprite->setScaleX(0);
    mHpSprite->runAction(CCSequence::create(CCDelayTime::create(0.2),CCScaleTo::create(0.3, (float)data3->mCurrValue/data3->mMaxValue,1),NULL));


    mAtkLabel3->setString(CCString::createWithFormat("%d",data4->mCurrValue)->getCString());
    mAtkSprite3->setScaleX(0);
    mAtkSprite3->runAction(CCSequence::create(CCDelayTime::create(0.2),CCScaleTo::create(0.3, (float)data4->mCurrValue/data4->mMaxValue,1),NULL));

    int fight = data1->mCurrValue + data2->mCurrValue + data3->mCurrValue + data4->mCurrValue;
    int maxFight = data1->mMaxValue + data2->mMaxValue + data3->mMaxValue + data4->mMaxValue;

    mAtkLabel4->setString(CCString::createWithFormat("%d",fight)->getCString());
    mAtkSprite4->setScaleX(0);
    mAtkSprite4->runAction(CCSequence::create(CCDelayTime::create(0.2),CCScaleTo::create(0.3, (float)fight/maxFight,1),NULL));
}

void PlanAttributeLayer::RefreshAttribute(cocos2d::CCObject *_obj)
{
    int type = ((CCString*)_obj)->intValue();
    UpgradeData * data = DataManager::GetInstance()->GetUpgradeData(type);
    switch (type)
    {
        case 1:
            mAtkLabel1->setString(CCString::createWithFormat("%d",data->mCurrValue)->getCString());
            mAtkSprite1->runAction(CCScaleTo::create(0.3, (float)data->mCurrValue/data->mMaxValue,1));;
            break;
        case 2:
            mAtkLabel2->setString(CCString::createWithFormat("%d",data->mCurrValue)->getCString());
            mAtkSprite2->runAction(CCScaleTo::create(0.3, (float)data->mCurrValue/data->mMaxValue,1));;
            break;
        case 3:
            mHpLabel->setString(CCString::createWithFormat("%d",data->mCurrValue)->getCString());

            mHpSprite->runAction(CCScaleTo::create(0.3, (float)data->mCurrValue/data->mMaxValue,1));;
            break;
        case 4:
            mAtkLabel3->setString(CCString::createWithFormat("%d",data->mCurrValue)->getCString());
            mAtkSprite3->runAction(CCScaleTo::create(0.3, (float)data->mCurrValue/data->mMaxValue,1));;
            break;
            
        default:
            break;
    }
    
    
    UpgradeData * data1 = DataManager::GetInstance()->GetUpgradeData(1);
    UpgradeData * data2 = DataManager::GetInstance()->GetUpgradeData(2);
    UpgradeData * data3 = DataManager::GetInstance()->GetUpgradeData(3);
    UpgradeData * data4 = DataManager::GetInstance()->GetUpgradeData(4);
    
    int fight = data1->mCurrValue + data2->mCurrValue + data3->mCurrValue + data4->mCurrValue;
    int maxFight = data1->mMaxValue + data2->mMaxValue + data3->mMaxValue + data4->mMaxValue;
    
    mAtkLabel4->setString(CCString::createWithFormat("%d",fight)->getCString());
    mAtkSprite4->runAction(CCScaleTo::create(0.3, (float)fight/maxFight,1));
}

