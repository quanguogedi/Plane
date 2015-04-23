//
//  SaveData.h
//  BnB
//
//  Created by wxf on 12/10/14.
//
// 本地存档数据,解锁的人物信息 关卡信息等

#ifndef __BnB__SaveData__
#define __BnB__SaveData__
#include "Common.h"
#include "Singleton.h"
#include "CocosSaveManager.h"


class LocalArchiveData
{
    DECLARE_SINGLETON(LocalArchiveData);
private:
    LocalArchiveData();
    void LoadArchiveData();
public:
    
    bool mSoundEnable;//是否能播放音效
    bool mMusicEnable;//是否能播放背景音乐
    int mDiamondCount;//钻石的数量
    int mKillerCount;//大招的数量
    int mShieldCount;//护盾的数量
   
    
    
    void SaveSoundEnable(bool _enable);
    void SaveMusicEnable(bool _enable);
    void SaveDiamondCount(int _change);
    void SaveKillerCount(int _change);
    void SaveShieldCount(int _change);
    
    
    
    void SavePlayerData(int _type,int _value);
    int GetPlayerDataByType(int _type);
    
    void SaveLevelStar(int _level,int _star);
    int LoadLevelStar(int _level);
    int LoadAllStart();
    
    int LoadUnlockLevelCount();
    void SaveUnLockLevelCount(int _count);


};
#endif /* defined(__BnB__SaveData__) */
