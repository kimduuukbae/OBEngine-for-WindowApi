#include "stdafx.h"
#include "Camera.h"
#include "World.h"

Camera* instance_{ nullptr };
Camera * Camera::instance(){
	if (instance_ == nullptr) {
		instance_ = new Camera();
		instance_->worldX = World::instance()->getWindowX()*10;
		instance_->worldY = World::instance()->getWindowY()*10;
	}
	return instance_;
}
Camera::~Camera() {
	delete instance_;
}
void Camera::setCameraPos(int x, int y) {
	xPos = x;
	yPos = y;
}
void Camera::addCameraPos(int x, int y) {
	xPos += x;
	yPos += y;
}
void Camera::setCameraPos(const Vector2D& v) {
	xPos = (int)v.getX();
	yPos = (int)v.getY();
}
Vector2D Camera::currentCameraPos() {
	return Vector2D((float)xPos, (float)yPos);
}
int Camera::currentCameraX() {
	return xPos;
}

int Camera::currentCameraY() {
	return yPos;
}

int Camera::getWorldX(){
	return worldX;
}

int Camera::getWorldY(){
	return worldY;
}
