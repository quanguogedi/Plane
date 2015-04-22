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
    mMainPlaneLevel = 0;
    mMissileLevel = 0;
    mArmorLevel = 0;
    mWingPlaneLevel = 0;
    mGameLevel = 0;
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
        {
            CCLog("type = %d Missile = %d playertype = %d",_type,mMissileLevel,mPlayerType);
            key = CCString::createWithFormat("Missile%d%d",mPlayerType,mMissileLevel);
            data = (UpgradeData*)LocalStaticData::GetInstance()->GetMissileDic()->objectForKey(key->getCString());;
            break;
        }
            
        case 3:
            key = CCString::createWithFormat("Armor%d%d",mPlayerType,mArmorLevel);
            data = (UpgradeData*)LocalStaticData::GetInstance()->GetArmorDic()->objectForKey(key->getCString());
            break;
        case 4:
            key = CCString::createWithFormat("WingPlane%d%d",mPlayerType,mWingPlaneLevel);
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
            break;
        case 3:
            if (_isMax)
            {
                mArmorLevel = 6;
            }else
            {
                mArmorLevel++;
            };
            break;
        case 4:
            if (_isMax)
            {
                mWingPlaneLevel = 6;
            }else
            {
                mWingPlaneLevel++;
            };
            break;
        default:
            break;
    }
    
    int value = mMainPlaneLevel*1000 + mMissileLevel*100 + mArmorLevel*10 + mWingPlaneLevel;
    CCLog("========%d========%d",mPlayerType,value);
    LocalArchiveData::GetInstance()->SavePlayerData(mPlayerType, value);
}


int DataManager::GetFight()
{
    UpgradeData * data1 = GetUpgradeData(1);
    UpgradeData * data2 = GetUpgradeData(2);
    UpgradeData * data3 = GetUpgradeData(3);
    UpgradeData * data4 = GetUpgradeData(4);
    
    int fight = data1->mCurrValue + data2->mCurrValue + data3->mCurrValue + data4->mCurrValue;
    
    return fight;
}

int DataManager::GetMaxFight()
{
    
    UpgradeData * data1 = GetUpgradeData(1);
    UpgradeData * data2 = GetUpgradeData(2);
    UpgradeData * data3 = GetUpgradeData(3);
    UpgradeData * data4 = GetUpgradeData(4);
    
    int maxFight = data1->mMaxValue + data2->mMaxValue + data3->mMaxValue + data4->mMaxValue;
    
    return maxFight;
}

void DataManager::SetGameLevel(int _level)
{
    mGameLevel = _level;
}

int DataManager::GetGameLevel()
{
    return mGameLevel;
}









