#pragma once
#include "Button.h"

class ClickButton : public Button{
public:
	ClickButton() = default;
	virtual void update() override;
	virtual void draw(HDC hDC) override;
	void drawBlend(HDC hDC);
};
