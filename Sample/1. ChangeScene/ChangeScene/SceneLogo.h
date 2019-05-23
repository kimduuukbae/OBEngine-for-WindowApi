#pragma once
#include "Scene.h" //Scene 상속을 위해

class SceneLogo : public Scene {
public:
	virtual void init() override;
	virtual void update(float dt) override;
	virtual void draw(HDC hDC) override;
	virtual void destroy() override;
	// 이 4개의 함수는 꼭 override 해야 합니다. (abstract class)


	//mouseDownEvent 함수는 다른 sample 에서 다루도록 하겠습니다. override는 하지 않아도 됩니다.
	//virtual void mouseDownEvent(const Vector2D& mousePos)override;
private:
};
