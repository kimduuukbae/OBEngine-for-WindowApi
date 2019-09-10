#pragma once

//Frame per second, 프레임을 관리하는 함수

class Fps {
public:
	Fps();
	float update();
	void draw(HDC hDC);
	void setFrame(float fTime);
private:
	float limitTime;
	float lastTime;
	float timeElapsed;
	int frameCount;

	int showFps;

	int delay;
};