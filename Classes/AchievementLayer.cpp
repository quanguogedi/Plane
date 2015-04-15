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

bool AchievementLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "diamondLabel", CCLabelTTF*, mDiamondLabel);
    
    return false;
}

SEL_MenuHandler AchievementLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "OnTouchCloseButton", AchievementLayer::OnTouchCloseButton);
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

void AchievementLayer::scrollViewDidScroll(cocos2d::extension::CCScrollView *view)
{
    
}

void AchievementLayer::scrollViewDidZoom(cocos2d::extension::CCScrollView *view)
{
    
}

////////////////////////////////////////

void AchievementLayer::InitAchievementList()
{
    CCSize size = CCSizeMake(SCREEN_W, SCREEN_H - 200);
    
    mContainerNode = CCNode::create();
    
    mAchievemenListScrollView = CCScrollView::create(size, mContainerNode);
    mAchievemenListScrollView->setTouchEnabled(true);
    mAchievemenListScrollView->setDelegate(this);
    mAchievemenListScrollView->setDirection(kCCScrollViewDirectionVertical);
    mAchievemenListScrollView->setPosition(ccp(0, 100));
    addChild(mAchievemenListScrollView);
    
    
    CCDictionary* dict = PrototypeDataManager::GetSingleton().GetAllAchievementDataDict();
    
    int num = dict->count();
    int setY = 100;
    int col = 150;
    
    for (int i = 0; i < num; i++)
    {
        PrototypeAchievementData* data = (PrototypeAchievementData*)dict->objectForKey(i + 1);
        if(!data)
        {
            continue;
        }
        
        AchievementCell* cell = (AchievementCell*)CCBManager::LoadCCBByNameAndLoader("AchievementCell", AchievementCellLoader::loader());
        cell->SetCell(data);
        cell->setPosition(ccp(size.width / 2, 0 + setY + col * i));
        mContainerNode->addChild(cell);
    }
    
    mAchievemenListScrollView->setContentSize(ccp(size.width, setY + num * col));
    mAchievemenListScrollView->setContentOffset(ccp(0, size.height - (setY + num * col)));
}

void AchievementLayer::Close()
{
    if(mDelegate)
    {
        mDelegate->HideLayer();
    }
}

void AchievementLayer::OnTouchCloseButton(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    Close();
}