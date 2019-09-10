#include "stdafx.h"
#include "Sprite.h"

void Sprite::setTexture(const char* fileName) {
	hBitmap = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	blendFlag = false;
	GetObject(hBitmap, sizeof(BITMAP), &imageSize);
	xSize = imageSize.bmWidth;
	ySize = imageSize.bmHeight;
	xPos = 0;
	yPos = 0;
}

void Sprite::setPos(int x, int y){
	xPos = x;
	yPos = y;
}
void Sprite::setBlendFlag(bool bFlag) {
	blendFlag = bFlag;
}
void Sprite::setSize(float x, float y) {
	xSize = (int)(x * imageSize.bmWidth);
	ySize = (int)(y * imageSize.bmHeight);
}
void Sprite::setBlend(float size){
	bf.AlphaFormat = 0;
	bf.BlendFlags = 0;
	bf.BlendOp = AC_SRC_OVER;
	bf.SourceConstantAlpha = (BYTE)(255 * size);
}
void Sprite::draw(HDC hDC){

	if (blendFlag == true) {
		AlphaBlend(hDC, xPos, yPos, (int)xSize, (int)ySize, drawDC, 0, 0, imageSize.bmWidth,
			imageSize.bmHeight, bf);
	}
	else
		StretchBlt(hDC, xPos, yPos, (int)xSize, (int)ySize, drawDC, 0, 0, imageSize.bmWidth, imageSize.bmHeight,
			SRCCOPY);
}
void Sprite::drawBlend(HDC hDC) {
	HDC memDC = CreateCompatibleDC(hDC);
	SelectObject(memDC, hBitmap);
	if (blendFlag) {
		AlphaBlend(hDC, xPos, yPos, (int)xSize, (int)ySize, memDC, 0, 0, imageSize.bmWidth,
			imageSize.bmHeight, bf);
	}
	else {
		TransparentBlt(hDC, xPos, yPos, xSize, ySize,
			memDC, 0, 0, imageSize.bmWidth, imageSize.bmHeight, RGB(255, 0, 255));
	}
	DeleteDC(memDC);
}
Sprite::~Sprite(){
	DeleteObject(hBitmap);
	DeleteObject(blendBitmap);
	DeleteDC(drawDC); // 여기까지 했음
}
