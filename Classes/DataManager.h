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
    
    void SetPlayerType(int _type);
    int GetPlayerType();
    
    UpgradeData * GetUpgradeData(int _type);
    void SavaUpgradeData(int _type,bool _isMax = false);
    
private:
    int mPlayerType;
    int mMainPlaneLevel;
    int mMissileLevel;
    int mArmorLevel;
    int mWingPlaneLevel;
};


#endif /* defined(__Plane__DataManager__) */
