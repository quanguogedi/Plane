#pragma once


#include "BaseScene.h"
#include "GameLevel.h"

enum{
	GAME_MENU = 1,  // 游戏菜单,
	GAME_LEVEL,     // 游戏关卡
	GAME_START,     // 游戏开始
    GAME_CLEAR,     // 游戏过关
	GAME_OVER,      // 游戏结束
};
//extern int g_iGameLevel;		// 游戏关卡

class CGameEvents : public CBaseScene
{
public:
	/**	开始翻屏	*/
	static void startFlipInterface(int iType);
	
	/**	创建函数	*/
    CREATE_FUNC(CGameEvents);

};