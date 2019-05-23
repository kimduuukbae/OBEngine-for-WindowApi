#pragma once
#include "vector.h"

class Input {
public:
	Input();
	~Input();
	static Input* instance();
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
		@return : std::pair<xPos, yPos>
	*/
	Vector2D isKeyMove();
	/*
		@Breif : ���� ���콺�� ��ǥ�� �����ɴϴ�.
		@args : NONE
		@return : Vector2D(xPos, yPos)
	*/
	Vector2D currentMousePos();

private:
	bool bFlag[256];
};