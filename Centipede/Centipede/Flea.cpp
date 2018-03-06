#include "stdafx.h"
#include "Flea.h"
#include "CentipedeGame.h"
#include "Mushroom.h"


Flea::Flea()
{
}


Flea::Flea(sf::RenderWindow * renderWindow) : GameObject(renderWindow)
{
	setTexture("../Sprites/flea.png");
	object.setScale(sf::Vector2f(.5,.5));
	object.setOrigin(-6, -10);
	object.setPosition(sf::Vector2f(0, 0));
	velocity = sf::Vector2i(0, interval.y);
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
		object.setPosition(object.getPosition().x, object.getPosition().y + velocity.y);
		object.setPosition(static_cast<sf::Vector2f>(getNearestCellPos(static_cast<sf::Vector2i>(object.getPosition()))));

		//reset frame counter
		frame = 0;
	
		if (rand() % 100 < 30 && currentPosition.y != 29)
			CentipedeGame::placeObject(currentPosition.x, currentPosition.y, new Mushroom(window, object.getPosition()));

	}

	//check if bottom of screen
	if (currentPosition.y >= window->getSize().y)
		health = 0;
}