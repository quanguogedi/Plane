//
//  DataManager.cpp
//  Plane
//
//  Created by 姜彬彬 on 4/19/15.
//
//

#include "DataManager.h"

IMPLEMENT_SINGLETON(DataManager)

DataManager::DataManager()
{
    Init();
}

DataManager::~DataManager()
{
    
}

void DataManager::Init()
{
    SetPlayerType(1);
}


void DataManager::SetPlayerType(int _type)
{
    mPlayerType = _type;
    
    
    int player = LocalArchiveData::GetInstance()->GetPlayerDataByType(mPlayerType);
    mMainPlaneLevel = player/1000;
    mMissileLevel = player%1000/100;
    mArmorLevel = player%100/10;
    mWingPlaneLevel = player%10;
}

int DataManager::GetPlayerType()
{
    return mPlayerType;
}





UpgradeData * DataManager::GetUpgradeData(int _type)
{
    UpgradeData * data = NULL;
    CCString * key = NULL;
    switch (_type)
    {
        case 1:
            key = CCString::createWithFormat("MainPlane%d%d",mPlayerType,mMainPlaneLevel);
            data = (UpgradeData*)LocalStaticData::GetInstance()->GetMainPlaneDic()->objectForKey(key->getCString());
            break;
        case 2:
            key = CCString::createWithFormat("Missile%d%d",mPlayerType,mMissileLevel);
            data = (UpgradeData*)LocalStaticData::GetInstance()->GetMissileDic()->objectForKey(key->getCString());;
            break;
        case 3:
            key = CCString::createWithFormat("Armor%d%d",mPlayerType,mArmorLevel);
            data = (UpgradeData*)LocalStaticData::GetInstance()->GetArmorDic()->objectForKey(key->getCString());
            break;
        case 4:
            key = CCString::createWithFormat("Wing%d%d",mPlayerType,mWingPlaneLevel);
            data = (UpgradeData*)LocalStaticData::GetInstance()->GetWingPlaneDic()->objectForKey(key->getCString());
            break;
       
        default:
            break;
    }
    
    return data;
}

void DataManager::SavaUpgradeData(int _type,bool _isMax)
{
    switch (_type)
    {
        case 1:
            if (_isMax)
            {
                mMainPlaneLevel = 6;
            }else
            {
                mMainPlaneLevel++;
            };
            break;
        case 2:
            if (_isMax)
            {
                mMissileLevel = 6;
            }else
            {
                mMissileLevel++;
            };
        case 3:
            if (_isMax)
            {
                mArmorLevel = 6;
            }else
            {
                mArmorLevel++;
            };
        case 4:
            if (_isMax)
            {
                mWingPlaneLevel = 6;
            }else
            {
                mWingPlaneLevel++;
            };
            
        default:
            break;
    }
    
    int value = mMainPlaneLevel*1000 + mMissileLevel*100 + mArmorLevel*10 + mWingPlaneLevel;
    LocalArchiveData::GetInstance()->SavePlayerData(mPlayerType, value);
}







