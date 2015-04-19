//
//  SaveData.cpp
//  BnB
//
//  Created by wxf on 12/10/14.
//
//

#include "LocalArchiveData.h"


IMPLEMENT_SINGLETON(LocalArchiveData)

LocalArchiveData::LocalArchiveData()
{
    LoadArchiveData();
}


void LocalArchiveData::LoadArchiveData()
{
    CocosSaveManager::GetInstance()->setIntegerForKey("PlayerData1", 1111);
    
    mIsScoundEnable = CocosSaveManager::GetInstance()->getBoolForKey("SoundState",true);
    mIsMusicEnable = CocosSaveManager::GetInstance()->getBoolForKey("MusicState",true);

}

void LocalArchiveData::SaveArchiveData()
{
    CocosSaveManager::GetInstance()->setBoolForKey("SoundState", mIsScoundEnable);
    CocosSaveManager::GetInstance()->setBoolForKey("MusicState", mIsMusicEnable);

}

void LocalArchiveData::SavePlayerData(int _type, int _value)
{
    CCString * key = CCString::createWithFormat("PlayerData%d",_type);
    CocosSaveManager::GetInstance()->setIntegerForKey(key->getCString(), _value);
}

int LocalArchiveData::GetPlayerDataByType(int _type)
{
    CCString * key = CCString::createWithFormat("PlayerData%d",_type);
    
    int player = CocosSaveManager::GetInstance()->getIntegerForKey(key->getCString(), 0);
    
    return player;
}



void LocalArchiveData::SaveLevelStar( int _level,int _star)
{

    
}

int LocalArchiveData::LoadLevelStar( int _level)
{
    
    CCString * key = CCString::createWithFormat("LevelStar%d",_level);
    int num = CocosSaveManager::GetInstance()->getIntegerForKey(key->getCString(), 0);
    return  num;
}

int LocalArchiveData::LoadAllStart()
{
    int num = CocosSaveManager::GetInstance()->getIntegerForKey("AllStar", 0);
    return num;
}



