#pragma once
#include "Scene.h" //Scene ����� ����

class SceneLogo : public Scene {
public:
	virtual void init() override;
	virtual void update(float dt) override;
	virtual void draw(HDC hDC) override;
	virtual void destroy() override;
	// �� 4���� �Լ��� �� override �ؾ� �մϴ�. (abstract class)


	//mouseDownEvent �Լ��� �ٸ� sample ���� �ٷ絵�� �ϰڽ��ϴ�. override�� ���� �ʾƵ� �˴ϴ�.
	//virtual void mouseDownEvent(const Vector2D& mousePos)override;
private:
};
