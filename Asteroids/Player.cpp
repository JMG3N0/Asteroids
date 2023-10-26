#include "src/Player.h"

void InitPlayer(Player& Player)
{
	Player.Life = 3;
	Player.Points = 0;
	Player.Position = { 500, 80 };
	Player.Mouse = GetMousePosition();
}