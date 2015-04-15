//
//  PlaneDisplayLayer.h
//  Plane
//
//  Created by 姜彬彬 on 4/12/15.
//
//

#ifndef __Plane__PlaneDisplayLayer__
#define __Plane__PlaneDisplayLayer__

#include "CCBLayer.h"

class PlaneDisplayLayer : public CCBLayer
{
public:
    CREATE_FUNC(PlaneDisplayLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);

    
};


class PlaneDisplayLayerLoader : public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(PlaneDisplayLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(PlaneDisplayLayer);
};

#endif /* defined(__Plane__PlaneDisplayLayer__) */
