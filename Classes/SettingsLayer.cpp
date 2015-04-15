//
//  SettingsLayer.cpp
//  Plane
//
//  Created by ml on 15-1-19.
//
//

#include "SettingsLayer.h"

bool SettingsLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    return false;
}
SEL_MenuHandler SettingsLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "OnTouchCloseButton", SettingsLayer::OnTouchCloseButton);

    return false;
}

SEL_CCControlHandler SettingsLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    return false;
}

void SettingsLayer::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    
}

void SettingsLayer::Close()
{
    if(mDelegate)
    {
        mDelegate->HideLayer();
    }
}

void SettingsLayer::OnTouchCloseButton(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    Close();
}
