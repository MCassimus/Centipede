#include "stdafx.h"
#include "Bullet.h"
#include "GameObject.h"


Bullet::Bullet(sf::RenderWindow * renderWindow, int x, int y) : GameObject(window, x, y)
{
	window = renderWindow;
	setVelocity(sf::Vector2i(0, -1));
	object.setTextureRect(sf::IntRect(50, 50, 100, 100));
	object.setColor(sf::Color::Red);
}


void Bullet::update()
{
	currentPosition.x += velocity.x;
	currentPosition.y += velocity.y;
	object.setPosition(static_cast<sf::Vector2f>(currentPosition*interval.x));
	std::cout << object.getPosition().x << ',' << object.getPosition().y << std::endl;
}


void Bullet::collides(GameObject*)
{
	activity = false;
}

bool Bullet::isActive() {
	return activity;
}

void Bullet::goToPosition(sf::Vector2i newPos)
{
	object.setPosition(static_cast<sf::Vector2f>(newPos));
	activity = true;
}