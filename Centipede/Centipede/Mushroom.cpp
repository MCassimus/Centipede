#include "stdafx.h"
#include "Mushroom.h"
#include <typeinfo>
#include "Spider.h"


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


void Mushroom::resetHeath()
{
	health = 4;
	setTexture("Sprites\\Mushroom\\mushroom4");
	return;
}


void Mushroom::collides( GameObject* other )
{

	if (dynamic_cast<Spider*>(other) != nullptr)


	return;
}