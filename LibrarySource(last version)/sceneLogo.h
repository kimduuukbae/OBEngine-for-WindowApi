#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "ClickButton.h"

class SceneLogo :  public Scene{
public:
	virtual void init() override;
	virtual void update(float dt) override;
	virtual void draw(HDC hDC) override;
	virtual void destroy() override;
	virtual void mouseDownEvent(const Vector2D& mousePos);
	SceneLogo() = default;
	virtual ~SceneLogo() = default;

private:
	
	Sprite m_sprite;
	Sprite backGround;

	ClickButton startButton;
	ClickButton exitButton;

};
