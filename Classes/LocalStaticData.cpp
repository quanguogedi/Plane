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
    AddMainPlaneData(1, 1,"plane_fighter_01.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200,5800);
    AddMainPlaneData(1, 2,"plane_fighter_01.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800,5600);
    AddMainPlaneData(1, 3,"plane_fighter_01.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200,4800);
    AddMainPlaneData(1, 4,"plane_fighter_01.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600,3600);
    AddMainPlaneData(1, 5,"plane_fighter_01.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000,2000);
    AddMainPlaneData(1, 6,"plane_fighter_01.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000,2000);
    
    //第二类战机
    
    AddMainPlaneData(2, 1,"plane_fighter_02.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200,5800);
    AddMainPlaneData(2, 2,"plane_fighter_02.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800,5600);
    AddMainPlaneData(2, 3,"plane_fighter_02.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200,4800);
    AddMainPlaneData(2, 4,"plane_fighter_02.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600,3600);
    AddMainPlaneData(2, 5,"plane_fighter_02.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000,2000);
    AddMainPlaneData(2, 6,"plane_fighter_02.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000,2000);
    
    //第三类战机
    
    AddMainPlaneData(3, 1,"plane_fighter_03.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200,5800);
    AddMainPlaneData(3, 2,"plane_fighter_03.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800,5600);
    AddMainPlaneData(3, 3,"plane_fighter_03.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200,4800);
    AddMainPlaneData(3, 4,"plane_fighter_03.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600,3600);
    AddMainPlaneData(3, 5,"plane_fighter_03.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000,2000);
    AddMainPlaneData(3, 6,"plane_fighter_03.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000,2000);
    

    //第四类战机
    
    AddMainPlaneData(4, 1,"plane_fighter_04.png", "火烈鸟", "吊！很吊！非常吊！",  100, 400,2000, true, 200,5800);
    AddMainPlaneData(4, 2,"plane_fighter_04.png", "火烈鸟", "吊！很吊！非常吊！",  400, 800,2000, true, 800,5600);
    AddMainPlaneData(4, 3,"plane_fighter_04.png", "火烈鸟", "吊！很吊！非常吊！",  800, 1200,2000, true, 1200,4800);
    AddMainPlaneData(4, 4,"plane_fighter_04.png", "火烈鸟", "吊！很吊！非常吊！",  1200, 1600,2000, true, 1600,3600);
    AddMainPlaneData(4, 5,"plane_fighter_04.png", "火烈鸟", "吊！很吊！非常吊！",  1600, 2000,2000, true, 2000,2000);
    AddMainPlaneData(4, 6,"plane_fighter_04.png", "火烈鸟", "吊！很吊！非常吊！",  2000, 2000,2000, false, 2000,2000);
}

void LocalStaticData::LoadWingPlaneData()
{
    //第一类僚机
    AddWingPlaneData(1, 1,"plane_wing_01.png", "火烈鸟", "贱！很贱！非常贱！",  100, 400,2000, true, 200,5800);
    AddWingPlaneData(1, 2,"plane_wing_01.png", "火烈鸟", "贱！很贱！非常贱！",  400, 800,2000, true, 800,5600);
    AddWingPlaneData(1, 3,"plane_wing_01.png", "火烈鸟", "贱！很贱！非常贱！",  800, 1200,2000, true, 1200,4800);
    AddWingPlaneData(1, 4,"plane_wing_01.png", "火烈鸟", "贱！很贱！非常贱！",  1200, 1600,2000, true, 1600,3600);
    AddWingPlaneData(1, 5,"plane_wing_01.png", "火烈鸟", "贱！很贱！非常贱！",  1600, 2000,2000, true, 2000,2000);
    AddWingPlaneData(1, 6,"plane_wing_01.png", "火烈鸟", "贱！很贱！非常贱！",  2000, 2000,2000, false, 2000,2000);
    
    //第二类僚机
    
    AddWingPlaneData(2, 1,"plane_wing_02.png", "火烈鸟", "贱！很贱！非常贱！",  100, 400,2000, true, 200,5800);
    AddWingPlaneData(2, 2,"plane_wing_02.png", "火烈鸟", "贱！很贱！非常贱！",  400, 800,2000, true, 800,5600);
    AddWingPlaneData(2, 3,"plane_wing_02.png", "火烈鸟", "贱！很贱！非常贱！",  800, 1200,2000, true, 1200,4800);
    AddWingPlaneData(2, 4,"plane_wing_02.png", "火烈鸟", "贱！很贱！非常贱！",  1200, 1600,2000, true, 1600,3600);
    AddWingPlaneData(2, 5,"plane_wing_02.png", "火烈鸟", "贱！很贱！非常贱！",  1600, 2000,2000, true, 2000,2000);
    AddWingPlaneData(2, 6,"plane_wing_02.png", "火烈鸟", "贱！很贱！非常贱！",  2000, 2000,2000, false, 2000,2000);
    
    //第三类僚机
    
    AddWingPlaneData(3, 1,"plane_wing_03.png", "火烈鸟", "贱！很贱！非常贱！",  100, 400,2000, true, 200,5800);
    AddWingPlaneData(3, 2,"plane_wing_03.png", "火烈鸟", "贱！很贱！非常贱！",  400, 800,2000, true, 800,5600);
    AddWingPlaneData(3, 3,"plane_wing_03.png", "火烈鸟", "贱！很贱！非常贱！",  800, 1200,2000, true, 1200,4800);
    AddWingPlaneData(3, 4,"plane_wing_03.png", "火烈鸟", "贱！很贱！非常贱！",  1200, 1600,2000, true, 1600,3600);
    AddWingPlaneData(3, 5,"plane_wing_03.png", "火烈鸟", "贱！很贱！非常贱！",  1600, 2000,2000, true, 2000 ,2000);
    AddWingPlaneData(3, 6,"plane_wing_03.png", "火烈鸟", "贱！很贱！非常贱！",  2000, 2000,2000, false, 2000, 2000);
    
    
    //第四类僚机
    
    AddWingPlaneData(4, 1,"plane_wing_04.png", "火烈鸟", "贱！很贱！非常贱！",  100, 400,2000, true, 200,5800);
    AddWingPlaneData(4, 2,"plane_wing_04.png", "火烈鸟", "贱！很贱！非常贱！",  400, 800,2000, true, 800,5600);
    AddWingPlaneData(4, 3,"plane_wing_04.png", "火烈鸟", "贱！很贱！非常贱！",  800, 1200,2000, true, 1200,4800);
    AddWingPlaneData(4, 4,"plane_wing_04.png", "火烈鸟", "贱！很贱！非常贱！",  1200, 1600,2000, true, 1600,3600);
    AddWingPlaneData(4, 5,"plane_wing_04.png", "火烈鸟", "贱！很贱！非常贱！",  1600, 2000,2000, true, 2000,2000);
    AddWingPlaneData(4, 6,"plane_wing_04.png", "火烈鸟", "贱！很贱！非常贱！",  2000, 2000,2000, false,2000, 2000);
}

void LocalStaticData::LoadArmorData()
{
    //第一类装甲
    AddArmorData(1, 1,"plane_armor_01.png", "火烈鸟", "强！很强！非常强！",  100, 400,2000, true, 200,5800);
    AddArmorData(1, 2,"plane_armor_01.png", "火烈鸟", "强！很强！非常强！",  400, 800,2000, true, 800,5600);
    AddArmorData(1, 3,"plane_armor_01.png", "火烈鸟", "强！很强！非常强！",  800, 1200,2000, true, 1200,4800);
    AddArmorData(1, 4,"plane_armor_01.png", "火烈鸟", "强！很强！非常强！",  1200, 1600,2000, true, 1600,3600);
    AddArmorData(1, 5,"plane_armor_01.png", "火烈鸟", "强！很强！非常强！",  1600, 2000,2000, true, 2000,2000);
    AddArmorData(1, 6,"plane_armor_01.png", "火烈鸟", "强！很强！非常强！",  2000, 2000,2000, false, 2000,2000);
    
    //第二类装甲
    
    AddArmorData(2, 1,"plane_armor_02.png", "火烈鸟", "强！很强！非常强！",  100, 400,2000, true, 200,5800);
    AddArmorData(2, 2,"plane_armor_02.png", "火烈鸟", "强！很强！非常强！",  400, 800,2000, true, 800,5600);
    AddArmorData(2, 3,"plane_armor_02.png", "火烈鸟", "强！很强！非常强！",  800, 1200,2000, true, 1200,4800);
    AddArmorData(2, 4,"plane_armor_02.png", "火烈鸟", "强！很强！非常强！",  1200, 1600,2000, true, 1600,3600);
    AddArmorData(2, 5,"plane_armor_02.png", "火烈鸟", "强！很强！非常强！",  1600, 2000,2000, true, 2000,2000);
    AddArmorData(2, 6,"plane_armor_02.png", "火烈鸟", "强！很强！非常强！",  2000, 2000,2000, false, 2000,2000);
    
    //第三类装甲
    
    AddArmorData(3, 1,"plane_armor_03.png", "火烈鸟", "强！很强！非常强！",  100, 400,2000, true, 200,5800);
    AddArmorData(3, 2,"plane_armor_03.png", "火烈鸟", "强！很强！非常强！",  400, 800,2000, true, 800,5600);
    AddArmorData(3, 3,"plane_armor_03.png", "火烈鸟", "强！很强！非常强！",  800, 1200,2000, true, 1200,4800);
    AddArmorData(3, 4,"plane_armor_03.png", "火烈鸟", "强！很强！非常强！",  1200, 1600,2000, true, 1600,3600);
    AddArmorData(3, 5,"plane_armor_03.png", "火烈鸟", "强！很强！非常强！",  1600, 2000,2000, true, 2000,2000);
    AddArmorData(3, 6,"plane_armor_03.png", "火烈鸟", "强！很强！非常强！",  2000, 2000,2000, false, 2000,2000);
    
    
    //第四类装甲
    
    AddArmorData(4, 1,"plane_armor_04.png", "火烈鸟", "强！很强！非常强！",  100, 400,2000, true, 200,5800);
    AddArmorData(4, 2,"plane_armor_04.png", "火烈鸟", "强！很强！非常强！",  400, 800,2000, true, 800,5600);
    AddArmorData(4, 3,"plane_armor_04.png", "火烈鸟", "强！很强！非常强！",  800, 1200,2000, true, 1200,4800);
    AddArmorData(4, 4,"plane_armor_04.png", "火烈鸟", "强！很强！非常强！",  1200, 1600,2000, true, 1600,3600);
    AddArmorData(4, 5,"plane_armor_04.png", "火烈鸟", "强！很强！非常强！",  1600, 2000,2000, true, 2000,2000);
    AddArmorData(4, 6,"plane_armor_04.png", "火烈鸟", "强！很强！非常强！",  2000, 2000,2000, false, 2000,2000);
}

void LocalStaticData::LoadMissileData()
{
    //第一类导弹
    AddMissileData(1, 1,"plane_missile_01.png", "火烈鸟", "准！很准！非常准！",  100, 400,2000, true, 200,5800);
    AddMissileData(1, 2,"plane_missile_01.png", "火烈鸟", "准！很准！非常准！",  400, 800,2000, true, 800,5600);
    AddMissileData(1, 3,"plane_missile_01.png", "火烈鸟", "准！很准！非常准！",  800, 1200,2000, true, 1200,4800);
    AddMissileData(1, 4,"plane_missile_01.png", "火烈鸟", "准！很准！非常准！",  1200, 1600,2000, true, 1600,3600);
    AddMissileData(1, 5,"plane_missile_01.png", "火烈鸟", "准！很准！非常准！",  1600, 2000,2000, true, 2000,2000);
    AddMissileData(1, 6,"plane_missile_01.png", "火烈鸟", "准！很准！非常准！",  2000, 2000,2000, false,2000,2000);
    
    //第二类导弹
    
    AddMissileData(2, 1,"plane_missile_02.png", "火烈鸟", "准！很准！非常准！",  100, 400,2000, true, 200,5800);
    AddMissileData(2, 2,"plane_missile_02.png", "火烈鸟", "准！很准！非常准！",  400, 800,2000, true, 800,5600);
    AddMissileData(2, 3,"plane_missile_02.png", "火烈鸟", "准！很准！非常准！",  800, 1200,2000, true, 1200,4800);
    AddMissileData(2, 4,"plane_missile_02.png", "火烈鸟", "准！很准！非常准！",  1200, 1600,2000, true, 1600,3600);
    AddMissileData(2, 5,"plane_missile_02.png", "火烈鸟", "准！很准！非常准！",  1600, 2000,2000, true, 2000,2000);
    AddMissileData(2, 6,"plane_missile_02.png", "火烈鸟", "准！很准！非常准！",  2000, 2000,2000, false,2000,2000);
    
    //第三类导弹
    
    AddMissileData(3, 1,"plane_missile_03.png", "火烈鸟", "准！很准！非常准！",  100, 400,2000, true, 200,5800);
    AddMissileData(3, 2,"plane_missile_03.png", "火烈鸟", "准！很准！非常准！",  400, 800,2000, true, 800,5600);
    AddMissileData(3, 3,"plane_missile_03.png", "火烈鸟", "准！很准！非常准！",  800, 1200,2000, true, 1200,4800);
    AddMissileData(3, 4,"plane_missile_03.png", "火烈鸟", "准！很准！非常准！",  1200, 1600,2000, true, 1600,3600);
    AddMissileData(3, 5,"plane_missile_03.png", "火烈鸟", "准！很准！非常准！",  1600, 2000,2000, true, 2000,2000);
    AddMissileData(3, 6,"plane_missile_03.png", "火烈鸟", "准！很准！非常准！",  2000, 2000,2000, false,2000,2000);
    
    
    //导弹
    
    AddMissileData(4, 1,"plane_missile_04.png", "火烈鸟", "准！很准！非常准！",  100, 400,2000, true, 200,5800);
    AddMissileData(4, 2,"plane_missile_04.png", "火烈鸟", "准！很准！非常准！",  400, 800,2000, true, 800,5600);
    AddMissileData(4, 3,"plane_missile_04.png", "火烈鸟", "准！很准！非常准！",  800, 1200,2000, true, 1200,4800);
    AddMissileData(4, 4,"plane_missile_04.png", "火烈鸟", "准！很准！非常准！",  1200, 1600,2000, true, 1600,3600);
    AddMissileData(4, 5,"plane_missile_04.png", "火烈鸟", "准！很准！非常准！",  1600, 2000,2000, true, 2000,2000);
    AddMissileData(4, 6,"plane_missile_04.png", "火烈鸟", "准！很准！非常准！",  2000, 2000,2000, false,2000,2000);
}


void LocalStaticData::AddMainPlaneData(int _type,int _level,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost,int _upMaxCost)
{
    char key[10];
    memset(key, 0, sizeof(key));
    sprintf(key, "MainPlane%d%d",_type,_level);
 
    UpgradeData * value = new UpgradeData(_smallFile,_name,_disc,_currValue,_nextValue,_maxValue,_isCanUp,_upCost,_level,_upMaxCost);
    value->autorelease();
    
    mMainPlaneDic->setObject(value, key);
}

void LocalStaticData::AddWingPlaneData(int _type,int _level,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost,int _upMaxCost)
{
    char key[10];
    memset(key, 0, sizeof(key));
    sprintf(key, "WingPlane%d%d",_type,_level);
    
    UpgradeData * value = new UpgradeData(_smallFile,_name,_disc,_currValue,_nextValue,_maxValue,_isCanUp,_upCost,_level,_upMaxCost);
    value->autorelease();
    
    mWingPlaneDic->setObject(value, key);
}

void LocalStaticData::AddArmorData(int _type,int _level,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost,int _upMaxCost)
{
    char key[10];
    memset(key, 0, sizeof(key));
    sprintf(key, "Armor%d%d",_type,_level);
    
    UpgradeData * value = new UpgradeData(_smallFile,_name,_disc,_currValue,_nextValue,_maxValue,_isCanUp,_upCost,_level,_upMaxCost);
    value->autorelease();
    
    mArmorDic->setObject(value, key);
}


void LocalStaticData::AddMissileData(int _type,int _level,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost,int _upMaxCost)
{
    char key[10];
    memset(key, 0, sizeof(key));
    sprintf(key, "Missile%d%d",_type,_level);
    
    UpgradeData * value = new UpgradeData(_smallFile,_name,_disc,_currValue,_nextValue,_maxValue,_isCanUp,_upCost,_level,_upMaxCost);
    value->autorelease();
    
    mMissileDic->setObject(value, key);
}







