//
//  GameData.cpp
//  Plane
//
//  Created by ml on 15-1-26.
//
//

#include "GameData.h"
#include "PrototypeDataManager.h"

#define MAX_PLANE_LEVEL   6

//////////////////////////////////////////////////

PlayerPlaneData* PlayerPlaneData::create(int planeType, int attack, int subMissileAttack, int planeHP, int wingAttack)
{
    PlayerPlaneData* data = new PlayerPlaneData;
    data->init(planeType, attack, subMissileAttack, planeHP, wingAttack);
    data->autorelease();
    
    return data;
}

bool PlayerPlaneData::init(int planeType, int attack, int subMissileAttack, int planeHP, int wingAttack)
{
    mPlaneType = planeType;
    mAttackLevel = attack;
    mSubMissileAttackLevel = subMissileAttack;
    mPlaneHPLevel = planeHP;
    mWingAttackLevel = wingAttack;
    
    return true;
}


///////////////////////////////////////////////////

IMPLEMENT_SINGLETON(GameDataManager)

GameDataManager::GameDataManager()
{
    Init();
}

GameDataManager::~GameDataManager()
{
    CC_SAFE_RELEASE_NULL(mAllPlayerPlaneDataDict);
}

void GameDataManager::Init()
{
    mAllPlayerPlaneDataDict = new CCDictionary();
    
    LoadUserSaveData();
}


void GameDataManager::LoadUserSaveData()
{
    mCurrentPlane = 1;
    mCurrentLevel = 1;
    mCurrentDiamond = 99999;
    
    UnlockPlane(1);
}

void GameDataManager::SelectPlane(int planeType)
{
    mCurrentLevel = planeType;
}

int GameDataManager::GetCurrentPlane()
{
    return mCurrentLevel;
}

void GameDataManager::UnlockPlane(int planeType)
{
    if(mAllPlayerPlaneDataDict->objectForKey(planeType))
    {
        return;
    }
    
    PlayerPlaneData* newData = PlayerPlaneData::create(planeType);
    
    mAllPlayerPlaneDataDict->setObject(newData, planeType);
}

void GameDataManager::PlaneUpgrade(int planeType, int upType)
{
    switch (upType)
    {
        case 1:
            AttackUpgrade(planeType);
            break;
        case 2:
            SubMissileUpgrade(planeType);
            break;
        case 3:
            HPUpgrade(planeType);
            break;
        case 4:
            WingAttackUpgrade(planeType);
            break;
        default:
            break;
    }
}

void GameDataManager::PlaneUpgradeMax(int planeType, int upType)
{
    
}

void GameDataManager::AttackUpgrade(int planeType)
{
    PlayerPlaneData* data = (PlayerPlaneData*)mAllPlayerPlaneDataDict->objectForKey(planeType);
    
    if (!data)
    {
        CCLog("Lock!");
        return;
    }
    
    int level = data->mAttackLevel;
//    PrototypePlaneData* proData = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(planeType, level);
    PrototypePlaneUpgradeCostData* costData = PrototypeDataManager::GetSingleton().GetPrototypePlaneUpgradeCostData(planeType, level);
    
    if(level >= MAX_PLANE_LEVEL)
    {
        CCLog("Max Level");
        return;
    }
    
    if(mCurrentDiamond < costData->mAttackCost || !costData)
    {
        CCLog("No diamond");
        return;
    }
    ChangeDiamond(-costData->mAttackCost);
    data->mAttackLevel ++;
}

void GameDataManager::SubMissileUpgrade(int planeType)
{
    PlayerPlaneData* data = (PlayerPlaneData*)mAllPlayerPlaneDataDict->objectForKey(planeType);
    
    if (!data)
    {
        CCLog("Lock!");
        return;
    }
    
    int level = data->mSubMissileAttackLevel;
//    PrototypePlaneData* proData = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(planeType, level);
    PrototypePlaneUpgradeCostData* costData = PrototypeDataManager::GetSingleton().GetPrototypePlaneUpgradeCostData(planeType, level);
    
    if(level >= MAX_PLANE_LEVEL || !costData)
    {
        CCLog("Max Level");
        return;
    }
    
    if(mCurrentDiamond < costData->mSubMissileAttackCost)
    {
        CCLog("No diamond");
        return;
    }
    ChangeDiamond(-costData->mSubMissileAttackCost);
    
    data->mSubMissileAttackLevel ++;
}

void GameDataManager::HPUpgrade(int planeType)
{
    PlayerPlaneData* data = (PlayerPlaneData*)mAllPlayerPlaneDataDict->objectForKey(planeType);
    
    if (!data)
    {
        CCLog("Lock!");
        return;
    }
    
    int level = data->mPlaneHPLevel;
//    PrototypePlaneData* proData = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(planeType, level);
    PrototypePlaneUpgradeCostData* costData = PrototypeDataManager::GetSingleton().GetPrototypePlaneUpgradeCostData(planeType, level);

    if(level >= MAX_PLANE_LEVEL || !costData)
    {
        CCLog("Max Level");
        return;
    }
    
    if(mCurrentDiamond < costData->mPlaneHPCost)
    {
        CCLog("No diamond");
        return;
    }
    ChangeDiamond(-costData->mPlaneHPCost);
    
    data->mPlaneHPLevel ++;
}

void GameDataManager::WingAttackUpgrade(int planeType)
{
    PlayerPlaneData* data = (PlayerPlaneData*)mAllPlayerPlaneDataDict->objectForKey(planeType);
    
    if (!data)
    {
        CCLog("Lock!");
        return;
    }
    
    int level = data->mWingAttackLevel;
//    PrototypePlaneData* proData = PrototypeDataManager::GetSingleton().GetPlayerPlaneData(planeType, level);
    PrototypePlaneUpgradeCostData* costData = PrototypeDataManager::GetSingleton().GetPrototypePlaneUpgradeCostData(planeType, level);
    
    if(level >= MAX_PLANE_LEVEL || !costData)
    {
        CCLog("Max Level");
        return;
    }
    
    if(mCurrentDiamond < costData->mWingAttackCost)
    {
        CCLog("No diamond");
        return;
    }
    ChangeDiamond(-costData->mWingAttackCost);
    data->mWingAttackLevel ++;
}

void GameDataManager::ChangeCurrentPower(int _change)
{
    mCurrentPower += _change;
}
int GameDataManager::GetCurrentPower()
{
    return mCurrentPower;
}

void GameDataManager::ChangeMaxPower(int _change)
{
    mMaxPower += _change;
}

int GameDataManager::GetMaxPower()
{
    return mMaxPower;
}


void GameDataManager::ChangeDiamond(int change)
{
    mCurrentDiamond += change;
}

int GameDataManager::GetDiamond()
{
    return mCurrentDiamond;
}

PlayerPlaneData* GameDataManager::GetPlayerPlaneData(int planeType)
{
    PlayerPlaneData* data = (PlayerPlaneData*)mAllPlayerPlaneDataDict->objectForKey(planeType);
    
    if(!data)
    {
        data = PlayerPlaneData::create(planeType);
    }
    
    return data;
}
