#pragma once
#include <windows.h>
#include <string_view>

class Sprite {
public:
	void setTexture(const std::string& fileName);
	void setPos(int x, int y);
	void setSize(float x, float y);
	void setBlend(float size);
	void setBlendFlag(bool bFlag);
	void draw(HDC hDC);
	~Sprite();
	Sprite() = default;
protected:
	BLENDFUNCTION bf;
	HBITMAP hBitmap;
	BITMAP imageSize;
	int xPos, yPos;
	int xSize, ySize;
	bool blendFlag;
};