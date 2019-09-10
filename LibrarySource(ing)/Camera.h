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
		Window ����� �ƴ� ���� ������ ũ�⸦ �˾ƿɴϴ�.
	*/
	int getWorldX();
	/*
		Window ����� �ƴ� ���� ������ ũ�⸦ �˾ƿɴϴ�.
	*/
	int getWorldY();
private:
	int xPos, yPos;	// ī�޶� �����ִ� ��ǥ
	int worldX, worldY;	// ������ X,Y ��ǥ
};