#pragma once
#pragma comment(lib, "msimg32.lib")

class  Animation {
public:
	void setTexture(int count, const char* name, ...);
	void setPos(int x, int y);
	void setblend(float size);
	void setblendFlag(bool bFlag);
	void draw(HDC hDC);
	void update(float dt);
	void setTime(float time);
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

	HDC memDC;
};