#pragma once

#include "raylib.h"

class screen
{
public:

	screen();
	~screen();

	void Run();

private:

	void Load();
	void Unload();
	void DrawPixel(int posX, int posY, Color color);

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

