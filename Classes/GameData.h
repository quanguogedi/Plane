//
//  GameData.h
//  Plane
//
//  Created by ml on 15-1-26.
//
//

#ifndef __Plane__GameData__
#define __Plane__GameData__

#include <stdio.h>
#include "Singleton.h"

#include "cocos2d.h"
USING_NS_CC;

class PlayerData : public CCObject
{
    
};

class PlayerPlaneData : public PlayerData
{
public:
    static PlayerPlaneData* create(int planeType, int attack = 1, int subMissileAttack = 1, int planeHP = 1, int wingAttack = 1);
    bool init(int planeType, int attack, int subMissileAttack, int planeHP, int wingAttack);
    
public:
    int mPlaneType;//飞机类型
    int mAttackLevel;//攻击力等级
    int mSubMissileAttackLevel;//导弹等级
    int mPlaneHPLevel;//生命值等级
    int mWingAttackLevel;//僚机等级

};

class PlayerAchievementData : public PlayerData
{
public:
    int mAchievementID;
    int mProgress;
    
public:
    
};

class GameDataManager
{
    DECLARE_SINGLETON(GameDataManager)
    
public:
    GameDataManager();
    ~GameDataManager();
    
    void Init();
    
    void LoadUserSaveData();
    
public:
    
    void SelectPlane(int planeType);
    int GetCurrentPlane();
    
    void UnlockPlane(int planeType);
    void PlaneUpgrade(int planeType, int upType);
    void PlaneUpgradeMax(int planeType, int upType);
    
    void AttackUpgrade(int planeType);
    void SubMissileUpgrade(int planeType);
    void HPUpgrade(int planeType);
    void WingAttackUpgrade(int planeType);
    
    void ChangeCurrentPower(int _change);
    int GetCurrentPower();
    
    void ChangeMaxPower(int _change);
    int GetMaxPower();
    
    
    void ChangeDiamond(int change);
    int GetDiamond();
    
    PlayerPlaneData* GetPlayerPlaneData(int planeType);
    
private:
    CCDictionary* mAllPlayerPlaneDataDict;
    int mCurrentPower;
    int mMaxPower;
    int mCurrentDiamond;
    int mCurrentLevel;
    int mCurrentPlane;
};



//杨延飞 添加
class PlaneAttributeData : public CCObject
{
public:
    char * mFile;
    char * mName;
    char * mDisc;
    bool mIsCanUpgrade;//是否可以升级
    int mCurrAttack;//当前等级的攻击力
    int mNextAttack;//下一等级的攻击力
    int mUpgradeCost;//升级所需钻石
    
};








#endif /* defined(__Plane__GameData__) */
