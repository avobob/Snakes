#include "screen.h"
#include "raylib.h"


int main(int argc, char* argv[]){
	{
	screen app;
	storage ST;
	InitWindow(ST.m_windowWidth, ST.m_windowHeight, "SNAKE");
	SetTargetFPS(ST.fps);
	app.Load();
	while (!WindowShouldClose()) {
		app.Update(GetFrameTime());
		app.Draw();
	}
	app.Unload();
	}
	return 0;
}
