//
//  LocalStaticData.cpp
//  BnB
//
//  Created by 杨延飞 on 14-12-15.
//
//

#include "LocalStaticData.h"

IMPLEMENT_SINGLETON(LocalStaticData)

CCDictionary * LocalStaticData::GetMapDictionary()
{
    return mMapDictionary;
}

CCDictionary * LocalStaticData::GetRoleDictionary()
{
    return mRoleDictionnary;
}

CCDictionary * LocalStaticData::GetEnemyDictionary()
{
    return mEnemyDictionary;
}

CCDictionary * LocalStaticData::GetPropDictionary()
{
    return mPropDictionary;
}

CCDictionary * LocalStaticData::GetSkillDictionary()
{
    return mSkillDictionary;
}

CCDictionary * LocalStaticData::GetSectionDictionary()
{
    return mSectionDictionary;
}

CCDictionary * LocalStaticData::GetMusicDictionary()
{
    return mMusicDictionary;
}

CCDictionary * LocalStaticData::GetGameBgDictionary()
{
    return mGameBgDictionary;
}

void LocalStaticData::LoadLocalStaticData()
{
    
}

LocalStaticData::LocalStaticData()
{
    mMapDictionary = CCDictionary::create();
    mMapDictionary->retain();
    
    mRoleDictionnary = CCDictionary::create();
    mRoleDictionnary->retain();
    
    mEnemyDictionary = CCDictionary::create();
    mEnemyDictionary->retain();
    
    mPropDictionary = CCDictionary::create();
    mPropDictionary->retain();
    
    mSkillDictionary = CCDictionary::create();
    mSkillDictionary->retain();
    
    mSectionDictionary = CCDictionary::create();
    mSectionDictionary->retain();
    
    mMusicDictionary = CCDictionary::create();
    mMusicDictionary->retain();
    
    mGameBgDictionary = CCDictionary::create();
    mGameBgDictionary->retain();
}

LocalStaticData::~LocalStaticData()
{
    CC_SAFE_RELEASE(mMapDictionary);
    CC_SAFE_RELEASE(mRoleDictionnary);
    CC_SAFE_RELEASE(mEnemyDictionary);
    CC_SAFE_RELEASE(mPropDictionary);
    CC_SAFE_RELEASE(mSkillDictionary);
    CC_SAFE_RELEASE(mSectionDictionary);
    CC_SAFE_RELEASE(mMusicDictionary);
    CC_SAFE_RELEASE(mGameBgDictionary);
}







