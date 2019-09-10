#pragma once
#include "Scene.h"
#include "ClickButton.h"
class SceneGame : public Scene {
public:
	virtual void init() override;
	virtual void update(float dt) override;
	virtual void draw(HDC hDC) override;
	virtual void destroy() override;

	SceneGame() = default;
	virtual ~SceneGame() = default;

private:
	int x{ 50 };
	int y{ 50 };
	ClickButton button;
};
//Make SceneManager ( SingleTone )