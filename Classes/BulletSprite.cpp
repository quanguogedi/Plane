#include "BulletSprite.h"
#include "GameManager.h"
#include "RoleSprite.h"

CBulletSprite* CBulletSprite::create(int iPlaneType, int iType, int iAllNum, int iCurNum, float x, float y)
{
	CBulletSprite *pRet = new CBulletSprite();
    if (pRet && pRet->init(iPlaneType, iType, iAllNum, iCurNum, x, y))
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

bool CBulletSprite::init(int iPlaneType, int iType, int iAllNum, int iCurNum, float x, float y)
{
	bool bRet = false;

	do{
		CC_BREAK_IF(! CCLayer::init());

		m_iPlaneType = iPlaneType;
		m_iType = iType;
		setAttr();
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		m_pSprite = CCSprite::createWithSpriteFrameName(m_szName);
        
		m_iWidth = m_pSprite->boundingBox().size.width;
		m_iHeight = m_pSprite->boundingBox().size.height;
		m_pSprite->setPosition(ccp(x, y));
		setMoveTrack(iAllNum, iCurNum);
		this->scheduleUpdate();

		bRet = true;
	}
	while(0);

	return bRet;
}

void CBulletSprite::setAttr()
{
//    switch(m_iType)
//    {
//    case 0:
//        strcpy(m_szName, "barrage_c_01.png");
//        m_iHarm = 1;
//        break;
//    default:
//        strcpy(m_szName, "barrage_a_02.png");
//        m_iHarm = 1;
//        break;
//    }
    
    
    char bullet[BULLET_EFFECT_MAX][64] =
    {
        "barrage_c_01.png",
        "barrage_c_02.png",
        "barrage_c_03.png",
        "barrage_c_04.png",
        "barrage_c_12.png",
        "barrage_c_13.png",
        "barrage_c_14.png",
        "barrage_c_15.png",
        "missile_01.png",
        "missile_02.png",
        "missile_03.png",
        "missile_04.png",
        "barrage_a_01.png",
    };
    
    strcpy(m_szName, bullet[m_iPlaneType]);
    m_iHarm = 1;
    
//    //以上为yyf加
//	switch(m_iType)
//	{
//	case 0:
//		strcpy(m_szName, "orangeCircle.png");
//		m_iHarm = 1;
//		break;
//	case 1:
//		strcpy(m_szName, "blueBall2.png");
//		m_iHarm = 1;
//		break;
//	case 2:
//		strcpy(m_szName, "monsterBullet1.png");
//		m_iHarm = 1;
//		break;
//	case 3:
//		strcpy(m_szName, "helperBullet.png");
//		m_iHarm = 1;
//		break;
//	case 4:
//		strcpy(m_szName, "purpleCircle.png");
//		m_iHarm = 1;
//		break;
//	case 5:
//		strcpy(m_szName, "yellowBall.png");
//		m_iHarm = 1;
//		break;
//	case 6:
//		strcpy(m_szName, "silverBall.png");
//		m_iHarm = 1;
//		break;
//	case 7:
//		strcpy(m_szName, "greenBall.png");
//		m_iHarm = 1;
//		break;
//	default:
//		break;
//	}
//
    
//    CCSpriteBatchNode
}

void CBulletSprite::setMoveTrack(int iAllNum, int iCurNum)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	float dx, dy;
	CCActionInterval* pAction;
	if(m_iPlaneType == PLAYER)
	{
//		if(m_iType == 5)
//		{
//			dx = 0;
//			dy = size.height/5;
//		}
//		else
//		{
        
//            if (iAllNum % 2 == 0)
//            {
//                if (iCurNum < (iAllNum + 1)/2)
//                {
//                    m_pSprite->setRotation(-(iAllNum/2 - iCurNum + 0.5) * 10);
//                }else
//                {
//                    m_pSprite->setRotation((iCurNum - iAllNum/2 - 0.5) * 10);
//                }
//            }else
//            {
//                if (iCurNum < (iAllNum + 1)/2)
//                {
//                    m_pSprite->setRotation(-((iAllNum + 1)/2 - iCurNum-1) * 10);
//                }else if (iCurNum > (iAllNum + 1)/2)
//                {
//                    m_pSprite->setRotation((iCurNum - (iAllNum + 1)/2 + 1) * 10);
//                }
//            }
//            
//            
//            
//			dx =  (iCurNum - 1)*50 - (iAllNum - 1)*25;
//			dy = size.height;
//		}
        
//        CCLog("Bullet 1 dx = %.2f, dy = %.2f, iCurNum = %d, iAllNum = %d", dx, dy, iCurNum, iAllNum);
        
        dx =  (iCurNum - 1)*50 - (iAllNum - 1)*25;
        dy = size.height;
        
		pAction = CCMoveBy::create(1, ccp(dx, dy));
	}
    else if(m_iPlaneType == PLAYER2)
    {

    }
    else if(m_iPlaneType == PLAYER3)
    {
        dx = 0;
        dy = size.height;
        
        //        CCLog("Bullet 2 dx = %.2f, dy = %.2f, iCurNum = %d, iAllNum = %d", dx, dy, iCurNum, iAllNum);
        
        pAction = CCMoveBy::create(1, ccp(dx, dy));
        
        m_pSprite->setPosition(m_pSprite->getPosition() + ccp((iCurNum - 1)*50 - (iAllNum - 1)*25, 0));
    }
    else if(m_iPlaneType == PLAYER4)
    {
        dx = 0;
        dy = size.height;
        
        //        CCLog("Bullet 2 dx = %.2f, dy = %.2f, iCurNum = %d, iAllNum = %d", dx, dy, iCurNum, iAllNum);
        
        pAction = CCMoveBy::create(1, ccp(dx, dy));
        
        m_pSprite->setPosition(m_pSprite->getPosition() + ccp((iCurNum - 1)*50 - (iAllNum - 1)*25, 0));
    }
    else if(m_iPlaneType == PLAYER_WING_BULLET)
    {
        dx =  0;
        dy = size.height;
        
        pAction = CCMoveBy::create(1, ccp(dx, dy));
        
        m_pSprite->setPosition(m_pSprite->getPosition() + ccp((iCurNum - 1)*200 - (iAllNum - 1)*100, 0));
    }
    else if(m_iPlaneType == PLAYER2_WING_BULLET)
    {
        
    }
    else if(m_iPlaneType == PLAYER3_WING_BULLET)
    {
        
    }
    else if(m_iPlaneType == PLAYER4_WING_BULLET)
    {
        dx =  0;
        dy = size.height;
        
        pAction = CCMoveBy::create(1, ccp(dx, dy));
        
        m_pSprite->setPosition(m_pSprite->getPosition() + ccp((iCurNum - 1)*200 - (iAllNum - 1)*100, 0));
    }
    else if(m_iPlaneType == PLAYER_MISSILE)
    {
        dx =  (iCurNum - 1)*50 - (iAllNum - 1)*25;
        dy = size.height;
        
        CCMoveBy* moveBy1 = CCMoveBy::create(0.8, ccp(dx, -80));
        CCMoveBy* moveBy2 = CCMoveBy::create(1, ccp(dx, dy));
        
        ccBezierConfig  bezier;
        bezier.endPosition = ccp((iCurNum - 1)*400 - (iAllNum - 1)*200, size.height);
        bezier.controlPoint_1 = ccp((iCurNum - 1)*100 - (iAllNum - 1)*50, -300);
        bezier.controlPoint_2 = ccp((iCurNum - 1)*200 - (iAllNum - 1)*100, -300);
        
        CCBezierBy* bezierBy = CCBezierBy::create(1, bezier);
        
        pAction = CCSequence::create(bezierBy, NULL);
    }
    else if(m_iPlaneType == PLAYER2_MISSILE)
    {
    }
    else if(m_iPlaneType == PLAYER3_MISSILE)
    {
    }
    else if(m_iPlaneType == PLAYER4_MISSILE)
    {
    }
	else if(m_iPlaneType == ENEMY)
	{	
		float iSpace = 43;
		float iRadians = CC_DEGREES_TO_RADIANS(270 + (iCurNum - iAllNum%2/2.0 - 0.5 - iAllNum/2)*iSpace);
		dx = size.height*5/4*cos(iRadians);
		dy = size.height*5/4*sin(iRadians);
		pAction = CCMoveBy::create(4, ccp(dx, dy));
	}
    
	CCCallFuncN *pFunc = CCCallFuncN::create(this, callfuncN_selector(CBulletSprite::setDelFunc));
	CCFiniteTimeAction *pMove = CCSequence::create(pAction, pFunc, NULL);  
	m_pSprite->runAction(pMove);
}

