#include "stdafx.h"
#include "Scorpion.h"
#include "GameObject.h"
#include "Bullet.h"


Scorpion::Scorpion(sf::RenderWindow * renderWindow, int x, int y) : GameObject(renderWindow, x,  y)
{
	pointValue = 1000;
	health = 1;
	scuttle = 0;
	object.setScale(sf::Vector2f(1.5, 1.5));

	if (currentPosition.x < 10)
		setVelocity(sf::Vector2i(1, 0));
	else
		setVelocity(sf::Vector2i(-1, 0));
}


static unsigned int frame = 0;
void Scorpion::update()
{
	setPixels();
	if (frame++ == frameMax)
	{
		currentPosition.x += velocity.x;

		if (scuttle++ >= 3)
			scuttle = 0;

		if (scuttle == 0)
			setTexture("../Sprites/Scorpion/scorpionLeft1.png");
		else if (scuttle == 1)
			setTexture("../Sprites/Scorpion/scorpionLeft2.png");
		else if (scuttle == 2)
			setTexture("../Sprites/Scorpion/scorpionRight1.png");
		else
			setTexture("../Sprites/Scorpion/scorpionRight2.png");

		if (currentPosition.x == 0 || currentPosition.x == 29)
			velocity = velocity*-1;

		frame = 0;
	}
}


void Scorpion::collideWith(GameObject* other)
{
	if (dynamic_cast<Bullet*>(other) != nullptr)
		health = 0;
}