//
//  PlanAttributeLayer.h
//  Plane
//
//  Created by 姜彬彬 on 4/11/15.
//
//

#ifndef __Plane__PlanAttributeLayer__
#define __Plane__PlanAttributeLayer__

#include "CCBLayer.h"
class PlanAttributeLayer : public CCBLayer
{
public:
    virtual void onEnter();
    virtual void onExit();
    CREATE_FUNC(PlanAttributeLayer);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual void RefreshUI();
    
    void RefreshAttribute(CCObject * _obj);
private:
    CCLabelTTF* mAtkLabel1;
    CCLabelTTF* mAtkLabel2;
    CCLabelTTF* mAtkLabel3;
    CCLabelTTF* mAtkLabel4;
    CCLabelTTF* mHpLabel;
    CCSprite * mAtkSprite1;
    CCSprite * mAtkSprite2;
    CCSprite * mAtkSprite3;
    CCSprite * mAtkSprite4;
    CCSprite * mHpSprite;
    
    
    int mCurrentPlaneType;
};

class PlanAttributeLayerLoader : public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(PlanAttributeLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(PlanAttributeLayer);
};

#endif /* defined(__Plane__PlanAttributeLayer__) */
