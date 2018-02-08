#include "stdafx.h"
#include "Mushroom.h"


Mushroom::Mushroom(sf::RenderWindow* window):GameObject(window)
{
	pointValue = 1;
	poisoned = false;
	health = 4;
}


Mushroom::~Mushroom()
{
}


void Mushroom::update()
{
	setTexture("mushroom.png");
	return;
}


bool Mushroom::getPoisoned()
{
	return poisoned;
}