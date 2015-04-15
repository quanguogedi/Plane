#pragma once
#include "cocos2d.h"

using namespace cocos2d;

extern int g_iGameLevel;		// 游戏关卡

class CGameMap : public CCLayer
{
public:
	/**	初始化函数	*/
	virtual bool init();
    
    virtual void update(float _dt);
    
    //地图滚动
    void scroll();

	/**	地图震动*/
	void shake();

	/**	创建函数	*/
	CREATE_FUNC(CGameMap);

private:
	CCSprite* m_pMap;	///<地图精灵
    CCSprite * mBgFirst;
    CCSprite * mBgSecond;
    float mBgOffsetY;
    float mBgHeight;//背景高度
};
