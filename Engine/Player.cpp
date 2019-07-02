#include "Player.h"

void Player::Draw(Graphics& gfx) const
{
	gfx.DrawRect(x, y, width, height, color);
}

void  Player::GoUp()
{
	y += -speed;
}

void Player::GoDown()
{
	y += speed;
}

void Player::Clamp()
{
	if (y <= 0)
	{
		y = 0;
	}
	if (y + height >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - height;
	}
}

void Player::AddScore()
{
	score++;
}

int Player::GetScore() const
{
	return score;
}

int Player::GetWidth() const
{
	return width;
}

int Player::GetHeight() const
{
	return height;
}

int Player::GetPos() const
{
	return y;
}