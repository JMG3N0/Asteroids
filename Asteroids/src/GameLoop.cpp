#include "Player.h"

void InitPlayer(Player& Player);

int GameLoop() {
	Player player;
	int counter = 5;
	InitPlayer(player);
	while (player.Life > 0)
	{
		player.Mouse = GetMousePosition();

		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			counter = 1;
			if (player.Mouse.x != player.Position.x)
			{
				if (player.Mouse.x > player.Position.x)
				{
					if (player.SpeedX + player.Acceleration < player.SpeedCap)
					{
						player.SpeedX += player.Acceleration;
					}
					
				}
				else if (player.Mouse.x < player.Position.x)
				{
					if (player.SpeedX - player.Acceleration > (player.SpeedCap * -1))
					{
						player.SpeedX -= player.Acceleration;
					}
				}
			}
			if (player.Mouse.y != player.Position.y)
			{
				if (player.Mouse.y > player.Position.y)
				{
					if (player.SpeedY + player.Acceleration < player.SpeedCap)
					{
						player.SpeedY += player.Acceleration;
					}
				}
				else if(player.Mouse.y < player.Position.y)
				{
					if (player.SpeedY - player.Acceleration > (player.SpeedCap * -1))
					{
						player.SpeedY -= player.Acceleration;
					}
					
				}
			}
		}

		player.Position.x += player.SpeedX * GetFrameTime();
		player.Position.y += player.SpeedY * GetFrameTime();

		if (counter > 0 && IsMouseButtonUp(MOUSE_BUTTON_RIGHT))
		{

			counter--;
			if (player.SpeedX > 0)
			{
				player.SpeedX += player.Slide;
			}
			else if (player.SpeedX < 0)
			{
				player.SpeedX -= player.Slide;
			}
			if (player.SpeedY > 0)
			{
				player.SpeedY += player.Slide;
			}
			else if (player.SpeedY < 0)
			{
				player.SpeedY -= player.Slide;
			}
			
		}
		else if (counter == 0)
		{
			if (player.SpeedX > 0)
			{
				player.SpeedX -= player.Drag;
				if (player.SpeedX < 0)
				{
					player.SpeedX = 0;
				}
			}
			else if (player.SpeedX < 0)
			{
				player.SpeedX += player.Drag;
				if (player.SpeedX > 0)
				{
					player.SpeedX = 0;
				}
			}
			if (player.SpeedY > 0)
			{
				player.SpeedY -= player.Drag;
				if (player.SpeedY < 0)
				{
					player.SpeedY = 0;
				}
			}
			else if (player.SpeedY < 0)
			{
				player.SpeedY += player.Drag;
				if (player.SpeedY > 0)
				{
					player.SpeedY = 0;
				}
			}
		}


		

		BeginDrawing();
		ClearBackground(MAROON);

		DrawRectangle(player.Position.x, player.Position.y, player.widght, player.height, BLUE);
		EndDrawing();
	}
	return 0;

}