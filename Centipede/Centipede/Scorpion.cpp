#include "stdafx.h"
#include "Scorpion.h"
#include "GameObject.h"


Scorpion::Scorpion(sf::RenderWindow * renderWindow) : GameObject(renderWindow)
{
	pointValue = 1000;
	setVelocity(sf::Vector2i())
}


void Scorpion::update()
{

	return;
}


Scorpion::~Scorpion()
{
}
