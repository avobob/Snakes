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

private:

	void Load();
	void Unload();
	void DrawPixel(int posX, int posY, int r, int g, int b, int a);
	//void DrawPixel(int posX, int posY, string color);

	void Update(float deltaTime);
	void Draw();

	Color GetTileColor(int tileValue);

private:

	int m_windowWidth = 800;
	int m_windowHeight = 800;

	static const int ROWS = 25;
	static const int COLS = 25;

	int m_tiles[ROWS * COLS];

	int m_tileWidth = 32;
	int m_tileHeight = 32;
};

