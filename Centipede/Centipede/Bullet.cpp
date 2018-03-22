#include "stdafx.h"
#include "Bullet.h"
#include "CentipedeGame.h"
#include "Mushroom.h"


bool Bullet::liveBullet = false;

Bullet::Bullet(sf::RenderWindow * renderWindow, int x, int y) : GameObject(renderWindow, x, y)
{
	window = renderWindow; 
	health = 1;
	setVelocity(sf::Vector2i(0, -1));
	setTexture("../Sprites/bullet.png");
	liveBullet = true;
}

Bullet::~Bullet()
{
	liveBullet = false;
}

void Bullet::update()
{
	if(CentipedeGame::clock % 2 == 0)
		currentPosition.y += velocity.y;

	printf("bullet pos %i %i\n", currentPosition.x, currentPosition.y);

	if (currentPosition.x <= 0 && currentPosition.x >= 29 && currentPosition.y <= 0 && currentPosition.y >= 29)
	{
		health = 0;
		liveBullet = false;
	}
}

void Bullet::collideWith(GameObject * other)
{
	health = 0;
}

void Bullet::die(GameObject *self) {
	liveBullet = false;
	delete self;
}

//#include "stdafx.h"
//#include "Bullet.h"
//#include "GameObject.h"
//#include "CentipedeGame.h"
//
//Bullet::Bullet(sf::RenderWindow * renderWindow) : GameObject(window)
//{
//	window = renderWindow;
//	setVelocity(sf::Vector2i(0, -1));
//	setTexture("../Sprites/bullet.png");
//	currentPosition = sf::Vector2i(15, 15);
//
//	health = 1;
//}
//
//
//void Bullet::update()
//{
//	//if (health > 0) {
//
//	//	//std::cout << CentipedeGame::clock << std::endl;
//	//	if (currentPosition.y == 0) {
//	//		health = 0;
//	//		std::cout << "i went off the screen!\n";
//	//	}
//	//	else if (CentipedeGame::clock % delay == 0) {
//	//		currentPosition.x += velocity.x;
//	//		currentPosition.y += velocity.y;
//	//	}
//	//}
//
//	//if (currentPosition.x >= 0 && currentPosition.x <= 29 && currentPosition.y >= 0 && currentPosition.y <= 29)
//	//	health = 0;
//
//	if (CentipedeGame::clock % 2 == 0)
//		currentPosition.y += velocity.y;
//
//	if (currentPosition.y <= 0)
//		health = 2;
//}
//
//
//void Bullet::collideWith(GameObject *other)
//{
//	/*if (other->getType() != "Player" || other->getType() != "Bullet")
//	{
//		std::cout << "i collided with a " << other->getType() << "!\n";
//		health = 0;
//	}	*/
//
//	if (other->getType() == "Mushroom")
//		health = 2;
//	else
//		std::cout << "i collided with a " << other->getType() << "!\n";
//
//}
//
//bool Bullet::isAlive() {
//	return health == 1;
//	//return currentPosition.x >= 0 && currentPosition.x <= 29 && currentPosition.y >= 0 && currentPosition.y <= 29;
//}
//
//void Bullet::shootFrom(sf::Vector2i pos)
//{
//	std::cout << "i was spawned!\n";
//	currentPosition.x = pos.x;
//	currentPosition.y = pos.y/* - 1*/;
//	CentipedeGame::placeObject(currentPosition.x, currentPosition.y, this);
//}
//
//char* Bullet::getType() {
//	return "Bullet";
//}
//