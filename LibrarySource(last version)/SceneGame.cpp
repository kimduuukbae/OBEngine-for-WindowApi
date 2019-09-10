#include "SceneGame.h"
#include "Define.h"
void SceneGame::init()
{
}

void SceneGame::update(float dt)
{
	if (D_INPUT->isKeyDown(VK_SPACE))
		D_SCENE->changeScene("Logo");
}

void SceneGame::draw(HDC hDC)
{
	TextOut(hDC, x++, y++, "SceneGame", 9);
}

void SceneGame::destroy()
{
}
