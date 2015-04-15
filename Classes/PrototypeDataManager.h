//
//  PrototypeDataManager.h
//  Plane
//
//  Created by ml on 15-1-24.
//
//

#ifndef __Plane__PrototypeDataManager__
#define __Plane__PrototypeDataManager__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

#include "Singleton.h"


class PrototypeData : public CCObject
{

};


class PrototypePlaneData : public PrototypeData
{
public:
    static PrototypePlaneData* create(int planeType, int planeLevel, int attack, int subMissileAttack, int planeHP, int wingAttack, int fightPoint);
    virtual bool init(int planeType, int planeLevel, int attack, int subMissileAttack, int planeHP, int wingAttack, int fightPoint);
    
public:
    int mPlaneType;
    int mPlaneLevel;
    int mAttack;
    int mSubMissileAttack;
    int mPlaneHP;
    int mWingAttack;
    int mFightPoint;
};

class PrototypePlaneUpgradeCostData : public PrototypeData
{
public:
    static PrototypePlaneUpgradeCostData* create(int planeType, int planeLevel, int attackCost, int subMissileAttackCost, int planeHPCost, int wingAttackCost, int fightPointCost);
    virtual bool init(int planeType, int planeLevel, int attackCost, int subMissileAttackCost, int planeHPCost, int wingAttackCost, int fightPointCost);
    
public:
    int mPlaneType;
    int mPlaneLevel;
    int mAttackCost;
    int mSubMissileAttackCost;
    int mPlaneHPCost;
    int mWingAttackCost;
    int mFightPointCost;
};


class PrototypeAchievementData : public PrototypeData
{
public:
    PrototypeAchievementData()
    {
        memset(mName, 0, 128);
        memset(mDesc, 0, 128);
    }
    
public:
    int mAchievementID;
    char mName[128];
    char mDesc[128];
    int mConditionNum;
    int mResultDiamond;
};



class PrototypeDataManager
{
    DECLARE_SINGLETON(PrototypeDataManager)
public:
    PrototypeDataManager();
    ~PrototypeDataManager();
    void Init();
    
public:
    PrototypePlaneData* GetPlayerPlaneData(int planeType, int planeLevel);
    PrototypePlaneUpgradeCostData*  GetPrototypePlaneUpgradeCostData(int planeType, int planeLevel);
    
    CCDictionary* GetAllAchievementDataDict();
    PrototypeAchievementData* GetPrototypeAchievementData(int pid);
    
private:
    void AddNewData(int planeType, int planeLevel, int attack, int subMissileAttack, int planeHP, int wingAttack, int fightPoint);
    void AddNewCostData(int planeType, int planeLevel, int attackCost, int subMissileAttackCost, int planeHPCost, int wingAttackCost, int fightPointCost);
    void AddNewmAllAchievementDataDictData(int pid, const char* name, const char* desc, int num, int result);
private:
    CCDictionary* mAllPlaneDataDict;
    CCDictionary* mAllPlaneCostDataDict;
    CCDictionary* mAllAchievementDataDict;
};



#endif /* defined(__Plane__PrototypeDataManager__) */
