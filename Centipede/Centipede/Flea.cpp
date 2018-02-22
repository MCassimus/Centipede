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


static unsigned int frame = 0;
void Flea::update()
{
	if (frame++ == delay)//if time to update
	{
		//apply velocity
		object.setPosition(currentPosition.x * (window->getSize().x / 29), currentPosition.y * (window->getSize().y / 29));
		currentPosition = sf::Vector2u(currentPosition.x, currentPosition.y - velocity.y);
		
		//reset frame counter
		frame = 0;
	}

	//check if bottom of screen
	if (currentPosition.y == 30)
		currentPosition = sf::Vector2u(rand() % 29, 0);
}