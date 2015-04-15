#pragma once
//#include "cocos2d.h"
//
//#include "Box2D/Box2D.h"
//
//#include "SimpleAudioEngine.h"
//
//using namespace cocos2d;

#include "Common.h"

class CUnitSprite : public CCLayer
{
public:
	/**	���������֮��ľ���	*/
	float getDist(float fPosX, float fPosY);

	/**	�õ���ת�Ƕ�	*/
	float getAngle(float fPosX, float fPosY);

	/**	��ȡ����	*/
	CCSprite *getSprite(){ return m_pSprite; }

protected:
	char m_szName[32];		///<����ͼƬ��
	int m_iHeight;			///<����ͼƬ�ĸ�
	int m_iWidth;			///<����ͼƬ�Ŀ�
	CCSprite *m_pSprite;	///<����

};
