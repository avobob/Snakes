#include "storage.h"
#include "raylib.h"

Color storage::GetTileColor(int tileValue) {
	switch (tileValue) {
	case 0:	return WHITE;
	case 1: return RED;
	case 2: return GREEN;
	case 3: return YELLOW;
	case 4: return BLACK;
	}
}