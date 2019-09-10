#include "stdafx.h"
#include "OBString.h"
#include "Fps.h"
#include "Camera.h"


Fps::Fps() {
	lastTime = (float)GetTickCount();
	timeElapsed = 0.0f;
	frameCount = 0;
	showFps = 0;
	delay = 0;
}
float Fps::update()
{
	auto now = GetTickCount();
	auto dt = 0.0f;
	timeElapsed += dt = (now - lastTime) * 0.001f;
	++frameCount;
	if (timeElapsed >= 1.0f) {
		showFps = (int)(frameCount);
		frameCount = 0;
		timeElapsed = 0.0f;
		if (showFps <= limitTime - 2)
			--delay;
		else if (showFps > limitTime)
			++delay;
	}
	else
		Sleep(delay - timeElapsed);
	lastTime = (float)now;
	return dt;
}
void Fps::setFrame(float fTime) {
	limitTime = fTime;
	delay = (int)(1000 / fTime);
}
void Fps::draw(HDC hDC)
{	
	auto s = makeString(showFps);
	TextOut(hDC, Camera::instance()->currentCameraX(), 
		Camera::instance()->currentCameraY(), s.getString(), s.getSize());
}
