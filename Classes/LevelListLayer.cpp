//
//  LevelListLayer.cpp
//  Plane
//
//  Created by KGB on 15/3/20.
//
//

#include "LevelListLayer.h"

bool LevelListLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    CCSize size = CCSizeMake(SCREEN_W, SCREEN_H);
    
    mContainerNode = CCNode::create();
    
    mLevelListScrollView = CCScrollView::create(size, mContainerNode);
    mLevelListScrollView->setTouchEnabled(true);
    mLevelListScrollView->setDelegate(this);
    mLevelListScrollView->setDirection(kCCScrollViewDirectionVertical);
    
    
    
    addChild(mLevelListScrollView);
    
    return true;
}

void LevelListLayer::scrollViewDidScroll(cocos2d::extension::CCScrollView *view)
{
    
}

void LevelListLayer::scrollViewDidZoom(cocos2d::extension::CCScrollView *view)
{
    
}


void LevelListLayer::AddSubCell(CCNode* cell)
{
    mContainerNode->addChild(cell);
}

void LevelListLayer::SetScrollHeight(float h)
{
    mLevelListScrollView->setContentSize(CCSizeMake(SCREEN_W, h));
}
