#pragma once
#include "raylib.h"

struct Player
{
	Vector2 Mouse;
	Vector2 Position;
	Vector2 Speed;
	int Life;
	int Points;
	int SpeedCap;
	int height;
	int width;
	int Pause;
	float Acceleration;
};

