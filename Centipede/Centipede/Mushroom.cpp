#include "stdafx.h"
#include "Mushroom.h"
#include "Spider.h"
#include "Scorpion.h"
#include "Bullet.h"


Mushroom::Mushroom(sf::RenderWindow* window):GameObject(window)
{
	pointValue = 1;
	poisoned = false;
	health = 4;
}


Mushroom::Mushroom(sf::RenderWindow * window, sf::Vector2f position) : GameObject(window)
{
	pointValue = 1;
	poisoned = false;
	health = 4;
	object.setOrigin(-2, -2);
	object.setPosition(static_cast<sf::Vector2f>(getNearestCellPos(static_cast<sf::Vector2i>(position))));
}


void Mushroom::update()
{
	switch (health)
	{
	case 1:
		setTexture("../Sprites/Mushroom/mushroom1.png");
		break;
	case 2:
		setTexture("../Sprites/Mushroom/mushroom2.png");
		break;
	case 3:
		setTexture("../Sprites/Mushroom/mushroom3.png");
		break;
	case 4:
		setTexture("../Sprites/Mushroom/mushroom4.png");
		break;
	}	
}


bool Mushroom::getPoisoned()
{
	return poisoned;
}


void Mushroom::resetHeath()
{
	health = 4;
	poisoned = false;
	setTexture("../Sprites/Mushroom/mushroom4.png");
}


void Mushroom::collides( GameObject* other ) //dynamic_cast returns null pointer if class
{                                            //is not what it is asked to change it to
	if (dynamic_cast<Spider*>(other) != nullptr)
		health = 0;
	if (dynamic_cast<Scorpion*>(other) != nullptr)
		poisoned = true;
	if (dynamic_cast<Bullet*>(other) != nullptr)
		health--;
}


Mushroom::~Mushroom()
{
}