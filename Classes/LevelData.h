//
//  LevelData.h
//  Plane
//
//  Created by ml on 15-1-22.
//
//

#ifndef __Plane__LevelData__
#define __Plane__LevelData__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

#include "Singleton.h"

enum EnemyStartType
{
    EnemyStartTypeNone = 0,
    EnemyStartTypeTop,
    EnemyStartTypeTopLeft,
    EnemyStartTypeTopRight,
    
    EnemyStartTypeLeft,
    EnemyStartTypeRight,
    
    EnemyStartTypeLeft2,
    EnemyStartTypeRight2,
    
    EnemyStartTypeMax,
};

class LevelSubData : public CCObject
{
public:
    static LevelSubData* create(float time, int enemyType, int startType, int moveType);
   
    virtual bool init(float time, int enemyType, int startType, int moveType);
    
public:
    float mTime; //出现时间
    int mEnemyType; //敌机外观类型
    int mStartType; //初始位置
    int mMoveType;//移动轨迹类型
    
};


class LevelData : public CCObject
{
public:
    LevelData();
    ~LevelData();
    
    CREATE_FUNC(LevelData);
    virtual bool init();
    
public:
    void AddLevelSubData(LevelSubData* subData);
    LevelSubData* GetLevelSubData(int subLevelIndex);
    
public:
    int mLevelID;
    CCString* mLevelName;
    CCString* mLevelDesc;
    
private:
    CCArray* mSubLevelArray;
};


class LevelManager
{
    DECLARE_SINGLETON(LevelManager)
public:
    LevelManager();
    ~LevelManager();
    void Init();
    
public:
    LevelData* GetLevelData(int level);
    
private:
    CCDictionary* mAllLevelDict;
    
};



#endif /* defined(__Plane__LevelData__) */
