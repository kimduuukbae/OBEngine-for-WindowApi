#include "Fps.h"
#include <string>
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
		showFps = (int)(frameCount / timeElapsed);
		frameCount = 0;
		timeElapsed = 0.0f;
	}
	else 
		Sleep(delay);
	
	lastTime = (float)now;
	return dt;
}
void Fps::setFrame(float fTime) {
	limitTime = fTime;
	delay = (int)(1000 / fTime);
}
void Fps::draw(HDC hDC)
{	
	auto s = std::to_string(showFps);
	TextOut(hDC, 0, 0, s.c_str(), s.size());
}
