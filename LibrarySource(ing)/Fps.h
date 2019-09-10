#pragma once

//Frame per second, �������� �����ϴ� �Լ�

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