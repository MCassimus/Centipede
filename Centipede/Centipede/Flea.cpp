#include "stdafx.h"
#include "Flea.h"

Flea::Flea()
{
}


Flea::Flea(sf::RenderWindow * renderWindow) : GameObject(renderWindow)
{
	setTexture("../Sprites/flea.png");
	currentPosition = sf::Vector2u(rand() % 29, 0);
	velocity = sf::Vector2i(0, -1);
	points = 200;
}


Flea::~Flea()
{
}


void Flea::update()
{
	currentPosition = sf::Vector2u(currentPosition.x, currentPosition.y - velocity.y);
	object.setPosition(currentPosition.x * (window->getSize().x / 29), currentPosition.y * (window->getSize().y / 29));

	if (currentPosition.y == 29)
		health = 0;
	return;
}