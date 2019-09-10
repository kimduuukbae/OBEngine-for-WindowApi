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
		@Brief : Ű�� ��� ������ �ִ��� �˻��մϴ�.
		@args : visual keyboard value
		@return : bool
	*/
	bool isKeyOverlap(int vk);
	/*
		@Brief : �ǽð����� ���콺�� ���� �����ɴϴ�.
		@args : NONE
		@return : std::pair<x��, y��>
	*/
	Vector2D isKeyMove();
	Vector2D currentMousePos();

private:
	bool bFlag[256];
};