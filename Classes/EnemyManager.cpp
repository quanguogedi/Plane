#include <map>
#include "EnemyManager.h"
#include "GameManager.h"
#include "PlayerSprite.h"

bool CEnemyManager::init()
{
	bool bRet = false;
	do{
		CC_BREAK_IF(! CCLayer::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		m_iEnemyCout = 0;
//		m_pEnemyList = CCSpriteBatchNode::create("Image/Plane.png");
        m_pEnemyList = CCSpriteBatchNode::create("res/003_enemy_a.png");
//        m_pEnemyList = CCSpriteBatchNode::create("new/plane_02.png");
		this->addChild(m_pEnemyList);
//		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Image/Plane.plist");
//		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Image/Boss.plist");
		this->scheduleUpdate();
		/**	敌人出现管理	*/
//		this->schedule(schedule_selector(CEnemyManager::createNewEnemys), 1.0f); 
//		
//
//		this->scheduleOnce(schedule_selector(CEnemyManager::createBoss), 100.0f);
        
        CreateAllEnemy(1);
        
		bRet = true;
	}
	while(0);

	return bRet;
}

void CEnemyManager::addEnemy()
{
	int iTag = -1;
	CEnemySprite* pEnemy = (CEnemySprite*)CEnemySprite::create(rand()%3 + 1); 
	for(int i = 0; i < m_iEnemyCout; i++)
	{
		CCSprite* pSprite= (CCSprite*)m_pEnemyList->getChildByTag(i);
		if(!pSprite)
		{
			iTag = i;
			break;
		}
	}
	if(iTag == -1)
	{
		iTag = m_iEnemyCout;
		m_iEnemyCout++;
	}
	m_pEnemyList->addChild(pEnemy->getSprite(), 1, iTag);
	this->addChild(pEnemy, 1, iTag);
}

void CEnemyManager::createNewEnemys(float dt)
{
		addEnemy();
}

void CEnemyManager::createBoss(float dt)
{
    int iBossType = DataManager::GetInstance()->GetGameLevel() - 1;
	CBossSprite *pBoss = CBossSprite::create(iBossType);
	this->addChild(pBoss, 1, 100);
	this->unschedule(schedule_selector(CEnemyManager::createNewEnemys));
}


void CEnemyManager::update(float dt)
{
	CEnemySprite *pEnemy = NULL;
	for(int i = 0; i < m_iEnemyCout; i++)
	{
		pEnemy = (CEnemySprite*)this->getChildByTag(i);
		if(pEnemy && pEnemy->isDestroy() == true)
		{
			m_pEnemyList->removeChildByTag(i, true); 
			this->removeChildByTag(i, true);
		}
	}
}

////////////////////////////////////////////
//new

void CEnemyManager::CreateAllEnemy(int level)
{
    mEnemyIndex = 0;
    mLevel = level;
    mTime = 0;

    schedule(schedule_selector(CEnemyManager::CreateEnemyByTime), 0.5);
}

void CEnemyManager::CreateEnemyByTime(float time)
{
    mTime += time;
    
    LevelData* levelData = (LevelData*)LevelManager::GetSingleton().GetLevelData(mLevel);
    
    LevelSubData* subData = (LevelSubData*)levelData->GetLevelSubData(mEnemyIndex);
    if(!subData)
    {
        return;
    }
    
    while (subData && mTime >= subData->mTime)
    {
        if(!subData->mEnemyType)
        {
            DataManager::GetInstance()->SetResult(true);
            CGameEvents::startFlipInterface(GAME_OVER);
            return;
        }
        
        CreateEnemy(subData);
        mEnemyIndex ++;
        subData = (LevelSubData*)levelData->GetLevelSubData(mEnemyIndex);
    }
    
}

void CEnemyManager::CreateEnemy(LevelSubData* subData)
{
    CCLog("CreateEnemy: subData: time: %.01f, EnemyType: %d, StartType: %d, MoveType: %d",
          subData->mTime, subData->mEnemyType, subData->mStartType, subData->mMoveType);
    
    CEnemySprite* pEnemy = CEnemySprite::create(subData->mEnemyType, subData->mStartType, subData->mMoveType);
    AddEnemy(pEnemy);
}

void CEnemyManager::AddEnemy(CEnemySprite* emeny)
{
    int iTag = -1;
    
    for(int i = 0; i < m_iEnemyCout; i++)
    {
        CCSprite* pSprite= (CCSprite*)m_pEnemyList->getChildByTag(i);
        if(!pSprite)
        {
            iTag = i;
            break;
        }
    }
    if(iTag == -1)
    {
        iTag = m_iEnemyCout;
        m_iEnemyCout++;
    }
    m_pEnemyList->addChild(emeny->getSprite(), 1, iTag);
    this->addChild(emeny, 1, iTag);
}

