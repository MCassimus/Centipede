#include "stdafx.h"
#include "Bullet.h"
#include "GameObject.h"
#include "CentipedeGame.h"


Bullet::Bullet(sf::RenderWindow * renderWindow, int x, int y) : GameObject(window, x, y)
{
	window = renderWindow;
	setVelocity(sf::Vector2i(0, -1));
	setTexture("../Sprites/bullet.png");
}


void Bullet::update()
{
	
	if (CentipedeGame::clock % delay == 0) {
		currentPosition.x += velocity.x;
		currentPosition.y += velocity.y;
	}
	if (currentPosition.y < 0) {
		activity = false;
	}
	else
		CentipedeGame::placeObject(currentPosition.x, currentPosition.y, this);
}


void Bullet::collideWith(GameObject*)
{
	activity = false;
}

bool Bullet::isActive() {
	return activity;
}

void Bullet::shootFrom(sf::Vector2i newPos)
{
	currentPosition.x = newPos.x;
	currentPosition.y = newPos.y-1;
	activity = true;
}