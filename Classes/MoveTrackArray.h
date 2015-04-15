#pragma once

#include "cocos2d.h"

#include "Box2D/Box2D.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;

class CMoveTrackArray
{
public:
	/**	��ȡ���˵��ƶ��켣����	*/
	static CCPointArray *getEnemyArray(int iType);

	/**	��ȡBOSS���ƶ��켣����	*/
	static CCPointArray *getBossArray(int iType, int iHeight, int iWidth);

private:
	/**	���˵��ƶ��켣����1	*/
	static CCPointArray *getEnemyArray1();

	/**	���˵��ƶ��켣����2	*/
	static CCPointArray *getEnemyArray2(int iDirection);

	/**	BOSS���ƶ��켣����1	*/
	static CCPointArray *getBossArray1(int iHeight, int iWidth);

	/**	BOSS���ƶ��켣����2	*/
	static CCPointArray *getBossArray2(int iHeight, int iWidth);

	/**	BOSS���ƶ��켣����3	*/
	static CCPointArray *getBossArray3(int iHeight, int iWidth);
    
    
    //new
    static CCPointArray* GetVerticalLineArray();
    static CCPointArray* GetSlantLineArray();
    static CCPointArray* GetBackSlantLineArray();
    static CCPointArray* GetHorizontalLeftArray();
    static CCPointArray* GetHorizontalRightArray();

};
