#include "screen.h"
#include "GreenBoxes.h"
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
		fpsCounter ++;
		Update(GetFrameTime());
		Draw();
		if (fpsCounter == frameAmount)
		{
			fpsCounter = 0;
		}
	}
	Unload();
}

void screen::Body()
{

}
void screen::Border()
{
	for (int i = 0; i < 28; i++)
	{
		m_tiles[i] = 4;
	}

	m_tiles[53] = 4;
	m_tiles[54] = 4;
	m_tiles[80] = 4;
	m_tiles[81] = 4;
	m_tiles[107] = 4;
	m_tiles[108] = 4;
	m_tiles[134] = 4;
	m_tiles[135] = 4;
	m_tiles[161] = 4;
	m_tiles[162] = 4;
	m_tiles[188] = 4;
	m_tiles[189] = 4;
	m_tiles[215] = 4;
	m_tiles[216] = 4;
	m_tiles[242] = 4;
	m_tiles[243] = 4;
	m_tiles[269] = 4;
	m_tiles[270] = 4;
	m_tiles[296] = 4;
	m_tiles[297] = 4;
	m_tiles[323] = 4;
	m_tiles[324] = 4;
	m_tiles[350] = 4;
	m_tiles[351] = 4;
	m_tiles[377] = 4;
	m_tiles[378] = 4;
	m_tiles[404] = 4;
	m_tiles[405] = 4;
	m_tiles[431] = 4;
	m_tiles[432] = 4;
	m_tiles[458] = 4;
	m_tiles[459] = 4;
	m_tiles[485] = 4;
	m_tiles[486] = 4;
	m_tiles[512] = 4;
	m_tiles[513] = 4;
	m_tiles[539] = 4;
	m_tiles[540] = 4;
	m_tiles[566] = 4;
	m_tiles[567] = 4;
	m_tiles[593] = 4;
	m_tiles[594] = 4;
	m_tiles[620] = 4;
	m_tiles[621] = 4;
	m_tiles[647] = 4;
	m_tiles[648] = 4;
	m_tiles[674] = 4;
	m_tiles[675] = 4;
	for (int i = 701; i < 729; i++)
	{
		m_tiles[i] = 4;
	}
}
void screen::Load()
{
	cout << Key << "-------------------------------" << endl;

	for (int i = 0; i < 729; i++)
	{
	m_tiles[i] = 0;
	}
	for (int i = 0; i < 729; i++)
	{
		m_tiles[redBox] = 1;
	}

	for (int i = 0; i < 21; i++)
	{
		b_tiles[whiteBox] = 2;
	}
	Body();
}
void screen::Unload()
{
}
void screen::Update(float deltaTime)
{
	TOD++;
	Border();
	{
	}
	for (int i = 0; i < 729; i++)
	{
		if (m_tiles[yellowBox] == 3)
		{
			break;
		}
		else
		{
			cout << "-----hello-------" << endl;
			yellow = true;
			break;
		}
	}
	if (yellow)
	{
		yellow = false;
		random_device rd;
		mt19937 e{ rd() };
		uniform_int_distribution<int> distr{ 28, 701 };
		cout << distr(e) << "------------" << endl;

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
	if (m_tiles[redBox] == 4)
	{
		GameOver = "GAME OVER!";
		GameEnd = true;
		Move = 0;
	}
	else if (m_tiles[redBox] == 2)
	{
		GameOver = "GAME OVER!";
		GameEnd = true;
		Move = 0;
	}
	if(!GameEnd)
	{
		if (IsKeyPressed(KEY_A))
		{
			if (Key != 1 && TOD > frameAmount)
			{
				Move = 4;
				Key = 4;
				TOD = 0;
			}
		}
		if (IsKeyPressed(KEY_W))
		{
			if (Key != 2 && TOD > frameAmount)
			{
				Move = 3;
				Key = 3;
				TOD = 0;
			}
		}
		if (IsKeyPressed(KEY_S))
		{
			if (Key != 3 && TOD > frameAmount)
			{
				Move = 2;
				Key = 2;
				TOD = 0;
			}
		}
		if (IsKeyPressed(KEY_D))
		{
			if (Key != 4 && TOD > frameAmount)
			{
				Move = 1;
				Key = 1;
				TOD = 0;
			}
		}
	}
	if ((Move == 4) && (fpsCounter == frameAmount))
	{
		//int i = 21; i > Counter; i--;
		m_tiles[redBox] = 2;
		whiteBox = b_tiles[0];
		b_tiles[0] = b_tiles[1];
		b_tiles[1] = b_tiles[2];
		b_tiles[2] = b_tiles[3];
		b_tiles[3] = b_tiles[4];
		b_tiles[4] = b_tiles[5];
		b_tiles[5] = b_tiles[6];
		b_tiles[6] = b_tiles[7];
		b_tiles[7] = b_tiles[8];
		b_tiles[8] = b_tiles[9];
		b_tiles[9] = b_tiles[10];
		b_tiles[10] = b_tiles[11];
		b_tiles[11] = b_tiles[12];
		b_tiles[12] = b_tiles[13];
		b_tiles[13] = b_tiles[14];
		b_tiles[14] = b_tiles[15];
		b_tiles[15] = b_tiles[16];
		b_tiles[16] = b_tiles[17];
		b_tiles[17] = b_tiles[18];
		b_tiles[18] = b_tiles[19];
		b_tiles[19] = b_tiles[20];
		b_tiles[20] = greenBox;
		greenBox = redBox;
		redBox -= 1;
		//if (Counter > 0)
		//{
		//	m_tiles[redBox] = 1;
		//	m_tiles[greenBox] = 2;
		//	m_tiles[b_tiles[i]] = 2;
		//	m_tiles[b_tiles[Counter]] = 0;
		//}
		if (Counter > 0)
		{
			m_tiles[redBox] = 1;
			m_tiles[greenBox] = 2;
			for (int i = 20; i >= Counter; i--) 
			{
				m_tiles[b_tiles[i]] = 2;
			}
			m_tiles[b_tiles[Counter]] = 0;
		}
		fpsCounter = 0;
	}
	/*if (Move == 4 && fpsCounter == frameAmount)
	{
		for (int i = 0; i < 729; i++)
		{
			if (m_tiles[i] == 1)
			{
				m_tiles[redBox] = 2;
				whiteBox = box1; box1 = box2; box2 = box3; box3 = box4; box4 = box5; box5 = box6; box6 = box7; box7 = box8; box8 = box9; box9 = box10; box10 = box11; box11 = box12; box12 = box13; box13 = box14; box14 = box15; box15 = box16; box16 = box17; box17 = box18; box18 = box19; box19 = box20; box20 = box21; box21 = greenBox; greenBox = redBox;
				redBox -= 1;
				m_tiles[redBox] = 1;
				if (Counter > 0)m_tiles[greenBox] = 5; m_tiles[box21] = 0;
				if (Counter > 1)m_tiles[box21] = 2, m_tiles[box20] = 0;
				if (Counter > 2)m_tiles[box20] = 5, m_tiles[box19] = 0;
				if (Counter > 3)m_tiles[box19] = 2, m_tiles[box18] = 0;
				if (Counter > 4)m_tiles[box18] = 5, m_tiles[box17] = 0;
				if (Counter > 5)m_tiles[box17] = 2, m_tiles[box16] = 0;
				if (Counter > 6)m_tiles[box16] = 5, m_tiles[box15] = 0;
				if (Counter > 7)m_tiles[box15] = 2, m_tiles[box14] = 0;
				if (Counter > 8)m_tiles[box14] = 5, m_tiles[box13] = 0;
				if (Counter > 9)m_tiles[box13] = 2, m_tiles[box12] = 0;
				if (Counter > 10)m_tiles[box12] = 5, m_tiles[box11] = 0;
				if (Counter > 11)m_tiles[box11] = 2, m_tiles[box10] = 0;
				if (Counter > 12)m_tiles[box10] = 5, m_tiles[box9] = 0;
				if (Counter > 13)m_tiles[box9] = 2, m_tiles[box8] = 0;
				if (Counter > 14)m_tiles[box8] = 5, m_tiles[box7] = 0;
				if (Counter > 15)m_tiles[box7] = 2, m_tiles[box6] = 0;
				if (Counter > 16)m_tiles[box6] = 5, m_tiles[box5] = 0;
				if (Counter > 17)m_tiles[box5] = 2, m_tiles[box4] = 0;
				if (Counter > 18)m_tiles[box4] = 5, m_tiles[box3] = 0;
				if (Counter > 19)m_tiles[box3] = 2, m_tiles[box2] = 0;
				if (Counter > 20)m_tiles[box2] = 5, m_tiles[box1] = 0;
				if (Counter > 21)m_tiles[box1] = 2, m_tiles[whiteBox] = 0;
			}
		}
		fpsCounter = 0;
	}*/
	if ((Move == 3) && (fpsCounter == frameAmount))
	{
		int i = 21; i > Counter; i--;
		m_tiles[redBox] = 2;
		whiteBox = b_tiles[1];
		b_tiles[1] = b_tiles[2];
		b_tiles[2] = b_tiles[3];
		b_tiles[3] = b_tiles[4];
		b_tiles[4] = b_tiles[5];
		b_tiles[5] = b_tiles[6];
		b_tiles[6] = b_tiles[7];
		b_tiles[7] = b_tiles[8];
		b_tiles[8] = b_tiles[9];
		b_tiles[9] = b_tiles[10];
		b_tiles[10] = b_tiles[11];
		b_tiles[11] = b_tiles[12];
		b_tiles[12] = b_tiles[13];
		b_tiles[13] = b_tiles[14];
		b_tiles[14] = b_tiles[15];
		b_tiles[15] = b_tiles[16];
		b_tiles[16] = b_tiles[17];
		b_tiles[17] = b_tiles[18];
		b_tiles[18] = b_tiles[19];
		b_tiles[19] = b_tiles[20];
		b_tiles[20] = greenBox;
		greenBox = redBox;
		redBox -= 27;
		if (Counter > 0)
		{
			m_tiles[redBox] = 1;
			m_tiles[greenBox] = 2;
			for (int i = 20; i >= Counter; i--)
			{
				m_tiles[b_tiles[i]] = 2;
			}
			m_tiles[b_tiles[Counter]] = 0;
		}
		fpsCounter = 0;
	}
	if ((Move == 2) && (fpsCounter == frameAmount))
	{
		int i = 21; i > Counter; i--;
		m_tiles[redBox] = 2;
		whiteBox = b_tiles[1];
		b_tiles[1] = b_tiles[2];
		b_tiles[2] = b_tiles[3];
		b_tiles[3] = b_tiles[4];
		b_tiles[4] = b_tiles[5];
		b_tiles[5] = b_tiles[6];
		b_tiles[6] = b_tiles[7];
		b_tiles[7] = b_tiles[8];
		b_tiles[8] = b_tiles[9];
		b_tiles[9] = b_tiles[10];
		b_tiles[10] = b_tiles[11];
		b_tiles[11] = b_tiles[12];
		b_tiles[12] = b_tiles[13];
		b_tiles[13] = b_tiles[14];
		b_tiles[14] = b_tiles[15];
		b_tiles[15] = b_tiles[16];
		b_tiles[16] = b_tiles[17];
		b_tiles[17] = b_tiles[18];
		b_tiles[18] = b_tiles[19];
		b_tiles[19] = b_tiles[20];
		b_tiles[20] = greenBox;
		greenBox = redBox;
		redBox += 27;
		if (Counter > 0)
		{
			m_tiles[redBox] = 1;
			m_tiles[greenBox] = 2;
			for (int i = 20; i >= Counter; i--)
			{
				m_tiles[b_tiles[i]] = 2;
			}
			m_tiles[b_tiles[Counter]] = 0;
		}
		fpsCounter = 0;
	}
	if ((Move == 1) && (fpsCounter == frameAmount))
	{
		int i = 21; i > Counter; i--;
		m_tiles[redBox] = 2;
		whiteBox = b_tiles[1];
		b_tiles[1] = b_tiles[2];
		b_tiles[2] = b_tiles[3];
		b_tiles[3] = b_tiles[4];
		b_tiles[4] = b_tiles[5];
		b_tiles[5] = b_tiles[6];
		b_tiles[6] = b_tiles[7];
		b_tiles[7] = b_tiles[8];
		b_tiles[8] = b_tiles[9];
		b_tiles[9] = b_tiles[10];
		b_tiles[10] = b_tiles[11];
		b_tiles[11] = b_tiles[12];
		b_tiles[12] = b_tiles[13];
		b_tiles[13] = b_tiles[14];
		b_tiles[14] = b_tiles[15];
		b_tiles[15] = b_tiles[16];
		b_tiles[16] = b_tiles[17];
		b_tiles[17] = b_tiles[18];
		b_tiles[18] = b_tiles[19];
		b_tiles[19] = b_tiles[20];
		b_tiles[20] = greenBox;
		greenBox = redBox;
		redBox += 1;
		if (Counter > 0)
		{
			m_tiles[redBox] = 1;
			m_tiles[greenBox] = 2;
			for (int i = 20; i >= Counter; i--)
			{
				m_tiles[b_tiles[i]] = 2;
			}
			m_tiles[b_tiles[Counter]] = 0;
		}
		fpsCounter = 0;
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
	case 5: return LIME;
	}
}