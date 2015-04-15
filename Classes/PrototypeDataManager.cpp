//
//  PrototypeDataManager.cpp
//  Plane
//
//  Created by ml on 15-1-24.
//
//

#include "PrototypeDataManager.h"

PrototypePlaneData* PrototypePlaneData::create(int planeType, int planeLevel, int attack, int subMissileAttack, int planeHP, int wingAttack, int fightPoint)
{
    PrototypePlaneData* data = new PrototypePlaneData;
    data->init(planeType, planeLevel, attack, subMissileAttack, planeHP, wingAttack, fightPoint);
    data->autorelease();
    
    return data;
}

bool PrototypePlaneData::init(int planeType, int planeLevel, int attack, int subMissileAttack, int planeHP, int wingAttack, int fightPoint)
{
    mPlaneType = planeType;
    mPlaneLevel = planeLevel;
    mAttack = attack;
    mSubMissileAttack = subMissileAttack;
    mPlaneHP = planeHP;
    mWingAttack = wingAttack;
    mFightPoint = fightPoint;
    
    return true;
}

/////////////////////////////////////////////


PrototypePlaneUpgradeCostData* PrototypePlaneUpgradeCostData::create(int planeType, int planeLevel, int attackCost, int subMissileAttackCost, int planeHPCost, int wingAttackCost, int fightPointCost)
{
    PrototypePlaneUpgradeCostData* data = new PrototypePlaneUpgradeCostData;
    data->init(planeType, planeLevel, attackCost, subMissileAttackCost, planeHPCost, wingAttackCost, fightPointCost);
    data->autorelease();
    
    return data;
}

bool PrototypePlaneUpgradeCostData::init(int planeType, int planeLevel, int attackCost, int subMissileAttackCost, int planeHPCost, int wingAttackCost, int fightPointCost)
{
    mPlaneType = planeType;
    mPlaneLevel = planeLevel;
    mAttackCost = attackCost;
    mSubMissileAttackCost = subMissileAttackCost;
    mPlaneHPCost = planeHPCost;
    mWingAttackCost = wingAttackCost;
    mFightPointCost = fightPointCost;
    
    return true;
}

////////////////////////////////////////////

IMPLEMENT_SINGLETON(PrototypeDataManager)

PrototypeDataManager::PrototypeDataManager()
{
    Init();
}

PrototypeDataManager::~PrototypeDataManager()
{
    CC_SAFE_RELEASE_NULL(mAllPlaneDataDict);
}

void PrototypeDataManager::Init()
{
    //status
    mAllPlaneDataDict = new CCDictionary;
    //plane1
    AddNewData(1, 1, 240, 200, 3000, 220, 810);
    AddNewData(1, 2, 288, 240, 3600, 264, 972);
    AddNewData(1, 3, 360, 300, 4500, 330, 1215);
    AddNewData(1, 4, 480, 400, 6000, 440, 1620);
    AddNewData(1, 5, 624, 520, 7800, 572, 2106);
    AddNewData(1, 6, 864, 720, 10800, 792, 2916);
    
    //plane2
    AddNewData(2, 1, 370, 200, 4800, 409, 1457);
    AddNewData(2, 2, 444, 240, 5760, 490, 1731);
    AddNewData(2, 3, 555, 300, 7200, 612, 2142);
    AddNewData(2, 4, 740, 400, 9600, 814, 2827);
    AddNewData(2, 5, 999, 520, 12960, 1098, 3786);
    AddNewData(2, 6, 864, 1443, 18720, 1584, 5430);
    
    //cost
    mAllPlaneCostDataDict = new CCDictionary;
    //plane1 cost
    AddNewCostData(1, 1, 240, 200, 3000, 220, 810);
    AddNewCostData(1, 2, 288, 240, 3600, 264, 972);
    AddNewCostData(1, 3, 360, 300, 4500, 330, 1215);
    AddNewCostData(1, 4, 480, 400, 6000, 440, 1620);
    AddNewCostData(1, 5, 624, 520, 7800, 572, 2106);
    AddNewCostData(1, 6, 864, 720, 10800, 792, 2916);
    
    
    //achievement
    mAllAchievementDataDict = new CCDictionary;
    AddNewmAllAchievementDataDictData(1, "ach1", "ach1 desc", 3, 100);
    AddNewmAllAchievementDataDictData(2, "ach2", "ach2 desc", 4, 500);
    AddNewmAllAchievementDataDictData(3, "ach3", "ach3 desc", 5, 800);
}

PrototypePlaneData* PrototypeDataManager::GetPlayerPlaneData(int planeType, int planeLevel)
{
    PrototypePlaneData* data = NULL;
    
    CCDictionary* dict = (CCDictionary*)mAllPlaneDataDict->objectForKey(planeType);
    if(dict)
    {
        data = (PrototypePlaneData*)dict->objectForKey(planeLevel);
    }
    
    return data;
}

PrototypePlaneUpgradeCostData*  PrototypeDataManager::GetPrototypePlaneUpgradeCostData(int planeType, int planeLevel)
{
    PrototypePlaneUpgradeCostData* data = NULL;
    
    CCDictionary* dict = (CCDictionary*)mAllPlaneDataDict->objectForKey(planeType);
    if(dict)
    {
        data = (PrototypePlaneUpgradeCostData*)dict->objectForKey(planeLevel);
    }
    
    return data;
}

CCDictionary* PrototypeDataManager::GetAllAchievementDataDict()
{
    return mAllAchievementDataDict;
}

PrototypeAchievementData* PrototypeDataManager::GetPrototypeAchievementData(int pid)
{
    return (PrototypeAchievementData*)mAllAchievementDataDict->objectForKey(pid);
}

//////////////////////////////////

void PrototypeDataManager::AddNewData(int planeType, int planeLevel, int attack, int subMissileAttack, int planeHP, int wingAttack, int fightPoint)
{
    CCDictionary* dict = (CCDictionary*)mAllPlaneDataDict->objectForKey(planeType);
    if(!dict)
    {
        dict = CCDictionary::create();
        mAllPlaneDataDict->setObject(dict, planeType);
    }
    
    PrototypePlaneData* data = PrototypePlaneData::create(planeType, planeLevel, attack, subMissileAttack, planeHP, wingAttack, fightPoint);
    dict->setObject(data, data->mPlaneLevel);
}

void PrototypeDataManager::AddNewCostData(int planeType, int planeLevel, int attackCost, int subMissileAttackCost, int planeHPCost, int wingAttackCost, int fightPointCost)
{
    CCDictionary* dict = (CCDictionary*)mAllPlaneCostDataDict->objectForKey(planeType);
    if(!dict)
    {
        dict = CCDictionary::create();
        mAllPlaneCostDataDict->setObject(dict, planeType);
    }
    
    PrototypePlaneUpgradeCostData* data = PrototypePlaneUpgradeCostData::create(planeType, planeLevel, attackCost, subMissileAttackCost, planeHPCost, wingAttackCost, fightPointCost);
    dict->setObject(data, data->mPlaneLevel);
}


void PrototypeDataManager::AddNewmAllAchievementDataDictData(int pid, const char* name, const char* desc, int num, int result)
{
    PrototypeAchievementData* data = new PrototypeAchievementData;
    data->mAchievementID = pid;
    sprintf(data->mName, "%s",name);
    sprintf(data->mDesc, "%s",desc);
    data->mConditionNum = num;
    data->mResultDiamond = result;
    
    mAllAchievementDataDict->setObject(data, data->mAchievementID);
}
