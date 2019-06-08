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
	E_LOGO,	// Logo Scene 에서 사용될 Sound
	E_GAME,	// Game Scene 에서 사용될 Sound
	E_HITSOUND,	// Game Scene 에서 누군가가 공격을 했을 때 Sound
	E_DAMAGESOUND,	// Game Scene에서 누군가가 공격을 받았을 때 Sound
};

