#pragma once
#include "vector.h"
class Camera {
public:
	static Camera* instance();
	void setCameraPos(int x, int y);
	void setCameraPos(const Vector2D& v);
	void addCameraPos(int x, int y);
	Vector2D currentCameraPos();
	~Camera();
	int currentCameraX();
	int currentCameraY();
	/*
		Window 사이즈가 아닌 실제 월드의 크기를 알아옵니다.
	*/
	int getWorldX();
	/*
		Window 사이즈가 아닌 실제 월드의 크기를 알아옵니다.
	*/
	int getWorldY();
private:
	int xPos, yPos;	// 카메라가 보고있는 좌표
	int worldX, worldY;	// 월드의 X,Y 좌표
};