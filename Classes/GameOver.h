#pragma once

#include "BaseScene.h"

class CGameOver : public CBaseScene
{
public:
	/**	初始化函数	*/
	virtual bool init();

	/**	场景	*/
	static CCScene* scene();

	/**	创建函数	*/
	CREATE_FUNC(CGameOver);

private:
	/**	返回按钮的回调函数	*/
	void back(CCObject* pSender);
};
