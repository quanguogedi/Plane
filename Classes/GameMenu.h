#pragma once


#include "BaseScene.h"
#include "MenuBottomLayer.h"
#include "PlaneDisplayLayer.h"
#include "UpgradeLayer.h"
#include "MenuTopBarLayer.h"
#include "AchievementLayer.h"
#include "SettingsLayer.h"
#include "BuyDiamondLayer.h"
#include "BuyPowerLayer.h"
#include "PlanAttributeLayer.h"
#include "GiftBagLayer.h"

class CGameMenu : public CBaseScene
{
public:
	

	/**	����	*/
    static CCScene* scene();
    CREATE_FUNC(CGameMenu);
    
    virtual bool init();
    //MenuTopBarLayer����
    virtual void OpenBuyPowerLayer();
    virtual void OpenBuyDiamondLayer();
    //BuyDiamondLayer����
    virtual void OpenGiftBagLayer();
    virtual void OpenBuyDiamondSureLayer();
    //MenuBottomLayer����
    virtual void OpenUpgradeLayer();
    virtual void OpenAchievementLayer();
    virtual void OpenSettingLayer();
    

private:
    void InitBackGround();
//    void InitTopLayer();
    void InitBottomLayer();
    void InitDisPlayLayer();
private:
    UpgradeLayer * mUpgradeLayer;
    BuyDiamondLayer * mBuyDiamondLayer;
    BuyPowerLayer * mBuyPowerLayer;
    AchievementLayer* mAchievementLayer;
    SettingsLayer* mSettingsLayer;
    GiftBagLayer * mGiftBagLayer;
    
    
};
