#pragma once

#include "BaseScene.h"

class CGameOver : public CBaseScene
{
public:
	/**	��ʼ������	*/
	virtual bool init();

	/**	����	*/
	static CCScene* scene();

	/**	��������	*/
	CREATE_FUNC(CGameOver);

private:
	/**	���ذ�ť�Ļص�����	*/
	void back(CCObject* pSender);
};
