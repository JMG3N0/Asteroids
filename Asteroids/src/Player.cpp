#include "Player.h"

void InitPlayer(Player& Player)
{
	Player.Life = 3;
	Player.Points = 0;
	Player.Position = { 500, 80 };
	Player.Mouse = GetMousePosition();
	Player.SpeedY = 0;
	Player.SpeedX = 0;
	Player.Acceleration = 25;
	Player.Slide = 10;
	Player.Drag = 1;
	Player.SpeedCap = 200;
	Player.height = 20;
	Player.widght = 20;
}