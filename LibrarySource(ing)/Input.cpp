#include "stdafx.h"
#include "Input.h"
#include "World.h"

static Input* instance_{ nullptr };

Input::Input() {
	for (int i = 0; i < 256; ++i)
		bFlag[i] = false;
}
Input::~Input() {
	delete instance_;
}
bool Input::isKeyDown(int vk)
{
	if (GetAsyncKeyState(vk) & 0x8000) {
		if (!bFlag[vk])
			return bFlag[vk] = true;
	}
	else
		bFlag[vk] = false;
	return false;
}
bool Input::isKeyOverlap(int vk) {
	return (GetAsyncKeyState(vk) & 0x8000) ? true : false;
}
bool Input::isKeyUp(int vk)
{
	if (GetAsyncKeyState(vk) & 0x8000)
		bFlag[vk] = true;
	else
		if (bFlag[vk] == true)
			return !(bFlag[vk] = false);
	return false;
}

Vector2D Input::isKeyMove()
{
	return Vector2D();		// ¾ÆÁ÷ ¾È¸¸µë
}
Vector2D Input::currentMousePos() {
	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(World::instance()->getWndHandle(), &mouse);
	return Vector2D((float)mouse.x, (float)mouse.y);
}

Input* Input::instance() {

	if (instance_ == nullptr) instance_ = new Input();
	return instance_;
}