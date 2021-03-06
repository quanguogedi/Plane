//
//  Common.h
//  Plane
//
//  Created by 杨延飞 on 14-11-22.
//
//

#ifndef Plane_Common_h
#define Plane_Common_h

#define SCREEN_W    720
#define SCREEN_H    1280

#define RUNNIGSCENE_TAG 12306

#define FIRSTLEVEL_LAYERTOUCH -129
#define FIRSTLEVEL_MENUTOUCH -135
#define FIRSTLEVEL_LAYERORDER 100

#define SECONDLEVEL_LAYERTOUCH -139
#define SECONDLEVEL_MENUTOUCH -145
#define SECONDLEVEL_LAYERORDER 200

#define THIRDLEVEL_LAYERTOUCH -149
#define THIRDLEVEL_MENUTOUCH -155
#define THIRDLEVEL_LAYERORDER 300

#include "cocos2d.h"
USING_NS_CC;

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#include <cocos-ext.h>
USING_NS_CC_EXT;

using namespace std;

#include <string.h>

#include "GameData.h"
#include "LocalStaticData.h"
#include "LocalArchiveData.h"
#include "DataManager.h"


#include "PrototypeDataManager.h"

#include "CCBManager.h"

#include "PlaneNotification.h"//宏定义


enum
{
    LEVEL_ONE = 1,
    LEVEL_TWO,
    LEVEL_THREE,
};

#endif
