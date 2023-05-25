#pragma once
#include <vector>
#include <string>
#include "move_snake.h"
#include "raylib.h"
using namespace std;
class screen
{
public:

	screen();
	~screen();

	void Run();
	void Drawing();
private:

	void Load();
	void Unload();
	void Border();

	void Update(float deltaTime);
	void Draw();

	Color GetTileColor(int tileValue);

public:
	move_snake snake;
	int fps = 60;
	int fpsCounter = 0;
	int frameAmount = 21;
	int whiteBox = 0;
	int redBox = ROWS * COLS /2;
	int greenBox = redBox + COLS;
	int yellowBox = 0;
	int tempBox;
	const char* GameOver = nullptr;
	int GameCounter = -1;
	int Counter = 21;
	int body = Counter;

	bool yellow = false;
	bool GameEnd = false;

	int Key = 0;
	int Move = 0;

	int m_windowWidth = 810;
	int m_windowHeight = 810;
	int m_tileWidth = 30;
	int m_tileHeight = 30;

	static const int ROWS = 27;
	static const int COLS = 27;
	int m_tiles[ROWS * COLS];

	static const int ROWS2 = 6;
	int b_tiles[ROWS2];


};

