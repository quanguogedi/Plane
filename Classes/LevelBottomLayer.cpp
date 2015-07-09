//
//  LevelBottomLayer.cpp
//  Plane
//
//  Created by 姜彬彬 on 4/12/15.
//
//

#include "LevelBottomLayer.h"
//#include "LevelListLayer.h"
#include "LevelContainerLayer.h"

bool LevelBottomLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    
    mIsTheLast = true;
    m_moveSpeed = 0;
    m_moveTime = 0;
    m_lastPos = CCPointZero;
    m_beginPos = CCPointZero;
    
    
    mContainer = (LevelContainerLayer*)CCBManager::LoadCCBByNameAndLoader("LevelContainerLayer", LevelContainerLayerLoader::loader());
    mContainer->RefreshUI();
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    mScrollView = CCScrollView::create(size, mContainer);
    schedule(schedule_selector(LevelBottomLayer::InertiaMotion));
    
    addChild(mScrollView);
    return true;
}



void LevelBottomLayer::onEnter()
{
    CCBLayer::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void LevelBottomLayer::onExit()
{
    CCBLayer::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool LevelBottomLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
    CCPoint startPos = pTouch->getLocation();
    mStartRect = CCRectMake(startPos.x-10, startPos.y-10, 20, 20);
    
    mContainer->stopAllActions();
    m_beginPos = startPos;
    m_lastPos = startPos;
    m_moveTime = 0;
    m_moveSpeed = 0;
    m_dragEnd = false;
  
    return true;
}

void LevelBottomLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
    CCPoint currPos = pTouch->getLocation();
    
    
    mDisY = currPos.y - m_lastPos.y;
   
    float posy = mContainer->getPositionY();
    
    posy += mDisY;
    
    if (posy <= 110 && posy >= mScrollView->getViewSize().height - mContainer->getContentSize().height - 110)
    {
        mContainer->setPositionY(posy);
        m_lastPos = currPos;
    }
   
    if (m_moveTime > 0.2f)
    {
        m_moveTime = 0.0f;
        m_beginPos = currPos;
    }
    
}

void LevelBottomLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint endPos = pTouch->getLocation();
    
    
    if (mStartRect.containsPoint(endPos))
    {
        for (int i = 1; i <= mContainer->getChildrenCount(); i ++)
        {
            CCSprite * sp = (CCSprite*)mContainer->getChildByTag(i);
            
            if (sp->boundingBox().containsPoint(mContainer->convertToNodeSpace(endPos)))
            {
                DataManager::GetInstance()->SetGameLevel(sp->getTag());
                if (mDelegate)
                {
                    mDelegate->OpenStartGameLayer();
                }
                CCLog("tousadfasfdasf ======== %d",sp->getTag());
                break;
            }
        }
    }

    if(m_moveTime == 0.0)
    {
        m_moveSpeed = 0.0f;
    }
    else
    {
        m_moveSpeed = (endPos.y - m_beginPos.y)/m_moveTime;
    }
    
    if(m_moveSpeed > -300.f && m_moveSpeed < 300.f)
    {
        m_moveSpeed = 0;
    }
    
    m_lastPos = endPos;
    
    m_dragEnd = true;
    
}

void LevelBottomLayer::InertiaMotion(float _time)
{
      m_moveTime += _time;
    
    if (!m_dragEnd)
    {
        return;
    }
    
  
    
    if(fabs(m_moveSpeed) < 200)
    {
        m_dragEnd= false;
        if (mContainer->getPositionY() > 0)
        {
            CCActionInterval * act = CCMoveTo::create(mContainer->getPositionY()/500, CCPointMake(0, 0));
            mContainer->runAction(CCEaseSineOut::create(act));
            m_moveSpeed = 0;
            m_moveTime = 0;
            
        }
        
        
        if (mContainer->getPositionY() < mScrollView->getViewSize().height - mContainer->getContentSize().height)
        {
            float dis = mScrollView->getViewSize().height - mContainer->getContentSize().height - mContainer->getPositionY();
            CCActionInterval * act = CCMoveTo::create(dis/500, CCPointMake(0, mScrollView->getViewSize().height - mContainer->getContentSize().height));
            mContainer->runAction(CCEaseSineOut::create(act));
            m_moveSpeed = 0;
            m_moveTime = 0;
        }
        return ;
    }
    
    double y = mContainer->getPositionY();
    y = y + m_moveSpeed *_time;
  
    
    if(y >= 110 || y <= mScrollView->getViewSize().height - mContainer->getContentSize().height - 110)
    {
        m_moveSpeed = 0;
        return ;
    }
    mContainer -> setPositionY(y);
    m_moveSpeed -= m_moveSpeed * _time*1.2;
}

bool LevelBottomLayer::adjustOffset()
{
   
}



bool LevelBottomLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    return false;
}

SEL_MenuHandler LevelBottomLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "UpgradeSelector", LevelBottomLayer::UpgradeSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "GiftSelector", LevelBottomLayer::GiftSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "BackSelector", LevelBottomLayer::BackSelector);
    
    return false;
}







void LevelBottomLayer::scrollViewDidScroll(cocos2d::extension::CCScrollView *view)
{
    CCLog("ccsrollview ==============scroll");
}


void LevelBottomLayer::scrollViewDidZoom(cocos2d::extension::CCScrollView *view)
{
    
}

//////////////////////////

void LevelBottomLayer::UpgradeSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if(mDelegate)
    {
        mDelegate->OpenUpgradeLayer();
    }
}

void LevelBottomLayer::GiftSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->OpenGiftBagLayer();
    }
}

void LevelBottomLayer::BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->HideLayer();
    }
}


