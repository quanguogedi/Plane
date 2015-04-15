#pragma once
#include "UnitSprite.h"

class CBulletSprite : public CUnitSprite
{
public:
	/**	��ʼ������	*/
	bool init(int iPlaneType, int iType, int iAllNum, int iCurNum, float x, float y);

	/**	��������	*/
	static CBulletSprite* create(int iPlaneType, int iType, int iAllNum, int iCurNum, float x, float y);

private:
	/**	���º���	*/
	void update(float dt);

	/**	 ���þ�������	*/
	void setDelFunc(CCNode* sender);
	
	/**	��������	*/
	void setAttr();

	/**	�����ƶ��켣	*/
	void setMoveTrack(int iAllNum, int iCurNum);

	int m_iType;			///<�ӵ�����
    int m_iFlyType;        ///�ӵ����й켣����
	int m_iPlaneType;		///<�����ӵ��ķɻ����ͣ�0Ϊ��ң�1Ϊ����
	int m_iHarm;			///<�ӵ����˺�
};
