#include "yellow_box.h"
#include "screen.h"
#include "raylib.h"
#include <stdlib.h>
#include <random>
#include <iostream>

using namespace std;
screen::screen(){
}
screen::~screen(){
}
void screen::Border(){
	for (int i = 0; i < ST.COLS; i++)ST.m_tiles[i] = 4;
	for (int i = 0; i < ST.COLS * ST.ROWS; i += ST.COLS)ST.m_tiles[i] = 4;
	for (int i = ST.COLS-1; i < ST.COLS * ST.ROWS; i += ST.COLS)ST.m_tiles[i] = 4;
	for (int i = ST.COLS * ST.ROWS - ST.COLS; i < ST.COLS * ST.ROWS; i++)ST.m_tiles[i] = 4;
}
void screen::Load(){
	for (int i = 0; i < ST.COLS * ST.ROWS; i++)ST.m_tiles[i] = 0;
	for (int i = 0; i < ST.COLS * ST.ROWS; i++)ST.m_tiles[ST.redBox] = 1;
}
void screen::Unload(){
}
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
}
	void screen::Draw(){
		BeginDrawing();
		ClearBackground(RAYWHITE);
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
				}
				DrawText(TextFormat("Score: %d", ST.GameCounter), 10, 10, 20, PURPLE);
			}
		}
		EndDrawing();
		ST.GameOver = nullptr;
	delete ST.GameOver;
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