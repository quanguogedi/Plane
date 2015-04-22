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
    if (!CCBLayer::init())
    {
        return false;
    }
    
    return true;
}

bool LevelListLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    return false;
}

SEL_MenuHandler LevelListLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "LevelSelector", LevelListLayer::LevelSlector);
    
    return false;
}

void LevelListLayer::RefreshUI()
{
    int unLockLevelCount = 5;//LocalArchiveData::GetInstance()->LoadUnlockLevelCount();
    for (int i = 1; i <= getChildrenCount(); i++)
    {
        
        
        if (i == unLockLevelCount)
        {
            CCSprite * yellowBorder = (CCSprite*)getChildByTag(i)->getChildByTag(1);//黄色外框
            yellowBorder->setVisible(true);
            getChildByTag(i)->getChildByTag(3)->setVisible(true);
        }else if (i < unLockLevelCount)
        {
            CCSprite * yellowBorder = (CCSprite*)getChildByTag(i)->getChildByTag(1);//黄色外框
            yellowBorder->setVisible(true);
            
            getChildByTag(i)->getChildByTag(2)->getChildByTag(1)->setVisible(true);
            
            CCNode * starBg = getChildByTag(i)->getChildByTag(4);//星星背景node
            starBg->setVisible(true);
            
            for (int j = 1; j <= 2; j ++)//LocalArchiveData::GetInstance()->LoadLevelStar(i)
            {
                starBg->getChildByTag(j)->getChildByTag(1)->setVisible(true);
            }
        }
    }
}

void LevelListLayer::LevelSlector(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLog("LevelSlector ==== %d",((CCMenuItem*)pSender)->getTag());
}


void LevelListLayer::AddSubCell(CCNode* cell)
{
    mContainerNode->addChild(cell);
}

void LevelListLayer::SetScrollHeight(float h)
{
    mLevelListScrollView->setContentSize(CCSizeMake(SCREEN_W, h));
}
