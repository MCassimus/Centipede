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
	object.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
	velocity = sf::Vector2i(0, 1);
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
		object.setPosition(object.getPosition().x, object.getPosition().y + velocity.y);
		object.setPosition(static_cast<sf::Vector2f>(getNearestCellPos(static_cast<sf::Vector2i>(object.getPosition()))));
		//apply velocity
		/*object.setPosition(currentPosition.x * (window->getSize().x / 29), currentPosition.y * (window->getSize().y / 29));
		currentPosition = sf::Vector2u(currentPosition.x, currentPosition.y - velocity.y);
		*/
		//reset frame counter
		frame = 0;
	}

	//if (!CentipedeGame::isMushroomCell(currentPosition.x, currentPosition.y))
		//CentipedeGame::placeObject(currentPosition.x, currentPosition.y, new Mushroom(window));
	
	//check if bottom of screen
	if (currentPosition.y == 30)
		health = 0;
}