#include "Sprite.h"

void Sprite::setTexture(const std::string & fileName) {
	hBitmap = (HBITMAP)LoadImage(NULL, fileName.data(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	blendFlag = false;
}

void Sprite::setPos(int x, int y){
	xPos = x;
	yPos = y;
}
void Sprite::setBlendFlag(bool bFlag) {
	blendFlag = bFlag;
}
void Sprite::setSize(float x, float y) {
	GetObject(hBitmap, sizeof(BITMAP), &imageSize);
	xSize = (int)(x * imageSize.bmWidth);
	ySize = (int)(y * imageSize.bmHeight);
}
void Sprite::setBlend(float size){
	bf.AlphaFormat = 0;
	bf.BlendFlags = 0;
	bf.BlendOp = AC_SRC_OVER;
	bf.SourceConstantAlpha = (int)(255 * size);
}
void Sprite::draw(HDC hDC){
	HDC memDC = CreateCompatibleDC(hDC);
	SelectObject(memDC, hBitmap);
	if (blendFlag == true)
		AlphaBlend(hDC, xPos, yPos, (int)xSize, (int)ySize, memDC, 0, 0, imageSize.bmWidth,
			imageSize.bmHeight, bf);
	else
		BitBlt(hDC, xPos, yPos, (int)xSize, (int)ySize, memDC,0,0, SRCCOPY);
	DeleteDC(memDC);
}
Sprite::~Sprite(){
	DeleteObject(hBitmap);
}
