#pragma once

#include "Colors.h"
#include "Graphics.h"
#include "Player.h"
#include <random>
#include <math.h>

// Increase velocity after couple of hits

class Ball
{
public:
	Ball(int x, int y)
	{
		this->x = x;
		this->y = y;
		Respawn();
	}
	void Draw(Graphics& gfx) const;
	void CheckIfBounce(Player& p1, Player& p2); // bounes off from top,bottom and players
	void CheckSideCollision(Player& p1, Player& p2); // gives points to the players && respawns
	void Move();
private:
	void Respawn();
private:
	int x;
	int y;
	double vx;
	double vy;
	static constexpr Color color = Colors::White;
	static constexpr int size = 20;
	bool bounced = false;
};