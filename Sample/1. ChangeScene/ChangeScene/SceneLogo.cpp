#include "SceneLogo.h"
#include "Define.h"
void SceneLogo::init(){

}

void SceneLogo::update(float dt){
	if (D_INPUT->isKeyDown(VK_SPACE))
		D_SCENE->changeSceneFade("Game");
}

void SceneLogo::draw(HDC hDC){

}

void SceneLogo::destroy(){
}

//void SceneLogo::mouseDownEvent(const Vector2D& mousePos) {
//
//}
