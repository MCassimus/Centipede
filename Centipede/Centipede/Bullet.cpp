#include "stdafx.h"
#include "Bullet.h"
#include "GameObject.h"


Bullet::Bullet(sf::RenderWindow * renderWindow) :GameObject(window)
{
	window = renderWindow;
	health = 1;
	setTexture("../Sprites/Bullet.png");
	setVelocity(sf::Vector2i(0, -1));
}


void Bullet::update()
{
	currentPosition.y = currentPosition.y + velocity.y;
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
