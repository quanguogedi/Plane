#pragma once

#include "BaseScene.h"
#include "EnemyManager.h"
#include "PlayerSprite.h"
#include "BulletManager.h"
#include "ItemManager.h"
#include "GameMap.h"
#include "GameMessage.h"
#include "GameEvents.h"
#include "PauseLayer.h"

using namespace cocos2d;

class CGameManager : public CBaseScene
{
public:
	/**	���º���	*/
    virtual bool init();
	
	/**	����	*/
	static CCScene* scene();

	/**	��ȡ�����	*/
	static CPlayerSprite* getPlayer(){return m_pPlayer;}

	/**	��ȡ�ӵ�������	*/
	static CBulletManager* getBulletManager(){return m_pBulletManager;}

	/**	��ȡ���˹�����	*/
	static CEnemyManager* getEnemyManager(){return m_pEnemyManager;}

	/**	��ȡ��Ʒ������	*/
	static CItemManager* getItemManager(){return m_pItemManager;}

	/**	��ȡ��ͼ��	*/
	static CGameMap* getGameMap(){return m_pGameMap;}

	/**	��������	*/
	static CGameManager* create();

    
    //GameMenuLayer����
    virtual void OpenPauseLayer();
private:
	/**	���º���	*/
	void update(float dt);

	/**	���ذ�ť�Ļص�����	*/
	void back(CCObject* pSender);

	static CEnemyManager *m_pEnemyManager;		///<���˹���
	static CPlayerSprite *m_pPlayer;			///<��ҹ���
	static CBulletManager *m_pBulletManager;	///<�ӵ�����
	static CItemManager *m_pItemManager;		///<��Ʒ����
	static CGameMap *m_pGameMap;				///<��Ϸ��ͼ
	CGameMessage *m_pGameMessage;				///<�����Ϣ
    
    
    PauseLayer * mPauseLayer;
};
