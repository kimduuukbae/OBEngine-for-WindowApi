#include "stdafx.h"
#include "Scene.h"
#include "World.h"
#include "SceneManager.h"
#include "OBString.h"
#include "Camera.h"

 SceneManager::SceneManager(){
	 fadeBrush = CreateSolidBrush(RGB(0, 0, 0));
	 cameraWorld = Camera::instance();
	 currentSceneName = new OBString("NULL");
	 windowX = World::instance()->getWindowX();
	 windowY = World::instance()->getWindowY();
}
SceneManager::~SceneManager() {
	DeleteObject(fadeBrush);
	delete currentSceneName;
}

void SceneManager::commit(const char* name, Scene * scene){
	AllScene.push_back(SceneState{ scene, new OBString(name) });

}

void SceneManager::changeScene(const char* name){
	if (pCurrent != nullptr)
		pCurrent->destroy();
	for (size_t i = 0; i < AllScene.size(); ++i) {
		if (*AllScene[i].name == name) {
			currentSceneName->setString(name);
			pCurrent = AllScene[i].scene;
			break;
		}
	}
	pCurrent->init();
}

void SceneManager::changeSceneFade(const char* name) {
	currentSceneName->setString(name);
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
	if (fadeState != E_NONE) {
		if (fade == NULL) {
			fade = CreateCompatibleDC(hDC);
			fadebit = CreateCompatibleBitmap(hDC, cameraWorld->getWorldX(), cameraWorld->getWorldY());
			SelectObject(fade, fadebit);
			DeleteObject(fadebit);
		}
		oldBrush = (HBRUSH)SelectObject(fade, fadeBrush);
		Rectangle(fade, 0, 0, windowX, windowY);
		SelectObject(fade, oldBrush);
		AlphaBlend(hDC, 0, 0, windowX + cameraWorld->currentCameraX(), windowY + cameraWorld->currentCameraY(), fade,
			0, 0, windowX, windowY, bf);
		if (fadeState == E_FADE_IN) {
			bf.SourceConstantAlpha += 5;
			if (bf.SourceConstantAlpha >= 255) {
				fadeState = E_FADE_OUT;
				changeScene(currentSceneName->getString());
			}
		}
		else {
			bf.SourceConstantAlpha -= 5;
			if (bf.SourceConstantAlpha <= 1) {
				fadeState = E_NONE;
				DeleteDC(fade);
				fade = nullptr;
			}
		}
	}
}
Scene* SceneManager::getCurrentScene() {
	return pCurrent;
}
SceneManager* instance_{ nullptr };
SceneManager* SceneManager::instance() {
	if (instance_ == nullptr)
		instance_ = new SceneManager();

	return instance_;
}