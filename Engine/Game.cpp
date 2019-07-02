/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	p1(p1X, p1Y, p1C),
	p2(p2X, p2Y, p2C),
	ball(400, 300)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed('W'))
	{
		p1.GoUp();
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		p1.GoDown();
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		p2.GoUp();
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		p2.GoDown();
	}

	p1.Clamp();
	p2.Clamp();

	if (!gameOver)
	{

		ball.Move();
		ball.CheckSideCollision(p1, p2);
		ball.CheckIfBounce(p1, p2);

		if (p1.GetScore() == 10 || p2.GetScore() == 10)
		{
			gameOver = true;
		}
	}
}

void Game::DrawPoints(int x, int h, Color color)
{
	gfx.DrawRect(x, 0, 20, h * 60, color);
}

void Game::ComposeFrame()
{
	p1.Draw(gfx);
	p2.Draw(gfx);
	DrawPoints(380, p1.GetScore(), Color(179, 255, 179));
	DrawPoints(400, p2.GetScore(), Color(255, 179, 179));
	ball.Draw(gfx);

	if (gameOver)
	{
		gfx.DrawRect(380, 280, 40, 40, Colors::Blue);
	}
}
