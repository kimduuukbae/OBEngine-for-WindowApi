#include "Define.h"
#include "sceneLogo.h"
#include "SceneGame.h"
// ��� ������Ʈ�� ���� camel Case �� �ۼ���, �׷��� Class (Base ����) �� Pascal Case �� �ۼ���.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR ,  int )
{
	D_WORLD->worldInit("INVERSUS", 1024, 768, hInstance);
	D_WORLD->setFrame(60.0f);

	D_SCENE->commit("Logo", new SceneLogo);
	D_SCENE->commit("Game", new SceneGame);

	D_SCENE->changeScene("Logo");
	D_WORLD->runLoop();

	return D_WORLD->GetExitState();
}
