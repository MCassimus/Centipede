#include "stdafx.h"
#include "Mushroom.h"


Mushroom::Mushroom(sf::RenderWindow* window):GameObject(window)
{
	pointValue=1;
	poisoned=false;
	health=4;
}


Mushroom::~Mushroom()
{
}


void Mushroom::update()
{
	if (health = 3)
		setTexture("Sprites\\Mushroom\\mushroom3");
	if (health = 2)
		setTexture("Sprites\\Mushroom\\mushroom2");
	if (health = 1)
		setTexture("Sprites\\Mushroom\\mushroom1");
	
	return;
}


bool Mushroom::getPoisoned()
{
	return poisoned;
}


void Mushroom::resetHeath()
{
	health = 4;
	setTexture("Sprites\\Mushroom\\mushroom4");
	return;
}