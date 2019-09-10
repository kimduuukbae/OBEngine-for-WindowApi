#include "stdafx.h"
#include "ClickButton.h"

void ClickButton::update(){

}

void ClickButton::draw(HDC hDC){
	if (bShowFlag) {
		HDC memDC = CreateCompatibleDC(hDC);
		SelectObject(memDC, buttonBitmap);
		StretchBlt(hDC, xPos, yPos, xSize, ySize, memDC, 0, 0, imageSize.bmWidth, imageSize.bmHeight, SRCCOPY);
		DeleteDC(memDC);
	}
}

void ClickButton::drawBlend(HDC hDC){
	if (bShowFlag) {
		HDC memDC = CreateCompatibleDC(hDC);
		SelectObject(memDC, buttonBitmap);
		TransparentBlt(hDC, xPos, yPos, xSize, ySize,
			memDC, 0, 0, imageSize.bmWidth, imageSize.bmHeight, RGB(255, 0, 255));
		DeleteDC(memDC);
	}
}
