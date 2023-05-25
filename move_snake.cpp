#include "move_snake.h"
#include "screen.h"
#include "GreenBoxes.h"
#include "raylib.h"
#include <stdlib.h>
#include <random>
#include <iostream>
using namespace std;

void move_snake::DrawSnake(int num, int& redBox, int& greenBox, int& whiteBox, int& GameCounter, int ROWS2, int b_tiles[], int m_tiles[])
{
	for (int i = ROWS2; i >= 0; i--)
	{
		b_tiles[i] = b_tiles[i - 1];
	}
	b_tiles[0] = greenBox;
	greenBox = redBox;
	redBox += num;
	if (GameCounter < ROWS2)
	{
		m_tiles[redBox] = 1;
		m_tiles[greenBox] = 2;
		for (int i = 0; i < GameCounter; i++)
		{
			m_tiles[b_tiles[i]] = 2;
		}
		m_tiles[b_tiles[GameCounter]] = 0;
	}
}