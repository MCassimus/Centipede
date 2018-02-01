#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(sf::RenderWindow * renderWindow)
{
	window = renderWindow;
}


GameObject::~GameObject()
{
}


int GameObject::getPointValue() const
{
	return pointValue;
}


unsigned int GameObject::getHealth() const
{
	return health;
}


sf::Vector2f GameObject::getVelocity() const
{
	return velocity;
}


void GameObject::setTexture(const char * filePath)
{
	sf::Texture textureTemp;
	textureTemp.loadFromFile(filePath);
	object.setTexture(textureTemp);
}


void update(float deltaTime)
{
	return;
}


void GameObject::render()
{
	window->draw(object);
}


void GameObject::setPointValue(unsigned int newPointValue)
{
	pointValue = newPointValue;
}


void GameObject::setVelocity(sf::Vector2f newVel)
{
	velocity = newVel;
}


void GameObject::addHealth()
{
	health++;
}