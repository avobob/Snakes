#include "move_snake.h"
#include "raylib.h"
#include <stdlib.h>
#include <random>
#include <iostream>
void move_snake::DrawSnake(int num){
	for (int i = 20; i >= 1; i--){
		ST.b_tiles[i] = ST.b_tiles[i - 1];
	}
	ST.b_tiles[0] = ST.greenBox;
	ST.greenBox = red;
	red += num;

	if (ST.GameCounter < ST.ROWS2){
		ST.m_tiles[red] = 1;
		ST.m_tiles[ST.greenBox] = 2;
		for (int i = 0; i < ST.GameCounter; i++)ST.m_tiles[ST.b_tiles[i]] = 2;
		ST.m_tiles[ST.b_tiles[ST.GameCounter]] = 0;
	}
}