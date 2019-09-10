#include "stdafx.h"
#include "Animation.h"
void Animation::setTexture(int count, const char * name, ...) {
	if (hBitmap != nullptr) {
		for(int i = 0 ; i < count ; ++i)
			DeleteObject(hBitmap);

		delete[] hBitmap;
	}
	hBitmap = new HBITMAP[count];
	va_list ap;

	va_start(ap, count);

	for (int i = 0; i < count; ++i) {
		const char* p = va_arg(ap, const char*);
		hBitmap[i] = (HBITMAP)LoadImage(NULL, p, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	va_end(ap);

	blendFlag = false;
	GetObject(hBitmap[0], sizeof(BITMAP), &imageSize);
	timePlan = 1.0f;
	xOffset = 0;
	yOffset = 0;
	IdxPlan = count;
	Idx = 0;
	time = 0.0f;
	bLoop = true;
}

void Animation::setPos(int x, int y) {
	xPos = x;
	yPos = y;
}
void Animation::setTime(float time) {
	timePlan = time;
}
void Animation::setOffset(int x, int y) {
	xOffset = x;
	yOffset = y;
}
void Animation::update(float dt) {
	time += dt;
	if (time >= timePlan) {
		if (bLoop) {
			++Idx;
			Idx %= IdxPlan;
		}
		else
			if(Idx != IdxPlan-1)
				++Idx;
		time = 0.0f;
	}
}
void Animation::draw(HDC hDC) {
	if (memDC == nullptr)
		memDC = CreateCompatibleDC(hDC);

	if (blendFlag) {

	}
	else {
		SelectObject(memDC, hBitmap[Idx]);
		TransparentBlt(hDC, xPos + xOffset, yPos + yOffset, imageSize.bmWidth, imageSize.bmHeight,
			memDC, 0, 0, imageSize.bmWidth, imageSize.bmHeight, RGB(255, 0, 255));
	}
}
Animation::~Animation() {
	delete[] hBitmap;
	DeleteDC(memDC);
}
void Animation::setIndex(int index) {
	Idx = index;
	time = 0.0f;
}
int Animation::getIndex() {
	return Idx;
}
int Animation::getMaxIndex() {
	return IdxPlan - 1;
}

void Animation::setLoop(bool flag){
	bLoop = flag;
}
