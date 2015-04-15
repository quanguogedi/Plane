#pragma once

#include "cocos2d.h"

#include "EnemySprite.h"
#include "PlayerSprite.h"

using namespace cocos2d;

class CItemManager : public CCLayer
{
public:
	/**	��ʼ������	*/
    virtual bool init();

	/**	������Ʒ	*/
	void createItem(int iType, float x, float y);
	
	/**	��������	*/
	CREATE_FUNC(CItemManager);

private:
	/**	���º���	*/
	void update(float dt);

	CCSpriteBatchNode* m_pItemList;		///<��Ʒ�б�
	int m_iItemCout;					///<Tag�ļ���ֵ
};
