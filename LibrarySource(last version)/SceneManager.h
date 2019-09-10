#pragma once
#include <map>
#include "Scene.h"

//�⺻������ map���� ��� Scene�� ������
//��� ���� init�� ���ÿ� ������, �׷��Ƿ� lazy initial �� ���� ���� 
class SceneManager {
public:
	static inline SceneManager* instance() {
		static SceneManager instance_;
		return &instance_;
	}
	void commit(const std::string& name, Scene* scene);
	void changeScene(const std::string& name);
/*
	*@brief : ���� �����ϴµ�, Fade ȿ���� �ݴϴ�.
	@Args : double x : ���� �� ������� �ɸ��� �ð�
	@Expetion : nothrow, ������
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
	Scene* pCurrent;	// ���� ��

	//���̵忡 ���õ�
	HDC fade;
	HBITMAP fadebit;
	BLENDFUNCTION bf;
};