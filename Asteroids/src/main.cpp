#include "raylib.h"

typedef enum GameScreen { TITLE = 0, GAME, CREDIT, ENDING } GameScreen;



int main(){

	SetExitKey(KEY_NULL);
	const int height = GetScreenHeight();
	const int width = GetScreenWidth();
	Vector2 Mouse = { -100.0f, -100.0f };
	
	int option = 0;

	InitWindow(width, height, "Samurai Rush");

	GameScreen currentScreen = TITLE;

	while (!WindowShouldClose())
	{
		Mouse = GetMousePosition();
		switch (currentScreen)
		{
		case TITLE:

			break;
		case GAME:
			break;
		case CREDIT:
			break;
		case ENDING:
			break;
		default:
			break;
		}

		BeginDrawing();
		ClearBackground(MAROON);

		switch (currentScreen)
		{
		case TITLE:
			DrawText("Samurai Rush", GetScreenWidth() / 3.2, GetScreenHeight() / 4, 120, GOLD);
			DrawText("Use the Mouse or W/A/S/D", GetScreenWidth() / 2.6, GetScreenHeight() / 1.1, 30, GRAY);
			if (Mouse.y >= (GetScreenHeight() /2 - 20) && Mouse.y <= (GetScreenHeight() / 2 + 50) && Mouse.x >= ((GetScreenWidth() / 2.1) -10) && Mouse.x <= ((GetScreenWidth() / 2.1) + 150))
			{
				DrawText("Play", GetScreenWidth() / 2.1, GetScreenHeight() / 2, 60, GRAY);
			}
			else
			{
				DrawText("Play", GetScreenWidth() / 2.1, GetScreenHeight() / 2, 60, GOLD);
			}
			
			if (Mouse.y >= (GetScreenHeight() / 1.7 - 20) && Mouse.y <= (GetScreenHeight() / 1.7 + 50) && Mouse.x >= ((GetScreenWidth() / 2.1) - 10) && Mouse.x <= ((GetScreenWidth() / 2.1) + 250))
			{
				DrawText("Credits", GetScreenWidth() / 2.1, GetScreenHeight() / 1.7, 60, GRAY);
			}
			else
			{
				DrawText("Credits", GetScreenWidth() / 2.1, GetScreenHeight() / 1.7, 60, GOLD);
			}
			if (Mouse.y >= (GetScreenHeight() / 1.5 - 20) && Mouse.y <= (GetScreenHeight() / 1.5 + 50) && Mouse.x >= ((GetScreenWidth() / 2.1) - 10) && Mouse.x <= ((GetScreenWidth() / 2.1) + 150))
			{
				DrawText("Exit", GetScreenWidth() / 2.1, GetScreenHeight() / 1.5, 60, GRAY);
			}
			else
			{
				DrawText("Exit", GetScreenWidth() / 2.1, GetScreenHeight() / 1.5, 60, GOLD);
			}
			
			break;
		case GAME:
			break;
		case CREDIT:
			break;
		case ENDING:
			break;
		default:
			break;
		}
		EndDrawing();
	}
	CloseWindow();
}