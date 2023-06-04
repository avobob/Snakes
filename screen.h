#pragma once
#include <vector>
#include <string>
#include "move_snake.h"
#include "yellow_box.h"
#include "raylib.h"
using namespace std;
class screen
{
public:

	screen();
	~screen();
	void Load();
	void Unload();
	void Border();
	void Update(float deltaTime);
	void Draw();
	//Color GetTileColor(int tileValue);

public:
	storage ST;
	move_snake snake;
	yellow_box yellow;
};

