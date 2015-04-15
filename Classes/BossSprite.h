#pragma once

#include "EnemySprite.h"

class CBossSprite : public CEnemySprite
{
public:
	/**	��ʼ������	*/
	bool init(int iType);
	
	/**	���º���	*/
	void update(float dt);

	/**	��������	*/
	void setAttr();

	/**	�����ƶ��켣	*/
	void setRun(float dt);

	/**	�ӵ�����	*/
	virtual void shoot(float dt);

	/**	�ӵ�2����	*/
	virtual void shoot2(float dt);

	/**	����	*/
	virtual void destroy(CCNode *pSender);

	/**	��������	*/
	static CBossSprite* create(int iType);

private:

	int m_iBullet2Num;		///<�ӵ�2����
	int m_iBullet2Type;		///<�ӵ�2����
	int m_fShoot2Space;		///<�ӵ�2������
	bool m_bHpChange1;		///<HP�ı�1��HP�Ƿ�С��2/3��
	bool m_bHpChange2;		///<HP�ı�2��HP�Ƿ�С��1/3��
};
