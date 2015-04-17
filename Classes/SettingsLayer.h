//
//  SettingsLayer.h
//  Plane
//
//  Created by ml on 15-1-19.
//
//

#ifndef __Plane__SettingsLayer__
#define __Plane__SettingsLayer__

#include "CCBLayer.h"


class SettingsLayer : public CCBLayer
{
public:
    virtual bool init();
    CREATE_FUNC(SettingsLayer);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    void MusicSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void SoundSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    void CloseSelector(CCObject *pSender, CCControlEvent pCCControlEvent);
    
    
    
private:
    CCSprite * mMusicSign;
    CCSprite * mSoundSign;

};

class SettingsLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SettingsLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(SettingsLayer);
};

#endif /* defined(__Plane__SettingsLayer__) */
