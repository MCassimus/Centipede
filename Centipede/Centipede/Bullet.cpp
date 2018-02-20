#include "stdafx.h"
#include "Bullet.h"
#include "GameObject.h"



Bullet::Bullet(sf::RenderWindow * renderWindow) : GameObject (renderWindow)
{
	window = renderWindow;
	setTexture("Sprites\\Bullet.png");
	setVelocity(sf::Vector2i(-1, 0));
}


static int delay = 0;
void Bullet::update()  //changes position by velocity
{
	currentPosition.x += velocity.x;
	currentPosition.y += velocity.y;
	if (currentPosition.x <= 0 || currentPosition.y <= 0)
		health = 0;

	if (++delay == 5)
		delay = 0;

	render();
	return;
}


void Bullet::collides(GameObject*)
{
	health = 0;
	
	return;
}


Bullet::~Bullet()
{
}