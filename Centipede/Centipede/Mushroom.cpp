#include "stdafx.h"
#include "Mushroom.h"
#include <typeinfo>
#include "Spider.h"
#include "Scorpion.h"
#include "Bullet.h"



Mushroom::Mushroom(sf::RenderWindow* window):GameObject(window)
{
	pointValue = 1;
	poisoned = false;
	health = 4;
}


void Mushroom::update()
{
	if (poisoned)
	{
		pointValue = 5;
		switch (health)
		{
		case 1:
			setTexture("Sprites\\Mushroom\\Poisoned1.png");
			break;
		case 2:
			setTexture("Sprites\\Mushroom\\Poisoned2.png");
			break;
		case 3:
			setTexture("Sprites\\Mushroom\\Poisoned3.png");
			break;
		case 4:
			setTexture("Sprites\\Mushroom\\Poisoned4.png");
			break;
		}
	}
	else
	{
		switch (health)
		{
		case 1:
			setTexture("Sprites\\Mushroom\\mushroom1.png");
			break;
		case 2:
			setTexture("Sprites\\Mushroom\\mushroom2.png");
			break;
		case 3:
			setTexture("Sprites\\Mushroom\\mushroom3.png");
			break;
		case 4:
			setTexture("Sprites\\Mushroom\\mushroom4.png");
			break;
		}
	}

	render();
	return;
}


bool Mushroom::getPoisoned()
{
	return poisoned;
}


void Mushroom::resetHeath()
{
	health = 4;
	return;
}


void Mushroom::collides( GameObject* other ) //dynamic_cast returns null pointer if class
{                                            //is not what it is asked to change it to

	if (dynamic_cast<Spider*>(other) != nullptr)
	{
		health = 0;
	}
	if (dynamic_cast<Scorpion*>(other) != nullptr)
	{
		poisoned = true;
	}
	if (dynamic_cast<Bullet*>(other) != nullptr)
	{
		health--;
	}

	return;
}


Mushroom::~Mushroom()
{
}
