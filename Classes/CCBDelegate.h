//
//  CCBDelegate.h
//  Plane
//
//  Created by 姜彬彬 on 4/10/15.
//
//

#ifndef Plane_CCBDelegate_h
#define Plane_CCBDelegate_h

#include "Common.h"

class CCBDelegate
{
public:
    //场景要实现的方法、
    
    
    
    //SettingsLayer
    virtual void CloseSettingsLayer(){};
    
    //UpgradeLayer
    virtual void CloseUpgradeLayer(){};
    
    //AchievementLayer
    virtual void CloseAchievementLayer(){};
    
    
/*------------------下面是GameMenu要实现的方法---------------------*/
    
    //BaseScene实现
    
    virtual void HideLayer(){};
    
    //MenuTopBarLayer调用
    virtual void OpenBuyPowerLayer(){};
    virtual void OpenBuyDiamondLayer(){};
    
    //BuyDiamondLayer调用
    virtual void OpenGiftLayer(){};
    virtual void OpenBuyDiamondSureLayer(){};
    
    //MenuBottomLayer调用
    virtual void OpenUpgradeLayer(){};
    virtual void OpenAchievementLayer(){};
    virtual void OpenSettingLayer(){};
    

    //LevelBottomLayer调用
    virtual void OpenStartGameLayer(){};
    
    //GameMenuLayer调用
    virtual void OpenPauseLayer(){};
    
    //
    virtual void OpenGiftBagLayer(){};
    
};

#endif
