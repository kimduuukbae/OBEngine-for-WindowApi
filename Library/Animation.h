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

	int xPos, yPos; // �ִϸ��̼��� ��ǥ
	int xSize, ySize;
	int xOffset, yOffset; // �ִϸ��̼��� Offset

	int Idx, IdxPlan; // ���� �ִϸ��̼��� idx

	bool blendFlag;

	float timePlan, time;	// �ִϸ��̼��� �ٲ�� �ð�

	HDC memDC;
};