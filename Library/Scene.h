#pragma once
#include <Windows.h>
class Vector2D;

class Scene {
public:
	/*
		각 씬의 변수들을 초기화 할떄 쓰는 함수
	*/
	virtual void init() = 0;
	/*
		각 씬의 변수들의 계산, dt 는 deltatime 이며, '초' 임! (millisecond 아님 !)
	*/
	virtual void update(float dt) = 0;
	/*
		모든 그리기는 여기서 작성함.
	*/
	virtual void draw(HDC hDC) = 0;
	/*
		만약 할당한 함수가 있다면 여기서 해제
	*/
	virtual void destroy() = 0;
	/*
		마우스의 왼쪽 버튼이 눌렸을 때.
	*/
	virtual void mouseDownEvent(const Vector2D& mousePos) { }
	virtual void mouseMoveEvent(const Vector2D& mosuePos) { }
	Scene() = default;
	virtual ~Scene() = default;
private:
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
};

// 모든 씬은 이 Scene을 상속하기만 하면 Scene으로 사용할 수 있음