void CBulletSprite::update(float dt)
{
	if(m_pSprite->isVisible() == false) return;
	if(m_iPlaneType != ENEMY)
	{
		CEnemyManager *pEnemyManager = CGameManager::getEnemyManager();
		for(int i = 0; i < pEnemyManager->getCount(); i++)
		{
			CEnemySprite *pEnemy = (CEnemySprite*)pEnemyManager->getChildByTag(i);
			if(!pEnemy || pEnemy->getSprite()->isVisible() == false) continue;
			if(pEnemy->getSprite()->boundingBox().intersectsRect(m_pSprite->boundingBox()))
			{
				m_pSprite->setVisible(false);
				pEnemy->hurt(m_iHarm);
			}
		}
		CBossSprite *pBoss = (CBossSprite*)pEnemyManager->getChildByTag(100);
		if(pBoss && pBoss->getSprite()->isVisible() == true)
		{
			if(pBoss->getSprite()->boundingBox().intersectsRect(m_pSprite->boundingBox()))
			{
				m_pSprite->setVisible(false);
				pBoss->hurt(m_iHarm);
			}
		}
	}
	else
	{
		CPlayerSprite *pPlayer = CGameManager::getPlayer();	
		if(!pPlayer->isWin())
		{
			if(m_pSprite->boundingBox().containsPoint(pPlayer->getSprite()->getPosition()))
			//if(CCRect::CCRectIntersectsRect(pPlayer->getSprite()->boundingBox(), m_pSprite->boundingBox()))
			{
				m_pSprite->setVisible(false);
				if(pPlayer->isShield() == false)
				{
					pPlayer->hurt(m_iHarm);
				}
			}
		}
	}
}

void CBulletSprite::setDelFunc(CCNode* sender) 
{
	m_pSprite->setVisible(false);
}