#pragma once
#include "vector.h"

class Input {
public:
	Input();
	static inline Input* instance() {
		static Input instance_;
		return &instance_;
	}
	bool isKeyDown(int vk);
	bool isKeyUp(int vk);
	/*
		@Brief : 키가 계속 눌리고 있는지 검사합니다.
		@args : visual keyboard value
		@return : bool
	*/
	bool isKeyOverlap(int vk);
	/*
		@Brief : 실시간으로 마우스의 값을 가져옵니다.
		@args : NONE
		@return : std::pair<x값, y값>
	*/
	Vector2D isKeyMove();
	Vector2D currentMousePos();

private:
	bool bFlag[256];
};