#pragma once


#include "BaseScene.h"
#include "GameLevel.h"

enum{
	GAME_MENU = 1,  // ��Ϸ�˵�,
	GAME_LEVEL,     // ��Ϸ�ؿ�
	GAME_START,     // ��Ϸ��ʼ
    GAME_CLEAR,     // ��Ϸ����
	GAME_OVER,      // ��Ϸ����
};
//extern int g_iGameLevel;		// ��Ϸ�ؿ�

class CGameEvents : public CBaseScene
{
public:
	/**	��ʼ����	*/
	static void startFlipInterface(int iType);
	
	/**	��������	*/
    CREATE_FUNC(CGameEvents);

};