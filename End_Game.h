#pragma once
#include "storage.h"
#include "move_snake.h"
#include "raylib.h"
#include <vector>

class End_Game
{
public:
	move_snake MS;
	storage ST;

	void GameOver();
};

