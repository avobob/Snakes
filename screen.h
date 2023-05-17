#pragma once
#include <string>
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
	void Body();
	//void BodyColour();
	//void DrawPixel(int posX, int posY, string color);

	void Update(float deltaTime);
	void Draw();

	Color GetTileColor(int tileValue);

private:
	int fps = 60;
	int fpsCounter = 0;
	int frameAmount = 21;
	int TOD = 0;
	int whiteBox = 0;
	int greenBox = 391;
	int redBox = 364;
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

	static const int ROWS = 27;
	static const int COLS = 27;

	static const int ROWS2 = 21;
	static const int COLS2 = 1;

	int m_tiles[ROWS * COLS];

	int m_tileWidth = 30;
	int m_tileHeight = 30;

	int b_tiles[ROWS2 * COLS2];

};

