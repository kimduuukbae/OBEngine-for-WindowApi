#pragma once
#include <windows.h>

#include "sceneLogo.h"
#include "SceneGame.h"
#include "vector.h"
#include "SceneManager.h"
#include "World.h"
#include "Input.h"
#include "Sprite.h"


#define D_SCENE		SceneManager::instance()
#define D_WORLD		World::instance()
#define D_INPUT		Input::instance()