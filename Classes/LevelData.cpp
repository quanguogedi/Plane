//
//  LevelData.cpp
//  Plane
//
//  Created by ml on 15-1-22.
//
//

#include "LevelData.h"


LevelSubData* LevelSubData::create(float time, int enemyType, int startType, int moveType)
{
    LevelSubData* data = new LevelSubData;
    data->init(time, enemyType, startType, moveType);
    data->autorelease();
    
    return data;
}

bool LevelSubData::init(float time, int enemyType, int startType, int moveType)
{
    mTime = time;
    mEnemyType = enemyType;
    mStartType = startType;
    mMoveType = moveType;
    
    return true;
}

//////////////////////////////////////////////////////////////////////////////

LevelData::LevelData()
{
    
}

LevelData::~LevelData()
{
    CC_SAFE_RELEASE_NULL(mSubLevelArray);
}

bool LevelData::init()
{
    mSubLevelArray = new CCArray;
    
    return true;
}

void LevelData::AddLevelSubData(LevelSubData* subData)
{
    if(!subData)
    {
        return;
    }
    
    mSubLevelArray->addObject(subData);
}

LevelSubData* LevelData::GetLevelSubData(int subLevelIndex)
{
    LevelSubData* subData = NULL;
    if (subLevelIndex < mSubLevelArray->count())
    {
        subData = (LevelSubData*)mSubLevelArray->objectAtIndex(subLevelIndex);
    }
    
    return subData;
}

/////////////////////////////////////////////////////////////////////////////////

IMPLEMENT_SINGLETON(LevelManager)

LevelManager::LevelManager()
{
    Init();
}

LevelManager::~LevelManager()
{
    CC_SAFE_RELEASE_NULL(mAllLevelDict);
}

void LevelManager::Init()
{
    mAllLevelDict = new CCDictionary;
    
    LevelData* levelData;
    
    //level 1
    levelData = LevelData::create();
    levelData->mLevelID = 1;
    levelData->AddLevelSubData(LevelSubData::create(5, 1, 1, 1));
    levelData->AddLevelSubData(LevelSubData::create(10, 1, 2, 1));
    levelData->AddLevelSubData(LevelSubData::create(10, 1, 3, 1));
    levelData->AddLevelSubData(LevelSubData::create(12, 1, 1, 1));
    levelData->AddLevelSubData(LevelSubData::create(13, 1, 2, 3));
    levelData->AddLevelSubData(LevelSubData::create(13, 1, 3, 2));
    levelData->AddLevelSubData(LevelSubData::create(13, 1, 4, 5));
    levelData->AddLevelSubData(LevelSubData::create(13, 1, 5, 4));
    levelData->AddLevelSubData(LevelSubData::create(15, 1, 2, 3));
    levelData->AddLevelSubData(LevelSubData::create(15, 1, 3, 2));
    levelData->AddLevelSubData(LevelSubData::create(15, 1, 4, 5));
    levelData->AddLevelSubData(LevelSubData::create(15, 1, 5, 4));
    levelData->AddLevelSubData(LevelSubData::create(20, 1, 1, 1));
    levelData->AddLevelSubData(LevelSubData::create(20, 1, 6, 1));
    levelData->AddLevelSubData(LevelSubData::create(20, 1, 7, 1));
    levelData->AddLevelSubData(LevelSubData::create(23, 1, 1, 1));
    levelData->AddLevelSubData(LevelSubData::create(25, 1, 6, 5));
    levelData->AddLevelSubData(LevelSubData::create(25, 1, 7, 4));
    levelData->AddLevelSubData(LevelSubData::create(28, 1, 4, 1));
    levelData->AddLevelSubData(LevelSubData::create(28, 1, 5, 1));
    levelData->AddLevelSubData(LevelSubData::create(30, 1, 6, 5));
    levelData->AddLevelSubData(LevelSubData::create(30, 1, 7, 4));
    levelData->AddLevelSubData(LevelSubData::create(35, 1, 1, 1));
    levelData->AddLevelSubData(LevelSubData::create(35, 1, 4, 5));
    levelData->AddLevelSubData(LevelSubData::create(35, 1, 5, 4));
    levelData->AddLevelSubData(LevelSubData::create(40, 1, 3, 3));
    levelData->AddLevelSubData(LevelSubData::create(40, 1, 2, 2));
    levelData->AddLevelSubData(LevelSubData::create(50, 0, 0, 0));
    
    mAllLevelDict->setObject(levelData, levelData->mLevelID);
    
    //level2
}

LevelData* LevelManager::GetLevelData(int level)
{
    LevelData* data = (LevelData*)mAllLevelDict->objectForKey(level);
    
    return data;
}


