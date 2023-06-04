#include "yellow_box.h"
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
<<<<<<< HEAD
void screen::Border(){
	for (int i = 0; i < ST.COLS; i++)ST.m_tiles[i] = 4;
	for (int i = 0; i < ST.COLS * ST.ROWS; i += ST.COLS)ST.m_tiles[i] = 4;
	for (int i = ST.COLS-1; i < ST.COLS * ST.ROWS; i += ST.COLS)ST.m_tiles[i] = 4;
	for (int i = ST.COLS * ST.ROWS - ST.COLS; i < ST.COLS * ST.ROWS; i++)ST.m_tiles[i] = 4;
}
void screen::Load(){
	for (int i = 0; i < ST.COLS * ST.ROWS; i++)ST.m_tiles[i] = 0;
	for (int i = 0; i < ST.COLS * ST.ROWS; i++)ST.m_tiles[ST.redBox] = 1;
=======

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
>>>>>>> parent of 6d91a21... simplify
}
void screen::Unload()
{
}
<<<<<<< HEAD
void screen::Update(float deltaTime){
	ST.fpsCounter++;
	Border();{
	}
	yellow.Summon();{
	}
	
	if (ST.m_tiles[ST.redBox] != 1){
		ST.GameOver = "GAME OVER!";
		ST.GameEnd = true;
		ST.Move = 0;
	}
	if(!ST.GameEnd){
		if (IsKeyPressed(KEY_A) && ST.Move != 1)ST.Move = 4;
		if (IsKeyPressed(KEY_W) && ST.Move != 2)ST.Move = 3;
		if (IsKeyPressed(KEY_S) && ST.Move != 3)ST.Move = 2;
		if (IsKeyPressed(KEY_D) && ST.Move != 4)ST.Move = 1;
	}
	if ((ST.Move == 4) && (ST.fpsCounter == ST.frameAmount))snake.DrawSnake(-1);//a
	if ((ST.Move == 3) && (ST.fpsCounter == ST.frameAmount))snake.DrawSnake(-ST.COLS);//w
	if ((ST.Move == 2) && (ST.fpsCounter == ST.frameAmount))snake.DrawSnake(ST.COLS);//s
	if ((ST.Move == 1) && (ST.fpsCounter == ST.frameAmount))snake.DrawSnake(1);//d

	if (ST.fpsCounter == ST.frameAmount)ST.fpsCounter = 0;
=======
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
>>>>>>> parent of 6d91a21... simplify
}
	void screen::Draw()
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
<<<<<<< HEAD
		for (int ROWINDEX = 0; ROWINDEX < ST.ROWS; ROWINDEX++){
			for (int COLINDEX = 0; COLINDEX < ST.COLS; COLINDEX++){
				float xPos = COLINDEX * ST.m_tileWidth;
				float yPos = ROWINDEX * ST.m_tileHeight;
				int INDEX = ROWINDEX * ST.COLS + COLINDEX;
				int tilevalue = ST.m_tiles[INDEX];
				Color color = ST.GetTileColor(tilevalue); // pass in the tilevalue
				DrawRectangle(xPos, yPos, ST.m_tileWidth, ST.m_tileHeight, color);
				if (ST.GameOver){
						int textWidth = MeasureText(ST.GameOver, 100);
						DrawText(ST.GameOver, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 + -100, 100, PURPLE);
=======
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
>>>>>>> parent of 6d91a21... simplify
				}
				DrawText(TextFormat("Score: %d", ST.GameCounter), 10, 10, 20, PURPLE);
			}
		}
		EndDrawing();
<<<<<<< HEAD
		ST.GameOver = nullptr;
	delete ST.GameOver;
=======
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
>>>>>>> parent of 6d91a21... simplify
	}
//Color screen::GetTileColor(int tileValue){
//	switch (tileValue){
//	case 0:	return WHITE;
//	case 1: return RED;
//	case 2: return GREEN;
//	case 3: return YELLOW;
//	case 4: return BLACK;
//	}
//}