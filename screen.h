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

