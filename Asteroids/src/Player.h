#pragma once
#include "raylib.h"

struct Player
{
	Vector2 Mouse;
	Vector2 Position;
	int Life;
	int Points;
	int SpeedY;
	int SpeedX;
	int Acceleration;
	int SpeedCap;
	int Slide;
	int Drag;
	int height;
	int widght;
};

