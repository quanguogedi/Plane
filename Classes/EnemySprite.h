#pragma once

#include "RoleSprite.h"

// �̳�CCSprite CCAnimation:create �ᱨ��
class CEnemySprite : public CRoleSprite
{
public:
	/**	��ʼ������ */
	bool init(int iType, int startType = 0, int moveType = 1);

	/**	��������	*/
	static CEnemySprite* create(int iType, int startType = 0, int moveType = 1);

protected:
	/**	���º���	*/
	void update(float dt);

	/**	��������	*/
	void setAttr();
//    void Set
    
    //λ��
    void setPosType(int posType);

	/**	�����ƶ��켣	*/
	void setRun(float dt);

	/**	 ���þ�������	*/
	void setDelFunc(CCNode* sender);

	/**	�ӵ�����	*/
	virtual void shoot(float dt);

	/**	����	*/
	virtual void destroy(CCNode *pSender);

	int m_iScore;			///<ɱ������õķ���
    int mStartType;         // ��ʼλ��
	int m_iMoveType;		///<�ƶ��켣����
	
};
