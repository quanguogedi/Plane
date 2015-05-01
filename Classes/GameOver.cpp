#include "GameOver.h"

#include "GameEvents.h"

#include "GameOverLayer.h"
CCScene* CGameOver::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        CGameOver *layer = CGameOver::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

bool CGameOver::init()
{
    bool bRet = false;

    do{
        CC_BREAK_IF(!CBaseScene::init());
        
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		
		/**	±³¾°	*/
		CCSprite *pBackGround = CCSprite::create("res/ui_bj_01.png");
		CC_BREAK_IF(! pBackGround);

		pBackGround->setPosition(ccp(size.width/2, size.height/2));
		this->addChild(pBackGround, 0);
        
        GameOverLayer * overLayer = (GameOverLayer*)CCBManager::LoadCCBByNameAndLoader("GameOverLayer",GameOverLayerLoader::loader());
        this->addChild(overLayer);
        overLayer->Show();

		bRet = true;
	}while(0);

	return bRet;
}


void CGameOver::SwitchToPrevScene()
{
    CGameEvents::startFlipInterface(GAME_LEVEL);
}

