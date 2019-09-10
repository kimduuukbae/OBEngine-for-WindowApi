#pragma once
#include "ClickButton.h"
enum E_OVERLAP_STATE {
	E_NONE,
	E_OVERLAP,
	E_CLICK
};
class OverlapButton : public ClickButton {
public:
	OverlapButton();
	virtual void draw(HDC hDC) override;
	virtual void update() override;
private:
	bool overlap;
	E_OVERLAP_STATE overlapState;
};