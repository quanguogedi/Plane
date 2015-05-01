//
//  DataManager.h
//  Plane
//
//  Created by 姜彬彬 on 4/19/15.
//
//

#ifndef __Plane__DataManager__
#define __Plane__DataManager__

#include "Common.h"
#include "Singleton.h"



class DataManager:public CCObject
{
    DECLARE_SINGLETON(DataManager)

   
public:
    DataManager();
    ~DataManager();
    void Init();
    
    void ResetData();
    
    void SetPlayerType(int _type);
    int GetPlayerType();
    
    UpgradeData * GetUpgradeData(int _type);
    void SavaUpgradeData(int _type,bool _isMax = false);
    
    int GetFight();
    int GetMaxFight();
    
    void SetGameLevel(int _level);
    int GetGameLevel();
    
    void SetScore(int _change);
    int GetScore();
    
    void SetHp();
    float GetHpPCT();
    
    void SetDiamond(int _diamond);
    int GetDiamond();
    
    void SetStar(int _star);
    int GetStar();
    
    void SetResult(bool _result);
    bool GetResult();
    
    void SetLevelState(bool _state);
    bool GetLevelState();
    
    void PlayBMG(MusicType _type, bool _repeat);
    int PlayEffect(MusicType _type, bool _repeat);
    
    
private:
    int mPlayerType;
    int mMainPlaneLevel;
    int mMissileLevel;
    int mArmorLevel;
    int mWingPlaneLevel;
    int mGameLevel;//开始游戏的关卡

    int mScore;
    int mMaxHp;
    int mHp;
    
    int mDiamond;
    int mStar;
    
    bool mResult;
    bool mLevelState;//管卡场景的状态 如果true 要显示强化战机界面
    
    MusicType mBgMusicType;
    
    
};


#endif /* defined(__Plane__DataManager__) */
