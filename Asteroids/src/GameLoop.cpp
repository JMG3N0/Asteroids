#include "Player.h"

void InitPlayer(Player& Player);

int GameLoop() {
	Player player;
	InitPlayer(player);
	Texture2D character = LoadTexture("res/character_sprite_sheet.png");
	Rectangle frameRec = { 0.0f, 0.0f, (float)character.width / 16, ((float)character.height / 2) - 51 };

	while (player.Life > 0)
	{
		player.Mouse = GetMousePosition();

		switch (player.Pause)
		{
		case 0:
			if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
			{
				if (player.Mouse.x != (player.Position.x + player.width / 2))
				{
					if (player.Mouse.x > (player.Position.x + player.width / 2))
					{
						if (player.Speed.x + player.Acceleration < player.SpeedCap)
						{
							player.Speed.x += player.Acceleration * GetFrameTime();
						}

					}
					else if (player.Mouse.x < (player.Position.x + player.width / 2))
					{
						if (player.Speed.x - player.Acceleration > (player.SpeedCap * -1))
						{
							player.Speed.x -= player.Acceleration * GetFrameTime();
						}
					}
				}
				if (player.Mouse.y != (player.Position.y + player.height / 2))
				{
					if (player.Mouse.y > (player.Position.y + player.height / 2))
					{
						if (player.Speed.y + player.Acceleration < player.SpeedCap)
						{
							player.Speed.y += player.Acceleration * GetFrameTime();
						}
					}
					else if (player.Mouse.y < (player.Position.y + player.height / 2))
					{
						if (player.Speed.y - player.Acceleration > (player.SpeedCap * -1))
						{
							player.Speed.y -= player.Acceleration * GetFrameTime();
						}

					}
				}
			}
			player.Position.x += player.Speed.x * GetFrameTime();
			player.Position.y += player.Speed.y * GetFrameTime();

			//Move when hit the edges
			if (player.Position.y + player.height >= GetScreenHeight())
			{
				player.Position.y = 0;
			}
			else if (player.Position.y <= 0)
			{
				player.Position.y = GetScreenHeight() - player.height;
			}



			if (player.Position.x + player.width >= GetScreenWidth())
			{
				player.Position.x = 0;
			}
			else if (player.Position.x <= 0)
			{
				player.Position.x = GetScreenWidth() - player.width;
			}
			if (player.Mouse.x >= 0 && player.Mouse.x <= 90 && player.Mouse.y >= 0 && player.Mouse.y <= 30)
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					player.Pause = 1;
				}
			}
			//
			break;
		case 1:
			if (player.Mouse.x >= 420 && player.Mouse.x <= 600 && player.Mouse.y >= 350 && player.Mouse.y <= 420)
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					player.Pause = 0;
				}
			}
			if (player.Mouse.x >= 330 && player.Mouse.x <= 700 && player.Mouse.y >= 440 && player.Mouse.y <= 480)
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					return 0;
				}
			}
			break;
		default:
			break;
		}






		BeginDrawing();
		ClearBackground(BLACK);

		
		
		DrawTextureRec(character, frameRec, player.Position, WHITE);
		if (player.Pause == 0)
		{
			DrawRectangle(0, 0, 90, 30, DARKBLUE);
			if (player.Mouse.x >= 0 && player.Mouse.x <= 90 && player.Mouse.y >= 0 && player.Mouse.y <= 30)
			{
				DrawText("Pause", 10, 5, 20, GRAY);
			}
			else
			{
				DrawText("Pause", 10, 5, 20, GOLD);
			}
			
		}
		else
		{
			DrawRectangle(90, 90, 844, 500, DARKBLUE);
			DrawText("Game Paused", 230, 100, 90, GOLD);
			if (player.Mouse.x >= 420 && player.Mouse.x <= 600 && player.Mouse.y >= 350 && player.Mouse.y <= 420)
			{
				DrawText(">Continue", GetScreenWidth() / 2.25, GetScreenHeight() / 2, 30, GRAY);
			}
			else
			{
				DrawText("Continue", GetScreenWidth() / 2.3, GetScreenHeight() / 2, 30, GOLD);
			}
			if (player.Mouse.x >= 330 && player.Mouse.x <= 700 && player.Mouse.y >= 440 && player.Mouse.y <= 480)
			{
				DrawText(">Return to Main Menu", GetScreenWidth() / 2.85, GetScreenHeight() / 1.7, 30, GRAY);
			}
			else
			{
				DrawText("Return to Main Menu", GetScreenWidth() / 2.9, GetScreenHeight() / 1.7, 30, GOLD);
			}
			
		}

		EndDrawing();
	}
	return 0;

}