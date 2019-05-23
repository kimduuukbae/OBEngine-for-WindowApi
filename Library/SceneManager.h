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
	*@brief : ���� �����ϴµ�, Fade ȿ���� �ݴϴ�.
	@Args : double x : ���� �� ������� �ɸ��� �ð�
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
	Scene* pCurrent;	// ���� ��

	//���̵忡 ���õ�
	HDC fade;
	HBITMAP fadebit;
	BLENDFUNCTION bf;
	HBRUSH fadeBrush, oldBrush;
	OBString* currentSceneName;

	int windowX, windowY;

};