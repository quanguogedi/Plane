#pragma once
#include "UnitSprite.h"

enum
{
	LEFT,
	STRAIGHT,
	RIGHT,
};
enum
{
    //
	PLAYER = 0,//��ͨ1
    PLAYER2,//��ͨ2
    PLAYER3,//ɢ��
    PLAYER4,//����
    //
    PLAYER_WING_BULLET,
    PLAYER2_WING_BULLET,
    PLAYER3_WING_BULLET,
    PLAYER4_WING_BULLET,
    //
    PLAYER_MISSILE,
    PLAYER2_MISSILE,
    PLAYER3_MISSILE,
    PLAYER4_MISSILE,
    //
	ENEMY,
    
    //max
    BULLET_EFFECT_MAX,
};

class CRoleSprite : public CUnitSprite
{
public:
	/**	���˺�	*/
	void hurt(int iHarm);

	/**	�Ƿ�����	*/
	bool isDestroy(){return m_bDestroy;}

protected:
	/**	���÷��ж���	*/
	void setFlyAnimation(int iDirection);

	/**	 ���þ�������	*/
	void setDelFunc(CCNode* sender);

	/**	�����ӵ�	*/
	virtual void shoot(float dt) = 0;

	/**	��ը	*/
	void explosion();

	/**	����	*/
	virtual void destroy(CCNode *pSender) = 0;

	/**	�ı���ж���	*/
	void changeFlyAnimation(float dt);

	/**	��ȡ���з���	*/
	int getDirection();

	int m_iHpMax;			///<HP����
	int m_iHp;				///<HP
	int m_iType;			///<�ɻ�����    
	bool m_bDestroy;		///<�Ƿ�����
	float m_fShootSpace;	///<�����ӵ����
	CCPoint m_pos;			///<��ʼ������
	int m_iBulletType;		///<�ӵ�����
    int m_iWingBulletType;  ///�Ż��ӵ�
     int m_iSubMissleType;  ///<����
	int m_iFlyStraightNum;	///<ֱ�ɶ���֡��
	int m_iFlyLeftNum;		///<��ɶ���֡��
	int m_iLife;			///<������
	int m_iDirection;		///<���з���
	int m_iBulletNum;		///<�ӵ�����
	CCSprite *m_pExplosion;	///<��ը����
	
};
