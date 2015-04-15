//
//  CCBIManager.h
//  BnB
//
//  Created by 杨延飞 on 14-10-28.
//
//

#ifndef __BnB__CCBIManager__
#define __BnB__CCBIManager__

#define LAYER_RES_PATH "Resources/"
#include "Common.h"

class CCBManager
{
//    DECLARE_SINGLETON(CCBManager);
public:
    static CCNode * LoadCCBByNameAndLoader(const char * _ccbName,CCNodeLoader * _loader);
    static CCNode * LoadCCBByNameAndLoader(CCArray * _ccbNameArr,CCArray * _loaderArr);
    
};

#endif /* defined(__BnB__CCBIManager__) */
