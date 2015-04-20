//
//  LevelListLayer.h
//  Plane
//
//  Created by KGB on 15/3/20.
//
//

#ifndef __Plane__LevelListLayer__
#define __Plane__LevelListLayer__

#include "Common.h"
#include "CCBLayer.h"

class LevelListLayer : public CCBLayer
{
public:
    virtual bool init();
    CREATE_FUNC(LevelListLayer);
    
private:
//    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView *view);
//    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView *view);
    
public:
    void AddSubCell(CCNode* cell);
    void SetScrollHeight(float h);
    
private:
    CCScrollView* mLevelListScrollView;
    CCNode* mContainerNode;
    
};


class LevelListLayerLoader: public CCBLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LevelListLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(LevelListLayer);
};




#endif /* defined(__Plane__LevelListLayer__) */
