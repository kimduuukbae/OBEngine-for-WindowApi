#include "stdafx.h"
#include "Button.h"

void Button::setPos(int x, int y){
	xPos = x;
	yPos = y;
}
void Button::setTexture(const char* sv){
	buttonBitmap = (HBITMAP)LoadImage(NULL, sv, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(buttonBitmap, sizeof(BITMAP), &imageSize);
	xSize = imageSize.bmWidth;
	ySize = imageSize.bmHeight;
	bShowFlag = true;
 }
bool Button::collision(int x, int y) {
	if (bShowFlag && xPos <= x && xPos + xSize >= x &&
		yPos <= y && yPos + ySize >= y)
		return true;
	return false;
}
Button::~Button()
{
	if (buttonBitmap != nullptr)
		DeleteObject(buttonBitmap);
}
void Button::setShow(bool bFlag) {
	bShowFlag = bFlag;
}

void Button::setSize(float x, float y){
	xSize = (int)(x * imageSize.bmWidth);
	ySize = (int)(y * imageSize.bmHeight);
}
