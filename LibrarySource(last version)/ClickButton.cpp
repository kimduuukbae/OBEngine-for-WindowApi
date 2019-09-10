#include "ClickButton.h"

void ClickButton::update(){

}

void ClickButton::draw(HDC hDC){
	if (bShowFlag) {
		HDC memDC = CreateCompatibleDC(hDC);
		SelectObject(memDC, buttonBitmap);
		StretchBlt(hDC, (int)xPos, (int)yPos, (int)xSize, (int)ySize, memDC, 0, 0, imageSize.bmWidth, imageSize.bmHeight, SRCCOPY);
		DeleteDC(memDC);
	}
}