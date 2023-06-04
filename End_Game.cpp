#include "End_Game.h"
#include "raylib.h"

void End_Game() {
	if (ST.m_tiles[MS.red] != 1) {
		ST.GameOver = "GAME OVER!";
		ST.GameEnd = true;
		ST.Move = 0;
	}
}
