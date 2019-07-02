#include "Ball.h"

void Ball::Draw(Graphics& gfx) const
{
	gfx.DrawRect(x, y, size, size, color);
}

void Ball::CheckIfBounce(Player& p1, Player& p2)
{
	// checks Top and Bottom 
	if (y <= 0)
	{
		y = 0;
		vy *= -1;
	}
	if (y + size >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - size;
		vy *= -1;
	}
	//-----------------------

	// checks Players
	if (x <= p1.GetWidth() && 
	   (y >= p1.GetPos() && y <= (p1.GetPos() + p1.GetHeight())))
	{
		x = p1.GetWidth();
		vx *= -1;
		bounced = true;
	}
	if (x + size >= (Graphics::ScreenWidth - p2.GetWidth()) && 
	   (y >= p2.GetPos() && y <= (p2.GetPos() + p2.GetHeight())))
	{
		x = Graphics::ScreenWidth - p2.GetWidth() - size;
		vx *= -1;
		bounced = true;
	}
	//----------------------

	// After every collision adds velocity
	if (bounced)
	{
		if (vx > 0)
		{
			vx += 0.2;
		}
		else
		{
			vx += -0.2;
		}

		if (vy > 0)
		{
			vy += 0.15;
		}
		else
		{
			vy += -0.15;
		}
		bounced = false;
	}
}

// Gives points to the players and respawns
void Ball::CheckSideCollision(Player& p1, Player& p2)
{
	if (x < 0)
	{
		p2.AddScore();
		Respawn();
	}
	if (x + size > Graphics::ScreenWidth)
	{
		p1.AddScore();
		Respawn();
	}
}

void Ball::Move()
{
	x += std::floor(vx);
	y += std::round(vy);
}


void Ball::Respawn()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> vxDist(0, 1);
	std::uniform_int_distribution<int> vyDist(0, 1);
	//can add random pos
	x = 400;
	y = 300;
	vx = 6;
	vy = 3;
	if (vxDist(rng) == 1)
	{
		vx *= -1;
	}
	if (vyDist(rng) == 1)
	{
		vy *= -1;
	}
}