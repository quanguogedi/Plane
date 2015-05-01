#include "GameEvents.h"
#include "GameMenu.h"
#include "GameManager.h"
#include "GameOver.h"

//int g_iGameLevel = LEVEL_ONE;

void CGameEvents::startFlipInterface(int iType)
{
	CCScene *pScene;
	if(iType == GAME_MENU)
	{
//		pScene = CCTransitionSplitRows::create(1.0f, CGameMenu::scene());
        pScene = CGameMenu::scene();
	}
	else if(iType == GAME_LEVEL)
	{
//		pScene = CCTransitionSplitRows::create(1.0f, CGameLevel::scene());
        pScene = CGameLevel::scene();
	}
	else if(iType == GAME_START)
	{
//		pScene = CCTransitionSplitRows::create(1.0f, CGameManager::scene());
        pScene = CGameManager::scene();
	}
    else if(iType == GAME_CLEAR)
    {
//        pScene = CCTransitionSplitRows::create(1.0f, CGameOver::scene());
        pScene = CGameOver::scene();
    }
	else if(iType == GAME_OVER)
	{
//		pScene = CCTransitionSplitRows::create(1.0f, ::scene());
        pScene = CGameOver::scene();
	}
	else
		return;

	CCDirector::sharedDirector()->replaceScene(pScene);
}