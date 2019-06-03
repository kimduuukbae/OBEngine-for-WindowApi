#pragma once
#include "stdafx.h"
#pragma comment(lib, "msimg32.lib")

class __declspec ( dllexport ) Animation {
public:
	/*
		@brief : 사용될 Animation Sprite 들을 지정합니다.
		@args : count : 사용될 이미지의 갯수, name : 사용될 이미지의 이름들
	*/
	void setTexture(int count, const char* name, ...);
	void setPos(int x, int y);
	void setblend(float size);
	void setblendFlag(bool bFlag);
	void draw(HDC hDC);
	void update(float dt);
	/*
		@breif : Animation 이 몇 초를 주기로 이미지를 변경할 것인지 지정합니다.
		기본은 1.0f (1초) 입니다.
	*/
	void setTime(float time);
	/*
		@breif : 이미지의 중심점을 이동합니다. 기본은 (0, 0) 입니다.
	*/
	void setOffset(int x, int y);
	~Animation();
protected:
	BLENDFUNCTION bf;
	HBITMAP* hBitmap{ nullptr };
	BITMAP imageSize;

	int xPos, yPos; // 애니메이션의 좌표
	int xSize, ySize;
	int xOffset, yOffset; // 애니메이션의 Offset

	int Idx, IdxPlan; // 현재 애니메이션의 idx

	bool blendFlag;

	float timePlan, time;	// 애니메이션이 바뀌는 시간

	HDC memDC{ nullptr };
};