#include "stdafx.h"
#include "GameObject.h"
#include <iostream>

sf::Vector2u GameObject::oWD = sf::Vector2u(0,0);
sf::Vector2i GameObject::interval = sf::Vector2i(0, 0);

GameObject::GameObject()
{

}

GameObject::GameObject(sf::RenderWindow * renderWindow, int x, int y)
{
	window = renderWindow;
	interval = static_cast<sf::Vector2i>(oWD / static_cast<unsigned int>(30));
	currentPosition = sf::Vector2i(x, y);
}

GameObject::GameObject(sf::RenderWindow * renderWindow)
{
	window = renderWindow;
	interval = static_cast<sf::Vector2i>(oWD / static_cast<unsigned int>(30));
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


void GameObject::render()
{
	setPixels();
	window->draw(object);
}


void GameObject::collideWith(GameObject *)
{
	return;
}


//void GameObject::collideWith(std::vector<GameObject *> *)
//{
//	return;
//}


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

sf::Vector2i GameObject::getRelMousePos() {
	sf::Vector2f mousePos(sf::Mouse::getPosition(*window));
	float scalar = static_cast<float>(oWD.x) / window->getSize().x;
	mousePos *= scalar;
	return sf::Vector2i(mousePos);
}

void GameObject::setPixels()
{
	object.setPosition(currentPosition.x * interval.x, currentPosition.y * interval.y);
}

unsigned int GameObject::die(bool &readyToDie) {
	readyToDie = true;
	return getPointValue();
}

char* GameObject::getType() {
	return "GameObject";
}