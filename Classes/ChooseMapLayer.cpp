//
//  ChooseMapLayer.cpp
//  BnB
//
//  Created by 杨延飞 on 14-11-10.
//
//

#include "Common.h"
#include "CCBLayer.h"
#include "ChooseMapLayer.h"


ChooseMapLayer::~ChooseMapLayer()
{
    CC_SAFE_RELEASE(mMapBg);
    CC_SAFE_RELEASE(mMap);
    CC_SAFE_RELEASE(mFilterBg);
    CC_SAFE_RELEASE(mDisc);
    CC_SAFE_RELEASE(mTypeMenu);
    CC_SAFE_RELEASE(mTypeMenuBg);
   
}
bool ChooseMapLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "MapBg", CCLayerColor*, mMapBg);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Map", CCSprite*, mMap);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "FilterBg", CCSprite*, mFilterBg);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Disc", CCLabelTTF*, mDisc);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "TypeMenu", CCMenu*, mTypeMenu);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "TypeMenuBg", CCSprite*, mTypeMenuBg);
    return false;
}

SEL_MenuHandler ChooseMapLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "FilterSelector", ChooseMapLayer::FilterSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "SureSelector", ChooseMapLayer::SureSelector);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "TypeSelector", ChooseMapLayer::TypeSelector);
    return NULL;
}

SEL_CCControlHandler ChooseMapLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

void ChooseMapLayer::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    SetMiniMap();
    
    //
    mTypeSelectTag = CCSprite::createWithSpriteFrameName("button_filtrate_disabled.png");
    CCMenuItemImage * item1 = (CCMenuItemImage*)mTypeMenu->getChildByTag(1);
    mTypeSelectTag->setPosition(item1->getPosition());
    mTypeSelectTag->setScale(0.98);
    mTypeMenuBg->addChild(mTypeSelectTag);
    
}

void ChooseMapLayer::onEnter()
{
//    CCBLayer::onEnter();
//    
//
//    mViewSize = mMapBg->boundingBox().size;
//    mTableView = CCTableView::create(this, mViewSize);
//    mTableView->setDirection(kCCScrollViewDirectionVertical);
//    mTableView->setPosition(CCPointZero);
//    mTableView->setDelegate(this);
//    mTableView->setVerticalFillOrder(kCCTableViewFillTopDown);
//    mMapBg->addChild(mTableView);
//    mTableView->reloadData();
}

void ChooseMapLayer::onExit()
{
//    CCBLayer::onExit();
}

void ChooseMapLayer::scrollViewDidScroll(CCScrollView *view)
{
}

void ChooseMapLayer::scrollViewDidZoom(CCScrollView *view)
{
}

void ChooseMapLayer::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    if (mSelectCell)
    {
//        CCLabelTTF * label = (CCLabelTTF*)mSelectCell->getChildByTag(123);
//        label->setColor(ccc3(255, 255, 255));
        ((CCSprite*)mSelectCell->getChildByTag(321))->setVisible(false);
    }
//
//    CCLabelTTF * currLabel = (CCLabelTTF*)cell->getChildByTag(123);
//    currLabel->setColor(ccYELLOW);
    ((CCSprite*)cell->getChildByTag(321))->setVisible(true);
//    mMapSelectTag->setPosition(cell->getPosition());
    
    mSelectCell = cell;
//    BattleManager::GetInstance()->mMapIndex = cell->getIdx() + 1;
    SetMiniMap();
}

CCSize ChooseMapLayer::cellSizeForTable(CCTableView *table)
{
    return CCSizeMake(mViewSize.width, 80);
}

