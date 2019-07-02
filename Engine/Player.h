#pragma once
#include "Colors.h"
#include "Graphics.h"

class Player
{
public:
	Player(int x, int y, Color c)
	{
		this->x = x;
		this->y = y;
		color = c;
	}
	void Draw(Graphics& gfx) const;
	void GoUp();
	void GoDown();
	void Clamp();
	void AddScore();
	int GetScore() const;
	int GetWidth() const;
	int GetHeight() const;
	int GetPos() const;
private:
	int x;
	int y;
	int score = 0;
	Color color;
	static constexpr int width = 20;
	static constexpr int height = 100;
	static constexpr int speed = 5;
};