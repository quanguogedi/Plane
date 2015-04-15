#pragma once
#include "BaseScene.h"


class CLoadLogo : public CBaseScene
{
public:
	/**	初始化函数	*/
    virtual bool init();  

	/**	场景	*/
    static CCScene* scene();

	/**	创建函数	*/
    CREATE_FUNC(CLoadLogo);

private:
	/**	切换场景	*/
	void makeTransition(float dt);
};

