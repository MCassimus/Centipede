#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
}

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


sf::Vector2i GameObject::getVelocity() const
{
	return velocity;
}


void GameObject::setTexture(const char * filePath)
{
	if (!textureTemp.loadFromFile(filePath))
		printf("Errors\n");
	object.setTexture(textureTemp);
}


void GameObject::render()
{
	window->draw(object);
}


void GameObject::collideWith(GameObject *)
{
	return;
}


void GameObject::collideWith(std::vector<GameObject *> *)
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
	
}