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
    
    mActionTag = 0;
    mContainer = (LevelContainerLayer*)CCBManager::LoadCCBByNameAndLoader("LevelContainerLayer", LevelContainerLayerLoader::loader());
    mContainer->RefreshUI();
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    mScrollView = CCScrollView::create(size, mContainer);
//    mScrollView->setTouchEnabled(true);
//    mScrollView->setDelegate(this);
//    mScrollView->setBounceable(true);
//    scrollView->setTouchPriority(-130);
//    mScrollView->setDirection(kCCScrollViewDirectionVertical);
    schedule(schedule_selector(LevelBottomLayer::UpdateContainer));
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
//    if (mContainer->getActionByTag(mActionTag))
//    {
//        mContainer->stopActionByTag(mActionTag);
//    }
    
    return true;
}

void LevelBottomLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
    mDisY = pTouch->getDelta().y;
   
    float posy = mContainer->getPositionY();
    if (posy + mDisY > 80 )
    {
        mDisY = 80 - posy;
        
    }else if (posy + mDisY < mScrollView->getViewSize().height -mContainer->getContentSize().height - 80 )
    {
        mDisY = mScrollView->getViewSize().height -mContainer->getContentSize().height - 80 -posy;
    }
    
    mContainer->setPositionY(mContainer->getPositionY() + mDisY);
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
   
   
    
//    if (adjustOffset())
//    {
//        float a = mDisY/0.05;
        
        
        float posy = mContainer->getPositionY();
        float dis = mDisY*30;
//        if (posy + dis > 80 )
//        {
//            dis = 80 - posy;
//        }else if (posy + dis < mScrollView->getViewSize().height -mContainer->getContentSize().height - 80 )
//        {
//            dis = mScrollView->getViewSize().height -mContainer->getContentSize().height - 80 -posy;
//        }
    
        CCLog("==============dis = %.2f",dis);
        
//        CCMoveBy * speedAction = CCMoveBy::create(fabsf(dis)/1300,ccp( 0,dis));
//        float time = sqrtf(2*dis/a);
       float time = fabsf(dis) / 1500 ;
         CCLog("==============dis = %.2f========%.2f",dis,time);
//        float time = fabsf(dis) / 2000 ;
//        if (time > 0.4)
//        {
//            time = 0.4;
//        }
        CCMoveBy * speedAction = CCMoveBy::create(time,ccp( 0,dis));
        mActionTag = mContainer->runAction(CCEaseExponentialOut::create(speedAction))->getTag();
//        mActionTag =  mContainer->runAction(CCSequence::createWithTwoActions(CCEaseExponentialOut::create(speedAction), CCCallFunc::create(this, callfunc_selector(LevelBottomLayer::adjustOffset))))->getTag();
        

//    }
    mDisY = 0;
    mActionTag = 0;
    
}

void LevelBottomLayer::UpdateContainer(float _time)
{
    bool flag = true;
    if (mContainer->getPositionY() > 0)
    {
        flag = false;
        if (mContainer->getActionByTag(mActionTag))
        {
            mContainer->stopActionByTag(mActionTag);
        }
        mScrollView->setContentOffset(CCPointZero,true);
    }
    else if (mContainer->getPositionY() < mScrollView->getViewSize().height -mContainer->getContentSize().height)
    {
//        flag = false;
        if (mContainer->getActionByTag(mActionTag))
        {
            mContainer->stopActionByTag(mActionTag);
        }
        mScrollView->setContentOffset(CCPointMake(0,mScrollView->getViewSize().height-mContainer->getContentSize().height),true);
    }
//    return flag;
}

bool LevelBottomLayer::adjustOffset()
{
    bool flag = true;
    if (mContainer->getPositionY() > 0)
    {
        flag = false;
        if (mContainer->getActionByTag(mActionTag))
        {
            mContainer->stopActionByTag(mActionTag);
        }
        mScrollView->setContentOffset(CCPointZero,true);
    }
    else if (mContainer->getPositionY() < mScrollView->getViewSize().height -mContainer->getContentSize().height)
    {
        flag = false;
        if (mContainer->getActionByTag(mActionTag))
        {
            mContainer->stopActionByTag(mActionTag);
        }
        mScrollView->setContentOffset(CCPointMake(0,mScrollView->getViewSize().height-mContainer->getContentSize().height),true);
    }
    return flag;
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
        mDelegate->OpenGiftLayer();
    }
}

void LevelBottomLayer::BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if (mDelegate)
    {
        mDelegate->HideLayer();
    }
}


