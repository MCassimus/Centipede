#include "stdafx.h"
#include "Bullet.h"
#include "GameObject.h"
#include "CentipedeGame.h"

Bullet::Bullet(sf::RenderWindow * renderWindow) : GameObject(window)
{
	window = renderWindow;
	setVelocity(sf::Vector2i(0, -1));
	setTexture("../Sprites/bullet.png");

	health = 0;
}


void Bullet::update()
{
	if (health > 0) {

		//std::cout << CentipedeGame::clock << std::endl;
		if (currentPosition.y == 0) {
			health = 0;
			std::cout << "i went off the screen!\n";
		}
		else if (CentipedeGame::clock % delay == 0) {
			currentPosition.x += velocity.x;
			currentPosition.y += velocity.y;
		}
	}
}


void Bullet::collideWith(GameObject *other)
{
	std::cout << "i collided with a " << other->getType() << "!\n";
	health = 0;
}

bool Bullet::isAlive() {
	return health > 0;
}

void Bullet::shootFrom(sf::Vector2i pos)
{
	std::cout << "i was spawned!\n";
	currentPosition.x = pos.x;
	currentPosition.y = pos.y - 1;
	health = 1;
	CentipedeGame::placeObject(currentPosition.x, currentPosition.y, this);
}

char* Bullet::getType() {
	return "Bullet";
}

void Bullet::die(GameObject*) {
	//do nothing
}