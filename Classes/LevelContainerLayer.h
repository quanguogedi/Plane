//
//  LevelContainerLayer.h
//  Plane
//
//  Created by 杨延飞 on 15/4/22.
//
//

#ifndef __Plane__LevelContainerLayer__
#define __Plane__LevelContainerLayer__

#include "Common.h"
#include "CCBLayer.h"

class LevelContainerLayer : public CCBLayer
{
public:
    virtual bool init();
    CREATE_FUNC(LevelContainerLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void RefreshUI();
    
};


class LevelContainerLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LevelContainerLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(LevelContainerLayer);
};

#endif /* defined(__Plane__LevelContainerLayer__) */
