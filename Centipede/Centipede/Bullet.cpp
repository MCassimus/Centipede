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
	object.setOrigin(-4, -4);
	liveBullet = true;
	pointValue = 0;

	soundClip.loadFromFile("../Audio/bulletFire.ogg");
	soundPlayer.play();
}


Bullet::~Bullet()
{
	liveBullet = false;
}


void Bullet::update()
{
	if(CentipedeGame::clock % delay == 0)
		currentPosition.y += velocity.y;
}


void Bullet::collideWith(GameObject * other)
{
	health = 0;
}


unsigned int Bullet::die(bool &readyToDie) {
	liveBullet = false;
	return GameObject::die(readyToDie);
}


char* Bullet::getType() {
	return "Bullet";
}