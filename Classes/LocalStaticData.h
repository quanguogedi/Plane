//
//  LocalStaticData.h
//  BnB
//
//  Created by 杨延飞 on 14-12-15.
//
// 本地静态数据,所有的地图数据和 所有的数据信息

#ifndef __BnB__LocalStaticData__
#define __BnB__LocalStaticData__
#include "Common.h"
#include "Singleton.h"
#define MUSIC_PATH(res) CCString::createWithFormat("%s%s", "res/music/", (res))->getCString()
class LocalStaticData
{
    DECLARE_SINGLETON(LocalStaticData);
public:
    CCDictionary * GetMainPlaneDic();//主机数据字典
    CCDictionary * GetWingPlaneDic();//僚机数据字典
    CCDictionary * GetArmorDic();//装甲数据字典
    CCDictionary * GetMissileDic();//导弹数据字典
    
    
    
private:
    LocalStaticData();
    ~LocalStaticData();
    void LoadLocalStaticData();//加载所有数据
    
    void LoadMainPlaneData();
    void LoadWingPlaneData();
    void LoadArmorData();
    void LoadMissileData();
    
    /*
     Method:
        AddMainPlaneData();
     parameters:
        _type:战机类型
        _level:战机等级
        _bigFile:战斗中用到的图片名字
        _smallFile:升级时小图片的名字
        _name:战机的名字
        _disc:战机的描述
        _currValue:当前等级的战斗力(或者血量)
        _nextValue:下一等级的战斗力
        _maxValue;最大攻击力
        _isCanUp:是否能升级(是否已经满级了)
        _upCost:升级花费钻石的数量
     
     */
    
    void AddMainPlaneData(int _type,int _level,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost,int _upMaxCost);
    
    void AddWingPlaneData(int _type,int _level,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost,int _upMaxCost);
    
    void AddArmorData(int _type,int _level,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost,int _upMaxCost);
    
    void AddMissileData(int _type,int _level,const char * _smallFile,const char * _name,const char * _disc, int _currValue,int _nextValue,int _maxValue,bool _isCanUp,int _upCost,int _upMaxCost);

private:
    CCDictionary * mMainPlaneDic;//所有主机数据字典
    CCDictionary * mWingPlaneDic;//所有僚机数据字典
    CCDictionary * mArmorDic;//所有装甲数据字典
    CCDictionary * mMissileDic;//所有导弹数据字典
    
};

#endif /* defined(__BnB__LocalStaticData__) */
