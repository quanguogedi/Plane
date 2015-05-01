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
	/**	��ʼ������	*/
    virtual bool init();  

	/**	����	*/
    static CCScene* scene();

	/**	��������	*/
	CREATE_FUNC(CGameLevel);
    
    virtual void SwitchToPrevScene();
    
    //MenuTopBarLayer����
    virtual void OpenBuyPowerLayer();
    virtual void OpenBuyDiamondLayer();
    //BuyDiamondLayer����
    virtual void OpenGiftBagLayer();
    //MenuBottomLayer����
    virtual void OpenUpgradeLayer();
    
    //LevelListLayer
    virtual void OpenStartGameLayer();
    
    

private:
    
    void InitBottomLayer();
    
    
	/**	ѡ��ؿ��Ļص�����	*/
	void setLevelMode(CCObject* pSender);

	/**	��ʼ��ť�Ļص�����	*/
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
    
    
	CCParticleSun* m_pSun;		///<̫����Ч

};