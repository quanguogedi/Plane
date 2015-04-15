#pragma once

#include "RoleSprite.h"

// 继承CCSprite CCAnimation:create 会报错
class CEnemySprite : public CRoleSprite
{
public:
	/**	初始化函数 */
	bool init(int iType, int startType = 0, int moveType = 1);

	/**	创建函数	*/
	static CEnemySprite* create(int iType, int startType = 0, int moveType = 1);

protected:
	/**	更新函数	*/
	void update(float dt);

	/**	设置属性	*/
	void setAttr();
//    void Set
    
    //位置
    void setPosType(int posType);

	/**	设置移动轨迹	*/
	void setRun(float dt);

	/**	 设置精灵消亡	*/
	void setDelFunc(CCNode* sender);

	/**	子弹发射	*/
	virtual void shoot(float dt);

	/**	销毁	*/
	virtual void destroy(CCNode *pSender);

	int m_iScore;			///<杀死所获得的分数
    int mStartType;         // 初始位置
	int m_iMoveType;		///<移动轨迹类型
	
};
