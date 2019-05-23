#include <Windows.h>
#include "Define.h"
#include "SceneLogo.h"
#include "SceneGame.h"
#pragma comment(lib, "OBEngine.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int){
	D_WORLD->worldInit("Sample", 1024, 768, hInstance);
	D_WORLD->setFrame(60.0f);

	D_SCENE->commit("Logo", new SceneLogo);
	D_SCENE->commit("Game", new SceneGame);
	D_SCENE->changeScene("Logo");
	D_WORLD->runLoop();

	
}
