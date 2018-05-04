#include "stdafx.h"
#include "Flea.h"
#include "CentipedeGame.h"
#include "Mushroom.h"


Flea::Flea()
{
}


Flea::Flea(int x, int y) : GameObject(x, y)
{
	setTexture("../Sprites/flea.png");
	object.setScale(sf::Vector2f(.5, .5));
	object.setOrigin(-6, -10);
	object.setPosition(sf::Vector2f(0, 0));
	velocity = sf::Vector2i(0, 1);
	pointValue = 200;
}


Flea::~Flea()
{
}


static unsigned int frame = 0;
void Flea::update(CentipedeGame *gameHandle)
{
	setPixels();
	if (frame++ == delay)//if time to update
	{
		//apply velocity
		currentPosition.y += velocity.y;

		//reset frame counter
		frame = 0;

		//this just fills the entire screen with fleas
		//if (rand() % 40)
		//	CentipedeGame::placeObject(rand() % 30, rand() % 30,
		//		new Flea(window, rand() % 30,rand() % 30));


		//places flea at random x cordinate at y==0
		if (rand() % 100 < 30 && currentPosition.y != 30 && !CentipedeGame::isMushroomCell(currentPosition.x, currentPosition.y))
			gameHandle->spawnObject<Mushroom>(currentPosition.x, currentPosition.y);






		//check if bottom of screen
		if (currentPosition.y == 29)
		{
			pointValue = 0;
			health = 0;
		}
	}
}


void Flea::collideWith(GameObject * other)
{
	if (dynamic_cast<Bullet *>(other) != nullptr)
		health = 0;
}