CCTableViewCell* ChooseMapLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
//    CCDictionary * tempDic = (CCDictionary*)BattleManager::GetInstance()->mMapDic->objectForKey(BattleManager::GetInstance()->mMapType);
//    MapData * mapData = (MapData*)tempDic->objectForKey(idx+1);
//    
//    CCTableViewCell *pCell = table->dequeueCell();
//
//    if (!pCell) {
//        pCell = new CCTableViewCell();
//        pCell->autorelease();
//        
//        CCSprite * bg = CCSprite::createWithSpriteFrameName("button_filtrate_00.png");
//        bg->setPosition(ccp(pCell->boundingBox().size.width*0.5, 40));
//        bg->setScale(2.0f);
//        pCell->addChild(bg);
//        
//        CCSprite * tag = CCSprite::createWithSpriteFrameName("button_filtrate_01.png");
//        tag->setPosition(ccp(pCell->boundingBox().size.width*0.5, 40));
//        tag->setScale(2.0f);
//        tag->setVisible(false);
//        pCell->addChild(tag,10,321);
//       
//        char str[256] ;
//        memset(str, 0, sizeof(str));
//        sprintf(str, "  %s    %d         %d",mapData->mName,mapData->mLevel,mapData->mPlayer);
//        CCLabelTTF *pLabel = CCLabelTTF::create(str, "Arial", 35);
//        pLabel->setHorizontalAlignment(kCCTextAlignmentLeft);
//        pLabel->setAnchorPoint(ccp(0,0.5));
//        pLabel->setPosition(ccp(0, 40));
//        pLabel->setTag(123);
//        pCell->addChild(pLabel);
//    }
//    else
//    {
//        CCLabelTTF *pLabel = (CCLabelTTF*)pCell->getChildByTag(123);
//        char str[256] ;
//        memset(str, 0, sizeof(str));
//        sprintf(str, "  %s    %d         %d",mapData->mName,mapData->mLevel,mapData->mPlayer);
//        pLabel->setString(str);
//       
//    }
//    if (idx + 1 == BattleManager::GetInstance()->mMapIndex)
//    {
//        
//        ((CCSprite*)pCell->getChildByTag(321))->setVisible(true);
//        
////        ((CCLabelTTF*)pCell->getChildByTag(123))->setColor(ccYELLOW);
//        mSelectCell = pCell;
//    }else
//    {
//        ((CCSprite*)pCell->getChildByTag(321))->setVisible(false);
////        ((CCLabelTTF*)pCell->getChildByTag(123))->setColor(ccc3(255, 255, 255));
//    }
//   
    
    return NULL;
}

unsigned int ChooseMapLayer::numberOfCellsInTableView(CCTableView *table)
{
//    CCDictionary * tempDic = (CCDictionary*)BattleManager::GetInstance()->mMapDic->objectForKey(BattleManager::GetInstance()->mMapType);
//
//    return tempDic->count();
    return 0;
}

void ChooseMapLayer::SetMiniMap()
{
//    CCDictionary * tempDic = (CCDictionary*)BattleManager::GetInstance()->mMapDic->objectForKey(BattleManager::GetInstance()->mMapType);
//    MapData * mapData = (MapData*)tempDic->objectForKey(BattleManager::GetInstance()->mMapIndex);
//    mMap->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(mapData->mMiniFile));
//    mDisc->setString(mapData->mDisc);
}


void ChooseMapLayer::FilterSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
//    CCBAnimationManager *   actionManager = (CCBAnimationManager*)getUserObject();
//    actionManager->setDelegate(this);
//    if (mFilterBg->isVisible())
//    {
//        actionManager->runAnimationsForSequenceNamed("FilterBgOut");
//    }else
//    {
//        actionManager->runAnimationsForSequenceNamed("FilterBgIn");
//    }
//    
    
}

void ChooseMapLayer::SureSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
//    mDelegate->CCBSureSelector();
//    if (!ZapyaJNI::GetIsSinglePlay())
//    {
//        SendChangeMapMsg();
//    }
    
}

void ChooseMapLayer::TypeSelector(CCObject *pSender, CCControlEvent pCCControlEvent)
{
//    CCMenuItemImage * item = (CCMenuItemImage*)pSender;
//    int tag = item->getTag();
//    
//    mTypeSelectTag->setPosition(item->getPosition());
//    
//    BattleManager::GetInstance()->mMapType = tag;
//    BattleManager::GetInstance()->mMapIndex = 1;
//    
//    SetMiniMap();
//    
//    mTableView->reloadData();
    
}

void ChooseMapLayer::SendChangeMapMsg()
{
//    MapInfo mapInfo;
//    mapInfo.mType = BattleManager::GetInstance()->mMapType;
//    mapInfo.mIndex = BattleManager::GetInstance()->mMapIndex;
//    mapInfo.mMsgID = msg_map;
//    mapInfo.mPlayerID = ZapyaJNI::GetLocalInfo().playerID;
//    mapInfo.mLength = sizeof(mapInfo);
//    
//    SocketStaticProtocol::SendRequest(mapInfo.mMsgID, &mapInfo, mapInfo.mLength, 0);
}








