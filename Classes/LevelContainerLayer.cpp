//
//  LevelContainerLayer.cpp
//  Plane
//
//  Created by 杨延飞 on 15/4/22.
//
//

#include "LevelContainerLayer.h"
bool LevelContainerLayer::init()
{
    if (!CCBLayer::init())
    {
        return false;
    }
    
    return true;
}

bool LevelContainerLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    //    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Menu", CCMenu*, mMenu);
    return false;
}

SEL_MenuHandler LevelContainerLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "LevelSelector", LevelContainerLayer::LevelSlector);
    
    return false;
}

void LevelContainerLayer::RefreshUI()
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


