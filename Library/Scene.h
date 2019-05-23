#pragma once
#include <Windows.h>
class Vector2D;

class Scene {
public:
	/*
		�� ���� �������� �ʱ�ȭ �ҋ� ���� �Լ�
	*/
	virtual void init() = 0;
	/*
		�� ���� �������� ���, dt �� deltatime �̸�, '��' ��! (millisecond �ƴ� !)
	*/
	virtual void update(float dt) = 0;
	/*
		��� �׸���� ���⼭ �ۼ���.
	*/
	virtual void draw(HDC hDC) = 0;
	/*
		���� �Ҵ��� �Լ��� �ִٸ� ���⼭ ����
	*/
	virtual void destroy() = 0;
	/*
		���콺�� ���� ��ư�� ������ ��.
	*/
	virtual void mouseDownEvent(const Vector2D& mousePos) { }
	virtual void mouseMoveEvent(const Vector2D& mosuePos) { }
	Scene() = default;
	virtual ~Scene() = default;
private:
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
};

// ��� ���� �� Scene�� ����ϱ⸸ �ϸ� Scene���� ����� �� ����
