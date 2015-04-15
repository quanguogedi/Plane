#pragma once

#include "RoleSprite.h"

extern int g_iGameLevel;

class CPlayerSprite : public CRoleSprite
{
public:
	/**	��ʼ������	*/
	bool init(int iType);

	/**	���ͨ�غ�ĳ�ʼ��	*/
	void initAttrWithWin();
	
	/**	��ȡ������	*/
	int getLife(){return m_iLife;}

	/**	��ȡHP����ֵ	*/
	int getHpMax(){return m_iHpMax;}

	/**	��ȡHPֵ*/
	int getHp(){return m_iHp;}

	/**	��ȡ����	*/
	int getScore(){return m_iScore;}

	/**	�����Ʒ	*/
	void gainItem(int iType, int iScore);

	/**	���ӷ���	*/
	void addScore(int iValue);

	/**	�Ƿ�ͨ��	*/
	bool isWin(){return m_bWin;}

	/**	����ͨ�غ���ƶ�	*/
	void setWinMove();

	/**	����ͨ�صĲ���ֵ*/
	void setWin(bool bValue){m_bWin = bValue;}

	/**	���䵼��	*/
	void shootMissile();

	/**	�Ƿ��б�����	*/
	bool isShield(){return m_bShield;}

	/**	��ȡ��������	*/
	int getMissileNum(){return m_iMissileNum;}

	/**	��������	*/
	static CPlayerSprite* create(int iType);

private:
	/**	������Ļ	*/
	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

	/**	������Ļ	*/
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);

	/**	�ӵ�����	*/
	virtual void shoot(float dt);

	/**	���������ĳ�ʼ��	*/
	void initAttrWithDie();

	/**	����	*/
	virtual void destroy(CCNode *pSender);

	/**	ͨ��	*/
	void win(CCNode *pSender);

	/**	���ñ�������Ч	*/
	void setShield();

	/**	�����������Ч	*/
	void clearShield(float dt);

	/**	�����ӵ�������Ч	*/
	void setShoot();

	/**	����ӵ�������Ч	*/
	void clearShoot();
	
	/**	��������	*/
	void createMissile();

	/**	������ը	*/
	void MissileExplore(CCNode *pSender);

	/**	��������	*/
	void MissileDestroy(CCNode *pSender);

	/**	�����Ե��˵��˺�	*/
	void hurtEnemy();

	CCPoint m_PosBack;					///<���ݴ���������
	bool m_bMissile;					///<�Ƿ��䵼����
	int m_iScore;						///<����
	bool m_bShield;						///<�Ƿ񱣻���
	bool m_bWin;						///<�Ƿ�ͨ��
	int m_iAddLifeScore;				///<���������������
	int m_iMissileNum;					///<��������
	unsigned int m_iShootSoundId;		///<�����ӵ���ЧID
	CCActionInterval*  m_pMoveAction;	///<�ƶ�
	CCSprite *m_pMissile;				///<��������
    
    CCSprite* m_Ray;                    ///ս��4����
};
