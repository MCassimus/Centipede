#include "stdafx.h"
#include "Scorpion.h"
#include "GameObject.h"
#include "Bullet.h"
#include <iostream>


Scorpion::Scorpion(sf::RenderWindow * renderWindow, int x, int y) : GameObject(renderWindow, x,  y)
{
	pointValue = 1000;
	health = 1;
	scuttle = 0;
	object.setScale(sf::Vector2f(1.5, 1.5));
	if (currentPosition.x < 10)
		setVelocity(sf::Vector2i(1* interval.x, 0));
	else
		setVelocity(sf::Vector2i(-1*interval.x, 0));
}


static unsigned int frame = 0;
void Scorpion::update()
{
	

	if (frame++ == frameMax)
	{
		object.setPosition(object.getPosition().x + velocity.x, object.getPosition().y );
		object.setPosition(static_cast<sf::Vector2f>(getNearestCellPos(static_cast<sf::Vector2i>(object.getPosition()))));

		if (scuttle++ >= 3)
			scuttle = 0;

		if (scuttle == 0)
			setTexture("../Sprites/Scorpion/scorpionLeft1.png");
		else if (scuttle==1)
			setTexture("../Sprites/Scorpion/scorpionLeft2.png");
		else if (scuttle==2)
			setTexture("../Sprites/Scorpion/scorpionRight1.png");
		else
			setTexture("../Sprites/Scorpion/scorpionRight2.png");

		frame = 0;
		if (object.getPosition().x >= window->getSize().x || object.getPosition().x < 0)
			velocity = velocity*-1;
		std::cout << object.getPosition().x << object.getPosition().y<<std::endl;
	}

	return;
}


void Scorpion::collideWith(GameObject* other)
{
	if (dynamic_cast<Bullet*>(other) != nullptr)
		health = 0;
}