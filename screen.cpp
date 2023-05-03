#include "screen.h"
#include "raylib.h"
#include <stdlib.h>
#include <random>

//test test 1
//test test 1
//test test 1
//test test 1
//test test 1
//test test 1
//test test 1
screen::screen()
{

}

screen::~screen()
{

}

void screen::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Simple Tilemap");
	SetTargetFPS(60);
	Load();
	DrawPixel(0,0,0,0,0,0);
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}

	Unload();
}
void screen::DrawPixel(int posX, int posY, int r, int g, int b, int a)
{
	posX = 12;
	posY = 12;
	r = 200;
	g = 122;
	b = 255;
	a = 255;
}

void screen::Load()
{
	// Task1:
	// Initialise all values in m_tiles array to a random
	// value between 0 and 5 exclusive;
	// -----------------------------------------------------

	// write your code here
	//std::random_device rd;
	//std::mt19937 e{ rd() }; // or std::default_random_engine e{rd()};
	//std::uniform_int_distribution<int> distr{ 0, 0 };
	//for (int i = 0; i < 625; i++)
	//{
	//	m_tiles[i] = distr(e);
	//}
	for (int i = 0; i < 625; i++) 
	{
	m_tiles[i] = 0;
	}
	for (int i = 0; i < 625; i++)
	{
		m_tiles[312] = 1;
	}
	// -----------------------------------------------------
}

void screen::Unload()
{

}

void screen::Update(float deltaTime)
{
	int IsPressed = false;
	if (IsKeyPressed(KEY_A)||(IsKeyPressed(KEY_W))||(IsKeyPressed(KEY_S))||(IsKeyPressed(KEY_D)))
	{
		IsPressed = true;
	}
	/*if (IsKeyPressed(KEY_A))
	{
		IsPressed = true;
	}
	if (IsKeyPressed(KEY_W)) 
	{
		IsPressed = true;
	}
	if (IsKeyPressed(KEY_S)) 
	{
		IsPressed = true;
	}
	if (IsKeyPressed(KEY_D)) 
	{
		IsPressed = true;
	}*/
	if (IsPressed)
	{
		//Vector2 headPos = GetMousePosition();
		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon
		for (int i = 0; i < 625; i++)
		{
			if (m_tiles[i] == 1)
			{
				int headPos
		int rowIndex = headPos.y / m_tileHeight;
		int colIndex = headPos.x / m_tileWidth;

		// TODO: calculate the index of the tile clicked on based on the row/col index
		int tileIndex = rowIndex * COLS + colIndex;

		m_tiles[tileIndex] += 1;
		if (m_tiles[tileIndex] >= 3)
			m_tiles[tileIndex] = 0;
		IsPressed = false;
		//test
			}
		}
	}
}

void screen::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	// Task2:
	// use a nested loop to iterate over rows and columns
	// Use raylib's DrawRect method to draw each tile in the array.
	// 	   use the row and col index multipled by m_tileHeight/m_tileWidth
	// 	   to calculate the x and y position for each rectangle.
	// 
	// change the color of the rect drawn based on the value of the tile.
	// 	   We have created a helper function you can use "GetTileColor"
	// --------------------------------------------------------------------
	// write your code here
	for (int ROWINDEX = 0; ROWINDEX < ROWS; ROWINDEX++)
	{
		for (int COLINDEX = 0; COLINDEX < COLS; COLINDEX++)
		{
			float xPos = COLINDEX * m_tileWidth;
			float yPos = ROWINDEX * m_tileHeight;
			int INDEX = ROWINDEX * COLS + COLINDEX;
			int tilevalue = m_tiles[INDEX];
			Color color = GetTileColor(tilevalue); // pass in the tilevalue

			DrawRectangle(xPos, yPos, m_tileWidth, m_tileHeight, color);
		}
	}

	// --------------------------------------------------------------------

	EndDrawing();
}

Color screen::GetTileColor(int tileValue)
{
	switch (tileValue)
	{
	case 0:	return WHITE;
	case 1: return RED;
	case 2: return GREEN;
	}
}