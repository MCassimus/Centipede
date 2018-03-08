#include "stdafx.h"
#include "Spider.h"


Spider::Spider(sf::RenderWindow * renderWindow, int x, int y) : GameObject(renderWindow, x,  y)
{
	setTexture("spider.png");
	pointValue = 0;
}


void Spider::update()
{
	//while spider exists
	{
		// if collision with mushroom
		{
			//remove mushroom
		}
	}
	//else
	{
		//spawn on screen with 1/400 chance
	}

	return;
}


void Spider::setPointValue()
{
	if (distanceFromPlayer > 4) //if more than 4 levels away
		pointValue = 300;
	else if (distanceFromPlayer < 4 || distanceFromPlayer == 4) //no more than 4 levels
		pointValue = 600;
	else if (distanceFromPlayer == 1) //no more than 1 level away 
		pointValue = 900;

	return;
}


bool Spider::takeHealth()
{
	return true;
}


Spider::~Spider()
{
}