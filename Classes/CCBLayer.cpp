//
//  BaseMenu.cpp
//  Gobang
//
//  Created by KGB on 14-4-15.
//
//
#include "CCBLayer.h"


bool CCBLayer::init()
{
    do
    {
        CC_BREAK_IF(!CCLayer::init());
    } while (0);
    
    mDelegate = NULL;
    mIsTheLast = false;
    mIsTheDialog = false;
    mTouchLevel = 0;
    
    mMenu = NULL;
    return true;
}

void CCBLayer::onEnter()
{
    CCLayer::onEnter();
    
    
    
//    RefreshUI();
    
    
    
    
    
    switch (mTouchLevel)
    {
        case 1:
            setZOrder(FIRSTLEVEL_LAYERORDER);
            CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, FIRSTLEVEL_LAYERTOUCH, true);
            if (mMenu)
            {
                mMenu->setTouchPriority(FIRSTLEVEL_MENUTOUCH);
            }
            break;
        case 2:
            setZOrder(SECONDLEVEL_LAYERORDER);
            CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, SECONDLEVEL_LAYERTOUCH, true);
            if (mMenu)
            {
                mMenu->setTouchPriority(SECONDLEVEL_MENUTOUCH);
            }
            break;
        case 3:
            setZOrder(THIRDLEVEL_LAYERORDER);
            CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, THIRDLEVEL_LAYERTOUCH, true);
            if (mMenu)
            {
                mMenu->setTouchPriority(THIRDLEVEL_MENUTOUCH);
            }
            break;
        default:
            break;
    }
}

void CCBLayer::onExit()
{
    CCLayer::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool CCBLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    return isVisible();
}

void CCBLayer::SetDelegate(CCBDelegate *_delegate)
{
    mDelegate = _delegate;
    for (int i = 1 ; i < getChildrenCount(); i++)
    {
        CCBLayer * layer = (CCBLayer*)getChildByTag(i);
        if (layer && layer->getTag() != -1)
        {
            layer->SetDelegate(_delegate);
        }
    }
}

CCBDelegate * CCBLayer::GetDelegate()
{
    return mDelegate;
}

bool CCBLayer::GetIsTheLast()
{
    return mIsTheLast;
}

bool CCBLayer::GetIsTheDialog()
{
    return mIsTheDialog;
}


bool CCBLayer::PlayAnimantionByName(const char *_name)
{
    CCBAnimationManager * manager = (CCBAnimationManager *)getUserObject();
    manager->setDelegate(this);
    if (manager->getSequenceId(_name) == -1)
    {
        return false;
    }
    manager->runAnimationsForSequenceNamed(_name);
    return true;
}

bool CCBLayer::PlayShowAnimation()
{
    
    return PlayAnimantionByName("Show");
}

bool CCBLayer::PlayHideAnimation()
{
    return PlayAnimantionByName("Hide");
}

void CCBLayer::Show()
{
    RefreshUI();
    setVisible(true);
    PlayShowAnimation();
    for (int i = 1 ; i < getChildrenCount(); i++)
    {
        CCBLayer * layer = (CCBLayer*)getChildByTag(i);
        if (layer && layer->getTag() != -1)
        {
            layer->Show();
        }
    }
    
    
}

void CCBLayer::Hide()
{
    if (!PlayHideAnimation())
    {
        setVisible(false);
    }
}
