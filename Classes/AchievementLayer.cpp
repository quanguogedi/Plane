//
//  AchievementLayer.cpp
//  Plane
//
//  Created by KGB on 15/3/25.
//
//

#include "CCBManager.h"
#include "AchievementLayer.h"
#include "AchievementCell.h"

bool AchievementLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    mIsTheDialog = true;
    mTouchLevel = 1;
    
    return true;
}

bool AchievementLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "diamondLabel", CCLabelTTF*, mDiamondLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "BorderSprite", CCSprite*, mBorderSprite);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    
    return false;
}

SEL_MenuHandler AchievementLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "BackSelector", AchievementLayer::BackSelector);
    return false;
}

SEL_CCControlHandler AchievementLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    return false;
}

void AchievementLayer::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    InitAchievementList();
}

//void AchievementLayer::scrollViewDidScroll(cocos2d::extension::CCScrollView *view)
//{
//    
//}
//
//void AchievementLayer::scrollViewDidZoom(cocos2d::extension::CCScrollView *view)
//{
//    
//}

////////////////////////////////////////

void AchievementLayer::InitAchievementList()
{
    CCSize size = CCSizeMake(mBorderSprite->getContentSize().width, mBorderSprite->getContentSize().height-100);
    
    mContainerNode = CCNode::create();
    
    mAchievemenListScrollView = CCScrollView::create(size, mContainerNode);
    mAchievemenListScrollView->setTouchEnabled(true);
    mAchievemenListScrollView->setTouchPriority(-130);
    mAchievemenListScrollView->setDelegate(this);
    mAchievemenListScrollView->setDirection(kCCScrollViewDirectionVertical);
    mAchievemenListScrollView->setPosition(ccp(0, 50));
    mBorderSprite->addChild(mAchievemenListScrollView);
    
    
    
    
    CCDictionary* dict = PrototypeDataManager::GetSingleton().GetAllAchievementDataDict();
    
    int num = dict->count();
    int col = 150;
    
    int containerHeight = col * num + (num -1)*100;
    
    int nn = containerHeight/size.height + 1;
    
    mContainerNode->setContentSize(CCSizeMake(size.width,nn *  size.height  ));
    
    for (int i = 0; i < num; i++)
    {
        PrototypeAchievementData* data = (PrototypeAchievementData*)dict->objectForKey(i + 1);
        if(!data)
        {
            continue;
        }
        
        AchievementCell* cell = (AchievementCell*)CCBManager::LoadCCBByNameAndLoader("AchievementCell", AchievementCellLoader::loader());
        cell->SetCell(data);
        cell->setPosition(ccp(size.width * 0.5, mContainerNode->getContentSize().height-30 -(col + 10) * i));
        mContainerNode->addChild(cell);
    }
    
    mAchievemenListScrollView->setContentOffset(ccp(0, size.height - mContainerNode->getContentSize().height ));

}


void AchievementLayer::BackSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    if(mDelegate)
    {
        mDelegate->HideLayer();
    }
}