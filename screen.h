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
	const char* GameOver = nullptr;
	int GameCounter = -1;
	int Counter = 0;
	int body = Counter;

	int box21 = 0;
	int box20 = 0;
	int box19 = 0;
	int box18 = 0;
	int box17 = 0;
	int box16 = 0;
	int box15 = 0;
	int box14 = 0;
	int box13 = 0;
	int box12 = 0;
	int box11 = 0;
	int box10 = 0;
	int box9 = 0;
	int box8 = 0;
	int box7 = 0;
	int box6 = 0;
	int box5 = 0;
	int box4 = 0;
	int box3 = 0;
	int box2 = 0;
	int box1 = 0;

	bool yellow = false;

	int Key = 0;
	int Move = 0;

	int m_windowWidth = 810;
	int m_windowHeight = 810;

	static const int ROWS = 27;
	static const int COLS = 27;

	int m_tiles[ROWS * COLS];

	int m_tileWidth = 30;
	int m_tileHeight = 30;

	static const int ROWS2 = 21;
	int b_tiles[ROWS2];

};

