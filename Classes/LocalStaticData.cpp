//
//  LocalStaticData.cpp
//  BnB
//
//  Created by 杨延飞 on 14-12-15.
//
//

#include "LocalStaticData.h"

IMPLEMENT_SINGLETON(LocalStaticData)

LocalStaticData::LocalStaticData()
{
    mMainPlaneDic = CCDictionary::create();
    mMainPlaneDic->retain();
    
    mWingPlaneDic = CCDictionary::create();
    mWingPlaneDic->retain();
    
    mArmorDic = CCDictionary::create();
    mArmorDic->retain();
    
    mMissileDic = CCDictionary::create();
    mMissileDic->retain();
    
    LoadMainPlaneData();
    LoadWingPlaneData();
    LoadArmorData();
    LoadMissileData();
}

LocalStaticData::~LocalStaticData()
{
    CC_SAFE_RELEASE(mMainPlaneDic);
    CC_SAFE_RELEASE(mWingPlaneDic);
    CC_SAFE_RELEASE(mArmorDic);
    CC_SAFE_RELEASE(mMissileDic);
}




CCDictionary * LocalStaticData ::GetMainPlaneDic()
{
    return mMainPlaneDic;
}

CCDictionary * LocalStaticData::GetWingPlaneDic()
{
    return mWingPlaneDic;
}

CCDictionary * LocalStaticData::GetArmorDic()
{
    return mArmorDic;
}

CCDictionary * LocalStaticData::GetMissileDic()
{
    return mMissileDic;
}


void LocalStaticData::LoadMainPlaneData()
{
    //第一类战机
    AddMainPlaneData(1, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddMainPlaneData(1, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddMainPlaneData(1, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddMainPlaneData(1, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddMainPlaneData(1, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddMainPlaneData(1, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000);
    
    //第二类战机
    
    AddMainPlaneData(2, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddMainPlaneData(2, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddMainPlaneData(2, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddMainPlaneData(2, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddMainPlaneData(2, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddMainPlaneData(2, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000);
    
    //第三类战机
    
    AddMainPlaneData(3, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddMainPlaneData(3, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddMainPlaneData(3, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddMainPlaneData(3, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddMainPlaneData(3, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddMainPlaneData(3, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000);
    

    //第四类战机
    
    AddMainPlaneData(4, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddMainPlaneData(4, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddMainPlaneData(4, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddMainPlaneData(4, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddMainPlaneData(4, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddMainPlaneData(4, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000);
}

void LocalStaticData::LoadWingPlaneData()
{
    //第一类僚机
    AddWingPlaneData(1, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddWingPlaneData(1, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddWingPlaneData(1, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddWingPlaneData(1, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddWingPlaneData(1, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddWingPlaneData(1, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000);
    
    //第二类僚机
    
    AddWingPlaneData(2, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddWingPlaneData(2, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddWingPlaneData(2, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddWingPlaneData(2, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddWingPlaneData(2, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddWingPlaneData(2, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000);
    
    //第三类僚机
    
    AddWingPlaneData(3, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddWingPlaneData(3, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddWingPlaneData(3, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddWingPlaneData(3, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddWingPlaneData(3, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddWingPlaneData(3, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000);
    
    
    //第四类僚机
    
    AddWingPlaneData(4, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddWingPlaneData(4, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddWingPlaneData(4, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddWingPlaneData(4, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddWingPlaneData(4, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddWingPlaneData(4, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false,2000);
}

void LocalStaticData::LoadArmorData()
{
    //第一类装甲
    AddArmorData(1, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddArmorData(1, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddArmorData(1, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddArmorData(1, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddArmorData(1, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddArmorData(1, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000);
    
    //第二类装甲
    
    AddArmorData(2, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddArmorData(2, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddArmorData(2, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddArmorData(2, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddArmorData(2, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddArmorData(2, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000);
    
    //第三类装甲
    
    AddArmorData(3, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddArmorData(3, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddArmorData(3, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddArmorData(3, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddArmorData(3, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddArmorData(3, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000);
    
    
    //第四类装甲
    
    AddArmorData(4, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddArmorData(4, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddArmorData(4, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddArmorData(4, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddArmorData(4, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddArmorData(4, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000);
}

void LocalStaticData::LoadMissileData()
{
    //第一类导弹
    AddMissileData(1, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddMissileData(1, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddMissileData(1, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddMissileData(1, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddMissileData(1, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddMissileData(1, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false,2000);
    
    //第二类导弹
    
    AddMissileData(2, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddMissileData(2, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddMissileData(2, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddMissileData(2, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddMissileData(2, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddMissileData(2, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false,2000);
    
    //第三类导弹
    
    AddMissileData(3, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddMissileData(3, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddMissileData(3, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddMissileData(3, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddMissileData(3, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddMissileData(3, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false,2000);
    
    
    //导弹
    
    AddMissileData(4, 1, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200);
    AddMissileData(4, 2, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800);
    AddMissileData(4, 3, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200);
    AddMissileData(4, 4, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600);
    AddMissileData(4, 5, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000);
    AddMissileData(4, 6, "big.png","small.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false,2000);
}


void LocalStaticData::AddMainPlaneData(int _type,int _level,const char * _bigFile,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost)
{
    char key[10];
    memset(key, 0, sizeof(key));
    sprintf(key, "MainPlane%d%d",_type,_level);
 
    UpgradeData * value = new UpgradeData(_bigFile,_smallFile,_name,_disc,_currValue,_nextValue,_maxValue,_isCanUp,_upCost);
    value->autorelease();
    
    mMainPlaneDic->setObject(value, key);
}

void LocalStaticData::AddWingPlaneData(int _type,int _level,const char * _bigFile,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost)
{
    char key[10];
    memset(key, 0, sizeof(key));
    sprintf(key, "WingPlane%d%d",_type,_level);
    
    UpgradeData * value = new UpgradeData(_bigFile,_smallFile,_name,_disc,_currValue,_nextValue,_maxValue,_isCanUp,_upCost);
    value->autorelease();
    
    mWingPlaneDic->setObject(value, key);
}

void LocalStaticData::AddArmorData(int _type,int _level,const char * _bigFile,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost)
{
    char key[10];
    memset(key, 0, sizeof(key));
    sprintf(key, "Armor%d%d",_type,_level);
    
    UpgradeData * value = new UpgradeData(_bigFile,_smallFile,_name,_disc,_currValue,_nextValue,_maxValue,_isCanUp,_upCost);
    value->autorelease();
    
    mArmorDic->setObject(value, key);
}


void LocalStaticData::AddMissileData(int _type,int _level,const char * _bigFile,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost)
{
    char key[10];
    memset(key, 0, sizeof(key));
    sprintf(key, "Missile%d%d",_type,_level);
    
    UpgradeData * value = new UpgradeData(_bigFile,_smallFile,_name,_disc,_currValue,_nextValue,_maxValue,_isCanUp,_upCost);
    value->autorelease();
    
    mMissileDic->setObject(value, key);
}







