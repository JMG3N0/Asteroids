#include "Player.h"

void InitPlayer(Player& Player)
{
	Player.Life = 3;
	Player.Points = 0;
	Player.Position = { 512, 388 };
	Player.Mouse = GetMousePosition();
	Player.Speed = { 0, 0 };
	Player.Acceleration = 100;
	Player.SpeedCap = 500;
	Player.height = 20;
	Player.width = 20;
	Player.Pause = 0;
}