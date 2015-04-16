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
    CCDictionary * GetMapDictionary();//获得所有地图数据
    CCDictionary * GetRoleDictionary();//获得所有角色数据
    CCDictionary * GetEnemyDictionary();//获得所有怪物数据
    CCDictionary * GetPropDictionary();//获得所有道具数据
    CCDictionary * GetSkillDictionary();//获得技能数据
    CCDictionary * GetSectionDictionary();//章节字典
    CCDictionary * GetMusicDictionary();//音乐字典
    CCDictionary * GetGameBgDictionary();//游戏界面背景
    void LoadLocalStaticData();
private:
    LocalStaticData();
    ~LocalStaticData();

private:
    CCDictionary * mMapDictionary;//所有地图数据的字典
    CCDictionary * mRoleDictionnary;//所有角色数据的字典
    CCDictionary * mEnemyDictionary;//所有怪物数据的字典
    CCDictionary * mPropDictionary;//所有道具数据的字典
    CCDictionary * mSkillDictionary;//所有技能数据的字典
    CCDictionary * mSectionDictionary;//所有章节数据
    CCDictionary * mMusicDictionary;//所有音乐的字典
    CCDictionary * mGameBgDictionary;//游戏场景的背景字典
    
};

#endif /* defined(__BnB__LocalStaticData__) */
