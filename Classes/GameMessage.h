#pragma once
#include "cocos2d.h"

#include "Box2D/Box2D.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;

class CGameMessage : public CCLayer
{
public:
	/**	��ʼ������	*/
	virtual bool init();

	/**	��������	*/
	CREATE_FUNC(CGameMessage);

private:
	/**	���º���	*/
	void update(float dt);

	/**	��ʾ����	*/
	void showScore();

	/**	��ʾHP	*/
	void showHp();

	/**	��ʾ����	*/
	void showLife();

	/**	��ʾ����	*/
	void showMissile();

	/**	���䵼��*/
	void shootMissile(CCObject* pSender);

	CCSprite *m_pHp;						///<HPѪ������
	CCLabelAtlas *m_pScore;					///<������ǩ
	CCLabelAtlas *m_pLife;					///<��������ǩ
	CCMenuItemImage *m_pMissileItem;		///<������ť�Ĳ˵���
	CCLabelAtlas *m_pMissileNum;			///<��������ǩ
	int m_iHeight;							///<HPѪ������ĸ�
	int m_iWidth;							///<HPѪ������Ŀ�
	float m_fMinX;							///<HPѪ������֡��ͼƬ�����СXֵ
	float m_fMinY;							///<HPѪ������֡��ͼƬ�����СYֵ
};
