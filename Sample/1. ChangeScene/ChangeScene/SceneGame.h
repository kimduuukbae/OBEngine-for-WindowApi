#pragma once
#include "Scene.h"

class SceneGame : public Scene {
public:
	virtual void init() override;
	virtual void update(float dt) override;
	virtual void draw(HDC hDC) override;
	virtual void destroy() override;
private:

};