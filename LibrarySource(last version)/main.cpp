#include "Define.h"
#include "sceneLogo.h"
#include "SceneGame.h"
// 모든 오브젝트와 씬은 camel Case 로 작성함, 그러나 Class (Base 포함) 는 Pascal Case 로 작성함.
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
