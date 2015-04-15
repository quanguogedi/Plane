#include "GameMap.h"

bool CGameMap::init()
{
	bool bRet = false;
	do{
//		CC_BREAK_IF(! CCLayer::init());
//		this->removeAllChildrenWithCleanup(true);
		CCSize size = CCDirector::sharedDirector()->getWinSize();
//		/**	¼ÓÔØÓÎÏ·±³¾°µØÍ¼	*/
//		char szText[128];
//		sprintf(szText, "Image/Map%d.png", g_iGameLevel);
//		m_pMap= CCSprite::create(szText);
//		CC_BREAK_IF(! m_pMap);
//		m_pMap->setPosition(ccp(size.width/2, 600));
//		this->addChild(m_pMap, 0);
//		m_pMap->runAction(CCMoveTo::create(100.0f, ccp(size.width/2, -(600 - size.height))));
        
        mBgFirst = CCSprite::create("new/sense_01.png");
        mBgFirst->setScaleY(size.height / mBgFirst->getContentSize().height);
        mBgFirst->setAnchorPoint(ccp(0.5, 0));
        mBgFirst->setPosition(ccp(size.width * 0.5, 0));
        this->addChild(mBgFirst,-1);
        
        mBgHeight = mBgFirst->boundingBox().size.height;
        mBgOffsetY = mBgFirst->boundingBox().size.height;
        
        mBgSecond = CCSprite::create("new/sense_01.png");
        mBgSecond->setScaleY(size.height / mBgSecond->getContentSize().height);
        mBgSecond->setAnchorPoint(ccp(0.5, 0));
        mBgSecond->setPosition(ccp(size.width * 0.5, mBgHeight - 1));
        this->addChild(mBgSecond,-1);
		
        this->scheduleUpdate();
		bRet = true;
	}
	while(0);

	return bRet;
}

void CGameMap::update(float _dt)
{
    this->scroll();
}

void CGameMap::scroll()
{
    mBgOffsetY--;
    
    if (mBgOffsetY <= 0)
    {
        mBgOffsetY = mBgFirst->boundingBox().size.height;
    }
    
    
    mBgFirst->setPosition(ccp(mBgFirst->getPosition().x, mBgOffsetY - mBgHeight));
    mBgSecond->setPosition(ccp(mBgSecond->getPosition().x, mBgOffsetY - 1));

}
void CGameMap::shake()
{
	this->runAction(CCJumpBy::create(1, ccp(0, 0), -15, 6));
}