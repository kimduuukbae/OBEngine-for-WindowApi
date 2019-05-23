#include "SceneGame.h"
#include "Define.h"

void SceneGame::init(){
}

void SceneGame::update(float dt){
	if (D_INPUT->isKeyDown(VK_SPACE))
		D_SCENE->changeSceneFade("Logo");
}

void SceneGame::draw(HDC hDC){
	std::string s{ "SceneGame" };
	TextOut(hDC, 512, 364, s.c_str(), s.size());
}

void SceneGame::destroy(){
}
