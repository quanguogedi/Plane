#pragma once

#include "cocos2d.h"

#include "EnemySprite.h"
#include "PlayerSprite.h"

using namespace cocos2d;
class CBulletManager : public CCLayer
{
public:
	/**	��ʼ������	*/
    virtual bool init();

	/**	�����ӵ�	*/
	void createBullet(int iPlaneType, int iType, int iNum, float x, float y);
//    void createWingBullet(int iPlaneType, int iType, int iNum, float x, float y);
//    void createSubMissile(int iPlaneType, int iType, int iNum, float x, float y);

	/**	��������	*/
	CREATE_FUNC(CBulletManager);

private:
	/**	���º���	*/
	void update(float dt);

	/**	��ȡ�յ�Tagֵ	*/
	int getFreeTag();

	CCSpriteBatchNode* m_pBulletList;	///<�ӵ��б�
//    CCSpriteBatchNode* m_pSubMissileList;  ///�����б�
	int m_iBulletCout;					///<Tag�ļ���ֵ
};
