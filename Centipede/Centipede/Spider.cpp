#include "stdafx.h"
#include "Spider.h"


Spider::Spider(sf::RenderWindow * renderWindow) : GameObject(renderWindow)
{

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

int Spider::returnPointValue(int distanceFromPlayer)
{
	int value;
	if (distanceFromPlayer > 4)
		value = 300;
	if (distanceFromPlayer < 4)
		value = 600;
	if (distanceFromPlayer == 1)
		value = 900;

	return value;          
}
bool Spider::takeHealth()
{

}


Spider::~Spider()
{
}