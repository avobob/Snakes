#include "yellow_box.h"
#include "screen.h"
#include "raylib.h"
#include <stdlib.h>
#include <random>
#include <iostream>
using namespace std;
void yellow_box::Summon() {
	for (int i = 0; i < ST.COLS * ST.ROWS; i++)
	{
		if (ST.m_tiles[yellowBox] == 3)break;
		else {
			yellow = true;
			break;
		}
	}
	if (yellow) { //Draws Fruit
		yellow = false;
		random_device rd;
		mt19937 e{ rd() };
		uniform_int_distribution<int> distr{ ST.COLS, ST.COLS * ST.ROWS - ST.COLS };
		int n = distr(e);
		yellowBox = n;
		ST.GameCounter++;
		if (ST.m_tiles[n] == 0) {
			ST.m_tiles[n] = 3;
			ST.Counter--;
			ST.GameCounter++;
			ST.frameAmount--;
		}
	}
}