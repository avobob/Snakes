#include "screen.h"
#include "raylib.h"
#include <stdlib.h>
#include <random>
#include <iostream>

using namespace std;
int whiteBox = 362;
int greenBox = 337;
int redBox = 312;
int keyA = true;
int keyW = true;
int keyS = false;
int keyD = true;
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
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}
	//Drawing();
	Unload();
}
//void screen::Drawing()
//{
//	while (!WindowShouldClose())
//	{
//		BeginDrawing();
//		ClearBackground(RAYWHITE);
//
//		DrawPixel(12,12,RED);
//
//		EndDrawing();
//	}
//}

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
		m_tiles[redBox] = 1;
	}
	for (int i = 0; i < 625; i++)
	{
		m_tiles[greenBox] = 2;
	}
	//for (int i = 0; i < 625; i++)
	//{
	//	m_tiles[whiteBox] = 3;
	//}
	// -----------------------------------------------------
}

//void screen::DrawPixel()
//{
//	int posX = 12;
//	int posY = 12;
//
//}
void screen::Unload()
{

}

void screen::Update(float deltaTime)
{
	int IsPressedA = false;
	int IsPressedW = false;
	int IsPressedS = false;
	int IsPressedD = false;
	/*if (IsKeyPressed(KEY_A)||(IsKeyPressed(KEY_W))||(IsKeyPressed(KEY_S))||(IsKeyPressed(KEY_D)))
	{
		IsPressed = true;
	}*/
	if (IsKeyPressed(KEY_A))
	{
		if (keyA)
		{
			keyA = true;
			keyW = true;
			keyS = true;
			keyD = false;
		IsPressedA = true;
		cout << keyA << endl;
		cout << keyW << endl;
		cout << keyS << endl;
		cout << keyD << endl;
		}
	}
	if (IsKeyPressed(KEY_W)) 
	{
		if (keyW)
		{
			keyA = true;
			keyW = true;
			keyS = false;
			keyD = true;
			IsPressedW = true;
			cout << keyA << endl;
			cout << keyW << endl;
			cout << keyS << endl;
			cout << keyD << endl;
		}
	}
	if (IsKeyPressed(KEY_S)) 
	{
		if (keyS)
		{
			keyA = true;
			keyW = false;
			keyS = true;
			keyD = true;
			IsPressedS = true;
			cout << keyA << endl;
			cout << keyW << endl;
			cout << keyS << endl;
			cout << keyD << endl;
		}
	}
	if (IsKeyPressed(KEY_D)) 
	{
		if (keyD)
		{
			keyA = false;
			keyW = true;
			keyS = true;
			keyD = true;
			IsPressedD = true;
			cout << keyA << endl;
			cout << keyW << endl;
			cout << keyS << endl;
			cout << keyD << endl;
		}
	}
	if (IsPressedA)
	{
		//Vector2 headPos = GetMousePosition();
		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon
		for (int i = 0; i < 625; i++)
		{
			if (m_tiles[i] == 1)
			{
				m_tiles[redBox] = 2;
				whiteBox = greenBox;
				greenBox = redBox;
				redBox -= 1;
				m_tiles[redBox] = 1;
				m_tiles[greenBox] = 2;
				m_tiles[whiteBox] = 0;

				int headPosX = redBox;
				int headPosY = redBox;
		int rowIndex = headPosY;
		int colIndex = headPosX;

		// TODO: calculate the index of the tile clicked on based on the row/col index
		int tileIndex = rowIndex * COLS + colIndex;
		//std::cout << tileIndex << "-------------------------------------" << std::endl;

		////m_tiles[tileIndex] += 1;
		//if (m_tiles[tileIndex] >= 5)
		//	m_tiles[tileIndex] = 0;
		IsPressedA = false;
			}
		}
	}
	if (IsPressedW)
	{
		//Vector2 headPos = GetMousePosition();
		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon
		for (int i = 0; i < 625; i++)
		{
			if (m_tiles[i] == 1)
			{
				m_tiles[redBox] = 2;
				whiteBox = greenBox;
				greenBox = redBox;
				redBox -= 25;
				m_tiles[redBox] = 1;
				m_tiles[greenBox] = 2;
				m_tiles[whiteBox] = 0;

				int headPosX = redBox;
				int headPosY = redBox;
				int rowIndex = headPosY;
				int colIndex = headPosX;

				// TODO: calculate the index of the tile clicked on based on the row/col index
				int tileIndex = rowIndex * COLS + colIndex;
				//std::cout << tileIndex << "-------------------------------------" << std::endl;

				////m_tiles[tileIndex] += 1;
				//if (m_tiles[tileIndex] >= 5)
				//	m_tiles[tileIndex] = 0;
				IsPressedW = false;
			}
		}
	}
	if (IsPressedS)
	{
		//Vector2 headPos = GetMousePosition();
		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon
		for (int i = 625; i > 0; i--)
		{
			if (m_tiles[i] == 1)
			{
				m_tiles[redBox] = 2;
				whiteBox = greenBox;
				greenBox = redBox;
				redBox += 25;
				m_tiles[redBox] = 1;
				m_tiles[greenBox] = 2;
				m_tiles[whiteBox] = 0;

				int headPosX = redBox;
				int headPosY = redBox;
				int rowIndex = headPosY;
				int colIndex = headPosX;

				// TODO: calculate the index of the tile clicked on based on the row/col index
				int tileIndex = rowIndex * COLS + colIndex;
				//std::cout << tileIndex << "-------------------------------------" << std::endl;

				////m_tiles[tileIndex] += 1;
				//if (m_tiles[tileIndex] >= 5)
				//	m_tiles[tileIndex] = 0;
				IsPressedS = false;
			}
		}
	}
	if (IsPressedD)
	{
		//Vector2 headPos = GetMousePosition();
		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon
		for (int i = 625; i > 0; i--)
		{
			if (m_tiles[i] == 1)
			{
				m_tiles[redBox] = 2;
				whiteBox = greenBox;
				greenBox = redBox;
				redBox += 1;
				m_tiles[redBox] = 1;
				m_tiles[greenBox] = 2;
				m_tiles[whiteBox] = 0;

				int headPosX = redBox;
				int headPosY = redBox;
				int rowIndex = headPosY;
				int colIndex = headPosX;

				// TODO: calculate the index of the tile clicked on based on the row/col index
				int tileIndex = rowIndex * COLS + colIndex;
				//std::cout << tileIndex << "-------------------------------------" << std::endl;

				////m_tiles[tileIndex] += 1;
				//if (m_tiles[tileIndex] >= 5)
				//	m_tiles[tileIndex] = 0;
				IsPressedD = false;
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
	case 3: return YELLOW;
	}
}