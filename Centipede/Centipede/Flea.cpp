#include "stdafx.h"
#include "Flea.h"
#include "CentipedeGame.h"
#include "Mushroom.h"


Flea::Flea()
{
}


Flea::Flea(sf::RenderWindow * renderWindow, int x, int y) : GameObject(renderWindow, x,  y)
{
 	setTexture("../Sprites/flea.png");
	object.setScale(sf::Vector2f(.5,.5));
	object.setOrigin(-6, -10);
	object.setPosition(sf::Vector2f(0, 0));
	velocity = sf::Vector2i(0, 1);
	points = 200;
}


Flea::~Flea()
{
}


static unsigned int frame = 0;
void Flea::update()
{
	setPixels();
	if (frame++ == delay)//if time to update
	{
		//apply velocity
		currentPosition.y += velocity.y;

		//reset frame counter
		frame = 0;
	
		if (rand() % 100 < 30 && currentPosition.y != 30 && !CentipedeGame::isMushroomCell(currentPosition.x, currentPosition.y))
			CentipedeGame::placeObject(currentPosition.x, currentPosition.y, new Mushroom(window, currentPosition.x, currentPosition.y));

		//check if bottom of screen
		if (currentPosition.y == 30)
			currentPosition = sf::Vector2i(rand() % 30, 0);
	}
}


void Flea::collideWith(GameObject * other)
{
	if (dynamic_cast<Bullet *>(other) != nullptr)
		health = 0;
}