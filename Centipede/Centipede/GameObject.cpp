#include "stdafx.h"
#include "GameObject.h"
#include "CentipedeGame.h"
#include <iostream>

sf::Vector2u GameObject::oWD = sf::Vector2u(0, 0);
sf::Vector2i GameObject::interval = sf::Vector2i(0, 0);


GameObject::GameObject()
{

}


GameObject::GameObject(int x, int y)
{
	currentPosition = sf::Vector2i(x, y); //consider adding an intermediary position variable so that objects such as ship can move based upon trigonometric functions (look up atan2)
	soundPlayer.setBuffer(soundClip);
}


GameObject::~GameObject()
{
}


int GameObject::getPointValue()
{
	return pointValue;
}


unsigned int GameObject::getHealth() const
{
	return health;
}


sf::Vector2i GameObject::getVelocity() const
{
	return velocity;
}


sf::Vector2i GameObject::getPosition() const
{
	return currentPosition;
}


void GameObject::setTexture(const char * filePath)
{
	if (!textureTemp.loadFromFile(filePath))
		printf("Errors\n");
	object.setTexture(textureTemp);
}


void GameObject::render(sf::RenderTexture & playerArea)
{
	setPixels();
	playerArea.draw(object);
}


void GameObject::collideWith(GameObject *)
{
	return;
}


void GameObject::setPointValue(unsigned int newPointValue)
{
	pointValue = newPointValue;
}


void GameObject::setVelocity(sf::Vector2i newVel)
{
	velocity = newVel;
}


void GameObject::addHealth(int health)
{
	return;
}

sf::Vector2i GameObject::getNearestCellPos(sf::Vector2i position) {
	position.x -= (position.x%interval.x);
	position.y -= (position.y%interval.y);
	return position;
}

void GameObject::setPixels()
{
	object.setPosition(currentPosition.x * interval.x, currentPosition.y * interval.y);
}

unsigned int GameObject::die(bool &readyToDie, CentipedeGame *gameHandle) {
	readyToDie = true;
	std::cout << getType() << " died\n";
	return getPointValue();
}

char* GameObject::getType() {
	return "GameObject";
}
