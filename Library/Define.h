#pragma once
/*
	Define.H
*/
#include "World.h"
#include "SceneManager.h"
#include "Input.h"
#include "SoundManager.h"
#include "Camera.h"

#define D_WORLD		World::instance()
#define D_SCENE		SceneManager::instance()
#define D_INPUT		Input::instance()
#define D_SOUND		SoundManager::instance()
#define D_CAMERA	Camera::instance()

enum E_SOUNDTYPE {
	E_LOGO,	// Logo Scene ���� ���� Sound
	E_GAME,	// Game Scene ���� ���� Sound
	E_HITSOUND,	// Game Scene ���� �������� ������ ���� �� Sound
	E_DAMAGESOUND,	// Game Scene���� �������� ������ �޾��� �� Sound
};

