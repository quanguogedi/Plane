#pragma once

#include "BaseScene.h"
#include "LevelListLayer.h"
#include "MenuTopBarLayer.h"
#include "LevelBottomLayer.h"
#include "BuyDiamondLayer.h"
#include "BuyPowerLayer.h"
#include "UpgradeLayer.h"
#include "PlanAttributeLayer.h"
#include "PlaneDisplayLayer.h"
#include "StartGameLayer.h"
#include "GiftBagLayer.h"

class CGameLevel : public CBaseScene
{
public:
	/**	初始化函数	*/
    virtual bool init();  

	/**	场景	*/
    static CCScene* scene();

	/**	创建函数	*/
	CREATE_FUNC(CGameLevel);
    
    virtual void SwitchToPrevScene();
    
    //MenuTopBarLayer调用
    virtual void OpenBuyPowerLayer();
    virtual void OpenBuyDiamondLayer();
    //BuyDiamondLayer调用
    virtual void OpenGiftBagLayer();
    //MenuBottomLayer调用
    virtual void OpenUpgradeLayer();
    
    //LevelListLayer
    virtual void OpenStartGameLayer();
    
    

private:
    
    void InitBottomLayer();
    
    
	/**	选择关卡的回调函数	*/
	void setLevelMode(CCObject* pSender);

	/**	开始按钮的回调函数	*/
	void setLevelStart(CCObject* pSender);

    
    
    virtual void CCBLevelCallBack(CCObject * pSender);
    

private:
    LevelListLayer* mLevelListLayer;
    MenuTopBarLayer * mMenuTopBarLayer;
    LevelBottomLayer * mLevelBottomLayer;
    BuyDiamondLayer * mBuyDiamondLayer;
    BuyPowerLayer * mBuyPowerLayer;
    UpgradeLayer * mUpgradeLayer;
    StartGameLayer * mStartGameLayer;
    GiftBagLayer * mGiftBagLayer;
    
    
	CCParticleSun* m_pSun;		///<太阳特效

};