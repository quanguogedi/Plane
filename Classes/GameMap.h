#pragma once
#include "cocos2d.h"

using namespace cocos2d;

extern int g_iGameLevel;		// ��Ϸ�ؿ�

class CGameMap : public CCLayer
{
public:
	/**	��ʼ������	*/
	virtual bool init();
    
    virtual void update(float _dt);
    
    //��ͼ����
    void scroll();

	/**	��ͼ��*/
	void shake();

	/**	��������	*/
	CREATE_FUNC(CGameMap);

private:
	CCSprite* m_pMap;	///<��ͼ����
    CCSprite * mBgFirst;
    CCSprite * mBgSecond;
    float mBgOffsetY;
    float mBgHeight;//�����߶�
};
