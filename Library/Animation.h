#pragma once
#pragma comment(lib, "msimg32.lib")

class Animation {
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
	/*
		@Breif : 현재 플레이 중인 이미지를 몇번으로 바꿀건지 수정합니다.
		예를 들어 0을 입력하면 0번째 이미지부터 다시 출력됩니다.
	*/
	void setIndex(int index);
	/*
		@Breif : 현재 플레이 중인 이미지의 index를 읽어옵니다.
		@return : 현재 index의 값 ( 0 ~ ? )
	*/
	int getIndex();
	/*
		@Breif : setTexture 된 이미지의 최종 Index를 읽어옵니다.
		@return : Animation sequence 의 마지막 Index 값 
	*/
	int getMaxIndex();
	~Animation();
protected:
	BLENDFUNCTION bf;
	HBITMAP* hBitmap{ nullptr };
	BITMAP imageSize;

	int xPos, yPos; // 애니메이션의 좌표
	int xOffset, yOffset; // 애니메이션의 Offset

	int Idx, IdxPlan; // 현재 애니메이션의 idx

	bool blendFlag;

	float timePlan, time;	// 애니메이션이 바뀌는 시간

	HDC memDC{ nullptr };
};