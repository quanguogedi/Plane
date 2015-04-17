//
//  SettingsLayer.cpp
//  Plane
//
//  Created by ml on 15-1-19.
//
//

#include "SettingsLayer.h"

bool SettingsLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    
    mIsTheDialog = true;
    mTouchLevel = 1;
    return true;
}


bool SettingsLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "MusicSign", CCSprite*, mMusicSign);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "SoundSign", CCSprite*, mSoundSign);
    return false;
}
SEL_MenuHandler SettingsLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "MusicSelector", SettingsLayer::MusicSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "SoundSelector", SettingsLayer::SoundSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "CloseSelector", SettingsLayer::CloseSelector);


    return false;
}

void SettingsLayer::MusicSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    mMusicSign->setVisible(!mMusicSign->isVisible());
}


void SettingsLayer::SoundSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    mSoundSign->setVisible(!mSoundSign->isVisible());
}

void SettingsLayer::CloseSelector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->HideLayer();
    }
}



