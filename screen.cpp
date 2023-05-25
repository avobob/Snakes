#include "screen.h"
#include "raylib.h"
#include <stdlib.h>
#include <random>
#include <iostream>

using namespace std;
screen::screen()
{

}

screen::~screen()
{

}

void screen::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "SNAKE");
	SetTargetFPS(fps);
	Load();
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
		if (fpsCounter == frameAmount)
		{
			fpsCounter = 0;
		}
	}
	Unload();
}
void screen::Border()
{
	for (int i = 0; i < COLS; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 0; i < COLS * ROWS; i += COLS)
	{
		m_tiles[i] = 4;
	}
	for (int i = COLS-1; i < COLS * ROWS; i += COLS)
	{
		m_tiles[i] = 4;
	}
	for (int i = COLS * ROWS - COLS; i < COLS * ROWS; i++)
	{
		m_tiles[i] = 4;
	}
}
void screen::Load()
{
	for (int i = 0; i < COLS * ROWS; i++)
	{
	m_tiles[i] = 0;
	}
	for (int i = 0; i < COLS * ROWS; i++)
	{
		m_tiles[redBox] = 1;
	}
}
void screen::Unload()
{
}
void screen::Update(float deltaTime)
{
	fpsCounter++;

	Border();
	{
	}
	for (int i = 0; i < COLS * ROWS; i++)
	{
		if (m_tiles[yellowBox] == 3)
		{
			break;
		}
		else
		{
			yellow = true;
			break;
		}
	}
	if (yellow) //Draws Fruit
	{
		yellow = false;
		random_device rd;
		mt19937 e{ rd() };
		uniform_int_distribution<int> distr{ COLS, COLS * ROWS - COLS };

		int n = distr(e);
		yellowBox = n;
		if (m_tiles[n] == 0)
		{
			m_tiles[n] = 3;
			Counter --;
			GameCounter++;
			frameAmount--;
		}
	}
	if (m_tiles[redBox] != 1)
	{
		GameOver = "GAME OVER!";
		GameEnd = true;
		Move = 0;
	}
	if(!GameEnd)
	{
		if (IsKeyPressed(KEY_A))
		{
			if (Move != 1)
			{
				Move = 4;
			}
		}
		if (IsKeyPressed(KEY_W))
		{
			if (Move != 2)
			{
				Move = 3;
			}
		}
		if (IsKeyPressed(KEY_S))
		{
			if (Move != 3)
			{
				Move = 2;
			}
		}
		if (IsKeyPressed(KEY_D))
		{
			if (Move != 4)
			{
				Move = 1;
			}
		}
	}
	if ((Move == 4) && (fpsCounter == frameAmount))//a
	{
		snake.DrawSnake(-1,redBox, greenBox, whiteBox, GameCounter, ROWS2, b_tiles, m_tiles);
	}
	if ((Move == 3) && (fpsCounter == frameAmount))//w
	{
		snake.DrawSnake(-COLS, redBox, greenBox, whiteBox, GameCounter, ROWS2, b_tiles, m_tiles);
	}
	if ((Move == 2) && (fpsCounter == frameAmount))//s
	{
		snake.DrawSnake(COLS, redBox, greenBox, whiteBox, GameCounter, ROWS2, b_tiles, m_tiles);
	}
	if ((Move == 1) && (fpsCounter == frameAmount))//d
	{
		snake.DrawSnake(1, redBox, greenBox, whiteBox, GameCounter, ROWS2, b_tiles, m_tiles);
	}
}
	void screen::Draw()
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
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
				if (GameOver)
				{
						int textWidth = MeasureText(GameOver, 100);
						DrawText(GameOver, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 + -100, 100, PURPLE);
				}
				DrawText(TextFormat("Score: %d", GameCounter), 10, 10, 20, PURPLE);
			}
		}
		EndDrawing();
	GameOver = nullptr;
	delete GameOver;
	}
Color screen::GetTileColor(int tileValue)
{
	switch (tileValue)
	{
	case 0:	return WHITE;
	case 1: return RED;
	case 2: return GREEN;
	case 3: return YELLOW;
	case 4: return BLACK;
	}
}