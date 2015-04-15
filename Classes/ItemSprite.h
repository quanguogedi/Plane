#pragma once
#include "UnitSprite.h"

class CItemSprite : public CUnitSprite
{
public:
	/**	��ʼ������	*/
	bool init(int iType, float x, float y);

	/**	��������	*/
	static CItemSprite* create(int iType, float x, float y);

private:
	/**	���º���	*/
	void update(float dt);

	/**	����ƶ�	*/
	void randomMove(float dt);

	/**	��������	*/
	void setAttr();

	/**	 ���þ�������	*/
	void setDelFunc(CCNode* sender);

	/**	�ı䱦ʯ����	*/
	void changeType(float dt);
	
	/**	���ñ�ʯ�Ķ���	*/
	void setAnimation();

	int m_iType;			///<��Ʒ����
	int m_iScore;			///<�õ�����Ʒ���õķ���
};