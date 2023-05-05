#include "screen.h"
#include "GreenBoxes.h"
#include "raylib.h"
#include <stdlib.h>
#include <random>
#include <iostream>

using namespace std;
int fps = 60;
int fpcCounter = 0;
int frameAmount = 21;
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

//bool moveA = false;
//bool moveW = false;
//bool moveS = false;
//bool moveD = false;
//
//bool keyA = true;
//bool keyW = true;
//bool keyS = false;
//bool keyD = true;


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
		fpcCounter ++;
		Update(GetFrameTime());
		Draw();
		if (fpcCounter == frameAmount)
		{
			fpcCounter = 0;
		}
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
	m_tiles[675] = 4;
	m_tiles[675] = 4;
	m_tiles[675] = 4;
	m_tiles[675] = 4;

	for (int i = 701; i < 729; i++)
	{
		m_tiles[i] = 4;
	}
}
void screen::Load()
{
	cout << Key << "-------------------------------" << endl;
	// Task1:
	// Initialise all values in m_tiles array to a random
	// value between 0 and 5 exclusive;
	// -----------------------------------------------------

	// write your code here
	for (int i = 0; i < 729; i++)
	{
	m_tiles[i] = 0;
	}
	for (int i = 0; i < 729; i++)
	{
		m_tiles[redBox] = 1;
	}
	/*for (int i = 0; i < 729; i++)
	{
		m_tiles[greenBox] = 2;
	}*/
	for (int i = 0; i < 21; i++)
	{
		b_tiles[whiteBox] = 2;
	}
	Body();
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
	Border();
	{
	}
	for (int i = 0; i < 729; i++)
	{
	/*	if (m_tiles[i] == 3)
		{
			yellow = false;
		}*/
		if (m_tiles[yellowBox] == 3)
		{
			//cout << "-----hi-------" << endl;
			break;
		}
		else
		{
			cout << "-----hello-------" << endl;
			yellow = true;
			frameAmount --;
			break;
		}
	}
	if(yellow)
	{
			yellow = false;
		random_device rd;
		mt19937 e{ rd() }; // or std::default_random_engine e{rd()};
		uniform_int_distribution<int> distr{ 28, 701 };
		cout << distr(e) << "------------" << endl;

		int n = distr(e);
		yellowBox = n;
		if (m_tiles[n] == 0)
		{
			m_tiles[n] = 3;
			Counter++;
			GameCounter++;
		}
	}

		if (m_tiles[redBox] == 4)
		{
			GameOver = "GAME OVER!";
		}
		else if (m_tiles[redBox] == 2)
		{
			GameOver = "GAME OVER!";
		}

	/*for (int i = 0; i < 28; i++)
		{
			m_tiles[i] = 4;
		}

		m_tiles[53]  = 4;
		m_tiles[54]  = 4;
		m_tiles[80]  = 4;
		m_tiles[81]  = 4;
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
		m_tiles[675] = 4;
		m_tiles[675] = 4;
		m_tiles[675] = 4;
		m_tiles[675] = 4;

		for (int i = 701; i < 729; i++)
		{
			m_tiles[i] = 4;
		}*/
	/*for (int i = 0;   i < 28;  i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 53;  i < 55;  i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 80;  i < 82;  i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 107; i < 109; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 134; i < 136; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 161; i < 163; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 188; i < 190; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 215; i < 217; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 242; i < 244; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 269; i < 271; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 296; i < 298; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 323; i < 325; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 350; i < 352; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 377; i < 379; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 404; i < 406; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 431; i < 433; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 458; i < 460; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 485; i < 487; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 512; i < 514; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 539; i < 541; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 566; i < 568; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 593; i < 595; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 620; i < 622; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 647; i < 649; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 674; i < 676; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 377; i < 379; i++)
	{
		m_tiles[i] = 4;
	}
	for (int i = 701; i < 729; i++)
	{
		m_tiles[i] = 4;
	}*/
	//int IsPressedA = false;
	//int IsPressedW = false;
	//int IsPressedS = false;
	//int IsPressedD = false;
	/*if (IsKeyPressed(KEY_A)||(IsKeyPressed(KEY_W))||(IsKeyPressed(KEY_S))||(IsKeyPressed(KEY_D)))
	{
		IsPressed = true;
	}*/
	if (IsKeyPressed(KEY_A))
	{
		if (Key != 1)
		{
			Move = 4;
			Key = 1;
			/*moveA = true;
			moveW = false;
			moveS = false;
			moveD = false;

			keyA = true;
			keyW = true;
			keyS = true;
			keyD = false;*/
			/*IsPressedA = true;
			cout << keyA << endl;
			cout << keyW << endl;
			cout << keyS << endl;
			cout << keyD << endl;*/
		}
	}
	if (IsKeyPressed(KEY_W))
	{
		if (Key != 2)
		{
			Move = 3;
			Key = 2;
			/*moveA = false;
			moveW = true;
			moveS = false;
			moveD = false;

			keyA = true;
			keyW = true;
			keyS = false;
			keyD = true;*/
			/*IsPressedW = true;
			cout << keyA << endl;
			cout << keyW << endl;
			cout << keyS << endl;
			cout << keyD << endl;*/
		}
	}
	if (IsKeyPressed(KEY_S))
	{
		if (Key != 3)
		{
			Move = 2;
			Key = 3;
			/*moveA = false;
			moveW = false;
			moveS = true;
			moveD = false;

			keyA = true;
			keyW = false;
			keyS = true;
			keyD = true;*/
			/*IsPressedS = true;
			cout << keyA << endl;
			cout << keyW << endl;
			cout << keyS << endl;
			cout << keyD << endl;*/
		}
	}
	if (IsKeyPressed(KEY_D))
	{
		if (Key != 4)
		{
			Move = 1;
			Key = 4;
			/*moveA = false;
			moveW = false;
			moveS = false;
			moveD = true;

			keyA = false;
			keyW = true;
			keyS = true;
			keyD = true;*/
			/*IsPressedD = true;
			cout << keyA << endl;
			cout << keyW << endl;
			cout << keyS << endl;
			cout << keyD << endl;*/
		}
	}

	/*do
	{*/

			if (Move == 4 && fpcCounter == frameAmount)
			{
				//Vector2 headPos = GetMousePosition();
				// Task 3:
				// TODO: Calculate row and col index based on the mouse positon

				for (int i = 0; i < 729; i++)
				{
					if (m_tiles[i] == 1)
					{
						m_tiles[redBox] = 2;
						whiteBox = box1;
						box1 = box2;
						box2 = box3;
						box3 = box4;
						box4 = box5;
						box5 = box6;
						box6 = box7;
						box7 = box8;
						box8 = box9;
						box9 = box10;
						box10 = box11;
						box11 = box12;
						box12 = box13;
						box13 = box14;
						box14 = box15;
						box15 = box16;
						box16 = box17;
						box17 = box18;
						box18 = box19;
						box19 = box20;
						box20 = box21;
						box21 = greenBox;
						greenBox = redBox;
						redBox -= 1;
						m_tiles[redBox] = 1;
						if (Counter > 1)m_tiles[greenBox] = 2;
						if (Counter == 1)m_tiles[box21] = 0;
						if (Counter > 2)m_tiles[box21] = 2;
						if (Counter == 2)m_tiles[box20] = 0;
						if (Counter > 3)m_tiles[box20] = 2;
						if (Counter == 3)m_tiles[box19] = 0;
						if (Counter > 4)m_tiles[box19] = 2;
						if (Counter == 4)m_tiles[box18] = 0;
						if (Counter > 5)m_tiles[box18] = 2;
						if (Counter == 5)m_tiles[box17] = 0;
						if (Counter > 6)m_tiles[box17] = 2;
						if (Counter == 6)m_tiles[box16] = 0;
						if (Counter > 7)m_tiles[box16] = 2;
						if (Counter == 7)m_tiles[box15] = 0;
						if (Counter > 8)m_tiles[box15] = 2;
						if (Counter == 8)m_tiles[box14] = 0;
						if (Counter > 9)m_tiles[box14] = 2;
						if (Counter == 9)m_tiles[box13] = 0;
						if (Counter > 10)m_tiles[box13] = 2;
						if (Counter == 10)m_tiles[box12] = 0;
						if (Counter > 11)m_tiles[box12] = 2;
						if (Counter == 11)m_tiles[box11] = 0;
						if (Counter > 12)m_tiles[box11] = 2;
						if (Counter == 12)m_tiles[box10] = 0;
						if (Counter > 13)m_tiles[box10] = 2;
						if (Counter == 13)m_tiles[box9] = 0;
						if (Counter > 14)m_tiles[box9] = 2;
						if (Counter == 14)m_tiles[box8] = 0;
						if (Counter > 15)m_tiles[box8] = 2;
						if (Counter == 15)m_tiles[box7] = 0;
						if (Counter > 16)m_tiles[box7] = 2;
						if (Counter == 16)m_tiles[box6] = 0;
						if (Counter > 17)m_tiles[box6] = 2;
						if (Counter == 17)m_tiles[box5] = 0;
						if (Counter > 18)m_tiles[box5] = 2;
						if (Counter == 18)m_tiles[box4] = 0;
						if (Counter > 19)m_tiles[box4] = 2;
						if (Counter == 19)m_tiles[box3] = 0;
						if (Counter > 20)m_tiles[box3] = 2;
						if (Counter == 20)m_tiles[box2] = 0;
						if (Counter > 21)m_tiles[box2] = 2;
						if (Counter == 21)m_tiles[box1] = 0;
						if (Counter > 21)
						{ 
							m_tiles[box1] = 2;
							m_tiles[whiteBox] = 0;
						}


						/*m_tiles[box21] = 2;
						m_tiles[box20] = 2;
						m_tiles[box19] = 2;
						m_tiles[box18] = 2;
						m_tiles[box17] = 2;
						m_tiles[box16] = 2;
						m_tiles[box15] = 2;
						m_tiles[box14] = 2;
						m_tiles[box13] = 2;
						m_tiles[box12] = 2;
						m_tiles[box11] = 2;
						m_tiles[box10] = 2;
						m_tiles[box9] = 2;
						m_tiles[box8] = 2;
						m_tiles[box7] = 2;
						m_tiles[box6] = 2;
						m_tiles[box5] = 2;
						m_tiles[box4] = 2;
						m_tiles[box3] = 2;
						m_tiles[box2] = 2;
						m_tiles[box1] = 2;
						m_tiles[whiteBox] = 0;*/

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
						//IsPressedA = false;
					}
				}
				fpcCounter = 0;
			}
			if (Move == 3 && fpcCounter == frameAmount)
			{
				//Vector2 headPos = GetMousePosition();
				// Task 3:
				// TODO: Calculate row and col index based on the mouse positon
				for (int i = 0; i < 729; i++)
				{
					if (m_tiles[i] == 1)
					{
						//m_tiles[redBox] = 2; 
						//whiteBox = greenBox;
						//Body();
						m_tiles[redBox] = 2;
						whiteBox = box1;
						box1 = box2;
						box2 = box3;
						box3 = box4;
						box4 = box5;
						box5 = box6;
						box6 = box7;
						box7 = box8;
						box8 = box9;
						box9 = box10;
						box10 = box11;
						box11 = box12;
						box12 = box13;
						box13 = box14;
						box14 = box15;
						box15 = box16;
						box16 = box17;
						box17 = box18;
						box18 = box19;
						box19 = box20;
						box20 = box21;
						box21 = greenBox;
						greenBox = redBox;
						redBox -= 27;
						m_tiles[redBox] = 1;
						if (Counter > 1)m_tiles[greenBox] = 2;
						if (Counter == 1)m_tiles[box21] = 0;
						if (Counter > 2)m_tiles[box21] = 2;
						if (Counter == 2)m_tiles[box20] = 0;
						if (Counter > 3)m_tiles[box20] = 2;
						if (Counter == 3)m_tiles[box19] = 0;
						if (Counter > 4)m_tiles[box19] = 2;
						if (Counter == 4)m_tiles[box18] = 0;
						if (Counter > 5)m_tiles[box18] = 2;
						if (Counter == 5)m_tiles[box17] = 0;
						if (Counter > 6)m_tiles[box17] = 2;
						if (Counter == 6)m_tiles[box16] = 0;
						if (Counter > 7)m_tiles[box16] = 2;
						if (Counter == 7)m_tiles[box15] = 0;
						if (Counter > 8)m_tiles[box15] = 2;
						if (Counter == 8)m_tiles[box14] = 0;
						if (Counter > 9)m_tiles[box14] = 2;
						if (Counter == 9)m_tiles[box13] = 0;
						if (Counter > 10)m_tiles[box13] = 2;
						if (Counter == 10)m_tiles[box12] = 0;
						if (Counter > 11)m_tiles[box12] = 2;
						if (Counter == 11)m_tiles[box11] = 0;
						if (Counter > 12)m_tiles[box11] = 2;
						if (Counter == 12)m_tiles[box10] = 0;
						if (Counter > 13)m_tiles[box10] = 2;
						if (Counter == 13)m_tiles[box9] = 0;
						if (Counter > 14)m_tiles[box9] = 2;
						if (Counter == 14)m_tiles[box8] = 0;
						if (Counter > 15)m_tiles[box8] = 2;
						if (Counter == 15)m_tiles[box7] = 0;
						if (Counter > 16)m_tiles[box7] = 2;
						if (Counter == 16)m_tiles[box6] = 0;
						if (Counter > 17)m_tiles[box6] = 2;
						if (Counter == 17)m_tiles[box5] = 0;
						if (Counter > 18)m_tiles[box5] = 2;
						if (Counter == 18)m_tiles[box4] = 0;
						if (Counter > 19)m_tiles[box4] = 2;
						if (Counter == 19)m_tiles[box3] = 0;
						if (Counter > 20)m_tiles[box3] = 2;
						if (Counter == 20)m_tiles[box2] = 0;
						if (Counter > 21)m_tiles[box2] = 2;
						if (Counter == 21)m_tiles[box1] = 0;
						if (Counter > 21)
						{
							m_tiles[box1] = 2;
							m_tiles[whiteBox] = 0;
						}

						/*m_tiles[box21] = 2;
						m_tiles[box20] = 2;
						m_tiles[box19] = 2;
						m_tiles[box18] = 2;
						m_tiles[box17] = 2;
						m_tiles[box16] = 2;
						m_tiles[box15] = 2;
						m_tiles[box14] = 2;
						m_tiles[box13] = 2;
						m_tiles[box12] = 2;
						m_tiles[box11] = 2;
						m_tiles[box10] = 2;
						m_tiles[box9] = 2;
						m_tiles[box8] = 2;
						m_tiles[box7] = 2;
						m_tiles[box6] = 2;
						m_tiles[box5] = 2;
						m_tiles[box4] = 2;
						m_tiles[box3] = 2;
						m_tiles[box2] = 2;
						m_tiles[box1] = 2;
						m_tiles[whiteBox] = 0;*/

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
						//IsPressedW = false;
					}
				}
				fpcCounter = 0;
			}
			if (Move == 2 && fpcCounter == frameAmount)
			{
				//Vector2 headPos = GetMousePosition();
				// Task 3:
				// TODO: Calculate row and col index based on the mouse positon
				for (int i = 729; i > 0; i--)
				{
					if (m_tiles[i] == 1)
					{
						//whiteBox = greenBox;
						//Body();
					    //m_tiles[redBox] = 2;
						m_tiles[redBox] = 2;
						whiteBox = box1;
						box1 = box2;
						box2 = box3;
						box3 = box4;
						box4 = box5;
						box5 = box6;
						box6 = box7;
						box7 = box8;
						box8 = box9;
						box9 = box10;
						box10 = box11;
						box11 = box12;
						box12 = box13;
						box13 = box14;
						box14 = box15;
						box15 = box16;
						box16 = box17;
						box17 = box18;
						box18 = box19;
						box19 = box20;
						box20 = box21;
						box21 = greenBox;
						greenBox = redBox;
						redBox += 27;
						m_tiles[redBox] = 1;
						if (Counter > 1)m_tiles[greenBox] = 2;
						if (Counter == 1)m_tiles[box21] = 0;
						if (Counter > 2)m_tiles[box21] = 2;
						if (Counter == 2)m_tiles[box20] = 0;
						if (Counter > 3)m_tiles[box20] = 2;
						if (Counter == 3)m_tiles[box19] = 0;
						if (Counter > 4)m_tiles[box19] = 2;
						if (Counter == 4)m_tiles[box18] = 0;
						if (Counter > 5)m_tiles[box18] = 2;
						if (Counter == 5)m_tiles[box17] = 0;
						if (Counter > 6)m_tiles[box17] = 2;
						if (Counter == 6)m_tiles[box16] = 0;
						if (Counter > 7)m_tiles[box16] = 2;
						if (Counter == 7)m_tiles[box15] = 0;
						if (Counter > 8)m_tiles[box15] = 2;
						if (Counter == 8)m_tiles[box14] = 0;
						if (Counter > 9)m_tiles[box14] = 2;
						if (Counter == 9)m_tiles[box13] = 0;
						if (Counter > 10)m_tiles[box13] = 2;
						if (Counter == 10)m_tiles[box12] = 0;
						if (Counter > 11)m_tiles[box12] = 2;
						if (Counter == 11)m_tiles[box11] = 0;
						if (Counter > 12)m_tiles[box11] = 2;
						if (Counter == 12)m_tiles[box10] = 0;
						if (Counter > 13)m_tiles[box10] = 2;
						if (Counter == 13)m_tiles[box9] = 0;
						if (Counter > 14)m_tiles[box9] = 2;
						if (Counter == 14)m_tiles[box8] = 0;
						if (Counter > 15)m_tiles[box8] = 2;
						if (Counter == 15)m_tiles[box7] = 0;
						if (Counter > 16)m_tiles[box7] = 2;
						if (Counter == 16)m_tiles[box6] = 0;
						if (Counter > 17)m_tiles[box6] = 2;
						if (Counter == 17)m_tiles[box5] = 0;
						if (Counter > 18)m_tiles[box5] = 2;
						if (Counter == 18)m_tiles[box4] = 0;
						if (Counter > 19)m_tiles[box4] = 2;
						if (Counter == 19)m_tiles[box3] = 0;
						if (Counter > 20)m_tiles[box3] = 2;
						if (Counter == 20)m_tiles[box2] = 0;
						if (Counter > 21)m_tiles[box2] = 2;
						if (Counter == 21)m_tiles[box1] = 0;
						if (Counter > 21)
						{
							m_tiles[box1] = 2;
							m_tiles[whiteBox] = 0;
						}
						/*m_tiles[box21] = 2;
						m_tiles[box20] = 2;
						m_tiles[box19] = 2;
						m_tiles[box18] = 2;
						m_tiles[box17] = 2;
						m_tiles[box16] = 2;
						m_tiles[box15] = 2;
						m_tiles[box14] = 2;
						m_tiles[box13] = 2;
						m_tiles[box12] = 2;
						m_tiles[box11] = 2;
						m_tiles[box10] = 2;
						m_tiles[box9] = 2;
						m_tiles[box8] = 2;
						m_tiles[box7] = 2;
						m_tiles[box6] = 2;
						m_tiles[box5] = 2;
						m_tiles[box4] = 2;
						m_tiles[box3] = 2;
						m_tiles[box2] = 2;
						m_tiles[box1] = 2;
						m_tiles[whiteBox] = 0;*/

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
						//IsPressedS = false;
					}
				}
				fpcCounter = 0;
			}
			if (Move == 1 && fpcCounter == frameAmount)
			{
				//Vector2 headPos = GetMousePosition();
				// Task 3:
				// TODO: Calculate row and col index based on the mouse positon
				for (int i = 729; i > 0; i--)
				{
					if (m_tiles[i] == 1)
					{
						//m_tiles[redBox] = 2;
						//whiteBox = greenBox;
						//Body();
						m_tiles[redBox] = 2;
						whiteBox = box1;
						box1 = box2;box2 = box3;box3 = box4;box4 = box5;box5 = box6;box6 = box7;box7 = box8;box8 = box9;box9 = box10;box10 = box11;box11 = box12;box12 = box13;box13 = box14;box14 = box15;box15 = box16;box16 = box17;box17 = box18;box18 = box19;box19 = box20;box20 = box21;box21 = greenBox;greenBox = redBox;
						redBox += 1;
						m_tiles[redBox] = 1;
						if (Counter > 1)m_tiles[greenBox] = 2;
						if (Counter == 1)m_tiles[box21] = 0;
						if (Counter > 2)m_tiles[box21] = 2;
						if (Counter == 2)m_tiles[box20] = 0;
						if (Counter > 3)m_tiles[box20] = 2;
						if (Counter == 3)m_tiles[box19] = 0;
						if (Counter > 4)m_tiles[box19] = 2;
						if (Counter == 4)m_tiles[box18] = 0;
						if (Counter > 5)m_tiles[box18] = 2;
						if (Counter == 5)m_tiles[box17] = 0;
						if (Counter > 6)m_tiles[box17] = 2;
						if (Counter == 6)m_tiles[box16] = 0;
						if (Counter > 7)m_tiles[box16] = 2;
						if (Counter == 7)m_tiles[box15] = 0;
						if (Counter > 8)m_tiles[box15] = 2;
						if (Counter == 8)m_tiles[box14] = 0;
						if (Counter > 9)m_tiles[box14] = 2;
						if (Counter == 9)m_tiles[box13] = 0;
						if (Counter > 10)m_tiles[box13] = 2;
						if (Counter == 10)m_tiles[box12] = 0;
						if (Counter > 11)m_tiles[box12] = 2;
						if (Counter == 11)m_tiles[box11] = 0;
						if (Counter > 12)m_tiles[box11] = 2;
						if (Counter == 12)m_tiles[box10] = 0;
						if (Counter > 13)m_tiles[box10] = 2;
						if (Counter == 13)m_tiles[box9] = 0;
						if (Counter > 14)m_tiles[box9] = 2;
						if (Counter == 14)m_tiles[box8] = 0;
						if (Counter > 15)m_tiles[box8] = 2;
						if (Counter == 15)m_tiles[box7] = 0;
						if (Counter > 16)m_tiles[box7] = 2;
						if (Counter == 16)m_tiles[box6] = 0;
						if (Counter > 17)m_tiles[box6] = 2;
						if (Counter == 17)m_tiles[box5] = 0;
						if (Counter > 18)m_tiles[box5] = 2;
						if (Counter == 18)m_tiles[box4] = 0;
						if (Counter > 19)m_tiles[box4] = 2;
						if (Counter == 19)m_tiles[box3] = 0;
						if (Counter > 20)m_tiles[box3] = 2;
						if (Counter == 20)m_tiles[box2] = 0;
						if (Counter > 21)m_tiles[box2] = 2;
						if (Counter == 21)m_tiles[box1] = 0;
						if (Counter > 21)
						{
							m_tiles[box1] = 2;
							m_tiles[whiteBox] = 0;
						}
						/*m_tiles[box21] = 2;
						m_tiles[box20] = 2;
						m_tiles[box19] = 2;
						m_tiles[box18] = 2;
						m_tiles[box17] = 2;
						m_tiles[box16] = 2;
						m_tiles[box15] = 2;
						m_tiles[box14] = 2;
						m_tiles[box13] = 2;
						m_tiles[box12] = 2;
						m_tiles[box11] = 2;
						m_tiles[box10] = 2;
						m_tiles[box9] = 2;
						m_tiles[box8] = 2;
						m_tiles[box7] = 2;
						m_tiles[box6] = 2;
						m_tiles[box5] = 2;
						m_tiles[box4] = 2;
						m_tiles[box3] = 2;
						m_tiles[box2] = 2;
						m_tiles[box1] = 2;
						m_tiles[whiteBox] = 0;*/

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
						//IsPressedD = false;
					}
				}
				fpcCounter = 0;
			}
		
}
//	while (true);
//}

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

		//DrawRectangleLines(0, 0, 810, 810, BLACK);
		//DrawRectangle(0, 0, 810, 810, BLACK);
		//DrawRectangleLinesEx();
				DrawRectangle(xPos, yPos, m_tileWidth, m_tileHeight, color);
				if (GameOver)
				{
						int textWidth = MeasureText(GameOver, 100);
						DrawText(GameOver, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 + -100, 100, PURPLE);
				}


				DrawText(TextFormat("Score: %d", GameCounter), 10, 10, 20, PURPLE);

			}
		}

		// --------------------------------------------------------------------

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