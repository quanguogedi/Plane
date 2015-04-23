#include "GameMessage.h"
#include "GameManager.h"

bool CGameMessage::init()
{
	bool bRet = false;
	do{
		CC_BREAK_IF(! CCLayer::init());

		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("res/Image/Message.plist");
		/**	信息框	*/
		CCSprite *pBox = CCSprite::createWithSpriteFrameName("Box.png");
        pBox->setScale(size.width/pBox->getContentSize().width);
		CC_BREAK_IF(! pBox);
		pBox->setPosition(ccp(size.width/2, size.height - pBox->boundingBox().size.height/2));
		this->addChild(pBox, 0);
		
		/**	分数	*/
		m_pScore = CCLabelAtlas::create("0", "res/Image/Num.plist");
		CC_BREAK_IF(! m_pScore);
        m_pScore->setScale(2.0f);
		this->addChild(m_pScore, 0);
		m_pScore->setPosition(ccp(300, size.height - 50) );

		/**	生命	*/
		m_pLife = CCLabelAtlas::create("3", "res/Image/Num.plist");
		CC_BREAK_IF(! m_pLife);
		this->addChild(m_pLife, 0);
        m_pLife->setScale(2.0f);
		m_pLife->setPosition(ccp(500, size.height - 40) );

		/**	HP	*/
		m_pHp = CCSprite::createWithSpriteFrameName("Hp.png");
		CC_BREAK_IF(! m_pHp);
		this->addChild(m_pHp, 0);
		m_pHp->setAnchorPoint(ccp(0, 0));
        m_pHp->setScale(1.5);
		m_iWidth = m_pHp->boundingBox().size.width;
		m_iHeight = m_pHp->boundingBox().size.height;
		m_pHp->setPosition(ccp(215, size.height - 145));
		m_fMinX = m_pHp->getTextureRect().getMinX();
		m_fMinY = m_pHp->getTextureRect().getMinY();

		/**	导弹图标	*/
		m_pMissileItem = CCMenuItemImage::create();       
		CC_BREAK_IF(! m_pMissileItem);
		m_pMissileItem->initWithTarget(this, menu_selector(CGameMessage::shootMissile));
		m_pMissileItem->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("MissileIco.png"));  
		m_pMissileItem->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("MissileIco.png"));
        m_pMissileItem->setScale(2.0f);
		m_pMissileItem->setPosition(ccp(m_pMissileItem->boundingBox().size.width*0.5, m_pMissileItem->boundingBox().size.height*2.5));
		
		CCMenu *pMissile = CCMenu::create(m_pMissileItem, NULL);
		CC_BREAK_IF(! pMissile);
		pMissile->setPosition(ccp(0, 0));
		this->addChild(pMissile, 0);

		m_pMissileNum = CCLabelAtlas::create("2", "res/Image/Num.plist");
		CC_BREAK_IF(! m_pMissileNum);
        
		m_pMissileItem->addChild(m_pMissileNum, 0);
		this->scheduleUpdate();

		bRet = true;
	}
	while(0);

	return bRet;
}

void CGameMessage::update(float dt)
{
	showScore();
	showHp();
	showLife();
	showMissile();
}

void CGameMessage::showScore()
{
	int iScore = CGameManager::getPlayer()->getScore();
	char szData[16];
	sprintf(szData,"%d",iScore);
	m_pScore->setString(szData);
}

void CGameMessage::showLife()
{
	
	char szData[16];
	int iLife = CGameManager::getPlayer()->getLife();
	if(iLife > 0)
	{
		sprintf(szData, "%d", iLife - 1);
		m_pLife->setString(szData);
	}
}

void CGameMessage::showHp()
{
	int iHp = CGameManager::getPlayer()->getHp();
	int iHpMax = CGameManager::getPlayer()->getHpMax();
	CCRect rect;
	rect.setRect(m_fMinX, m_fMinY, m_iWidth*(float)iHp/iHpMax, m_iHeight);
	m_pHp->setTextureRect(rect);
}

void CGameMessage::showMissile()
{
	char szData[16];
	int iMissileNum = CGameManager::getPlayer()->getMissileNum();
	if(iMissileNum > 0)
	{
		m_pMissileItem->setOpacity(255);
		m_pMissileNum->setVisible(true);
		sprintf(szData, "%d", iMissileNum);
		m_pMissileNum->setString(szData);
	}
	else
	{
		m_pMissileItem->setOpacity(150);
		m_pMissileNum->setVisible(false);
	}
}

void CGameMessage::shootMissile(CCObject* pSender)
{
	CGameManager::getPlayer()->shootMissile();
}