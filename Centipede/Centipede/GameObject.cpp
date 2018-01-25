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


sf::Vector2f GameObject::getPosition() const
{
	return object.getPosition();
}


unsigned int GameObject::getHealth() const
{
	return health;
}


sf::Vector2f GameObject::getVelocity() const
{
	return velocity;
}


sf::FloatRect GameObject::getBoundingBox() const
{
	return object.getGlobalBounds();
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


bool GameObject::collides(GameObject *  other)
{
	return object.getGlobalBounds().intersects(other->getBoundingBox());
}


void GameObject::setPointValue(unsigned int newPointValue)
{
	pointValue = newPointValue;
}


void GameObject::setPosition(sf::Vector2f newPos)
{
	object.setPosition(newPos);
}


void GameObject::setPosition(float newXPos, float newYPos)
{
	object.setPosition(sf::Vector2f(newXPos, newYPos));
}


void GameObject::setVelocity(sf::Vector2f newVel)
{
	velocity = newVel;
}


void GameObject::addHealth()
{
	health++;
}


bool GameObject::takeHealth()
{
	return --health == 0;
}