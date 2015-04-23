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
    mSoundEnable = CocosSaveManager::GetInstance()->getBoolForKey("SoundEnable",true);
    mMusicEnable = CocosSaveManager::GetInstance()->getBoolForKey("MusicEnable",true);
    mDiamondCount = CocosSaveManager::GetInstance()->getIntegerForKey("DiamondCount",1234);
    mKillerCount = CocosSaveManager::GetInstance()->getIntegerForKey("KillerCount", 3);
    mShieldCount = CocosSaveManager::GetInstance()->getIntegerForKey("ShieldCount", 3);

}

void LocalArchiveData::SaveSoundEnable(bool _enable)
{
    mSoundEnable = _enable;
    CocosSaveManager::GetInstance()->setBoolForKey("SoundEnable", mSoundEnable);
}

void LocalArchiveData::SaveMusicEnable(bool _enable)
{
    mMusicEnable = _enable;
    CocosSaveManager::GetInstance()->setBoolForKey("MusicEnable", mMusicEnable);
}

void LocalArchiveData::SaveDiamondCount(int _change)
{
    mDiamondCount += _change;
    CocosSaveManager::GetInstance()->setIntegerForKey("DiamondCount", mDiamondCount);
}

void LocalArchiveData::SaveKillerCount(int _change)
{
    mKillerCount += _change;
    CocosSaveManager::GetInstance()->setIntegerForKey("KillerCount", mKillerCount);
}

void LocalArchiveData::SaveShieldCount(int _change)
{
    mShieldCount += _change;
    CocosSaveManager::GetInstance()->setIntegerForKey("ShieldCount",mShieldCount );
}



void LocalArchiveData::SavePlayerData(int _type, int _value)
{
    CCString * key = CCString::createWithFormat("PlayerData%d",_type);
    CocosSaveManager::GetInstance()->setIntegerForKey(key->getCString(), _value);
}

int LocalArchiveData::GetPlayerDataByType(int _type)
{
    CCString * key = CCString::createWithFormat("PlayerData%d",_type);
   
    int player = 0;
    
    if (_type == 1)
    {
        player = CocosSaveManager::GetInstance()->getIntegerForKey(key->getCString(), 1111);
    }else
    {
        player = CocosSaveManager::GetInstance()->getIntegerForKey(key->getCString(), 0);
    }
    
    
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

int LocalArchiveData::LoadUnlockLevelCount()
{
    int num = CocosSaveManager::GetInstance()->getIntegerForKey("UnLockLevelCount", 1);
    return  num;
}
void LocalArchiveData::SaveUnLockLevelCount(int _count)
{
    if (_count > LoadUnlockLevelCount())
    {
        CocosSaveManager::GetInstance()->setIntegerForKey("UnLockLevelCount", _count);
    }
    
}


