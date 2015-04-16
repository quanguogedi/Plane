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
public:
    bool mIsScoundEnable;//是否能播放音效
    bool mIsMusicEnable;//是否能播放背景音乐
    int mFinishLevel;//闯关数
   
    
    void LoadArchiveData();
    void SaveArchiveData();
    
    void SaveLevelStar(int _level,int _star);
    int LoadLevelStar(int _level);
    int LoadAllStart();


};
#endif /* defined(__BnB__SaveData__) */
