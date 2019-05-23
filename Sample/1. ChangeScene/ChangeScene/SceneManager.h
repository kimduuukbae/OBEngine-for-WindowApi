#pragma once
#include <vector>

class Scene;
class OBString;
struct SceneState {
	Scene* scene;
	OBString* name;
};

class SceneManager {
public:
	static SceneManager* instance();
	void commit(const char* name, Scene* scene);
	void changeScene(const char* name);
/*
	*@brief : 씬을 변경하는데, Fade 효과를 줍니다.
	@Args : double x : 다음 씬 변경까지 걸리는 시간
*/
	void changeSceneFade(const char* name);

	void update(float dt);
	void draw(HDC hDC);

	Scene* getCurrentScene();

private:
	
	enum E_FADE_STATE {
		E_NONE,
		E_FADE_IN,
		E_FADE_OUT
	}fadeState = E_NONE;

	~SceneManager();
	SceneManager();


	std::vector<SceneState> AllScene;
	Scene* pCurrent;	// 현재 씬

	//페이드에 관련된
	HDC fade;
	HBITMAP fadebit;
	BLENDFUNCTION bf;
	HBRUSH fadeBrush, oldBrush;
	OBString* currentSceneName;

	int windowX, windowY;

};