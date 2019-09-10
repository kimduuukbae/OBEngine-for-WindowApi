#pragma once
#include <Windows.h>
#include <string_view>
class Button {
public:
	virtual void update() = 0;
	virtual void draw(HDC hDC) = 0;
	bool collision(int, int);
	void setPos(int, int);
	void setTexture(const std::string_view& sv);
	void setShow(bool);
	void setSize(float x, float y);
	~Button();
	// draw
protected:
	HBITMAP buttonBitmap;
	BITMAP imageSize;
	int xSize, ySize;
	int xPos, yPos;
	bool bShowFlag;
};