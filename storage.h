#pragma once
#include "raylib.h"
class storage
{
public:
	Color GetTileColor(int tileValue);
	int fps = 60;
	int fpsCounter = 0;
	int whiteBox = 0;
	int redBox = ROWS * COLS / 2;
	//int redBox = 281;
	int greenBox = redBox + COLS;
	int frameAmount = 21;
	int GameCounter = 0;
	int Counter = 21;
	int Move = 0;

	bool GameEnd = false;

	const char* GameOver = nullptr;

	int m_windowWidth = 810;
	int m_windowHeight = 810;
	int m_tileWidth = 30;
	int m_tileHeight = 30;

	static const int ROWS = 27;
	static const int COLS = 27;
	static const int ROWS2 = 21;

	int m_tiles[ROWS * COLS];
	int b_tiles[ROWS2];
};

