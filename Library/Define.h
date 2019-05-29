#pragma once

#include "World.h"
#include "SceneManager.h"
#include "Input.h"
#include "SoundManager.h"
#define D_WORLD		World::instance()
#define D_SCENE		SceneManager::instance()
#define D_INPUT		Input::instance()
#define D_SOUND		SoundManager::instance()