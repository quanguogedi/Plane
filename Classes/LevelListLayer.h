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

class LevelListLayer : public CCLayer, public CCScrollViewDelegate
{
public:
    virtual bool init();
    CREATE_FUNC(LevelListLayer);
    
private:
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView *view);
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView *view);
    
public:
    void AddSubCell(CCNode* cell);
    void SetScrollHeight(float h);
    
private:
    CCScrollView* mLevelListScrollView;
    CCNode* mContainerNode;
    
};




#endif /* defined(__Plane__LevelListLayer__) */
