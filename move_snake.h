#pragma once
#include "storage.h"
#include <vector>
#include "raylib.h"

class move_snake{
	public:
	storage ST;
	void DrawSnake(int num);
	int red = -ST.redBox - 11;
	//int red = ST.COLS * ST.ROWS / 2;
	private:
};


