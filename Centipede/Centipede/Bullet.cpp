#include "stdafx.h"
#include "Bullet.h"
#include "GameObject.h"


Bullet::Bullet(sf::RenderWindow * renderWindow) :GameObject(window)
{
	window = renderWindow;
	setVelocity(sf::Vector2i(1, 0));
}


void Bullet::update()
{
	return;
}


void Bullet::collides(GameObject*)
{
	health = 0;
	
	return;
}

bool Bullet::isActive() {
	return true;
}


Bullet::~Bullet()
{
}
