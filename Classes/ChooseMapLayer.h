//
//  ChooseMapLayer.h
//  BnB
//
//  Created by 杨延飞 on 14-11-10.
//
//

#ifndef __BnB__ChooseMapLayer__
#define __BnB__ChooseMapLayer__

#include <iostream>


class ChooseMapLayer : public CCBLayer,public CCTableViewDataSource,public CCTableViewDelegate
{
public:
    CREATE_FUNC(ChooseMapLayer);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view);
    
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view);
    
    //处理触摸事件，可以计算点击的是哪一个子项
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
    //每一项的宽度和高度
    virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::CCTableView *table);
    //生成列表每一项的内容
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    //一共多少项
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);
    
   
    void SetMiniMap();

    
    void FilterSelector(CCObject* pSender,CCControlEvent pCCControlEvent);
    void SureSelector(CCObject* pSender,CCControlEvent pCCControlEvent);
    void TypeSelector(CCObject* pSender,CCControlEvent pCCControlEvent);
    
    
    void SendChangeMapMsg();
private:
    ~ChooseMapLayer();
    
    CCTableView * mTableView;
    CCLayerColor * mMapBg;
    CCSprite * mMap;
    CCSprite * mFilterBg;
    CCLabelTTF * mDisc;
    CCMenu * mTypeMenu;
    CCSprite * mTypeMenuBg;
    
    CCSize mViewSize;
    CCTableViewCell * mSelectCell;
    CCSprite * mTypeSelectTag;
    CCSprite * mMapSelectTag;
    
};


class ChooseMapLayerLoader : public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ChooseMapLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ChooseMapLayer);
};

#endif /* defined(__BnB__ChooseMapLayer__) */
