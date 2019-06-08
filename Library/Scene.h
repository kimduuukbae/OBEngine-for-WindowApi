#pragma once
#include <Windows.h>
class Vector2D;

class Scene {
public:
	virtual void init() = 0;
	virtual void update(float dt) = 0;
	virtual void draw(HDC hDC) = 0;
	virtual void destroy() = 0;

	virtual void mouseDownEvent(const Vector2D& mousePos) { }
	virtual void mouseMoveEvent(const Vector2D& mosuePos) { }
	Scene() = default;
	virtual ~Scene() = default;
private:
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
};

// ��� ���� �� Scene�� ����ϱ⸸ �ϸ� Scene���� ����� �� ����
