//
//  PlaneDisplayLayer.cpp
//  Plane
//
//  Created by 姜彬彬 on 4/12/15.
//
//

#include "PlaneDisplayLayer.h"


bool PlaneDisplayLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    return false;
}

SEL_MenuHandler PlaneDisplayLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "SureSelector", PlaneDisplayLayer::SureSelector);
    
    return false;
}


//////////////////////////

