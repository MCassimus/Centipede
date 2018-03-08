#include "stdafx.h"
#include "Bullet.h"
#include "GameObject.h"


Bullet::Bullet(sf::RenderWindow * renderWindow, int x, int y) : GameObject(window, x, y)
{
	window = renderWindow;
	setVelocity(sf::Vector2i(1, 0));
	object.setTextureRect(sf::IntRect(5, 5, 10, 10));
	object.setColor(sf::Color::Red);
}


void Bullet::update()
{
	setPixels();
	object.setPosition(object.getPosition().x, object.getPosition().y + velocity.y);
	object.setPosition(static_cast<sf::Vector2f>(getNearestCellPos(static_cast<sf::Vector2i>(object.getPosition()))));
}


void Bullet::collides(GameObject*)
{
	health = 0;
	
	return;
}

bool Bullet::isActive() {
	return true;
}

void Bullet::goToPosition(sf::Vector2f newPos)
{
	object.setPosition(newPos);
}


Bullet::~Bullet()
{
}