#pragma once
#include "BaseScene.h"


class CLoadLogo : public CBaseScene
{
public:
	/**	��ʼ������	*/
    virtual bool init();  

	/**	����	*/
    static CCScene* scene();

	/**	��������	*/
    CREATE_FUNC(CLoadLogo);

private:
	/**	�л�����	*/
	void makeTransition(float dt);
};

