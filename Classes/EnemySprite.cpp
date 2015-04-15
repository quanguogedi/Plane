#include "EnemySprite.h"
#include "MoveTrackArray.h"
#include "GameManager.h"
#include "LevelData.h"

CEnemySprite* CEnemySprite::create(int iType, int startType, int moveType)
{
	CEnemySprite *pRet = new CEnemySprite();
    if (pRet && pRet->init(iType, startType, moveType))
    { 
        pRet->autorelease(); 
        return pRet; 
    } 
    else 
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool CEnemySprite::init(int iType, int startType, int moveType)
{
	bool bRet = false;

	do{
		CC_BREAK_IF(! CCLayer::init());	

		m_iType = iType;
        mStartType = startType;
        m_iMoveType = moveType;
		m_bDestroy = false;
		m_iDirection = STRAIGHT;
		memset(&m_szName, 0, sizeof(m_szName));
//		m_pSprite = CCSprite::createWithSpriteFrameName("Plane1_0.png");
//        m_pSprite = CCSprite::createWithSpriteFrameName("plane_small_01_a.png");
//        m_pSprite = CCSprite::create("new/plane_02.png");
//        m_pSprite->setFlipY(true);
		setAttr();
//		setFlyAnimation(m_iDirection);
		/**	���õ����ƶ��켣	*/
		setRun(0);
		this->scheduleUpdate();
		this->schedule(schedule_selector(CEnemySprite::shoot), m_fShootSpace);
		this->schedule(schedule_selector(CEnemySprite::changeFlyAnimation), 0.1f);

		bRet = true;
	}
	while(0);

	return bRet;
}

void CEnemySprite::setAttr()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	m_iLife = 0;
	switch(m_iType)
	{
	case 1:
        m_pSprite = CCSprite::createWithSpriteFrameName("plane_small_01_a.png");
//		m_pos.x = float(rand()%(int)(size.width - 64) + 32);
//		m_pos.y = size.height + 32;	
//		m_iMoveType = 1;
		m_iHpMax = 15;
		m_iFlyStraightNum = 1;
		m_iFlyLeftNum = 1;
		m_fShootSpace = 4.0f;
		m_iBulletType = 1;
		m_iScore = 1;
		switch(g_iGameLevel)
		{
		case LEVEL_ONE:
			m_iBulletNum = 3;
			break;
		case LEVEL_TWO:
			m_iBulletNum = 9;
			break;
		case LEVEL_THREE:
			m_iBulletNum = 18;
			break;
		default:
			break;
		}
		break;
	case 2:
        m_pSprite = CCSprite::createWithSpriteFrameName("plane_small_01_b.png");
//		m_pos.x = -32;
//		m_pos.y = float(rand()%(int)(size.height/2) + size.height/2);
//		m_iMoveType = 2;
		m_iHpMax = 10;
		m_iFlyStraightNum = 1;
		m_iFlyLeftNum = 1;
		m_fShootSpace = 2.0f;
		m_iBulletType = 1;
		m_iScore = 1;
		switch(g_iGameLevel)
		{
		case LEVEL_ONE:
			m_iBulletNum = 1;
			break;
		case LEVEL_TWO:
			m_iBulletNum = 2;
			break;
		case LEVEL_THREE:
			m_iBulletNum = 2;
			break;
		default:
			break;
		}
		break;
	case 3:
        m_pSprite = CCSprite::createWithSpriteFrameName("plane_small_01_c.png");
//		m_pos.x = size.width + 32;
//		m_pos.y = float(rand()%(int)(size.height/2) + size.height/2);
//		m_iMoveType = 3;
		m_iHpMax = 10;
		m_iFlyStraightNum = 1;
		m_iFlyLeftNum = 1;
		m_fShootSpace = 2.0f;
		m_iBulletType = 1;
		m_iScore = 1;
		switch(g_iGameLevel)
		{
		case LEVEL_ONE:
			m_iBulletNum = 2;
			break;
		case LEVEL_TWO:
			m_iBulletNum = 2;
			break;
		case LEVEL_THREE:
			m_iBulletNum = 3;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	m_iHp = m_iHpMax;
    
    setPosType(mStartType);
}

void CEnemySprite::setPosType(int posType)
{
    CCSize screen = CCDirector::sharedDirector()->getWinSize();
    CCSize enemySize = m_pSprite->getContentSize();
    
    CCPointArray* startPosArray = CCPointArray::create(EnemyStartTypeMax);
    startPosArray->addControlPoint(ccp(0, 0));//EnemyStartTypeNone
    startPosArray->addControlPoint(ccp(screen.width / 2, screen.height + enemySize.height / 2));//1 EnemyStartTypeTop
    startPosArray->addControlPoint(ccp(screen.width / 3, screen.height + enemySize.height / 2));//2 EnemyStartTypeTopLeft
    startPosArray->addControlPoint(ccp(screen.width * 2 / 3, screen.height + enemySize.height / 2));//3 EnemyStartTypeTopRight
    startPosArray->addControlPoint(ccp(-enemySize.width / 2, screen.height * 2 / 3));//4 EnemyStartTypeLeft
    startPosArray->addControlPoint(ccp(screen.width + enemySize.width / 2, screen.height * 2 / 3));//5 EnemyStartTypeRight
    startPosArray->addControlPoint(ccp(-enemySize.width / 2, screen.height / 3));//6 EnemyStartTypeLeft2
    startPosArray->addControlPoint(ccp(screen.width + enemySize.width / 2, screen.height / 3));//7 EnemyStartTypeRight2
    
    m_pos = startPosArray->getControlPointAtIndex(posType);
    
    CCLog("CEnemySprite::setPosType posType: %d, pos: %0.2f, %0.2f", posType, m_pos.x, m_pos.y);
    m_pSprite->setPosition(m_pos);
}

void CEnemySprite::setRun(float dt)
{
	CCPointArray *pArray = CMoveTrackArray::getEnemyArray(m_iMoveType);
	CCCardinalSplineBy *pAction = CCCardinalSplineBy::create(10, pArray, 0);
	CCCallFuncN *pFunc = CCCallFuncN::create(this, callfuncN_selector(CEnemySprite::setDelFunc));
	CCFiniteTimeAction *pMove = CCSequence::create(pAction, pFunc, NULL);  
	m_pSprite->runAction(pMove);
	
}

void CEnemySprite::setDelFunc(CCNode* sender) 
{
	m_pSprite->setVisible(false);
	m_bDestroy = true;
}

void CEnemySprite::update(float dt)
{
	if(m_pSprite->isVisible() == false) return;
	CPlayerSprite *pPlayer = CGameManager::getPlayer();
	if(pPlayer->isShield() == false)
	{
		if(pPlayer->getSprite()->boundingBox().intersectsRect(m_pSprite->boundingBox()))
		{
			hurt(1);
			pPlayer->hurt(1);
		}
	}
}
void CEnemySprite::shoot(float dt)
{
	CCPoint pos = m_pSprite->getPosition();
	CGameManager::getBulletManager()->createBullet(ENEMY, m_iBulletType, m_iBulletNum, pos.x, pos.y);
}

void CEnemySprite::destroy(CCNode *pSender)
{
	m_bDestroy = true;
	CGameManager::getPlayer()->addScore(m_iScore);
	CCPoint pos = m_pSprite->getPosition();
	switch(rand()%20)
	{
	case 0:
		CGameManager::getItemManager()->createItem(rand()%3 + 1, pos.x, pos.y);
		break;
	case 1:
		CGameManager::getItemManager()->createItem(4, pos.x, pos.y);
		break;
	default:
		CGameManager::getItemManager()->createItem(0, pos.x, pos.y);
		break;
	}

}