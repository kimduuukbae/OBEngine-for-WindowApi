#pragma once
#include <map>
#include "Scene.h"

//기본적으로 map으로 모든 Scene을 관리함
//모든 씬은 init과 동시에 관리됨, 그러므로 lazy initial 을 하지 않음 
class SceneManager {
public:
	static inline SceneManager* instance() {
		static SceneManager instance_;
		return &instance_;
	}
	void commit(const std::string& name, Scene* scene);
	void changeScene(const std::string& name);
/*
	*@brief : 씬을 변경하는데, Fade 효과를 줍니다.
	@Args : double x : 다음 씬 변경까지 걸리는 시간
	@Expetion : nothrow, 제작중
*/
	void changeSceneFade(const std::string& name);

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
	SceneManager() = default;


	std::map<std::string, Scene*> AllScene;
	std::string currentSceneName;
	Scene* pCurrent;	// 현재 씬

	//페이드에 관련된
	HDC fade;
	HBITMAP fadebit;
	BLENDFUNCTION bf;
};