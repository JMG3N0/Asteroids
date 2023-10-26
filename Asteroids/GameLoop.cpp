#include "src/Player.h"

void InitPlayer(Player& Player);

int GameLoop() {
	Player player;

	InitPlayer(player);
	while (player.Life > 0)
	{
		player.Mouse = GetMousePosition();

		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			if (player.Mouse.x != player.Position.x)
			{
				if (player.Mouse.x > player.Position.x)
				{
					player.Position.x++;
				}
				else
				{
					player.Position.x--;
				}
			}
			if (player.Mouse.y != player.Position.y)
			{
				if (player.Mouse.y > player.Position.y)
				{
					player.Position.y++;
				}
				else
				{
					player.Position.y--;
				}
			}
		}

		BeginDrawing();
		ClearBackground(MAROON);

		DrawRectangle(player.Position.x, player.Position.y, 20, 20, BLUE);
		EndDrawing();
	}
	return 0;

}