#include "stdafx.h"
#include "Scorpion.h"
#include "GameObject.h"
#include "Bullet.h"


Scorpion::Scorpion(sf::RenderWindow * renderWindow) : GameObject(renderWindow)
{
	pointValue = 1000;
	health = 1;
	scuttle = 0;
	if (currentPosition.x < 10)
		setVelocity(sf::Vector2i(1, 0));
	else
		setVelocity(sf::Vector2i(-1, 0));
}


void Scorpion::update()
{
	currentPosition.x = currentPosition.x + velocity.x;
	/*for()*/
	if (scuttle == 0)
		setTexture("../Sprites/Scorpion/scorpionLeft1.png");
	else if (scuttle==1)
		setTexture("../Sprites/Scorpion/scorpionLeft2.png");
	else if (scuttle==2)
		setTexture("../Sprites/Scorpion/scorpionRight1.png");
	else
		setTexture("../Sprites/Scorpion/scorpionRight2.png");
	render();
	return;
}


void Scorpion::collides(GameObject* other)
{
	if (dynamic_cast<Bullet*>(other) != nullptr)
		health = 0;
}


Scorpion::~Scorpion()
{
}
