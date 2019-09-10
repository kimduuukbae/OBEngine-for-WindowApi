#include "SceneManager.h"

SceneManager::~SceneManager() {

}

void SceneManager::commit(const std::string & name, Scene * scene){
	AllScene.emplace(std::move(name), std::move(scene));
}

void SceneManager::changeScene(const std::string & name){
	if (pCurrent != nullptr)
		pCurrent->destroy();
	currentSceneName = name;
	pCurrent = AllScene[currentSceneName];
	pCurrent->init();
}

void SceneManager::changeSceneFade(const std::string & name) {
	currentSceneName = name;
	fadeState = E_FADE_IN;
	bf.SourceConstantAlpha = 0;
	bf.AlphaFormat = 0;
	bf.BlendFlags = 0;
	bf.BlendOp = AC_SRC_OVER;
}
void SceneManager::update(float dt)
{
	pCurrent->update(dt);
}
void SceneManager::draw(HDC hDC)
{
	pCurrent->draw(hDC);
	switch (fadeState) {
	case E_FADE_IN:
		if (fade == NULL) {
			fade = CreateCompatibleDC(hDC);
			fadebit = CreateCompatibleBitmap(hDC, 1024, 768);
			SelectObject(fade, fadebit);
			DeleteObject(fadebit);
		}
		Rectangle(fade, 0, 0, 1024, 768);
		AlphaBlend(hDC, 0, 0, 1024, 768, fade, 0, 0, 1024, 768, bf);
		bf.SourceConstantAlpha += 5;
		if (bf.SourceConstantAlpha >= 255) {
			fadeState = E_FADE_OUT;
			changeScene(currentSceneName);
		}
		break;
	case E_FADE_OUT:
		Rectangle(fade, 0, 0, 1024, 768);
		AlphaBlend(hDC, 0, 0, 1024, 768, fade, 0, 0, 1024, 768, bf);
		bf.SourceConstantAlpha -= 5;
		if (bf.SourceConstantAlpha <= 0) {
			fadeState = E_NONE;
			DeleteDC(fade);
		}
		break;
	}
}
Scene* SceneManager::getCurrentScene() {
	return pCurrent;
}