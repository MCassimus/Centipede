#include "stdafx.h"
#include "Spider.h"


Spider::Spider(sf::RenderWindow * renderWindow, int x, int y, Player& p) : GameObject(renderWindow, x,  y)
{
	currentPosition.x = x;
	currentPosition.y = y;
	setTexture("spider.png");
	pointValue = 0;
	player = &p;
}


void Spider::update()
{
	setPointValue();
	

	return;
}


void Spider::setPointValue()
{
	if (distanceFromPlayer > 4) //if more than 4 levels away
		pointValue = 900;
	else if (distanceFromPlayer < 4 || distanceFromPlayer == 4) //no more than 4 levels
		pointValue = 600;
	else if (distanceFromPlayer == 1) //no more than 1 level away 
		pointValue = 300;

	return;
}


bool Spider::takeHealth()
{
	return true;
}


void Spider::findDistancePlayer()
{
	if(((player->getPosition().x <= currentPosition.x + 1)&&(player->getPosition().x >= currentPosition.x -1)))
		if (((player->getPosition().y <= currentPosition.y + 1) && (player->getPosition().y >= currentPosition.y - 1)))
		{
			pointValue = 300;
			return;
		}
	
	else if (((player->getPosition().x <= currentPosition.x + 4) && (player->getPosition().x >= currentPosition.x - 4)))
		if (((player->getPosition().y <= currentPosition.y + 4) && (player->getPosition().y >= currentPosition.y - 4)))
		{
			pointValue = 600;
			return;
		}
		
	else
	{
		pointValue = 900;
		return;
	}
}


void Spider::colideWith(GameObject* other)
{
	if (dynamic_cast<Bullet*>(other) != nullptr)
		health = 0;
	else if (dynamic_cast<Player*>(other) != nullptr)
		health = 0;
	return;
}


Spider::~Spider()
{
}