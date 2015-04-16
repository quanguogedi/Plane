//
//  SaveData.cpp
//  BnB
//
//  Created by wxf on 12/10/14.
//
//

#include "LocalArchiveData.h"


IMPLEMENT_SINGLETON(LocalArchiveData)


void LocalArchiveData::LoadArchiveData()
{
   
    
    mIsScoundEnable = CocosSaveManager::GetInstance()->getBoolForKey("SoundState",true);
    mIsMusicEnable = CocosSaveManager::GetInstance()->getBoolForKey("MusicState",true);
// 
//    mRole->mPhysicalData = CocosSaveManager::GetInstance()->getIntegerForKey("PhysicalData", 46);
//    mRole->mCheckTime = CocosSaveManager::GetInstance()->getIntegerForKey("CheckTime", Tools::getCurrentTime());
//    mRole->mMaxPhysicalData =  Tools::getMaxPhysiclByLevel(mRole->mLevel);
//    mCopterSection = CocosSaveManager::GetInstance()->getIntegerForKey("CopterSection", 1);
//    mCopterLevel = CocosSaveManager::GetInstance()->getIntegerForKey("CopterLevel", 1);
//    mBattleSecion = CocosSaveManager::GetInstance()->getIntegerForKey("BattleSecion ", 1);
//    mBattleLevel = CocosSaveManager::GetInstance()->getIntegerForKey("BattleLevel", 1);
//    mIsShowGuide = CocosSaveManager::GetInstance()->getIntegerForKey("IsShowGuide", true);
//    mSoundEnable = CocosSaveManager::GetInstance()->getIntegerForKey("SoundEnable",true);
}

void LocalArchiveData::SaveArchiveData()
{
    CocosSaveManager::GetInstance()->setBoolForKey("SoundState", mIsScoundEnable);
    CocosSaveManager::GetInstance()->setBoolForKey("MusicState", mIsMusicEnable);
//    CocosSaveManager::GetInstance()->setIntegerForKey("money", mRole->mMoney);
//    CocosSaveManager::GetInstance()->setIntegerForKey("goodHave", mRole->mGoodHave);
//    CocosSaveManager::GetInstance()->setIntegerForKey("badHave", mRole->mBadHave);
//    CocosSaveManager::GetInstance()->setIntegerForKey("goodLock", mRole->mGoodLock);
//    CocosSaveManager::GetInstance()->setIntegerForKey("badLock", mRole->mBadLock);
//    CocosSaveManager::GetInstance()->setIntegerForKey("checkHead", mRole->mCheckHead);
//    CocosSaveManager::GetInstance()->setIntegerForKey("checkRole", mRole->mCheckRole);
//    CocosSaveManager::GetInstance()->setStringForKey("roleName", mRole->mName->getCString());
//    CocosSaveManager::GetInstance()->setIntegerForKey("roleLevel", mRole->mLevel);
//    CocosSaveManager::GetInstance()->setIntegerForKey("roleExp", mRole->mExp);
//    CocosSaveManager::GetInstance()->setIntegerForKey("PhysicalData", mRole->mPhysicalData);
//    CocosSaveManager::GetInstance()->setIntegerForKey("CheckTime", mRole->mCheckTime);
//    CocosSaveManager::GetInstance()->setIntegerForKey("CopterSection", mCopterSection);
//    CocosSaveManager::GetInstance()->setIntegerForKey("CopterLevel", mCopterLevel);
//    CocosSaveManager::GetInstance()->setIntegerForKey("BattleSecion", mBattleSecion);
//    CocosSaveManager::GetInstance()->setIntegerForKey("BattleLevel", mBattleLevel);
//    CocosSaveManager::GetInstance()->setIntegerForKey("IsShowGuide", mIsShowGuide);
//    CocosSaveManager::GetInstance()->setIntegerForKey("SoundEnable", mSoundEnable);
}

void LocalArchiveData::SaveLevelStar( int _level,int _star)
{
//    CCString * key1 = CCString::createWithFormat("LevelStar%d%d",_section,_level);
//    CCString * key2 =CCString::createWithFormat("SectionStar%d",_section);
//    CCString * key3 =CCString::create("AllStar");
//   
// 
//    int addStar = _star - CocosSaveManager::GetInstance()->getIntegerForKey(key1->getCString(), 0);
//    int sectionStar = CocosSaveManager::GetInstance()->getIntegerForKey(key2->getCString(), 0);
//    int allStar = CocosSaveManager::GetInstance()->getIntegerForKey(key3->getCString(), 0);
//    
//    if (addStar > 0)
//    {
//        allStar += addStar;
//        sectionStar += addStar;
//        CocosSaveManager::GetInstance()->setIntegerForKey(key1->getCString(), _star);
//        CocosSaveManager::GetInstance()->setIntegerForKey(key2->getCString(), sectionStar);
//        CocosSaveManager::GetInstance()->setIntegerForKey(key3->getCString(), allStar);
//    }
    
    
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



